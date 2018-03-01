/*
 * PluginFramework.hpp
 *
 *  Created on: 21.06.2017
 *      Author: alwi0251
 */

#ifndef PLUGINFRAMEWORK_PLUGINFRAMEWORKIMPL_HPP
#define PLUGINFRAMEWORK_PLUGINFRAMEWORKIMPL_HPP

#include <map>
#include <vector>

#include "pluginFramework/PluginFramework.hpp"

class PluginFrameworkImpl : virtual public PluginFramework
{
	private:
		PluginFrameworkImpl(PluginFrameworkImpl const&) = delete;
		PluginFrameworkImpl& operator=(PluginFrameworkImpl const&) = delete;
		static PluginFramework* create();

	public:
		virtual ~PluginFrameworkImpl();
		virtual std::shared_ptr<MDE4CPPPlugin> findPluginByName(const std::string name) const;
		virtual void clear();

	protected:
		friend class PluginFramework;
		PluginFrameworkImpl();

		virtual void initialize();
		virtual std::vector<std::string> findAllAvailableLibraries();
		virtual std::string checkLibrary(struct dirent* file, std::string folderName);
		virtual void loadLibrary(std::string libraryPath);

	private:
		std::map<std::string, std::shared_ptr<MDE4CPPPlugin>> m_pluginMap;
		bool m_debugMode;
		std::string m_endingDebug;
		std::string m_endingRelease;
		std::string m_endingString;
};

#endif
