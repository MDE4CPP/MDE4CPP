#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"

using namespace ocl::Expressions;
				 
//static initialisation
std::shared_ptr<ExpressionsFactory> ExpressionsFactory::instance;

std::shared_ptr<ExpressionsFactory> ExpressionsFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ExpressionsFactoryImpl::create());
	}	
	return instance;
}
