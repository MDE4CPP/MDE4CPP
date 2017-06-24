#include "CalcModelPluginImpl.hpp"
#include "CalcModelFactory.hpp"
#include "CalcModelPackage.hpp"

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

std::shared_ptr<uml::Factory> CalcModelPluginImpl::getFactory()
{
	return CalcModelFactory::eInstance();
}

std::shared_ptr<uml::Package> CalcModelPluginImpl::getPackage()
{
	return CalcModelPackage::eInstance();
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
