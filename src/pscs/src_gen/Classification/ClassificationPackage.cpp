#include "Classification/ClassificationPackage.hpp"
#include "Classification/impl/ClassificationPackageImpl.hpp"

using namespace Classification;

//static initialisation
const std::string ClassificationPackage::eNAME ="Classification";
const std::string ClassificationPackage::eNS_URI ="http:///PSCS_Semantics/Semantics/Classification.ecore";
const std::string ClassificationPackage::eNS_PREFIX ="PSCS_Semantics.Semantics.Classification";

//Singleton 
std::shared_ptr<ClassificationPackage> ClassificationPackage::instance;

std::shared_ptr<ClassificationPackage>ClassificationPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ClassificationPackageImpl::create());
		std::dynamic_pointer_cast<ClassificationPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
