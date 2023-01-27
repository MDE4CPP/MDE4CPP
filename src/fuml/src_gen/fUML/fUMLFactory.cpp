#include "fUML/fUMLFactory.hpp"
//#include "fUML/impl/fUMLFactoryImpl.hpp"

using namespace fUML;
				 
//static initialisation
//std::shared_ptr<fUMLFactory> fUMLFactory::eInstance()
{
	static std::shared_ptr<fUMLFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(fUMLFactoryImpl::create());
	}	
	return instance;
}
