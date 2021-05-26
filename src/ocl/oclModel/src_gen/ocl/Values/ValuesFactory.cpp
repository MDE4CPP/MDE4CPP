#include "ocl/Values/ValuesFactory.hpp"
#include "ocl/Values/impl/ValuesFactoryImpl.hpp"

using namespace ocl::Values;
				 
//static initialisation
std::shared_ptr<ValuesFactory> ValuesFactory::instance;

std::shared_ptr<ValuesFactory> ValuesFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ValuesFactoryImpl::create());
	}	
	return instance;
}
