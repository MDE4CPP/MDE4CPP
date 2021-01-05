#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"

using namespace fUML::Semantics::Activities;
				 
//static initialisation
std::shared_ptr<ActivitiesFactory> ActivitiesFactory::instance;

std::shared_ptr<ActivitiesFactory> ActivitiesFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ActivitiesFactoryImpl::create());
	}	
	return instance;
}
