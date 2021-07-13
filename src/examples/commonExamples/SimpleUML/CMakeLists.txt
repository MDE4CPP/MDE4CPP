cmake_minimum_required(VERSION 3.7)
project(SubsetUnion)

set(CMAKE_CXX_STANDARD 14)
SET(GCC_COVERAGE_COMPILE_FLAGS "-fopenmp")

set(SOURCE_FILES
        src/main.cpp
        )


INCLUDE_DIRECTORIES(
        ${MDE4CPP_HOME}/application/include
)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
add_executable(SubsetUnion ${SOURCE_FILES})