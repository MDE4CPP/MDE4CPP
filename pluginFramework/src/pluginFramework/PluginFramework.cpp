/*
 * PluginFramework.cpp
 *
 *  Created on: 21.06.2017
 *      Author: alwi0251
 */

#include "pluginFramework/PluginFramework.hpp"

#ifdef _WIN32
	#include "pluginFramework/impl/PluginFrameworkImplWin.hpp"
#elif __linux__
	#include "pluginFramework/impl/PluginFrameworkImplLinux.hpp"
#elif __APPLE__
	#include "pluginFramework/impl/PluginFrameworkImplApple.hpp"
#else
	#include "pluginFramework/impl/PluginFrameworkImpl.hpp"
#endif

std::shared_ptr<PluginFramework> PluginFramework::instance;

std::shared_ptr<PluginFramework> PluginFramework::eInstance()
{
	if (instance == nullptr)
	{
#ifdef _WIN32
		instance.reset(PluginFrameworkImplWin::create());
#elif __linux__
		instance.reset(PluginFrameworkImplLinux::create());
#elif __APPLE__
		instance.reset(PluginFrameworkImplApple::create());
#else
		instance.reset(PluginFrameworkImpl::create());
#endif
	}
	return instance;
}
