require('dotenv').config();
const path = require('path');
const fs = require('fs-extra');

/**
 * Resolve path to absolute path for production reliability
 * @param {string} relativePath - Path (relative or absolute)
 * @param {string} fallbackRelative - Fallback relative path from backend directory
 * @returns {string} Absolute path
 */
function resolvePath(relativePath, fallbackRelative) {
    if (!relativePath) {
        return path.resolve(__dirname, '../../', fallbackRelative);
    }
    if (path.isAbsolute(relativePath)) {
        return relativePath;
    }
    // If relative, resolve from backend directory
    return path.resolve(__dirname, '../../', relativePath);
}

const config = {
    env: process.env.NODE_ENV || 'development',
    port: parseInt(process.env.PORT, 10) || 8000,
    host: process.env.HOST || '0.0.0.0',
    
    mde4cpp: {
        // MDE4CPP_HOME should be absolute path in production
        // Default: resolve from backend directory (assumes interface/backend/src/config structure)
        // __dirname is at: interface/backend/src/config
        // Need to go up 4 levels: config -> src -> backend -> interface -> MDE4CPP root
        home: process.env.MDE4CPP_HOME 
            ? (path.isAbsolute(process.env.MDE4CPP_HOME) 
                ? process.env.MDE4CPP_HOME 
                : path.resolve(process.env.MDE4CPP_HOME))
            : path.resolve(__dirname, '../../../../'),
        // Workspace root is relative to storage root, not used directly
        workspaceRoot: process.env.MDE4CPP_WORKSPACE_ROOT || 'builds'
    },
    
    storage: {
        // Storage root: absolute path if provided, otherwise relative to backend directory
        root: process.env.STORAGE_ROOT 
            ? resolvePath(process.env.STORAGE_ROOT, '')
            : path.resolve(__dirname, '../../storage'),
        uploadMaxSizeMB: parseInt(process.env.UPLOAD_MAX_SIZE_MB, 10) || 50,
        outputRetentionHours: parseInt(process.env.OUTPUT_RETENTION_HOURS, 10) || 24
    },
    
    build: {
        maxConcurrentBuilds: parseInt(process.env.MAX_CONCURRENT_BUILDS, 10) || 3,
        timeoutSeconds: parseInt(process.env.BUILD_TIMEOUT_SECONDS, 10) || 600
    },
    
    powershell: {
        executionPolicy: process.env.POWERSHELL_EXECUTION_POLICY || 'Bypass'
    },
    
    cors: {
        origin: process.env.CORS_ORIGIN 
            ? process.env.CORS_ORIGIN.split(',').map(o => o.trim())
            : (process.env.NODE_ENV === 'production' ? ['http://localhost:3000'] : '*')
    },
    
    logging: {
        level: process.env.LOG_LEVEL || 'info',
        file: process.env.LOG_FILE 
            ? resolvePath(process.env.LOG_FILE, '')
            : path.resolve(__dirname, '../../logs/app.log')
    },
    
    // Plugin API configuration (MDE4CPP_PluginAPI C++ service)
    pluginAPI: {
        enabled: process.env.PLUGIN_API_ENABLED !== 'false',
        host: process.env.PLUGIN_API_HOST || '127.0.0.1',
        port: parseInt(process.env.PLUGIN_API_PORT, 10) || 8080,
        timeout: parseInt(process.env.PLUGIN_API_TIMEOUT, 10) || 5000
    },
    
    // Secure terminal configuration
    terminal: {
        // Use containerized execution (REQUIRED for security)
        useContainers: process.env.TERMINAL_USE_CONTAINERS !== 'false', // Default: true
        // Docker configuration
        docker: {
            socketPath: process.env.DOCKER_SOCKET_PATH || (process.platform === 'win32' ? '//./pipe/docker_engine' : '/var/run/docker.sock'),
            image: process.env.TERMINAL_DOCKER_IMAGE || 'mde4cpp-terminal:latest',
            // Container resource limits
            memory: parseInt(process.env.TERMINAL_MEMORY_LIMIT_MB, 10) || 512, // 512MB per container
            cpuShares: parseInt(process.env.TERMINAL_CPU_SHARES, 10) || 512, // 50% of one CPU
            // Container timeout (auto-destroy after inactivity)
            idleTimeoutMs: parseInt(process.env.TERMINAL_IDLE_TIMEOUT_MS, 10) || 3600000, // 1 hour
            // Command execution timeout
            commandTimeoutMs: parseInt(process.env.TERMINAL_COMMAND_TIMEOUT_MS, 10) || 600000, // 10 minutes
            // Network isolation
            networkDisabled: process.env.TERMINAL_NETWORK_DISABLED !== 'false', // Default: true (no network)
            // Read-only filesystem for MDE4CPP_HOME (prevents modifications)
            readOnlyMDE4CPP: process.env.TERMINAL_READONLY_MDE4CPP !== 'false', // Default: true
            // User namespace (runs as non-root in container)
            user: process.env.TERMINAL_DOCKER_USER || '1000:1000', // UID:GID
            // Working directory in container
            workingDir: process.env.TERMINAL_WORKING_DIR || '/workspace'
        },
        // Maximum concurrent terminal sessions
        maxSessions: parseInt(process.env.TERMINAL_MAX_SESSIONS, 10) || 10,
        // Cleanup interval for orphaned containers
        cleanupIntervalMs: parseInt(process.env.TERMINAL_CLEANUP_INTERVAL_MS, 10) || 300000 // 5 minutes
    }
};

