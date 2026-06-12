#!/usr/bin/env bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "$SCRIPT_DIR/common.sh"

REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

print_header "run_gradle_install" "Running Gradle install to download third-party dependencies..."

source "$REPO_ROOT/setenv.sh"
cd "$REPO_ROOT"

GRADLE_WRAPPER="$REPO_ROOT/application/tools/gradlew"
if [[ -x "$GRADLE_WRAPPER" ]]; then
    set +e
    "$GRADLE_WRAPPER" install --no-daemon
    GRADLE_EXIT=$?
    set -e
    if [[ $GRADLE_EXIT -ne 0 ]]; then
        echo "${C_ERROR}ERROR: Gradle install task failed (exit $GRADLE_EXIT)${C_RESET}"
        exit $GRADLE_EXIT
    fi
    echo "${C_SUCCESS}Gradle install completed successfully.${C_RESET}"
else
    echo "WARNING: Gradle wrapper not found or not executable at $GRADLE_WRAPPER, skipping Gradle install."
fi
