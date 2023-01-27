#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
//#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"

using namespace fUML::Semantics::StructuredClassifiers;
				 
//static initialisation
//std::shared_ptr<StructuredClassifiersFactory> StructuredClassifiersFactory::eInstance()
{
	static std::shared_ptr<StructuredClassifiersFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(StructuredClassifiersFactoryImpl::create());
	}	
	return instance;
}
