#############################################################################
#																	        #
#		 			Manually edited CMakeList             					# 
#																	        #
#############################################################################

CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

PROJECT(oclParser)

IF(NOT CMAKE_BUILD_TYPE) 
    SET(CMAKE_BUILD_TYPE Debug)
ENDIF(NOT CMAKE_BUILD_TYPE)
SET(CMAKE_DEBUG_POSTFIX d)

SET(CMAKE_CXX_STANDARD 17)

IF(("$ENV{DEBUG_MESSAGE_OCLPARSER}" EQUAL "1") AND (CMAKE_BUILD_TYPE MATCHES Debug))
	SET(ENABLED_DEBUG_MESSAGE " ")
ELSE()
	SET(ENABLED_DEBUG_MESSAGE " -DNDEBUG")
ENDIF()
IF("$ENV{DEBUG_MESSAGE_ACTIVITY_DEBUGGER}" EQUAL "1")
	SET(ENABLED_DEBUG_MESSAGE "${ENABLED_DEBUG_MESSAGE} -DACTIVITY_DEBUG_ON")
ENDIF()

SET(CMAKE_CXX_FLAGS "-Wall -Wno-overloaded-virtual -Wdeprecated-declarations -fmax-errors=5")
IF(APPLE)
  string(APPEND CMAKE_CXX_FLAGS " -Qunused-arguments")
ENDIF(APPLE)
SET(CMAKE_CXX_FLAGS_DEBUG " -Og -ggdb ${ENABLED_DEBUG_MESSAGE}")
SET(CMAKE_CXX_FLAGS_RELEASE " -O3  ${ENABLED_DEBUG_MESSAGE}")

string(REPLACE "\\" "/" MDE4CPP_HOME "$ENV{MDE4CPP_HOME}")

SET(SOURCE_FILES
# Utilities
	Utilities/OclConversion.cpp
	Utilities/OclEcore.cpp
	#Utilities/OclUml.cpp
# OclCS
    OclCS/OclFragments.cpp
    OclCS/OclLexer.cpp
    OclCS/OclParser.cpp
    OclCS/OclParserBaseVisitor.cpp
    OclCS/OclParserCustomVisitor.cpp
    OclCS/OclParserVisitor.cpp
# Eval
	Eval/EcoreEval.cpp
	Eval/EcoreEnvironment.cpp
)

INCLUDE_DIRECTORIES(
	../
	${MDE4CPP_HOME}/application/include
	${MDE4CPP_HOME}/application/include/antlr4-runtime
)

# Apple specific stuff
if(APPLE)
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -undefined dynamic_lookup")
  set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -undefined dynamic_lookup")
endif(APPLE)

