const path = require('path');
const logger = require('./logger');
const config = require('../config');

/**
 * Command validator for MDE4CPP terminal
 * Ensures only safe, MDE4CPP-related commands are executed
 */

// Allowed commands whitelist
const ALLOWED_COMMANDS = {
    // Gradle commands
    'gradlew': true,
    'gradlew.bat': true,
    'gradle': true,
    
    // Navigation commands
    'cd': true,
    'dir': true,
    'ls': true,
    'pwd': true,
    'get-location': true, // PowerShell equivalent of pwd
    
    // PowerShell built-ins (safe ones)
    'echo': true,
    'write-host': true,
    'write-output': true,
    'get-childitem': true,
    'get-item': true,
    'test-path': true,
    
    // File viewing commands
    'cat': true,
    'head': true,
    'tail': true,
    'type': true,
    'get-content': true,
    'more': true,
    'less': true,
    
    // Search commands
    'find': true,
    'grep': true,
    'select-string': true,
    
    // Environment variable commands
    'set': true,
    
    // MDE4CPP scripts
    'powershell': true, // For running PowerShell scripts
    
    // Help commands
    'help': true,
    'get-help': true,
    'man': true,
    
    // Clear terminal
    'clear': true,
    'cls': true,
};

// Excluded directory patterns (security - prevent access to sensitive folders)
const EXCLUDED_PATTERNS = [
    /\.git(\/|\\|$)/i,
    /\.env/i,
    /node_modules(\/|\\|$)/i,
    /\.idea(\/|\\|$)/i,
    /\.vscode(\/|\\|$)/i,
    /\.gradle(\/|\\|$)/i,
    /\.settings(\/|\\|$)/i,
    /interface[\/\\]backend(\/|\\|$)/i,
    /interface[\/\\]frontend(\/|\\|$)/i,
    /docker(\/|\\|$)/i,
    /ansible(\/|\\|$)/i,
    /\.github(\/|\\|$)/i,
    /logs(\/|\\|$)/i,
    /^storage[\/\\]/i,  // Block storage root, but allow workspace subdirs
];

// Allowed workspace pattern (exception for storage/builds/{sessionId}/)
const ALLOWED_WORKSPACE_PATTERN = /^storage[\/\\]builds[\/\\][a-f0-9-]+[\/\\]/i;

// Blocked dangerous commands
const BLOCKED_COMMANDS = [
    'rm', 'rmdir', 'del', 'delete', 'remove-item',
    'format', 'fdisk', 'diskpart',
    'shutdown', 'restart', 'reboot',
    'net', 'netstat', 'taskkill', 'kill',
    'reg', 'regedit',
    'sc', 'services.msc',
    'cmd', 'command', // Block nested shells
    'start', // Block starting arbitrary processes
    'invoke-expression', 'iex', // Block code execution
    'invoke-command', 'icm',
    'new-object', // Block object creation
    'add-type', // Block adding types
];

/**
 * Extract the base command from a command string
 * @param {string} command - Full command string
 * @returns {string} Base command name
 */
