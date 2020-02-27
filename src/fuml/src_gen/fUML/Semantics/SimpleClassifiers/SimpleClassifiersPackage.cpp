#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersPackageImpl.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

//static initialisation
const std::string SimpleClassifiersPackage::eNAME ="SimpleClassifiers";
const std::string SimpleClassifiersPackage::eNS_URI ="http:///fUML_Semantics/Semantics/SimpleClassifiers.ecore";
const std::string SimpleClassifiersPackage::eNS_PREFIX ="fUML_Semantics.Semantics.SimpleClassifiers";

//Singleton 
std::shared_ptr<SimpleClassifiersPackage> SimpleClassifiersPackage::instance;

std::shared_ptr<SimpleClassifiersPackage> SimpleClassifiersPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(SimpleClassifiersPackageImpl::create());
		std::dynamic_pointer_cast<SimpleClassifiersPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
