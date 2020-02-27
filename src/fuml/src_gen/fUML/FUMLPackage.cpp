#include "fUML/FUMLPackage.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

using namespace fUML;

//static initialisation
const std::string FUMLPackage::eNAME ="fUML";
const std::string FUMLPackage::eNS_URI ="http://www.omg.org/spec/FUML/20180501";
const std::string FUMLPackage::eNS_PREFIX ="fUML_Semantics";

//Singleton 
std::shared_ptr<FUMLPackage> FUMLPackage::instance;

std::shared_ptr<FUMLPackage> FUMLPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(FUMLPackageImpl::create());
		std::dynamic_pointer_cast<FUMLPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
