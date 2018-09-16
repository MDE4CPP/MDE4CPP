
#include "subsetUnionBenchmark/SubsetUnionBenchmarkPlugin.hpp"
#include "subsetUnionBenchmark/impl/SubsetUnionBenchmarkPluginImpl.hpp"

using namespace subsetUnionBenchmark;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> SubsetUnionBenchmarkPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> SubsetUnionBenchmarkPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new SubsetUnionBenchmarkPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return SubsetUnionBenchmarkPlugin::eInstance();
}
