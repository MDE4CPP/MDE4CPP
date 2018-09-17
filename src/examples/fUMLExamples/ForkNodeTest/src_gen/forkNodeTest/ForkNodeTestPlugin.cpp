
#include "forkNodeTest/ForkNodeTestPlugin.hpp"
#include "forkNodeTest/impl/ForkNodeTestPluginImpl.hpp"

using namespace forkNodeTest;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> ForkNodeTestPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> ForkNodeTestPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new ForkNodeTestPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return ForkNodeTestPlugin::eInstance();
}
