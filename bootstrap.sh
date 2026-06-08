#!/bin/bash

# ############################################
# Bootstrap script for MDE4CPP installation
# ############################################
# This script runs independently of Gradle to:
#   1. Check for existing tool installations
#   2. Ask user to use existing or provide new paths
#   3. Create setenv with detected/selected paths
#   4. Run install scripts (which read versions directly)
#   5. Source setenv and run Gradle install
# ############################################

echo "[bootstrap] MDE4CPP Bootstrap Script for Linux/MacOS"
echo "[bootstrap] Starting setup..."

# Get the directory where this script is located
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
VERSIONS_FILE="${SCRIPT_DIR}/versions.properties"
SETENV_FILE="${SCRIPT_DIR}/setenv"

# Check if versions.properties exists
if [ ! -f "$VERSIONS_FILE" ]; then
    echo "[bootstrap] ERROR: versions.properties not found at $VERSIONS_FILE"
    exit 1
fi

echo "[bootstrap] versions.properties found at $VERSIONS_FILE"

# Step 1: Detect existing tool installations and prompt user
echo ""
echo "[bootstrap] Checking for existing tool installations..."
echo ""

detect_and_prompt_tools

# Step 2: Create setenv if it doesn't exist
if [ ! -f "$SETENV_FILE" ]; then
    echo ""
    echo "[bootstrap] Creating setenv with detected paths..."
    create_setenv_from_paths "$SETENV_FILE"
    if [ $? -ne 0 ]; then
        echo "[bootstrap] ERROR: Failed to create setenv"
        exit 1
    fi
    echo "[bootstrap] setenv created successfully"
    chmod +x "$SETENV_FILE"
else
    echo "[bootstrap] setenv already exists, skipping creation"
fi

# Step 3: Run install scripts
# Note: Each install script reads versions directly from versions.properties
echo "[bootstrap] Installing required tools..."

# Install Java (required for Gradle)
if [ -x "${SCRIPT_DIR}/scripts/Linux/installJava.sh" ]; then
    echo "[bootstrap] Installing Java..."
    set +e
    bash "${SCRIPT_DIR}/scripts/Linux/installJava.sh"
    JAVA_EXIT=$?
    set -e
    if [ ${JAVA_EXIT} -eq 0 ]; then
        echo "[bootstrap] Java installation completed"
    else
        echo "[bootstrap] WARNING: Java installation failed or was skipped (exit code: ${JAVA_EXIT})"
    fi
else
    echo "[bootstrap] WARNING: installJava.sh not found"
fi

# Install C++ Compiler
if [ -x "${SCRIPT_DIR}/scripts/Linux/installCompiler.sh" ]; then
    echo "[bootstrap] Installing C++ Compiler..."
    set +e
    bash "${SCRIPT_DIR}/scripts/Linux/installCompiler.sh"
    COMPILER_EXIT=$?
    set -e
    if [ ${COMPILER_EXIT} -eq 0 ]; then
        echo "[bootstrap] Compiler installation completed"
    else
        echo "[bootstrap] WARNING: Compiler installation failed or was skipped (exit code: ${COMPILER_EXIT})"
    fi
else
    echo "[bootstrap] WARNING: installCompiler.sh not found"
fi

# Install CMake
if [ -x "${SCRIPT_DIR}/scripts/Linux/installCMake.sh" ]; then
    echo "[bootstrap] Installing CMake..."
    set +e
    bash "${SCRIPT_DIR}/scripts/Linux/installCMake.sh"
    CMAKE_EXIT=$?
    set -e
    if [ ${CMAKE_EXIT} -eq 0 ]; then
        echo "[bootstrap] CMake installation completed"
    else
        echo "[bootstrap] WARNING: CMake installation failed or was skipped (exit code: ${CMAKE_EXIT})"
    fi
else
    echo "[bootstrap] WARNING: installCMake.sh not found"
fi

