#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfileFactoryImpl.hpp"

using namespace StandardProfile;

//static initialisation
std::shared_ptr<StandardProfileFactory> StandardProfileFactory::instance;

std::shared_ptr<StandardProfileFactory>StandardProfileFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(StandardProfileFactoryImpl::create());
	}	
	return instance;
}
