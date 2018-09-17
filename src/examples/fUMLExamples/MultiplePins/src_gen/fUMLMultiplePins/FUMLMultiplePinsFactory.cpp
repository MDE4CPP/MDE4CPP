
#include "fUMLMultiplePins/FUMLMultiplePinsFactory.hpp"
#include "fUMLMultiplePins/impl/FUMLMultiplePinsFactoryImpl.hpp"

using namespace fUMLMultiplePins;

//static initialisation
std::shared_ptr<FUMLMultiplePinsFactory> FUMLMultiplePinsFactory::instance;

std::shared_ptr<FUMLMultiplePinsFactory> FUMLMultiplePinsFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(FUMLMultiplePinsFactoryImpl::create());
	}	
	return instance;
}
