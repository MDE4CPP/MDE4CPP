#!/bin/bash
# Install Eclipse Modeling Tools and required plugins
# This script reuses the native bootstrap script

set -euo pipefail

echo 'Setting up environment for Eclipse installation...'

# Export required variables for the bootstrap script
export MDE4CPP_HOME="/home/mde4cpp"
export MDE4CPP_ECLIPSE_TARGET_DIR="/home/eclipse/ide"

# Read versions from default and custom properties and export them
set -a
if [ -f "${MDE4CPP_HOME}/MDE4CPP_default.properties" ]; then
    source "${MDE4CPP_HOME}/MDE4CPP_default.properties"
fi
if [ -f "${MDE4CPP_HOME}/MDE4CPP_custom.properties" ]; then
    source "${MDE4CPP_HOME}/MDE4CPP_custom.properties"
fi
set +a

# Execute the native bootstrap script
bash "${MDE4CPP_HOME}/bootstrap/unix/installEclipse.sh"

echo '✓ Eclipse installation complete'
