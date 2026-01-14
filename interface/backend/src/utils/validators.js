const path = require('path');
const logger = require('./logger');

/**
 * Validate file extension is .ecore or .uml
 * @param {string} filename - File name to validate
 * @returns {boolean} True if valid
 */
function isValidModelFile(filename) {
    const ext = path.extname(filename).toLowerCase();
    return ext === '.ecore' || ext === '.uml';
}

/**
 * Validate file size is within limits
 * @param {number} size - File size in bytes
 * @param {number} maxSizeMB - Maximum size in MB
 * @returns {boolean} True if valid
 */
function isValidFileSize(size, maxSizeMB) {
    const maxSizeBytes = maxSizeMB * 1024 * 1024;
    return size <= maxSizeBytes;
}

/**
 * Validate build ID format (UUID)
 * @param {string} buildId - Build ID to validate
 * @returns {boolean} True if valid UUID format
 */
function isValidBuildId(buildId) {
    const uuidRegex = /^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$/i;
    return uuidRegex.test(buildId);
}

module.exports = {
    isValidModelFile,
    isValidFileSize,
    isValidBuildId
};
