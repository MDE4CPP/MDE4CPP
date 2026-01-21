/**
 * MDE4CPP Terminal
 * Web-based terminal interface using xterm.js and WebSocket
 */

class MDE4CPPTerminal {
    constructor() {
        this.terminal = null;
        this.socket = null;
        this.fitAddon = null;
        this.currentLine = '';
        this.commandHistory = [];
        this.historyIndex = -1;
        this.isConnected = false;
        this.wsUrl = this.getWebSocketUrl();
        this.workingDirectory = '';
        this.commandStartTime = null;
        this.historySearchMode = false;
        this.historySearchQuery = '';
        this.historySearchResults = [];
        this.historySearchIndex = -1;
        this.autoScrollEnabled = true;
        
        // Available commands for suggestions
        this.availableCommands = [
            'cd', 'dir', 'ls', 'pwd', 'get-location',
            'cat', 'head', 'tail', 'type', 'get-content', 'more', 'less',
            'find', 'grep', 'select-string',
            'gradlew', 'gradlew.bat', 'gradle',
            'clear', 'cls', 'help', 'get-help'
        ];
        
        this.initializeTerminal();
        this.connectWebSocket();
    }
    
    /**
     * Get WebSocket URL - use same backend URL as API
     */
    getWebSocketUrl() {
        // Use the same backend URL as the API (localhost:8000)
        // Extract from API_BASE_URL if available, otherwise construct from window.location
        const apiBaseUrl = window.API_BASE_URL || 'http://localhost:8000/api/v1';
        const url = new URL(apiBaseUrl);
        const protocol = url.protocol === 'https:' ? 'wss:' : 'ws:';
        return `${protocol}//${url.host}/api/v1/terminal/ws`;
    }
    
