const express = require('express');
const multer = require('multer');
const path = require('path');
const terminalController = require('../controllers/terminal.controller');
const config = require('../config');
const fs = require('fs-extra');

const router = express.Router();

// Configure multer for terminal file uploads
const upload = multer({
    dest: path.join(config.storage.root, 'terminals', 'temp'),
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

// Ensure temp directory exists
fs.ensureDirSync(path.join(config.storage.root, 'terminals', 'temp'));

// POST /api/v1/terminal/:sessionId/upload - Upload file to terminal workspace
router.post('/:sessionId/upload',
    upload.single('file'),
    terminalController.uploadFile
);

// GET /api/v1/terminal/:sessionId/files - List files in terminal workspace
router.get('/:sessionId/files',
    terminalController.listFiles
);

module.exports = router;
