#include "SubsetUnionBenchmarkFactory.hpp"
#include "impl/SubsetUnionBenchmarkFactoryImpl.hpp"

using namespace subsetUnionBenchmark;

//static initialisation
std::shared_ptr<SubsetUnionBenchmarkFactory> SubsetUnionBenchmarkFactory::instance;

std::shared_ptr<SubsetUnionBenchmarkFactory>SubsetUnionBenchmarkFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(SubsetUnionBenchmarkFactoryImpl::create());
		std::dynamic_pointer_cast<SubsetUnionBenchmarkFactoryImpl>(instance)->init();
	}	
	return instance;
}
