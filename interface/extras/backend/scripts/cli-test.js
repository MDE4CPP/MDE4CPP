#!/usr/bin/env node

/**
 * CLI tool for testing the MDE4CPP Build Service API
 * Usage:
 *   node scripts/cli-test.js upload --file model.ecore
 *   node scripts/cli-test.js status --build-id <id>
 *   node scripts/cli-test.js download --build-id <id> --output ./downloads
 */

const axios = require('axios');
const FormData = require('form-data');
const fs = require('fs');
const path = require('path');

const API_BASE_URL = process.env.API_URL || 'http://localhost:8000/api/v1';

/**
 * Upload file and start build
 */
async function uploadFile(filePath) {
    if (!fs.existsSync(filePath)) {
        console.error(`Error: File not found: ${filePath}`);
        process.exit(1);
    }
    
    console.log(`Uploading file: ${filePath}`);
    
    const form = new FormData();
    form.append('file', fs.createReadStream(filePath));
    
    try {
        const response = await axios.post(`${API_BASE_URL}/build`, form, {
            headers: form.getHeaders(),
            maxContentLength: Infinity,
            maxBodyLength: Infinity
        });
        
        console.log('\nBuild started successfully!');
        console.log('Build ID:', response.data.buildId);
        console.log('Status URL:', `${API_BASE_URL}/build/${response.data.buildId}/status`);
        console.log('\nCheck status with:');
        console.log(`  node scripts/cli-test.js status --build-id ${response.data.buildId}`);
        
        return response.data.buildId;
    } catch (error) {
        console.error('Error uploading file:');
        if (error.response) {
            console.error('Status:', error.response.status);
            console.error('Error:', error.response.data);
        } else {
            console.error(error.message);
        }
        process.exit(1);
    }
}

/**
 * Check build status
 */
async function checkStatus(buildId) {
    try {
        const response = await axios.get(`${API_BASE_URL}/build/${buildId}/status`);
        const build = response.data;
        
        console.log('\nBuild Status:');
        console.log('  Build ID:', build.buildId);
        console.log('  Status:', build.status);
        console.log('  Progress:', build.progress + '%');
        console.log('  Stage:', build.stage);
        console.log('  Message:', build.message);
        
        if (build.startedAt) {
            console.log('  Started:', build.startedAt);
        }
        if (build.completedAt) {
            console.log('  Completed:', build.completedAt);
        }
        
        if (build.outputFiles) {
            console.log('\nOutput Files:');
            if (build.outputFiles.dlls && build.outputFiles.dlls.length > 0) {
                console.log('  DLLs:');
                build.outputFiles.dlls.forEach(dll => {
                    console.log(`    - ${dll.name} (${dll.size} bytes)`);
                });
            }
            if (build.outputFiles.executables && build.outputFiles.executables.length > 0) {
                console.log('  Executables:');
                build.outputFiles.executables.forEach(exe => {
                    console.log(`    - ${exe.name} (${exe.size} bytes)`);
                });
            }
        }
        
        if (build.errors && build.errors.length > 0) {
            console.log('\nErrors:');
            build.errors.forEach(error => {
                console.log(`  [${error.stage}] ${error.message}`);
            });
        }
        
        return build;
    } catch (error) {
        console.error('Error checking status:');
        if (error.response) {
            console.error('Status:', error.response.status);
            console.error('Error:', error.response.data);
        } else {
            console.error(error.message);
        }
        process.exit(1);
    }
}

/**
 * Download build files
 */
