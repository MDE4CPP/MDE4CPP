@echo off

SET modelFolder=%cd%
SET modelFile=%modelFolder%/simpleUML.uml

REM Go to MDE4CPP home folder to call the gradle task 'generateModel'
REM Task 'generateModel' is defined in $MDE4CPP_HOME/src/common/universalGradleTasks/build.gradle
CD /D %MDE4CPP_HOME%

REM Call the task 'generateModel' with model path as parameter
REM generator will be detected automatically (UML4CPP is used because parameter SO (struktureOnly) is defined)
CALL gradlew generateModel -PModel=%modelFile% -PSO

REM Go back to model folder
CD /D %modelFolder%