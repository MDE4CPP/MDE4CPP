# MDE4CPP Build Service Backend Architecture Plan

**Created:** January 14, 2026  
**Technology Stack:** Node.js + Express  
**Location:** `interface/backend/`  
**Purpose:** REST API backend for building and compiling MDE4CPP model files

---

## Architecture Overview

### Technology Stack

- **Runtime:** Node.js (v18+)
- **Framework:** Express.js
- **File Upload:** multer
- **Process Execution:** child_process (for PowerShell scripts)
- **Job Queue:** bull (Redis-based, optional) or simple in-memory queue
- **Validation:** express-validator / joi
- **Documentation:** swagger-jsdoc + swagger-ui-express
- **Logging:** winston
- **Environment:** dotenv

**Why Node.js:**
- ✅ Excellent async/await support
- ✅ Great file handling capabilities
- ✅ Easy process execution (PowerShell scripts)
- ✅ Large ecosystem
- ✅ Fast development
- ✅ Easy testing
- ✅ Can easily wrap PowerShell scripts

---

## Directory Structure

```
interface/
└── backend/
    ├── src/
    │   ├── index.js                    # Application entry point
    │   ├── app.js                      # Express app configuration
    │   ├── config/
    │   │   ├── index.js                # Configuration management
    │   │   └── constants.js            # Constants
    │   ├── routes/
    │   │   ├── index.js                # Route aggregator
    │   │   ├── build.routes.js         # Build endpoints
    │   │   ├── status.routes.js        # Status endpoints
    │   │   └── download.routes.js      # Download endpoints
    │   ├── controllers/
    │   │   ├── build.controller.js     # Build request handlers
    │   │   ├── status.controller.js    # Status handlers
    │   │   └── download.controller.js  # Download handlers
    │   ├── services/
    │   │   ├── build.service.js        # Build orchestration
    │   │   ├── file.service.js         # File handling
    │   │   ├── storage.service.js      # File storage management
    │   │   └── script.service.js       # PowerShell script execution
    │   ├── models/
    │   │   └── build.model.js          # Build data models
    │   ├── middleware/
    │   │   ├── errorHandler.js         # Error handling middleware
    │   │   ├── validator.js            # Request validation
    │   │   └── logger.js               # Request logging
    │   ├── utils/
    │   │   ├── logger.js               # Winston logger setup
    │   │   ├── pathUtils.js            # Path utilities
    │   │   ├── buildIdGenerator.js     # Unique ID generation
    │   │   └── validators.js           # Input validation
    │   └── jobs/
    │       └── buildQueue.js           # Build job queue (optional)
    ├── storage/
    │   ├── uploads/                    # Temporary uploaded files
    │   ├── builds/                     # Build workspaces (isolated per build)
    │   │   └── {buildId}/
    │   │       ├── model/
    │   │       ├── src_gen/
    │   │       └── application/
    │   └── outputs/                    # Build outputs (organized by build_id)
    │       └── {buildId}/
    │           ├── dlls/
    │           └── executables/
    ├── tests/
    │   ├── unit/
    │   │   ├── services/
    │   │   └── utils/
    │   ├── integration/
    │   │   └── build.test.js
    │   └── fixtures/                   # Test files
    │       └── sample.ecore
    ├── scripts/
    │   └── cli-test.js                 # CLI testing script
    ├── .env.example                    # Environment variables template
    ├── .gitignore
    ├── package.json
    ├── README.md                       # Backend documentation
    └── swagger.yaml                    # API documentation (optional)
```

---

## API Endpoints

### 1. Build Endpoints

#### POST `/api/v1/build`
**Description:** Upload model file and start build process

**Request:**
- Method: `POST`
- Content-Type: `multipart/form-data`
- Body:
  - `file`: Model file (.ecore or .uml) - **required**
  - `options` (optional JSON string): Build options
    ```json
    {
        "publishPlugins": false,
        "generateOnly": false,
        "compileOnly": false
    }
    ```

