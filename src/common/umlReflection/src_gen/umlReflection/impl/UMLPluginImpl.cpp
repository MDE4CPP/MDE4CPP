#include "umlReflection/impl/UMLPluginImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif
#include <iostream>


#include "umlReflection/UMLPackage.hpp"

using namespace UML;

//*********************************
// Constructor / Destructor
//*********************************
UMLPluginImpl::UMLPluginImpl()
{
}

UMLPluginImpl::~UMLPluginImpl()
{
}

std::shared_ptr<ecore::EObject> UMLPluginImpl::create(const std::string& name) const
{		
	return nullptr;
}

std::shared_ptr<ecore::EObject> UMLPluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return nullptr;
}

std::shared_ptr<uml::Factory> UMLPluginImpl::getFactory()
{
	return nullptr;
}

std::shared_ptr<uml::Package> UMLPluginImpl::getPackage()
{
	return UMLPackage::eInstance();
}

std::string UMLPluginImpl::eclipseURI()
{
	return "pathmap://UML_METAMODELS/UML.metamodel.uml";
}

std::string UMLPluginImpl::eNAME()
{
	return "UML";
}

std::string UMLPluginImpl::eNS_URI()
{
	return "http://www.omg.org/spec/UML/20131001";
}

std::string UMLPluginImpl::eNS_PREFIX()
{
	return "";
}
