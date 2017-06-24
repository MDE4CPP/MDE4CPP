#include "CalcModelExecPluginImpl.hpp"
#include "CheckIfPrimeExecution.hpp"
using namespace CalcModel;

//*********************************
// Constructor / Destructor
//*********************************
CalcModelExecPluginImpl::CalcModelExecPluginImpl()
{
}

CalcModelExecPluginImpl::~CalcModelExecPluginImpl()
{
}

std::string CalcModelExecPluginImpl::eNAME()
{
	return "CalcModelExec";
}

std::string CalcModelExecPluginImpl::eNS_URI()
{
	return "";
}

std::string CalcModelExecPluginImpl::eNS_PREFIX()
{
	return "";
}


boost::any CalcModelExecPluginImpl::executeActivity(std::string activityName, std::shared_ptr<std::vector<boost::any>> parameterList)
{

	return nullptr;
}