**Response (202 Accepted - Async):**
```json
{
    "status": "accepted",
    "buildId": "550e8400-e29b-41d4-a716-446655440000",
    "message": "Build request accepted",
    "statusUrl": "/api/v1/build/550e8400-e29b-41d4-a716-446655440000/status",
    "estimatedTime": "2-5 minutes"
}
```

**Status Codes:**
- `202 Accepted` - Build request accepted
- `400 Bad Request` - Invalid file or options
- `413 Payload Too Large` - File too large
- `500 Internal Server Error` - Server error

#### GET `/api/v1/build/{buildId}/status`
**Description:** Get build status and progress

**Response:**
```json
{
    "buildId": "550e8400-e29b-41d4-a716-446655440000",
    "status": "building|completed|failed|queued",
    "progress": 75,
    "stage": "compiling",
    "message": "Compiling library...",
    "startedAt": "2026-01-14T19:30:00Z",
    "completedAt": null,
    "outputFiles": {
        "dlls": [],
        "executables": []
    },
    "errors": []
}
```

**Status Values:**
- `queued` - Build is queued
- `building` - Build in progress
- `completed` - Build completed successfully
- `failed` - Build failed
- `cancelled` - Build was cancelled

#### GET `/api/v1/build/{buildId}/logs`
**Description:** Get build logs (streaming or full)

**Query Parameters:**
- `stream` (optional): `true` for Server-Sent Events streaming
- `tail` (optional): Number of last lines to return

**Response:**
```json
{
    "buildId": "550e8400-e29b-41d4-a716-446655440000",
    "logs": [
        {
            "timestamp": "2026-01-14T19:30:05Z",
            "level": "info",
            "message": "Starting build process...",
            "stage": "initialization"
        },
        {
            "timestamp": "2026-01-14T19:30:10Z",
            "level": "info",
            "message": "Code generation completed",
            "stage": "generation"
        }
    ],
    "totalLines": 150
}
```

### 2. Download Endpoints

#### GET `/api/v1/build/{buildId}/download/{fileType}`
**Description:** Download build artifacts

**Parameters:**
- `fileType`: `dll` | `executable` | `all` | `zip`

**Examples:**
- `/api/v1/build/{buildId}/download/zip` - Download all files as ZIP
- `/api/v1/build/{buildId}/download/dll` - Download DLL files as ZIP
- `/api/v1/build/{buildId}/download/executable` - Download executables as ZIP

**Response:**
- File download (binary)
- Content-Type: `application/zip` or `application/octet-stream`
- Content-Disposition: `attachment; filename="build-{buildId}.zip"`

#### GET `/api/v1/build/{buildId}/files`
**Description:** List available output files with metadata

**Response:**
```json
{
    "buildId": "550e8400-e29b-41d4-a716-446655440000",
    "files": {
        "dlls": [
            {
                "name": "libraryModel_ecore.dll",
                "size": 1081856,
                "sizeFormatted": "1.03 MB",
                "downloadUrl": "/api/v1/build/{buildId}/download/dll/libraryModel_ecore.dll",
                "createdAt": "2026-01-14T19:32:00Z"
            },
            {
                "name": "libraryModel_ecored.dll",
                "size": 8262416,
                "sizeFormatted": "7.88 MB",
                "downloadUrl": "/api/v1/build/{buildId}/download/dll/libraryModel_ecored.dll",
                "createdAt": "2026-01-14T19:32:05Z"
            }
        ],
        "executables": [
            {
                "name": "App_libraryModel_ecore.exe",
                "size": 211862,
                "sizeFormatted": "206.9 KB",
                "downloadUrl": "/api/v1/build/{buildId}/download/executable/App_libraryModel_ecore.exe",
                "createdAt": "2026-01-14T19:32:15Z"
            },
            {
                "name": "App_libraryModel_ecored.exe",
                "size": 849275,
                "sizeFormatted": "829.37 KB",
                "downloadUrl": "/api/v1/build/{buildId}/download/executable/App_libraryModel_ecored.exe",
                "createdAt": "2026-01-14T19:32:20Z"
            }
        ]
    }
}
```

