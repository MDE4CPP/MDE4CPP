
#include "fUML/FUMLPlugin.hpp"
#include "fUML/impl/FUMLPluginImpl.hpp"

using namespace fUML;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> FUMLPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> FUMLPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new FUMLPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return FUMLPlugin::eInstance();
}
