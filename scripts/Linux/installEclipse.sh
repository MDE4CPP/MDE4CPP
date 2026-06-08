#!/usr/bin/env bash
set -euo pipefail

# Step 1: Find repo root and read Eclipse versions from versions.properties
echo "[installEclipse] Reading configuration from versions.properties..."
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../../.." && pwd)"
VERSIONS_FILE="${REPO_ROOT}/versions.properties"

if [[ ! -f "${VERSIONS_FILE}" ]]; then
    echo "[installEclipse] ERROR: versions.properties not found at ${VERSIONS_FILE}"
    exit 1
fi

# Helper function to read property from file
read_property() {
    grep -i "^$1=" "${VERSIONS_FILE}" | cut -d'=' -f2 | tr -d ' ' | tr -d '\r'
}

# Read all Eclipse versions from properties file
MDE4CPP_HOME="${REPO_ROOT}"
MDE4CPP_ECLIPSE_VERSION=$(read_property "MDE4CPP_ECLIPSE_VERSION")
MDE4CPP_ECLIPSE_MILESTONE=$(read_property "MDE4CPP_ECLIPSE_MILESTONE")
MDE4CPP_ECLIPSE_ACCELEO_VERSION=$(read_property "MDE4CPP_ECLIPSE_ACCELEO_VERSION")
MDE4CPP_ECLIPSE_SIRIUS_VERSION=$(read_property "MDE4CPP_ECLIPSE_SIRIUS_VERSION")
MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION=$(read_property "MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION")

# Print requested Eclipse component versions.
echo "[installEclipse] Installing Eclipse ${MDE4CPP_ECLIPSE_VERSION} with Acceleo ${MDE4CPP_ECLIPSE_ACCELEO_VERSION} and Sirius ${MDE4CPP_ECLIPSE_SIRIUS_VERSION}"

# Validate required versions.
if [[ -z "${MDE4CPP_HOME}" ]]; then
  echo "[installEclipse] ERROR: Could not determine MDE4CPP_HOME"
  exit 1
fi

if [[ -z "${MDE4CPP_ECLIPSE_VERSION}" ]]; then
  echo "[installEclipse] ERROR: MDE4CPP_ECLIPSE_VERSION not found in ${VERSIONS_FILE}"
  exit 1
fi

if [[ -z "${MDE4CPP_ECLIPSE_MILESTONE}" ]]; then
  echo "[installEclipse] ERROR: MDE4CPP_ECLIPSE_MILESTONE not found in ${VERSIONS_FILE}"
  exit 1
fi

if [[ -z "${MDE4CPP_ECLIPSE_ACCELEO_VERSION}" ]]; then
  echo "[installEclipse] ERROR: MDE4CPP_ECLIPSE_ACCELEO_VERSION not found in ${VERSIONS_FILE}"
  exit 1
fi

if [[ -z "${MDE4CPP_ECLIPSE_SIRIUS_VERSION}" ]]; then
  echo "[installEclipse] ERROR: MDE4CPP_ECLIPSE_SIRIUS_VERSION not found in ${VERSIONS_FILE}"
  exit 1
fi

if [[ -z "${MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION}" ]]; then
  echo "[installEclipse] ERROR: MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION not found in ${VERSIONS_FILE}"
  exit 1
fi

# Step 3: Resolve installation paths and download URLs.
MDE4CPP_PARENT="$(cd "${MDE4CPP_HOME}/.." && pwd)"
TARGET_DIR="${MDE4CPP_PARENT}/eclipse"
TMP_DIR="$(mktemp -d)"
ARCHIVE_PATH="${TMP_DIR}/eclipse-modeling.tar.gz"

ECLIPSE_ARCHIVE_URL="https://ftp.halifax.rwth-aachen.de/eclipse/technology/epp/downloads/release/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}/${MDE4CPP_ECLIPSE_MILESTONE//[[:space:]]/}/eclipse-modeling-${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}-${MDE4CPP_ECLIPSE_MILESTONE//[[:space:]]/}-linux-gtk-x86_64.tar.gz"
ACCELEO_REPOSITORY_URL="https://download.eclipse.org/acceleo/updates/releases/${MDE4CPP_ECLIPSE_ACCELEO_VERSION//[[:space:]]/}"
SIRIUS_REPOSITORY_URL="https://download.eclipse.org/sirius/updates/releases/${MDE4CPP_ECLIPSE_SIRIUS_VERSION//[[:space:]]/}/${MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION//[[:space:]]/}"
CDT_REPOSITORY_URL="https://download.eclipse.org/releases/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}"

# Step 4: Register cleanup for temporary files.
cleanup() {
  rm -rf "${TMP_DIR}"
}
trap cleanup EXIT

# Step 5: Download and extract Eclipse Modeling package.
echo "MDE4CPP_HOME=${MDE4CPP_HOME}"
echo "Install location=${TARGET_DIR}"
echo "Using Eclipse version=${MDE4CPP_ECLIPSE_VERSION}, milestone=${MDE4CPP_ECLIPSE_MILESTONE}, Acceleo=${MDE4CPP_ECLIPSE_ACCELEO_VERSION}, Sirius=${MDE4CPP_ECLIPSE_SIRIUS_VERSION}"

