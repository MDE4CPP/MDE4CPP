#include "ocl/Values/ValuesPackage.hpp"
#include "ocl/Values/impl/ValuesPackageImpl.hpp"

using namespace ocl::Values;

//static initialisation
const std::string ValuesPackage::eNAME ="Values";
const std::string ValuesPackage::eNS_URI ="http://ocl4cpp/ocl/values.ecore";
const std::string ValuesPackage::eNS_PREFIX ="ocl.values";

//Singleton 
std::shared_ptr<ValuesPackage> ValuesPackage::instance;

std::shared_ptr<ValuesPackage> ValuesPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ValuesPackageImpl::create());
		std::dynamic_pointer_cast<ValuesPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
