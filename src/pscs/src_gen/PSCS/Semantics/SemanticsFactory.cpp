#include "PSCS/Semantics/SemanticsFactory.hpp"
#include "PSCS/Semantics/impl/SemanticsFactoryImpl.hpp"

using namespace PSCS::Semantics;
				 
//static initialisation
std::shared_ptr<SemanticsFactory> SemanticsFactory::instance;

std::shared_ptr<SemanticsFactory> SemanticsFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(SemanticsFactoryImpl::create());
	}	
	return instance;
}
