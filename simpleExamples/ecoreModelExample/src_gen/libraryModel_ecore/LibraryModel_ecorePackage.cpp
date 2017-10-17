#include "LibraryModel_ecorePackage.hpp"
#include "impl/LibraryModel_ecorePackageImpl.hpp"

using namespace libraryModel_ecore;

//static initialisation
const std::string LibraryModel_ecorePackage::eNAME ="libraryModel_ecore";
const std::string LibraryModel_ecorePackage::eNS_URI ="http://www.example.org/libraryModel_ecore";
const std::string LibraryModel_ecorePackage::eNS_PREFIX ="libraryModel_ecore";

//Singleton 
std::shared_ptr<LibraryModel_ecorePackage> LibraryModel_ecorePackage::instance;

std::shared_ptr<LibraryModel_ecorePackage>LibraryModel_ecorePackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(LibraryModel_ecorePackageImpl::create());
		std::dynamic_pointer_cast<LibraryModel_ecorePackageImpl>(instance)->init();
	}	
	return instance;
}
