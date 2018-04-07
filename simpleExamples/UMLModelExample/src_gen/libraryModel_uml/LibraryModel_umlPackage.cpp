#include "LibraryModel_uml/LibraryModel_umlPackage.hpp"
#include "LibraryModel_uml/impl/LibraryModel_umlPackageImpl.hpp"

using namespace LibraryModel_uml;

//static initialisation
const std::string LibraryModel_umlPackage::eNAME ="LibraryModel_uml";
const std::string LibraryModel_umlPackage::eNS_URI ="";
const std::string LibraryModel_umlPackage::eNS_PREFIX ="";

//Singleton 
std::shared_ptr<LibraryModel_umlPackage> LibraryModel_umlPackage::instance;

std::shared_ptr<LibraryModel_umlPackage> LibraryModel_umlPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(LibraryModel_umlPackageImpl::create());
		std::dynamic_pointer_cast<LibraryModel_umlPackageImpl>(instance)->init();
	}	
	return instance;
}
