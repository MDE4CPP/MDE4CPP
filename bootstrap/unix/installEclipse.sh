#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "${SCRIPT_DIR}/common.sh"

print_header "installEclipse" "Running Eclipse installation..."

echo "${C_PURPLE}[installEclipse]${C_ORANGE} MDE4CPP_ECLIPSE_VERSION=${MDE4CPP_ECLIPSE_VERSION:-}${C_RESET}"
echo "${C_PURPLE}[installEclipse]${C_ORANGE} MDE4CPP_ECLIPSE_MILESTONE=${MDE4CPP_ECLIPSE_MILESTONE:-}${C_RESET}"
echo "${C_PURPLE}[installEclipse]${C_ORANGE} MDE4CPP_ECLIPSE_ACCELEO_VERSION=${MDE4CPP_ECLIPSE_ACCELEO_VERSION:-}${C_RESET}"
echo "${C_PURPLE}[installEclipse]${C_ORANGE} MDE4CPP_ECLIPSE_PAPYRUS_VERSION=${MDE4CPP_ECLIPSE_PAPYRUS_VERSION:-}${C_RESET}"
echo "${C_PURPLE}[installEclipse]${C_ORANGE} MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION=${MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION:-}${C_RESET}"
echo "${C_PURPLE}[installEclipse]${C_ORANGE} MDE4CPP_ECLIPSE_SIRIUS_VERSION=${MDE4CPP_ECLIPSE_SIRIUS_VERSION:-}${C_RESET}"
echo "${C_PURPLE}[installEclipse]${C_ORANGE} MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION=${MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION:-}${C_RESET}"

if [[ -z "${MDE4CPP_HOME:-}" ]]; then
  echo "${C_PURPLE}[installEclipse]${C_ERROR} ERROR: MDE4CPP_HOME is not set.${C_RESET}"
  exit 1
fi
if [[ -z "${MDE4CPP_ECLIPSE_VERSION:-}" ]]; then
  echo "${C_PURPLE}[installEclipse]${C_ERROR} ERROR: MDE4CPP_ECLIPSE_VERSION is not set.${C_RESET}"
  exit 1
fi
if [[ -z "${MDE4CPP_ECLIPSE_PAPYRUS_VERSION:-}" ]]; then
  echo "${C_PURPLE}[installEclipse]${C_ERROR} ERROR: MDE4CPP_ECLIPSE_PAPYRUS_VERSION is not set.${C_RESET}"
  exit 1
fi
if [[ -z "${MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION:-}" ]]; then
  echo "${C_PURPLE}[installEclipse]${C_ERROR} ERROR: MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION is not set.${C_RESET}"
  exit 1
fi

MDE4CPP_PARENT="$(cd "${MDE4CPP_HOME}/.." && pwd)"
if [[ -n "${MDE4CPP_ECLIPSE_LOCATION:-}" ]]; then
  TARGET_DIR="${MDE4CPP_ECLIPSE_LOCATION}"
else
  TARGET_DIR="${MDE4CPP_ECLIPSE_TARGET_DIR:-${MDE4CPP_PARENT}/eclipse}"
fi
TMP_DIR="$(mktemp -d)"

ACCELEO_REPOSITORY_URL="https://download.eclipse.org/acceleo/updates/releases/${MDE4CPP_ECLIPSE_ACCELEO_VERSION//[[:space:]]/}"
SIRIUS_REPOSITORY_URL="https://download.eclipse.org/sirius/updates/releases/${MDE4CPP_ECLIPSE_SIRIUS_VERSION//[[:space:]]/}/${MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION//[[:space:]]/}"
PAPYRUS_REPOSITORY_URL="https://download.eclipse.org/modeling/mdt/papyrus/updates/releases/${MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION//[[:space:]]/}"
PAPYRUS_DEPENDENCIES_URL="https://download.eclipse.org/releases/${MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION//[[:space:]]/}"
CDT_REPOSITORY_URL="https://download.eclipse.org/releases/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}"

cleanup() {
  rm -rf "${TMP_DIR}"
}
trap cleanup EXIT

echo "MDE4CPP_HOME=${MDE4CPP_HOME}"
echo "Install location=${TARGET_DIR}"

SKIP_DOWNLOAD=0
ECLIPSE_BIN=""


if [ "$(uname -s)" = "Darwin" ]; then
    ARCH_SUFFIX=$(get_arch)
    ECLIPSE_ARCHIVE_URL="https://ftp.halifax.rwth-aachen.de/eclipse/technology/epp/downloads/release/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}/${MDE4CPP_ECLIPSE_MILESTONE//[[:space:]]/}/eclipse-modeling-${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}-${MDE4CPP_ECLIPSE_MILESTONE//[[:space:]]/}-macosx-cocoa-${ARCH_SUFFIX}.tar.gz"
    ARCHIVE_PATH="${TMP_DIR}/eclipse-modeling.tar.gz"
    ECLIPSE_BIN="${TARGET_DIR}/Eclipse.app/Contents/MacOS/eclipse"
    P2_DESTINATION="${TARGET_DIR}/Eclipse.app/Contents/Eclipse"
else
    # Linux
    ECLIPSE_ARCH=$(get_arch)
    ECLIPSE_ARCHIVE_URL="https://ftp.halifax.rwth-aachen.de/eclipse/technology/epp/downloads/release/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}/${MDE4CPP_ECLIPSE_MILESTONE//[[:space:]]/}/eclipse-modeling-${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}-${MDE4CPP_ECLIPSE_MILESTONE//[[:space:]]/}-linux-gtk-${ECLIPSE_ARCH}.tar.gz"
    ARCHIVE_PATH="${TMP_DIR}/eclipse-modeling.tar.gz"
    ECLIPSE_BIN="${TARGET_DIR}/eclipse"
    P2_DESTINATION="${TARGET_DIR}"
