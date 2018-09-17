
#include "ecore/EcorePlugin.hpp"
#include "ecore/impl/EcorePluginImpl.hpp"

using namespace ecore;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> EcorePlugin::instance;

std::shared_ptr<MDE4CPPPlugin> EcorePlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new EcorePluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return EcorePlugin::eInstance();
}
