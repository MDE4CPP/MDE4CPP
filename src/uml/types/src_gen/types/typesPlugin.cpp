
#include "types/typesPlugin.hpp"
#include "types/impl/typesPluginImpl.hpp"

using namespace types;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> typesPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> typesPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new typesPluginImpl());
	}
	return instance;
}

TYPES_API std::shared_ptr<MDE4CPPPlugin> start()
{
	return typesPlugin::eInstance();
}
