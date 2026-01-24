const express = require('express');
const buildRoutes = require('./build.routes');
const statusRoutes = require('./status.routes');
const pluginRoutes = require('./plugin.routes');  // Add this line

const router = express.Router();

router.use('/build', buildRoutes);
router.use('/plugins', pluginRoutes);  // Add this line
router.use('/', statusRoutes);

module.exports = router;