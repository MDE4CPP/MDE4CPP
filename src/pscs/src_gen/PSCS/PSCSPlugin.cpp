
#include "PSCS/PSCSPlugin.hpp"
#include "PSCS/impl/PSCSPluginImpl.hpp"

using namespace PSCS;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> PSCSPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> PSCSPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new PSCSPluginImpl());
	}
	return instance;
}

PSCS_API std::shared_ptr<MDE4CPPPlugin> start()
{
	return PSCSPlugin::eInstance();
}
