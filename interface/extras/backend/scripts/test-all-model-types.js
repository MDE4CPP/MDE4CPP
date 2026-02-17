#!/usr/bin/env node

/**
 * Comprehensive test script for all model types
 * Tests ECORE, UML, fUML, PSSM, PSCS, and OCL models
 * Logs all results and issues for script improvement
 */

const axios = require('axios');
const FormData = require('form-data');
const fs = require('fs');
const path = require('path');

const API_BASE_URL = process.env.API_URL || 'http://localhost:8000/api/v1';
const MDE4CPP_HOME = process.env.MDE4CPP_HOME || path.resolve(__dirname, '../../../..');
const TEST_RESULTS_FILE = path.join(__dirname, 'test-results-all-models.json');
const TEST_LOG_FILE = path.join(__dirname, 'test-log-all-models.txt');

// Test models organized by type
const testModels = {
    ECORE: [
        { path: 'src/examples/ecoreExamples/ecoreModelExample/model/libraryModel_ecore.ecore', name: 'LibraryModel_ecore', category: 'Example' },
        { path: 'src/examples/ecoreExamples/ecoreAnnotationsExample/model/ecoreAnnotationsExample.ecore', name: 'EcoreAnnotationsExample', category: 'Example' },
        { path: 'src/examples/ecoreExamples/TestSuite/copyTest/model/copyTest.ecore', name: 'CopyTest', category: 'TestSuite' },
        { path: 'src/examples/ecoreExamples/TestSuite/SubsetUnionExample/SubsetUnion/model/subsetUnion.ecore', name: 'SubsetUnion', category: 'TestSuite' },
    ],
    UML: [
        { path: 'src/examples/UMLExamples/UMLModelExample/model/LibraryModel_uml.uml', name: 'LibraryModel_uml', category: 'Example' },
        { path: 'src/examples/UMLExamples/TestSuite/copyTestUML/model/copyTestUML.uml', name: 'copyTestUML', category: 'TestSuite' },
    ],
    fUML: [
        { path: 'src/examples/fUMLExamples/Calculator/model/CalcModel.uml', name: 'CalcModel', category: 'Example' },
        { path: 'src/examples/fUMLExamples/ThreePhilosophers/model/philosophers.uml', name: 'Philosophers', category: 'Example' },
        { path: 'src/examples/fUMLExamples/TestSuite/ActionTest/model/ActionTest.uml', name: 'ActionTest', category: 'TestSuite' },
        { path: 'src/examples/fUMLExamples/TestSuite/ForkNodeTest/model/forkNodeTest.uml', name: 'ForkNodeTest', category: 'TestSuite' },
    ],
    PSSM: [
        { path: 'src/examples/PSSMExamples/PSSM_HelloWorld/model/PSSM_HelloWorld.uml', name: 'PSSM_HelloWorld', category: 'Example' },
        { path: 'src/examples/PSSMExamples/PSSM_Composite/model/PSSM_Composite.uml', name: 'PSSM_Composite', category: 'Example' },
        { path: 'src/examples/PSSMExamples/VendingMachine/model/VendingMachine.uml', name: 'VendingMachine', category: 'Example' },
        { path: 'src/examples/PSSMExamples/TestSuite/Test_Behavior_001/model/Test_Behavior_001.uml', name: 'Test_Behavior_001', category: 'TestSuite' },
    ],
    PSCS: [
        { path: 'src/examples/PSCSExamples/TestSuite/01_Inst_01_AssemCon_P_P/model/AssemCon_P_P.uml', name: 'AssemCon_P_P', category: 'TestSuite' },
        { path: 'src/examples/PSCSExamples/TestSuite/01_Inst_04_DefaultValue_BasicTypes/model/DefaultValue_BasicTypes.uml', name: 'DefaultValue_BasicTypes', category: 'TestSuite' },
        { path: 'src/examples/PSCSExamples/TestSuite/02_Comm_01_LossOfMessages_Op/model/LossOfMessages_Op.uml', name: 'LossOfMessages_Op', category: 'TestSuite' },
    ],
    OCL: [
        { path: 'src/examples/oclExamples/oclEcoreModelExample/model/Library_ecore.ecore', name: 'Library_ecore', category: 'Example' },
        { path: 'src/examples/oclExamples/oclQueryEcoreModelExample/model/Library_QueryEcore.ecore', name: 'Library_QueryEcore', category: 'Example' },
        { path: 'src/examples/oclExamples/Connect4/model/Connect4.uml', name: 'Connect4', category: 'Example' },
    ]
};

