#include "FoundationalModelLibrary/PrimitiveBehaviors/RealFunctions/RealFunctionsPackage.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/RealFunctions/impl/RealFunctionsPackageImpl.hpp"

using namespace FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions;

//static initialisation
const std::string RealFunctionsPackage::eNAME ="RealFunctions";
const std::string RealFunctionsPackage::eNS_URI ="";
const std::string RealFunctionsPackage::eNS_PREFIX ="PrimitiveBehaviors";

//Singleton 
std::shared_ptr<RealFunctionsPackage> RealFunctionsPackage::instance;

std::shared_ptr<RealFunctionsPackage> RealFunctionsPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(RealFunctionsPackageImpl::create());
		std::dynamic_pointer_cast<RealFunctionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
