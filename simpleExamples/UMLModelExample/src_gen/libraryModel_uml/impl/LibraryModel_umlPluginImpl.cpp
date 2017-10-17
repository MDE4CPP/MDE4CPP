#include "LibraryModel_umlPluginImpl.hpp"
#include "LibraryModel_umlFactory.hpp"
#include "LibraryModel_umlPackage.hpp"

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

std::shared_ptr<uml::Factory> LibraryModel_umlPluginImpl::getFactory()
{
	return LibraryModel_umlFactory::eInstance();
}

std::shared_ptr<uml::Package> LibraryModel_umlPluginImpl::getPackage()
{
	return LibraryModel_umlPackage::eInstance();
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
