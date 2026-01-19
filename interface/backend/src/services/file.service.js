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
        
        logger.debug(`Scanning ${files.length} files in ${binDir} for model: ${modelName}`);
        
        for (const file of files) {
            const filePath = path.join(binDir, file);
            const stats = await fs.stat(filePath);
            
            if (!stats.isFile()) continue;
            
            const lowerName = file.toLowerCase();
            const modelLower = modelName.toLowerCase();
            
            // Check for DLL files matching model name (case-insensitive)
            // Exclude Exec DLLs to avoid false positives with fUML execution libraries
            if (lowerName.endsWith('.dll')) {
                if (lowerName.includes(modelLower) && !lowerName.includes(`${modelLower}exec`)) {
                    outputFiles.dlls.push({
                        name: file,
                        path: filePath,
                        size: stats.size,
                        sizeFormatted: formatFileSize(stats.size),
                        createdAt: stats.birthtime.toISOString()
                    });
                    logger.debug(`Found DLL: ${file}`);
                }
            }
            
            // Check for executable files matching model name (case-insensitive)
            // Support multiple patterns: App_ModelName, App_modelName, App_ModelNamed, or files containing model name (excluding Exec files)
            if (lowerName.endsWith('.exe')) {
                const modelPascal = modelName.charAt(0).toUpperCase() + modelName.slice(1);
                if (lowerName.startsWith(`app_${modelLower}`) || 
                    lowerName.startsWith(`app_${modelLower}d`) ||
                    lowerName.startsWith(`app_${modelName.toLowerCase()}`) ||
                    lowerName.startsWith(`app_${modelPascal.toLowerCase()}`) ||
                    (lowerName.includes(modelLower) && !lowerName.includes('exec'))) {
                    outputFiles.executables.push({
                        name: file,
                        path: filePath,
                        size: stats.size,
                        sizeFormatted: formatFileSize(stats.size),
                        createdAt: stats.birthtime.toISOString()
                    });
                    logger.debug(`Found executable: ${file}`);
                }
            }
        }
        
        logger.info(`Found ${outputFiles.dlls.length} DLLs and ${outputFiles.executables.length} executables for ${modelName}`);
    } catch (error) {
        logger.error('Error finding output files:', error);
        logger.error('Error stack:', error.stack);
        // Don't throw - return empty result instead
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
