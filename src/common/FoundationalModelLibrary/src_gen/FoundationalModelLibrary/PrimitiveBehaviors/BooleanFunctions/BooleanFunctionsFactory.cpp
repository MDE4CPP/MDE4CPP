
#include "FoundationalModelLibrary/PrimitiveBehaviors/BooleanFunctions/BooleanFunctionsFactory.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/BooleanFunctions/impl/BooleanFunctionsFactoryImpl.hpp"

using namespace FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions;

//static initialisation
std::shared_ptr<BooleanFunctionsFactory> BooleanFunctionsFactory::instance;

std::shared_ptr<BooleanFunctionsFactory> BooleanFunctionsFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(BooleanFunctionsFactoryImpl::create());
	}	
	return instance;
}
