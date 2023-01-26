
#include "FoundationalModelLibrary/PrimitiveBehaviors/IntegerFunctions/IntegerFunctionsFactory.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/IntegerFunctions/impl/IntegerFunctionsFactoryImpl.hpp"

using namespace FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions;

//static initialisation
std::shared_ptr<IntegerFunctionsFactory> IntegerFunctionsFactory::instance;

std::shared_ptr<IntegerFunctionsFactory> IntegerFunctionsFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(IntegerFunctionsFactoryImpl::create());
	}	
	return instance;
}
