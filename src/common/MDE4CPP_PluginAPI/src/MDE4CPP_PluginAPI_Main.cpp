#include "MDE4CPP_PluginAPI.hpp"
#include "pluginFramework/PluginFramework.hpp"
#include <atomic>
#include <chrono>
#include <csignal>
#include <thread>

static std::atomic_bool g_running{true};

static void handleSignal(int)
{
	g_running = false;
}

int main() {
	std::signal(SIGINT, handleSignal);
	std::signal(SIGTERM, handleSignal);

	std::shared_ptr<PluginFramework> pluginFw = PluginFramework::eInstance();
	std::shared_ptr<GenericApi> api_obj = GenericApi::eInstance(pluginFw); //starts API

	// Keep process alive (Crow server may run on worker threads)
	while(g_running)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	return 0;
}
