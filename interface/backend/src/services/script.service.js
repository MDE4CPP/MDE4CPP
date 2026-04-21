const { spawn } = require('child_process');
const path = require('path');
const fs = require('fs-extra');
const logger = require('../utils/logger');
const config = require('../config');

/**
 * Execute PowerShell build script
 * 
 * Build script location: MDE4CPP_HOME/addition/script/build-model-workspace.ps1
 * Workspace location: storage/builds/{buildId}/
 * Output files location: MDE4CPP_HOME/application/bin/
 * 
 * @param {string} modelFilePath - Path to model file (absolute)
 * @param {string} workspacePath - Workspace path (absolute)
 * @param {function} onOutput - Callback for stdout data
 * @param {function} onError - Callback for stderr data
 * @returns {Promise<object>} Build result
 */
async function executeBuildScript(modelFilePath, workspacePath, onOutput, onError) {
    return new Promise((resolve, reject) => {
        // Get script path - use absolute path for production reliability
        const scriptPath = path.resolve(config.mde4cpp.home, 'addition', 'script', 'build-model-workspace.ps1');
        
        // Verify script exists
        if (!fs.pathExistsSync(scriptPath)) {
            const error = new Error(`Build script not found: ${scriptPath}`);
            logger.error(error.message);
            logger.error(`MDE4CPP_HOME: ${config.mde4cpp.home}`);
            reject(error);
            return;
        }
        
        logger.info(`Executing build script: ${scriptPath}`);
        logger.info(`Model file: ${modelFilePath}`);
        logger.info(`Workspace: ${workspacePath}`);
        logger.info(`MDE4CPP_HOME: ${config.mde4cpp.home}`);
        
        // Ensure workspace path is absolute
        const absoluteWorkspacePath = path.isAbsolute(workspacePath) 
            ? workspacePath 
            : path.resolve(workspacePath);
        
        // Ensure model file path is absolute
        const absoluteModelFilePath = path.isAbsolute(modelFilePath)
            ? modelFilePath
            : path.resolve(modelFilePath);
        
        const psArgs = [
            '-ExecutionPolicy', config.powershell.executionPolicy,
            '-File', scriptPath,
            '-ModelFilePath', absoluteModelFilePath,
            '-WorkspacePath', absoluteWorkspacePath,
            '-MDE4CPP_HOME', config.mde4cpp.home
        ];
        
        const psProcess = spawn('powershell.exe', psArgs, {
            cwd: path.dirname(absoluteModelFilePath),
            env: {
                ...process.env,
                MDE4CPP_HOME: config.mde4cpp.home,
                MDE4CPP_ECLIPSE_HOME: path.resolve(config.mde4cpp.home, 'eclipse'),
                ORG_GRADLE_PROJECT_RELEASE: '1',
                ORG_GRADLE_PROJECT_DEBUG: '1',
                PATH: `${path.resolve(config.mde4cpp.home, 'application', 'tools')};${process.env.PATH}`
            }
        });
        
        let stdout = '';
        let stderr = '';
        let hasTimedOut = false;
        
        // Set timeout
        const timeout = setTimeout(() => {
            hasTimedOut = true;
            psProcess.kill();
            reject(new Error(`Build timeout after ${config.build.timeoutSeconds} seconds`));
        }, config.build.timeoutSeconds * 1000);
        
        psProcess.stdout.on('data', (data) => {
            const output = data.toString();
            stdout += output;
            if (onOutput) {
                onOutput(output);
            }
        });
        
        psProcess.stderr.on('data', (data) => {
            const error = data.toString();
            stderr += error;
            if (onError) {
                onError(error);
            }
        });
        
        psProcess.on('close', (code) => {
            clearTimeout(timeout);
            
            if (hasTimedOut) {
                return; // Already rejected
            }
            
            const result = {
                exitCode: code,
                stdout,
                stderr,
                success: code === 0
            };
            
            logger.info(`PowerShell script exited with code: ${code}`);
            
            if (code === 0) {
                logger.info('Build script completed successfully');
                logger.debug(`Stdout length: ${stdout.length}, Stderr length: ${stderr.length}`);
                resolve(result);
            } else {
                logger.error(`Build script failed with exit code ${code}`);
                logger.error(`Stderr output: ${stderr.substring(0, 1000)}`); // Log first 1000 chars
                reject(new Error(`Build failed with exit code ${code}: ${stderr.substring(0, 500)}`));
            }
        });
        
        psProcess.on('error', (error) => {
            clearTimeout(timeout);
            logger.error('Error executing build script:', error);
            reject(error);
        });
    });
}

module.exports = {
    executeBuildScript
};
