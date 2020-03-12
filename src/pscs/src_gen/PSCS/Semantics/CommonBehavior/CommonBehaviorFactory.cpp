#include "PSCS/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

using namespace PSCS::Semantics::CommonBehavior;
				 
//static initialisation
std::shared_ptr<CommonBehaviorFactory> CommonBehaviorFactory::instance;

std::shared_ptr<CommonBehaviorFactory> CommonBehaviorFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(CommonBehaviorFactoryImpl::create());
	}	
	return instance;
}
