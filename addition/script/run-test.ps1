# Simple test runner for build-model-workspace.ps1
# This will run the script and show what works and what doesn't

$MDE4CPP_HOME = "D:\DEV\test2\MDE4CPP"
$modelFile = "D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample\model\libraryModel_ecore.ecore"
$workspace = "D:\DEV\test2\MDE4CPP\test_workspace_run"

# Create workspace
New-Item -ItemType Directory -Path "$workspace\model" -Force | Out-Null
Copy-Item -Path $modelFile -Destination "$workspace\model\libraryModel_ecore.ecore" -Force

Write-Host "Running build script..." -ForegroundColor Cyan
Write-Host "Model: $modelFile" -ForegroundColor Yellow
Write-Host "Workspace: $workspace" -ForegroundColor Yellow
Write-Host ""

& "$MDE4CPP_HOME\addition\script\build-model-workspace.ps1" `
    -ModelFilePath "$workspace\model\libraryModel_ecore.ecore" `
    -WorkspacePath $workspace `
    -MDE4CPP_HOME $MDE4CPP_HOME

Write-Host "`nExit Code: $LASTEXITCODE" -ForegroundColor $(if ($LASTEXITCODE -eq 0) { "Green" } else { "Red" })
