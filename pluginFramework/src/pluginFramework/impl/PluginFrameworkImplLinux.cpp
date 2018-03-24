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

#include <dirent.h>
#include <iostream>
#include <sstream>
#include <unistd.h>

#include "pluginFramework/MDE4CPPPlugin.hpp"

#define MAX_CHAR 260
using namespace std;

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
	char cCurrentPath[MAX_CHAR];
	std::vector<std::string> libraries;
	if (!getcwd(cCurrentPath, sizeof(cCurrentPath)))
	{
		return libraries;
	}

#ifdef NDEBUG
	m_debugMode = false;
#else
	m_debugMode = true;
#endif
	m_endingDebug = "d.so";
	m_endingRelease = ".so";

	std::string folderName(cCurrentPath);
	std::cout << folderName << std::endl;
	DIR *dir;
	struct dirent *file;
	if((dir = opendir(folderName.c_str())) != NULL)
	{
		DEBUG_MESSAGE(std::cout << "libraries to be loaded" << std::endl;)
		while((file = readdir(dir)) != NULL)
		{
			std::string libName = checkLibrary(file, folderName);
			if (!libName.empty())
			{
				DEBUG_MESSAGE(std::cout << "\t" << libName << std::endl;)
				libraries.push_back(libName);
			}
		}
		closedir (dir);
	}
	else
	{
		std::cerr << "Could not open directory " << folderName << " failed" << std::endl;
	}

	return libraries;
}

void PluginFrameworkImplLinux::loadLibrary(std::string libraryPath)
{
	std::cerr << "PluginFrameworkImpl::loadLibrary is not implemented for Linux systems!";
}
