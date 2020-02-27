#include "CommonBehavior/CommonBehaviorFactory.hpp"
#include "CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

using namespace CommonBehavior;

//static initialisation
std::shared_ptr<CommonBehaviorFactory> CommonBehaviorFactory::instance;

std::shared_ptr<CommonBehaviorFactory>CommonBehaviorFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(CommonBehaviorFactoryImpl::create());
	}	
	return instance;
}
