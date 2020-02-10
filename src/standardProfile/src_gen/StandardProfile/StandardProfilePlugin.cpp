
#include "StandardProfile/StandardProfilePlugin.hpp"
#include "StandardProfile/impl/StandardProfilePluginImpl.hpp"

using namespace StandardProfile;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> StandardProfilePlugin::instance;

std::shared_ptr<MDE4CPPPlugin> StandardProfilePlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new StandardProfilePluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return StandardProfilePlugin::eInstance();
}
