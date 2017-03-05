#include "FUMLFactory.hpp"
#include "impl/FUMLFactoryImpl.hpp"

using namespace fUML;

//static initialisation
std::shared_ptr<FUMLFactory> FUMLFactory::instance;

std::shared_ptr<FUMLFactory> FUMLFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(FUMLFactoryImpl::create());
		std::dynamic_pointer_cast<FUMLFactoryImpl>(instance)->init();
	}	
	return instance;
}
