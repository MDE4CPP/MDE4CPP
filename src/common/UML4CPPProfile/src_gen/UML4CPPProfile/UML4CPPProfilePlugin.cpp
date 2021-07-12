
#include "UML4CPPProfile/UML4CPPProfilePlugin.hpp"
#include "UML4CPPProfile/impl/UML4CPPProfilePluginImpl.hpp"

using namespace UML4CPPProfile;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> UML4CPPProfilePlugin::instance;

std::shared_ptr<MDE4CPPPlugin> UML4CPPProfilePlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new UML4CPPProfilePluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return UML4CPPProfilePlugin::eInstance();
}
