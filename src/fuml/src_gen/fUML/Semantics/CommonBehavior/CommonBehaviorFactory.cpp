#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
//#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

using namespace fUML::Semantics::CommonBehavior;
				 
//static initialisation
//std::shared_ptr<CommonBehaviorFactory> CommonBehaviorFactory::eInstance()
{
	static std::shared_ptr<CommonBehaviorFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(CommonBehaviorFactoryImpl::create());
	}	
	return instance;
}
