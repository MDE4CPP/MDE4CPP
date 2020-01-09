#include "StandardProfile/impl/StandardProfilePluginImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif
#include <iostream>

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
	std::cout << "WARNING: container based create function is not implemented for UML models!!!" << std::endl;
	return nullptr; //StandardProfileFactory::eInstance()->create(name, container, referenceID);
}

std::shared_ptr<uml::Factory> StandardProfilePluginImpl::getFactory()
{
	return StandardProfileFactory::eInstance();
}

std::shared_ptr<uml::Package> StandardProfilePluginImpl::getPackage()
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
	return "";
}
