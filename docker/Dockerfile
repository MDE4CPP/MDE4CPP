# Optimized for runtime builds via docker-compose
# System packages installed at build time, Eclipse at runtime

# ============================================================================
# Base Image with JDK
# ============================================================================
FROM eclipse-temurin:21-jdk-jammy

# Install system build dependencies (these go to /usr/bin, not affected by bind mounts)
RUN apt-get update && apt-get install -y --no-install-recommends \
    bash \
    sudo \
    build-essential \
    gcc \
    g++ \
    git \
    wget \
    unzip \
    tar \
    mingw-w64 \
    g++-mingw-w64-x86-64 \
    gcc-mingw-w64-x86-64 \
    gnupg \
    ca-certificates \
    uuid-dev \
    && rm -rf /var/lib/apt/lists/* \
    && apt-get clean

# Install CMake from Kitware
RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc | gpg --dearmor -o /usr/share/keyrings/kitware-archive-keyring.gpg \
    && echo "deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ jammy main" > /etc/apt/sources.list.d/kitware.list \
    && apt-get update \
    && apt-get install -y cmake \
    && rm -rf /var/lib/apt/lists/* \
    && apt-get clean

# Configure MinGW-w64 alternatives
RUN update-alternatives --set x86_64-w64-mingw32-g++ /usr/bin/x86_64-w64-mingw32-g++-posix 2>/dev/null || true \
    && update-alternatives --set x86_64-w64-mingw32-gcc /usr/bin/x86_64-w64-mingw32-gcc-posix 2>/dev/null || true

# Set JAVA_HOME for JDK 21 (needed for Gradle and build tools)
ENV JAVA_HOME=/opt/java/openjdk

# Create user and project directory structure
RUN useradd -u 1000 -m -d /home/mde4cpp mde4cpp \
    && mkdir -p /home/mde4cpp \
    && chown -R mde4cpp:mde4cpp /home/mde4cpp

# Set working directory
WORKDIR /home/mde4cpp

# Note: Eclipse and user-space dependencies are installed at runtime
# via bind mount and docker/scripts/install-eclipse.sh in the build-full service
# System packages (cmake, gcc, etc.) are already in the image
