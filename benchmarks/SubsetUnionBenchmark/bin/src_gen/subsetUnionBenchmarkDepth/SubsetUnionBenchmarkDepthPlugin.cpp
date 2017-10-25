
#include "SubsetUnionBenchmarkDepthPlugin.hpp"
#include "impl/SubsetUnionBenchmarkDepthPluginImpl.hpp"

using namespace subsetUnionBenchmarkDepth;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> SubsetUnionBenchmarkDepthPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> SubsetUnionBenchmarkDepthPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new SubsetUnionBenchmarkDepthPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return SubsetUnionBenchmarkDepthPlugin::eInstance();
}
