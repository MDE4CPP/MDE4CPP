#!/usr/bin/env node

/**
 * Test script for backend API
 * Uploads all model files and checks results
 */

const axios = require('axios');
const FormData = require('form-data');
const fs = require('fs');
const path = require('path');

const API_BASE_URL = process.env.API_URL || 'http://localhost:8000/api/v1';
const MDE4CPP_HOME = process.env.MDE4CPP_HOME || path.join(__dirname, '../..');

const testModels = [
    { file: path.join(MDE4CPP_HOME, 'src/examples/ecoreExamples/ecoreModelExample/model/libraryModel_ecore.ecore'), category: 'ECORE', type: 'ECORE' },
    { file: path.join(MDE4CPP_HOME, 'src/examples/fUMLExamples/TestSuite/SignalExample/model/SignalExample.uml'), category: 'fUML', type: 'fUML' },
    { file: path.join(MDE4CPP_HOME, 'src/examples/fUMLExamples/TestSuite/RegionTest/model/RegionTest.uml'), category: 'fUML', type: 'fUML' },
    { file: path.join(MDE4CPP_HOME, 'src/examples/fUMLExamples/TestSuite/SimpleBehaviorTest/model/SimpleBehaviorTest.uml'), category: 'fUML', type: 'fUML' },
    { file: path.join(MDE4CPP_HOME, 'src/examples/fUMLExamples/ThreePhilosophers/model/philosophers_datastore.uml'), category: 'fUML', type: 'fUML' },
    { file: path.join(MDE4CPP_HOME, 'src/examples/fUMLExamples/ThreePhilosophers/model/philosophers.uml'), category: 'fUML', type: 'fUML' },
    { file: path.join(MDE4CPP_HOME, 'src/examples/oclExamples/oclEcoreModelExample/model/Library_ecore.ecore'), category: 'OCL-ECORE', type: 'OCL' },
    { file: path.join(MDE4CPP_HOME, 'src/examples/oclExamples/oclQueryEcoreModelExample/model/Library_QueryEcore.ecore'), category: 'OCL-ECORE', type: 'OCL' },
    { file: path.join(MDE4CPP_HOME, 'src/examples/oclExamples/TestSuite/oclUmlModelExample/model/Library_uml.uml'), category: 'OCL-UML', type: 'OCL' },
    { file: path.join(MDE4CPP_HOME, 'src/examples/PSSMExamples/PSSM_ComplexBehavior/model/PSSM_ComplexBehavior.uml'), category: 'PSSM', type: 'PSSM' },
    { file: path.join(MDE4CPP_HOME, 'src/examples/PSSMExamples/PSSM_HelloWorld/model/PSSM_HelloWorld.uml'), category: 'PSSM', type: 'PSSM' },
    { file: path.join(MDE4CPP_HOME, 'src/examples/PSSMExamples/PSSM_InternalTransition/model/PSSM_InternalTransition.uml'), category: 'PSSM', type: 'PSSM' },
    { file: path.join(MDE4CPP_HOME, 'src/examples/PSSMExamples/TestSuite/Test_Behavior_001/model/Test_Behavior_001.uml'), category: 'PSSM', type: 'PSSM' },
    { file: path.join(MDE4CPP_HOME, 'src/examples/UMLExamples/TestSuite/subsetUnion/model/simpleUML.uml'), category: 'UML', type: 'UML' },
    { file: path.join(MDE4CPP_HOME, 'src/examples/UMLExamples/UMLModelExample/model/LibraryModel_uml.uml'), category: 'UML', type: 'UML' }
];

const results = [];

async function checkHealth() {
    try {
        const response = await axios.get(`${API_BASE_URL.replace('/api/v1', '')}/api/v1/health`);
        return true;
    } catch (error) {
        return false;
    }
}

