/*
 * PluginFrameworkImplLinux.hpp
 *
 *  Created on: 23.03.2018
 *      Author: wichmann
 */

#ifndef PLUGINFRAMEWORK_PLUGINFRAMEWORKIMPLLINUX_HPP
#define PLUGINFRAMEWORK_PLUGINFRAMEWORKIMPLLINUX_HPP

#include "pluginFramework/impl/PluginFrameworkImpl.hpp"

class PluginFrameworkImplLinux: virtual public PluginFrameworkImpl
{
	private:
		PluginFrameworkImplLinux(PluginFrameworkImplLinux const&) = delete;
		PluginFrameworkImplLinux& operator=(PluginFrameworkImplLinux const&) = delete;

	protected:
		friend class PluginFramework;
		PluginFrameworkImplLinux();

	public:
		virtual ~PluginFrameworkImplLinux();
		static PluginFramework* create();

		virtual std::vector<std::string> findAllAvailableLibraries();
		virtual void loadLibrary(std::string libraryPath);
};

#endif
