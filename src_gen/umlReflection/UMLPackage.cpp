#include "UMLPackage.hpp"
#include "impl/UMLPackageImpl.hpp"

using namespace UML;

//static initialisation
const std::string UMLPackage::eNAME ="UML";
const std::string UMLPackage::eNS_URI ="http://www.omg.org/spec/UML/20131001";
const std::string UMLPackage::eNS_PREFIX ="invalid";

//Singleton 
UMLPackage * UMLPackage::instance = nullptr;

UMLPackage * UMLPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance = UMLPackageImpl::create();
		dynamic_cast<UMLPackageImpl * >(instance)->init();
	}	
	return instance;
}
