#include "EcoreSimpleExampleModelFactory.hpp"
#include "impl/EcoreSimpleExampleModelFactoryImpl.hpp"

using namespace ecoreSimpleExampleModel;

//static initialisation
std::shared_ptr<EcoreSimpleExampleModelFactory> EcoreSimpleExampleModelFactory::instance;

std::shared_ptr<EcoreSimpleExampleModelFactory>EcoreSimpleExampleModelFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(EcoreSimpleExampleModelFactoryImpl::create());
		std::dynamic_pointer_cast<EcoreSimpleExampleModelFactoryImpl>(instance)->init();
	}	
	return instance;
}
