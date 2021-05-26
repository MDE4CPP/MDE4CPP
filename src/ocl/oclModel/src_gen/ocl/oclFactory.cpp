#include "ocl/oclFactory.hpp"
#include "ocl/impl/oclFactoryImpl.hpp"

using namespace ocl;
				 
//static initialisation
std::shared_ptr<oclFactory> oclFactory::instance;

std::shared_ptr<oclFactory> oclFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(oclFactoryImpl::create());
	}	
	return instance;
}
