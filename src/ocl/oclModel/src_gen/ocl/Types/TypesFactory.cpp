#include "ocl/Types/TypesFactory.hpp"
#include "ocl/Types/impl/TypesFactoryImpl.hpp"

using namespace ocl::Types;
				 
//static initialisation
std::shared_ptr<TypesFactory> TypesFactory::instance;

std::shared_ptr<TypesFactory> TypesFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(TypesFactoryImpl::create());
	}	
	return instance;
}
