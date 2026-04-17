const path = require('path');
const fs = require('fs-extra');
const archiver = require('archiver');
const buildService = require('../services/build.service');
const { asyncHandler } = require('../middleware/errorHandler');
const config = require('../config');

/**
 * Download build artifacts
 * GET /api/v1/build/:buildId/download/:fileType
 */
const downloadFiles = asyncHandler(async (req, res) => {
    const { buildId, fileType } = req.params;
    const build = buildService.getBuildStatus(buildId);
    
    if (!build) {
        return res.status(404).json({
            error: {
                code: 'BUILD_NOT_FOUND',
                message: 'Build not found',
                timestamp: new Date().toISOString()
            }
        });
    }
    
    if (build.status !== 'completed') {
        return res.status(400).json({
            error: {
                code: 'BUILD_NOT_READY',
                message: 'Build is not completed yet',
                timestamp: new Date().toISOString()
            }
        });
    }
    
    const outputDir = path.join(config.storage.root, 'outputs', buildId);
    
    if (!await fs.pathExists(outputDir)) {
        return res.status(404).json({
            error: {
                code: 'FILES_NOT_FOUND',
                message: 'Output files not found',
                timestamp: new Date().toISOString()
            }
        });
    }
    
    // Set headers for ZIP download
    const filename = `build-${buildId}.zip`;
    res.setHeader('Content-Type', 'application/zip');
    res.setHeader('Content-Disposition', `attachment; filename="${filename}"`);
    
    // Create ZIP archive
    const archive = archiver('zip', {
        zlib: { level: 9 }
    });
    
    archive.on('error', (err) => {
        throw err;
    });
    
    archive.pipe(res);
    
    // Add files based on fileType
    if (fileType === 'all' || fileType === 'zip') {
        // Add all files
        const dllDir = path.join(outputDir, 'dlls');
        const exeDir = path.join(outputDir, 'executables');
        
        if (await fs.pathExists(dllDir)) {
            archive.directory(dllDir, 'dlls');
        }
        if (await fs.pathExists(exeDir)) {
            archive.directory(exeDir, 'executables');
        }
    } else if (fileType === 'dll') {
        const dllDir = path.join(outputDir, 'dlls');
        if (await fs.pathExists(dllDir)) {
            archive.directory(dllDir, 'dlls');
        }
    } else if (fileType === 'executable') {
        const exeDir = path.join(outputDir, 'executables');
        if (await fs.pathExists(exeDir)) {
            archive.directory(exeDir, 'executables');
        }
    } else {
        return res.status(400).json({
            error: {
                code: 'INVALID_FILE_TYPE',
                message: 'Invalid file type. Use: dll, executable, all, or zip',
                timestamp: new Date().toISOString()
            }
        });
    }
    
    await archive.finalize();
});

module.exports = {
    downloadFiles
};