    /**
     * Initialize xterm.js terminal
     */
    initializeTerminal() {
        const Terminal = window.Terminal;
        const FitAddon = window.FitAddon;
        const WebLinksAddon = window.WebLinksAddon;
        
        // Create terminal instance with proper monospace font settings
        this.terminal = new Terminal({
            cursorBlink: true,
            fontSize: 14,
            fontFamily: 'Consolas, "Courier New", "Lucida Console", Monaco, "DejaVu Sans Mono", monospace',
            fontWeight: 'normal',
            fontWeightBold: 'bold',
            lineHeight: 1.0,
            letterSpacing: 0,
            allowProposedApi: true,
            scrollback: 1000,
            convertEol: true,
            disableStdin: false,
            theme: {
                background: '#1e1e1e',
                foreground: '#d4d4d4',
                cursor: '#aeafad',
                cursorAccent: '#1e1e1e',
                selection: '#264f78',
                black: '#000000',
                red: '#cd3131',
                green: '#0dbc79',
                yellow: '#e5e510',
                blue: '#2472c8',
                magenta: '#bc3fbc',
                cyan: '#11a8cd',
                white: '#e5e5e5',
                brightBlack: '#666666',
                brightRed: '#f14c4c',
                brightGreen: '#23d18b',
                brightYellow: '#f5f543',
                brightBlue: '#3b8eea',
                brightMagenta: '#d670d6',
                brightCyan: '#29b8db',
                brightWhite: '#e5e5e5'
            }
        });
        
        // Add addons
        this.fitAddon = new FitAddon.FitAddon();
        this.terminal.loadAddon(this.fitAddon);
        this.terminal.loadAddon(new WebLinksAddon.WebLinksAddon());
        
        // Open terminal in container
        const container = document.getElementById('terminal-container');
        
        // Clear any existing content
        container.innerHTML = '';
        
        // Open terminal
        this.terminal.open(container);
        
        // Wait for fonts to load and terminal to initialize
        const initTerminal = () => {
            // Force a fit to calculate proper dimensions
            try {
                // First fit to get initial dimensions
                this.fitAddon.fit();
                
                // Double-check after a brief delay to ensure font metrics are calculated
                setTimeout(() => {
                    const container = document.getElementById('terminal-container');
                    if (container) {
                        // Get the actual terminal element
                        const terminalElement = container.querySelector('.xterm');
                        if (terminalElement) {
                            // Force the terminal to use the constrained height
                            // The CSS absolute positioning should handle this, but we ensure it
                            const containerHeight = container.clientHeight;
                            const containerPadding = 16; // 1rem top padding
                            const promptSpace = 56; // 3.5rem bottom space
                            const availableHeight = containerHeight - containerPadding - promptSpace;
                            
                            // Set explicit height to constrain terminal rendering
                            terminalElement.style.height = `${availableHeight}px`;
                            terminalElement.style.maxHeight = `${availableHeight}px`;
                            
                            // Re-fit with the constrained height
                            this.fitAddon.fit();
                            
                            // Force another fit after a small delay to ensure it sticks
                            setTimeout(() => {
                                this.fitAddon.fit();
                                this.scrollToBottom();
                            }, 50);
                        }
                    }
                    
                    // Scroll to bottom to show prompt
                    setTimeout(() => {
                        this.scrollToBottom();
                    }, 150);
                    
                    // Send initial resize
                    if (this.socket && this.socket.readyState === WebSocket.OPEN) {
                        this.socket.send(JSON.stringify({
                            type: 'resize',
                            cols: this.terminal.cols,
                            rows: this.terminal.rows
                        }));
                    }
                }, 50);
            } catch (error) {
                console.error('Error fitting terminal:', error);
            }
        };
        
        // Wait for fonts to be ready
        if (document.fonts && document.fonts.ready) {
            document.fonts.ready.then(() => {
                setTimeout(initTerminal, 100);
            });
        } else {
            setTimeout(initTerminal, 200);
        }
        
        // Ensure terminal is properly sized on resize
        const resizeObserver = new ResizeObserver(() => {
            try {
                const container = document.getElementById('terminal-container');
                if (container) {
                    const terminalElement = container.querySelector('.xterm');
                    if (terminalElement) {
                        // Recalculate available height
                        const containerHeight = container.clientHeight;
                        const containerPadding = 16;
                        const promptSpace = 56;
                        const availableHeight = containerHeight - containerPadding - promptSpace;
                        
                        // Constrain terminal height
                        terminalElement.style.height = `${availableHeight}px`;
                        terminalElement.style.maxHeight = `${availableHeight}px`;
                    }
                }
                
                this.fitAddon.fit();
                if (this.autoScrollEnabled) {
                    this.scrollToBottom();
                }
                if (this.socket && this.socket.readyState === WebSocket.OPEN) {
                    this.socket.send(JSON.stringify({
                        type: 'resize',
                        cols: this.terminal.cols,
                        rows: this.terminal.rows
                    }));
                }
            } catch (error) {
                console.error('Error resizing terminal:', error);
            }
        });
        
        resizeObserver.observe(container);
        
        // Handle window resize
        window.addEventListener('resize', () => {
            this.fitAddon.fit();
            if (this.autoScrollEnabled) {
                this.scrollToBottom();
            }
            if (this.socket && this.socket.readyState === WebSocket.OPEN) {
                this.socket.send(JSON.stringify({
                    type: 'resize',
                    cols: this.terminal.cols,
                    rows: this.terminal.rows
                }));
            }
        });
        
        // Handle terminal input
        this.terminal.onData((data) => {
            this.handleTerminalInput(data);
        });
        
        // Handle terminal resize
        this.terminal.onResize((size) => {
            if (this.socket && this.socket.readyState === WebSocket.OPEN) {
                this.socket.send(JSON.stringify({
                    type: 'resize',
                    cols: size.cols,
                    rows: size.rows
                }));
            }
        });
        
        // Monitor scroll position to enable/disable auto-scroll
        this.setupScrollMonitoring();
    }
    
