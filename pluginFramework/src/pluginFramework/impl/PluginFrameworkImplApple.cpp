/*
 * PluginFrameworkImplApple.cpp
 *
 *  Created on: 23.03.2018
 *      Author: alwi0251
 */

#include "pluginFramework/impl/PluginFrameworkImplApple.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>

#include "pluginFramework/MDE4CPPPlugin.hpp"

#define MAX_CHAR 260

PluginFrameworkImplApple::PluginFrameworkImplApple():
	PluginFrameworkImpl()
{
}

PluginFrameworkImplApple::~PluginFrameworkImplApple()
{
}

PluginFramework* PluginFrameworkImplApple::create()
{
	return new PluginFrameworkImplApple();
}

std::vector<std::string> PluginFrameworkImplApple::findAllAvailableLibraries()
{
	char folderBuffer[MAX_CHAR];
	char nameBuffer[MAX_CHAR];
	std::vector<std::string> libraries;

	m_debugMode = false;
	m_endingDebug = "d.dylib";
	m_endingRelease = ".dylib";
	m_endingString = "d";
	std::cerr << "PluginFrameworkImpl::findAllAvailableLibraries is not implemented for Apple systems!";
	return libraries;
}

void PluginFrameworkImplApple::loadLibrary(std::string libraryPath)
{
	std::cerr << "PluginFrameworkImpl::loadLibrary is not implemented for Apple systems!";
}
