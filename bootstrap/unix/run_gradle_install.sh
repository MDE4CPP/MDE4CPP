#!/usr/bin/env bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

echo "==========================================================="
echo "Running Gradle install to download third-party dependencies..."
echo "==========================================================="

source "$REPO_ROOT/setenv.sh"
cd "$REPO_ROOT"

GRADLE_WRAPPER="$REPO_ROOT/application/tools/gradlew"
if [[ -x "$GRADLE_WRAPPER" ]]; then
    set +e
    "$GRADLE_WRAPPER" install --no-daemon
    GRADLE_EXIT=$?
    set -e
    if [[ $GRADLE_EXIT -ne 0 ]]; then
        echo "ERROR: Gradle install task failed (exit $GRADLE_EXIT)"
        exit $GRADLE_EXIT
    fi
    echo "Gradle install completed successfully."
else
    echo "WARNING: Gradle wrapper not found or not executable at $GRADLE_WRAPPER, skipping Gradle install."
fi
