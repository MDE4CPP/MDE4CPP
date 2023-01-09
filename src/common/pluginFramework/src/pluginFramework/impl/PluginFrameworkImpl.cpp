/*
 * PluginFramework.cpp
 *
 *  Created on: 21.06.2017
 *      Author: wichmann
 */

#include "pluginFramework/impl/PluginFrameworkImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

#ifdef _WIN32
	#include <windows.h>

	#define getcwd _getcwd
	#define getStartFunction GetProcAddress
	#define getError GetLastError
#else
	#include <dlfcn.h>
	#include <unistd.h>

	#define __stdcall
	#define getStartFunction dlsym
	#define getError dlerror
#endif

#include <dirent.h>
#include <iostream>

#include "abstractDataTypes/Bag.hpp"
#include "pluginFramework/MDE4CPPPlugin.hpp"

PluginFrameworkImpl::PluginFrameworkImpl():
	m_debugMode(false)
{
#ifdef _WIN32
	m_endingDebug = "d.dll" ;
	m_endingRelease = ".dll";
#elif __linux__
	m_endingDebug = "d.so" ;
	m_endingRelease = ".so";
#elif __APPLE__
	m_endingDebug = "d.dylib" ;
	m_endingRelease = ".dylib";
#else
	m_endingDebug = "d" ;
	m_endingRelease = "";
#endif

#ifdef NDEBUG
	m_debugMode = false;
#else
	m_debugMode = true;
#endif
}

PluginFrameworkImpl::~PluginFrameworkImpl()
{
	m_mapPluginName.clear();
	m_mapPluginUri.clear();
}

PluginFramework* PluginFrameworkImpl::create()
{
	PluginFrameworkImpl* instance = new PluginFrameworkImpl();
	instance->initialize();
	return instance;
}

std::vector<std::string> PluginFrameworkImpl::findAllAvailableLibraries()
{
	char folderBuffer[MAX_CHAR];
	std::vector<std::string> libraries;
	if (!getcwd(folderBuffer, sizeof(folderBuffer)))
	{
		return libraries;
	}

	std::string folderName(folderBuffer);
	DIR *dir;
	struct dirent *file;
	if((dir = opendir(folderName.c_str())) != NULL)
	{
		while((file = readdir(dir)) != NULL)
		{
			std::string libName = checkLibrary(file, folderName);
			if (!libName.empty())
			{
				DEBUG_INFO("Found plugin '" << libName << "'.")
				libraries.push_back(libName);
			}
		}
		closedir (dir);
	}
	else
	{
		std::cerr << "Could not open directory '" << folderName << "'! Failed to load plugins!" << std::endl;
	}

	return libraries;
}

std::string PluginFrameworkImpl::checkLibrary(struct dirent* file, std::string folderName)
{
	std::string name(file->d_name);
	if(m_debugMode)
	{
		if(name.length() >= m_endingDebug.length())
		{
			if((0 == name.compare(name.length() - m_endingDebug.length(), m_endingDebug.length(), m_endingDebug)))
			{
				return folderName + "/" + name;
			}
		}
	}
	else
	{
		if(name.length() >= m_endingRelease.length())
		{
			if((0 == name.compare(name.length() - m_endingRelease.length(), m_endingRelease.length(), m_endingRelease)))
			{
				if(name.length() >= m_endingDebug.length())
				{
					if((0 != name.compare(name.length() - m_endingDebug.length(), m_endingDebug.length(), m_endingDebug)))
					{
						return folderName + "/" + name;
					}
				}
			}
		}
	}
	return "";
}

void PluginFrameworkImpl::initialize()
{
	std::vector<std::string> libraries = findAllAvailableLibraries();

	for (std::string libraryPath : libraries)
	{
		loadLibrary(libraryPath);
	}
}

void PluginFrameworkImpl::loadLibrary(std::string libraryPath)
{
#ifdef _WIN32
	HINSTANCE handle = LoadLibrary(libraryPath.c_str());
#else
	void* handle = dlopen(libraryPath.c_str(), RTLD_LAZY);
#endif

	if(!handle)
	{
		std::cerr << "Could not load dynamic library! ErrorCode: " << getError() << "." << std::endl;
		return;
	}

	StartFunction startFunction = (StartFunction) getStartFunction(handle, "_Z5startv");
	if(!startFunction)
	{
		DEBUG_ERROR("Unable to locate start function 'std::shared_ptr<MDE4CPPPlugin> start()' in plugin '" << libraryPath << "'.")
	}
	else
	{
		std::shared_ptr<MDE4CPPPlugin> plugin = startFunction();
		m_mapPluginName.insert(std::pair<std::string, std::shared_ptr<MDE4CPPPlugin>>(plugin->eNAME(), plugin));
		m_mapPluginUri.insert(std::pair<std::string, std::shared_ptr<MDE4CPPPlugin>>(plugin->eNS_URI(), plugin));
		std::string eclipseURI = plugin->eclipseURI();
		if (!eclipseURI.empty())
		{
			m_mapPluginUri.insert(std::pair<std::string, std::shared_ptr<MDE4CPPPlugin>>(eclipseURI, plugin));
		}

		DEBUG_INFO("Started plugin '" << plugin << "'.")
	}
}

void PluginFrameworkImpl::clear()
{
	m_mapPluginName.clear();
	m_mapPluginUri.clear();
}

std::shared_ptr<MDE4CPPPlugin> PluginFrameworkImpl::findPluginByName(const std::string name) const
{
	std::map<std::string, std::shared_ptr<MDE4CPPPlugin>>::const_iterator iter = m_mapPluginName.find(name);

	std::shared_ptr<MDE4CPPPlugin> pluginObject;
	if(iter != m_mapPluginName.end())
	{
		return iter->second;
	}

	return nullptr;
}

std::shared_ptr<MDE4CPPPlugin> PluginFrameworkImpl::findPluginByUri(const std::string uri) const
{
	std::map<std::string, std::shared_ptr<MDE4CPPPlugin>>::const_iterator iter = m_mapPluginUri.find(uri);

	std::shared_ptr<MDE4CPPPlugin> pluginObject;
	if(iter != m_mapPluginUri.end())
	{
		return iter->second;
	}

	return nullptr;
}

std::shared_ptr<Bag<MDE4CPPPlugin>> PluginFrameworkImpl::getAllPlugins() const
{
	std::shared_ptr<Bag<MDE4CPPPlugin>> pluginList(new Bag<MDE4CPPPlugin>());

	std::map<std::string, std::shared_ptr<MDE4CPPPlugin>>::const_iterator iter = m_mapPluginName.begin();
	std::map<std::string, std::shared_ptr<MDE4CPPPlugin>>::const_iterator end = m_mapPluginName.end();
	while (iter != end)
	{
		pluginList->push_back(iter->second);
		iter++;
	}

	return pluginList;
}