# Install Eclipse
if [ -x "${SCRIPT_DIR}/scripts/Linux/installEclipse.sh" ]; then
    echo "[bootstrap] Installing Eclipse..."
    set +e
    bash "${SCRIPT_DIR}/scripts/Linux/installEclipse.sh"
    ECLIPSE_EXIT=$?
    set -e
    if [ ${ECLIPSE_EXIT} -eq 0 ]; then
        echo "[bootstrap] Eclipse installation completed"
    else
        echo "[bootstrap] WARNING: Eclipse installation failed or was skipped (exit code: ${ECLIPSE_EXIT})"
    fi
else
    echo "[bootstrap] WARNING: installEclipse.sh not found"
fi

echo "[bootstrap] Bootstrap completed successfully"

# Step 4: Configure environment and run Gradle install
if [ -f "$SETENV_FILE" ]; then
    echo "[bootstrap] Sourcing setenv to configure environment..."
    # shellcheck disable=SC1090
    source "$SETENV_FILE"
else
    echo "[bootstrap] WARNING: $SETENV_FILE not found, skipping environment setup"
fi

GRADLE_WRAPPER="${SCRIPT_DIR}/application/tools/gradlew"
if [ -x "${GRADLE_WRAPPER}" ]; then
    echo "[bootstrap] Running Gradle install via ${GRADLE_WRAPPER}"
    set +e
    "${GRADLE_WRAPPER}" install --no-daemon
    GRADLE_EXIT=$?
    set -e
    if [ ${GRADLE_EXIT} -ne 0 ]; then
        echo "[bootstrap] ERROR: Gradle install task failed (exit ${GRADLE_EXIT})"
        exit ${GRADLE_EXIT}
    fi
    echo "[bootstrap] Bootstrap and install completed successfully"
else
    echo "[bootstrap] WARNING: Gradle wrapper not found at ${GRADLE_WRAPPER}, skipping Gradle install"
fi

exit 0

# ############################################
# Functions
# ############################################

