#include "MDE4CPP_PluginAPI.hpp"
#include "pluginFramework/PluginFramework.hpp"

int main() {
	std::shared_ptr<PluginFramework> pluginFw = PluginFramework::eInstance();
	std::shared_ptr<GenericApi> api_obj = GenericApi::eInstance(pluginFw); //starts API
}
