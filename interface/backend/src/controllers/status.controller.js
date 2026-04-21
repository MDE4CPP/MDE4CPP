const { asyncHandler } = require('../middleware/errorHandler');
const buildModel = require('../models/build.model');

/**
 * Health check endpoint
 * GET /api/v1/health
 */
const health = asyncHandler(async (req, res) => {
    res.json({
        status: 'healthy',
        version: '1.0.0',
        timestamp: new Date().toISOString(),
        uptime: process.uptime()
    });
});

/**
 * Service statistics
 * GET /api/v1/stats
 */
const stats = asyncHandler(async (req, res) => {
    const builds = buildModel.getAllBuilds();
    
    const stats = {
        activeBuilds: builds.filter(b => b.status === 'building').length,
        queuedBuilds: builds.filter(b => b.status === 'queued').length,
        completedBuilds: builds.filter(b => b.status === 'completed').length,
        failedBuilds: builds.filter(b => b.status === 'failed').length,
        totalBuilds: builds.length
    };
    
    // Calculate average build time (for completed builds)
    const completedBuilds = builds.filter(b => b.status === 'completed' && b.startedAt && b.completedAt);
    if (completedBuilds.length > 0) {
        const totalTime = completedBuilds.reduce((sum, b) => {
            const start = new Date(b.startedAt);
            const end = new Date(b.completedAt);
            return sum + (end - start);
        }, 0);
        const avgTime = totalTime / completedBuilds.length;
        const minutes = Math.floor(avgTime / 60000);
        const seconds = Math.floor((avgTime % 60000) / 1000);
        stats.averageBuildTime = `${minutes}m ${seconds}s`;
    }
    
    res.json(stats);
});

module.exports = {
    health,
    stats
};