# detect_and_prompt_tools: detect existing tools and prompt user for paths
detect_and_prompt_tools() {
    local JAVA_HOME_DEFAULT="/usr/lib/jvm/java-21"
    local CMAKE_HOME_DEFAULT="/usr/local"
    local COMPILER_HOME_DEFAULT="/usr"
    local ECLIPSE_HOME_DEFAULT="${HOME}/eclipse"

    # Initialize with defaults
    JAVA_HOME_FINAL="$JAVA_HOME_DEFAULT"
    CMAKE_HOME_FINAL="$CMAKE_HOME_DEFAULT"
    COMPILER_HOME_FINAL="$COMPILER_HOME_DEFAULT"
    ECLIPSE_HOME_FINAL="$ECLIPSE_HOME_DEFAULT"

    # Detect Java
    echo "[bootstrap] Detecting Java..."
    if command -v java >/dev/null 2>&1; then
        JAVA_INFO=$(java -version 2>&1 | head -1)
        echo "[bootstrap]   Found: $JAVA_INFO"
        read -p "             Use existing Java? (Y/n) or enter new path: " USER_CHOICE
        if [[ "$USER_CHOICE" != "n" && "$USER_CHOICE" != "N" ]]; then
            if [ -z "$USER_CHOICE" ]; then
                echo "[bootstrap]   Using existing Java"
                JAVA_BIN=$(command -v java)
                JAVA_HOME_FINAL=$(dirname "$(dirname "$JAVA_BIN")")
            else
                JAVA_HOME_FINAL="$USER_CHOICE"
            fi
        else
            read -p "             Enter Java home path: " JAVA_HOME_FINAL
            [ -z "$JAVA_HOME_FINAL" ] && JAVA_HOME_FINAL="$JAVA_HOME_DEFAULT"
        fi
    else
        echo "[bootstrap]   Java not found"
        read -p "             Enter Java home path [$JAVA_HOME_DEFAULT]: " JAVA_HOME_FINAL
        [ -z "$JAVA_HOME_FINAL" ] && JAVA_HOME_FINAL="$JAVA_HOME_DEFAULT"
    fi
    echo "[bootstrap]   Java path set to: $JAVA_HOME_FINAL"
    echo ""

    # Detect CMake
    echo "[bootstrap] Detecting CMake..."
    if command -v cmake >/dev/null 2>&1; then
        CMAKE_INFO=$(cmake --version | head -1)
        echo "[bootstrap]   Found: $CMAKE_INFO"
        read -p "             Use existing CMake? (Y/n) or enter new path: " USER_CHOICE
        if [[ "$USER_CHOICE" != "n" && "$USER_CHOICE" != "N" ]]; then
            if [ -z "$USER_CHOICE" ]; then
                echo "[bootstrap]   Using existing CMake"
                CMAKE_BIN=$(command -v cmake)
                CMAKE_HOME_FINAL=$(dirname "$(dirname "$CMAKE_BIN")")
            else
                CMAKE_HOME_FINAL="$USER_CHOICE"
            fi
        else
            read -p "             Enter CMake home path: " CMAKE_HOME_FINAL
            [ -z "$CMAKE_HOME_FINAL" ] && CMAKE_HOME_FINAL="$CMAKE_HOME_DEFAULT"
        fi
    else
        echo "[bootstrap]   CMake not found"
        read -p "             Enter CMake home path [$CMAKE_HOME_DEFAULT]: " CMAKE_HOME_FINAL
        [ -z "$CMAKE_HOME_FINAL" ] && CMAKE_HOME_FINAL="$CMAKE_HOME_DEFAULT"
    fi
    echo "[bootstrap]   CMake path set to: $CMAKE_HOME_FINAL"
    echo ""

    # Detect C++ Compiler
    echo "[bootstrap] Detecting C++ Compiler..."
    if command -v g++ >/dev/null 2>&1; then
        COMPILER_INFO=$(g++ --version | head -1)
        echo "[bootstrap]   Found: $COMPILER_INFO"
        COMPILER_VERSION_DETECTED=$(g++ --version | grep -oP '\d+\.\d+\.\d+' | head -1)
        read -p "             Use existing compiler? (Y/n) or enter new path: " USER_CHOICE
        if [[ "$USER_CHOICE" != "n" && "$USER_CHOICE" != "N" ]]; then
            if [ -z "$USER_CHOICE" ]; then
                echo "[bootstrap]   Using existing compiler"
                COMPILER_BIN=$(command -v g++)
                COMPILER_HOME_FINAL=$(dirname "$(dirname "$COMPILER_BIN")")
            else
                COMPILER_HOME_FINAL="$USER_CHOICE"
            fi
        else
            read -p "             Enter compiler home path: " COMPILER_HOME_FINAL
            [ -z "$COMPILER_HOME_FINAL" ] && COMPILER_HOME_FINAL="$COMPILER_HOME_DEFAULT"
        fi
    else
        echo "[bootstrap]   C++ compiler not found"
        read -p "             Enter compiler home path [$COMPILER_HOME_DEFAULT]: " COMPILER_HOME_FINAL
        [ -z "$COMPILER_HOME_FINAL" ] && COMPILER_HOME_FINAL="$COMPILER_HOME_DEFAULT"
    fi
    [ -z "$COMPILER_VERSION_DETECTED" ] && COMPILER_VERSION_DETECTED="11.2.0"
    echo "[bootstrap]   Compiler path set to: $COMPILER_HOME_FINAL"
    echo "[bootstrap]   Compiler version: $COMPILER_VERSION_DETECTED"
    echo ""

    # Detect Eclipse
    echo "[bootstrap] Detecting Eclipse..."
    if command -v eclipse >/dev/null 2>&1; then
        echo "[bootstrap]   Found in PATH"
        read -p "             Use existing Eclipse? (Y/n) or enter new path: " USER_CHOICE
        if [[ "$USER_CHOICE" != "n" && "$USER_CHOICE" != "N" ]]; then
            if [ -z "$USER_CHOICE" ]; then
                echo "[bootstrap]   Using existing Eclipse"
                ECLIPSE_BIN=$(command -v eclipse)
                ECLIPSE_HOME_FINAL=$(dirname "$ECLIPSE_BIN")
            else
                ECLIPSE_HOME_FINAL="$USER_CHOICE"
            fi
        else
            read -p "             Enter Eclipse home path: " ECLIPSE_HOME_FINAL
            [ -z "$ECLIPSE_HOME_FINAL" ] && ECLIPSE_HOME_FINAL="$ECLIPSE_HOME_DEFAULT"
        fi
    else
        echo "[bootstrap]   Eclipse not found in PATH"
        read -p "             Enter Eclipse home path [$ECLIPSE_HOME_DEFAULT]: " ECLIPSE_HOME_FINAL
        [ -z "$ECLIPSE_HOME_FINAL" ] && ECLIPSE_HOME_FINAL="$ECLIPSE_HOME_DEFAULT"
    fi
    echo "[bootstrap]   Eclipse path set to: $ECLIPSE_HOME_FINAL"
    echo ""

    # Export for use in other functions
    export JAVA_HOME_FINAL
    export CMAKE_HOME_FINAL
    export COMPILER_HOME_FINAL
    export ECLIPSE_HOME_FINAL
}

