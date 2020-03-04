#include "PSCS/PSCSFactory.hpp"
#include "PSCS/impl/PSCSFactoryImpl.hpp"

using namespace PSCS;
				 
//static initialisation
std::shared_ptr<PSCSFactory> PSCSFactory::instance;

std::shared_ptr<PSCSFactory> PSCSFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(PSCSFactoryImpl::create());
	}	
	return instance;
}
