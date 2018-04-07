/*
 * PluginFramework.cpp
 *
 *  Created on: 21.06.2017
 *      Author: alwi0251
 */

#include "pluginFramework/PluginFramework.hpp"
#include "pluginFramework/impl/PluginFrameworkImpl.hpp"

std::shared_ptr<PluginFramework> PluginFramework::instance;

std::shared_ptr<PluginFramework> PluginFramework::eInstance()
{
	if (instance == nullptr)
	{
		instance.reset(PluginFrameworkImpl::create());
	}
	return instance;
}
