#include "ecoreReflection/EcorePackage.hpp"
#include "ecoreReflection/impl/EcorePackageImpl.hpp"

using namespace Ecore;

//static initialisation
const std::string EcorePackage::eNAME ="Ecore";
const std::string EcorePackage::eNS_URI ="http://www.eclipse.org/emf/2002/Ecore";
const std::string EcorePackage::eNS_PREFIX ="";

//Singleton 
std::shared_ptr<EcorePackage> EcorePackage::instance;

std::shared_ptr<EcorePackage> EcorePackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(EcorePackageImpl::create());
		std::dynamic_pointer_cast<EcorePackageImpl>(instance)->init();
	}	
	return instance;
}