async function uploadFile(modelPath) {
    if (!fs.existsSync(modelPath)) {
        throw new Error(`File not found: ${modelPath}`);
    }
    
    const form = new FormData();
    form.append('file', fs.createReadStream(modelPath));
    
    const response = await axios.post(`${API_BASE_URL}/build`, form, {
        headers: form.getHeaders(),
        maxContentLength: Infinity,
        maxBodyLength: Infinity
    });
    
    return response.data.buildId;
}

async function checkStatus(buildId) {
    const response = await axios.get(`${API_BASE_URL}/build/${buildId}/status`);
    return response.data;
}

async function getFiles(buildId) {
    const response = await axios.get(`${API_BASE_URL}/build/${buildId}/files`);
    return response.data;
}

async function testModel(model) {
    const fileName = path.basename(model.file);
    console.log(`\n${'='.repeat(40)}`);
    console.log(`Testing: ${fileName} (${model.category})`);
    console.log('='.repeat(40));
    
    const result = {
        file: fileName,
        category: model.category,
        type: model.type,
        buildId: null,
        success: false,
        status: null,
        dlls: 0,
        exes: 0,
        duration: 0,
        failureReason: null,
        errorDetails: null
    };
    
    const startTime = Date.now();
    
    try {
        // Upload
        console.log('Uploading file to backend...');
        result.buildId = await uploadFile(model.file);
        console.log(`  Build ID: ${result.buildId}`);
        
        // Poll for status
        console.log('Waiting for build to complete...');
        const maxWaitTime = 600000; // 10 minutes
        const pollInterval = 3000; // 3 seconds
        const startPoll = Date.now();
        let buildComplete = false;
        
        while (Date.now() - startPoll < maxWaitTime && !buildComplete) {
            await new Promise(resolve => setTimeout(resolve, pollInterval));
            
            try {
                const status = await checkStatus(result.buildId);
                result.status = status.status;
                const elapsed = Math.floor((Date.now() - startPoll) / 1000);
                console.log(`  Status: ${status.status} (${elapsed}s)`);
                
                if (status.status === 'completed' || status.status === 'failed') {
                    buildComplete = true;
                    
                    if (status.status === 'completed') {
                        try {
                            const files = await getFiles(result.buildId);
                            result.dlls = files.dlls ? files.dlls.length : 0;
                            result.exes = files.executables ? files.executables.length : 0;
                            result.success = result.dlls > 0;
                            
                            if (result.success) {
                                console.log(`  [SUCCESS] Build completed!`);
                                console.log(`    DLLs: ${result.dlls}, EXEs: ${result.exes}`);
                            } else {
                                result.failureReason = 'Build completed but no DLLs found';
                                console.log(`  [FAIL] Build completed but no DLLs generated`);
                            }
                        } catch (error) {
                            result.failureReason = 'Could not retrieve file list';
                            result.errorDetails = error.message;
                            console.log(`  [FAIL] Could not get file list: ${error.message}`);
                        }
                    } else {
                        result.failureReason = 'Build failed';
                        result.errorDetails = status.error || 'Unknown error';
                        console.log(`  [FAIL] Build failed`);
                        if (result.errorDetails) {
                            const shortError = result.errorDetails.length > 100 
                                ? result.errorDetails.substring(0, 100) + '...' 
                                : result.errorDetails;
                            console.log(`    Error: ${shortError}`);
                        }
                    }
                }
            } catch (error) {
                console.log(`  Error checking status: ${error.message}`);
                // Continue polling
            }
        }
        
        if (!buildComplete) {
            result.failureReason = 'Build timeout';
            result.errorDetails = `Build did not complete within ${maxWaitTime / 1000} seconds`;
            console.log(`  [FAIL] Build timeout`);
        }
        
    } catch (error) {
        result.failureReason = 'Exception during test';
        result.errorDetails = error.message;
        console.log(`  [FAIL] Exception: ${error.message}`);
    }
    
    result.duration = Math.round((Date.now() - startTime) / 100) / 10; // Round to 1 decimal
    results.push(result);
    return result;
}

