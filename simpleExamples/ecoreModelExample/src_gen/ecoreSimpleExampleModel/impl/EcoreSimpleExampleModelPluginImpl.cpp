#include "EcoreSimpleExampleModelPluginImpl.hpp"
#include "EcoreSimpleExampleModelFactory.hpp"
#include "EcoreSimpleExampleModelPackage.hpp"

using namespace ecoreSimpleExampleModel;

//*********************************
// Constructor / Destructor
//*********************************
EcoreSimpleExampleModelPluginImpl::EcoreSimpleExampleModelPluginImpl()
{
}

EcoreSimpleExampleModelPluginImpl::~EcoreSimpleExampleModelPluginImpl()
{
}

std::shared_ptr<ecore::EFactory> EcoreSimpleExampleModelPluginImpl::getFactory()
{
	return EcoreSimpleExampleModelFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> EcoreSimpleExampleModelPluginImpl::getPackage()
{
	return EcoreSimpleExampleModelPackage::eInstance();
}

std::string EcoreSimpleExampleModelPluginImpl::eNAME()
{
	return "ecoreSimpleExampleModel";
}

std::string EcoreSimpleExampleModelPluginImpl::eNS_URI()
{
	return "http://www.example.org/ecoreSimpleExampleModel";
}

std::string EcoreSimpleExampleModelPluginImpl::eNS_PREFIX()
{
	return "ecoreSimpleExampleModel";
}
