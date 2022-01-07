
#include "fUML/fUMLPlugin.hpp"
#include "fUML/impl/fUMLPluginImpl.hpp"

using namespace fUML;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> fUMLPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> fUMLPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new fUMLPluginImpl());
	}
	return instance;
}

FUML_API std::shared_ptr<MDE4CPPPlugin> start()
{
	return fUMLPlugin::eInstance();
}
