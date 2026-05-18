#!/usr/bin/env bash
set -euo pipefail

echo "[installJava] MDE4CPP_JAVA_VERSION=${MDE4CPP_JAVA_VERSION:-}"
if [[ -z "${MDE4CPP_JAVA_VERSION:-}" ]]; then
  echo "[installJava] ERROR: MDE4CPP_JAVA_VERSION is not set."
  exit 1
fi

if command -v java >/dev/null 2>&1; then
  INSTALLED_MAJOR="$(java -version 2>&1 | awk -F[\".] '/version/ {print $2; exit}')"
  if [[ "${INSTALLED_MAJOR}" == "${MDE4CPP_JAVA_VERSION}" ]]; then
    echo "[installJava] Java ${MDE4CPP_JAVA_VERSION} is already installed. Skipping."
    exit 0
  fi
  echo "[installJava] Found Java ${INSTALLED_MAJOR}. Installing Java ${MDE4CPP_JAVA_VERSION}."
else
  echo "[installJava] Java is not installed. Installing Java ${MDE4CPP_JAVA_VERSION}."
fi

if ! command -v brew >/dev/null 2>&1; then
  echo "[installJava] ERROR: Homebrew is required on macOS. Install it from https://brew.sh/"
  exit 1
fi

JAVA_FORMULA="openjdk@${MDE4CPP_JAVA_VERSION}"
echo "[installJava] Installing ${JAVA_FORMULA} via Homebrew"
brew update
brew install "${JAVA_FORMULA}"

JAVA_PREFIX="$(brew --prefix "${JAVA_FORMULA}" 2>/dev/null || true)"
if [[ -n "${JAVA_PREFIX}" && -d "${JAVA_PREFIX}/libexec/openjdk.jdk/Contents/Home" ]]; then
  JAVA_HOME="${JAVA_PREFIX}/libexec/openjdk.jdk/Contents/Home"
elif [[ -d "/Library/Java/JavaVirtualMachines/openjdk-${MDE4CPP_JAVA_VERSION}.jdk/Contents/Home" ]]; then
  JAVA_HOME="/Library/Java/JavaVirtualMachines/openjdk-${MDE4CPP_JAVA_VERSION}.jdk/Contents/Home"
elif command -v javac >/dev/null 2>&1; then
  JAVA_HOME="$(cd "$(dirname "$(dirname "$(command -v javac)")")" && pwd)"
fi

if [[ -z "${JAVA_HOME:-}" || ! -x "${JAVA_HOME}/bin/java" ]]; then
  echo "[installJava] ERROR: Cannot locate installed java binary."
  exit 1
fi

echo "[installJava] Installed Java home: ${JAVA_HOME}"
"${JAVA_HOME}/bin/java" -version
