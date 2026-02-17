# Test operation execution for Library_ecore
Write-Host "Testing Library_ecore operation execution..." -ForegroundColor Cyan

# 1. Check capabilities
Write-Host "`n1. Checking capabilities..." -ForegroundColor Yellow
try {
    $caps = Invoke-RestMethod -Uri "http://localhost:8080/Library_ecore/capabilities" -Method GET
    Write-Host "   invoke.supported: $($caps.invoke.supported)" -ForegroundColor Green
    Write-Host "   invoke.via: $($caps.invoke.via)" -ForegroundColor Green
    if (-not $caps.invoke.supported) {
        Write-Host "   ERROR: invoke not supported!" -ForegroundColor Red
        exit 1
    }
} catch {
    Write-Host "   ERROR: Could not connect to C++ API: $_" -ForegroundColor Red
    exit 1
}

# 2. Create Library instance via Node backend
Write-Host "`n2. Creating Library instance..." -ForegroundColor Yellow
try {
    $lib = Invoke-RestMethod -Uri "http://localhost:8001/api/v1/plugins/Library_ecore/classifiers/Library/create" -Method POST -ContentType "application/json" -Body '{"instanceName": "testLib", "properties": {"name": "Test Library"}}'
    Write-Host "   Created: $($lib.object.id)" -ForegroundColor Green
    $libId = $lib.object.id
} catch {
    Write-Host "   ERROR: Could not create Library: $_" -ForegroundColor Red
    exit 1
}

# 3. Create Book child
Write-Host "`n3. Creating Book child..." -ForegroundColor Yellow
try {
    $book = Invoke-RestMethod -Uri "http://localhost:8001/api/v1/plugins/Library_ecore/objects/$libId/children/Book/testBook" -Method POST -ContentType "application/json" -Body '{"referenceID": 3, "properties": {"title": "Test Book", "copies": 10}}'
    Write-Host "   Created Book: testBook" -ForegroundColor Green
} catch {
    Write-Host "   ERROR: Could not create Book: $_" -ForegroundColor Red
    exit 1
}

# 4. Invoke countCopies operation
Write-Host "`n4. Invoking countCopies operation..." -ForegroundColor Yellow
try {
    $result = Invoke-RestMethod -Uri "http://localhost:8001/api/v1/plugins/objects/testBook/invoke/countCopies" -Method POST -ContentType "application/json" -Body '{"arguments": []}'
    Write-Host "   Result: $($result.result)" -ForegroundColor Green
    Write-Host "   Success: $($result.success)" -ForegroundColor Green
    Write-Host "   Fallback: $($result.fallback)" -ForegroundColor $(if ($result.fallback) { "Yellow" } else { "Green" })
    if ($result.fallback) {
        Write-Host "   WARNING: Operation returned fallback result (not executed)" -ForegroundColor Yellow
    } else {
        Write-Host "   SUCCESS: Operation executed!" -ForegroundColor Green
    }
} catch {
    Write-Host "   ERROR: Could not invoke operation: $_" -ForegroundColor Red
    exit 1
}

# 5. Invoke addCopies operation
Write-Host "`n5. Invoking addCopies operation..." -ForegroundColor Yellow
try {
    $result2 = Invoke-RestMethod -Uri "http://localhost:8001/api/v1/plugins/objects/testBook/invoke/addCopies" -Method POST -ContentType "application/json" -Body '{"arguments": [5]}'
    Write-Host "   Result: $($result2.result)" -ForegroundColor Green
    Write-Host "   Success: $($result2.success)" -ForegroundColor Green
    Write-Host "   Fallback: $($result2.fallback)" -ForegroundColor $(if ($result2.fallback) { "Yellow" } else { "Green" })
    if ($result2.fallback) {
        Write-Host "   WARNING: Operation returned fallback result (not executed)" -ForegroundColor Yellow
    } else {
        Write-Host "   SUCCESS: Operation executed!" -ForegroundColor Green
    }
} catch {
    Write-Host "   ERROR: Could not invoke operation: $_" -ForegroundColor Red
    exit 1
}

# 6. Check if C++ API is still running
Write-Host "`n6. Verifying C++ API is still running..." -ForegroundColor Yellow
try {
    $caps2 = Invoke-RestMethod -Uri "http://localhost:8080/Library_ecore/capabilities" -Method GET
    Write-Host "   C++ API is still running!" -ForegroundColor Green
} catch {
    Write-Host "   ERROR: C++ API crashed or stopped!" -ForegroundColor Red
    exit 1
}

Write-Host "`nTest completed!" -ForegroundColor Cyan
