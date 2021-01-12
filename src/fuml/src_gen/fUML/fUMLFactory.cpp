#include "fUML/fUMLFactory.hpp"
#include "fUML/impl/fUMLFactoryImpl.hpp"

using namespace fUML;
				 
//static initialisation
std::shared_ptr<fUMLFactory> fUMLFactory::instance;

std::shared_ptr<fUMLFactory> fUMLFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(fUMLFactoryImpl::create());
	}	
	return instance;
}
