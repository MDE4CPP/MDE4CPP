#include "EcorePackage.hpp"
#include "impl/EcorePackageImpl.hpp"

using namespace ecore;

//static initialisation
const std::string EcorePackage::eNAME ="ecore";
const std::string EcorePackage::eNS_URI ="http://www.eclipse.org/emf/2002/Ecore";
const std::string EcorePackage::eNS_PREFIX ="ecore";

//Singleton 
std::shared_ptr<EcorePackage> EcorePackage::instance;

std::shared_ptr<EcorePackage> EcorePackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(EcorePackageImpl::create());
		std::dynamic_pointer_cast<EcorePackageImpl>(instance)->init();
	}	
	return instance;
}
