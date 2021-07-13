#include "ecoreReflection/impl/EcorePluginImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif
#include <iostream>


#include "ecoreReflection/EcorePackage.hpp"

using namespace Ecore;

//*********************************
// Constructor / Destructor
//*********************************
EcorePluginImpl::EcorePluginImpl()
{
}

EcorePluginImpl::~EcorePluginImpl()
{
}

std::shared_ptr<ecore::EObject> EcorePluginImpl::create(const std::string& name) const
{		
	return nullptr;
}

std::shared_ptr<ecore::EObject> EcorePluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return nullptr;
}

std::shared_ptr<uml::Factory> EcorePluginImpl::getFactory()
{
	return nullptr;
}

std::shared_ptr<uml::Package> EcorePluginImpl::getPackage()
{
	return EcorePackage::eInstance();
}

std::string EcorePluginImpl::eclipseURI()
{
	return "pathmap://UML_METAMODELS/Ecore.metamodel.uml";
}

std::string EcorePluginImpl::eNAME()
{
	return "Ecore";
}

std::string EcorePluginImpl::eNS_URI()
{
	return "http://www.eclipse.org/emf/2002/Ecore";
}

std::string EcorePluginImpl::eNS_PREFIX()
{
	return "";
}
