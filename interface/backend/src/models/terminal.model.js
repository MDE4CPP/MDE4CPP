/**
 * Terminal session storage
 * Stores session state (working directory, environment variables, command history)
 */
const path = require('path');
const sessions = new Map();

/**
 * Create a new terminal session
 * @param {string} sessionId - Unique session ID
 * @param {object} initialConfig - Initial configuration
 * @returns {object} Session object
 */
function createSession(sessionId, initialConfig = {}) {
    const config = require('../config');
    
    const session = {
        sessionId,
        workingDirectory: initialConfig.workingDirectory || config.mde4cpp.home,
        environment: {
            ...process.env,
            MDE4CPP_HOME: config.mde4cpp.home,
            MDE4CPP_ECLIPSE_HOME: path.resolve(config.mde4cpp.home, 'eclipse'),
            ORG_GRADLE_PROJECT_RELEASE: '1',
            ORG_GRADLE_PROJECT_DEBUG: '1',
            PATH: `${path.resolve(config.mde4cpp.home, 'application', 'tools')};${process.env.PATH}`,
            ...initialConfig.environment
        },
        commandHistory: [],
        historyIndex: -1,
        currentLine: '', // Track current command line being typed
        createdAt: new Date(),
        lastActivity: new Date(),
        active: true
    };
    
    sessions.set(sessionId, session);
    return session;
}

/**
 * Get session by ID
 * @param {string} sessionId - Session ID
 * @returns {object|null} Session object or null
 */
function getSession(sessionId) {
    return sessions.get(sessionId) || null;
}

/**
 * Update session working directory
 * @param {string} sessionId - Session ID
 * @param {string} newWorkingDir - New working directory
 * @returns {boolean} Success
 */
function updateWorkingDirectory(sessionId, newWorkingDir) {
    const session = sessions.get(sessionId);
    if (!session) return false;
    
    session.workingDirectory = newWorkingDir;
    session.lastActivity = new Date();
    return true;
}

/**
 * Add command to history
 * @param {string} sessionId - Session ID
 * @param {string} command - Command string
 */
function addToHistory(sessionId, command) {
    const session = sessions.get(sessionId);
    if (!session) return;
    
    // Don't add empty commands or duplicates of last command
    if (!command.trim() || 
        (session.commandHistory.length > 0 && 
         session.commandHistory[session.commandHistory.length - 1] === command)) {
        return;
    }
    
    session.commandHistory.push(command);
    session.historyIndex = session.commandHistory.length;
    session.lastActivity = new Date();
    
    // Keep only last 100 commands
    if (session.commandHistory.length > 100) {
        session.commandHistory.shift();
        session.historyIndex = session.commandHistory.length;
    }
}

/**
 * Get command from history
 * @param {string} sessionId - Session ID
 * @param {number} offset - Offset from current position (-1 for previous, 1 for next)
 * @returns {string|null} Command or null
 */
function getHistoryCommand(sessionId, offset) {
    const session = sessions.get(sessionId);
    if (!session || session.commandHistory.length === 0) return null;
    
    session.historyIndex += offset;
    
    if (session.historyIndex < 0) {
        session.historyIndex = -1;
        return '';
    }
    
    if (session.historyIndex >= session.commandHistory.length) {
        session.historyIndex = session.commandHistory.length;
        return '';
    }
    
    return session.commandHistory[session.historyIndex];
}

/**
 * Update session activity timestamp
 * @param {string} sessionId - Session ID
 */
function updateActivity(sessionId) {
    const session = sessions.get(sessionId);
    if (session) {
        session.lastActivity = new Date();
    }
}

/**
 * Deactivate session
 * @param {string} sessionId - Session ID
 */
function deactivateSession(sessionId) {
    const session = sessions.get(sessionId);
    if (session) {
        session.active = false;
    }
}

/**
 * Remove session
 * @param {string} sessionId - Session ID
 */
function removeSession(sessionId) {
    sessions.delete(sessionId);
}

/**
 * Clean up inactive sessions (older than timeout)
 * @param {number} timeoutMs - Timeout in milliseconds (default: 1 hour)
 */
function cleanupInactiveSessions(timeoutMs = 3600000) {
    const now = new Date();
    const toRemove = [];
    
    sessions.forEach((session, sessionId) => {
        if (!session.active || (now - session.lastActivity) > timeoutMs) {
            toRemove.push(sessionId);
        }
    });
    
    toRemove.forEach(sessionId => {
        sessions.delete(sessionId);
    });
    
    return toRemove.length;
}

/**
 * Get all active sessions
 * @returns {Array} Array of session objects
 */
function getAllSessions() {
    return Array.from(sessions.values()).filter(s => s.active);
}

// Cleanup inactive sessions every 30 minutes
setInterval(() => {
    cleanupInactiveSessions();
}, 30 * 60 * 1000);

module.exports = {
    createSession,
    getSession,
    updateWorkingDirectory,
    addToHistory,
    getHistoryCommand,
    updateActivity,
    deactivateSession,
    removeSession,
    cleanupInactiveSessions,
    getAllSessions
};
