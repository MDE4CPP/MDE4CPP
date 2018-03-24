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
#include <dlfcn.h>
#include <iostream>
#include <sstream>
#include <unistd.h>

#include "pluginFramework/MDE4CPPPlugin.hpp"

#define MAX_CHAR 260
typedef std::shared_ptr<MDE4CPPPlugin> (*StartFunction)();
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
	// open the library
	DEBUG_MESSAGE(std::cout << "Opening " << libraryPath << std::endl;)
	void* handle = dlopen(libraryPath.c_str(), RTLD_LAZY);

	if (!handle)
	{
		DEBUG_MESSAGE(std::cout << "Cannot open library: " << dlerror() << std::endl;)
		return;
	}

	// reset errors
	dlerror();
	StartFunction startFunction = (StartFunction) dlsym(handle, "_Z5startv");
	const char *dlsym_error = dlerror();
	if (dlsym_error)
	{
		DEBUG_MESSAGE(std::cout << "Could not locate the start function 'std::shared_ptr<MDE4CPPPlugin> start()' in library " << libraryPath << std::endl;)
		dlclose(handle);
		return;
	}

	if(startFunction)
	{
		std::shared_ptr<MDE4CPPPlugin> plugin = startFunction();
		m_mapPluginName.insert(std::pair<std::string, std::shared_ptr<MDE4CPPPlugin>>(plugin->eNAME(), plugin));
		m_mapPluginUri.insert(std::pair<std::string, std::shared_ptr<MDE4CPPPlugin>>(plugin->eNS_URI(), plugin));
		std::string eclipseURI = plugin->eclipseURI();
		if (!eclipseURI.empty())
		{
			m_mapPluginUri.insert(std::pair<std::string, std::shared_ptr<MDE4CPPPlugin>>(eclipseURI, plugin));
		}
		DEBUG_MESSAGE(std::cout << "library " << libraryPath << " started" << std::endl;)
	}
}
