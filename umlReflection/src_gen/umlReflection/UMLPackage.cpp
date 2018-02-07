#include "umlReflection/UMLPackage.hpp"
#include "umlReflection/impl/UMLPackageImpl.hpp"

using namespace UML;

//static initialisation
const std::string UMLPackage::eNAME ="UML";
const std::string UMLPackage::eNS_URI ="http://www.omg.org/spec/UML/20131001";
const std::string UMLPackage::eNS_PREFIX ="";

//Singleton 
std::shared_ptr<UMLPackage> UMLPackage::instance;

std::shared_ptr<UMLPackage> UMLPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(UMLPackageImpl::create());
		std::dynamic_pointer_cast<UMLPackageImpl>(instance)->init();
	}	
	return instance;
}
