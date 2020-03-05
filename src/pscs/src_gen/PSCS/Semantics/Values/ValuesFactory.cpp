#include "PSCS/Semantics/Values/ValuesFactory.hpp"
#include "PSCS/Semantics/Values/impl/ValuesFactoryImpl.hpp"

using namespace PSCS::Semantics::Values;
				 
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
