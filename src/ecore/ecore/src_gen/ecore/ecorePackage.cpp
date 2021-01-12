#include "ecore/ecorePackage.hpp"
#include "ecore/impl/ecorePackageImpl.hpp"

using namespace ecore;

//static initialisation
const std::string ecorePackage::eNAME ="ecore";
const std::string ecorePackage::eNS_URI ="http://www.eclipse.org/emf/2002/Ecore";
const std::string ecorePackage::eNS_PREFIX ="ecore";

//Singleton 
std::shared_ptr<ecorePackage> ecorePackage::instance;

std::shared_ptr<ecorePackage> ecorePackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ecorePackageImpl::create());
		std::dynamic_pointer_cast<ecorePackageImpl>(instance)->init(instance);
	}	
	return instance;
}
