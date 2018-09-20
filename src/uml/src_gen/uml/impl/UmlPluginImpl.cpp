#include "uml/impl/UmlPluginImpl.hpp"

#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

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


std::shared_ptr<ecore::EObject> UmlPluginImpl::create(const std::string& name)
{
	return UmlFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EFactory> UmlPluginImpl::getEFactory()
{
	return UmlFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> UmlPluginImpl::getEPackage()
{
	return UmlPackage::eInstance();
}

std::string UmlPluginImpl::eclipseURI()
{
	return "pathmap://UML_METAMODELS/UML.metamodel.uml";
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
