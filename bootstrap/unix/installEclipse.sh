#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "${SCRIPT_DIR}/common.sh"

echo "${C_PURPLE}[installEclipse]${C_INFO} MDE4CPP_ECLIPSE_VERSION=${MDE4CPP_ECLIPSE_VERSION:-}${C_RESET}"
echo "${C_PURPLE}[installEclipse]${C_INFO} MDE4CPP_ECLIPSE_MILESTONE=${MDE4CPP_ECLIPSE_MILESTONE:-}${C_RESET}"
echo "${C_PURPLE}[installEclipse]${C_INFO} MDE4CPP_ECLIPSE_ACCELEO_VERSION=${MDE4CPP_ECLIPSE_ACCELEO_VERSION:-}${C_RESET}"
echo "${C_PURPLE}[installEclipse]${C_INFO} MDE4CPP_ECLIPSE_SIRIUS_VERSION=${MDE4CPP_ECLIPSE_SIRIUS_VERSION:-}${C_RESET}"
echo "${C_PURPLE}[installEclipse]${C_INFO} MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION=${MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION:-}${C_RESET}"

if [[ -z "${MDE4CPP_HOME:-}" ]]; then
  echo "${C_PURPLE}[installEclipse]${C_ERROR} ERROR: MDE4CPP_HOME is not set.${C_RESET}"
  exit 1
fi
if [[ -z "${MDE4CPP_ECLIPSE_VERSION:-}" ]]; then
  echo "${C_PURPLE}[installEclipse]${C_ERROR} ERROR: MDE4CPP_ECLIPSE_VERSION is not set.${C_RESET}"
  exit 1
fi

MDE4CPP_PARENT="$(cd "${MDE4CPP_HOME}/.." && pwd)"
TARGET_DIR="${MDE4CPP_PARENT}/eclipse"
TMP_DIR="$(mktemp -d)"

ACCELEO_REPOSITORY_URL="https://download.eclipse.org/acceleo/updates/releases/${MDE4CPP_ECLIPSE_ACCELEO_VERSION//[[:space:]]/}"
SIRIUS_REPOSITORY_URL="https://download.eclipse.org/sirius/updates/releases/${MDE4CPP_ECLIPSE_SIRIUS_VERSION//[[:space:]]/}/${MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION//[[:space:]]/}"
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
  "${ECLIPSE_BIN}" -nosplash -application org.eclipse.equinox.p2.director -listInstalledIU > "${TMP_DIR}/installed.txt" 2>&1 || true
  
  acceleo_version=$(grep -E '^org\.eclipse\.acceleo\.feature\.group[[:space:]]+' "${TMP_DIR}/installed.txt" | awk '{print $NF}' | head -n1 || true)
  sirius_version=$(grep -E '^org\.eclipse\.sirius\.feature\.group[[:space:]]+' "${TMP_DIR}/installed.txt" | awk '{print $NF}' | head -n1 || true)
  
  echo "${C_PURPLE}[installEclipse]${C_SUCCESS} Found Acceleo: ${acceleo_version}${C_RESET}"
  echo "${C_PURPLE}[installEclipse]${C_SUCCESS} Found Sirius: ${sirius_version}${C_RESET}"
  
  if [[ "${acceleo_version}" == "${MDE4CPP_ECLIPSE_ACCELEO_VERSION//[[:space:]]/}"* && "${sirius_version}" == "${MDE4CPP_ECLIPSE_SIRIUS_VERSION//[[:space:]]/}"* ]]; then
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
      mkdir -p "${MDE4CPP_PARENT}"
      tar -xzf "${ARCHIVE_PATH}" -C "${MDE4CPP_PARENT}"
  fi
fi

if [[ ! -x "${ECLIPSE_BIN}" ]]; then
  echo "${C_PURPLE}[installEclipse]${C_ERROR} ERROR: Eclipse binary not found at ${ECLIPSE_BIN}${C_RESET}"
  exit 1
fi

ECLIPSE_PLUGINS=(
  "org.eclipse.acceleo.feature.group"
  "org.eclipse.acceleo.ui.interpreter.ocl.feature.group"
  "org.eclipse.acceleo.ui.interpreter.completeocl.feature.group"
  "org.eclipse.emf.sdk.feature.group"
  "org.eclipse.uml2.sdk.feature.group"
  "org.eclipse.ocl.all.sdk.feature.group"
  "org.eclipse.acceleo.query.feature.group"
  "org.eclipse.acceleo.query.source.feature.group"
  "org.antlr.runtime"
  "org.eclipse.sirius.common.acceleo.aql"
  "org.eclipse.sirius.ui.properties"
  "org.eclipse.sirius.aql.feature.group"
  "org.eclipse.sirius.runtime.aql.feature.group"
  "org.eclipse.sirius.properties.feature.feature.group"
  "org.eclipse.sirius.aql.source.feature.group"
  "org.eclipse.sirius.interpreter.feature.feature.group"
  "org.eclipse.sirius.interpreter.feature.source.feature.group"
  "org.eclipse.sirius.model.feature.source.feature.group"
  "org.eclipse.sirius.properties.feature.source.feature.group"
  "org.eclipse.sirius.runtime.aql.source.feature.group"
  "org.eclipse.sirius.runtime.ide.ui.feature.group"
  "org.eclipse.sirius.specifier.feature.group"
  "org.eclipse.sirius.specifier.ide.ui.aql.feature.group"
  "org.eclipse.sirius.specifier.ide.ui.aql.source.feature.group"
  "org.eclipse.sirius.specifier.ide.ui.feature.group"
  "org.eclipse.sirius.specifier.ide.ui.source.feature.group"
  "org.eclipse.sirius.specifier.properties.feature.feature.group"
  "org.eclipse.sirius.specifier.properties.feature.source.feature.group"
  "org.eclipse.sirius.specifier.source.feature.group"
  "org.eclipse.eef.ext.widgets.reference.feature.feature.group"
  "org.eclipse.eef.ext.widgets.reference.feature.source.feature.group"
  "org.eclipse.eef.sdk.feature.feature.group"
  "org.eclipse.eef.sdk.feature.source.feature.group"
  "org.eclipse.cdt.feature.group"
)

IU_ARGS=()
for plugin in "${ECLIPSE_PLUGINS[@]}"; do
  IU_ARGS+=("-installIU" "${plugin}")
done

echo "Installing Eclipse plugins (Acceleo, Sirius, CDT)..."
"${ECLIPSE_BIN}" \
  -nosplash \
  -application org.eclipse.equinox.p2.director \
  -repository "https://download.eclipse.org/releases/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/},${ACCELEO_REPOSITORY_URL},${SIRIUS_REPOSITORY_URL},${CDT_REPOSITORY_URL}" \
  "${IU_ARGS[@]}" \
  -destination "${P2_DESTINATION}" \
  -profileProperties org.eclipse.update.install.features=true

echo "${C_SUCCESS}Eclipse installation finished: ${TARGET_DIR}${C_RESET}"
