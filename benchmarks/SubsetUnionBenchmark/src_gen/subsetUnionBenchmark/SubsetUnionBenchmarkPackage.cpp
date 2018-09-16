#include "subsetUnionBenchmark/SubsetUnionBenchmarkPackage.hpp"
#include "subsetUnionBenchmark/impl/SubsetUnionBenchmarkPackageImpl.hpp"

using namespace subsetUnionBenchmark;

//static initialisation
const std::string SubsetUnionBenchmarkPackage::eNAME ="subsetUnionBenchmark";
const std::string SubsetUnionBenchmarkPackage::eNS_URI ="http://www.example.org/subsetUnionBenchmark";
const std::string SubsetUnionBenchmarkPackage::eNS_PREFIX ="subsetUnionBenchmark";

//Singleton 
std::shared_ptr<SubsetUnionBenchmarkPackage> SubsetUnionBenchmarkPackage::instance;

std::shared_ptr<SubsetUnionBenchmarkPackage>SubsetUnionBenchmarkPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(SubsetUnionBenchmarkPackageImpl::create());
		std::dynamic_pointer_cast<SubsetUnionBenchmarkPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