const results = {
    startTime: new Date().toISOString(),
    totalTests: 0,
    passed: 0,
    failed: 0,
    skipped: 0,
    tests: [],
    summary: {
        ECORE: { total: 0, passed: 0, failed: 0 },
        UML: { total: 0, passed: 0, failed: 0 },
        fUML: { total: 0, passed: 0, failed: 0 },
        PSSM: { total: 0, passed: 0, failed: 0 },
        PSCS: { total: 0, passed: 0, failed: 0 },
        OCL: { total: 0, passed: 0, failed: 0 }
    }
};

// Logging functions
function log(message, toFile = true) {
    const timestamp = new Date().toISOString();
    const logMessage = `[${timestamp}] ${message}`;
    console.log(logMessage);
    if (toFile) {
        fs.appendFileSync(TEST_LOG_FILE, logMessage + '\n');
    }
}

function logError(message, error, toFile = true) {
    const timestamp = new Date().toISOString();
    const errorMessage = `[${timestamp}] ERROR: ${message}`;
    console.error(errorMessage);
    if (error) {
        console.error(error.stack || error.message);
    }
    if (toFile) {
        fs.appendFileSync(TEST_LOG_FILE, errorMessage + '\n');
        if (error) {
            fs.appendFileSync(TEST_LOG_FILE, (error.stack || error.message) + '\n');
        }
    }
}

/**
 * Upload file and start build
 */
async function uploadFile(filePath) {
    if (!fs.existsSync(filePath)) {
        throw new Error(`File not found: ${filePath}`);
    }
    
    const form = new FormData();
    form.append('file', fs.createReadStream(filePath));
    
    const response = await axios.post(`${API_BASE_URL}/build`, form, {
        headers: form.getHeaders(),
        maxContentLength: Infinity,
        maxBodyLength: Infinity,
        timeout: 30000
    });
    
    return response.data.buildId;
}

/**
 * Wait for build to complete
 */
async function waitForBuild(buildId, timeoutSeconds = 600) {
    const startTime = Date.now();
    const timeout = timeoutSeconds * 1000;
    
    while (true) {
        try {
            const response = await axios.get(`${API_BASE_URL}/build/${buildId}/status`);
            const build = response.data;
            
            if (build.status === 'completed') {
                return { success: true, build };
            }
            
            if (build.status === 'failed') {
                return { success: false, build, error: build.message || 'Build failed' };
            }
            
            // Check timeout
            if (Date.now() - startTime > timeout) {
                return { success: false, build, error: 'Build timeout' };
            }
            
            // Wait before next check
            await new Promise(resolve => setTimeout(resolve, 2000));
        } catch (error) {
            if (error.response && error.response.status === 404) {
                return { success: false, error: 'Build not found' };
            }
            throw error;
        }
    }
}

/**
 * Get build logs
 */
async function getBuildLogs(buildId, tail = 50) {
    try {
        const response = await axios.get(`${API_BASE_URL}/build/${buildId}/logs?tail=${tail}`);
        return response.data.logs || [];
    } catch (error) {
        return [];
    }
}

/**
 * Test a single model
 */
async function testModel(modelType, model) {
    const fullPath = path.join(MDE4CPP_HOME, model.path);
    const testResult = {
        type: modelType,
        name: model.name,
        category: model.category,
        file: model.path,
        status: 'unknown',
        buildId: null,
        duration: 0,
        outputFiles: null,
        errors: [],
        logs: [],
        issues: []
    };
    
    log(`\n${'='.repeat(80)}`);
    log(`Testing ${modelType} - ${model.name} (${model.category})`);
    log(`File: ${model.path}`);
    log(`${'='.repeat(80)}`);
    
    const startTime = Date.now();
    
    try {
        // Check if file exists
        if (!fs.existsSync(fullPath)) {
            testResult.status = 'skipped';
            testResult.issues.push(`File not found: ${fullPath}`);
            log(`SKIPPED: File not found`);
            results.skipped++;
            return testResult;
        }
        
        results.totalTests++;
        results.summary[modelType].total++;
        
        // Upload file
        log(`Uploading file...`);
        const buildId = await uploadFile(fullPath);
        testResult.buildId = buildId;
        log(`Build started: ${buildId}`);
        
        // Wait for build
        log(`Waiting for build to complete...`);
        const buildResult = await waitForBuild(buildId, 600);
        testResult.duration = Math.round((Date.now() - startTime) / 1000);
        
        if (buildResult.success) {
            testResult.status = 'passed';
            testResult.outputFiles = buildResult.build.outputFiles;
            log(`✓ PASSED in ${testResult.duration}s`);
            log(`  DLLs: ${buildResult.build.outputFiles?.dlls?.length || 0}`);
            log(`  Executables: ${buildResult.build.outputFiles?.executables?.length || 0}`);
            results.passed++;
            results.summary[modelType].passed++;
        } else {
            testResult.status = 'failed';
            testResult.errors.push(buildResult.error || 'Build failed');
            if (buildResult.build?.errors) {
                testResult.errors.push(...buildResult.build.errors.map(e => e.message));
            }
            log(`✗ FAILED: ${buildResult.error}`);
            results.failed++;
            results.summary[modelType].failed++;
        }
        
        // Get logs
        const logs = await getBuildLogs(buildId, 100);
        testResult.logs = logs.map(l => l.message).slice(-20); // Last 20 log lines
        
    } catch (error) {
        testResult.status = 'failed';
        testResult.duration = Math.round((Date.now() - startTime) / 1000);
        testResult.errors.push(error.message);
        if (error.response) {
            testResult.errors.push(`HTTP ${error.response.status}: ${JSON.stringify(error.response.data)}`);
        }
        logError(`Test failed with exception:`, error);
        results.failed++;
        results.summary[modelType].failed++;
    }
    
    return testResult;
}

