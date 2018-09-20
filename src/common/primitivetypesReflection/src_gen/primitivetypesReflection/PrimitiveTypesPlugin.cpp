
#include "primitivetypesReflection/PrimitiveTypesPlugin.hpp"
#include "primitivetypesReflection/impl/PrimitiveTypesPluginImpl.hpp"

using namespace PrimitiveTypes;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> PrimitiveTypesPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> PrimitiveTypesPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new PrimitiveTypesPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return PrimitiveTypesPlugin::eInstance();
}