IF(UNIX AND NOT APPLE)
    # for Linux, BSD, Solaris, Minix
	IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
		FIND_LIBRARY(ECORE_DEBUG ecored.so ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(FUML_DEBUG fUMLd.so ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(TYPES_DEBUG typesd.so ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(UML_DEBUG umld.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(PLUGINFRAMEWORK_DEBUG pluginFrameworkd.so ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(PRIMITIVETYPESREFLECTION_DEBUG primitivetypesReflectiond.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(OCL_DEBUG ocld.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(ANTLR_DEBUG libantlr4-runtime.so ${MDE4CPP_HOME}/application/bin)
	ELSE()
		FIND_LIBRARY(ECORE_RELEASE ecore.so ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(FUML_RELEASE fUML.so ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(TYPES_RELEASE types.so ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(UML_RELEASE uml.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(PLUGINFRAMEWORK_RELEASE pluginFramework.so ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(PRIMITIVETYPESREFLECTION_RELEASE primitivetypesReflection.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(OCL_RELEASE ocl.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(ANTLR_RELEASE libantlr4-runtime.so ${MDE4CPP_HOME}/application/bin)
	ENDIF()
ELSEIF(APPLE)
	IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
		FIND_LIBRARY(ECORE_DEBUG ecored.dylib ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(FUML_DEBUG fUMLd.dylib ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(TYPES_DEBUG typesd.dylib ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(UML_DEBUG umld.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(PLUGINFRAMEWORK_DEBUG pluginFrameworkd.dylib ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(PRIMITIVETYPESREFLECTION_DEBUG primitivetypesReflectiond.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(OCL_DEBUG ocld.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(ANTLR_DEBUG libantlr4-runtime.dylib ${MDE4CPP_HOME}/application/bin)
	ELSE()
		FIND_LIBRARY(ECORE_RELEASE ecore.dylib ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(FUML_RELEASE fUML.dylib ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(TYPES_RELEASE types.dylib ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(UML_RELEASE uml.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(PLUGINFRAMEWORK_RELEASE pluginFramework.dylib ${MDE4CPP_HOME}/application/bin)
		#FIND_LIBRARY(PRIMITIVETYPESREFLECTION_RELEASE primitivetypesReflection.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(OCL_RELEASE ocl.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(ANTLR_RELEASE libantlr4-runtime.dylib ${MDE4CPP_HOME}/application/bin)
	ENDIF()
ELSE()
	IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
		FIND_LIBRARY(ECORE_DEBUG ecored ${MDE4CPP_HOME}/application/lib)
		#FIND_LIBRARY(FUML_DEBUG fUMLd ${MDE4CPP_HOME}/application/lib)
		#FIND_LIBRARY(TYPES_DEBUG typesd ${MDE4CPP_HOME}/application/lib)
		#FIND_LIBRARY(UML_DEBUG umld ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(PLUGINFRAMEWORK_DEBUG pluginFrameworkd ${MDE4CPP_HOME}/application/lib)
		#FIND_LIBRARY(PRIMITIVETYPESREFLECTION_DEBUG primitivetypesReflectiond ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(OCL_DEBUG ocld ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(ANTLR_DEBUG antlr4-runtime ${MDE4CPP_HOME}/application/lib)
	ELSE()
		FIND_LIBRARY(ECORE_RELEASE ecore ${MDE4CPP_HOME}/application/lib)
		#FIND_LIBRARY(FUML_RELEASE fUML ${MDE4CPP_HOME}/application/lib)
		#FIND_LIBRARY(TYPES_RELEASE types ${MDE4CPP_HOME}/application/lib)
		#FIND_LIBRARY(UML_RELEASE uml ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(PLUGINFRAMEWORK_RELEASE pluginFramework ${MDE4CPP_HOME}/application/lib)
		#FIND_LIBRARY(PRIMITIVETYPESREFLECTION_RELEASE primitivetypesReflection ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(OCL_RELEASE ocl ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(ANTLR_RELEASE antlr4-runtime ${MDE4CPP_HOME}/application/lib)
	ENDIF()
ENDIF()

ADD_LIBRARY(${PROJECT_NAME} SHARED ${SOURCE_FILES})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES PREFIX "")

IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
	TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		debug ${ECORE_DEBUG}
		#debug ${FUML_DEBUG}
		#debug ${TYPES_DEBUG}
		#debug ${UML_DEBUG}
		debug ${PLUGINFRAMEWORK_DEBUG}
		#debug ${PRIMITIVETYPESREFLECTION_DEBUG}
		debug ${OCL_DEBUG}
		debug ${ANTLR_DEBUG}
	)
ELSE()
	TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		optimized ${ECORE_RELEASE}
		#optimized ${FUML_RELEASE}
		#optimized ${TYPES_RELEASE}
		#optimized ${UML_RELEASE}
		optimized ${PLUGINFRAMEWORK_RELEASE}
		#optimized ${PRIMITIVETYPESREFLECTION_RELEASE}
		optimized ${OCL_RELEASE}
		optimized ${ANTLR_RELEASE}
	)
ENDIF()

#-----------------------------------------------------
# DELIVERING binaries and header to ${MDE4CPP_HOME}
#-----------------------------------------------------

INSTALL(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION ${MDE4CPP_HOME}/application/bin
    LIBRARY DESTINATION ${MDE4CPP_HOME}/application/bin
    ARCHIVE DESTINATION ${MDE4CPP_HOME}/application/lib
)

INSTALL(DIRECTORY . DESTINATION ${MDE4CPP_HOME}/application/include/${PROJECT_NAME}
	FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h"
	PATTERN ".cmake" EXCLUDE
	PATTERN "src" EXCLUDE
)
