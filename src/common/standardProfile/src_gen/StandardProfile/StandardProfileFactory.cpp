
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfileFactoryImpl.hpp"

using namespace StandardProfile;

//static initialisation
std::shared_ptr<StandardProfileFactory> StandardProfileFactory::instance;

std::shared_ptr<StandardProfileFactory> StandardProfileFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(StandardProfileFactoryImpl::create());
	}	
	return instance;
}
