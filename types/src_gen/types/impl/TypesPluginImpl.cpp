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

std::shared_ptr<ecore::EFactory> TypesPluginImpl::getFactory()
{
	return TypesFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> TypesPluginImpl::getPackage()
{
	return TypesPackage::eInstance();
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