fi

if [[ -x "${ECLIPSE_BIN}" ]]; then
  echo "${C_PURPLE}[installEclipse]${C_SUCCESS} Existing Eclipse installation found at ${TARGET_DIR}.${C_RESET}"
  "${ECLIPSE_BIN}" -nosplash -application org.eclipse.equinox.p2.director -listInstalledRoots > "${TMP_DIR}/installed.txt" 2>&1 || true
  
  acceleo_version=$(grep '^org\.eclipse\.acceleo\.feature\.group/' "${TMP_DIR}/installed.txt" | awk -F'/' '{print $2}' | head -n1 || true)
  sirius_version=$(grep '^org\.eclipse\.sirius\.specifier\.feature\.group/' "${TMP_DIR}/installed.txt" | awk -F'/' '{print $2}' | head -n1 || true)
  cdt_version=$(grep '^org\.eclipse\.cdt\.feature\.group/' "${TMP_DIR}/installed.txt" | awk -F'/' '{print $2}' | head -n1 || true)
  papyrus_version=$(grep '^org\.eclipse\.papyrus\.sdk\.feature\.feature\.group/' "${TMP_DIR}/installed.txt" | awk -F'/' '{print $2}' | head -n1 || true)
  
  echo "${C_PURPLE}[installEclipse]${C_SUCCESS} Found existing Eclipse plugins:${C_RESET}"
  for plugin in $(cat "${SCRIPT_DIR}/../eclipse_plugins.txt"); do
      version=$(grep "^${plugin}/" "${TMP_DIR}/installed.txt" | awk -F'/' '{print $2}' | head -n1 || true)
      if [ -n "$version" ]; then
          echo "${C_PURPLE}[installEclipse]${C_INFO} ${plugin}: ${version}${C_RESET}"
      else
          echo "${C_PURPLE}[installEclipse]${C_INFO} ${plugin}: ${C_ERROR}NOT FOUND${C_RESET}"
      fi
  done
  
  if [[ "${acceleo_version}" == "${MDE4CPP_ECLIPSE_ACCELEO_VERSION//[[:space:]]/}"* && "${sirius_version}" == "${MDE4CPP_ECLIPSE_SIRIUS_VERSION//[[:space:]]/}"* && "${papyrus_version}" == "${MDE4CPP_ECLIPSE_PAPYRUS_VERSION//[[:space:]]/}"* && -n "${cdt_version}" ]]; then
    echo "${C_PURPLE}[installEclipse]${C_SUCCESS} Requested Eclipse plugins already installed, skipping installation.${C_RESET}"
    exit 0
  else
    echo "${C_PURPLE}[installEclipse]${C_INFO} Eclipse plugin versions differ or are missing; updating installation.${C_RESET}"
    SKIP_DOWNLOAD=1
  fi
fi

if [[ "${SKIP_DOWNLOAD}" -eq 0 ]]; then
  echo "Downloading ${ECLIPSE_ARCHIVE_URL}"
  download_file "${ECLIPSE_ARCHIVE_URL}" "${ARCHIVE_PATH}"

  rm -rf "${TARGET_DIR}"
  if [ "$(uname -s)" = "Darwin" ]; then
      mkdir -p "${TARGET_DIR}"
      tar -xzf "${ARCHIVE_PATH}" -C "${TARGET_DIR}"
  else
      TARGET_PARENT="$(dirname "${TARGET_DIR}")"
      mkdir -p "${TARGET_PARENT}"
      tar -xzf "${ARCHIVE_PATH}" -C "${TARGET_PARENT}"
      if [ "$(basename "${TARGET_DIR}")" != "eclipse" ]; then
          mv "${TARGET_PARENT}/eclipse" "${TARGET_DIR}"
      fi
  fi
fi

if [[ ! -x "${ECLIPSE_BIN}" ]]; then
  echo "${C_PURPLE}[installEclipse]${C_ERROR} ERROR: Eclipse binary not found at ${ECLIPSE_BIN}${C_RESET}"
  exit 1
fi



IU_ARGS=()
for plugin in $(cat "${SCRIPT_DIR}/../eclipse_plugins.txt"); do
  IU_ARGS+=("-installIU" "${plugin}")
done

echo "${C_PURPLE}[installEclipse]${C_INFO} Installing Eclipse plugins (Acceleo, Sirius, CDT, Papyrus)...${C_RESET}"
if ! "${ECLIPSE_BIN}" \
  -nosplash \
  -application org.eclipse.equinox.p2.director \
  -repository "https://download.eclipse.org/releases/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/},${ACCELEO_REPOSITORY_URL},${SIRIUS_REPOSITORY_URL},${PAPYRUS_REPOSITORY_URL},${PAPYRUS_DEPENDENCIES_URL},${CDT_REPOSITORY_URL}" \
  "${IU_ARGS[@]}" \
  -destination "${P2_DESTINATION}" \
  -profileProperties org.eclipse.update.install.features=true 2> "${TMP_DIR}/p2_stderr.log" | while IFS= read -r line; do
    echo "${C_PURPLE}[installEclipse]${C_INFO} ${line}${C_RESET}"
  done; then
  
  echo "${C_PURPLE}[installEclipse]${C_ERROR} ERROR: Eclipse plugin installation failed.${C_RESET}"
  cat "${TMP_DIR}/p2_stderr.log"
  exit 1
fi

echo "${C_PURPLE}[installEclipse]${C_SUCCESS} Eclipse installation finished: ${TARGET_DIR}${C_RESET}"
