
#include "CalcModel/CalcModelPlugin.hpp"
#include "CalcModel/impl/CalcModelPluginImpl.hpp"

using namespace CalcModel;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> CalcModelPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> CalcModelPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new CalcModelPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return CalcModelPlugin::eInstance();
}