### 3. Health/Status Endpoints

#### GET `/api/v1/health`
**Description:** Health check endpoint

**Response:**
```json
{
    "status": "healthy",
    "version": "1.0.0",
    "timestamp": "2026-01-14T19:30:00Z",
    "uptime": 3600
}
```

#### GET `/api/v1/stats`
**Description:** Service statistics

**Response:**
```json
{
    "activeBuilds": 2,
    "queuedBuilds": 5,
    "completedBuilds": 150,
    "failedBuilds": 3,
    "totalBuilds": 160,
    "averageBuildTime": "2m 30s"
}
```

---

## Build Service Flow

### 1. File Upload & Validation
```
User uploads file via POST /api/v1/build
    ↓
Validate file type (.ecore/.uml) - multer + custom validation
    ↓
Validate file size (max 50MB configurable)
    ↓
Generate unique build ID (UUID v4)
    ↓
Create isolated workspace: storage/builds/{buildId}/
    ↓
Set up directory structure:
    storage/builds/{buildId}/model/
    storage/builds/{buildId}/src_gen/
    storage/builds/{buildId}/application/
    ↓
Save uploaded file to: storage/builds/{buildId}/model/{filename}
    ↓
Create build record in memory/DB
    ↓
Return 202 Accepted with buildId
```

### 2. Build Process (Async)
```
Queue build job (if queue system implemented)
    ↓
Execute PowerShell script:
    node child_process.exec() or child_process.spawn()
    Script: addition/script/build-model.ps1
    Parameters:
        -ModelFilePath: {workspace}/model/{filename}
        -WorkspacePath: {workspace}
        -OutputFormat: JSON (if supported)
        -MDE4CPP_HOME: {env.MDE4CPP_HOME}
    ↓
Monitor build progress (capture stdout/stderr)
    ↓
Parse script output (if JSON mode)
    ↓
Update build status periodically
    ↓
Collect output files from workspace
    ↓
Move outputs to: storage/outputs/{buildId}/
    ↓
Update build status to 'completed' or 'failed'
    ↓
Clean workspace (optional, after download/expiry)
```

### 3. Output Management
```
After build completion:
    ↓
Scan workspace for output files:
    - DLLs: application/bin/{modelName}*.dll
    - Executables: application/bin/App_{modelName}*.exe
    - Headers: application/include/{modelName}/
    ↓
Copy outputs to: storage/outputs/{buildId}/
    ↓
Organize structure:
    storage/outputs/{buildId}/dlls/
    storage/outputs/{buildId}/executables/
    storage/outputs/{buildId}/headers/
    ↓
Generate download URLs
    ↓
Update build record with file metadata
    ↓
Set expiration timestamp (24 hours default)
```

---

## Node.js Implementation Details

### Core Dependencies (package.json)

```json
{
  "name": "mde4cpp-build-service",
  "version": "1.0.0",
  "description": "MDE4CPP Model Build Service API",
  "main": "src/index.js",
  "scripts": {
    "start": "node src/index.js",
    "dev": "nodemon src/index.js",
    "test": "jest",
    "test:watch": "jest --watch"
  },
  "dependencies": {
    "express": "^4.18.2",
    "multer": "^1.4.5-lts.1",
    "cors": "^2.8.5",
    "dotenv": "^16.3.1",
    "uuid": "^9.0.1",
    "winston": "^3.11.0",
    "express-validator": "^7.0.1",
    "archiver": "^6.0.1",
    "fs-extra": "^11.2.0",
    "path": "^0.12.7"
  },
  "devDependencies": {
    "nodemon": "^3.0.2",
    "jest": "^29.7.0",
    "supertest": "^6.3.3"
  }
}
```

### Key Service Implementation

#### build.service.js Structure
```javascript
class BuildService {
    async createBuild(file, options) {
        // Generate build ID
        // Create workspace
        // Save file
        // Queue build job
        // Return build ID
    }
    
    async executeBuild(buildId) {
        // Execute PowerShell script
        // Monitor progress
        // Update status
        // Collect outputs
    }
    
    async getBuildStatus(buildId) {
        // Return current build status
    }
    
    async getBuildLogs(buildId) {
        // Return build logs
    }
}
```

