
#include "FoundationalModelLibrary/PrimitiveBehaviors/UnlimitedNaturalFunctions/UnlimitedNaturalFunctionsFactory.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/UnlimitedNaturalFunctions/impl/UnlimitedNaturalFunctionsFactoryImpl.hpp"

using namespace FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions;

//static initialisation
std::shared_ptr<UnlimitedNaturalFunctionsFactory> UnlimitedNaturalFunctionsFactory::instance;

std::shared_ptr<UnlimitedNaturalFunctionsFactory> UnlimitedNaturalFunctionsFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(UnlimitedNaturalFunctionsFactoryImpl::create());
	}	
	return instance;
}