    /**
     * Setup scroll monitoring to detect manual scrolling
     */
    setupScrollMonitoring() {
        // Wait for terminal to be fully initialized
        setTimeout(() => {
            const viewport = this.terminal.element.querySelector('.xterm-viewport');
            if (viewport) {
                viewport.addEventListener('scroll', () => {
                    // Check if user scrolled to bottom (within 10px threshold to account for prompt)
                    const scrollBottom = viewport.scrollTop + viewport.clientHeight;
                    const isAtBottom = Math.abs(viewport.scrollHeight - scrollBottom) < 10;
                    
                    // Re-enable auto-scroll if user scrolled back to bottom
                    if (isAtBottom) {
                        this.autoScrollEnabled = true;
                        // Ensure we're truly at bottom
                        setTimeout(() => this.scrollToBottom(), 50);
                    } else {
                        // Disable auto-scroll if user scrolled up
                        this.autoScrollEnabled = false;
                    }
                });
            }
        }, 500);
    }
    
    /**
     * Connect to WebSocket server
     */
    connectWebSocket() {
        this.updateConnectionStatus('Connecting...', 'connecting');
        console.log('Connecting to WebSocket:', this.wsUrl);
        
        try {
            this.socket = new WebSocket(this.wsUrl);
            
            this.socket.onopen = () => {
                this.isConnected = true;
                this.updateConnectionStatus('Connected', 'connected');
                console.log('WebSocket connected');
            };
            
            this.socket.onmessage = (event) => {
                try {
                    const message = JSON.parse(event.data);
                    this.handleWebSocketMessage(message);
                } catch (error) {
                    console.error('Error parsing WebSocket message:', error);
                    this.terminal.writeln(`Error: ${error.message}`);
                }
            };
            
            this.socket.onerror = (error) => {
                console.error('WebSocket error:', error);
                console.error('WebSocket URL:', this.wsUrl);
                this.updateConnectionStatus('Connection Error', 'error');
                this.terminal.writeln(`\r\n\x1b[31mWebSocket connection error. URL: ${this.wsUrl}\x1b[0m\r\n`);
                this.terminal.writeln('\x1b[33mMake sure the backend server is running on http://localhost:8000\x1b[0m\r\n');
            };
            
            this.socket.onclose = (event) => {
                this.isConnected = false;
                this.updateConnectionStatus('Disconnected', 'disconnected');
                console.log('WebSocket disconnected', event.code, event.reason);
                
                // Only attempt to reconnect if it wasn't a normal closure
                if (event.code !== 1000 && event.code !== 1001) {
                    // Attempt to reconnect after 3 seconds
                    setTimeout(() => {
                        if (!this.isConnected) {
                            console.log('Attempting to reconnect...');
                            this.connectWebSocket();
                        }
                    }, 3000);
                }
            };
        } catch (error) {
            console.error('Error creating WebSocket:', error);
            this.updateConnectionStatus('Connection Failed', 'error');
            this.terminal.writeln(`\r\n\x1b[31mFailed to connect: ${error.message}\x1b[0m\r\n`);
        }
    }
    
    /**
     * Scroll terminal to bottom, ensuring prompt and previous line are visible
     */
    scrollToBottom() {
        if (!this.terminal) return;
        
        try {
            // Get the viewport element
            const viewport = this.terminal.element.querySelector('.xterm-viewport');
            if (viewport) {
                // Scroll to absolute bottom - since terminal is constrained, this should show the prompt
                const scrollHeight = viewport.scrollHeight;
                const clientHeight = viewport.clientHeight;
                
                // Scroll to show the last content (which should be the prompt)
                // The terminal is constrained, so scrolling to bottom should show the prompt
                viewport.scrollTop = scrollHeight;
                
                // Multiple attempts to ensure we're at the bottom
                setTimeout(() => {
                    viewport.scrollTop = viewport.scrollHeight;
                }, 10);
                
                setTimeout(() => {
                    viewport.scrollTop = viewport.scrollHeight;
                }, 50);
                
                setTimeout(() => {
                    // Final scroll to absolute bottom
                    viewport.scrollTop = viewport.scrollHeight;
                }, 100);
            }
            
            // Also use terminal's scroll method if available
            if (this.terminal.scrollToBottom) {
                this.terminal.scrollToBottom();
            }
            
            // Force a refresh to ensure prompt is visible
            if (this.terminal.refresh) {
                this.terminal.refresh(0, this.terminal.rows - 1);
            }
        } catch (error) {
            console.error('Error scrolling to bottom:', error);
        }
    }
    
