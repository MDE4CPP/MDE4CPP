#include "types/impl/TypesPluginImpl.hpp"

#include "types/TypesFactory.hpp"
#include "types/TypesPackage.hpp"

using namespace types;

//*********************************
// Constructor / Destructor
//*********************************
TypesPluginImpl::TypesPluginImpl()
{
}

TypesPluginImpl::~TypesPluginImpl()
{
}


std::shared_ptr<ecore::EObject> TypesPluginImpl::create(const std::string& name)
{
	return TypesFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EFactory> TypesPluginImpl::getEFactory()
{
	return TypesFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> TypesPluginImpl::getEPackage()
{
	return TypesPackage::eInstance();
}

std::string TypesPluginImpl::eclipseURI()
{
	return "";
}

std::string TypesPluginImpl::eNAME()
{
	return "types";
}

std::string TypesPluginImpl::eNS_URI()
{
	return "http://www.eclipse.org/uml2/5.0.0/Types";
}

std::string TypesPluginImpl::eNS_PREFIX()
{
	return "types";
}
