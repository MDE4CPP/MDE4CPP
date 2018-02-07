#include "fUML/impl/FUMLPluginImpl.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
FUMLPluginImpl::FUMLPluginImpl()
{
}

FUMLPluginImpl::~FUMLPluginImpl()
{
}

std::shared_ptr<ecore::EFactory> FUMLPluginImpl::getFactory()
{
	return FUMLFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> FUMLPluginImpl::getPackage()
{
	return FUMLPackage::eInstance();
}

std::string FUMLPluginImpl::eNAME()
{
	return "fUML";
}

std::string FUMLPluginImpl::eNS_URI()
{
	return "http://www.eclipse.org/emf/2002/fUML";
}

std::string FUMLPluginImpl::eNS_PREFIX()
{
	return "fUML";
}
