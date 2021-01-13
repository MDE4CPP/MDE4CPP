#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "fUML/Semantics/Values/impl/ValuesFactoryImpl.hpp"

using namespace fUML::Semantics::Values;
				 
//static initialisation
std::shared_ptr<ValuesFactory> ValuesFactory::instance;

std::shared_ptr<ValuesFactory> ValuesFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ValuesFactoryImpl::create());
	}	
	return instance;
}
