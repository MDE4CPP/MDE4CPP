#include "Actions/ActionsFactory.hpp"
#include "Actions/impl/ActionsFactoryImpl.hpp"

using namespace Actions;

//static initialisation
std::shared_ptr<ActionsFactory> ActionsFactory::instance;

std::shared_ptr<ActionsFactory>ActionsFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ActionsFactoryImpl::create());
	}	
	return instance;
}
