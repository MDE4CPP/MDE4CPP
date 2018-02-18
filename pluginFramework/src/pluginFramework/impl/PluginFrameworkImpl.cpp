/*
 * PluginFramework.cpp
 *
 *  Created on: 21.06.2017
 *      Author: alwi0251
 */

#include "pluginFramework/impl/PluginFrameworkImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#define MAX_CHAR 260
typedef std::shared_ptr<MDE4CPPPlugin> (__stdcall *StartFunction)();

#include <iostream>
#include <dirent.h>

#ifdef __linux__

#elif defined(_WIN32)
	#include <windows.h>
#endif

PluginFrameworkImpl::PluginFrameworkImpl()
{
	initialize();
}

PluginFrameworkImpl::~PluginFrameworkImpl()
{
	m_pluginMap.clear();
}

PluginFramework* PluginFrameworkImpl::create()
{
	return new PluginFrameworkImpl();
}

std::vector<std::string> PluginFrameworkImpl::findAllAvailableLibraries()
{
	char folderBuffer[MAX_CHAR];
	char nameBuffer[MAX_CHAR];

	m_debugMode = false;
#ifdef __linux__
	m_endingDebug = "d.so";
	m_endingRelease = ".so";
	m_endingString = "d";
	std::cerr << "PluginFrameworkImpl::findAllAvailableLibraries is not implemented for Linux systems!"
	return libraries;
#elif defined(_WIN32)
	GetCurrentDirectory(MAX_CHAR, folderBuffer);
	GetModuleFileName(NULL, nameBuffer, MAX_CHAR);
	m_endingDebug = "d.dll";
	m_endingRelease = ".dll";
	m_endingString = "d.exe";
#else
	std::cerr << "PluginFrameworkImpl::findAllAvailableLibraries is not implemented for this system!"
	return libraries;
#endif

	std::string fileName(nameBuffer);
	std::string folderName(folderBuffer);

	std::vector<std::string> libraries;
	if (fileName.length() >= m_endingString.length())
	{
		m_debugMode =  (0 == fileName.compare(fileName.length() - m_endingString.length(), m_endingString.length(), m_endingString));
	}

	DIR *dir;
	struct dirent *file;

#ifdef __linux__
	std::cerr << "PluginFrameworkImpl::findAllAvailableLibraries is not implemented for Linux systems!"
#elif defined(_WIN32)
	if((dir = opendir(folderBuffer)) != NULL)
	{
		while((file = readdir(dir)) != NULL)
		{
			std::string libName = checkLibrary(file, folderName);
			if (!libName.empty())
			{
				libraries.push_back(libName);
			}
		}
		closedir (dir);
	}
	else
	{
		std::cerr << "Could not open directory " << folderName << " failed" << std::endl;
	}
#else
	std::cerr << "PluginFrameworkImpl::findAllAvailableLibraries is not implemented for this system!"
#endif

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
				return folderName + "\\" + name;
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
						return folderName + "\\" + name;
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
	HINSTANCE hGetProcIDDLL = LoadLibrary(libraryPath.c_str());
	if(!hGetProcIDDLL)
	{
		std::cerr << "could not load the dynamic library, ErrorCode: " << GetLastError() << std::endl;
		return;
	}

	StartFunction startFunction = (StartFunction) GetProcAddress(hGetProcIDDLL, "_Z5startv");
	if(!startFunction)
	{
		DEBUG_MESSAGE(std::cout << "Could not locate the start function 'std::shared_ptr<MDE4CPPPlugin> start()' in library " << libraryPath << std::endl;)
	}
	else
	{
		std::shared_ptr<MDE4CPPPlugin> plugin = startFunction();
		m_pluginMap.insert(std::pair<std::string, std::shared_ptr<MDE4CPPPlugin>>(plugin->eNAME(), plugin));

		DEBUG_MESSAGE(std::cout << "library " << plugin << " started" << std::endl;)
	}
}

void PluginFrameworkImpl::clear()
{
	m_pluginMap.clear();
}

std::shared_ptr<MDE4CPPPlugin> PluginFrameworkImpl::findPluginByName(const std::string name) const
{
	std::map<std::string, std::shared_ptr<MDE4CPPPlugin>>::const_iterator iter = m_pluginMap.find(name);

	std::shared_ptr<MDE4CPPPlugin> pluginObject;
	if(iter != m_pluginMap.end())
	{
		return iter->second;
	}

	return nullptr;
}
