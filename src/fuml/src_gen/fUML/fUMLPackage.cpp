#include "fUML/fUMLPackage.hpp"
#include "fUML/impl/fUMLPackageImpl.hpp"

using namespace fUML;

//static initialisation
const std::string fUMLPackage::eNAME ="fUML";
const std::string fUMLPackage::eNS_URI ="http://www.omg.org/spec/FUML/20180501";
const std::string fUMLPackage::eNS_PREFIX ="fUML_Semantics";

//Singleton 
std::shared_ptr<fUMLPackage> fUMLPackage::instance;

std::shared_ptr<fUMLPackage> fUMLPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(fUMLPackageImpl::create());
		std::dynamic_pointer_cast<fUMLPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
