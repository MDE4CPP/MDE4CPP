/*
 * PluginFramework.hpp
 *
 *  Created on: 21.06.2017
 *      Author: alwi0251
 */

#ifndef PLUGINFRAMEWORK_PLUGINFRAMEWORK_HPP
#define PLUGINFRAMEWORK_PLUGINFRAMEWORK_HPP

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <map>
#include <string>
#include <vector>

#include "boost/shared_ptr.hpp"
#include "pluginFramework/MDE4CPPPlugin.hpp"

#define MAX_CHAR 260
typedef std::shared_ptr<MDE4CPPPlugin> (__stdcall *StartFunction)();

class PluginFramework
{
	private:
		PluginFramework(PluginFramework const&) = delete;
		PluginFramework& operator=(PluginFramework const&) = delete;

	protected:
		PluginFramework(){};

	public:
		static std::shared_ptr<PluginFramework> eInstance();

		virtual ~PluginFramework(){};
		virtual void clear() = 0;
		virtual std::shared_ptr<MDE4CPPPlugin> findPluginByName(const std::string name) const = 0;

	private:
		static std::shared_ptr<PluginFramework> instance;
};

#endif
