#!/bin/bash
set -e

# Always ensure we are in the right directory
cd /home/mde4cpp

# Setup and source environment
if [ -f "./docker/scripts/setup-setenv.sh" ]; then
    ./docker/scripts/setup-setenv.sh > /dev/null 2>&1
fi

if [ -f "./setenv" ]; then
    source ./setenv
fi

# Execute the command passed to the container
exec "$@"
