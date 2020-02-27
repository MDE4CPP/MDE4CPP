#include "ecore/EcoreFactory.hpp"
#include "ecore/impl/EcoreFactoryImpl.hpp"

using namespace ecore;
				 
//static initialisation
std::shared_ptr<EcoreFactory> EcoreFactory::instance;

std::shared_ptr<EcoreFactory> EcoreFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(EcoreFactoryImpl::create());
	}	
	return instance;
}