# Step 5: Download and extract Eclipse if not already installed.
echo "Checking existing Eclipse installation..."
SKIP_DOWNLOAD=0
if [[ -x "${TARGET_DIR}/eclipse" ]]; then
  echo "Existing Eclipse installation found at ${TARGET_DIR}, skipping download and extraction."
  mkdir -p "${TMP_DIR}"
else
  echo "Downloading ${ECLIPSE_ARCHIVE_URL}"
  
  if command -v curl >/dev/null 2>&1; then
    curl -fL "${ECLIPSE_ARCHIVE_URL}" -o "${ARCHIVE_PATH}"
  elif command -v wget >/dev/null 2>&1; then
    wget -O "${ARCHIVE_PATH}" "${ECLIPSE_ARCHIVE_URL}"
  else
    echo "Neither curl nor wget is available."
    exit 1
  fi

  rm -rf "${TARGET_DIR}"
  mkdir -p "${MDE4CPP_PARENT}"
  tar -xzf "${ARCHIVE_PATH}" -C "${MDE4CPP_PARENT}"
fi

# Step 6: Install Acceleo into the Eclipse installation.
echo "Installing Acceleo from ${ACCELEO_REPOSITORY_URL}"
"${TARGET_DIR}/eclipse" \
  -nosplash \
  -application org.eclipse.equinox.p2.director \
  -repository "https://download.eclipse.org/releases/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/},${ACCELEO_REPOSITORY_URL}" \
  -installIU org.eclipse.acceleo.feature.group \
  -installIU org.eclipse.acceleo.ui.interpreter.ocl.feature.group \
  -installIU org.eclipse.acceleo.ui.interpreter.completeocl.feature.group \
  -installIU org.eclipse.emf.sdk.feature.group \
  -installIU org.eclipse.uml2.sdk.feature.group \
  -installIU org.eclipse.ocl.all.sdk.feature.group \
  -installIU org.eclipse.acceleo.query.feature.group \
  -installIU org.eclipse.acceleo.query.source.feature.group \
  -installIU org.antlr.runtime \
  -destination "${TARGET_DIR}" \
  -profileProperties org.eclipse.update.install.features=true

# Step 7: Install Sirius into the Eclipse installation.
echo "Installing Sirius from ${SIRIUS_REPOSITORY_URL}"
"${TARGET_DIR}/eclipse" \
  -nosplash \
  -application org.eclipse.equinox.p2.director \
  -repository "${SIRIUS_REPOSITORY_URL}" \
  -installIU org.eclipse.sirius.common.acceleo.aql \
  -installIU org.eclipse.sirius.ui.properties \
  -installIU org.eclipse.sirius.aql.feature.group \
  -installIU org.eclipse.sirius.common.acceleo.aql \
  -installIU org.eclipse.sirius.runtime.aql.feature.group \
  -installIU org.eclipse.sirius.properties.feature.feature.group \
  -installIU org.eclipse.sirius.aql.source.feature.group \
  -installIU org.eclipse.sirius.aql.feature.group \
  -installIU org.eclipse.sirius.interpreter.feature.feature.group \
  -installIU org.eclipse.sirius.interpreter.feature.source.feature.group \
  -installIU org.eclipse.sirius.model.feature.source.feature.group \
  -installIU org.eclipse.sirius.properties.feature.source.feature.group \
  -installIU org.eclipse.sirius.runtime.aql.source.feature.group \
  -installIU org.eclipse.sirius.runtime.ide.ui.feature.group \
  -installIU org.eclipse.sirius.specifier.feature.group \
  -installIU org.eclipse.sirius.specifier.ide.ui.aql.feature.group \
  -installIU org.eclipse.sirius.specifier.ide.ui.aql.source.feature.group \
  -installIU org.eclipse.sirius.specifier.ide.ui.feature.group \
  -installIU org.eclipse.sirius.specifier.ide.ui.source.feature.group \
  -installIU org.eclipse.sirius.specifier.properties.feature.feature.group \
  -installIU org.eclipse.sirius.specifier.properties.feature.source.feature.group \
  -installIU org.eclipse.sirius.specifier.source.feature.group \
  -installIU org.eclipse.eef.ext.widgets.reference.feature.feature.group \
  -installIU org.eclipse.eef.ext.widgets.reference.feature.source.feature.group \
  -installIU org.eclipse.eef.sdk.feature.feature.group \
  -installIU org.eclipse.eef.sdk.feature.source.feature.group \
  -destination "${TARGET_DIR}" \
  -profileProperties org.eclipse.update.install.features=true

# Step 8: Install CDT into the Eclipse installation.
echo "Installing CDT from ${CDT_REPOSITORY_URL}"
"${TARGET_DIR}/eclipse" \
  -nosplash \
  -application org.eclipse.equinox.p2.director \
  -repository "${CDT_REPOSITORY_URL}" \
  -installIU org.eclipse.cdt.feature.group \
  -destination "${TARGET_DIR}" \
  -profileProperties org.eclipse.update.install.features=true

echo "Eclipse installation finished: ${TARGET_DIR}"
