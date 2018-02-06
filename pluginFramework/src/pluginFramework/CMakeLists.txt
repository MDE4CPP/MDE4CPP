# C++ project of PluginFramework

CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

if(UNIX AND NOT APPLE)
    # for Linux, BSD, Solaris, Minix
	SET(CMAKE_C_COMPILER "gcc")
	SET(CMAKE_CXX_COMPILER "g++")
else()
   SET(CMAKE_C_COMPILER "gcc.exe")
   SET(CMAKE_CXX_COMPILER "g++.exe")
endif()

PROJECT(pluginFramework)

IF(NOT CMAKE_BUILD_TYPE) 
    SET(CMAKE_BUILD_TYPE Debug)
ENDIF(NOT CMAKE_BUILD_TYPE)
SET(CMAKE_DEBUG_POSTFIX d)

SET(CMAKE_CXX_STANDARD 14)
SET(GCC_COVERAGE_LINK_FLAGS "-fopenmp")
SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wno-overloaded-virtual -Wdeprecated-declarations -fopenmp -fmax-errors=5")
SET(CMAKE_CXX_FLAGS_DEBUG " -Og -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE " -O3 -DNDEBUG")

string(REPLACE "\\" "/" MDE4CPP_HOME $ENV{MDE4CPP_HOME})

SET(SOURCE_FILES
	PluginFramework.cpp
	impl/PluginFrameworkImpl.cpp
)

INCLUDE_DIRECTORIES(
	../
	${MDE4CPP_HOME}/application/include
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

INSTALL(DIRECTORY . DESTINATION ${MDE4CPP_HOME}/application/include/${PROJECT_NAME}
	FILES_MATCHING PATTERN "*.hpp"
	PATTERN ".cmake" EXCLUDE
)