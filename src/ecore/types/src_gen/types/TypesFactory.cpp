#include "types/TypesFactory.hpp"
#include "types/impl/TypesFactoryImpl.hpp"

using namespace types;

//static initialisation
std::shared_ptr<TypesFactory> TypesFactory::instance;

std::shared_ptr<TypesFactory>TypesFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(TypesFactoryImpl::create());
	}	
	return instance;
}
