/*
 * PluginFramework.cpp
 *
 *  Created on: 21.06.2017
 *      Author: wichmann
 */

#include "pluginFramework/impl/PluginFrameworkImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>
#include <dirent.h>

PluginFrameworkImpl::PluginFrameworkImpl()
{
	initialize();
}

PluginFrameworkImpl::~PluginFrameworkImpl()
{
	m_mapPluginName.clear();
	m_mapPluginUri.clear();
}

PluginFramework* PluginFrameworkImpl::create()
{
	return new PluginFrameworkImpl();
}

std::vector<std::string> PluginFrameworkImpl::findAllAvailableLibraries()
{
	std::vector<std::string> libraries;
	std::cerr << "PluginFrameworkImpl::findAllAvailableLibraries is not implemented for this system!";
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
	std::cerr << "PluginFrameworkImpl::loadLibrary is not implemented for this system!";
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

