/*
 * PluginFramework.hpp
 *
 *  Created on: 21.06.2017
 *      Author: alwi0251
 */

#ifndef SRC_PLUGINFRAMEWORK_HPP_
#define SRC_PLUGINFRAMEWORK_HPP_

#include "boost/shared_ptr.hpp"
#include <map>
#include <string>
#include <vector>

#include "MDE4CPPPlugin.hpp"

#define MAX_CHAR 260
typedef std::shared_ptr<MDE4CPPPlugin> (__stdcall *StartFunction)();

class PluginFramework
{
	public:
		static std::shared_ptr<PluginFramework> eInstance();

		virtual ~PluginFramework();
		virtual std::shared_ptr<MDE4CPPPlugin> findPluginByName(const std::string name) const;

	protected:
		PluginFramework();

		virtual void initialize();
		virtual std::vector<std::string> findAllAvailableLibraries();
		virtual void loadLibrary(std::string libraryPath);

	private:
		static std::shared_ptr<PluginFramework> instance;
		std::map<std::string, std::shared_ptr<MDE4CPPPlugin>> m_pluginMap;

};

#endif /* SRC_PLUGINFRAMEWORK_HPP_ */
