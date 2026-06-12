#!/usr/bin/env bash
# Common functions for MDE4CPP bootstrap scripts

# Function to read properties file and export variables
load_properties() {
    local prop_file="$1"
    if [ -f "$prop_file" ]; then
        echo "Loading properties from $prop_file..."
        while IFS='=' read -r key value; do
            # Ignore comments and empty lines
            if [[ "$key" =~ ^#.* ]] || [[ -z "$key" ]]; then
                continue
            fi
            # Remove leading/trailing whitespaces and carriage returns
            key=$(echo "$key" | xargs)
            value=$(echo "$value" | tr -d '\r' | xargs)
            export "$key"="$value"
            echo "  $key=$value"
        done < "$prop_file"
    else
        echo "Error: Properties file $prop_file not found!"
        exit 1
    fi
}
