#include "StandardProfile/impl/StandardProfilePluginImpl.hpp"

#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/StandardProfilePackage.hpp"

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
StandardProfilePluginImpl::StandardProfilePluginImpl()
{
}

StandardProfilePluginImpl::~StandardProfilePluginImpl()
{
}


std::shared_ptr<ecore::EObject> StandardProfilePluginImpl::create(const std::string& name) const
{
	return StandardProfileFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EObject> StandardProfilePluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return StandardProfileFactory::eInstance()->create(name, container, referenceID);
}

std::shared_ptr<ecore::EFactory> StandardProfilePluginImpl::getEFactory()
{
	return StandardProfileFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> StandardProfilePluginImpl::getEPackage()
{
	return StandardProfilePackage::eInstance();
}

std::string StandardProfilePluginImpl::eclipseURI()
{
	return "";
}

std::string StandardProfilePluginImpl::eNAME()
{
	return "StandardProfile";
}

std::string StandardProfilePluginImpl::eNS_URI()
{
	return "http://www.omg.org/spec/UML/20161101/StandardProfile";
}

std::string StandardProfilePluginImpl::eNS_PREFIX()
{
	return "StandardProfile";
}
