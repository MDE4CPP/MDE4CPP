#include "FoundationalModelLibrary/PrimitiveBehaviors/BooleanFunctions/BooleanFunctionsPackage.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/BooleanFunctions/impl/BooleanFunctionsPackageImpl.hpp"

using namespace FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions;

//static initialisation
const std::string BooleanFunctionsPackage::eNAME ="BooleanFunctions";
const std::string BooleanFunctionsPackage::eNS_URI ="";
const std::string BooleanFunctionsPackage::eNS_PREFIX ="PrimitiveBehaviors";

//Singleton 
std::shared_ptr<BooleanFunctionsPackage> BooleanFunctionsPackage::instance;

std::shared_ptr<BooleanFunctionsPackage> BooleanFunctionsPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(BooleanFunctionsPackageImpl::create());
		std::dynamic_pointer_cast<BooleanFunctionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
