#include "TypesFactory.hpp"
#include "impl/TypesFactoryImpl.hpp"

using namespace types;

//static initialisation
std::shared_ptr<TypesFactory> TypesFactory::instance;

std::shared_ptr<TypesFactory> TypesFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(TypesFactoryImpl::create());
		std::dynamic_pointer_cast<TypesFactoryImpl>(instance)->init();
	}	
	return instance;
}
