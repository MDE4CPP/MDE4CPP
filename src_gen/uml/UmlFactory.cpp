#include "UmlFactory.hpp"
#include "impl/UmlFactoryImpl.hpp"

using namespace uml;

//static initialisation
UmlFactory * UmlFactory::instance = nullptr;

UmlFactory * UmlFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Factoryimplementation
		instance = UmlFactoryImpl::create();
		dynamic_cast<UmlFactoryImpl * >(instance)->init();
	}	
	return instance;
}
