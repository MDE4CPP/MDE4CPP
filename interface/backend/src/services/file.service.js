const fs = require('fs-extra');
const path = require('path');
const logger = require('../utils/logger');
const { sanitizeFilename, formatFileSize } = require('../utils/pathUtils');
const config = require('../config');

/**
 * Find output files in the MDE4CPP application/bin directory
 * @param {string} modelName - Model name to search for
 * @returns {Promise<object>} Object with dlls and executables arrays
 */
async function findOutputFiles(modelName) {
    const binDir = path.join(config.mde4cpp.home, 'application', 'bin');
    const outputFiles = {
        dlls: [],
        executables: []
    };
    
    if (!await fs.pathExists(binDir)) {
        logger.warn(`Bin directory not found: ${binDir}`);
        return outputFiles;
    }
    
    try {
        const files = await fs.readdir(binDir);
        
        for (const file of files) {
            const filePath = path.join(binDir, file);
            const stats = await fs.stat(filePath);
            
            if (!stats.isFile()) continue;
            
            const lowerName = file.toLowerCase();
            
            // Check for DLL files matching model name
            if ((lowerName.endsWith('.dll')) && 
                (file.includes(modelName) || file.includes(modelName.toLowerCase()))) {
                outputFiles.dlls.push({
                    name: file,
                    path: filePath,
                    size: stats.size,
                    sizeFormatted: formatFileSize(stats.size),
                    createdAt: stats.birthtime.toISOString()
                });
            }
            
            // Check for executable files matching model name
            if ((lowerName.endsWith('.exe')) && 
                (file.startsWith(`App_${modelName}`) || file.startsWith(`App_${modelName.toLowerCase()}`))) {
                outputFiles.executables.push({
                    name: file,
                    path: filePath,
                    size: stats.size,
                    sizeFormatted: formatFileSize(stats.size),
                    createdAt: stats.birthtime.toISOString()
                });
            }
        }
    } catch (error) {
        logger.error('Error finding output files:', error);
    }
    
    return outputFiles;
}

/**
 * Copy output files to storage/outputs/{buildId}/
 * @param {string} buildId - Build ID
 * @param {object} outputFiles - Output files object with dlls and executables
 * @returns {Promise<object>} Copied files with new paths
 */
async function copyOutputFiles(buildId, outputFiles) {
    const outputDir = path.join(config.storage.root, 'outputs', buildId);
    const dllDir = path.join(outputDir, 'dlls');
    const exeDir = path.join(outputDir, 'executables');
    
    await fs.ensureDir(dllDir);
    await fs.ensureDir(exeDir);
    
    const copiedFiles = {
        dlls: [],
        executables: []
    };
    
    // Copy DLLs
    for (const dll of outputFiles.dlls) {
        const destPath = path.join(dllDir, dll.name);
        await fs.copy(dll.path, destPath);
        copiedFiles.dlls.push({
            ...dll,
            path: destPath
        });
    }
    
    // Copy executables
    for (const exe of outputFiles.executables) {
        const destPath = path.join(exeDir, exe.name);
        await fs.copy(exe.path, destPath);
        copiedFiles.executables.push({
            ...exe,
            path: destPath
        });
    }
    
    return copiedFiles;
}

module.exports = {
    findOutputFiles,
    copyOutputFiles
};
