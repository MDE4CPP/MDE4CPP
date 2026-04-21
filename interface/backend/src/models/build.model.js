/**
 * In-memory build status storage
 * In production, this would be replaced with Redis or a database
 */
const builds = new Map();

/**
 * Create a new build record
 * @param {string} buildId - Unique build ID
 * @param {object} buildData - Build data
 * @returns {object} Build record
 */
function createBuild(buildId, buildData) {
    const build = {
        buildId,
        status: 'queued',
        progress: 0,
        stage: 'initialization',
        message: 'Build request accepted',
        file: buildData.file,
        outputFiles: {
            dlls: [],
            executables: []
        },
        logs: [],
        errors: [],
        startedAt: null,
        completedAt: null,
        createdAt: new Date().toISOString()
    };
    
    builds.set(buildId, build);
    return build;
}

/**
 * Get build record by ID
 * @param {string} buildId - Build ID
 * @returns {object|null} Build record or null
 */
function getBuild(buildId) {
    return builds.get(buildId) || null;
}

/**
 * Update build record
 * @param {string} buildId - Build ID
 * @param {object} updates - Updates to apply
 * @returns {object|null} Updated build record or null
 */
function updateBuild(buildId, updates) {
    const build = builds.get(buildId);
    if (!build) return null;
    
    Object.assign(build, updates);
    builds.set(buildId, build);
    return build;
}

/**
 * Add log entry to build
 * @param {string} buildId - Build ID
 * @param {string} level - Log level (info, error, warning)
 * @param {string} message - Log message
 * @param {string} stage - Build stage
 */
function addBuildLog(buildId, level, message, stage = null) {
    const build = builds.get(buildId);
    if (!build) return;
    
    const logEntry = {
        timestamp: new Date().toISOString(),
        level,
        message,
        stage: stage || build.stage
    };
    
    build.logs.push(logEntry);
    
    // Keep only last 1000 log entries
    if (build.logs.length > 1000) {
        build.logs = build.logs.slice(-1000);
    }
}

/**
 * Add error to build
 * @param {string} buildId - Build ID
 * @param {string} stage - Error stage
 * @param {string} message - Error message
 * @param {object} details - Error details
 */
function addBuildError(buildId, stage, message, details = {}) {
    const build = builds.get(buildId);
    if (!build) return;
    
    build.errors.push({
        stage,
        message,
        details,
        timestamp: new Date().toISOString()
    });
}

/**
 * Get all builds (for stats)
 * @returns {Array} Array of build records
 */
function getAllBuilds() {
    return Array.from(builds.values());
}

module.exports = {
    createBuild,
    getBuild,
    updateBuild,
    addBuildLog,
    addBuildError,
    getAllBuilds
};
