#include "fUML/FUMLFactory.hpp"
#include "fUML/impl/FUMLFactoryImpl.hpp"

using namespace fUML;
				 
//static initialisation
std::shared_ptr<FUMLFactory> FUMLFactory::instance;

std::shared_ptr<FUMLFactory> FUMLFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(FUMLFactoryImpl::create());
	}	
	return instance;
}