    /**
     * Handle WebSocket messages
     */
    handleWebSocketMessage(message) {
        switch (message.type) {
            case 'output':
                this.terminal.write(message.data);
                // Try to extract working directory from prompt
                this.extractWorkingDirectory(message.data);
                // Auto-scroll to bottom when output is received
                if (this.autoScrollEnabled) {
                    // Use multiple timeouts to ensure DOM is fully updated and prompt is visible
                    // Stagger the scrolls to account for rendering delays
                    setTimeout(() => this.scrollToBottom(), 5);
                    setTimeout(() => this.scrollToBottom(), 20);
                    setTimeout(() => this.scrollToBottom(), 50);
                    setTimeout(() => this.scrollToBottom(), 100);
                    setTimeout(() => this.scrollToBottom(), 200);
                }
                break;
                
            case 'error':
                // Enhanced error formatting with background color
                this.terminal.write(`\x1b[41m\x1b[37m${message.data}\x1b[0m`);
                // Check if it's a command not found error and suggest alternatives
                this.suggestCommand(message.data);
                // Auto-scroll to bottom for errors too
                if (this.autoScrollEnabled) {
                    setTimeout(() => this.scrollToBottom(), 5);
                    setTimeout(() => this.scrollToBottom(), 20);
                    setTimeout(() => this.scrollToBottom(), 50);
                    setTimeout(() => this.scrollToBottom(), 100);
                    setTimeout(() => this.scrollToBottom(), 200);
                }
                break;
                
            case 'history':
                // Replace current line with history command
                this.currentLine = message.data || '';
                this.terminal.write('\r\x1b[K'); // Clear line
                this.terminal.write(this.currentLine);
                break;
                
            case 'pong':
                // Keep-alive response
                break;
                
            default:
                console.warn('Unknown message type:', message.type);
        }
    }
    
    /**
     * Extract working directory from prompt output
     */
    extractWorkingDirectory(output) {
        // Look for prompt pattern: PS path> or similar
        const promptMatch = output.match(/PS\s+([^\s>]+)>/);
        if (promptMatch) {
            this.workingDirectory = promptMatch[1];
            this.updateWorkingDirectoryDisplay();
        }
    }
    
    /**
     * Update working directory display in footer
     */
    updateWorkingDirectoryDisplay() {
        const workingDirElement = document.getElementById('working-dir');
        if (workingDirElement) {
            const displayPath = this.workingDirectory || '-';
            workingDirElement.textContent = `Working Directory: ${displayPath}`;
        }
    }
    
