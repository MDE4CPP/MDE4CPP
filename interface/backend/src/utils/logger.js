const winston = require('winston');
const path = require('path');
const fs = require('fs-extra');
const config = require('../config');

// Ensure logs directory exists
const logDir = path.dirname(config.logging.file);
fs.ensureDirSync(logDir);

const logger = winston.createLogger({
    level: config.logging.level,
    format: winston.format.combine(
        winston.format.timestamp({ format: 'YYYY-MM-DD HH:mm:ss' }),
        winston.format.errors({ stack: true }),
        winston.format.splat(),
        winston.format.json()
    ),
    defaultMeta: { service: 'mde4cpp-build-service' },
    transports: [
        new winston.transports.File({ filename: config.logging.file, level: 'error' }),
        new winston.transports.File({ filename: config.logging.file.replace('.log', '-combined.log') })
    ]
});

// Add console transport in development
if (config.env !== 'production') {
    logger.add(new winston.transports.Console({
        format: winston.format.combine(
            winston.format.colorize(),
            winston.format.simple()
        )
    }));
}

module.exports = logger;
