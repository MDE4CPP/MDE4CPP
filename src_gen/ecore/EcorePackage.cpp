#include "EcorePackage.hpp"
#include "impl/EcorePackageImpl.hpp"

using namespace ecore;

//static initialisation
const std::string EcorePackage::eNAME ="ecore";
const std::string EcorePackage::eNS_URI ="http://www.eclipse.org/emf/2002/Ecore";
const std::string EcorePackage::eNS_PREFIX ="ecore";

//Singleton 
EcorePackage * EcorePackage::instance = nullptr;

EcorePackage * EcorePackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Factoryimplementation
		instance = EcorePackageImpl::create();
		dynamic_cast<EcorePackageImpl * >(instance)->init();
	}	
	return instance;
}
