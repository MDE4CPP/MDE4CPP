#include "fUMLMultiplePins/impl/FUMLMultiplePinsPluginImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include "fUMLMultiplePins/FUMLMultiplePinsFactory.hpp"
#include "fUMLMultiplePins/FUMLMultiplePinsPackage.hpp"

using namespace fUMLMultiplePins;

//*********************************
// Constructor / Destructor
//*********************************
FUMLMultiplePinsPluginImpl::FUMLMultiplePinsPluginImpl()
{
}

FUMLMultiplePinsPluginImpl::~FUMLMultiplePinsPluginImpl()
{
}

std::shared_ptr<uml::Factory> FUMLMultiplePinsPluginImpl::getFactory()
{
	return FUMLMultiplePinsFactory::eInstance();
}

std::shared_ptr<uml::Package> FUMLMultiplePinsPluginImpl::getPackage()
{
	return FUMLMultiplePinsPackage::eInstance();
}

std::string FUMLMultiplePinsPluginImpl::eNAME()
{
	return "fUMLMultiplePins";
}

std::string FUMLMultiplePinsPluginImpl::eNS_URI()
{
	return "";
}

std::string FUMLMultiplePinsPluginImpl::eNS_PREFIX()
{
	return "";
}
