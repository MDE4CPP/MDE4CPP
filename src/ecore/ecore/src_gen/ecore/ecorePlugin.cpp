
#include "ecore/ecorePlugin.hpp"
#include "ecore/impl/ecorePluginImpl.hpp"

using namespace ecore;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> ecorePlugin::instance;

std::shared_ptr<MDE4CPPPlugin> ecorePlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new ecorePluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return ecorePlugin::eInstance();
}
