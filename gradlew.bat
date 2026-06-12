@echo off
setlocal

REM Auto-load the environment variables if available
if exist "%~dp0setenv.bat" call "%~dp0setenv.bat"

REM Delegate to the actual Gradle wrapper located in application/tools
call "%~dp0application\tools\gradlew.bat" %*

endlocal
exit /b %errorlevel%
