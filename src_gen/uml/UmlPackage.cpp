#include "uml/UmlPackage.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

using namespace uml;

//static initialisation
const std::string UmlPackage::eNAME ="uml";
const std::string UmlPackage::eNS_URI ="http://www.eclipse.org/uml2/5.0.0/UML";
const std::string UmlPackage::eNS_PREFIX ="uml";

//Singleton 
std::shared_ptr<UmlPackage> UmlPackage::instance;

std::shared_ptr<UmlPackage>UmlPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(UmlPackageImpl::create());
		std::dynamic_pointer_cast<UmlPackageImpl>(instance)->init();
	}	
	return instance;
}
