#!/usr/bin/env bash
# Setup setenv file for Docker environments
# This script delegates to the primary setenv generator to configure the environment.
#
# To customize for your system, edit the configuration values below

# ============================================================================
# Configuration
# ============================================================================

# Number of parallel make jobs (1 = single-threaded, 2+ = parallel)
# Lower values use less memory. Recommended: 1 for 8GB RAM, 2-3 for 16GB+ RAM
export WORKER_COUNT=3

# Enable Gradle parallel execution (true/false)
# Set to false for low-memory systems (8GB RAM or less)
export GRADLE_PARALLEL=true

# Path configurations for Docker
export PROJECT_DIR="/home/mde4cpp"
export ECLIPSE_DIR="/home/eclipse/ide"
export SETENV_FILE="/home/mde4cpp/setenv"

echo "Delegating setenv generation to bootstrap/unix/generate_setenv.sh..."

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
bash "$SCRIPT_DIR/../../bootstrap/unix/generate_setenv.sh"

echo '✓ setenv created and configured for Docker'
