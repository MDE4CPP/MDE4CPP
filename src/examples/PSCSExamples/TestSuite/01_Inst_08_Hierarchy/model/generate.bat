@echo off

SET modelFolder=%cd%
SET modelFile=%modelFolder%/Hierarchy.uml

REM Go to MDE4CPP home folder to call the gradle task 'generateModel'
REM Task 'generateModel' is defined in $MDE4CPP_HOME/src/common/universalGradleTasks/build.gradle
CD /D %MDE4CPP_HOME%

REM Call the task 'generateModel' with model path as parameter
REM generator will be detected automatically (fUML4CPP is used here)
CALL gradlew generateModel -PModel=%modelFile%

:: Go back to initial folder
CD /D %modelFolder%