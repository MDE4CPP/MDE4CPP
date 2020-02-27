#include "StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"

using namespace StructuredClassifiers;

//static initialisation
std::shared_ptr<StructuredClassifiersFactory> StructuredClassifiersFactory::instance;

std::shared_ptr<StructuredClassifiersFactory>StructuredClassifiersFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(StructuredClassifiersFactoryImpl::create());
	}	
	return instance;
}
