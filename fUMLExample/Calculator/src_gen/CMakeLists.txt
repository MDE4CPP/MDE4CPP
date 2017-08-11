cmake_minimum_required(VERSION 3.9)
project(src_gen)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        CalcModel/impl/CalcModelFactoryImpl.cpp
        CalcModel/impl/CalcModelFactoryImpl.hpp
        CalcModel/impl/CalcModelPackageImpl.cpp
        CalcModel/impl/CalcModelPackageImpl.hpp
        CalcModel/impl/CalcModelPluginImpl.cpp
        CalcModel/impl/CalcModelPluginImpl.hpp
        CalcModel/impl/CalculatorImpl.cpp
        CalcModel/impl/CalculatorImpl.hpp
        CalcModel/impl/CheckIfPrimeImpl.cpp
        CalcModel/impl/CheckIfPrimeImpl.hpp
        CalcModel/impl/MainActivityImpl.cpp
        CalcModel/impl/MainActivityImpl.hpp
        CalcModel/impl/PrimeCheckerImpl.cpp
        CalcModel/impl/PrimeCheckerImpl.hpp
        CalcModel/impl/sumActivityImpl.cpp
        CalcModel/impl/sumActivityImpl.hpp
        CalcModel/CalcModelFactory.cpp
        CalcModel/CalcModelFactory.hpp
        CalcModel/CalcModelPackage.cpp
        CalcModel/CalcModelPackage.hpp
        CalcModel/CalcModelPlugin.cpp
        CalcModel/CalcModelPlugin.hpp
        CalcModel/Calculator.hpp
        CalcModel/CheckIfPrime.hpp
        CalcModel/CMakeLists.txt
        CalcModel/MainActivity.hpp
        CalcModel/PrimeChecker.hpp
        CalcModel/sumActivity.hpp
        CalcModelExec/CMakeLists.txt
        CalcModelExec/FbDividesExecution.cpp
        CalcModelExec/FbDividesExecution.hpp
        CalcModelExec/FbIsNotFinishedExecution.cpp
        CalcModelExec/FbIsNotFinishedExecution.hpp
        CalcModelExec/FbIsOddExecution.cpp
        CalcModelExec/FbIsOddExecution.hpp
        CalcModelExec/FbNextExecution.cpp
        CalcModelExec/FbNextExecution.hpp
        CalcModelExec/FbPrintIsPrimeExecution.cpp
        CalcModelExec/FbPrintIsPrimeExecution.hpp
        CalcModelExec/FbPrintNotPrimeExecution.cpp
        CalcModelExec/FbPrintNotPrimeExecution.hpp
        CalcModelExec/main.cpp
        CalcModelExec/PrimeCheckerExecution.cpp
        CalcModelExec/PrimeCheckerExecution.hpp)

add_executable(src_gen ${SOURCE_FILES})