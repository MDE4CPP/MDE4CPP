
#include "FoundationalModelLibrary/PrimitiveBehaviors/RealFunctions/RealFunctionsFactory.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/RealFunctions/impl/RealFunctionsFactoryImpl.hpp"

using namespace FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions;

//static initialisation
std::shared_ptr<RealFunctionsFactory> RealFunctionsFactory::instance;

std::shared_ptr<RealFunctionsFactory> RealFunctionsFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(RealFunctionsFactoryImpl::create());
	}	
	return instance;
}
