# MDE4CPP Build Service Backend

REST API backend for building and compiling MDE4CPP model files.

## Installation

1. Install Node.js dependencies:
```bash
npm install
```

2. Configure environment variables (copy `.env.example` to `.env` and update):
```bash
cp .env.example .env
```

3. Update `.env` with your MDE4CPP_HOME path:
```
MDE4CPP_HOME=D:\DEV\test2\MDE4CPP
```

## Running the Server

### Development
```bash
npm run dev
```

### Production
```bash
npm start
```

The server will start on `http://localhost:8000` by default.

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

### GET `/api/v1/build/:buildId/files`
List available output files.

### GET `/api/v1/build/:buildId/download/:fileType`
Download build artifacts. `fileType` can be: `dll`, `executable`, `all`, or `zip`.

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
- **Build Script:** PowerShell script integration
- **Storage:** File system (workspaces and outputs)
- **Status Tracking:** In-memory (Map)

## Development

See the architecture plan in `addition/plan/backend_architecture_plan.md` for detailed design information.
