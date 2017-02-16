#include "TypesFactory.hpp"
#include "impl/TypesFactoryImpl.hpp"

using namespace types;

//static initialisation
TypesFactory * TypesFactory::instance = nullptr;

TypesFactory * TypesFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Factoryimplementation
		instance = TypesFactoryImpl::create();
		dynamic_cast<TypesFactoryImpl * >(instance)->init();
	}	
	return instance;
}
