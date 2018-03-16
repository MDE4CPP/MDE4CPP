#include "libraryModel_ecore/impl/LibraryModel_ecorePluginImpl.hpp"

#include "libraryModel_ecore/LibraryModel_ecoreFactory.hpp"
#include "libraryModel_ecore/LibraryModel_ecorePackage.hpp"

using namespace libraryModel_ecore;

//*********************************
// Constructor / Destructor
//*********************************
LibraryModel_ecorePluginImpl::LibraryModel_ecorePluginImpl()
{
}

LibraryModel_ecorePluginImpl::~LibraryModel_ecorePluginImpl()
{
}


std::shared_ptr<ecore::EObject> LibraryModel_ecorePluginImpl::create(const std::string& name)
{
	return LibraryModel_ecoreFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EFactory> LibraryModel_ecorePluginImpl::getEFactory()
{
	return LibraryModel_ecoreFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> LibraryModel_ecorePluginImpl::getEPackage()
{
	return LibraryModel_ecorePackage::eInstance();
}

std::string LibraryModel_ecorePluginImpl::eclipseURI()
{
	return "";
}

std::string LibraryModel_ecorePluginImpl::eNAME()
{
	return "libraryModel_ecore";
}

std::string LibraryModel_ecorePluginImpl::eNS_URI()
{
	return "http://www.example.org/libraryModel_ecore";
}

std::string LibraryModel_ecorePluginImpl::eNS_PREFIX()
{
	return "libraryModel_ecore";
}
