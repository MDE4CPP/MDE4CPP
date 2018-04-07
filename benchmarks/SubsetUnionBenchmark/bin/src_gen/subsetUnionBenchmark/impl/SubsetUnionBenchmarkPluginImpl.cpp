#include "SubsetUnionBenchmarkPluginImpl.hpp"
#include "SubsetUnionBenchmarkFactory.hpp"
#include "SubsetUnionBenchmarkPackage.hpp"

using namespace subsetUnionBenchmark;

//*********************************
// Constructor / Destructor
//*********************************
SubsetUnionBenchmarkPluginImpl::SubsetUnionBenchmarkPluginImpl()
{
}

SubsetUnionBenchmarkPluginImpl::~SubsetUnionBenchmarkPluginImpl()
{
}

std::shared_ptr<ecore::EFactory> SubsetUnionBenchmarkPluginImpl::getFactory()
{
	return SubsetUnionBenchmarkFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> SubsetUnionBenchmarkPluginImpl::getPackage()
{
	return SubsetUnionBenchmarkPackage::eInstance();
}

std::string SubsetUnionBenchmarkPluginImpl::eNAME()
{
	return "subsetUnionBenchmark";
}

std::string SubsetUnionBenchmarkPluginImpl::eNS_URI()
{
	return "http://www.example.org/subsetUnionBenchmark";
}

std::string SubsetUnionBenchmarkPluginImpl::eNS_PREFIX()
{
	return "subsetUnionBenchmark";
}
