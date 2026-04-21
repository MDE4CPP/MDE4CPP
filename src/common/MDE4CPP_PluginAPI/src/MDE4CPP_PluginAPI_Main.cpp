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
	try {
		std::signal(SIGINT, handleSignal);
		std::signal(SIGTERM, handleSignal);

		std::cout << "Initializing PluginFramework..." << std::endl;
		std::cout.flush();
		std::shared_ptr<PluginFramework> pluginFw = PluginFramework::eInstance();
		
		std::cout << "Initializing GenericApi (this starts the HTTP server)..." << std::endl;
		std::cout.flush();
		std::shared_ptr<GenericApi> api_obj = GenericApi::eInstance(pluginFw); //starts API

		std::cout << "Plugin API server started. Main thread entering wait loop..." << std::endl;
		std::cout.flush();

		// Keep process alive (Crow server may run on worker threads)
		while(g_running)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		
		std::cout << "Shutting down..." << std::endl;
		std::cout.flush();
		return 0;
	} catch(const std::exception& e) {
		std::cerr << "FATAL EXCEPTION in main(): " << e.what() << std::endl;
		std::cerr.flush();
		return 1;
	} catch(...) {
		std::cerr << "FATAL EXCEPTION in main(): unknown error" << std::endl;
		std::cerr.flush();
		return 1;
	}
}
