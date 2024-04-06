cmake_minimum_required(VERSION 3.9)
project(API_Tests)

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

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

SET(SOURCE_FILES
  testMain.cpp
  testHelpers.cpp
  ../src/ModelInstance.cpp
  ../src/helperFunc.cpp
)

INCLUDE_DIRECTORIES(
	../
	$ENV{MDE4CPP_HOME}/application/include
  $ENV{MDE4CPP_HOME}/src/common/MDE4CPP_PluginAPI/src
)

IF(APPLE)
  SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -undefined dynamic_lookup")
  SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -undefined dynamic_lookup")
ENDIF(APPLE)

IF(UNIX AND NOT APPLE) # for Linux, BSD, Solaris, Minix
  FIND_LIBRARY(TYPES typesd.so $ENV{MDE4CPP_HOME}/application/lib)
  FIND_LIBRARY(ECORE ecored.so $ENV{MDE4CPP_HOME}/application/lib)
  FIND_LIBRARY(LIBRARYMODEL_ECORE libraryModel_ecored.so ${MDE4CPP_HOME}/application/lib)
ELSEIF(APPLE)
  FIND_LIBRARY(TYPES typesd.dylib $ENV{MDE4CPP_HOME}/application/lib)
  FIND_LIBRARY(ECORE ecored.dylib $ENV{MDE4CPP_HOME}/application/lib)
  FIND_LIBRARY(LIBRARYMODEL_ECORE libraryModel_ecored.dylib $ENV{MDE4CPP_HOME}/application/lib)
ELSE() # for Windows
  FIND_LIBRARY(TYPES typesd $ENV{MDE4CPP_HOME}/application/lib)
  FIND_LIBRARY(ECORE ecored $ENV{MDE4CPP_HOME}/application/lib)
  FIND_LIBRARY(LIBRARYMODEL_ECORE libraryModel_ecored $ENV{MDE4CPP_HOME}/application/lib)
ENDIF()

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(
  ${PROJECT_NAME}
	debug ${LIBRARYMODEL_ECORE}
  debug ${TYPES}
  debug ${ECORE}
	ws2_32
	wsock32
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})