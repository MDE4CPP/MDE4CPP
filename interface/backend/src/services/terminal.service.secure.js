const path = require('path');
const logger = require('../utils/logger');
const config = require('../config');
const { validateCommand, validatePath } = require('../utils/commandValidator');
const terminalModel = require('../models/terminal.model');
const containerManager = require('./container.manager').getInstance();

/**
 * Secure Terminal Service
 * Executes commands in isolated Docker containers
 * This prevents any possibility of server compromise
 */
class SecureTerminalService {
    /**
     * Execute a command in an isolated container
     * @param {string} sessionId - Session ID
     * @param {string} command - Command to execute
     * @param {function} onOutput - Output callback
     * @param {function} onError - Error callback
     * @param {function} onExit - Exit callback
     * @returns {Promise<object>} Execution result
     */
    async executeCommand(sessionId, command, onOutput, onError, onExit) {
        const session = terminalModel.getSession(sessionId);
        if (!session) {
            throw new Error('Session not found');
        }
        
        // Update activity
        terminalModel.updateActivity(sessionId);
        containerManager.updateActivity(sessionId);
        
        // Validate command (still validate even in container for safety)
        const validation = validateCommand(command, session.workingDirectory);
        if (!validation.valid) {
            const errorMsg = `Error: ${validation.error}\r\n`;
            onError(errorMsg);
            onExit(1, 'Command validation failed');
            return { exitCode: 1, error: validation.error };
        }
        
        // Add to history
        terminalModel.addToHistory(sessionId, validation.sanitizedCommand);
        
        // Handle special commands
        const baseCommand = validation.sanitizedCommand.trim().toLowerCase();
        
        // Handle cd command (update session state only, actual cd happens in container)
        if (baseCommand.startsWith('cd ')) {
            return this.handleCdCommand(sessionId, validation.sanitizedCommand, onOutput, onError, onExit);
        }
        
        // Handle pwd/get-location
        if (baseCommand === 'pwd' || baseCommand === 'get-location') {
            onOutput(`${session.workingDirectory}\r\n`);
            onExit(0, 'Success');
            return { exitCode: 0 };
        }
        
        // Handle clear/cls
        if (baseCommand === 'clear' || baseCommand === 'cls') {
            onOutput('\x1b[2J\x1b[H');
            onExit(0, 'Success');
            return { exitCode: 0 };
        }
        
        // Handle file viewing commands
        const fileViewCommands = ['cat', 'head', 'tail', 'type', 'get-content', 'more', 'less'];
        if (fileViewCommands.includes(baseCommand)) {
            return this.handleFileViewCommand(sessionId, validation.sanitizedCommand, baseCommand, onOutput, onError, onExit);
        }
        
        // Handle search commands
        const searchCommands = ['find', 'grep', 'select-string'];
        if (searchCommands.includes(baseCommand)) {
            return this.handleSearchCommand(sessionId, validation.sanitizedCommand, baseCommand, onOutput, onError, onExit);
        }
        
        // Execute command in container
        // Build full command with cd to working directory
        // Map Windows paths to container paths
        let containerWorkingDir = session.workingDirectory;
        if (containerWorkingDir.startsWith(config.mde4cpp.home)) {
            containerWorkingDir = containerWorkingDir.replace(config.mde4cpp.home, '/mde4cpp');
        }
        
        const fullCommand = `cd "${containerWorkingDir}" && ${validation.sanitizedCommand}`;
        
        return containerManager.executeCommand(sessionId, fullCommand, onOutput, onError, onExit);
    }
    
