/*
 * PluginFrameworkImplApple.hpp
 *
 *  Created on: 23.03.2018
 *      Author: wichmann
 */

#ifndef PLUGINFRAMEWORK_PLUGINFRAMEWORKIMPLAPPLE_HPP
#define PLUGINFRAMEWORK_PLUGINFRAMEWORKIMPLAPPLE_HPP

#include "pluginFramework/impl/PluginFrameworkImpl.hpp"

class PluginFrameworkImplApple: virtual public PluginFrameworkImpl
{
	private:
		PluginFrameworkImplApple(PluginFrameworkImplApple const&) = delete;
		PluginFrameworkImplApple& operator=(PluginFrameworkImplApple const&) = delete;

	protected:
		friend class PluginFramework;
		PluginFrameworkImplApple();

	public:
		virtual ~PluginFrameworkImplApple();
		static PluginFramework* create();

		virtual std::vector<std::string> findAllAvailableLibraries();
		virtual void loadLibrary(std::string libraryPath);
};

#endif
