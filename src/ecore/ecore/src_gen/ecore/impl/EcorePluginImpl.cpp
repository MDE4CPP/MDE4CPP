#include "ecore/impl/EcorePluginImpl.hpp"

#include "ecore/EcoreFactory.hpp"
#include "ecore/EcorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EcorePluginImpl::EcorePluginImpl()
{
}

EcorePluginImpl::~EcorePluginImpl()
{
}


std::shared_ptr<ecore::EObject> EcorePluginImpl::create(const std::string& name)
{
	return EcoreFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EFactory> EcorePluginImpl::getEFactory()
{
	return EcoreFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> EcorePluginImpl::getEPackage()
{
	return EcorePackage::eInstance();
}

std::string EcorePluginImpl::eclipseURI()
{
	return "";
}

std::string EcorePluginImpl::eNAME()
{
	return "ecore";
}

std::string EcorePluginImpl::eNS_URI()
{
	return "http://www.eclipse.org/emf/2002/Ecore";
}

std::string EcorePluginImpl::eNS_PREFIX()
{
	return "ecore";
}
