#include <iostream>

#include "pluginFramework/PluginFramework.hpp"
#include "pluginFramework/MDE4CPPPlugin.hpp"

int main()
{
	std::shared_ptr<PluginFramework> pluginFramework = PluginFramework::eInstance();

	// plugin searching test
	std::string name = "ecore";
	std::shared_ptr<MDE4CPPPlugin> plugin = pluginFramework->findPluginByName(name);

	if (plugin)
	{
		std::cout << "plugin " << plugin->eNAME() << " found" << std::endl;
	}

	std::cout << "DONE" << std::endl;
	
    return 0;
}
