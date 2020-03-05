#include "PSCS/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

using namespace PSCS::Semantics::CommonBehavior;

//static initialisation
const std::string CommonBehaviorPackage::eNAME ="CommonBehavior";
const std::string CommonBehaviorPackage::eNS_URI ="http:///PSCS_Semantics/Semantics/CommonBehavior.ecore";
const std::string CommonBehaviorPackage::eNS_PREFIX ="PSCS_Semantics.Semantics.CommonBehavior";

//Singleton 
std::shared_ptr<CommonBehaviorPackage> CommonBehaviorPackage::instance;

std::shared_ptr<CommonBehaviorPackage> CommonBehaviorPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(CommonBehaviorPackageImpl::create());
		std::dynamic_pointer_cast<CommonBehaviorPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