#### script.service.js (PowerShell Execution)
```javascript
class ScriptService {
    async executeBuildScript(modelFilePath, workspacePath, options) {
        // Use child_process.spawn() to execute PowerShell
        // Capture stdout/stderr
        // Parse output
        // Return result
    }
}
```

---

## Build Script Integration

### Required Script Modifications

The existing `addition/script/build-model.ps1` needs these modifications:

1. **JSON Output Mode** (Future Enhancement)
   - Add `-OutputFormat JSON` parameter
   - Output JSON to stdout instead of Write-Host
   - Include progress updates

2. **Workspace Parameter** (Critical)
   - Add `-WorkspacePath` parameter
   - Use provided workspace instead of auto-detection
   - Output files to workspace-specific location

3. **Progress File** (Alternative if JSON not available)
   - Write progress to: `{workspace}/.build_progress.json`
   - Include: status, stage, progress percentage

### Current Script Usage (Without Modifications)

Since the script currently uses Write-Host, we can:
1. Capture stdout/stderr from PowerShell execution
2. Parse text output to extract status
3. Monitor file system for output files
4. Use file timestamps to track progress

### Script Execution Pattern

```javascript
const { spawn } = require('child_process');
const path = require('path');

async function executeBuild(modelFilePath, workspacePath) {
    const scriptPath = path.join(process.cwd(), 'addition/script/build-model.ps1');
    const psProcess = spawn('powershell.exe', [
        '-ExecutionPolicy', 'Bypass',
        '-File', scriptPath,
        '-ModelFilePath', modelFilePath,
        '-MDE4CPP_HOME', process.env.MDE4CPP_HOME
    ]);
    
    let stdout = '';
    let stderr = '';
    
    psProcess.stdout.on('data', (data) => {
        stdout += data.toString();
        // Parse output, update progress
    });
    
    psProcess.stderr.on('data', (data) => {
        stderr += data.toString();
    });
    
    psProcess.on('close', (code) => {
        // Handle completion
    });
}
```

---

## Testing Without Frontend

### 1. CLI Testing Script (`scripts/cli-test.js`)

```javascript
#!/usr/bin/env node

// CLI tool for testing the backend
// Usage:
//   node scripts/cli-test.js upload --file model.ecore
//   node scripts/cli-test.js status --build-id <id>
//   node scripts/cli-test.js download --build-id <id> --output ./downloads

const axios = require('axios');
const FormData = require('form-data');
const fs = require('fs');
const path = require('path');

const API_BASE_URL = process.env.API_URL || 'http://localhost:8000/api/v1';

async function uploadFile(filePath) {
    const form = new FormData();
    form.append('file', fs.createReadStream(filePath));
    
    const response = await axios.post(`${API_BASE_URL}/build`, form, {
        headers: form.getHeaders()
    });
    
    console.log('Build started:', response.data);
    return response.data.buildId;
}

async function checkStatus(buildId) {
    const response = await axios.get(`${API_BASE_URL}/build/${buildId}/status`);
    console.log('Build status:', response.data);
    return response.data;
}

async function downloadFiles(buildId, outputDir) {
    const response = await axios.get(
        `${API_BASE_URL}/build/${buildId}/download/zip`,
        { responseType: 'stream' }
    );
    
    const outputPath = path.join(outputDir, `build-${buildId}.zip`);
    const writer = fs.createWriteStream(outputPath);
    
    response.data.pipe(writer);
    
    return new Promise((resolve, reject) => {
        writer.on('finish', resolve);
        writer.on('error', reject);
    });
}

// CLI interface
const [,, command, ...args] = process.argv;

if (command === 'upload') {
    const fileIndex = args.indexOf('--file');
    if (fileIndex === -1) {
        console.error('Usage: cli-test.js upload --file <path>');
        process.exit(1);
    }
    const filePath = args[fileIndex + 1];
    uploadFile(filePath).then(buildId => {
        console.log(`Build ID: ${buildId}`);
        console.log(`Check status: node scripts/cli-test.js status --build-id ${buildId}`);
    });
} else if (command === 'status') {
    const buildIdIndex = args.indexOf('--build-id');
    if (buildIdIndex === -1) {
        console.error('Usage: cli-test.js status --build-id <id>');
        process.exit(1);
    }
    const buildId = args[buildIdIndex + 1];
    checkStatus(buildId);
} else if (command === 'download') {
    const buildIdIndex = args.indexOf('--build-id');
    const outputIndex = args.indexOf('--output');
    if (buildIdIndex === -1) {
        console.error('Usage: cli-test.js download --build-id <id> --output <dir>');
        process.exit(1);
    }
    const buildId = args[buildIdIndex + 1];
    const outputDir = outputIndex !== -1 ? args[outputIndex + 1] : './downloads';
    downloadFiles(buildId, outputDir).then(() => {
        console.log(`Files downloaded to ${outputDir}`);
    });
}
```

