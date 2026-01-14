const fs = require('fs-extra');
const path = require('path');
const logger = require('../utils/logger');
const { sanitizeFilename } = require('../utils/pathUtils');
const config = require('../config');

/**
 * Create workspace directory structure for a build
 * @param {string} buildId - Build ID
 * @returns {Promise<string>} Workspace path
 */
async function createWorkspace(buildId) {
    const workspacePath = path.join(config.storage.root, 'builds', buildId);
    const modelDir = path.join(workspacePath, 'model');
    const srcGenDir = path.join(workspacePath, 'src_gen');
    const appDir = path.join(workspacePath, 'application');
    
    await fs.ensureDir(modelDir);
    await fs.ensureDir(srcGenDir);
    await fs.ensureDir(appDir);
    
    logger.info(`Created workspace: ${workspacePath}`);
    return workspacePath;
}

/**
 * Save uploaded file to workspace
 * @param {string} workspacePath - Workspace path
 * @param {object} file - Multer file object
 * @returns {Promise<string>} Path to saved file
 */
async function saveUploadedFile(workspacePath, file) {
    const modelDir = path.join(workspacePath, 'model');
    const sanitizedFilename = sanitizeFilename(file.originalname);
    const destPath = path.join(modelDir, sanitizedFilename);
    
    await fs.move(file.path, destPath, { overwrite: true });
    logger.info(`Saved uploaded file to: ${destPath}`);
    
    return destPath;
}

/**
 * Clean up workspace (optional, for cleanup jobs)
 * @param {string} buildId - Build ID
 * @returns {Promise<void>}
 */
async function cleanupWorkspace(buildId) {
    const workspacePath = path.join(config.storage.root, 'builds', buildId);
    
    if (await fs.pathExists(workspacePath)) {
        await fs.remove(workspacePath);
        logger.info(`Cleaned up workspace: ${workspacePath}`);
    }
}

/**
 * Clean up output files (for cleanup jobs)
 * @param {string} buildId - Build ID
 * @returns {Promise<void>}
 */
async function cleanupOutputs(buildId) {
    const outputPath = path.join(config.storage.root, 'outputs', buildId);
    
    if (await fs.pathExists(outputPath)) {
        await fs.remove(outputPath);
        logger.info(`Cleaned up outputs: ${outputPath}`);
    }
}

module.exports = {
    createWorkspace,
    saveUploadedFile,
    cleanupWorkspace,
    cleanupOutputs
};
