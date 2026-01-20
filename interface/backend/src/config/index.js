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
        // Default: resolve from backend directory (assumes interface/backend structure)
        home: process.env.MDE4CPP_HOME 
            ? (path.isAbsolute(process.env.MDE4CPP_HOME) 
                ? process.env.MDE4CPP_HOME 
                : path.resolve(process.env.MDE4CPP_HOME))
            : path.resolve(__dirname, '../../..'),
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

module.exports = config;
