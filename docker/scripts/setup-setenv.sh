#!/bin/bash
# Setup setenv file if it doesn't exist
# This script is used by Docker services to configure the setenv file
#
# To customize for your system, edit the configuration values below (lines 10-22)

# ============================================================================
# Configuration - Edit these values to customize for your system
# ============================================================================
# Path to MDE4CPP home folder in the container
MDE4CPP_HOME_VALUE="/home/mde4cpp"

# Path to Eclipse home folder in the container
MDE4CPP_ECLIPSE_HOME_VALUE="/home/mde4cpp/eclipse"

# Number of parallel make jobs (1 = single-threaded, 2+ = parallel)
# Lower values use less memory. Recommended: 1 for 8GB RAM, 2-3 for 16GB+ RAM
WORKER_COUNT=1

# Enable Gradle parallel execution (true/false)
# Set to false for low-memory systems (8GB RAM or less)
GRADLE_PARALLEL=true

# Create setenv from default if it doesn't exist
if [ ! -f setenv ]; then
    echo 'Creating setenv from setenv.default...'
    cp setenv.default setenv
fi

# Update MDE4CPP_HOME path
sed -i "s|export MDE4CPP_HOME=\$PWD|export MDE4CPP_HOME=${MDE4CPP_HOME_VALUE}|" setenv

# Update MDE4CPP_ECLIPSE_HOME path
sed -i "s|export MDE4CPP_ECLIPSE_HOME=~.*|export MDE4CPP_ECLIPSE_HOME=${MDE4CPP_ECLIPSE_HOME_VALUE}|" setenv

# Update WORKER count (handles any current value)
sed -i "s|export ORG_GRADLE_PROJECT_WORKER=[0-9]*|export ORG_GRADLE_PROJECT_WORKER=${WORKER_COUNT}|" setenv

# Update Gradle parallel execution based on configuration
if [ "$GRADLE_PARALLEL" = "false" ]; then
    sed -i 's|export GRADLE_OPTS=-Dorg.gradle.parallel=true|export GRADLE_OPTS=-Dorg.gradle.parallel=false|' setenv
else
    sed -i 's|export GRADLE_OPTS=-Dorg.gradle.parallel=false|export GRADLE_OPTS=-Dorg.gradle.parallel=true|' setenv
fi

# Remove gradlew commands that execute when sourcing (lines 88-91 in setenv.default)
sed -i '/^cd \.\/gradlePlugins$/,/^cd \$MDE4CPP_HOME$/d' setenv

# Remove bash command at end of file
sed -i '/^# bash$/d' setenv
sed -i '/^bash$/d' setenv

chmod +x setenv
echo '✓ setenv created and configured'
