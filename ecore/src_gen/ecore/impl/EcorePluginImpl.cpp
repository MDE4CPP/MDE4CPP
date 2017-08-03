#include "EcorePluginImpl.hpp"
#include "EcoreFactory.hpp"
#include "EcorePackage.hpp"

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

std::shared_ptr<ecore::EFactory> EcorePluginImpl::getFactory()
{
	return EcoreFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> EcorePluginImpl::getPackage()
{
	return EcorePackage::eInstance();
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