### 2. cURL Examples

```bash
# Upload and build
curl -X POST http://localhost:8000/api/v1/build \
  -F "file=@libraryModel_ecore.ecore" \
  -H "Content-Type: multipart/form-data"

# Check status
curl http://localhost:8000/api/v1/build/{buildId}/status

# Get file list
curl http://localhost:8000/api/v1/build/{buildId}/files

# Download all files as ZIP
curl http://localhost:8000/api/v1/build/{buildId}/download/zip \
  -o build_output.zip

# Download DLLs only
curl http://localhost:8000/api/v1/build/{buildId}/download/dll \
  -o dlls.zip
```

### 3. PowerShell Testing

```powershell
# Upload file
$file = Get-Item "libraryModel_ecore.ecore"
$form = @{
    file = $file
}
$response = Invoke-RestMethod -Uri "http://localhost:8000/api/v1/build" `
    -Method Post `
    -Form $form `
    -ContentType "multipart/form-data"

# Get status
$buildId = $response.buildId
$status = Invoke-RestMethod -Uri "http://localhost:8000/api/v1/build/$buildId/status"

# Download files
Invoke-WebRequest -Uri "http://localhost:8000/api/v1/build/$buildId/download/zip" `
    -OutFile "output.zip"
```

---

## Configuration

### Environment Variables (`.env`)

```env
# Server Configuration
NODE_ENV=development
PORT=8000
HOST=0.0.0.0

# MDE4CPP Configuration
MDE4CPP_HOME=D:\DEV\test2\MDE4CPP
MDE4CPP_WORKSPACE_ROOT=interface/backend/storage/builds

# File Storage
UPLOAD_MAX_SIZE_MB=50
STORAGE_ROOT=interface/backend/storage
OUTPUT_RETENTION_HOURS=24

# Build Configuration
MAX_CONCURRENT_BUILDS=3
BUILD_TIMEOUT_SECONDS=600

# PowerShell Configuration
POWERSHELL_EXECUTION_POLICY=Bypass

# CORS Configuration
CORS_ORIGIN=http://localhost:3000,http://localhost:8080

# Logging
LOG_LEVEL=info
LOG_FILE=logs/app.log
```

---

## Security Considerations

1. **File Upload Security**
   - Validate file types (whitelist: .ecore, .uml only)
   - Validate file size limits (configurable, default 50MB)
   - Sanitize filenames (remove special chars, prevent path traversal)
   - Scan filenames for malicious patterns

2. **Path Security**
   - Prevent directory traversal attacks
   - Use absolute paths within workspace only
   - Validate all file paths before access
   - Use path.join() instead of string concatenation

3. **Build Isolation**
   - Each build in isolated workspace directory
   - No access between builds
   - Cleanup after completion/expiry
   - Use unique build IDs (UUID v4)

4. **Process Security**
   - Timeout for build processes
   - Resource limits
   - Validate script paths
   - Sanitize command arguments

5. **Rate Limiting** (Future)
   - Limit requests per IP
   - Queue system for builds
   - Max concurrent builds per user

