#include "forkNodeTest/ForkNodeTestPackage.hpp"
#include "forkNodeTest/impl/ForkNodeTestPackageImpl.hpp"

using namespace forkNodeTest;

//static initialisation
const std::string ForkNodeTestPackage::eNAME ="forkNodeTest";
const std::string ForkNodeTestPackage::eNS_URI ="";
const std::string ForkNodeTestPackage::eNS_PREFIX ="";

//Singleton 
std::shared_ptr<ForkNodeTestPackage> ForkNodeTestPackage::instance;

std::shared_ptr<ForkNodeTestPackage> ForkNodeTestPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(ForkNodeTestPackageImpl::create());
		std::dynamic_pointer_cast<ForkNodeTestPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
