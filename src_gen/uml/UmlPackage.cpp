#include "UmlPackage.hpp"
#include "impl/UmlPackageImpl.hpp"

using namespace uml;

//static initialisation
const std::string UmlPackage::eNAME ="uml";
const std::string UmlPackage::eNS_URI ="http://www.eclipse.org/uml2/5.0.0/UML";
const std::string UmlPackage::eNS_PREFIX ="uml";

//Singleton 
UmlPackage * UmlPackage::instance = nullptr;

UmlPackage * UmlPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Factoryimplementation
		instance = UmlPackageImpl::create();
		dynamic_cast<UmlPackageImpl * >(instance)->init();
	}	
	return instance;
}
