
#include "UmlPlugin.hpp"
#include "impl/UmlPluginImpl.hpp"

using namespace uml;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> UmlPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> UmlPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new UmlPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return UmlPlugin::eInstance();
}
