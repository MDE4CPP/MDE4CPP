# Build script for MDE4CPP Terminal Docker image
# This creates a secure container image for terminal execution

$ErrorActionPreference = "Stop"

Write-Host "Building MDE4CPP Terminal Docker image..." -ForegroundColor Cyan

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$backendDir = Split-Path -Parent $scriptDir
$dockerDir = Join-Path $backendDir "docker"
$dockerfile = Join-Path $dockerDir "Dockerfile.terminal"

if (-not (Test-Path $dockerfile)) {
    Write-Error "Dockerfile not found: $dockerfile"
    exit 1
}

# Build the image
Write-Host "`nBuilding Docker image: mde4cpp-terminal:latest" -ForegroundColor Yellow
docker build -f $dockerfile -t mde4cpp-terminal:latest $dockerDir

if ($LASTEXITCODE -eq 0) {
    Write-Host "`n✓ Terminal Docker image built successfully!" -ForegroundColor Green
    Write-Host "`nImage: mde4cpp-terminal:latest" -ForegroundColor Cyan
    Write-Host "You can now start the backend server with secure terminal enabled." -ForegroundColor Cyan
} else {
    Write-Error "Failed to build Docker image"
    exit 1
}
