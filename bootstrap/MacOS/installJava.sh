#!/usr/bin/env bash
set -euo pipefail

if [[ -z "${MDE4CPP_JAVA_VERSION:-}" ]]; then
  echo "[installJava] ERROR: MDE4CPP_JAVA_VERSION is not set."
  exit 1
fi

JAVA_MAJOR="${MDE4CPP_JAVA_VERSION%%.*}"
echo "[installJava] Checking for Java $JAVA_MAJOR..."

# 1. Use macOS native tool to check for the required major version
if /usr/libexec/java_home -F -v "$JAVA_MAJOR" &>/dev/null; then
    echo "[installJava] Java $JAVA_MAJOR is already installed."
    # Get the exact path of the installed version
    JAVA_HOME=$(/usr/libexec/java_home -v "$JAVA_MAJOR")
else
    echo "[installJava] Java $JAVA_MAJOR is not installed."
    
    if ! command -v brew >/dev/null 2>&1; then
      echo "[installJava] ERROR: Homebrew is required on macOS. Install it from https://brew.sh/"
      exit 1
    fi

    echo "[installJava] Installing openjdk@$JAVA_MAJOR via Homebrew..."
    brew update
    brew install "openjdk@$JAVA_MAJOR"
    
    # 2. Crucial Step: Symlink it so the macOS system java wrapper and /usr/libexec/java_home can find it
    echo "[installJava] Creating symlink to /Library/Java/JavaVirtualMachines/ (requires sudo)"
    sudo ln -sfn "/opt/homebrew/opt/openjdk@$JAVA_MAJOR/libexec/openjdk.jdk" "/Library/Java/JavaVirtualMachines/openjdk-$JAVA_MAJOR.jdk" || true

    # Get the newly installed path
    JAVA_HOME=$(/usr/libexec/java_home -v "$JAVA_MAJOR")
fi

echo "[installJava] Installed Java home: ${JAVA_HOME}"
"${JAVA_HOME}/bin/java" -version
