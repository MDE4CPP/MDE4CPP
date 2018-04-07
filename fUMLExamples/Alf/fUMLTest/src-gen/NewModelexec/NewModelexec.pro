#-------------------------------------------------
#
# Project created by Mesapp Generator 
#
#-------------------------------------------------

#TODO: set SDKPath to your local uml includes (if needed)
#TODO: create a kit in Qt Creator and set its name here
#NOTE: The following values are globally set in the ../common.pri file.
# Start of user code SDKPATH
#SDKPath = Q:/x86_64-win-mingw.pro
#KITNAME = KASI
# End of user code

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS_WARN_ON = -Wall -Wno-overloaded-virtual


include(../common.pri)

QT       += core
QT 		 += xml
QT       -= gui


TARGET = NewModel

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS += PrintNotPrimeExecution.hpp
SOURCES += PrintNotPrimeExecution.cpp
HEADERS += IsNotFinishedExecution.hpp
SOURCES += IsNotFinishedExecution.cpp
HEADERS += DividesExecution.hpp
SOURCES += DividesExecution.cpp
HEADERS += IsOddExecution.hpp
SOURCES += IsOddExecution.cpp
HEADERS += PrintIsPrimeExecution.hpp
SOURCES += PrintIsPrimeExecution.cpp
HEADERS += NextExecution.hpp
SOURCES += NextExecution.cpp


#Classes
HEADERS += PrimeCheckerExecution.hpp
SOURCES += PrimeCheckerExecution.cpp
HEADERS += CheckIfPrimeExecution.hpp
SOURCES += CheckIfPrimeExecution.cpp

SOURCES += main.cpp

#Metamodel Package Include 

INCLUDEPATH += ../NewModel

win32:CONFIG(release, debug|release): LIBS += -L../build-NewModel-$${KITNAME}-Release/release -lNewModel
else:win32:CONFIG(debug, debug|release): LIBS += -L../build-NewModel-$${KITNAME}-Debug/debug -lNewModeld
else:unix: LIBS += -L$$OUT_PWD/../ecore/ -lecore

Release: DEFINES += QT_NO_DEBUG_OUTPUT

# Start of user code includes
INCLUDEPATH += $${SDKPath}/include
INCLUDEPATH += $${SDKPath}/include/mesapp
INCLUDEPATH += $${SDKPath}/include/mesapp/uml
INCLUDEPATH += $${SDKPath}/include/mesapp/fuml
INCLUDEPATH += $${SDKPath}/include/mesapp/ecore
INCLUDEPATH += $${SDKPath}/include/mesapp/PrimitiveTypes
INCLUDEPATH += $${SDKPath}/include/mesapp/Util

win32:CONFIG(release, debug|release): LIBS += -L$${SDKPath}/bin -lecore -luml -lPrimitiveTypes -lUML_ -lEcore_ -lfuml
else:win32:CONFIG(debug, debug|release): LIBS += -L$${SDKPath}/bin -lecored -lumld -lPrimitiveTypesd -lUML_d -lEcore_d -lfumld
else:unix: LIBS += -L$$OUT_PWD/../ecore/ -lecore
# End of user code


