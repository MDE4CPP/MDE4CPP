
#include "types/TypesPlugin.hpp"
#include "types/impl/TypesPluginImpl.hpp"

using namespace types;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> TypesPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> TypesPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new TypesPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return TypesPlugin::eInstance();
}
