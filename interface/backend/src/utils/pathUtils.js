const path = require('path');

/**
 * Sanitize filename to prevent directory traversal and invalid characters
 * @param {string} filename - Original filename
 * @returns {string} Sanitized filename
 */
function sanitizeFilename(filename) {
    // Remove path separators and relative paths
    let sanitized = path.basename(filename);
    
    // Remove or replace invalid characters (Windows)
    sanitized = sanitized.replace(/[<>:"|?*\x00-\x1f]/g, '_');
    
    // Limit length
    if (sanitized.length > 255) {
        const ext = path.extname(sanitized);
        const name = path.basename(sanitized, ext);
        sanitized = name.substring(0, 255 - ext.length) + ext;
    }
    
    return sanitized || 'file';
}

/**
 * Validate path is within allowed directory (prevent directory traversal)
 * @param {string} filePath - File path to validate
 * @param {string} baseDir - Base directory that path must be within
 * @returns {boolean} True if path is safe
 */
function isPathSafe(filePath, baseDir) {
    const resolvedPath = path.resolve(filePath);
    const resolvedBase = path.resolve(baseDir);
    return resolvedPath.startsWith(resolvedBase);
}

/**
 * Format file size to human-readable string
 * @param {number} bytes - File size in bytes
 * @returns {string} Formatted size string
 */
function formatFileSize(bytes) {
    if (bytes === 0) return '0 Bytes';
    const k = 1024;
    const sizes = ['Bytes', 'KB', 'MB', 'GB'];
    const i = Math.floor(Math.log(bytes) / Math.log(k));
    return Math.round(bytes / Math.pow(k, i) * 100) / 100 + ' ' + sizes[i];
}

module.exports = {
    sanitizeFilename,
    isPathSafe,
    formatFileSize
};
