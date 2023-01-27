#include "FoundationalModelLibrary/BasicInputOutput/BasicInputOutputPackage.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/impl/BasicInputOutputPackageImpl.hpp"

using namespace FoundationalModelLibrary::BasicInputOutput;

//static initialisation
const std::string BasicInputOutputPackage::eNAME ="BasicInputOutput";
const std::string BasicInputOutputPackage::eNS_URI ="";
const std::string BasicInputOutputPackage::eNS_PREFIX ="FoundationalModelLibrary";

//Singleton 
std::shared_ptr<BasicInputOutputPackage> BasicInputOutputPackage::instance;

std::shared_ptr<BasicInputOutputPackage> BasicInputOutputPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(BasicInputOutputPackageImpl::create());
		std::dynamic_pointer_cast<BasicInputOutputPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
