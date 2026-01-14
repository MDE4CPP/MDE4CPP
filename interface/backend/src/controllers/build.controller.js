const buildService = require('../services/build.service');
const { asyncHandler } = require('../middleware/errorHandler');
const { formatFileSize } = require('../utils/pathUtils');

/**
 * Create new build from uploaded file
 * POST /api/v1/build
 */
const createBuild = asyncHandler(async (req, res) => {
    const options = req.body.options ? JSON.parse(req.body.options) : {};
    const build = await buildService.createBuild(req.file, options);
    
    res.status(202).json({
        status: 'accepted',
        buildId: build.buildId,
        message: 'Build request accepted',
        statusUrl: `/api/v1/build/${build.buildId}/status`,
        estimatedTime: '2-5 minutes'
    });
});

/**
 * Get build status
 * GET /api/v1/build/:buildId/status
 */
const getStatus = asyncHandler(async (req, res) => {
    const { buildId } = req.params;
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
    
    res.json(build);
});

/**
 * Get build logs
 * GET /api/v1/build/:buildId/logs
 */
const getLogs = asyncHandler(async (req, res) => {
    const { buildId } = req.params;
    const tail = req.query.tail ? parseInt(req.query.tail, 10) : null;
    const logs = buildService.getBuildLogs(buildId, tail);
    
    if (!logs) {
        return res.status(404).json({
            error: {
                code: 'BUILD_NOT_FOUND',
                message: 'Build not found',
                timestamp: new Date().toISOString()
            }
        });
    }
    
    res.json(logs);
});

/**
 * Get build files list
 * GET /api/v1/build/:buildId/files
 */
const getFiles = asyncHandler(async (req, res) => {
    const { buildId } = req.params;
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
    
    const files = {
        dlls: build.outputFiles.dlls.map(file => ({
            name: file.name,
            size: file.size,
            sizeFormatted: formatFileSize(file.size),
            downloadUrl: `/api/v1/build/${buildId}/download/dll/${file.name}`,
            createdAt: file.createdAt
        })),
        executables: build.outputFiles.executables.map(file => ({
            name: file.name,
            size: file.size,
            sizeFormatted: formatFileSize(file.size),
            downloadUrl: `/api/v1/build/${buildId}/download/executable/${file.name}`,
            createdAt: file.createdAt
        }))
    };
    
    res.json({
        buildId,
        files
    });
});

module.exports = {
    createBuild,
    getStatus,
    getLogs,
    getFiles
};
