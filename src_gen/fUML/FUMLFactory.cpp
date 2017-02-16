#include "FUMLFactory.hpp"
#include "impl/FUMLFactoryImpl.hpp"

using namespace fUML;

//static initialisation
FUMLFactory * FUMLFactory::instance = nullptr;

FUMLFactory * FUMLFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Factoryimplementation
		instance = FUMLFactoryImpl::create();
		dynamic_cast<FUMLFactoryImpl * >(instance)->init();
	}	
	return instance;
}
