
#include "fUMLMultiplePins/FUMLMultiplePinsPlugin.hpp"
#include "fUMLMultiplePins/impl/FUMLMultiplePinsPluginImpl.hpp"

using namespace fUMLMultiplePins;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> FUMLMultiplePinsPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> FUMLMultiplePinsPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new FUMLMultiplePinsPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return FUMLMultiplePinsPlugin::eInstance();
}
