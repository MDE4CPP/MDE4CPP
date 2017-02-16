#include "EcorePackage.hpp"
#include "impl/EcorePackageImpl.hpp"

using namespace Ecore;

//static initialisation
const std::string EcorePackage::eNAME ="Ecore";
const std::string EcorePackage::eNS_URI ="http://www.eclipse.org/emf/2002/Ecore";
const std::string EcorePackage::eNS_PREFIX ="invalid";

//Singleton 
EcorePackage * EcorePackage::instance = nullptr;

EcorePackage * EcorePackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance = EcorePackageImpl::create();
		dynamic_cast<EcorePackageImpl * >(instance)->init();
	}	
	return instance;
}