# create_setenv_from_paths: creates setenv with collected paths
create_setenv_from_paths() {
    local SETENV_PATH="$1"

    cat > "$SETENV_PATH" << EOF
#!/bin/bash

########################################
# Environment configuration of MDE4CPP #
# Generated by bootstrap.sh            #
########################################

# path to MDE4CPP home folder
export MDE4CPP_HOME="\$(cd "\$(dirname "\${BASH_SOURCE[0]}")" && pwd)"

# path to eclipse home folder including Acceleo plugins
# required for creating the generators
export MDE4CPP_ECLIPSE_HOME="$ECLIPSE_HOME_FINAL"

##################################################
# configure Gradle tasks and compiling processes #
##################################################

# enable parallel execution of Gradle tasks permanently with value 'true', otherwise 'false'
export GRADLE_OPTS="-Dorg.gradle.parallel=true"

# configure count of worker for each compile task
export ORG_GRADLE_PROJECT_WORKER=1

# release version will be compiled with value unequal '0' or if ORG_GRADLE_PROJECT_RELEASE and ORG_GRADLE_PROJECT_DEBUG are undefined
export ORG_GRADLE_PROJECT_RELEASE=1

# debug version will be compiled with value unequal '0'
export ORG_GRADLE_PROJECT_DEBUG=1

# debug messages of fUML library will be enabled with value '1'
export ORG_GRADLE_PROJECT_DEBUG_MESSAGE_FUML=0

#####################################################
# configure PATH variable with minimal set of paths #
#####################################################

# path to cmake home folder
export CMAKE_HOME="$CMAKE_HOME_FINAL"

# path to compiler home folder
export COMPILER_HOME="$COMPILER_HOME_FINAL"

# path to java development kit
export JAVA_HOME="$JAVA_HOME_FINAL"

# Set combined PATH
if [ -n "\$CMAKE_HOME" ]; then
    export PATH="\$CMAKE_HOME/bin:\$PATH"
fi
if [ -n "\$COMPILER_HOME" ]; then
    export PATH="\$COMPILER_HOME/bin:\$PATH"
fi
if [ -n "\$JAVA_HOME" ]; then
    export PATH="\$JAVA_HOME/bin:\$PATH"
fi
if [ -n "\$MDE4CPP_HOME" ]; then
    export PATH="\$MDE4CPP_HOME/application/bin:\$MDE4CPP_HOME/application/tools:\$PATH"
fi

###############################################################################
# configure compiler information for include path setting inside your c++ IDE #
###############################################################################

# delivery name of compiler
export COMPILER_DELIVERY_NAME="x86_64-linux-gnu"

# compiler version for include path generation
export COMPILER_VERSION="$COMPILER_VERSION_DETECTED"

# Optional: path to your C++ IDE executable
# export CPP_IDE_EXECUTABLE=~/eclipse/eclipse
EOF

    echo "[bootstrap] setenv created successfully"
    return 0
}
