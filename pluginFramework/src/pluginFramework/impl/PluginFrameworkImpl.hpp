/*
 * PluginFramework.hpp
 *
 *  Created on: 21.06.2017
 *      Author: alwi0251
 */

#ifndef PLUGINFRAMEWORK_PLUGINFRAMEWORKIMPL_HPP
#define PLUGINFRAMEWORK_PLUGINFRAMEWORKIMPL_HPP

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <map>
#include <string>
#include <vector>

#include "boost/shared_ptr.hpp"
#include "pluginFramework/pluginFramework.hpp"

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
		virtual std::shared_ptr<MDE4CPPPlugin> findPluginByName(const std::string name) const;
		virtual void clear();

	protected:
		friend class PluginFramework;
		PluginFrameworkImpl();

		virtual void initialize();
		virtual std::vector<std::string> findAllAvailableLibraries();
		virtual void loadLibrary(std::string libraryPath);

	private:
		std::map<std::string, std::shared_ptr<MDE4CPPPlugin>> m_pluginMap;

};

#endif
