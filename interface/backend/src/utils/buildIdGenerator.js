const { v4: uuidv4 } = require('uuid');

/**
 * Generate a unique build ID
 * @returns {string} UUID v4 string
 */
function generateBuildId() {
    return uuidv4();
}

module.exports = {
    generateBuildId
};
