#include "fUML/Semantics/Classification/ClassificationFactory.hpp"
#include "fUML/Semantics/Classification/impl/ClassificationFactoryImpl.hpp"

using namespace fUML::Semantics::Classification;
				 
//static initialisation
std::shared_ptr<ClassificationFactory> ClassificationFactory::instance;

std::shared_ptr<ClassificationFactory> ClassificationFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ClassificationFactoryImpl::create());
	}	
	return instance;
}
