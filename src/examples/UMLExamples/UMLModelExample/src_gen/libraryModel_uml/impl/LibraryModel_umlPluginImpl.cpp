#include "LibraryModel_uml/impl/LibraryModel_umlPluginImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include "LibraryModel_uml/LibraryModel_umlFactory.hpp"
#include "LibraryModel_uml/LibraryModel_umlPackage.hpp"

using namespace LibraryModel_uml;

//*********************************
// Constructor / Destructor
//*********************************
LibraryModel_umlPluginImpl::LibraryModel_umlPluginImpl()
{
}

LibraryModel_umlPluginImpl::~LibraryModel_umlPluginImpl()
{
}

std::shared_ptr<ecore::EObject> LibraryModel_umlPluginImpl::create(const std::string& name)
{		
	return LibraryModel_umlFactory::eInstance()->create(name);
}

std::shared_ptr<uml::Factory> LibraryModel_umlPluginImpl::getFactory()
{
	return LibraryModel_umlFactory::eInstance();
}

std::shared_ptr<uml::Package> LibraryModel_umlPluginImpl::getPackage()
{
	return LibraryModel_umlPackage::eInstance();
}

std::string LibraryModel_umlPluginImpl::eclipseURI()
{
	return "";
}

std::string LibraryModel_umlPluginImpl::eNAME()
{
	return "LibraryModel_uml";
}

std::string LibraryModel_umlPluginImpl::eNS_URI()
{
	return "";
}

std::string LibraryModel_umlPluginImpl::eNS_PREFIX()
{
	return "";
}
