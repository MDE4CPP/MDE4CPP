#include "uml/umlFactory.hpp"
#include "uml/impl/umlFactoryImpl.hpp"

using namespace uml;
				 
//static initialisation
std::shared_ptr<umlFactory> umlFactory::instance;

std::shared_ptr<umlFactory> umlFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(umlFactoryImpl::create());
	}	
	return instance;
}
