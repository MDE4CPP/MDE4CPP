#include "ecore/ecoreFactory.hpp"
#include "ecore/impl/ecoreFactoryImpl.hpp"

using namespace ecore;
				 
//static initialisation
std::shared_ptr<ecoreFactory> ecoreFactory::instance;

std::shared_ptr<ecoreFactory> ecoreFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ecoreFactoryImpl::create());
	}	
	return instance;
}
