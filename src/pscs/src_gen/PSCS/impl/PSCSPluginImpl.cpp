#include "PSCS/impl/PSCSPluginImpl.hpp"

#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"

using namespace PSCS;

//*********************************
// Constructor / Destructor
//*********************************
PSCSPluginImpl::PSCSPluginImpl()
{
}

PSCSPluginImpl::~PSCSPluginImpl()
{
}


std::shared_ptr<ecore::EObject> PSCSPluginImpl::create(const std::string& name) const
{
	return PSCSFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EObject> PSCSPluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return PSCSFactory::eInstance()->create(name, container, referenceID);
}

std::shared_ptr<ecore::EFactory> PSCSPluginImpl::getEFactory()
{
	return PSCSFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> PSCSPluginImpl::getEPackage()
{
	return PSCSPackage::eInstance();
}

std::string PSCSPluginImpl::eclipseURI()
{
	return "";
}

std::string PSCSPluginImpl::eNAME()
{
	return "PSCS";
}

std::string PSCSPluginImpl::eNS_URI()
{
	return "http://www.omg.org/spec/PSCS/20180801";
}

std::string PSCSPluginImpl::eNS_PREFIX()
{
	return "PSCS_Semantics";
}
