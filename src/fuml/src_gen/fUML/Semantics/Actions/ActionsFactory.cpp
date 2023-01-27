#include "fUML/Semantics/Actions/ActionsFactory.hpp"
//#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"

using namespace fUML::Semantics::Actions;
				 
//static initialisation
//std::shared_ptr<ActionsFactory> ActionsFactory::eInstance()
{
	static std::shared_ptr<ActionsFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ActionsFactoryImpl::create());
	}	
	return instance;
}