    /**
     * Suggest similar commands when command not found
     */
    suggestCommand(errorMessage) {
        // Check if error is about command not found
        if (errorMessage.includes('not in the allowed list') || 
            errorMessage.includes('not allowed') ||
            errorMessage.includes('not found')) {
            
            // Extract command from error or use current line
            const commandMatch = errorMessage.match(/Command\s+'([^']+)'/);
            const failedCommand = commandMatch ? commandMatch[1] : this.currentLine.trim().split(/\s+/)[0];
            
            if (failedCommand) {
                const suggestions = this.getCommandSuggestions(failedCommand);
                if (suggestions.length > 0) {
                    this.terminal.write(`\r\n\x1b[33mDid you mean:\x1b[0m\r\n`);
                    suggestions.slice(0, 3).forEach(cmd => {
                        this.terminal.write(`  \x1b[36m${cmd}\x1b[0m\r\n`);
                    });
                }
            }
        }
    }
    
    /**
     * Get command suggestions based on similarity
     */
    getCommandSuggestions(command) {
        if (!command) return [];
        
        const lowerCommand = command.toLowerCase();
        const suggestions = [];
        
        // Exact match check
        for (const cmd of this.availableCommands) {
            if (cmd.toLowerCase() === lowerCommand) {
                return []; // Command exists, no suggestions needed
            }
        }
        
        // Find similar commands (Levenshtein distance or substring match)
        for (const cmd of this.availableCommands) {
            const lowerCmd = cmd.toLowerCase();
            
            // Check if command starts with input
            if (lowerCmd.startsWith(lowerCommand)) {
                suggestions.push(cmd);
            }
            // Check if input starts with command
            else if (lowerCommand.startsWith(lowerCmd)) {
                suggestions.push(cmd);
            }
            // Check for similar characters
            else if (this.stringSimilarity(lowerCommand, lowerCmd) > 0.6) {
                suggestions.push(cmd);
            }
        }
        
        // Sort by similarity
        suggestions.sort((a, b) => {
            const simA = this.stringSimilarity(lowerCommand, a.toLowerCase());
            const simB = this.stringSimilarity(lowerCommand, b.toLowerCase());
            return simB - simA;
        });
        
        return suggestions;
    }
    
    /**
     * Calculate string similarity (simple Levenshtein-based)
     */
    stringSimilarity(str1, str2) {
        const longer = str1.length > str2.length ? str1 : str2;
        const shorter = str1.length > str2.length ? str2 : str1;
        
        if (longer.length === 0) return 1.0;
        
        // Check for substring match
        if (longer.includes(shorter)) return 0.8;
        
        // Simple similarity based on common characters
        let matches = 0;
        for (let i = 0; i < shorter.length; i++) {
            if (longer.includes(shorter[i])) matches++;
        }
        
        return matches / longer.length;
    }
    
    /**
     * Handle terminal input
     */
    handleTerminalInput(data) {
        // Handle special keys
        if (data === '\r' || data === '\n' || data === '\r\n') {
            // Enter key - send command
            if (this.currentLine.trim()) {
                this.commandHistory.push(this.currentLine);
                this.historyIndex = this.commandHistory.length;
            }
            
            this.sendCommand(this.currentLine);
            this.currentLine = '';
            return;
        }
        
        // Handle backspace
        if (data === '\x7f' || data === '\b') {
            if (this.currentLine.length > 0) {
                this.currentLine = this.currentLine.slice(0, -1);
                this.terminal.write('\b \b');
            }
            return;
        }
        
        // Handle Ctrl+C
        if (data === '\x03') {
            this.terminal.write('^C\r\n');
            this.currentLine = '';
            this.historySearchMode = false;
            // Send interrupt signal (would need backend support)
            return;
        }
        
        // Handle Ctrl+L (clear)
        if (data === '\x0c') {
            this.terminal.clear();
            this.currentLine = '';
            this.historySearchMode = false;
            return;
        }
        
        // Handle Ctrl+R (reverse history search)
        if (data === '\x12') {
            this.startHistorySearch();
            return;
        }
        
        // Handle arrow keys
        if (data === '\x1b[A') { // Up arrow
            if (this.commandHistory.length > 0) {
                if (this.historyIndex > 0) {
                    this.historyIndex--;
                }
                const command = this.commandHistory[this.historyIndex] || '';
                this.replaceCurrentLine(command);
            }
            return;
        }
        
        if (data === '\x1b[B') { // Down arrow
            if (this.historyIndex < this.commandHistory.length - 1) {
                this.historyIndex++;
                const command = this.commandHistory[this.historyIndex] || '';
                this.replaceCurrentLine(command);
            } else {
                this.historyIndex = this.commandHistory.length;
                this.replaceCurrentLine('');
            }
            return;
        }
        
        // Handle history search input
        if (this.historySearchMode) {
            if (data === '\r' || data === '\n') {
                // Enter - use selected command
                if (this.historySearchResults.length > 0 && this.historySearchIndex >= 0) {
                    const selectedCommand = this.commandHistory[this.historySearchResults[this.historySearchIndex]];
                    this.currentLine = selectedCommand;
                    this.terminal.write('\r\n');
                    this.terminal.write(selectedCommand);
                }
                this.historySearchMode = false;
                return;
            } else if (data === '\x7f' || data === '\b') {
                // Backspace in search
                if (this.historySearchQuery.length > 0) {
                    this.historySearchQuery = this.historySearchQuery.slice(0, -1);
                    this.performHistorySearch();
                }
                return;
            } else if (data >= ' ') {
                // Add character to search query
                this.historySearchQuery += data;
                this.performHistorySearch();
                return;
            }
        }
        
        // Regular character input
        if (data >= ' ' || data === '\t') {
            this.currentLine += data;
            this.terminal.write(data);
        }
    }
    
    /**
     * Replace current line with new text
     */
    replaceCurrentLine(newText) {
        // Clear current line
        const currentLength = this.currentLine.length;
        this.terminal.write('\r');
        for (let i = 0; i < currentLength; i++) {
            this.terminal.write(' ');
        }
        this.terminal.write('\r');
        
        // Write new line
        this.currentLine = newText;
        this.terminal.write(newText);
    }
    
    /**
     * Start reverse history search (Ctrl+R)
     */
    startHistorySearch() {
        if (this.commandHistory.length === 0) {
            this.terminal.write('\r\n\x1b[33mNo command history available\x1b[0m\r\n');
            return;
        }
        
        this.historySearchMode = true;
        this.historySearchQuery = '';
        this.historySearchResults = [];
        this.historySearchIndex = -1;
        this.terminal.write('\r\n\x1b[33m(reverse-i-search)\'\x1b[0m: ');
    }
    
    /**
     * Send command to server
     */
    sendCommand(command) {
        if (!this.socket || this.socket.readyState !== WebSocket.OPEN) {
            this.terminal.writeln('\r\n\x1b[31mNot connected to server\x1b[0m\r\n');
            return;
        }
        
        // Record command start time for execution time display
        this.commandStartTime = Date.now();
        
        // Ensure we're scrolled to bottom before sending command
        this.scrollToBottom();
        
        // Send the full command line with newline
        this.socket.send(JSON.stringify({
            type: 'input',
            data: command + '\r\n'
        }));
        
        // Auto-scroll after sending command
        setTimeout(() => this.scrollToBottom(), 50);
    }
    
    /**
     * Perform history search
     */
    performHistorySearch() {
        if (!this.historySearchQuery) {
            this.historySearchResults = [];
            this.historySearchIndex = -1;
            this.terminal.write('\r\x1b[K\x1b[33m(reverse-i-search)\'\x1b[0m: ');
            return;
        }
        
        // Find matching commands
        this.historySearchResults = [];
        for (let i = this.commandHistory.length - 1; i >= 0; i--) {
            if (this.commandHistory[i].toLowerCase().includes(this.historySearchQuery.toLowerCase())) {
                this.historySearchResults.push(i);
            }
        }
        
        if (this.historySearchResults.length > 0) {
            this.historySearchIndex = 0;
            const matchIndex = this.historySearchResults[0];
            const matchCommand = this.commandHistory[matchIndex];
            
            this.terminal.write('\r\x1b[K');
            this.terminal.write(`\x1b[33m(reverse-i-search)\'${this.historySearchQuery}\'\x1b[0m: ${matchCommand}`);
        } else {
            this.terminal.write('\r\x1b[K');
            this.terminal.write(`\x1b[33m(reverse-i-search)\'${this.historySearchQuery}\'\x1b[0m: \x1b[31m(no matches)\x1b[0m`);
        }
    }
    
    /**
     * Update connection status indicator with better messages
     */
    updateConnectionStatus(status, className) {
        const statusElement = document.getElementById('connection-status');
        if (statusElement) {
            let displayStatus = status;
            
            // Enhance status messages
            if (status === 'Connecting...') {
                displayStatus = 'Connecting to server...';
            } else if (status === 'Connected') {
                displayStatus = 'Connected ✓';
            } else if (status === 'Disconnected') {
                displayStatus = 'Disconnected';
            } else if (status === 'Connection Error' || status === 'Connection Failed') {
                displayStatus = 'Connection Error ✗';
            }
            
            statusElement.textContent = displayStatus;
            statusElement.className = `status-indicator ${className}`;
        }
    }
}

// Initialize terminal when DOM is loaded
document.addEventListener('DOMContentLoaded', () => {
    new MDE4CPPTerminal();
});
