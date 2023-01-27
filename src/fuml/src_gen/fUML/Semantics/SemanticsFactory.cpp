#include "fUML/Semantics/SemanticsFactory.hpp"
//#include "fUML/Semantics/impl/SemanticsFactoryImpl.hpp"

using namespace fUML::Semantics;
				 
//static initialisation
//std::shared_ptr<SemanticsFactory> SemanticsFactory::eInstance()
{
	static std::shared_ptr<SemanticsFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(SemanticsFactoryImpl::create());
	}	
	return instance;
}
