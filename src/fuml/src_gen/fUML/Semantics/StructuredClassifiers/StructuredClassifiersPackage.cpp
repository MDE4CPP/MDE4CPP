#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

using namespace fUML::Semantics::StructuredClassifiers;

//static initialisation
const std::string StructuredClassifiersPackage::eNAME ="StructuredClassifiers";
const std::string StructuredClassifiersPackage::eNS_URI ="http:///fUML_Semantics/Semantics/StructuredClassifiers.ecore";
const std::string StructuredClassifiersPackage::eNS_PREFIX ="fUML_Semantics.Semantics.StructuredClassifiers";

//Singleton 
std::shared_ptr<StructuredClassifiersPackage> StructuredClassifiersPackage::instance;

std::shared_ptr<StructuredClassifiersPackage> StructuredClassifiersPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(StructuredClassifiersPackageImpl::create());
		std::dynamic_pointer_cast<StructuredClassifiersPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
