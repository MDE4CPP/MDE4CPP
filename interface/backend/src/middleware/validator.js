const { body, param, validationResult } = require('express-validator');
const { isValidModelFile, isValidFileSize } = require('../utils/validators');
const { isValidBuildId } = require('../utils/validators');
const config = require('../config');

/**
 * Validate file upload
 */
function validateFileUpload(req, res, next) {
    if (!req.file) {
        return res.status(400).json({
            error: {
                code: 'MISSING_FILE',
                message: 'No file uploaded',
                timestamp: new Date().toISOString()
            }
        });
    }
    
    // Validate file type
    if (!isValidModelFile(req.file.originalname)) {
        return res.status(400).json({
            error: {
                code: 'INVALID_FILE_TYPE',
                message: 'File must be .ecore or .uml',
                timestamp: new Date().toISOString()
            }
        });
    }
    
    // Validate file size
    if (!isValidFileSize(req.file.size, config.storage.uploadMaxSizeMB)) {
        return res.status(413).json({
            error: {
                code: 'FILE_TOO_LARGE',
                message: `File size exceeds limit of ${config.storage.uploadMaxSizeMB}MB`,
                timestamp: new Date().toISOString()
            }
        });
    }
    
    next();
}

/**
 * Validate build ID parameter
 */
const validateBuildId = [
    param('buildId').custom((value) => {
        if (!isValidBuildId(value)) {
            throw new Error('Invalid build ID format');
        }
        return true;
    }),
    (req, res, next) => {
        const errors = validationResult(req);
        if (!errors.isEmpty()) {
            return res.status(400).json({
                error: {
                    code: 'INVALID_BUILD_ID',
                    message: 'Invalid build ID format',
                    details: errors.array(),
                    timestamp: new Date().toISOString()
                }
            });
        }
        next();
    }
];

module.exports = {
    validateFileUpload,
    validateBuildId
};