// Ensure required directories exist on startup
const storageDirs = [
    path.join(config.storage.root, 'builds'),
    path.join(config.storage.root, 'outputs'),
    path.join(config.storage.root, 'uploads'),
    path.dirname(config.logging.file)
];

storageDirs.forEach(dir => {
    try {
        fs.ensureDirSync(dir);
    } catch (error) {
        console.error(`Failed to create directory ${dir}:`, error.message);
    }
});

// Validate MDE4CPP_HOME exists
if (!fs.pathExistsSync(config.mde4cpp.home)) {
    console.warn(`Warning: MDE4CPP_HOME does not exist: ${config.mde4cpp.home}`);
    console.warn('Builds will fail if MDE4CPP_HOME is incorrect.');
}

// Validate build script exists
const buildScriptPath = path.join(config.mde4cpp.home, 'addition', 'script', 'build-model-workspace.ps1');
if (!fs.pathExistsSync(buildScriptPath)) {
    console.warn(`Warning: Build script not found: ${buildScriptPath}`);
    console.warn('Builds will fail if the script path is incorrect.');
}

// Validate application/bin directory exists (where outputs are generated)
const binDir = path.join(config.mde4cpp.home, 'application', 'bin');
if (!fs.pathExistsSync(binDir)) {
    console.warn(`Warning: Application bin directory not found: ${binDir}`);
    console.warn('Output files will not be found if this directory does not exist.');
}

// Validate Docker is available if containers are enabled (async check, don't block)
if (config.terminal.useContainers) {
    try {
        const Docker = require('dockerode');
        const docker = new Docker({ socketPath: config.terminal.docker.socketPath });
        docker.ping((err) => {
            if (err) {
                console.error('ERROR: Docker is not available. Secure terminal requires Docker.');
                console.error('Please install Docker or set TERMINAL_USE_CONTAINERS=false (NOT RECOMMENDED)');
                console.error('Docker error:', err.message);
            } else {
                console.log('✓ Docker connection verified for secure terminal');
            }
        });
    } catch (error) {
        console.error('ERROR: Cannot initialize Docker client. Secure terminal requires Docker.');
        console.error('Please install Docker or set TERMINAL_USE_CONTAINERS=false (NOT RECOMMENDED)');
        console.error('Error:', error.message);
    }
}

module.exports = config;
