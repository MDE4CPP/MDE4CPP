const { spawn } = require('child_process');
const path = require('path');
const fs = require('fs-extra');
const logger = require('../utils/logger');
const config = require('../config');
const { validateCommand, validatePath } = require('../utils/commandValidator');
const terminalModel = require('../models/terminal.model');

/**
 * Execute a command in the terminal session
 * @param {string} sessionId - Session ID
 * @param {string} command - Command to execute
 * @param {function} onOutput - Callback for stdout data
 * @param {function} onError - Callback for stderr data
 * @param {function} onExit - Callback when command exits
 * @returns {Promise<object>} Command execution result
 */
async function executeCommand(sessionId, command, onOutput, onError, onExit) {
    const session = terminalModel.getSession(sessionId);
    if (!session) {
        throw new Error('Session not found');
    }
    
    // Update activity
    terminalModel.updateActivity(sessionId);
    
    // Validate command
    const validation = validateCommand(command, session.workingDirectory);
    if (!validation.valid) {
        const errorMsg = `Error: ${validation.error}\r\n`;
        onError(errorMsg);
        onExit(1, 'Command validation failed');
        return { exitCode: 1, error: validation.error };
    }
    
    // Add to history
    terminalModel.addToHistory(sessionId, validation.sanitizedCommand);
    
    // Handle special commands that need custom processing
    const baseCommand = validation.sanitizedCommand.trim().toLowerCase();
    
    // Handle cd command
    if (baseCommand.startsWith('cd ')) {
        return handleCdCommand(sessionId, validation.sanitizedCommand, onOutput, onError, onExit);
    }
    
    // Handle pwd/get-location
    if (baseCommand === 'pwd' || baseCommand === 'get-location') {
        onOutput(`${session.workingDirectory}\r\n`);
        onExit(0, 'Success');
        return { exitCode: 0 };
    }
    
    // Handle clear/cls
    if (baseCommand === 'clear' || baseCommand === 'cls') {
        // Send clear sequence (this will be handled by terminal)
        onOutput('\x1b[2J\x1b[H');
        onExit(0, 'Success');
        return { exitCode: 0 };
    }
    
    // Execute command using PowerShell
    return executePowerShellCommand(
        sessionId,
        validation.sanitizedCommand,
        session.workingDirectory,
        session.environment,
        onOutput,
        onError,
        onExit
    );
}

/**
 * Handle cd command
 * @param {string} sessionId - Session ID
 * @param {string} command - cd command
 * @param {function} onOutput - Output callback
 * @param {function} onError - Error callback
 * @param {function} onExit - Exit callback
 */
