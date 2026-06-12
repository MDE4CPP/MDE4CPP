#!/bin/bash
# Clean CMake cache files and build artifacts
# Preserves application/lib and application/bin directories
# This script is used by Docker services to clean build artifacts

set +e  # Temporarily disable exit on error for cleanup operations

echo "Cleaning CMake cache files and build artifacts..."
echo "----------------------------------------"

# Find and remove matching files/directories in a single pass,
# explicitly skipping the application/lib and application/bin directories
# We print '1' for each match to easily count them
cleaned_count=$(find . \
    -type d \( -path "*/application/lib" -o -path "*/application/bin" \) -prune \
    -o \
    \( -name ".cmake" -o -name "CMakeCache.txt" -o -name "CMakeFiles" -o -name "src_gen" \) \
    -exec rm -rf {} + -exec echo 1 \; | wc -l)

# Strip whitespace from word count
cleaned_count=$((cleaned_count))

set -e  # Re-enable exit on error

if [ "$cleaned_count" -eq 0 ]; then
    echo "  No cache files found to clean."
else
    echo "  Cleaned $cleaned_count cache directories/files."
fi
echo ""
