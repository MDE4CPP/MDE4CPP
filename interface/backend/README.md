# MDE4CPP Build Service Backend

REST API backend for building and compiling MDE4CPP model files.

## Production Setup

### Prerequisites

- Node.js 18+ installed
- MDE4CPP project properly configured
- PowerShell 5.1+ (Windows)
- MDE4CPP build tools and dependencies installed

### Installation

1. **Install Node.js dependencies:**
```bash
cd interface/backend
npm install
```

2. **Configure environment variables:**

Copy `.env.example` to `.env`:
```bash
cp .env.example .env
```

3. **Update `.env` with your configuration:**

**Required settings:**
```env
# MDE4CPP_HOME must be an absolute path
MDE4CPP_HOME=D:\DEV\test2\MDE4CPP

# Server configuration
NODE_ENV=production
PORT=8000
HOST=0.0.0.0

# CORS - specify your frontend URL(s)
CORS_ORIGIN=http://localhost:3000,https://yourdomain.com
```

**Optional settings:**
```env
# Storage location (default: interface/backend/storage)
STORAGE_ROOT=storage

# Build configuration
MAX_CONCURRENT_BUILDS=3
BUILD_TIMEOUT_SECONDS=600

# Logging
LOG_LEVEL=info
LOG_FILE=logs/app.log
```

### File Locations

**Important:** All paths are resolved to absolute paths for production reliability.

#### Generated Files During Build

1. **Workspace Directory:** `{STORAGE_ROOT}/builds/{buildId}/`
   - `model/` - Uploaded model file (.ecore or .uml)
   - `src_gen/` - Generated C++ source code
   - `application/` - Application source code
   - `settings.gradle`, `build.gradle` - Generated build files

2. **Output Files (Generated):** `{MDE4CPP_HOME}/application/bin/`
   - `{ModelName}.dll` / `{ModelName}d.dll` - Library files (Release/Debug)
   - `App_{ModelName}.exe` / `App_{ModelName}d.exe` - Executables (Release/Debug)
   - `{ModelName}Exec.dll` - PSSM execution DLLs (if applicable)

3. **Output Files (Copied for Download):** `{STORAGE_ROOT}/outputs/{buildId}/`
   - `dlls/` - Copied DLL files
   - `executables/` - Copied executable files

#### Logs

- **Application Logs:** `{LOG_FILE}` (default: `interface/backend/logs/app.log`)
- **Error Logs:** `{LOG_FILE}` (error level)
- **Combined Logs:** `{LOG_FILE}` with `-combined` suffix

### Running the Server

#### Development
```bash
npm run dev
```

#### Production
```bash
npm start
```

The server will start on `http://localhost:8000` by default (or the port specified in `.env`).

### Verification

On startup, the server will:
- ✅ Create required storage directories
- ✅ Validate MDE4CPP_HOME exists
- ✅ Validate build script exists
- ✅ Validate application/bin directory exists

Check the console output for any warnings about missing directories or files.

## API Endpoints

### POST `/api/v1/build`
Upload a model file and start build process.

**Request:**
- Content-Type: `multipart/form-data`
- Body: `file` (model file .ecore or .uml)

**Response:**
```json
{
    "status": "accepted",
    "buildId": "550e8400-e29b-41d4-a716-446655440000",
    "message": "Build request accepted",
    "statusUrl": "/api/v1/build/550e8400-e29b-41d4-a716-446655440000/status"
}
```

### GET `/api/v1/build/:buildId/status`
Get build status and progress.

**Response:**
```json
{
    "buildId": "550e8400-e29b-41d4-a716-446655440000",
    "status": "completed",
    "stage": "completed",
    "progress": 100,
    "message": "Build completed successfully",
    "outputFiles": {
        "dlls": [...],
        "executables": [...]
    }
}
```

### GET `/api/v1/build/:buildId/files`
List available output files.

### GET `/api/v1/build/:buildId/download/:fileType`
Download build artifacts. `fileType` can be: `dll`, `executable`, `all`, or `zip`.

### GET `/api/v1/build/:buildId/logs`
Get build logs (optional `?tail=N` parameter for last N lines).

### GET `/api/v1/health`
Health check endpoint.

### GET `/api/v1/stats`
Service statistics.

## Testing Without Frontend

### Using the CLI Tool

The backend includes a CLI testing tool:

```bash
# Upload a file
node scripts/cli-test.js upload --file path/to/model.ecore

# Check status
node scripts/cli-test.js status --build-id <buildId>

# List files
node scripts/cli-test.js files --build-id <buildId>

# Download files
node scripts/cli-test.js download --build-id <buildId> --output ./downloads
```

### Development Testing Scripts

Development testing scripts are located in `scripts/dev/`:
- `test-all-models.js` - Test multiple model types
- `test-single-model.js` - Test a single model

### Using cURL

```bash
# Upload file
curl -X POST http://localhost:8000/api/v1/build \
  -F "file=@model.ecore"

# Check status
curl http://localhost:8000/api/v1/build/{buildId}/status

# Download files
curl http://localhost:8000/api/v1/build/{buildId}/download/zip \
  -o build_output.zip
```

### Using PowerShell

```powershell
# Upload file
$file = Get-Item "model.ecore"
$form = @{file=$file}
$response = Invoke-RestMethod -Uri "http://localhost:8000/api/v1/build" `
    -Method Post -Form $form

# Check status
$status = Invoke-RestMethod -Uri "http://localhost:8000/api/v1/build/$($response.buildId)/status"

# Download files
Invoke-WebRequest -Uri "http://localhost:8000/api/v1/build/$($response.buildId)/download/zip" `
    -OutFile "output.zip"
```

## Architecture

- **Framework:** Express.js
- **File Upload:** Multer
- **Build Script:** PowerShell script integration (`addition/script/build-model-workspace.ps1`)
- **Storage:** File system (workspaces and outputs)
- **Status Tracking:** In-memory (Map)

### Build Process Flow

1. **Upload:** Model file uploaded → saved to `storage/builds/{buildId}/model/`
2. **Generation:** PowerShell script generates C++ code → `storage/builds/{buildId}/src_gen/`
3. **Compilation:** Gradle compiles code → outputs to `MDE4CPP_HOME/application/bin/`
4. **Collection:** Backend finds output files in `application/bin/`
5. **Copy:** Output files copied to `storage/outputs/{buildId}/` for download
6. **Download:** Users can download files via API

### Supported Model Types

- **ECORE** models (.ecore files)
- **UML** models (.uml files)
- **fUML** models (UML with behaviors)
- **PSSM** models (State machines)
- **PSCS** models (Component structures)
- **OCL** models (with constraints)

## Troubleshooting

### Build Fails

1. Check MDE4CPP_HOME is correct and exists
2. Verify build script exists: `{MDE4CPP_HOME}/addition/script/build-model-workspace.ps1`
3. Check application/bin directory exists: `{MDE4CPP_HOME}/application/bin/`
4. Review build logs via `/api/v1/build/{buildId}/logs`

### Output Files Not Found

1. Verify model name matches file naming patterns
2. Check `application/bin/` directory for generated files
3. Review file detection logic in logs

### Path Issues

- All paths are resolved to absolute paths on startup
- Check console warnings for path validation
- Ensure MDE4CPP_HOME is an absolute path in `.env`

## Development

See the architecture plan in `addition/plan/backend_architecture_plan.md` for detailed design information.
