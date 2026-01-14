const express = require('express');
const buildRoutes = require('./build.routes');
const statusRoutes = require('./status.routes');

const router = express.Router();

router.use('/build', buildRoutes);
router.use('/', statusRoutes);

module.exports = router;
