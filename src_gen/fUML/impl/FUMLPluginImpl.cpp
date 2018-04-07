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


std::shared_ptr<ecore::EObject> FUMLPluginImpl::create(const std::string& name)
{
	return FUMLFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EFactory> FUMLPluginImpl::getEFactory()
{
	return FUMLFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> FUMLPluginImpl::getEPackage()
{
	return FUMLPackage::eInstance();
}

std::string FUMLPluginImpl::eclipseURI()
{
	return "";
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
