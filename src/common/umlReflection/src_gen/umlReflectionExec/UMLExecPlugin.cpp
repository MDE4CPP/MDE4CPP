
#include "umlReflectionExec/UMLExecPlugin.hpp"
#include "umlReflectionExec/impl/UMLExecPluginImpl.hpp"

using namespace UML;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> UMLExecPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> UMLExecPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new UMLExecPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return UMLExecPlugin::eInstance();
}