async function main() {
    console.log('\n' + '='.repeat(40));
    console.log('BACKEND API TEST SUITE');
    console.log('='.repeat(40));
    console.log(`Backend URL: ${API_BASE_URL}`);
    console.log(`MDE4CPP_HOME: ${MDE4CPP_HOME}`);
    
    // Check if backend is running
    console.log('\nChecking if backend is running...');
    const isHealthy = await checkHealth();
    if (!isHealthy) {
        console.log('  [FAIL] Backend is not running or not accessible');
        console.log('  Please start the backend server first:');
        console.log('    cd interface/backend');
        console.log('    npm start');
        process.exit(1);
    }
    console.log('  [OK] Backend is running');
    
    console.log(`\nTesting ${testModels.length} model files via backend API...`);
    console.log('This will take approximately 20-40 minutes (builds run sequentially)\n');
    
    const totalStart = Date.now();
    
    // Test each model sequentially
    for (const model of testModels) {
        await testModel(model);
    }
    
    const totalDuration = Math.round((Date.now() - totalStart) / 100) / 10;
    
    // Print summary
    console.log('\n' + '='.repeat(40));
    console.log('FINAL SUMMARY');
    console.log('='.repeat(40));
    
    const successful = results.filter(r => r.success).length;
    const failed = results.filter(r => !r.success && r.status !== 'skipped').length;
    const validTests = results.filter(r => r.status !== 'skipped');
    
    console.log('\n=== SUCCESSFUL BUILDS ===');
    const successfulTests = results.filter(r => r.success);
    if (successfulTests.length > 0) {
        successfulTests.forEach(test => {
            console.log(`[OK] ${test.file} (${test.category})`);
            console.log(`    Build ID: ${test.buildId}, DLLs: ${test.dlls}, EXEs: ${test.exes}, Duration: ${test.duration}s`);
        });
    } else {
        console.log('None');
    }
    
    console.log('\n=== FAILED BUILDS ===');
    const failedTests = results.filter(r => !r.success && r.status !== 'skipped');
    if (failedTests.length > 0) {
        failedTests.forEach(test => {
            console.log(`[FAIL] ${test.file} (${test.category})`);
            console.log(`    Build ID: ${test.buildId}`);
            console.log(`    Status: ${test.status}`);
            console.log(`    Reason: ${test.failureReason}`);
            if (test.errorDetails) {
                const shortDetails = test.errorDetails.length > 100 
                    ? test.errorDetails.substring(0, 100) + '...' 
                    : test.errorDetails;
                console.log(`    Error: ${shortDetails}`);
            }
        });
    } else {
        console.log('None');
    }
    
    console.log('\n=== STATISTICS ===');
    console.log(`Total Tests: ${validTests.length}`);
    if (validTests.length > 0) {
        const successPercent = Math.round((successful / validTests.length) * 100 * 10) / 10;
        const failPercent = Math.round((failed / validTests.length) * 100 * 10) / 10;
        console.log(`Successful: ${successful} - ${successPercent}%`);
        console.log(`Failed: ${failed} - ${failPercent}%`);
    }
    const totalDLLs = results.reduce((sum, r) => sum + r.dlls, 0);
    const totalEXEs = results.reduce((sum, r) => sum + r.exes, 0);
    console.log(`Total DLLs Generated: ${totalDLLs}`);
    console.log(`Total EXEs Generated: ${totalEXEs}`);
    const durationMin = Math.round(totalDuration / 60 * 10) / 10;
    console.log(`Total Duration: ${totalDuration}s (${durationMin} minutes)`);
    
    // Save results
    const timestamp = new Date().toISOString().replace(/[:.]/g, '-').slice(0, 19);
    const resultsFile = path.join(__dirname, `backend-api-test-results-${timestamp}.json`);
    fs.writeFileSync(resultsFile, JSON.stringify(results, null, 2));
    console.log(`\nResults saved to: ${resultsFile}`);
    
    console.log('\n' + '='.repeat(40));
    
    // Exit with appropriate code
    process.exit(failed > 0 ? 1 : 0);
}

main().catch(error => {
    console.error('Fatal error:', error);
    process.exit(1);
});