function handleCdCommand(sessionId, command, onOutput, onError, onExit) {
    const session = terminalModel.getSession(sessionId);
    if (!session) {
        onError('Session not found\r\n');
        onExit(1, 'Session error');
        return { exitCode: 1 };
    }
    
    // Extract path from cd command
    const parts = command.trim().split(/\s+/);
    let targetPath = parts.length > 1 ? parts.slice(1).join(' ') : '';
    
    // Remove quotes
    targetPath = targetPath.replace(/^["']|["']$/g, '');
    
    // If no path, go to MDE4CPP_HOME
    if (!targetPath) {
        targetPath = config.mde4cpp.home;
    }
    
    // Validate path
    const pathValidation = validatePath(targetPath, session.workingDirectory);
    
    if (!pathValidation.valid) {
        onError(`cd: ${pathValidation.error}\r\n`);
        onExit(1, 'Path validation failed');
        return { exitCode: 1 };
    }
    
    // Check if path exists
    if (!fs.pathExistsSync(pathValidation.normalizedPath)) {
        onError(`cd: The system cannot find the path specified: ${targetPath}\r\n`);
        onExit(1, 'Path not found');
        return { exitCode: 1 };
    }
    
    // Update working directory
    terminalModel.updateWorkingDirectory(sessionId, pathValidation.normalizedPath);
    onExit(0, 'Success');
    return { exitCode: 0 };
}

/**
 * Execute a PowerShell command
 * @param {string} sessionId - Session ID
 * @param {string} command - Command to execute
 * @param {string} workingDir - Working directory
 * @param {object} env - Environment variables
 * @param {function} onOutput - Output callback
 * @param {function} onError - Error callback
 * @param {function} onExit - Exit callback
 * @returns {Promise<object>} Execution result
 */
function executePowerShellCommand(sessionId, command, workingDir, env, onOutput, onError, onExit) {
    return new Promise((resolve) => {
        // Use PowerShell to execute the command
        // Wrap command in a way that preserves working directory and environment
        const psCommand = `
            $env:PWD = '${workingDir.replace(/'/g, "''")}'
            Set-Location -LiteralPath $env:PWD
            ${command}
        `;
        
        const psArgs = [
            '-NoProfile',
            '-NonInteractive',
            '-ExecutionPolicy', 'Bypass',
            '-Command', psCommand
        ];
        
        const psProcess = spawn('powershell.exe', psArgs, {
            cwd: workingDir,
            env: env,
            shell: false
        });
        
        let stdout = '';
        let stderr = '';
        let hasExited = false;
        
        // Handle stdout
        psProcess.stdout.on('data', (data) => {
            const output = data.toString();
            stdout += output;
            onOutput(output);
        });
        
        // Handle stderr
        psProcess.stderr.on('data', (data) => {
            const output = data.toString();
            stderr += output;
            onError(output);
        });
        
        // Handle process exit
        psProcess.on('exit', (code, signal) => {
            if (hasExited) return;
            hasExited = true;
            
            const exitCode = code !== null ? code : (signal ? 1 : 0);
            onExit(exitCode, signal || 'exited');
            
            resolve({
                exitCode,
                signal,
                stdout,
                stderr
            });
        });
        
        // Handle process error
        psProcess.on('error', (error) => {
            if (hasExited) return;
            hasExited = true;
            
            const errorMsg = `Error executing command: ${error.message}\r\n`;
            stderr += errorMsg;
            onError(errorMsg);
            onExit(1, 'process error');
            
            resolve({
                exitCode: 1,
                error: error.message,
                stdout,
                stderr
            });
        });
        
        // Timeout for long-running commands (10 minutes)
        const timeout = setTimeout(() => {
            if (!hasExited) {
                psProcess.kill();
                const timeoutMsg = '\r\nCommand timed out after 10 minutes\r\n';
                stderr += timeoutMsg;
                onError(timeoutMsg);
                onExit(124, 'timeout');
                resolve({
                    exitCode: 124,
                    error: 'Command timed out',
                    stdout,
                    stderr
                });
            }
        }, 10 * 60 * 1000);
        
        psProcess.on('exit', () => {
            clearTimeout(timeout);
        });
    });
}

/**
 * Initialize terminal session with welcome message
 * @param {string} sessionId - Session ID
 * @param {function} onOutput - Output callback
 */
function initializeSession(sessionId, onOutput) {
    const session = terminalModel.getSession(sessionId);
    if (!session) {
        return;
    }
    
    const welcomeMessage = `
MDE4CPP Terminal
================
MDE4CPP_HOME: ${config.mde4cpp.home}
Working Directory: ${session.workingDirectory}

Available commands:
  - gradlew, gradlew.bat - Gradle wrapper commands
  - cd, dir, ls, pwd - Navigation commands
  - PowerShell commands (limited to MDE4CPP operations)

Type 'help' for more information or start using MDE4CPP commands.

`;
    
    onOutput(welcomeMessage);
    
    // Show current directory prompt
    const prompt = getPrompt(session.workingDirectory);
    onOutput(prompt);
}

/**
 * Get terminal prompt
 * @param {string} workingDir - Working directory
 * @returns {string} Prompt string
 */
function getPrompt(workingDir) {
    const config = require('../config');
    const relativePath = path.relative(config.mde4cpp.home, workingDir);
    const displayPath = relativePath ? relativePath : '.';
    return `PS ${displayPath}> `;
}

/**
 * Get command history
 * @param {string} sessionId - Session ID
 * @param {number} offset - History offset (-1 for previous, 1 for next)
 * @returns {string|null} Command from history
 */
function getHistory(sessionId, offset) {
    return terminalModel.getHistoryCommand(sessionId, offset);
}

module.exports = {
    executeCommand,
    initializeSession,
    getPrompt,
    getHistory
};
