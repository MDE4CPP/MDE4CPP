#include "EcoreFactory.hpp"
#include "impl/EcoreFactoryImpl.hpp"

using namespace ecore;

//static initialisation
EcoreFactory * EcoreFactory::instance = nullptr;

EcoreFactory * EcoreFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Factoryimplementation
		instance = EcoreFactoryImpl::create();
		dynamic_cast<EcoreFactoryImpl * >(instance)->init();
	}	
	return instance;
}