async function downloadFiles(buildId, outputDir) {
    if (!fs.existsSync(outputDir)) {
        fs.mkdirSync(outputDir, { recursive: true });
    }
    
    console.log(`Downloading files for build: ${buildId}`);
    console.log(`Output directory: ${outputDir}`);
    
    try {
        const response = await axios.get(
            `${API_BASE_URL}/build/${buildId}/download/zip`,
            { responseType: 'stream' }
        );
        
        const outputPath = path.join(outputDir, `build-${buildId}.zip`);
        const writer = fs.createWriteStream(outputPath);
        
        response.data.pipe(writer);
        
        return new Promise((resolve, reject) => {
            writer.on('finish', () => {
                console.log(`\nFiles downloaded successfully to: ${outputPath}`);
                resolve(outputPath);
            });
            writer.on('error', reject);
        });
    } catch (error) {
        console.error('Error downloading files:');
        if (error.response) {
            console.error('Status:', error.response.status);
            console.error('Error:', error.response.data);
        } else {
            console.error(error.message);
        }
        process.exit(1);
    }
}

/**
 * List build files
 */
async function listFiles(buildId) {
    try {
        const response = await axios.get(`${API_BASE_URL}/build/${buildId}/files`);
        const data = response.data;
        
        console.log('\nBuild Files:');
        console.log('  Build ID:', data.buildId);
        
        if (data.files.dlls && data.files.dlls.length > 0) {
            console.log('\n  DLLs:');
            data.files.dlls.forEach(file => {
                console.log(`    - ${file.name} (${file.sizeFormatted})`);
            });
        }
        
        if (data.files.executables && data.files.executables.length > 0) {
            console.log('\n  Executables:');
            data.files.executables.forEach(file => {
                console.log(`    - ${file.name} (${file.sizeFormatted})`);
            });
        }
    } catch (error) {
        console.error('Error listing files:');
        if (error.response) {
            console.error('Status:', error.response.status);
            console.error('Error:', error.response.data);
        } else {
            console.error(error.message);
        }
        process.exit(1);
    }
}

// CLI interface
const [,, command, ...args] = process.argv;

if (command === 'upload') {
    const fileIndex = args.indexOf('--file');
    if (fileIndex === -1 || !args[fileIndex + 1]) {
        console.error('Usage: node scripts/cli-test.js upload --file <path>');
        process.exit(1);
    }
    const filePath = args[fileIndex + 1];
    uploadFile(filePath);
} else if (command === 'status') {
    const buildIdIndex = args.indexOf('--build-id');
    if (buildIdIndex === -1 || !args[buildIdIndex + 1]) {
        console.error('Usage: node scripts/cli-test.js status --build-id <id>');
        process.exit(1);
    }
    const buildId = args[buildIdIndex + 1];
    checkStatus(buildId);
} else if (command === 'download') {
    const buildIdIndex = args.indexOf('--build-id');
    const outputIndex = args.indexOf('--output');
    if (buildIdIndex === -1 || !args[buildIdIndex + 1]) {
        console.error('Usage: node scripts/cli-test.js download --build-id <id> [--output <dir>]');
        process.exit(1);
    }
    const buildId = args[buildIdIndex + 1];
    const outputDir = outputIndex !== -1 && args[outputIndex + 1] ? args[outputIndex + 1] : './downloads';
    downloadFiles(buildId, outputDir);
} else if (command === 'files') {
    const buildIdIndex = args.indexOf('--build-id');
    if (buildIdIndex === -1 || !args[buildIdIndex + 1]) {
        console.error('Usage: node scripts/cli-test.js files --build-id <id>');
        process.exit(1);
    }
    const buildId = args[buildIdIndex + 1];
    listFiles(buildId);
} else {
    console.log('MDE4CPP Build Service CLI Test Tool');
    console.log('\nUsage:');
    console.log('  node scripts/cli-test.js upload --file <path>');
    console.log('  node scripts/cli-test.js status --build-id <id>');
    console.log('  node scripts/cli-test.js download --build-id <id> [--output <dir>]');
    console.log('  node scripts/cli-test.js files --build-id <id>');
    console.log('\nExamples:');
    console.log('  node scripts/cli-test.js upload --file model.ecore');
    console.log('  node scripts/cli-test.js status --build-id abc123-def456-ghi789');
    console.log('  node scripts/cli-test.js download --build-id abc123-def456-ghi789 --output ./downloads');
}
