#include "forkNodeTest/impl/ForkNodeTestPluginImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include "forkNodeTest/ForkNodeTestFactory.hpp"
#include "forkNodeTest/ForkNodeTestPackage.hpp"

using namespace forkNodeTest;

//*********************************
// Constructor / Destructor
//*********************************
ForkNodeTestPluginImpl::ForkNodeTestPluginImpl()
{
}

ForkNodeTestPluginImpl::~ForkNodeTestPluginImpl()
{
}

std::shared_ptr<ecore::EObject> ForkNodeTestPluginImpl::create(const std::string& name)
{		
	return ForkNodeTestFactory::eInstance()->create(name);
}

std::shared_ptr<uml::Factory> ForkNodeTestPluginImpl::getFactory()
{
	return ForkNodeTestFactory::eInstance();
}

std::shared_ptr<uml::Package> ForkNodeTestPluginImpl::getPackage()
{
	return ForkNodeTestPackage::eInstance();
}

std::string ForkNodeTestPluginImpl::eclipseURI()
{
	return "";
}

std::string ForkNodeTestPluginImpl::eNAME()
{
	return "forkNodeTest";
}

std::string ForkNodeTestPluginImpl::eNS_URI()
{
	return "";
}

std::string ForkNodeTestPluginImpl::eNS_PREFIX()
{
	return "";
}
