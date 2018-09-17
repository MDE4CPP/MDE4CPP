#-------------------------------------------------
#
# Project created by Mesapp Generator 
#
#-------------------------------------------------

#TODO: set SDKPath to your local uml includes (if needed), or create a common.pri file and comment the include line below
# Start of user code SDKPATH
# INFO: The 2 lines below won't be overwritten on the following generation of the model.
include(../common.pri)
# SDKPath = Q:/x86_64-win-mingw.pro
# End of user code


CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS_WARN_ON = -Wall -Wno-overloaded-virtual




QT       += core
QT 		 += xml
QT       -= gui


TARGET = NewModel

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = lib



# Model Headers
HEADERS += 	 PrimeChecker.hpp \ 
	 CheckIfPrime.hpp

# Implementation Headers
HEADERS += 	impl/PrimeCheckerImpl.hpp \ 
	impl/CheckIfPrimeImpl.hpp

# Implementation Source
SOURCES += 	impl/PrimeCheckerImpl.cpp \ 
	impl/CheckIfPrimeImpl.cpp
# Enum Headers
HEADERS += 

# Factory
HEADERS += NewModelFactory.hpp \
		   impl/NewModelFactoryImpl.hpp 
SOURCES += impl/NewModelFactoryImpl.cpp \
			NewModelFactory.cpp




# Package
HEADERS += NewModelPackage.hpp \
		   impl/NewModelPackageImpl.hpp 
SOURCES += impl/NewModelPackageImpl.cpp \
			NewModelPackage.cpp 
Release: DEFINES += QT_NO_DEBUG_OUTPUT
INCLUDEPATH +=$$PWD/../

# Start of user code includes
INCLUDEPATH += $${SDKPath}/include
INCLUDEPATH += $${SDKPath}/include/mesapp
INCLUDEPATH += $${SDKPath}/include/mesapp/uml
INCLUDEPATH += $${SDKPath}/include/mesapp/fuml
INCLUDEPATH += $${SDKPath}/include/mesapp/ecore
INCLUDEPATH += $${SDKPath}/include/mesapp/PrimitiveTypes
INCLUDEPATH += $${SDKPath}/include/mesapp/Util

win32:CONFIG(release, debug|release): LIBS += -L$${SDKPath}/bin -lecore -luml -lPrimitiveTypes -lUML_ -lEcore_
else:win32:CONFIG(debug, debug|release): LIBS += -L$${SDKPath}/bin -lecored -lumld -lPrimitiveTypesd -lUML_d -lEcore_d
else:unix: LIBS += -L$$OUT_PWD/../ecore/ -lecore

# End of user code

CONFIG(debug, debug|release) {
     mac: TARGET = $$join(TARGET,,,_debug)
     win32: TARGET = $$join(TARGET,,,d)
 }

