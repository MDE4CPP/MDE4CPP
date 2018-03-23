/*
 * PluginFrameworkImplWin.cpp
 *
 *  Created on: 23.03.2018
 *      Author: alwi0251
 */

#include "pluginFramework/impl/PluginFrameworkImplWin.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <dirent.h>
#include <iostream>
#include <windows.h>

#include "pluginFramework/MDE4CPPPlugin.hpp"

typedef std::shared_ptr<MDE4CPPPlugin> (__stdcall *StartFunction)();
#define MAX_CHAR 260

PluginFrameworkImplWin::PluginFrameworkImplWin():
	PluginFrameworkImpl()
{
}

PluginFrameworkImplWin::~PluginFrameworkImplWin()
{
}

PluginFramework* PluginFrameworkImplWin::create()
{
	return new PluginFrameworkImplWin();
}

std::vector<std::string> PluginFrameworkImplWin::findAllAvailableLibraries()
{
	char folderBuffer[MAX_CHAR];
	char nameBuffer[MAX_CHAR];
	std::vector<std::string> libraries;

	m_debugMode = false;
	GetCurrentDirectory(MAX_CHAR, folderBuffer);
	GetModuleFileName(NULL, nameBuffer, MAX_CHAR);
	m_endingDebug = "d.dll";
	m_endingRelease = ".dll";
	m_endingString = "d.exe";

	std::string fileName(nameBuffer);
	std::string folderName(folderBuffer);

	if (fileName.length() >= m_endingString.length())
	{
		m_debugMode =  (0 == fileName.compare(fileName.length() - m_endingString.length(), m_endingString.length(), m_endingString));
	}

	DIR *dir;
	struct dirent *file;
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

	return libraries;
}

void PluginFrameworkImplWin::loadLibrary(std::string libraryPath)
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
		m_mapPluginName.insert(std::pair<std::string, std::shared_ptr<MDE4CPPPlugin>>(plugin->eNAME(), plugin));
		m_mapPluginUri.insert(std::pair<std::string, std::shared_ptr<MDE4CPPPlugin>>(plugin->eNS_URI(), plugin));
		std::string eclipseURI = plugin->eclipseURI();
		if (!eclipseURI.empty())
		{
			m_mapPluginUri.insert(std::pair<std::string, std::shared_ptr<MDE4CPPPlugin>>(eclipseURI, plugin));
		}

		DEBUG_MESSAGE(std::cout << "library " << plugin << " started" << std::endl;)
	}
}
