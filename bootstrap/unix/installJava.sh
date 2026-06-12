#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "${SCRIPT_DIR}/../common.sh"

echo "[installJava] MDE4CPP_JAVA_VERSION=${MDE4CPP_JAVA_VERSION:-}"
if [[ -z "${MDE4CPP_JAVA_VERSION:-}" ]]; then
    echo "[installJava] ERROR: MDE4CPP_JAVA_VERSION is not set."
    exit 1
fi

JAVA_MAJOR="${MDE4CPP_JAVA_VERSION%%.*}"

if [ "$(uname -s)" = "Darwin" ]; then
    echo "[installJava] Checking for Java $JAVA_MAJOR on MacOS..."
    if /usr/libexec/java_home -F -v "$JAVA_MAJOR" &>/dev/null; then
        echo "[installJava] Java $JAVA_MAJOR is already installed."
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
        echo "[installJava] Creating symlink to /Library/Java/JavaVirtualMachines/ (requires sudo)"
        sudo ln -sfn "/opt/homebrew/opt/openjdk@$JAVA_MAJOR/libexec/openjdk.jdk" "/Library/Java/JavaVirtualMachines/openjdk-$JAVA_MAJOR.jdk" || true
        JAVA_HOME=$(/usr/libexec/java_home -v "$JAVA_MAJOR")
    fi
    echo "[installJava] Installed Java home: ${JAVA_HOME}"
    "${JAVA_HOME}/bin/java" -version
else
    # Linux logic
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

    require_sudo "$@"

    pkg_mgr=""
    install_cmd=""
    update_cmd=""
    install_pkg=""

    if command -v apt-get >/dev/null 2>&1; then
      pkg_mgr="apt"
      update_cmd="apt-get update"
      install_cmd="apt-get install -y"
      install_pkg="openjdk-${MDE4CPP_JAVA_VERSION}-jdk"
    elif command -v dnf >/dev/null 2>&1; then
      pkg_mgr="dnf"
      update_cmd="dnf makecache"
      install_cmd="dnf install -y"
      install_pkg="java-1.${MDE4CPP_JAVA_VERSION}.0-openjdk-devel"
    elif command -v yum >/dev/null 2>&1; then
      pkg_mgr="yum"
      update_cmd="yum makecache"
      install_cmd="yum install -y"
      install_pkg="java-1.${MDE4CPP_JAVA_VERSION}.0-openjdk-devel"
    elif command -v zypper >/dev/null 2>&1; then
      pkg_mgr="zypper"
      update_cmd="zypper refresh"
      install_cmd="zypper install -yn"
      install_pkg="java-${MDE4CPP_JAVA_VERSION}-openjdk-devel"
    elif command -v pacman >/dev/null 2>&1; then
      pkg_mgr="pacman"
      update_cmd="pacman -Sy --noconfirm"
      install_cmd="pacman -S --noconfirm"
      install_pkg="jdk-openjdk"
    else
      echo "[installJava] ERROR: No supported package manager found (apt, dnf, yum, zypper, pacman)."
      exit 1
    fi

    echo "[installJava] Using package manager: ${pkg_mgr}"
    ${update_cmd}
    ${install_cmd} ${install_pkg}

    JAVA_HOME=""
    for candidate in "/usr/lib/jvm/java-${MDE4CPP_JAVA_VERSION}-openjdk-amd64" "/usr/lib/jvm/java-${MDE4CPP_JAVA_VERSION}-openjdk" "/usr/lib/jvm/java-${MDE4CPP_JAVA_VERSION}-oracle"; do
      if [[ -d "${candidate}" ]]; then
        JAVA_HOME="${candidate}"
        break
      fi
    done

    if [[ -z "${JAVA_HOME}" ]] && command -v javac >/dev/null 2>&1; then
      JAVA_HOME="$(dirname "$(dirname "$(readlink -f "$(command -v javac)")")")"
    fi

    if [[ -z "${JAVA_HOME}" ]]; then
      echo "[installJava] ERROR: Cannot determine JAVA_HOME."
      exit 1
    fi

    if [[ ! -x "${JAVA_HOME}/bin/java" ]]; then
      echo "[installJava] ERROR: Cannot locate installed java binary."
      exit 1
    fi

    JAVA_PRIORITY=$((MDE4CPP_JAVA_VERSION * 10))
    for tool in java javac jar javadoc; do
      alt_path="${JAVA_HOME}/bin/${tool}"
      if [[ -x "${alt_path}" ]]; then
        if ! update-alternatives --list "${tool}" 2>/dev/null | grep -Fxq "${alt_path}"; then
          update-alternatives --install "/usr/bin/${tool}" "${tool}" "${alt_path}" "${JAVA_PRIORITY}"
        fi
        update-alternatives --set "${tool}" "${alt_path}"
      fi
    done

    java -version
fi
