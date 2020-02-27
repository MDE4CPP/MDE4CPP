#include "Semantics/SemanticsFactory.hpp"
#include "Semantics/impl/SemanticsFactoryImpl.hpp"

using namespace Semantics;

//static initialisation
std::shared_ptr<SemanticsFactory> SemanticsFactory::instance;

std::shared_ptr<SemanticsFactory>SemanticsFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(SemanticsFactoryImpl::create());
	}	
	return instance;
}
