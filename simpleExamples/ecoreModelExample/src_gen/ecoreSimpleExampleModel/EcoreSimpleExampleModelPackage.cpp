#include "EcoreSimpleExampleModelPackage.hpp"
#include "impl/EcoreSimpleExampleModelPackageImpl.hpp"

using namespace ecoreSimpleExampleModel;

//static initialisation
const std::string EcoreSimpleExampleModelPackage::eNAME ="ecoreSimpleExampleModel";
const std::string EcoreSimpleExampleModelPackage::eNS_URI ="http://www.example.org/ecoreSimpleExampleModel";
const std::string EcoreSimpleExampleModelPackage::eNS_PREFIX ="ecoreSimpleExampleModel";

//Singleton 
std::shared_ptr<EcoreSimpleExampleModelPackage> EcoreSimpleExampleModelPackage::instance;

std::shared_ptr<EcoreSimpleExampleModelPackage>EcoreSimpleExampleModelPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(EcoreSimpleExampleModelPackageImpl::create());
		std::dynamic_pointer_cast<EcoreSimpleExampleModelPackageImpl>(instance)->init();
	}	
	return instance;
}