/**
 * Main test function
 */
async function runTests() {
    // Initialize log file
    fs.writeFileSync(TEST_LOG_FILE, `MDE4CPP Model Type Testing\n`);
    fs.appendFileSync(TEST_LOG_FILE, `Started: ${results.startTime}\n`);
    fs.appendFileSync(TEST_LOG_FILE, `MDE4CPP_HOME: ${MDE4CPP_HOME}\n`);
    fs.appendFileSync(TEST_LOG_FILE, `API URL: ${API_BASE_URL}\n`);
    fs.appendFileSync(TEST_LOG_FILE, `${'='.repeat(80)}\n\n`);
    
    log(`Starting comprehensive model type testing...`);
    log(`MDE4CPP_HOME: ${MDE4CPP_HOME}`);
    log(`API URL: ${API_BASE_URL}`);
    log(`Total models to test: ${Object.values(testModels).flat().length}`);
    
    // Test each model type
    for (const [modelType, models] of Object.entries(testModels)) {
        log(`\n${'#'.repeat(80)}`);
        log(`Testing ${modelType} Models (${models.length} models)`);
        log(`${'#'.repeat(80)}`);
        
        for (const model of models) {
            const result = await testModel(modelType, model);
            results.tests.push(result);
            
            // Save results after each test
            results.endTime = new Date().toISOString();
            fs.writeFileSync(TEST_RESULTS_FILE, JSON.stringify(results, null, 2));
        }
    }
    
    // Final summary
    results.endTime = new Date().toISOString();
    
    log(`\n${'='.repeat(80)}`);
    log(`TEST SUMMARY`);
    log(`${'='.repeat(80)}`);
    log(`Total Tests: ${results.totalTests}`);
    log(`Passed: ${results.passed} (${Math.round(results.passed / results.totalTests * 100)}%)`);
    log(`Failed: ${results.failed} (${Math.round(results.failed / results.totalTests * 100)}%)`);
    log(`Skipped: ${results.skipped}`);
    log(`\nBy Type:`);
    
    for (const [type, summary] of Object.entries(results.summary)) {
        if (summary.total > 0) {
            log(`  ${type}: ${summary.passed}/${summary.total} passed`);
        }
    }
    
    // Save final results
    fs.writeFileSync(TEST_RESULTS_FILE, JSON.stringify(results, null, 2));
    
    log(`\nResults saved to: ${TEST_RESULTS_FILE}`);
    log(`Log saved to: ${TEST_LOG_FILE}`);
    
    // Print failed tests
    const failedTests = results.tests.filter(t => t.status === 'failed');
    if (failedTests.length > 0) {
        log(`\n${'='.repeat(80)}`);
        log(`FAILED TESTS (${failedTests.length}):`);
        log(`${'='.repeat(80)}`);
        failedTests.forEach(test => {
            log(`\n${test.type} - ${test.name}:`);
            log(`  File: ${test.file}`);
            if (test.errors.length > 0) {
                log(`  Errors:`);
                test.errors.forEach(err => log(`    - ${err}`));
            }
            if (test.issues.length > 0) {
                log(`  Issues:`);
                test.issues.forEach(issue => log(`    - ${issue}`));
            }
        });
    }
    
    return results;
}

// Run tests
if (require.main === module) {
    runTests()
        .then(results => {
            process.exit(results.failed > 0 ? 1 : 0);
        })
        .catch(error => {
            logError('Fatal error running tests:', error);
            process.exit(1);
        });
}

module.exports = { runTests, testModels };
