/*
 * PluginFramework.hpp
 *
 *  Created on: 21.06.2017
 *      Author: alwi0251
 */

#ifndef PLUGINFRAMEWORK_PLUGINFRAMEWORKIMPL_HPP
#define PLUGINFRAMEWORK_PLUGINFRAMEWORKIMPL_HPP

#include "pluginFramework/PluginFramework.hpp"

#include <map>
#include <vector>

#ifndef __stdcall
	#define __stdcall
#endif

#define MAX_CHAR 260
typedef std::shared_ptr<MDE4CPPPlugin> (__stdcall *StartFunction)();

class PluginFrameworkImpl : virtual public PluginFramework
{
	private:
		PluginFrameworkImpl(PluginFrameworkImpl const&) = delete;
		PluginFrameworkImpl& operator=(PluginFrameworkImpl const&) = delete;
		static PluginFramework* create();

	public:
		virtual ~PluginFrameworkImpl();
		virtual std::shared_ptr<MDE4CPPPlugin> findPluginByName(const std::string) const;
		virtual std::shared_ptr<MDE4CPPPlugin> findPluginByUri(const std::string) const;
		virtual std::shared_ptr<Bag<MDE4CPPPlugin>> getAllPlugins() const;
		virtual void clear();

	protected:
		friend class PluginFramework;
		PluginFrameworkImpl();

		virtual void initialize();
		virtual std::vector<std::string> findAllAvailableLibraries();
		virtual std::string checkLibrary(struct dirent*, std::string);
		virtual void loadLibrary(std::string);

		std::map<std::string, std::shared_ptr<MDE4CPPPlugin>> m_mapPluginName;
		std::map<std::string, std::shared_ptr<MDE4CPPPlugin>> m_mapPluginUri;

		bool m_debugMode;
		std::string m_endingDebug;
		std::string m_endingRelease;
		std::string m_endingString;
};

#endif