6. **Authentication** (Future)
   - API keys
   - JWT tokens
   - User authentication
   - Build quotas per user

---

## Error Handling

### Error Response Format

```json
{
    "error": {
        "code": "BUILD_FAILED",
        "message": "Compilation failed: missing dependencies",
        "details": {
            "stage": "compilation",
            "exitCode": 1,
            "logs": "Error output..."
        },
        "timestamp": "2026-01-14T19:32:15Z"
    }
}
```

### Error Codes

- `INVALID_FILE_TYPE` (400): File is not .ecore or .uml
- `FILE_TOO_LARGE` (413): File exceeds size limit
- `INVALID_FILE_NAME` (400): Filename contains invalid characters
- `BUILD_NOT_FOUND` (404): Build ID does not exist
- `BUILD_FAILED` (500): Build process failed
- `BUILD_TIMEOUT` (504): Build exceeded timeout
- `WORKSPACE_ERROR` (500): Failed to create workspace
- `SCRIPT_ERROR` (500): PowerShell script execution error
- `STORAGE_ERROR` (500): File storage operation failed

### Error Middleware

```javascript
// middleware/errorHandler.js
function errorHandler(err, req, res, next) {
    logger.error(err);
    
    res.status(err.status || 500).json({
        error: {
            code: err.code || 'INTERNAL_ERROR',
            message: err.message || 'Internal server error',
            details: err.details,
            timestamp: new Date().toISOString()
        }
    });
}
```

---

## Build Status Tracking

### In-Memory Storage (Initial Implementation)

```javascript
// Simple in-memory store (can be replaced with Redis/DB later)
const builds = new Map();

// Build record structure
{
    buildId: 'uuid',
    status: 'queued|building|completed|failed',
    progress: 0-100,
    stage: 'initialization|generation|compilation|completed',
    message: 'Current status message',
    file: {
        originalName: 'model.ecore',
        savedPath: 'storage/builds/{buildId}/model/model.ecore'
    },
    outputFiles: {
        dlls: [],
        executables: []
    },
    logs: [],
    errors: [],
    startedAt: Date,
    completedAt: Date,
    createdAt: Date
}
```

### Future: Database/Redis Storage
- Redis for fast status lookups
- PostgreSQL/MongoDB for persistent storage
- Job queue system (Bull/BullMQ)

---

## Implementation Phases

### Phase 1: Core API (MVP)
- [ ] Express server setup
- [ ] File upload endpoint (POST /api/v1/build)
- [ ] Build status endpoint (GET /api/v1/build/{id}/status)
- [ ] Basic build execution (PowerShell script integration)
- [ ] File download endpoint (GET /api/v1/build/{id}/download/zip)
- [ ] CLI testing tool
- [ ] Error handling
- [ ] Basic logging

### Phase 2: Enhanced Features
- [ ] Build queue system (in-memory or Bull)
- [ ] Progress tracking (file monitoring)
- [ ] Build logs endpoint (GET /api/v1/build/{id}/logs)
- [ ] File listing endpoint (GET /api/v1/build/{id}/files)
- [ ] Multiple download options (dll, executable, all)
- [ ] Health check endpoint
- [ ] Statistics endpoint

### Phase 3: Production Ready
- [ ] Authentication/Authorization
- [ ] Rate limiting
- [ ] Build caching (detect duplicate builds)
- [ ] Cleanup job (remove old builds)
- [ ] API documentation (Swagger)
- [ ] Comprehensive testing
- [ ] Docker containerization
- [ ] Monitoring and metrics

---

## Testing Strategy

### 1. Unit Tests (Jest)
- File validation functions
- Path sanitization
- Build ID generation
- Status tracking logic
- Error handling

### 2. Integration Tests
- End-to-end build flow
- File upload → build → download
- Error scenarios
- Concurrent builds (if queue implemented)

### 3. CLI Testing
- Manual testing via CLI tool
- Script testing via PowerShell
- cURL testing
- Postman collection (optional)

---

## API Response Examples