function extractBaseCommand(command) {
    if (!command || typeof command !== 'string') {
        return '';
    }
    
    // Remove leading/trailing whitespace
    command = command.trim();
    
    // Handle PowerShell variable assignments ($var = ...)
    if (command.startsWith('$')) {
        const match = command.match(/^\$[\w:]+\s*=\s*(.+)/);
        if (match) {
            command = match[1].trim();
        }
    }
    
    // Handle environment variable assignments (SET VAR=...)
    if (command.toUpperCase().startsWith('SET ')) {
        const match = command.match(/^SET\s+\w+\s*=\s*(.+)/i);
        if (match) {
            command = match[1].trim();
        }
    }
    
    // Extract first word (command name)
    const parts = command.split(/\s+/);
    let baseCommand = parts[0] || '';
    
    // Remove quotes if present
    baseCommand = baseCommand.replace(/^["']|["']$/g, '');
    
    // Remove path separators to get just the command name
    baseCommand = baseCommand.split(/[\\\/]/).pop();
    
    // Remove file extension for .bat, .exe, .ps1, etc.
    baseCommand = baseCommand.replace(/\.(bat|exe|ps1|cmd|sh)$/i, '');
    
    return baseCommand.toLowerCase();
}

/**
 * Check if a command is in the blocked list
 * @param {string} command - Command string
 * @returns {boolean} True if command is blocked
 */
function isBlockedCommand(command) {
    const baseCommand = extractBaseCommand(command);
    
    for (const blocked of BLOCKED_COMMANDS) {
        if (baseCommand === blocked.toLowerCase()) {
            return true;
        }
    }
    
    // Check for dangerous patterns
    const dangerousPatterns = [
        /invoke-expression/i,
        /iex\s+/i,
        /\.invoke\(/i,
        /new-object/i,
        /add-type/i,
        /\[system\./i,
    ];
    
    for (const pattern of dangerousPatterns) {
        if (pattern.test(command)) {
            return true;
        }
    }
    
    return false;
}

/**
 * Check if a command is allowed
 * @param {string} command - Command string
 * @returns {boolean} True if command is allowed
 */
function isAllowedCommand(command) {
    if (!command || typeof command !== 'string') {
        return false;
    }
    
    // Check if blocked first
    if (isBlockedCommand(command)) {
        return false;
    }
    
    const baseCommand = extractBaseCommand(command);
    
    // Check whitelist
    if (ALLOWED_COMMANDS[baseCommand]) {
        return true;
    }
    
    // Allow gradlew/gradle with MDE4CPP tasks
    if (baseCommand === 'gradlew' || baseCommand === 'gradle') {
        return true;
    }
    
    // Allow PowerShell script execution if it's an MDE4CPP script
    if (baseCommand === 'powershell' || command.includes('.ps1')) {
        // Check if it's an MDE4CPP script path
        const mde4cppPath = config.mde4cpp.home.toLowerCase();
        const commandLower = command.toLowerCase();
        if (commandLower.includes(mde4cppPath)) {
            return true;
        }
    }
    
    return false;
}

/**
 * Check if a path is allowed (not in excluded directories)
 * @param {string} pathToCheck - Path to check (can be absolute or relative)
 * @param {string} mde4cppHome - MDE4CPP_HOME absolute path
 * @returns {object} {allowed: boolean, error: string}
 */
function isPathAllowed(pathToCheck, mde4cppHome) {
    if (!pathToCheck) {
        return { allowed: true, error: null };
    }
    
    try {
        // Normalize path separators to forward slashes for pattern matching
        const normalizedPath = pathToCheck.replace(/\\/g, '/');
        
        // Check if path matches excluded patterns
        for (const pattern of EXCLUDED_PATTERNS) {
            if (pattern.test(normalizedPath)) {
                // Exception: Allow workspace directories (storage/builds/{sessionId}/)
                if (pattern.source === '^storage[\\/\\\\]/i' && ALLOWED_WORKSPACE_PATTERN.test(normalizedPath)) {
                    continue; // This is an allowed workspace directory
                }
                
                // Extract the excluded folder name for error message
                const match = normalizedPath.match(pattern);
                const folderName = match ? match[0].replace(/[\/\\]/g, '') : 'restricted folder';
                
                return {
                    allowed: false,
                    error: `Access to '${folderName}' is restricted for security reasons`
                };
            }
        }
        
        return { allowed: true, error: null };
    } catch (error) {
        return {
            allowed: false,
            error: `Path validation error: ${error.message}`
        };
    }
}

/**
 * Validate and normalize a path
 * @param {string} pathToValidate - Path to validate
 * @param {string} currentWorkingDir - Current working directory
 * @returns {object} {valid: boolean, normalizedPath: string, error: string}
 */
function validatePath(pathToValidate, currentWorkingDir) {
    if (!pathToValidate) {
        return { valid: true, normalizedPath: currentWorkingDir, error: null };
    }
    
    try {
        // Resolve path relative to current working directory
        let resolvedPath;
        if (path.isAbsolute(pathToValidate)) {
            resolvedPath = path.normalize(pathToValidate);
        } else {
            resolvedPath = path.resolve(currentWorkingDir, pathToValidate);
        }
        
        // Ensure path is within MDE4CPP_HOME or its subdirectories
        const mde4cppHome = path.resolve(config.mde4cpp.home);
        const relativePath = path.relative(mde4cppHome, resolvedPath);
        
        // Check if path tries to escape MDE4CPP_HOME
        if (relativePath.startsWith('..') || path.isAbsolute(relativePath)) {
            return {
                valid: false,
                normalizedPath: null,
                error: 'Path must be within MDE4CPP_HOME directory'
            };
        }
        
        // Check if path is in excluded directories (security check)
        const pathCheck = isPathAllowed(relativePath, mde4cppHome);
        if (!pathCheck.allowed) {
            return {
                valid: false,
                normalizedPath: null,
                error: pathCheck.error
            };
        }
        
        return {
            valid: true,
            normalizedPath: resolvedPath,
            error: null
        };
    } catch (error) {
        return {
            valid: false,
            normalizedPath: null,
            error: `Invalid path: ${error.message}`
        };
    }
}

/**
 * Validate a command for execution
 * @param {string} command - Command to validate
 * @param {string} currentWorkingDir - Current working directory
 * @returns {object} {valid: boolean, error: string, sanitizedCommand: string}
 */
function validateCommand(command, currentWorkingDir) {
    if (!command || typeof command !== 'string') {
        return {
            valid: false,
            error: 'Command cannot be empty',
            sanitizedCommand: null
        };
    }
    
    // Trim whitespace
    const trimmedCommand = command.trim();
    
    if (!trimmedCommand) {
        return {
            valid: false,
            error: 'Command cannot be empty',
            sanitizedCommand: null
        };
    }
    
    // Check if command is blocked
    if (isBlockedCommand(trimmedCommand)) {
        return {
            valid: false,
            error: `Command '${extractBaseCommand(trimmedCommand)}' is not allowed for security reasons`,
            sanitizedCommand: null
        };
    }
    
    // Check if command is allowed
    if (!isAllowedCommand(trimmedCommand)) {
        return {
            valid: false,
            error: `Command '${extractBaseCommand(trimmedCommand)}' is not in the allowed list. Only MDE4CPP-related commands are permitted.`,
            sanitizedCommand: null
        };
    }
    
    // Validate paths in command (for cd, dir, ls, file viewing, search, etc.)
    const pathCommands = [
        'cd', 'dir', 'ls', 'get-childitem', 'test-path',
        'cat', 'head', 'tail', 'type', 'get-content', 'more', 'less',
        'find', 'grep', 'select-string'
    ];
    const baseCommand = extractBaseCommand(trimmedCommand);
    
    if (pathCommands.includes(baseCommand)) {
        // Extract path argument(s)
        const parts = trimmedCommand.split(/\s+/);
        if (parts.length > 1) {
            // For commands like "find . -name", skip flags and get the path
            let pathArg = '';
            if (baseCommand === 'find' || baseCommand === 'grep') {
                // Find the first non-flag argument (usually the path)
                for (let i = 1; i < parts.length; i++) {
                    if (!parts[i].startsWith('-') && !parts[i].startsWith('/')) {
                        pathArg = parts[i];
                        break;
                    }
                }
            } else {
                // For other commands, path is usually the first argument after command
                pathArg = parts.slice(1).join(' ').replace(/^["']|["']$/g, '');
            }
            
            if (pathArg) {
                const pathValidation = validatePath(pathArg, currentWorkingDir);
                
                if (!pathValidation.valid) {
                    return {
                        valid: false,
                        error: pathValidation.error,
                        sanitizedCommand: null
                    };
                }
            }
        }
    }
    
    // Sanitize command (remove potentially dangerous characters while preserving functionality)
    let sanitizedCommand = trimmedCommand;
    
    // Remove null bytes and control characters (except newlines and tabs)
    sanitizedCommand = sanitizedCommand.replace(/[\x00-\x08\x0B-\x0C\x0E-\x1F\x7F]/g, '');
    
    return {
        valid: true,
        error: null,
        sanitizedCommand: sanitizedCommand
    };
}

module.exports = {
    validateCommand,
    validatePath,
    isPathAllowed,
    isAllowedCommand,
    isBlockedCommand,
    extractBaseCommand
};
