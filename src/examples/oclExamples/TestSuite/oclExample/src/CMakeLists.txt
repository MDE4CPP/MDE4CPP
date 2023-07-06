#############################################################################
#																			#
#		 			CMakeList created manually								# 
#																			#
#############################################################################

CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

PROJECT(oclExample)

IF(NOT CMAKE_BUILD_TYPE) 
    SET(CMAKE_BUILD_TYPE Debug)
ENDIF(NOT CMAKE_BUILD_TYPE)

SET(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS "-Wall -Wno-overloaded-virtual -Wdeprecated-declarations -fmax-errors=5")
SET(CMAKE_CXX_FLAGS_DEBUG "-Og -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE " -O3 -DNDEBUG")

string(REPLACE "\\" "/" MDE4CPP_HOME $ENV{MDE4CPP_HOME})

SET(SOURCE_FILES
	main.cpp
)

INCLUDE_DIRECTORIES(
	${MDE4CPP_HOME}/application/include
)

# Apple specific stuff
IF(APPLE)
  SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -undefined dynamic_lookup")
  SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -undefined dynamic_lookup")
ENDIF(APPLE)

IF(UNIX AND NOT APPLE)
    # for Linux, BSD, Solaris, Minix
	IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
		FIND_LIBRARY(ECORE_DEBUG ecored.so ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(UML_DEBUG umld.so ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(TYPES_DEBUG typesd.so ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(PRIMITIVETYPESREFLECTION_DEBUG primitivetypesReflectiond.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(OCLPARSER_DEBUG oclParserd.so ${MDE4CPP_HOME}/application/bin)
	ELSE()
		FIND_LIBRARY(ECORE_RELEASE ecore.so ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(UML_RELEASE uml.so ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(TYPES_RELEASE types.so ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(PRIMITIVETYPESREFLECTION_RELEASE primitivetypesReflection.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(OCLPARSER_RELEASE oclParser.so ${MDE4CPP_HOME}/application/bin)
	ENDIF()
ELSEIF(APPLE)
	IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
		FIND_LIBRARY(ECORE_DEBUG ecored.dylib ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(UML_DEBUG umld.dylib ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(TYPES_DEBUG typesd.dylib ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(PRIMITIVETYPESREFLECTION_DEBUG primitivetypesReflectiond.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(OCLPARSER_DEBUG oclParserd.dylib ${MDE4CPP_HOME}/application/bin)
	ELSE()
		FIND_LIBRARY(ECORE_RELEASE ecore.dylib ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(UML_RELEASE uml.dylib ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(TYPES_RELEASE types.dylib ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(PRIMITIVETYPESREFLECTION_RELEASE primitivetypesReflection.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(OCLPARSER_RELEASE oclParser.dylib ${MDE4CPP_HOME}/application/bin)
	ENDIF()
ELSE()
	IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
		FIND_LIBRARY(ECORE_DEBUG ecored ${MDE4CPP_HOME}/application/lib)
		#FIND_LIBRARY(UML_DEBUG umld ${MDE4CPP_HOME}/application/lib)
		#FIND_LIBRARY(TYPES_DEBUG typesd ${MDE4CPP_HOME}/application/lib)
		#FIND_LIBRARY(PRIMITIVETYPESREFLECTION_DEBUG primitivetypesReflectiond ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(OCLPARSER_DEBUG oclParserd ${MDE4CPP_HOME}/application/lib)
	ELSE()
		FIND_LIBRARY(ECORE_RELEASE ecore ${MDE4CPP_HOME}/application/lib)
		#FIND_LIBRARY(UML_RELEASE uml ${MDE4CPP_HOME}/application/lib)
		#FIND_LIBRARY(TYPES_RELEASE types ${MDE4CPP_HOME}/application/lib)
		#FIND_LIBRARY(PRIMITIVETYPESREFLECTION_RELEASE primitivetypesReflection ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(OCLPARSER_RELEASE oclParser ${MDE4CPP_HOME}/application/lib)
	ENDIF()
ENDIF()


ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILES})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")

IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} 	
		debug ${ECORE_DEBUG}
		#debug ${UML_DEBUG}
		#debug ${TYPES_DEBUG}
		#debug ${PRIMITIVETYPESREFLECTION_DEBUG}
		debug ${OCLPARSER_DEBUG}
	)
ELSE()
	TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		optimized ${ECORE_RELEASE}
		#optimized ${UML_RELEASE}
		#optimized ${TYPES_RELEASE}
		#optimized ${PRIMITIVETYPESREFLECTION_RELEASE}
		optimized ${OCLPARSER_RELEASE}
	)
ENDIF()

#-----------------------------------------------------
# DELIVERING binaries and header to ${MDE4CPP_HOME}
#-----------------------------------------------------

INSTALL(TARGETS ${PROJECT_NAME} 
	RUNTIME DESTINATION ${MDE4CPP_HOME}/application/bin
)