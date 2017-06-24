
#include "CalcModelExecPlugin.hpp"
#include "impl/CalcModelExecPluginImpl.hpp"

using namespace CalcModel;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> CalcModelExecPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> CalcModelExecPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new CalcModelExecPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return CalcModelExecPlugin::eInstance();
}
