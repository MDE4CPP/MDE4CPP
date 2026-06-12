#!/usr/bin/env bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Auto-load the environment variables if available
if [ -f "$SCRIPT_DIR/setenv.sh" ]; then
    source "$SCRIPT_DIR/setenv.sh" > /dev/null 2>&1
fi

# Delegate to the actual Gradle wrapper located in application/tools
exec "$SCRIPT_DIR/application/tools/gradlew" "$@"
