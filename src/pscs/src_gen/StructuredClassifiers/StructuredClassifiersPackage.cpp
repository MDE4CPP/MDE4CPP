#include "StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

using namespace StructuredClassifiers;

//static initialisation
const std::string StructuredClassifiersPackage::eNAME ="StructuredClassifiers";
const std::string StructuredClassifiersPackage::eNS_URI ="http:///PSCS_Semantics/Semantics/StructuredClassifiers.ecore";
const std::string StructuredClassifiersPackage::eNS_PREFIX ="PSCS_Semantics.Semantics.StructuredClassifiers";

//Singleton 
std::shared_ptr<StructuredClassifiersPackage> StructuredClassifiersPackage::instance;

std::shared_ptr<StructuredClassifiersPackage>StructuredClassifiersPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(StructuredClassifiersPackageImpl::create());
		std::dynamic_pointer_cast<StructuredClassifiersPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
