#include "FoundationalModelLibrary/PrimitiveBehaviors/UnlimitedNaturalFunctions/UnlimitedNaturalFunctionsPackage.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/UnlimitedNaturalFunctions/impl/UnlimitedNaturalFunctionsPackageImpl.hpp"

using namespace FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions;

//static initialisation
const std::string UnlimitedNaturalFunctionsPackage::eNAME ="UnlimitedNaturalFunctions";
const std::string UnlimitedNaturalFunctionsPackage::eNS_URI ="";
const std::string UnlimitedNaturalFunctionsPackage::eNS_PREFIX ="PrimitiveBehaviors";

//Singleton 
std::shared_ptr<UnlimitedNaturalFunctionsPackage> UnlimitedNaturalFunctionsPackage::instance;

std::shared_ptr<UnlimitedNaturalFunctionsPackage> UnlimitedNaturalFunctionsPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(UnlimitedNaturalFunctionsPackageImpl::create());
		std::dynamic_pointer_cast<UnlimitedNaturalFunctionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
