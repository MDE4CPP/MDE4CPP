#include "uml/UmlFactory.hpp"
#include "uml/impl/UmlFactoryImpl.hpp"

using namespace uml;
				 
//static initialisation
std::shared_ptr<UmlFactory> UmlFactory::instance;

std::shared_ptr<UmlFactory> UmlFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(UmlFactoryImpl::create());
	}	
	return instance;
}
