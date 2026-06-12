#!/usr/bin/env bash
# Linux Bootstrap script for MDE4CPP

set -e

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
source "$DIR/common.sh"

PROPS_FILE="$DIR/../versions.properties"
load_properties "$PROPS_FILE"

echo "Linux bootstrap script is currently a placeholder."
echo "Required versions from versions.properties:"
echo "Java: $MDE4CPP_JAVA_VERSION"
echo "GCC: $MDE4CPP_COMPILER_VERSION"
echo "CMake: $MDE4CPP_CMAKE_VERSION"
echo "Eclipse: $MDE4CPP_ECLIPSE_VERSION"
