const fs = require('fs-extra');
const path = require('path');
const logger = require('../utils/logger');
const { sanitizeFilename } = require('../utils/pathUtils');
const config = require('../config');

/**
 * Terminal Workspace Service
 * Manages workspace directories for terminal sessions
 * Each terminal session gets its own isolated workspace
 */
class TerminalWorkspaceService {
    /**
     * Create workspace directory structure for a terminal session
     * 
     * Workspace location: {STORAGE_ROOT}/terminals/{sessionId}/
     * 
     * @param {string} sessionId - Session ID
     * @returns {Promise<string>} Workspace path (absolute)
     */
    async createTerminalWorkspace(sessionId) {
        const workspacePath = path.join(config.storage.root, 'terminals', sessionId);
        const modelDir = path.join(workspacePath, 'model');
        const srcGenDir = path.join(workspacePath, 'src_gen');
        const appDir = path.join(workspacePath, 'application');
        
        await fs.ensureDir(modelDir);
        await fs.ensureDir(srcGenDir);
        await fs.ensureDir(appDir);
        
        logger.info(`Created terminal workspace: ${workspacePath}`);
        return workspacePath;
    }
    
    /**
     * Get terminal workspace path
     * @param {string} sessionId - Session ID
     * @returns {string} Workspace path (absolute)
     */
    getTerminalWorkspacePath(sessionId) {
        return path.join(config.storage.root, 'terminals', sessionId);
    }
    
    /**
     * Save uploaded file to terminal workspace
     * 
     * File location: {STORAGE_ROOT}/terminals/{sessionId}/model/{filename}
     * 
     * @param {string} sessionId - Session ID
     * @param {object} file - Multer file object
     * @returns {Promise<object>} File info (name, path, size)
     */
    async saveTerminalFile(sessionId, file) {
        // Ensure workspace exists
        const workspacePath = await this.createTerminalWorkspace(sessionId);
        const modelDir = path.join(workspacePath, 'model');
        
        // Sanitize filename
        const sanitizedFilename = sanitizeFilename(file.originalname);
        const destPath = path.join(modelDir, sanitizedFilename);
        
        // Move uploaded file to workspace
        await fs.move(file.path, destPath, { overwrite: true });
        
        // Get file stats
        const stats = await fs.stat(destPath);
        
        logger.info(`Saved terminal file to: ${destPath} (${stats.size} bytes)`);
        
        return {
            name: sanitizedFilename,
            originalName: file.originalname,
            path: destPath,
            relativePath: `model/${sanitizedFilename}`,
            size: stats.size,
            uploadedAt: new Date().toISOString()
        };
    }
    
    /**
     * List files in terminal workspace
     * @param {string} sessionId - Session ID
     * @returns {Promise<object>} Files by directory
     */
    async listTerminalFiles(sessionId) {
        const workspacePath = this.getTerminalWorkspacePath(sessionId);
        
        if (!(await fs.pathExists(workspacePath))) {
            return {
                model: [],
                src_gen: [],
                application: []
            };
        }
        
        const modelDir = path.join(workspacePath, 'model');
        const srcGenDir = path.join(workspacePath, 'src_gen');
        const appDir = path.join(workspacePath, 'application');
        
        const listDir = async (dir) => {
            if (!(await fs.pathExists(dir))) {
                return [];
            }
            const files = await fs.readdir(dir);
            const fileList = [];
            for (const file of files) {
                const filePath = path.join(dir, file);
                const stats = await fs.stat(filePath);
                if (stats.isFile()) {
                    fileList.push({
                        name: file,
                        size: stats.size,
                        modifiedAt: stats.mtime.toISOString()
                    });
                }
            }
            return fileList;
        };
        
        return {
            model: await listDir(modelDir),
            src_gen: await listDir(srcGenDir),
            application: await listDir(appDir)
        };
    }
    
    /**
     * Clean up terminal workspace
     * @param {string} sessionId - Session ID
     * @returns {Promise<void>}
     */
    async cleanupTerminalWorkspace(sessionId) {
        const workspacePath = this.getTerminalWorkspacePath(sessionId);
        
        if (await fs.pathExists(workspacePath)) {
            await fs.remove(workspacePath);
            logger.info(`Cleaned up terminal workspace: ${workspacePath}`);
        }
    }
    
    /**
     * Check if workspace exists
     * @param {string} sessionId - Session ID
     * @returns {Promise<boolean>}
     */
    async workspaceExists(sessionId) {
        const workspacePath = this.getTerminalWorkspacePath(sessionId);
        return await fs.pathExists(workspacePath);
    }
}

// Singleton instance
let instance = null;

module.exports = {
    getInstance: () => {
        if (!instance) {
            instance = new TerminalWorkspaceService();
        }
        return instance;
    }
};
