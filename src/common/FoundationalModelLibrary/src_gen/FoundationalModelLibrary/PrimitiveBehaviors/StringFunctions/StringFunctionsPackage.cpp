#include "FoundationalModelLibrary/PrimitiveBehaviors/StringFunctions/StringFunctionsPackage.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/StringFunctions/impl/StringFunctionsPackageImpl.hpp"

using namespace FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions;

//static initialisation
const std::string StringFunctionsPackage::eNAME ="StringFunctions";
const std::string StringFunctionsPackage::eNS_URI ="";
const std::string StringFunctionsPackage::eNS_PREFIX ="PrimitiveBehaviors";

//Singleton 
std::shared_ptr<StringFunctionsPackage> StringFunctionsPackage::instance;

std::shared_ptr<StringFunctionsPackage> StringFunctionsPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(StringFunctionsPackageImpl::create());
		std::dynamic_pointer_cast<StringFunctionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
