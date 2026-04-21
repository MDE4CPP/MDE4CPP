#!/bin/bash
# Sequential build script for MDE4CPP
# This script runs generateAll, compileAll, and buildOCLAll tasks sequentially
# to ensure proper build order and avoid race conditions
#
# Prerequisites:
# - Eclipse must be installed (via install-eclipse.sh)
# - setenv file must be sourced before calling this script (done in docker-compose.yml)
#
# Usage: ./docker/scripts/build-full.sh (run from MDE4CPP root directory)

set -e  # Exit on any error

# Change to project root if not already there
cd /home/mde4cpp

# Use hardcoded gradlew path
GRADLEW="./application/tools/gradlew"

if [ ! -f "$GRADLEW" ]; then
    echo "Error: gradlew not found at $GRADLEW"
    echo "Please ensure you're running this script from the MDE4CPP root directory."
    exit 1
fi

# Publish gradle plugins if needed (this is normally done in setenv)
# Do this after GRADLEW is defined so we can use it
if [ -d "gradlePlugins" ]; then
    echo "Publishing MDE4CPP Gradle plugins..."
    (./application/tools/gradlew publishMDE4CPPPluginsToMavenLocal >/dev/null 2>&1 || true)
fi

echo "=========================================="
echo "MDE4CPP Sequential Build Script"
echo "=========================================="
echo ""

# Clean CMake cache files before building
./docker/scripts/clean-cmake.sh

# Step 1: Generate all models
echo "Step 1/3: Running generateAll..."
echo "----------------------------------------"
if ! "$GRADLEW" generateAll; then
    echo ""
    echo "ERROR: generateAll failed!"
    exit 1
fi
echo "✓ generateAll completed successfully"
echo ""

# Step 2: Compile all generated code
echo "Step 2/3: Running compileAll..."
echo "----------------------------------------"
if ! "$GRADLEW" compileAll; then
    echo ""
    echo "ERROR: compileAll failed!"
    exit 1
fi
echo "✓ compileAll completed successfully"
echo ""

# Step 3: Build OCL components
echo "Step 3/3: Running src:buildOCLAll..."
echo "----------------------------------------"
if ! "$GRADLEW" src:buildOCLAll; then
    echo ""
    echo "ERROR: src:buildOCLAll failed!"
    exit 1
fi
echo "✓ src:buildOCLAll completed successfully"
echo ""

echo "=========================================="
echo "BUILD SUCCESSFUL - All tasks completed!"
echo "=========================================="
