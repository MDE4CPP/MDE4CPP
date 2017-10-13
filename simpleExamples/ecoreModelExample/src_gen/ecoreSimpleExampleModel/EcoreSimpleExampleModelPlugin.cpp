
#include "EcoreSimpleExampleModelPlugin.hpp"
#include "impl/EcoreSimpleExampleModelPluginImpl.hpp"

using namespace ecoreSimpleExampleModel;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> EcoreSimpleExampleModelPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> EcoreSimpleExampleModelPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new EcoreSimpleExampleModelPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return EcoreSimpleExampleModelPlugin::eInstance();
}
