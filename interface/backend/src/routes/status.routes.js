const express = require('express');
const statusController = require('../controllers/status.controller');

const router = express.Router();

// GET /api/v1/health - Health check
router.get('/health', statusController.health);

// GET /api/v1/stats - Service statistics
router.get('/stats', statusController.stats);

module.exports = router;
