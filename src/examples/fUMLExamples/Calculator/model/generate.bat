@echo off

SET modelFolder=%cd%
SET modelFile=%modelFolder%/CalcModel.uml

:: Go to folder, in which the gradle task 'generateModel' is callable, e.g. the MDE4CPP home folder
:: 'generateModel' is defined in %MDE4CPP_HOME%/src/common/universalGradleTasks/build.gradle
CD /D %MDE4CPP_HOME%

:: Call the gradle task with model path as parameter
:: 'FUML4CPP' will be used. To use 'UML4CPP' add parameter -PSO
CALL gradle generateModel -PModel=%modelFile%

:: Go back to initial folder
CD /D %modelFolder%