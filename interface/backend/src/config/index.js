require('dotenv').config();
const path = require('path');

const config = {
    env: process.env.NODE_ENV || 'development',
    port: parseInt(process.env.PORT, 10) || 8000,
    host: process.env.HOST || '0.0.0.0',
    
    mde4cpp: {
        home: process.env.MDE4CPP_HOME || path.join(__dirname, '../../..'),
        workspaceRoot: process.env.MDE4CPP_WORKSPACE_ROOT || 'interface/backend/storage/builds'
    },
    
    storage: {
        root: process.env.STORAGE_ROOT || path.join(__dirname, '../../storage'),
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
        origin: process.env.CORS_ORIGIN ? process.env.CORS_ORIGIN.split(',') : (process.env.NODE_ENV === 'production' ? ['http://localhost:3000'] : '*')
    },
    
    logging: {
        level: process.env.LOG_LEVEL || 'info',
        file: process.env.LOG_FILE || 'logs/app.log'
    }
};

module.exports = config;
