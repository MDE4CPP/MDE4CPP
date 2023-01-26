
#include "FoundationalModelLibrary/PrimitiveBehaviors/StringFunctions/StringFunctionsFactory.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/StringFunctions/impl/StringFunctionsFactoryImpl.hpp"

using namespace FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions;

//static initialisation
std::shared_ptr<StringFunctionsFactory> StringFunctionsFactory::instance;

std::shared_ptr<StringFunctionsFactory> StringFunctionsFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(StringFunctionsFactoryImpl::create());
	}	
	return instance;
}
