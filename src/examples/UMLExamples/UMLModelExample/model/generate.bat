@echo off

SET modelFolder=%cd%
SET modelFile=%modelFolder%/LibraryModel_uml.uml

:: Go to folder, in which the gradle task 'generateModel' is callable, e.g. the MDE4CPP home folder
:: 'generateModel' is defined in %MDE4CPP_HOME%/src/common/universalGradleTasks/build.gradle
CD /D %MDE4CPP_HOME%

:: Call the gradle task with model path as parameter
:: Parameter SO indicates to use the generator 'UML4CPP'
CALL gradlew generateModel -PModel=%modelFile% -PSO

:: Go back to initial folder
CD /D %modelFolder%