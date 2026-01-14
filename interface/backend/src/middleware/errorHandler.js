const logger = require('../utils/logger');

/**
 * Error handling middleware
 */
function errorHandler(err, req, res, next) {
    logger.error('Error:', err);
    
    const status = err.status || err.statusCode || 500;
    const code = err.code || 'INTERNAL_ERROR';
    const message = err.message || 'Internal server error';
    const details = err.details || {};
    
    res.status(status).json({
        error: {
            code,
            message,
            details,
            timestamp: new Date().toISOString()
        }
    });
}

/**
 * Async handler wrapper to catch errors in async route handlers
 */
function asyncHandler(fn) {
    return (req, res, next) => {
        Promise.resolve(fn(req, res, next)).catch(next);
    };
}

module.exports = {
    errorHandler,
    asyncHandler
};
