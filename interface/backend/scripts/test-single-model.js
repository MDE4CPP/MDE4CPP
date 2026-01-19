#!/usr/bin/env node

/**
 * Test script for backend API - single model test
 * Tests one model file to verify fixes
 */

const axios = require('axios');
const FormData = require('form-data');
const fs = require('fs');
const path = require('path');

const API_BASE_URL = process.env.API_URL || 'http://localhost:8000/api/v1';
const MDE4CPP_HOME = process.env.MDE4CPP_HOME || path.join(__dirname, '../../..');

// Test with libraryModel_ecore.ecore (simpler ECORE example)
const testModel = path.join(MDE4CPP_HOME, 'src', 'examples', 'ecoreExamples', 'ecoreModelExample', 'model', 'libraryModel_ecore.ecore');

async function testModelFile() {
    console.log('=== Testing Backend with Single Model File ===\n');
    console.log('Model file:', testModel);
    
    if (!fs.existsSync(testModel)) {
        console.error('Error: Model file not found:', testModel);
        process.exit(1);
    }
    
    try {
        // Upload file
        console.log('\nUploading file...');
        const form = new FormData();
        form.append('file', fs.createReadStream(testModel));
        
        const uploadResponse = await axios.post(`${API_BASE_URL}/build`, form, {
            headers: form.getHeaders(),
            timeout: 30000
        });
        
        const buildId = uploadResponse.data.buildId;
        console.log('Build ID:', buildId);
        console.log('Initial Status:', uploadResponse.data.status);
        
        // Poll for status
        console.log('\nPolling build status...');
        for (let i = 0; i < 60; i++) {
            await new Promise(resolve => setTimeout(resolve, 3000));
            
            try {
                const statusResponse = await axios.get(`${API_BASE_URL}/build/${buildId}/status`);
                const status = statusResponse.data;
                
                console.log(`[${i * 3}s] Status: ${status.status} - ${status.message || ''}`);
                
                if (status.status === 'completed' || status.status === 'failed') {
                    console.log('\n=== Final Status ===');
                    console.log('Status:', status.status);
                    console.log('Message:', status.message || '');
                    
                    if (status.outputFiles) {
                        console.log('\nOutput Files:');
                        if (status.outputFiles.dlls && status.outputFiles.dlls.length > 0) {
                            console.log(`  DLLs: ${status.outputFiles.dlls.length}`);
                            status.outputFiles.dlls.forEach(f => {
                                console.log(`    - ${f.name} (${f.sizeFormatted})`);
                            });
                        } else {
                            console.log('  DLLs: 0 (none found)');
                        }
                        
                        if (status.outputFiles.executables && status.outputFiles.executables.length > 0) {
                            console.log(`  Executables: ${status.outputFiles.executables.length}`);
                            status.outputFiles.executables.forEach(f => {
                                console.log(`    - ${f.name} (${f.sizeFormatted})`);
                            });
                        } else {
                            console.log('  Executables: 0 (none found)');
                        }
                    } else {
                        console.log('\nNo output files information available');
                    }
                    
                    // Success if completed and has DLLs
                    if (status.status === 'completed' && status.outputFiles && status.outputFiles.dlls && status.outputFiles.dlls.length > 0) {
                        console.log('\n✓ Test PASSED: Build completed successfully with DLLs found');
                        process.exit(0);
                    } else if (status.status === 'completed') {
                        console.log('\n⚠ Test PARTIAL: Build completed but no DLLs found');
                        process.exit(1);
                    } else {
                        console.log('\n✗ Test FAILED: Build failed');
                        process.exit(1);
                    }
                }
            } catch (err) {
                console.error('Error polling status:', err.message);
                if (err.response) {
                    console.error('Response:', err.response.data);
                }
                process.exit(1);
            }
        }
        
        console.log('\n✗ Test TIMEOUT: Build did not complete within 3 minutes');
        process.exit(1);
    } catch (err) {
        console.error('\n✗ Test FAILED: Error uploading file');
        console.error('Error:', err.message);
        if (err.response) {
            console.error('Response:', err.response.data);
        }
        process.exit(1);
    }
}

testModelFile();
