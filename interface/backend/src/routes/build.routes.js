const express = require('express');
const multer = require('multer');
const path = require('path');
const buildController = require('../controllers/build.controller');
const downloadController = require('../controllers/download.controller');
const { validateFileUpload, validateBuildId } = require('../middleware/validator');
const config = require('../config');
const fs = require('fs-extra');

const router = express.Router();

// Configure multer for file uploads
const upload = multer({
    dest: path.join(config.storage.root, 'uploads'),
    limits: {
        fileSize: config.storage.uploadMaxSizeMB * 1024 * 1024
    },
    fileFilter: (req, file, cb) => {
        const ext = path.extname(file.originalname).toLowerCase();
        if (ext === '.ecore' || ext === '.uml') {
            cb(null, true);
        } else {
            cb(new Error('Only .ecore and .uml files are allowed'));
        }
    }
});

// POST /api/v1/build - Upload file and start build
router.post('/',
    upload.single('file'),
    validateFileUpload,
    buildController.createBuild
);

// GET /api/v1/build/:buildId/status - Get build status
router.get('/:buildId/status',
    validateBuildId,
    buildController.getStatus
);

// GET /api/v1/build/:buildId/logs - Get build logs
router.get('/:buildId/logs',
    validateBuildId,
    buildController.getLogs
);

// GET /api/v1/build/:buildId/files - Get file list
router.get('/:buildId/files',
    validateBuildId,
    buildController.getFiles
);

// GET /api/v1/build/:buildId/download/:fileType - Download files
router.get('/:buildId/download/:fileType',
    validateBuildId,
    downloadController.downloadFiles
);

module.exports = router;
