#
#  MDE4CPP - Model Driven Engineering for C++
#
#  Copyright (c) TU Ilmenau, Systems and Software Engineering Group
#  All rights reserved.
#
#  MIT License
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy of this
#  software and associated documentation files (the "Software"), to deal in the Software
#  without restriction, including without limitation the rights to use, copy, modify, merge,
#  publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
#  to whom the Software is furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included in all copies or
#  substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED *AS IS*, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
#  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
#  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
#  FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
#  OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
#  DEALINGS IN THE SOFTWARE.
#

CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

PROJECT(pluginAPI)

IF(NOT CMAKE_BUILD_TYPE) 
    SET(CMAKE_BUILD_TYPE Debug)
ENDIF(NOT CMAKE_BUILD_TYPE)
SET(CMAKE_DEBUG_POSTFIX d)

SET(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "-Wall -Wno-overloaded-virtual -Wdeprecated-declarations -fmax-errors=5")
IF(APPLE)
  string(APPEND CMAKE_CXX_FLAGS " -Qunused-arguments")
ENDIF(APPLE)
SET(CMAKE_CXX_FLAGS_DEBUG " -Og -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE " -O3 -DNDEBUG")

#string(REPLACE "\\" "/" MDE4CPP_HOME $ENV{MDE4CPP_HOME})

SET(SOURCE_FILES
	MDE4CPP_PluginAPI.cpp
	MDE4CPP_PluginAPI_Main.cpp
	ModelInstance.cpp
	helperFunc.cpp
	pluginHandler.cpp
	json2ecore.cpp
	#ecore2json.cpp
)

INCLUDE_DIRECTORIES(
	../
	$ENV{MDE4CPP_HOME}/application/include
)
# Apple specific stuff
IF(APPLE)
  SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -undefined dynamic_lookup")
  SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -undefined dynamic_lookup")
ENDIF(APPLE)

IF(UNIX AND NOT APPLE)
    # for Linux, BSD, Solaris, Minix
	IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
		FIND_LIBRARY(PLUGINFRAMEWORK_DEBUG pluginFrameworkd.so $ENV{MDE4CPP_HOME}/application/bin)
	ELSE()
		FIND_LIBRARY(PLUGINFRAMEWORK_RELEASE pluginFramework.so $ENV{MDE4CPP_HOME}/application/bin)
	ENDIF()
ELSEIF(APPLE)
	IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
		FIND_LIBRARY(PLUGINFRAMEWORK_DEBUG pluginFrameworkd.dylib $ENV{MDE4CPP_HOME}/application/bin)
	ELSE()
		FIND_LIBRARY(PLUGINFRAMEWORK_RELEASE pluginFramework.dylib $ENV{MDE4CPP_HOME}/application/bin)
	ENDIF()
ELSE()
	IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
		FIND_LIBRARY(PLUGINFRAMEWORK_DEBUG pluginFrameworkd $ENV{MDE4CPP_HOME}/application/lib)
	ELSE()
		FIND_LIBRARY(PLUGINFRAMEWORK_RELEASE pluginFramework $ENV{MDE4CPP_HOME}/application/lib)
	ENDIF()
ENDIF()

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILES})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES PREFIX "")

IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
	TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		debug ${PLUGINFRAMEWORK_DEBUG}
	    debug ws2_32
	    debug wsock32
	)
ELSE()
	TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		optimized ${PLUGINFRAMEWORK_RELEASE}
	    optimized ws2_32
	    optimized wsock32
	)
ENDIF()


#-----------------------------------------------------
# DELIVERING binaries ${MDE4CPP_HOME}
#-----------------------------------------------------

INSTALL(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION $ENV{MDE4CPP_HOME}/application/bin
    LIBRARY DESTINATION $ENV{MDE4CPP_HOME}/application/bin
    ARCHIVE DESTINATION $ENV{MDE4CPP_HOME}/application/lib
)

# Interface are installed from gradle task "deliverPluginFrameworkInterface"
#INSTALL(DIRECTORY . DESTINATION ${MDE4CPP_HOME}/application/include/${PROJECT_NAME}
#	FILES_MATCHING PATTERN "*.hpp"
#	PATTERN ".cmake" EXCLUDE
#	PATTERN "impl" EXCLUDE
#)
