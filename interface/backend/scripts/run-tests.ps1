# Script to start backend and run comprehensive tests
$ErrorActionPreference = "Continue"

$scriptsDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$backendDir = Split-Path -Parent $scriptsDir
$interfaceDir = Split-Path -Parent $backendDir
$mde4cppHome = Split-Path -Parent $interfaceDir

# Override with environment variable if set
if ($env:MDE4CPP_HOME) {
    $mde4cppHome = $env:MDE4CPP_HOME
}

Write-Host "==========================================" -ForegroundColor Cyan
Write-Host "MDE4CPP Backend Test Runner" -ForegroundColor Cyan
Write-Host "==========================================" -ForegroundColor Cyan
Write-Host "Backend Directory: $backendDir" -ForegroundColor Yellow
Write-Host "MDE4CPP_HOME: $mde4cppHome" -ForegroundColor Yellow
Write-Host "==========================================`n" -ForegroundColor Cyan

# Check if Node.js is available
$nodeVersion = node --version 2>$null
if (-not $nodeVersion) {
    Write-Host "ERROR: Node.js is not installed or not in PATH" -ForegroundColor Red
    exit 1
}
Write-Host "Node.js version: $nodeVersion" -ForegroundColor Green

# Check if dependencies are installed
if (-not (Test-Path "$backendDir\node_modules")) {
    Write-Host "Installing dependencies..." -ForegroundColor Cyan
    Set-Location $backendDir
    npm install
    if ($LASTEXITCODE -ne 0) {
        Write-Host "ERROR: Failed to install dependencies" -ForegroundColor Red
        exit 1
    }
}

# Set environment variables
$env:MDE4CPP_HOME = $mde4cppHome
$env:NODE_ENV = "development"
$env:PORT = "8000"

Write-Host "`nStarting backend server..." -ForegroundColor Cyan
Write-Host "Server will run in background. Press Ctrl+C to stop after tests complete." -ForegroundColor Yellow

# Start backend server in background
$serverProcess = Start-Process -FilePath "node" `
    -ArgumentList "$backendDir\src\index.js" `
    -WorkingDirectory $backendDir `
    -NoNewWindow `
    -PassThru `
    -RedirectStandardOutput "$backendDir\server-output.log" `
    -RedirectStandardError "$backendDir\server-error.log"

Write-Host "Backend server started (PID: $($serverProcess.Id))" -ForegroundColor Green

# Wait for server to start
Write-Host "Waiting for server to start..." -ForegroundColor Cyan
$maxWait = 30
$waited = 0
$serverReady = $false

while ($waited -lt $maxWait) {
    Start-Sleep -Seconds 2
    $waited += 2
    try {
        $response = Invoke-WebRequest -Uri "http://localhost:8000/api/v1/health" -TimeoutSec 2 -ErrorAction SilentlyContinue
        if ($response.StatusCode -eq 200) {
            $serverReady = $true
            break
        }
    } catch {
        # Server not ready yet
    }
    Write-Host "." -NoNewline -ForegroundColor Gray
}

Write-Host ""

if (-not $serverReady) {
    Write-Host "ERROR: Server did not start within $maxWait seconds" -ForegroundColor Red
    Write-Host "Check server logs:" -ForegroundColor Yellow
    Write-Host "  $backendDir\server-output.log" -ForegroundColor Gray
    Write-Host "  $backendDir\server-error.log" -ForegroundColor Gray
    if (Test-Path "$backendDir\server-error.log") {
        Write-Host "`nServer Error Log:" -ForegroundColor Red
        Get-Content "$backendDir\server-error.log" | ForEach-Object { Write-Host $_ -ForegroundColor Red }
    }
    Stop-Process -Id $serverProcess.Id -Force -ErrorAction SilentlyContinue
    exit 1
}

Write-Host "Server is ready!" -ForegroundColor Green

# Run tests
Write-Host "`n==========================================" -ForegroundColor Cyan
Write-Host "Running Comprehensive Tests" -ForegroundColor Cyan
Write-Host "==========================================`n" -ForegroundColor Cyan

Set-Location $backendDir
$env:API_URL = "http://localhost:8000/api/v1"
$env:MDE4CPP_HOME = $mde4cppHome

node scripts/test-all-model-types.js

$testExitCode = $LASTEXITCODE

Write-Host "`n==========================================" -ForegroundColor Cyan
Write-Host "Tests Completed" -ForegroundColor Cyan
Write-Host "==========================================" -ForegroundColor Cyan
Write-Host "Test Results: $backendDir\scripts\test-results-all-models.json" -ForegroundColor Yellow
Write-Host "Test Log: $backendDir\scripts\test-log-all-models.txt" -ForegroundColor Yellow
Write-Host "`nStopping backend server..." -ForegroundColor Cyan

# Stop server
Stop-Process -Id $serverProcess.Id -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 2

Write-Host "Backend server stopped." -ForegroundColor Green
Write-Host "`nExit Code: $testExitCode" -ForegroundColor $(if ($testExitCode -eq 0) { "Green" } else { "Red" })

exit $testExitCode
