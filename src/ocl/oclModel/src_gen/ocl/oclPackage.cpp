#include "ocl/oclPackage.hpp"
#include "ocl/impl/oclPackageImpl.hpp"

using namespace ocl;

//static initialisation
const std::string oclPackage::eNAME ="ocl";
const std::string oclPackage::eNS_URI ="http://ocl4cpp/ocl";
const std::string oclPackage::eNS_PREFIX ="ocl";

//Singleton 
std::shared_ptr<oclPackage> oclPackage::instance;

std::shared_ptr<oclPackage> oclPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(oclPackageImpl::create());
		std::dynamic_pointer_cast<oclPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
