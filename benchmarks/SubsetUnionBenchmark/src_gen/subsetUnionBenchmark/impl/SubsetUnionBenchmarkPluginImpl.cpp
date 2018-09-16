#include "subsetUnionBenchmark/impl/SubsetUnionBenchmarkPluginImpl.hpp"

#include "subsetUnionBenchmark/SubsetUnionBenchmarkFactory.hpp"
#include "subsetUnionBenchmark/SubsetUnionBenchmarkPackage.hpp"

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


std::shared_ptr<ecore::EObject> SubsetUnionBenchmarkPluginImpl::create(const std::string& name)
{
	return SubsetUnionBenchmarkFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EFactory> SubsetUnionBenchmarkPluginImpl::getEFactory()
{
	return SubsetUnionBenchmarkFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> SubsetUnionBenchmarkPluginImpl::getEPackage()
{
	return SubsetUnionBenchmarkPackage::eInstance();
}

std::string SubsetUnionBenchmarkPluginImpl::eclipseURI()
{
	return "";
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
