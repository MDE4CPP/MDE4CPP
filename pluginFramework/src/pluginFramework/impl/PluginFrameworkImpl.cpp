/*
 * PluginFramework.cpp
 *
 *  Created on: 21.06.2017
 *      Author: alwi0251
 */

#include "pluginFramework/impl/PluginFrameworkImpl.hpp"

#include <dirent.h>
#include <iostream>
#include <windows.h>


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

	GetCurrentDirectory(MAX_CHAR, folderBuffer);
	GetModuleFileName(NULL, nameBuffer, MAX_CHAR );

	std::string fileName(nameBuffer);
	std::string folderName(folderBuffer);
	std::string endingDebug = "d.dll";
	std::string endingRelease = ".dll";
	std::string endingString("d.exe");
	std::vector<std::string> libraries;
	bool debugMode = false;
	if (fileName.length() >= endingString.length())
	{
		debugMode =  (0 == fileName.compare(fileName.length() - endingString.length(), endingString.length(), endingString));
	}

	DIR *dir;
	struct dirent *file;
	if((dir = opendir(folderBuffer)) != NULL)
	{
		while((file = readdir(dir)) != NULL)
		{
			std::string name(file->d_name);
			if(debugMode)
			{
				if(name.length() >= endingDebug.length())
				{
					if((0 == name.compare (name.length() - endingDebug.length(), endingDebug.length(), endingDebug)))
					{
						libraries.push_back(folderName + "\\" + name);
					}
				}
			}
			else
			{
				if(name.length() >= endingRelease.length())
				{
					if((0 == name.compare (name.length() - endingRelease.length(), endingRelease.length(), endingRelease)))
					{
						if(name.length() >= endingDebug.length())
						{
							if((0 != name.compare (name.length() - endingDebug.length(), endingDebug.length(), endingDebug)))
							{
								libraries.push_back(folderName + "\\" + name);
							}
						}
					}
				}
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
