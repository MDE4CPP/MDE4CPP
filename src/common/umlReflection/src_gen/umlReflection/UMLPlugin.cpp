
#include "umlReflection/UMLPlugin.hpp"
#include "umlReflection/impl/UMLPluginImpl.hpp"

using namespace UML;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> UMLPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> UMLPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new UMLPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return UMLPlugin::eInstance();
}
