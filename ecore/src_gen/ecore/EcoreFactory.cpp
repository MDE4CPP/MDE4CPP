#include "EcoreFactory.hpp"
#include "impl/EcoreFactoryImpl.hpp"

using namespace ecore;

//static initialisation
std::shared_ptr<EcoreFactory> EcoreFactory::instance;

std::shared_ptr<EcoreFactory>EcoreFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(EcoreFactoryImpl::create());
		std::dynamic_pointer_cast<EcoreFactoryImpl>(instance)->init();
	}	
	return instance;
}
