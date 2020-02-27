#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/impl/SemanticsPackageImpl.hpp"

using namespace fUML::Semantics;

//static initialisation
const std::string SemanticsPackage::eNAME ="Semantics";
const std::string SemanticsPackage::eNS_URI ="http:///fUML_Semantics/Semantics.ecore";
const std::string SemanticsPackage::eNS_PREFIX ="fUML_Semantics.Semantics";

//Singleton 
std::shared_ptr<SemanticsPackage> SemanticsPackage::instance;

std::shared_ptr<SemanticsPackage> SemanticsPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(SemanticsPackageImpl::create());
		std::dynamic_pointer_cast<SemanticsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
