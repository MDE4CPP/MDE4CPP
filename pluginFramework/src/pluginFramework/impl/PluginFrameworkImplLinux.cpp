/*
 * PluginFrameworkImplLinux.cpp
 *
 *  Created on: 23.03.2018
 *      Author: alwi0251
 */

#include "pluginFramework/impl/PluginFrameworkImplLinux.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>

#include "pluginFramework/MDE4CPPPlugin.hpp"

#define MAX_CHAR 260

PluginFrameworkImplLinux::PluginFrameworkImplLinux():
	PluginFrameworkImpl()
{
}

PluginFrameworkImplLinux::~PluginFrameworkImplLinux()
{
}

PluginFramework* PluginFrameworkImplLinux::create()
{
	PluginFrameworkImplLinux* instance = new PluginFrameworkImplLinux();
	instance->initialize();
	return instance;
}

std::vector<std::string> PluginFrameworkImplLinux::findAllAvailableLibraries()
{
	char folderBuffer[MAX_CHAR];
	char nameBuffer[MAX_CHAR];
	std::vector<std::string> libraries;

	m_debugMode = false;
	m_endingDebug = "d.so";
	m_endingRelease = ".so";
	m_endingString = "d";
	std::cerr << "PluginFrameworkImpl::findAllAvailableLibraries is not implemented for Linux systems!";
	return libraries;
}

void PluginFrameworkImplLinux::loadLibrary(std::string libraryPath)
{
	std::cerr << "PluginFrameworkImpl::loadLibrary is not implemented for Linux systems!";
}
