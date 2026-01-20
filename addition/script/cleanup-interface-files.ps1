# MDE4CPP Interface Development Cleanup Script
# This script removes unnecessary files created during interface development
# Usage: .\cleanup-interface-files.ps1

param(
    [Parameter(Mandatory=$false)]
    [switch]$DryRun = $false
)

$ErrorActionPreference = "Continue"

# Get script directory and MDE4CPP root
$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$mde4cppRoot = Split-Path -Parent (Split-Path -Parent $scriptDir)

Write-Host "MDE4CPP Interface Development Cleanup Script" -ForegroundColor Cyan
Write-Host "=============================================" -ForegroundColor Cyan
Write-Host "MDE4CPP Root: $mde4cppRoot" -ForegroundColor Gray
if ($DryRun) {
    Write-Host "DRY RUN MODE - No files will be deleted" -ForegroundColor Yellow
}
Write-Host ""

$filesRemoved = 0
$dirsRemoved = 0

# Function to remove file or directory
function Remove-Item-Safe {
    param(
        [string]$Path,
        [string]$Description
    )
    
    if (Test-Path $Path) {
        if ($DryRun) {
            Write-Host "[DRY RUN] Would remove: $Description" -ForegroundColor Yellow
            Write-Host "  Path: $Path" -ForegroundColor Gray
        } else {
            try {
                if (Test-Path $Path -PathType Container) {
                    Remove-Item $Path -Recurse -Force -ErrorAction SilentlyContinue
                    Write-Host "[REMOVED] $Description" -ForegroundColor Green
                    $script:dirsRemoved++
                } else {
                    Remove-Item $Path -Force -ErrorAction SilentlyContinue
                    Write-Host "[REMOVED] $Description" -ForegroundColor Green
                    $script:filesRemoved++
                }
            } catch {
                Write-Host "[ERROR] Failed to remove: $Description" -ForegroundColor Red
                Write-Host "  Error: $_" -ForegroundColor Red
            }
        }
    }
}

# 1. Remove test build ID files from interface/backend
Write-Host "Step 1: Removing test build ID files..." -ForegroundColor Cyan
$backendDir = Join-Path $mde4cppRoot "interface\backend"
if (Test-Path $backendDir) {
    Get-ChildItem -Path $backendDir -Filter "*_build_id.txt" -File | ForEach-Object {
        Remove-Item-Safe $_.FullName "Test build ID file: $($_.Name)"
    }
}

# 2. Remove test result JSON files from interface/backend/scripts
Write-Host "`nStep 2: Removing test result JSON files from interface/backend/scripts..." -ForegroundColor Cyan
$scriptsDir = Join-Path $backendDir "scripts"
if (Test-Path $scriptsDir) {
    Get-ChildItem -Path $scriptsDir -Filter "*test-results*.json" -File | ForEach-Object {
        Remove-Item-Safe $_.FullName "Test result file: $($_.Name)"
    }
}

# 3. Remove test result JSON files from addition/script
Write-Host "`nStep 3: Removing test result JSON files from addition/script..." -ForegroundColor Cyan
$additionScriptDir = Join-Path $mde4cppRoot "addition\script"
if (Test-Path $additionScriptDir) {
    Get-ChildItem -Path $additionScriptDir -Filter "*test-results*.json" -File | ForEach-Object {
        Remove-Item-Safe $_.FullName "Test result file: $($_.Name)"
    }
}

# 4. Remove temporary test workspace directories
Write-Host "`nStep 4: Removing temporary test workspace directories..." -ForegroundColor Cyan
Get-ChildItem -Path $mde4cppRoot -Directory -Filter "test_*" -ErrorAction SilentlyContinue | ForEach-Object {
    Remove-Item-Safe $_.FullName "Test workspace: $($_.Name)"
}

# 5. Remove test_manual_* directories
Write-Host "`nStep 5: Removing test_manual_* directories..." -ForegroundColor Cyan
Get-ChildItem -Path $mde4cppRoot -Directory -Filter "test_manual_*" -ErrorAction SilentlyContinue | ForEach-Object {
    Remove-Item-Safe $_.FullName "Manual test directory: $($_.Name)"
}

# 6. Remove userProjects directory
Write-Host "`nStep 6: Removing userProjects directory..." -ForegroundColor Cyan
$userProjectsDir = Join-Path $mde4cppRoot "userProjects"
Remove-Item-Safe $userProjectsDir "User projects directory"

# 7. Remove workspace file
Write-Host "`nStep 7: Removing workspace file..." -ForegroundColor Cyan
$workspaceFile = Join-Path $mde4cppRoot "test2.code-workspace"
Remove-Item-Safe $workspaceFile "Workspace file: test2.code-workspace"

# Summary
Write-Host "`n=============================================" -ForegroundColor Cyan
if ($DryRun) {
    Write-Host "DRY RUN COMPLETE" -ForegroundColor Yellow
    Write-Host "Run without -DryRun to actually remove files" -ForegroundColor Yellow
} else {
    Write-Host "CLEANUP COMPLETE" -ForegroundColor Green
    Write-Host "Files removed: $filesRemoved" -ForegroundColor Green
    Write-Host "Directories removed: $dirsRemoved" -ForegroundColor Green
}
Write-Host "=============================================" -ForegroundColor Cyan
