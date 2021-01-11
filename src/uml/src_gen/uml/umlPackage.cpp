#include "uml/umlPackage.hpp"
#include "uml/impl/umlPackageImpl.hpp"

using namespace uml;

//static initialisation
const std::string umlPackage::eNAME ="uml";
const std::string umlPackage::eNS_URI ="http://www.eclipse.org/uml2/5.0.0/UML";
const std::string umlPackage::eNS_PREFIX ="uml";

//Singleton 
std::shared_ptr<umlPackage> umlPackage::instance;

std::shared_ptr<umlPackage> umlPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(umlPackageImpl::create());
		std::dynamic_pointer_cast<umlPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
