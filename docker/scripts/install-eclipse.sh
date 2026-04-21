#!/bin/bash
# Install Eclipse Modeling Tools and required plugins
# This script is used by Docker services to install Eclipse at runtime

set -e

if [ ! -f /home/mde4cpp/eclipse/eclipse ]; then
    echo 'Installing Eclipse Modeling Tools...'
    mkdir -p /home/mde4cpp/eclipse
    cd /tmp
    
    ECLIPSE_URL_2025='https://www.eclipse.org/downloads/download.php?file=/technology/epp/downloads/release/2025-06/R/eclipse-modeling-2025-06-R-linux-gtk-x86_64.tar.gz&r=1'
    ECLIPSE_URL_2024='https://www.eclipse.org/downloads/download.php?file=/technology/epp/downloads/release/2024-06/R/eclipse-modeling-2024-06-R-linux-gtk-x86_64.tar.gz&r=1'
    
    if wget -q --spider "$ECLIPSE_URL_2025" 2>/dev/null; then
        echo 'Downloading Eclipse 2025-06...'
        wget -O eclipse.tar.gz "$ECLIPSE_URL_2025"
    else
        echo 'Eclipse 2025-06 not available, trying 2024-06...'
        wget -O eclipse.tar.gz "$ECLIPSE_URL_2024"
    fi
    
    tar -xzf eclipse.tar.gz -C /home/mde4cpp/eclipse --strip-components=1
    rm -f eclipse.tar.gz
    chmod +x /home/mde4cpp/eclipse/eclipse
    
    echo 'Installing Eclipse plugins...'
    /home/mde4cpp/eclipse/eclipse -nosplash -application org.eclipse.equinox.p2.director \
        -repository 'https://download.eclipse.org/releases/2025-06/,https://download.eclipse.org/releases/2024-06/' \
        -installIU org.eclipse.acceleo.feature.group \
        -installIU org.eclipse.emf.sdk.feature.group \
        -installIU org.eclipse.uml2.sdk.feature.group \
        -installIU org.eclipse.ocl.all.sdk.feature.group \
        -destination /home/mde4cpp/eclipse \
        -profileProperties org.eclipse.update.install.features=true \
        -bundlepool /home/mde4cpp/eclipse \
        -p2.os linux -p2.ws gtk -p2.arch x86_64
    
    echo '✓ Eclipse installed'
else
    echo '✓ Eclipse already installed'
fi
