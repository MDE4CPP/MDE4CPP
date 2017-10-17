# C++ project of for exampleApplication

CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

SET(CMAKE_C_COMPILER "gcc.exe")
SET(CMAKE_CXX_COMPILER "g++.exe")

PROJECT(umlModelExample)

IF(NOT CMAKE_BUILD_TYPE) 
    SET(CMAKE_BUILD_TYPE Debug)
ENDIF(NOT CMAKE_BUILD_TYPE)

SET(CMAKE_CXX_STANDARD 14)
SET(GCC_COVERAGE_LINK_FLAGS "-fopenmp")
SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wno-overloaded-virtual -Wdeprecated-declarations -fopenmp -fmax-errors=5")
SET(CMAKE_CXX_FLAGS_DEBUG " -Og -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE " -O3 -DNDEBUG")

string(REPLACE "\\" "/" MDE4CPP_HOME $ENV{MDE4CPP_HOME})

SET(SOURCE_FILES
	src/main.cpp
)

INCLUDE_DIRECTORIES(
	${MDE4CPP_HOME}/application/include
	${MDE4CPP_HOME}/application/include/abstractDataTypes
	${MDE4CPP_HOME}/application/include/ecore
	${MDE4CPP_HOME}/application/include/types
	${MDE4CPP_HOME}/application/include/uml
	${MDE4CPP_HOME}/application/include/libraryModel_uml
)

FIND_LIBRARY(ECORE_DEBUG ecored ${MDE4CPP_HOME}/application/lib)
FIND_LIBRARY(ECORE_RELEASE ecore ${MDE4CPP_HOME}/application/lib)
FIND_LIBRARY(TYPES_DEBUG typesd ${MDE4CPP_HOME}/application/lib)
FIND_LIBRARY(TYPES_RELEASE types ${MDE4CPP_HOME}/application/lib)
FIND_LIBRARY(UML_DEBUG umld ${MDE4CPP_HOME}/application/lib)
FIND_LIBRARY(UML_RELEASE uml ${MDE4CPP_HOME}/application/lib)
FIND_LIBRARY(UMLREFLECTION_DEBUG umlreflectiond ${MDE4CPP_HOME}/application/lib)
FIND_LIBRARY(UMLREFLECTION_RELEASE umlreflection ${MDE4CPP_HOME}/application/lib)
FIND_LIBRARY(LIBRARYMODEL_UML_DEBUG LibraryModel_umld ${MDE4CPP_HOME}/application/lib)
FIND_LIBRARY(LIBRARYMODEL_UML_RELEASE LibraryModel_uml ${MDE4CPP_HOME}/application/lib)

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILES})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")
TARGET_LINK_LIBRARIES(${PROJECT_NAME} 
	debug ${ECORE_DEBUG}
	debug ${TYPES_DEBUG}
	debug ${UML_DEBUG}
	debug ${UMLREFLECTION_DEBUG}
	debug ${PRIMITIVETYPESREFLECTION_DEBUG}
	debug ${LIBRARYMODEL_UML_DEBUG}
)
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
	optimized ${ECORE_RELEASE}
	optimized ${TYPES_RELEASE}
	optimized ${UML_RELEASE}
	optimized ${UMLREFLECTION_RELEASE}
	optimized ${PRIMITIVETYPESREFLECTION_RELEASE}
	optimized ${LIBRARYMODEL_UML_RELEASE}
)

#-----------------------------------------------------
# DELIVERING binaries and header to ${MDE4CPP_HOME}
#-----------------------------------------------------

INSTALL(TARGETS ${PROJECT_NAME} 
	RUNTIME DESTINATION ${MDE4CPP_HOME}/application/bin
)