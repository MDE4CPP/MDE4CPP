# Setup script for Secure Terminal
# This script checks prerequisites and builds the Docker image

$ErrorActionPreference = "Stop"

Write-Host "MDE4CPP Secure Terminal Setup" -ForegroundColor Cyan
Write-Host "==============================" -ForegroundColor Cyan
Write-Host ""

# Check if Docker is installed
Write-Host "Checking Docker installation..." -ForegroundColor Yellow
try {
    $dockerVersion = docker --version 2>&1
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✓ Docker found: $dockerVersion" -ForegroundColor Green
    } else {
        Write-Error "Docker is not installed or not in PATH"
        Write-Host "Please install Docker Desktop from: https://www.docker.com/products/docker-desktop" -ForegroundColor Yellow
        exit 1
    }
} catch {
    Write-Error "Docker is not installed or not in PATH"
    Write-Host "Please install Docker Desktop from: https://www.docker.com/products/docker-desktop" -ForegroundColor Yellow
    exit 1
}

# Check if Docker daemon is running
Write-Host "`nChecking Docker daemon..." -ForegroundColor Yellow
try {
    docker ps | Out-Null
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✓ Docker daemon is running" -ForegroundColor Green
    } else {
        throw "Docker daemon not running"
    }
} catch {
    Write-Host "✗ Docker daemon is not running" -ForegroundColor Red
    Write-Host ""
    Write-Host "Please start Docker Desktop:" -ForegroundColor Yellow
    Write-Host "  1. Open Docker Desktop application" -ForegroundColor White
    Write-Host "  2. Wait for it to fully start (whale icon in system tray)" -ForegroundColor White
    Write-Host "  3. Run this script again" -ForegroundColor White
    Write-Host ""
    Write-Host "Or start Docker Desktop now and press any key to continue..." -ForegroundColor Cyan
    $null = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")
    
    # Wait a bit for Docker to start
    Write-Host "Waiting for Docker to start..." -ForegroundColor Yellow
    $maxAttempts = 30
    $attempt = 0
    while ($attempt -lt $maxAttempts) {
        Start-Sleep -Seconds 2
        try {
            docker ps | Out-Null
            if ($LASTEXITCODE -eq 0) {
                Write-Host "✓ Docker daemon is now running" -ForegroundColor Green
                break
            }
        } catch {
            # Continue waiting
        }
        $attempt++
        Write-Host "." -NoNewline -ForegroundColor Gray
    }
    Write-Host ""
    
    if ($attempt -ge $maxAttempts) {
        Write-Error "Docker daemon did not start. Please start Docker Desktop manually and try again."
        exit 1
    }
}

# Check if npm dependencies are installed
Write-Host "`nChecking npm dependencies..." -ForegroundColor Yellow
if (Test-Path "node_modules") {
    Write-Host "✓ Dependencies appear to be installed" -ForegroundColor Green
} else {
    Write-Host "Installing npm dependencies..." -ForegroundColor Yellow
    npm install
    if ($LASTEXITCODE -ne 0) {
        Write-Error "Failed to install npm dependencies"
        exit 1
    }
    Write-Host "✓ Dependencies installed" -ForegroundColor Green
}

# Build Docker image
Write-Host "`nBuilding terminal Docker image..." -ForegroundColor Yellow
$dockerfile = Join-Path $PSScriptRoot "..\docker\Dockerfile.terminal"
$dockerDir = Join-Path $PSScriptRoot "..\docker"

if (-not (Test-Path $dockerfile)) {
    Write-Error "Dockerfile not found: $dockerfile"
    exit 1
}

Write-Host "Building image: mde4cpp-terminal:latest" -ForegroundColor Cyan
docker build -f $dockerfile -t mde4cpp-terminal:latest $dockerDir

if ($LASTEXITCODE -eq 0) {
    Write-Host ""
    Write-Host "✓ Setup complete!" -ForegroundColor Green
    Write-Host ""
    Write-Host "The secure terminal is ready to use." -ForegroundColor Cyan
    Write-Host "Start the server with: npm start" -ForegroundColor Cyan
    Write-Host ""
    Write-Host "Security features enabled:" -ForegroundColor Yellow
    Write-Host "  - Container isolation" -ForegroundColor White
    Write-Host "  - Network isolation (no internet access)" -ForegroundColor White
    Write-Host "  - Resource limits (512MB RAM, 50% CPU)" -ForegroundColor White
    Write-Host "  - Read-only MDE4CPP_HOME" -ForegroundColor White
    Write-Host "  - Non-root user execution" -ForegroundColor White
} else {
    Write-Error "Failed to build Docker image"
    exit 1
}
