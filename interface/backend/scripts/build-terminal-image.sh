#!/bin/bash
# Build script for MDE4CPP Terminal Docker image
# This creates a secure container image for terminal execution

set -e

echo "Building MDE4CPP Terminal Docker image..."

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BACKEND_DIR="$(dirname "$SCRIPT_DIR")"
DOCKER_DIR="$BACKEND_DIR/docker"
DOCKERFILE="$DOCKER_DIR/Dockerfile.terminal"

if [ ! -f "$DOCKERFILE" ]; then
    echo "Error: Dockerfile not found: $DOCKERFILE"
    exit 1
fi

# Build the image
echo ""
echo "Building Docker image: mde4cpp-terminal:latest"
docker build -f "$DOCKERFILE" -t mde4cpp-terminal:latest "$DOCKER_DIR"

if [ $? -eq 0 ]; then
    echo ""
    echo "✓ Terminal Docker image built successfully!"
    echo ""
    echo "Image: mde4cpp-terminal:latest"
    echo "You can now start the backend server with secure terminal enabled."
else
    echo "Error: Failed to build Docker image"
    exit 1
fi
