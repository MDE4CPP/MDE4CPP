#include "FoundationalModelLibrary/PrimitiveBehaviors/IntegerFunctions/IntegerFunctionsPackage.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/IntegerFunctions/impl/IntegerFunctionsPackageImpl.hpp"

using namespace FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions;

//static initialisation
const std::string IntegerFunctionsPackage::eNAME ="IntegerFunctions";
const std::string IntegerFunctionsPackage::eNS_URI ="";
const std::string IntegerFunctionsPackage::eNS_PREFIX ="PrimitiveBehaviors";

//Singleton 
std::shared_ptr<IntegerFunctionsPackage> IntegerFunctionsPackage::instance;

std::shared_ptr<IntegerFunctionsPackage> IntegerFunctionsPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(IntegerFunctionsPackageImpl::create());
		std::dynamic_pointer_cast<IntegerFunctionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
