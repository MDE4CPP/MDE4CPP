#include "umlReflectionExec/impl/UMLExecPluginImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <cassert>
#include <iostream>
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "uml/Activity.hpp"
#include "uml/Element.hpp"


using namespace UML;

//*********************************
// Constructor / Destructor
//*********************************
UMLExecPluginImpl::UMLExecPluginImpl()
{	
}

UMLExecPluginImpl::~UMLExecPluginImpl()
{
}

std::string UMLExecPluginImpl::eclipseURI()
{
	return "";
}

std::string UMLExecPluginImpl::eNAME()
{
	return "UMLExec";
}

std::string UMLExecPluginImpl::eNS_URI()
{
	return "http://www.omg.org/spec/UML/20131001";
}

std::string UMLExecPluginImpl::eNS_PREFIX()
{
	return "";
}

std::shared_ptr<ecore::EObject> UMLExecPluginImpl::create(const std::string& name) const
{		
	return nullptr;
}

std::shared_ptr<ecore::EObject> UMLExecPluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return nullptr;
}

void UMLExecPluginImpl::initialize()
{

	m_IsInitialized = true;
}

Any UMLExecPluginImpl::executeActivity(std::shared_ptr<uml::Activity> activity, std::shared_ptr<std::vector<Any>> parameterList, std::shared_ptr<uml::Element> element)
{
	if(!m_IsInitialized)
	{
		initialize();
	}
	return nullptr;
}

