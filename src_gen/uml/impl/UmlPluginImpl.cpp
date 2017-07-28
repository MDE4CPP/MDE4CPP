#include "UmlPluginImpl.hpp"
#include "UmlFactory.hpp"
#include "UmlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
UmlPluginImpl::UmlPluginImpl()
{
}

UmlPluginImpl::~UmlPluginImpl()
{
}

std::shared_ptr<ecore::EFactory> UmlPluginImpl::getFactory()
{
	return UmlFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> UmlPluginImpl::getPackage()
{
	return UmlPackage::eInstance();
}

std::string UmlPluginImpl::eNAME()
{
	return "uml";
}

std::string UmlPluginImpl::eNS_URI()
{
	return "http://www.eclipse.org/uml2/5.0.0/UML";
}

std::string UmlPluginImpl::eNS_PREFIX()
{
	return "uml";
}
