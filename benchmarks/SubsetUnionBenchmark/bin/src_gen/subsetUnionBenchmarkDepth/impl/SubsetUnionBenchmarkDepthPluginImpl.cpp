#include "SubsetUnionBenchmarkDepthPluginImpl.hpp"
#include "SubsetUnionBenchmarkDepthFactory.hpp"
#include "SubsetUnionBenchmarkDepthPackage.hpp"

using namespace subsetUnionBenchmarkDepth;

//*********************************
// Constructor / Destructor
//*********************************
SubsetUnionBenchmarkDepthPluginImpl::SubsetUnionBenchmarkDepthPluginImpl()
{
}

SubsetUnionBenchmarkDepthPluginImpl::~SubsetUnionBenchmarkDepthPluginImpl()
{
}

std::shared_ptr<ecore::EFactory> SubsetUnionBenchmarkDepthPluginImpl::getFactory()
{
	return SubsetUnionBenchmarkDepthFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> SubsetUnionBenchmarkDepthPluginImpl::getPackage()
{
	return SubsetUnionBenchmarkDepthPackage::eInstance();
}

std::string SubsetUnionBenchmarkDepthPluginImpl::eNAME()
{
	return "subsetUnionBenchmarkDepth";
}

std::string SubsetUnionBenchmarkDepthPluginImpl::eNS_URI()
{
	return "http://www.example.org/subsetUnionBenchmark";
}

std::string SubsetUnionBenchmarkDepthPluginImpl::eNS_PREFIX()
{
	return "subsetUnionBenchmark";
}
