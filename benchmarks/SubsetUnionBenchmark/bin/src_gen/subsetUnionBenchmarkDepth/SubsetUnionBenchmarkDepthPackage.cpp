#include "SubsetUnionBenchmarkDepthPackage.hpp"
#include "impl/SubsetUnionBenchmarkDepthPackageImpl.hpp"

using namespace subsetUnionBenchmarkDepth;

//static initialisation
const std::string SubsetUnionBenchmarkDepthPackage::eNAME ="subsetUnionBenchmarkDepth";
const std::string SubsetUnionBenchmarkDepthPackage::eNS_URI ="http://www.example.org/subsetUnionBenchmark";
const std::string SubsetUnionBenchmarkDepthPackage::eNS_PREFIX ="subsetUnionBenchmark";

//Singleton 
std::shared_ptr<SubsetUnionBenchmarkDepthPackage> SubsetUnionBenchmarkDepthPackage::instance;

std::shared_ptr<SubsetUnionBenchmarkDepthPackage>SubsetUnionBenchmarkDepthPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(SubsetUnionBenchmarkDepthPackageImpl::create());
		std::dynamic_pointer_cast<SubsetUnionBenchmarkDepthPackageImpl>(instance)->init();
	}	
	return instance;
}
