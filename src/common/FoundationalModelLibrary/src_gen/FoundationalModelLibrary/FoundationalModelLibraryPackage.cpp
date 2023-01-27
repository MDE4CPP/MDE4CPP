#include "FoundationalModelLibrary/FoundationalModelLibraryPackage.hpp"
#include "FoundationalModelLibrary/impl/FoundationalModelLibraryPackageImpl.hpp"

using namespace FoundationalModelLibrary;

//static initialisation
const std::string FoundationalModelLibraryPackage::eNAME ="FoundationalModelLibrary";
const std::string FoundationalModelLibraryPackage::eNS_URI ="https://www.omg.org/spec/FUML/20150801";
const std::string FoundationalModelLibraryPackage::eNS_PREFIX ="";

//Singleton 
std::shared_ptr<FoundationalModelLibraryPackage> FoundationalModelLibraryPackage::instance;

std::shared_ptr<FoundationalModelLibraryPackage> FoundationalModelLibraryPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(FoundationalModelLibraryPackageImpl::create());
		std::dynamic_pointer_cast<FoundationalModelLibraryPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