### Successful Build Status
```json
{
    "buildId": "abc123-def456-ghi789",
    "status": "completed",
    "progress": 100,
    "stage": "completed",
    "message": "Build completed successfully",
    "startedAt": "2026-01-14T19:30:00Z",
    "completedAt": "2026-01-14T19:32:15Z",
    "outputFiles": {
        "dlls": [
            {
                "name": "libraryModel_ecore.dll",
                "size": 1081856,
                "path": "storage/outputs/abc123/dlls/libraryModel_ecore.dll"
            },
            {
                "name": "libraryModel_ecored.dll",
                "size": 8262416,
                "path": "storage/outputs/abc123/dlls/libraryModel_ecored.dll"
            }
        ],
        "executables": [
            {
                "name": "App_libraryModel_ecore.exe",
                "size": 211862,
                "path": "storage/outputs/abc123/executables/App_libraryModel_ecore.exe"
            },
            {
                "name": "App_libraryModel_ecored.exe",
                "size": 849275,
                "path": "storage/outputs/abc123/executables/App_libraryModel_ecored.exe"
            }
        ]
    },
    "errors": []
}
```

### Failed Build Status
```json
{
    "buildId": "abc123-def456-ghi789",
    "status": "failed",
    "progress": 45,
    "stage": "compilation",
    "message": "Compilation failed",
    "startedAt": "2026-01-14T19:30:00Z",
    "completedAt": "2026-01-14T19:31:30Z",
    "outputFiles": {
        "dlls": [],
        "executables": []
    },
    "errors": [
        {
            "stage": "compilation",
            "message": "Error: Missing dependency library",
            "details": "ecore.dll not found"
        }
    ]
}
```

---

## Key Implementation Files

### 1. src/index.js (Entry Point)
```javascript
const app = require('./app');
const config = require('./config');

const PORT = config.port || 8000;
const HOST = config.host || '0.0.0.0';

app.listen(PORT, HOST, () => {
    console.log(`MDE4CPP Build Service API running on http://${HOST}:${PORT}`);
    console.log(`Environment: ${config.env}`);
});
```

### 2. src/app.js (Express App)
```javascript
const express = require('express');
const cors = require('cors');
const routes = require('./routes');
const errorHandler = require('./middleware/errorHandler');

const app = express();

app.use(cors());
app.use(express.json());
app.use('/api/v1', routes);
app.use(errorHandler);

module.exports = app;
```

### 3. src/routes/build.routes.js
```javascript
const express = require('express');
const multer = require('multer');
const buildController = require('../controllers/build.controller');
const { validateFileUpload } = require('../middleware/validator');

const router = express.Router();
const upload = multer({ 
    dest: 'storage/uploads/',
    limits: { fileSize: 50 * 1024 * 1024 } // 50MB
});

router.post('/build', 
    upload.single('file'),
    validateFileUpload,
    buildController.createBuild
);

router.get('/build/:buildId/status', buildController.getStatus);
router.get('/build/:buildId/files', buildController.getFiles);
router.get('/build/:buildId/logs', buildController.getLogs);

module.exports = router;
```

---

## Next Steps

1. **Create directory structure** in `interface/backend/`
2. **Initialize Node.js project** (`npm init`)
3. **Install dependencies** (`npm install`)
4. **Create basic Express server**
5. **Implement file upload endpoint**
6. **Integrate PowerShell script execution**
7. **Implement status tracking**
8. **Create download endpoints**
9. **Build CLI testing tool**
10. **Testing and validation**

---

## Notes

- **Script Integration**: Initially, the script will be called as-is with stdout/stderr capture. JSON output mode can be added later.
- **Progress Tracking**: Monitor file system (output file creation) to track progress until script supports JSON output.
- **Workspace Management**: Each build gets isolated workspace. Cleanup after download or expiry.
- **Scalability**: Start with in-memory status storage. Can upgrade to Redis/DB later.
- **Testing**: CLI tool allows testing without frontend from day one.

---

**Last Updated:** January 14, 2026  
**Technology:** Node.js + Express.js  
**Status:** Planning Phase
