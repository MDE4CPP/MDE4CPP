const path = require('path');
const logger = require('../utils/logger');
const { generateBuildId } = require('../utils/buildIdGenerator');
const buildModel = require('../models/build.model');
const storageService = require('./storage.service');
const fileService = require('./file.service');
const scriptService = require('./script.service');
const config = require('../config');

/**
 * Create a new build from uploaded file
 * @param {object} file - Multer file object
 * @param {object} options - Build options
 * @returns {Promise<object>} Build record
 */
async function createBuild(file, options = {}) {
    const buildId = generateBuildId();
    logger.info(`Creating new build: ${buildId}`);
    
    // Create workspace
    const workspacePath = await storageService.createWorkspace(buildId);
    
    // Save uploaded file
    const modelFilePath = await storageService.saveUploadedFile(workspacePath, file);
    
    // Extract model name from filename
    const modelName = path.basename(modelFilePath, path.extname(modelFilePath));
    
    // Create build record
    const build = buildModel.createBuild(buildId, {
        file: {
            originalName: file.originalname,
            savedPath: modelFilePath,
            modelName
        }
    });
    
    // Start build process asynchronously
    executeBuild(buildId, modelFilePath, modelName).catch(error => {
        logger.error(`Build ${buildId} failed:`, error);
        buildModel.updateBuild(buildId, {
            status: 'failed',
            message: error.message,
            completedAt: new Date().toISOString()
        });
        buildModel.addBuildError(buildId, 'execution', error.message, { error: error.toString() });
    });
    
    return build;
}

/**
 * Execute build process
 * @param {string} buildId - Build ID
 * @param {string} modelFilePath - Path to model file
 * @param {string} modelName - Model name
 * @returns {Promise<void>}
 */
async function executeBuild(buildId, modelFilePath, modelName) {
    logger.info(`Starting build execution: ${buildId}`);
    
    buildModel.updateBuild(buildId, {
        status: 'building',
        stage: 'initialization',
        message: 'Starting build process...',
        startedAt: new Date().toISOString(),
        progress: 5
    });
    
    buildModel.addBuildLog(buildId, 'info', 'Starting build process...', 'initialization');
    
    try {
        // Calculate actual workspace path from buildId (parent of model directory)
        // modelFilePath = storage/builds/{buildId}/model/filename
        // workspacePath should be = storage/builds/{buildId}
        const actualWorkspacePath = path.join(config.storage.root, 'builds', buildId);
        
        logger.debug(`Model file path: ${modelFilePath}`);
        logger.debug(`Actual workspace path: ${actualWorkspacePath}`);
        
        // Execute PowerShell script
        const scriptResult = await scriptService.executeBuildScript(
            modelFilePath,
            actualWorkspacePath,  // Use actual workspace path, not model directory
            (output) => {
                // Handle stdout
                buildModel.addBuildLog(buildId, 'info', output.trim(), 'building');
                logger.debug(`Build ${buildId} stdout:`, output);
            },
            (error) => {
                // Handle stderr
                buildModel.addBuildLog(buildId, 'error', error.trim(), 'building');
                logger.debug(`Build ${buildId} stderr:`, error);
            }
        );
        
        logger.info(`Build script completed with exit code: ${scriptResult.exitCode}`);
        
        // Check if script actually succeeded (exit code 0)
        if (!scriptResult.success) {
            throw new Error(`Build script failed with exit code ${scriptResult.exitCode}: ${scriptResult.stderr}`);
        }
        
        buildModel.updateBuild(buildId, {
            stage: 'collecting',
            message: 'Build completed, collecting output files...',
            progress: 90
        });
        
        buildModel.addBuildLog(buildId, 'info', 'Build script completed, collecting output files...', 'collecting');
        
        // Find output files
        logger.info(`Finding output files for model: ${modelName}`);
        const outputFiles = await fileService.findOutputFiles(modelName);
        
        logger.info(`Found ${outputFiles.dlls.length} DLLs and ${outputFiles.executables.length} executables`);
        
        // Copy output files to storage
        logger.info(`Copying output files to storage for build: ${buildId}`);
        const copiedFiles = await fileService.copyOutputFiles(buildId, outputFiles);
        
        // Update build record
        buildModel.updateBuild(buildId, {
            status: 'completed',
            stage: 'completed',
            message: 'Build completed successfully',
            progress: 100,
            outputFiles: {
                dlls: copiedFiles.dlls.map(f => ({ name: f.name, size: f.size, path: f.path })),
                executables: copiedFiles.executables.map(f => ({ name: f.name, size: f.size, path: f.path }))
            },
            completedAt: new Date().toISOString()
        });
        
        buildModel.addBuildLog(buildId, 'info', 'Build completed successfully', 'completed');
        logger.info(`Build ${buildId} completed successfully`);
        
    } catch (error) {
        logger.error(`Build ${buildId} failed:`, error);
        logger.error(`Error stack:`, error.stack);
        
        buildModel.updateBuild(buildId, {
            status: 'failed',
            stage: 'failed',
            message: error.message || 'Build failed',
            completedAt: new Date().toISOString()
        });
        
        buildModel.addBuildError(buildId, 'execution', error.message || 'Build failed', {
            error: error.toString(),
            stack: error.stack
        });
        
        buildModel.addBuildLog(buildId, 'error', `Build failed: ${error.message}`, 'failed');
        
        // Don't throw to prevent unhandled rejection, but log it
        // The status is already updated to 'failed' above
    }
}

/**
 * Get build status
 * @param {string} buildId - Build ID
 * @returns {object|null} Build record
 */
function getBuildStatus(buildId) {
    return buildModel.getBuild(buildId);
}

/**
 * Get build logs
 * @param {string} buildId - Build ID
 * @param {number} tail - Number of last lines to return
 * @returns {object|null} Build logs
 */
function getBuildLogs(buildId, tail = null) {
    const build = buildModel.getBuild(buildId);
    if (!build) return null;
    
    let logs = build.logs;
    if (tail && tail > 0) {
        logs = logs.slice(-tail);
    }
    
    return {
        buildId,
        logs,
        totalLines: build.logs.length
    };
}

module.exports = {
    createBuild,
    getBuildStatus,
    getBuildLogs
};
