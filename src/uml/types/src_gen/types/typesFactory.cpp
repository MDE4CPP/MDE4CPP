#include "types/typesFactory.hpp"
//#include "types/impl/typesFactoryImpl.hpp"

using namespace types;
				 
//static initialisation
//std::shared_ptr<typesFactory> typesFactory::eInstance()
{
	static std::shared_ptr<typesFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(typesFactoryImpl::create());
	}	
	return instance;
}
