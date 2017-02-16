#include "FUMLPackage.hpp"
#include "impl/FUMLPackageImpl.hpp"

using namespace fUML;

//static initialisation
const std::string FUMLPackage::eNAME ="fUML";
const std::string FUMLPackage::eNS_URI ="http://www.eclipse.org/emf/2002/fUML";
const std::string FUMLPackage::eNS_PREFIX ="fUML";

//Singleton 
FUMLPackage * FUMLPackage::instance = nullptr;

FUMLPackage * FUMLPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Factoryimplementation
		instance = FUMLPackageImpl::create();
		dynamic_cast<FUMLPackageImpl * >(instance)->init();
	}	
	return instance;
}
