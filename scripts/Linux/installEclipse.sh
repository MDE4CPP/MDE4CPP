#!/usr/bin/env bash
set -euo pipefail

# Step 1: Print requested Eclipse component versions.
echo "Installing Eclipse ${MDE4CPP_ECLIPSE_VERSION} with Acceleo ${MDE4CPP_ECLIPSE_ACCELEO_VERSION} and Sirius ${MDE4CPP_ECLIPSE_SIRIUS_VERSION}"

# Step 2: Validate required input variables.
if [[ -z "${MDE4CPP_HOME:-}" ]]; then
  echo "MDE4CPP_HOME is not set."
  exit 1
fi

if [[ -z "${MDE4CPP_ECLIPSE_VERSION:-}" ]]; then
  echo "MDE4CPP_ECLIPSE_VERSION is not set."
  exit 1
fi

if [[ -z "${MDE4CPP_ECLIPSE_MILESTONE:-}" ]]; then
  echo "MDE4CPP_ECLIPSE_MILESTONE is not set."
  exit 1
fi

if [[ -z "${MDE4CPP_ECLIPSE_ACCELEO_VERSION:-}" ]]; then
  echo "MDE4CPP_ECLIPSE_ACCELEO_VERSION is not set."
  exit 1
fi

if [[ -z "${MDE4CPP_ECLIPSE_SIRIUS_VERSION:-}" ]]; then
  echo "MDE4CPP_ECLIPSE_SIRIUS_VERSION is not set."
  exit 1
fi

if [[ -z "${MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION:-}" ]]; then
  echo "MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION is not set."
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

echo "Checking existing Eclipse installation..."
SKIP_DOWNLOAD=0
if [[ -x "${TARGET_DIR}/eclipse" ]]; then
  echo "Existing Eclipse installation found at ${TARGET_DIR}."
  mkdir -p "${TMP_DIR}"
  "${TARGET_DIR}/eclipse" -nosplash -application org.eclipse.equinox.p2.director -listInstalledIU > "${TMP_DIR}/installed.txt" 2>&1 || true
  echo "Installed IU output:"
  grep -E '^org\.eclipse\.(acceleo|sirius)\.' "${TMP_DIR}/installed.txt" || true
  acceleo_version=$(grep -E '^org\.eclipse\.acceleo\.feature\.group[[:space:]]+' "${TMP_DIR}/installed.txt" | awk '{print $NF}' | head -n1 || true)
  sirius_version=$(grep -E '^org\.eclipse\.sirius\.feature\.group[[:space:]]+' "${TMP_DIR}/installed.txt" | awk '{print $NF}' | head -n1 || true)
  echo "Found Acceleo: ${acceleo_version}"
  echo "Found Sirius: ${sirius_version}"
  if [[ "${acceleo_version}" == "${MDE4CPP_ECLIPSE_ACCELEO_VERSION//[[:space:]]/}"* && "${sirius_version}" == "${MDE4CPP_ECLIPSE_SIRIUS_VERSION//[[:space:]]/}"* ]]; then
    echo "Requested Eclipse plugins already installed, skipping installation."
    exit 0
  else
    echo "Eclipse plugin versions differ or are missing; updating installation."
    SKIP_DOWNLOAD=1
  fi
fi

echo "Downloading ${ECLIPSE_ARCHIVE_URL}"

if [[ "$SKIP_DOWNLOAD" == "0" ]]; then
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
else
  echo "Skipping Eclipse download/extract because existing installation is being updated."
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
