#!/bin/bash
# Clean CMake cache files and build artifacts
# Preserves application/lib and application/bin directories
# This script is used by Docker services to clean build artifacts

set +e  # Temporarily disable exit on error for cleanup operations

echo "Cleaning CMake cache files and build artifacts..."
echo "----------------------------------------"

cleaned_count=0

# Find and remove all .cmake directories (excluding application/lib and application/bin)
while IFS= read -r -d '' dir; do
    # Skip if inside application/lib or application/bin
    if [[ "$dir" != *"/application/lib"* ]] && [[ "$dir" != *"/application/bin"* ]]; then
        echo "  Removing: $dir"
        rm -rf "$dir" 2>/dev/null || true
        cleaned_count=$((cleaned_count + 1))
    fi
done < <(find . -type d -name ".cmake" -print0 2>/dev/null || true)

# Find and remove all CMakeCache.txt files
while IFS= read -r -d '' file; do
    if [[ "$file" != *"/application/lib"* ]] && [[ "$file" != *"/application/bin"* ]]; then
        echo "  Removing: $file"
        rm -f "$file" 2>/dev/null || true
        cleaned_count=$((cleaned_count + 1))
    fi
done < <(find . -type f -name "CMakeCache.txt" -print0 2>/dev/null || true)

# Find and remove all CMakeFiles directories
while IFS= read -r -d '' dir; do
    if [[ "$dir" != *"/application/lib"* ]] && [[ "$dir" != *"/application/bin"* ]]; then
        echo "  Removing: $dir"
        rm -rf "$dir" 2>/dev/null || true
        cleaned_count=$((cleaned_count + 1))
    fi
done < <(find . -type d -name "CMakeFiles" -print0 2>/dev/null || true)

# Find and remove all src_gen directories (for fresh code generation)
while IFS= read -r -d '' dir; do
    if [[ "$dir" != *"/application/lib"* ]] && [[ "$dir" != *"/application/bin"* ]]; then
        echo "  Removing: $dir"
        rm -rf "$dir" 2>/dev/null || true
        cleaned_count=$((cleaned_count + 1))
    fi
done < <(find . -type d -name "src_gen" -print0 2>/dev/null || true)

set -e  # Re-enable exit on error

if [ $cleaned_count -eq 0 ]; then
    echo "  No cache files found to clean."
else
    echo "  Cleaned $cleaned_count cache directories/files."
fi
echo ""
