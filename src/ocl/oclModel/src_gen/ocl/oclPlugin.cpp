
#include "ocl/oclPlugin.hpp"
#include "ocl/impl/oclPluginImpl.hpp"

using namespace ocl;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> oclPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> oclPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new oclPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return oclPlugin::eInstance();
}
