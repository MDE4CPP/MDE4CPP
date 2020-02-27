#include "Semantics/SemanticsPackage.hpp"
#include "Semantics/impl/SemanticsPackageImpl.hpp"

using namespace Semantics;

//static initialisation
const std::string SemanticsPackage::eNAME ="Semantics";
const std::string SemanticsPackage::eNS_URI ="http:///PSCS_Semantics/Semantics.ecore";
const std::string SemanticsPackage::eNS_PREFIX ="PSCS_Semantics.Semantics";

//Singleton 
std::shared_ptr<SemanticsPackage> SemanticsPackage::instance;

std::shared_ptr<SemanticsPackage>SemanticsPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(SemanticsPackageImpl::create());
		std::dynamic_pointer_cast<SemanticsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
