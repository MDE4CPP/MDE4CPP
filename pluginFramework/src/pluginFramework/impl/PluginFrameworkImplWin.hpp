/*
 * PluginFrameworkImplWin.hpp
 *
 *  Created on: 23.03.2018
 *      Author: wichmann
 */

#ifndef PLUGINFRAMEWORK_PLUGINFRAMEWORKIMPLWIN_HPP
#define PLUGINFRAMEWORK_PLUGINFRAMEWORKIMPLWIN_HPP

#include "pluginFramework/impl/PluginFrameworkImpl.hpp"

class PluginFrameworkImplWin: virtual public PluginFrameworkImpl
{
	private:
		PluginFrameworkImplWin(PluginFrameworkImplWin const&) = delete;
		PluginFrameworkImplWin& operator=(PluginFrameworkImplWin const&) = delete;

	protected:
		friend class PluginFramework;
		PluginFrameworkImplWin();

	public:
		virtual ~PluginFrameworkImplWin();
		static PluginFramework* create();

		virtual std::vector<std::string> findAllAvailableLibraries();
		virtual void loadLibrary(std::string libraryPath);
};

#endif
