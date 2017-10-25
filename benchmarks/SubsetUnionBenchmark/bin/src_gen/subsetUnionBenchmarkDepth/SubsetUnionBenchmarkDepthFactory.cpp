#include "SubsetUnionBenchmarkDepthFactory.hpp"
#include "impl/SubsetUnionBenchmarkDepthFactoryImpl.hpp"

using namespace subsetUnionBenchmarkDepth;

//static initialisation
std::shared_ptr<SubsetUnionBenchmarkDepthFactory> SubsetUnionBenchmarkDepthFactory::instance;

std::shared_ptr<SubsetUnionBenchmarkDepthFactory>SubsetUnionBenchmarkDepthFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(SubsetUnionBenchmarkDepthFactoryImpl::create());
		std::dynamic_pointer_cast<SubsetUnionBenchmarkDepthFactoryImpl>(instance)->init();
	}	
	return instance;
}
