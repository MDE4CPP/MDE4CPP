# C++ project of PluginFramework

CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

SET(CMAKE_C_COMPILER "gcc.exe")
SET(CMAKE_CXX_COMPILER "g++.exe")

PROJECT(PluginFramework)

IF(NOT CMAKE_BUILD_TYPE) 
    SET(CMAKE_BUILD_TYPE Debug)
ENDIF(NOT CMAKE_BUILD_TYPE)
SET(CMAKE_DEBUG_POSTFIX d)

SET(CMAKE_CXX_STANDARD 14)
SET(GCC_COVERAGE_LINK_FLAGS "-fopenmp")
SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wno-overloaded-virtual -Wdeprecated-declarations -fopenmp -fmax-errors=5")
SET(CMAKE_CXX_FLAGS_DEBUG " -Og")
SET(CMAKE_CXX_FLAGS_RELEASE " -O3 -DNDEBUG")

string(REPLACE "\\" "/" MDE4CPP_HOME $ENV{MDE4CPP_HOME})

SET(SOURCE_FILES
	src/PluginFramework.cpp
)

INCLUDE_DIRECTORIES(
	src
	$ENV{MDE4CPP_HOME}/application/include
)

ADD_LIBRARY(${PROJECT_NAME} SHARED ${SOURCE_FILES})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES PREFIX "")

#-----------------------------------------------------
# DELIVERING binaries and header to ${MDE4CPP_HOME}
#-----------------------------------------------------

INSTALL(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION ${MDE4CPP_HOME}/application/bin
    LIBRARY DESTINATION ${MDE4CPP_HOME}/application/bin
    ARCHIVE DESTINATION ${MDE4CPP_HOME}/application/lib
)

INSTALL(FILES 
	src/EcoreModelPlugin.hpp
	src/MDE4CPPPlugin.hpp
	src/PluginFramework.hpp
	src/UMLExecutionModelPlugin.hpp
	src/UMLModelPlugin.hpp
	DESTINATION ${MDE4CPP_HOME}/application/include/${PROJECT_NAME}
)