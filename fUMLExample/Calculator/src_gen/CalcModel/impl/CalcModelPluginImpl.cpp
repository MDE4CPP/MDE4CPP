#include "CalcModel/impl/CalcModelPluginImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include "CalcModel/CalcModelFactory.hpp"
#include "CalcModel/CalcModelPackage.hpp"

using namespace CalcModel;

//*********************************
// Constructor / Destructor
//*********************************
CalcModelPluginImpl::CalcModelPluginImpl()
{
}

CalcModelPluginImpl::~CalcModelPluginImpl()
{
}

std::shared_ptr<ecore::EObject> CalcModelPluginImpl::create(const std::string& name)
{		
	return CalcModelFactory::eInstance()->create(name);
}

std::shared_ptr<uml::Factory> CalcModelPluginImpl::getFactory()
{
	return CalcModelFactory::eInstance();
}

std::shared_ptr<uml::Package> CalcModelPluginImpl::getPackage()
{
	return CalcModelPackage::eInstance();
}

std::string CalcModelPluginImpl::eclipseURI()
{
	return "";
}

std::string CalcModelPluginImpl::eNAME()
{
	return "CalcModel";
}

std::string CalcModelPluginImpl::eNS_URI()
{
	return "";
}

std::string CalcModelPluginImpl::eNS_PREFIX()
{
	return "";
}
