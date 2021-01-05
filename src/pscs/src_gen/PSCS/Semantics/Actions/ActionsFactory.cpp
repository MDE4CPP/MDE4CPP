#include "PSCS/Semantics/Actions/ActionsFactory.hpp"
#include "PSCS/Semantics/Actions/impl/ActionsFactoryImpl.hpp"

using namespace PSCS::Semantics::Actions;
				 
//static initialisation
std::shared_ptr<ActionsFactory> ActionsFactory::instance;

std::shared_ptr<ActionsFactory> ActionsFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ActionsFactoryImpl::create());
	}	
	return instance;
}
