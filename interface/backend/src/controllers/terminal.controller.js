const { v4: uuidv4 } = require('uuid');
const logger = require('../utils/logger');
const config = require('../config');
// Use secure terminal service if containers are enabled
const terminalService = config.terminal.useContainers 
    ? require('../services/terminal.service.secure')
    : require('../services/terminal.service');
const terminalModel = require('../models/terminal.model');

/**
 * Handle WebSocket connection for terminal
 * @param {WebSocket} ws - WebSocket connection
 */
async function handleTerminalConnection(ws) {
    const sessionId = uuidv4();
    logger.info(`New terminal session: ${sessionId} (secure: ${config.terminal.useContainers})`);
    
    // Create session
    terminalModel.createSession(sessionId);
    
    // Initialize terminal with welcome message
    await terminalService.initializeSession(sessionId, (output) => {
        if (ws.readyState === ws.OPEN) {
            ws.send(JSON.stringify({
                type: 'output',
                data: output
            }));
        }
    });
    
    // Handle incoming messages
    ws.on('message', (message) => {
        try {
            const data = JSON.parse(message.toString());
            
            switch (data.type) {
                case 'input':
                    handleInput(sessionId, data.data, ws);
                    break;
                    
                case 'resize':
                    // Handle terminal resize if needed
                    logger.debug(`Terminal resize: ${data.cols}x${data.rows}`);
                    break;
                    
                case 'ping':
                    // Keep-alive ping
                    ws.send(JSON.stringify({ type: 'pong' }));
                    break;
                    
                default:
                    logger.warn(`Unknown message type: ${data.type}`);
            }
        } catch (error) {
            logger.error('Error parsing WebSocket message:', error);
            ws.send(JSON.stringify({
                type: 'error',
                data: `Error: ${error.message}\r\n`
            }));
        }
    });
    
    // Handle connection close
    ws.on('close', async () => {
        logger.info(`Terminal session closed: ${sessionId}`);
        terminalModel.deactivateSession(sessionId);
        
        // Cleanup secure container if using containers
        if (config.terminal.useContainers && terminalService.cleanupSession) {
            await terminalService.cleanupSession(sessionId);
        }
        
        // Clean up after a delay (in case of reconnection)
        setTimeout(() => {
            terminalModel.removeSession(sessionId);
        }, 60000); // Remove after 1 minute
    });
    
    // Handle connection error
    ws.on('error', (error) => {
        logger.error(`Terminal WebSocket error for session ${sessionId}:`, error);
        terminalModel.deactivateSession(sessionId);
    });
}

/**
 * Handle terminal input
 * @param {string} sessionId - Session ID
 * @param {string} input - Input data
 * @param {WebSocket} ws - WebSocket connection
 */
function handleInput(sessionId, input, ws) {
    const session = terminalModel.getSession(sessionId);
    if (!session) {
        ws.send(JSON.stringify({
            type: 'error',
            data: 'Session not found\r\n'
        }));
        return;
    }
    
    // Initialize command line if not exists
    if (session.currentLine === undefined) {
        session.currentLine = '';
    }
    
    // Handle command execution (when full command is received with newline)
    if (input.endsWith('\r') || input.endsWith('\n') || input.endsWith('\r\n')) {
        // Extract command (remove trailing newlines)
        const command = input.replace(/[\r\n]+$/, '').trim();
        session.currentLine = '';
        
        if (!command) {
            // Empty command, just show prompt
            const prompt = terminalService.getPrompt(session.workingDirectory);
            ws.send(JSON.stringify({
                type: 'output',
                data: prompt
            }));
            return;
        }
        
        // Execute command
        executeCommand(sessionId, command, ws);
        return;
    }
    
    // Handle special keys (these come as escape sequences)
    if (input === '\x1b[A') { // Up arrow
        const command = terminalService.getHistory(sessionId, -1);
        if (command !== null) {
            session.currentLine = command;
            ws.send(JSON.stringify({
                type: 'history',
                data: command
            }));
        }
        return;
    }
    
    if (input === '\x1b[B') { // Down arrow
        const command = terminalService.getHistory(sessionId, 1);
        if (command !== null) {
            session.currentLine = command;
            ws.send(JSON.stringify({
                type: 'history',
                data: command
            }));
        } else {
            session.currentLine = '';
            ws.send(JSON.stringify({
                type: 'history',
                data: ''
            }));
        }
        return;
    }
    
    // For other input, the frontend handles it locally
    // We only process complete commands (with newline)
}

/**
 * Execute a command
 * @param {string} sessionId - Session ID
 * @param {string} command - Command to execute
 * @param {WebSocket} ws - WebSocket connection
 */
function executeCommand(sessionId, command, ws) {
    const session = terminalModel.getSession(sessionId);
    if (!session) {
        ws.send(JSON.stringify({
            type: 'error',
            data: 'Session not found\r\n'
        }));
        return;
    }
    
    // Don't echo the command - frontend terminal already displays user input
    // Execute command
    terminalService.executeCommand(
        sessionId,
        command,
        // onOutput
        (output) => {
            if (ws.readyState === ws.OPEN) {
                ws.send(JSON.stringify({
                    type: 'output',
                    data: output
                }));
            }
        },
        // onError
        (error) => {
            if (ws.readyState === ws.OPEN) {
                ws.send(JSON.stringify({
                    type: 'error',
                    data: error
                }));
            }
        },
        // onExit
        (exitCode, signal) => {
            // Show prompt after command completes
            const session = terminalModel.getSession(sessionId);
            if (session && ws.readyState === ws.OPEN) {
                const prompt = terminalService.getPrompt(session.workingDirectory);
                ws.send(JSON.stringify({
                    type: 'output',
                    data: prompt
                }));
            }
        }
    ).catch((error) => {
        logger.error(`Error executing command in session ${sessionId}:`, error);
        if (ws.readyState === ws.OPEN) {
            ws.send(JSON.stringify({
                type: 'error',
                data: `Error: ${error.message}\r\n`
            }));
            
            // Show prompt after error
            const session = terminalModel.getSession(sessionId);
            if (session) {
                const prompt = terminalService.getPrompt(session.workingDirectory);
                ws.send(JSON.stringify({
                    type: 'output',
                    data: prompt
                }));
            }
        }
    });
}

module.exports = {
    handleTerminalConnection
};
