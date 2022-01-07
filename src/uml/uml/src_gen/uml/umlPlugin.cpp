
#include "uml/umlPlugin.hpp"
#include "uml/impl/umlPluginImpl.hpp"

using namespace uml;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> umlPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> umlPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new umlPluginImpl());
	}
	return instance;
}

UML_API std::shared_ptr<MDE4CPPPlugin> start()
{
	return umlPlugin::eInstance();
}
