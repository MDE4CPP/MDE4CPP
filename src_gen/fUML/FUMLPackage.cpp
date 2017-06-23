#include "FUMLPackage.hpp"
#include "impl/FUMLPackageImpl.hpp"

using namespace fUML;

//static initialisation
const std::string FUMLPackage::eNAME ="fUML";
const std::string FUMLPackage::eNS_URI ="http://www.eclipse.org/emf/2002/fUML";
const std::string FUMLPackage::eNS_PREFIX ="fUML";

//Singleton 
std::shared_ptr<FUMLPackage> FUMLPackage::instance;

std::shared_ptr<FUMLPackage>FUMLPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(FUMLPackageImpl::create());
		std::dynamic_pointer_cast<FUMLPackageImpl>(instance)->init();
	}	
	return instance;
}
