#include "types/typesFactory.hpp"
#include "types/impl/typesFactoryImpl.hpp"

using namespace types;
				 
//static initialisation
std::shared_ptr<typesFactory> typesFactory::instance;

std::shared_ptr<typesFactory> typesFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(typesFactoryImpl::create());
	}	
	return instance;
}
