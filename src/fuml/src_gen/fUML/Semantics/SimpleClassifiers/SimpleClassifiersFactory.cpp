#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersFactoryImpl.hpp"

using namespace fUML::Semantics::SimpleClassifiers;
				 
//static initialisation
std::shared_ptr<SimpleClassifiersFactory> SimpleClassifiersFactory::instance;

std::shared_ptr<SimpleClassifiersFactory> SimpleClassifiersFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(SimpleClassifiersFactoryImpl::create());
	}	
	return instance;
}
