#!/usr/bin/env bash
set -euo pipefail

# Step 1: Find repo root and read Java version from versions.properties
echo "[installJava] Reading configuration from versions.properties..."
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../../.." && pwd)"
VERSIONS_FILE="${REPO_ROOT}/versions.properties"

if [[ ! -f "${VERSIONS_FILE}" ]]; then
    echo "[installJava] ERROR: versions.properties not found at ${VERSIONS_FILE}"
    exit 1
fi

# Read MDE4CPP_JAVA_VERSION from properties file
MDE4CPP_JAVA_VERSION=""
if [[ -f "${VERSIONS_FILE}" ]]; then
    MDE4CPP_JAVA_VERSION=$(grep -i "^MDE4CPP_JAVA_VERSION=" "${VERSIONS_FILE}" | cut -d'=' -f2 | tr -d ' ' | tr -d '\r')
fi

echo "[installJava] MDE4CPP_JAVA_VERSION=${MDE4CPP_JAVA_VERSION}"
if [[ -z "${MDE4CPP_JAVA_VERSION}" ]]; then
    echo "[installJava] ERROR: MDE4CPP_JAVA_VERSION not found in ${VERSIONS_FILE}"
    exit 1
fi

# Step 1: Check if the required Java version is already installed (before requesting elevation).
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

# Step 2: Request root privileges only when installation is actually required.
if [[ "${1:-}" != "--elevated" ]] && [[ "${EUID}" -ne 0 ]]; then
  echo "[installJava] Root privileges are required for installation. Requesting sudo elevation..."
  exec sudo -E bash "$0" --elevated
fi

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

if [[ -z "${JAVA_HOME}" && command -v javac >/dev/null 2>&1 ]]; then
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

if [[ -z "${JAVA_HOME}" && command -v javac >/dev/null 2>&1 ]]; then
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
