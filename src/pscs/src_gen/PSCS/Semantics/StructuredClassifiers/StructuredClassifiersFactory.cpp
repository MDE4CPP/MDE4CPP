#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"

using namespace PSCS::Semantics::StructuredClassifiers;
				 
//static initialisation
std::shared_ptr<StructuredClassifiersFactory> StructuredClassifiersFactory::instance;

std::shared_ptr<StructuredClassifiersFactory> StructuredClassifiersFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(StructuredClassifiersFactoryImpl::create());
	}	
	return instance;
}