    /**
     * Handle cd command
     */
    async handleCdCommand(sessionId, command, onOutput, onError, onExit) {
        const session = terminalModel.getSession(sessionId);
        if (!session) {
            onError('Session not found\r\n');
            onExit(1, 'Session error');
            return { exitCode: 1 };
        }
        
        // Extract path
        const parts = command.trim().split(/\s+/);
        let targetPath = parts.length > 1 ? parts.slice(1).join(' ') : '';
        targetPath = targetPath.replace(/^["']|["']$/g, '');
        
        if (!targetPath) {
            targetPath = config.mde4cpp.home; // MDE4CPP_HOME
        }
        
        // Validate path
        const pathValidation = validatePath(targetPath, session.workingDirectory);
        if (!pathValidation.valid) {
            onError(`cd: ${pathValidation.error}\r\n`);
            onExit(1, 'Path validation failed');
            return { exitCode: 1 };
        }
        
        // Update working directory in session
        terminalModel.updateWorkingDirectory(sessionId, pathValidation.normalizedPath);
        onExit(0, 'Success');
        return { exitCode: 0 };
    }
    
    /**
     * Initialize terminal session
     * Creates container for the session
     */
    async initializeSession(sessionId, onOutput) {
        const session = terminalModel.getSession(sessionId);
        if (!session) {
            return;
        }
        
        try {
            // Create container for this session
            await containerManager.createContainer(sessionId);
            
            const welcomeMessage = `\r\nMDE4CPP Secure Terminal\r\n=======================\r\nRunning in isolated container (Docker)\r\nMDE4CPP_HOME: /mde4cpp (read-only)\r\nWorking Directory: ${session.workingDirectory}\r\n\r\nSecurity Features:\r\n  - Network isolation (no internet access)\r\n  - Resource limits (CPU, memory)\r\n  - Read-only filesystem for MDE4CPP_HOME\r\n  - Non-root user execution\r\n  - Automatic cleanup\r\n\r\nAvailable commands:\r\n  - gradlew, gradlew.bat - Gradle wrapper commands\r\n  - cd, dir, ls, pwd - Navigation commands\r\n  - cat, head, tail, type, get-content - File viewing commands\r\n  - find, grep, select-string - Search commands\r\n  - Limited PowerShell commands (MDE4CPP operations only)\r\n\r\nType 'help' for more information.\r\n\r\n`;
            
            onOutput(welcomeMessage);
            
            // Show prompt
            const prompt = this.getPrompt(session.workingDirectory);
            onOutput(prompt);
        } catch (error) {
            logger.error(`Failed to initialize secure terminal session ${sessionId}:`, error);
            onOutput(`\r\nERROR: Failed to create secure container: ${error.message}\r\n`);
            onOutput('Terminal session cannot be started securely.\r\n');
        }
    }
    
    /**
     * Handle file viewing commands
     */
    async handleFileViewCommand(sessionId, command, baseCommand, onOutput, onError, onExit) {
        const session = terminalModel.getSession(sessionId);
        if (!session) {
            onError('Session not found\r\n');
            onExit(1, 'Session error');
            return { exitCode: 1 };
        }
        
        // Extract file path from command
        const parts = command.trim().split(/\s+/);
        let filePath = '';
        
        // Handle different command formats
        if (baseCommand === 'head' || baseCommand === 'tail') {
            // head -n 10 file.txt or head file.txt
            for (let i = 1; i < parts.length; i++) {
                if (!parts[i].startsWith('-')) {
                    filePath = parts.slice(i).join(' ');
                    break;
                }
            }
        } else {
            // cat file.txt, type file.txt, get-content file.txt
            filePath = parts.slice(1).join(' ').replace(/^["']|["']$/g, '');
        }
        
        if (!filePath) {
            onError(`Error: ${baseCommand} requires a file path\r\n`);
            onExit(1, 'Missing file path');
            return { exitCode: 1 };
        }
        
        // Validate path
        const pathValidation = validatePath(filePath, session.workingDirectory);
        if (!pathValidation.valid) {
            onError(`${baseCommand}: ${pathValidation.error}\r\n`);
            onExit(1, 'Path validation failed');
            return { exitCode: 1 };
        }
        
        // Map Windows commands to Linux equivalents for container
        let containerCommand = command;
        if (baseCommand === 'type') {
            // Windows 'type' -> Linux 'cat'
            containerCommand = command.replace(/^type\s+/i, 'cat ');
        } else if (baseCommand === 'get-content') {
            // PowerShell 'get-content' -> Linux 'cat'
            containerCommand = command.replace(/^get-content\s+/i, 'cat ');
        }
        
        // Map Windows paths to container paths
        let containerFilePath = pathValidation.normalizedPath;
        if (containerFilePath.startsWith(config.mde4cpp.home)) {
            containerFilePath = containerFilePath.replace(config.mde4cpp.home, '/mde4cpp');
        } else if (containerFilePath.startsWith(config.storage.root)) {
            // Workspace path
            const relativePath = path.relative(config.storage.root, containerFilePath);
            containerFilePath = path.join(config.terminal.docker.workingDir, relativePath);
        }
        
        // Replace file path in command with container path
        containerCommand = containerCommand.replace(filePath, containerFilePath);
        
        // Map working directory
        let containerWorkingDir = session.workingDirectory;
        if (containerWorkingDir.startsWith(config.mde4cpp.home)) {
            containerWorkingDir = containerWorkingDir.replace(config.mde4cpp.home, '/mde4cpp');
        } else if (containerWorkingDir.startsWith(config.storage.root)) {
            const relativePath = path.relative(config.storage.root, containerWorkingDir);
            containerWorkingDir = path.join(config.terminal.docker.workingDir, relativePath);
        }
        
        const fullCommand = `cd "${containerWorkingDir}" && ${containerCommand}`;
        
        return containerManager.executeCommand(sessionId, fullCommand, onOutput, onError, onExit);
    }
    
    /**
     * Handle search commands
     */
    async handleSearchCommand(sessionId, command, baseCommand, onOutput, onError, onExit) {
        const session = terminalModel.getSession(sessionId);
        if (!session) {
            onError('Session not found\r\n');
            onExit(1, 'Session error');
            return { exitCode: 1 };
        }
        
        // Map PowerShell select-string to grep
        let containerCommand = command;
        if (baseCommand === 'select-string') {
            // PowerShell 'select-string' -> Linux 'grep'
            // select-string "pattern" file.txt -> grep "pattern" file.txt
            containerCommand = command.replace(/^select-string\s+/i, 'grep ');
        }
        
        // Extract paths from command for validation
        const parts = command.trim().split(/\s+/);
        let searchPath = '';
        
        if (baseCommand === 'find') {
            // find . -name "*.txt" or find /path
            for (let i = 1; i < parts.length; i++) {
                if (!parts[i].startsWith('-') && !parts[i].startsWith('/')) {
                    searchPath = parts[i];
                    break;
                }
            }
            if (!searchPath) {
                searchPath = '.'; // Default to current directory
            }
        } else if (baseCommand === 'grep' || baseCommand === 'select-string') {
            // grep "pattern" file.txt - path is usually the last argument
            for (let i = parts.length - 1; i > 0; i--) {
                if (!parts[i].startsWith('-') && !parts[i].startsWith('/')) {
                    searchPath = parts[i];
                    break;
                }
            }
        }
        
        // Validate path if provided
        if (searchPath && searchPath !== '.') {
            const pathValidation = validatePath(searchPath, session.workingDirectory);
            if (!pathValidation.valid) {
                onError(`${baseCommand}: ${pathValidation.error}\r\n`);
                onExit(1, 'Path validation failed');
                return { exitCode: 1 };
            }
            
            // Map Windows paths to container paths
            let containerPath = pathValidation.normalizedPath;
            if (containerPath.startsWith(config.mde4cpp.home)) {
                containerPath = containerPath.replace(config.mde4cpp.home, '/mde4cpp');
            } else if (containerPath.startsWith(config.storage.root)) {
                const relativePath = path.relative(config.storage.root, containerPath);
                containerPath = path.join(config.terminal.docker.workingDir, relativePath);
            }
            
            // Replace path in command
            containerCommand = containerCommand.replace(searchPath, containerPath);
        }
        
        // Map working directory
        let containerWorkingDir = session.workingDirectory;
        if (containerWorkingDir.startsWith(config.mde4cpp.home)) {
            containerWorkingDir = containerWorkingDir.replace(config.mde4cpp.home, '/mde4cpp');
        } else if (containerWorkingDir.startsWith(config.storage.root)) {
            const relativePath = path.relative(config.storage.root, containerWorkingDir);
            containerWorkingDir = path.join(config.terminal.docker.workingDir, relativePath);
        }
        
        const fullCommand = `cd "${containerWorkingDir}" && ${containerCommand}`;
        
        return containerManager.executeCommand(sessionId, fullCommand, onOutput, onError, onExit);
    }
    
    /**
     * Get terminal prompt with improved formatting
     */
    getPrompt(workingDir) {
        const relativePath = path.relative(config.mde4cpp.home, workingDir);
        let displayPath = relativePath ? relativePath : '.';
        
        // Normalize path separators for display
        displayPath = displayPath.replace(/\\/g, '/');
        
        // Color coding: use ANSI escape codes for terminal colors
        // Green for path, reset for prompt
        return `\x1b[32mPS\x1b[0m \x1b[36m${displayPath}\x1b[0m> `;
    }
    
    /**
     * Cleanup session (destroy container)
     */
    async cleanupSession(sessionId) {
        try {
            await containerManager.destroyContainer(sessionId);
        } catch (error) {
            logger.error(`Failed to cleanup session ${sessionId}:`, error);
        }
    }
    
    /**
     * Get command history
     */
    getHistory(sessionId, offset) {
        return terminalModel.getHistoryCommand(sessionId, offset);
    }
}

module.exports = new SecureTerminalService();
