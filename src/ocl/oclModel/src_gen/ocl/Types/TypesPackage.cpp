#include "ocl/Types/TypesPackage.hpp"
#include "ocl/Types/impl/TypesPackageImpl.hpp"

using namespace ocl::Types;

//static initialisation
const std::string TypesPackage::eNAME ="Types";
const std::string TypesPackage::eNS_URI ="http://ocl4cpp/ocl/types.ecore";
const std::string TypesPackage::eNS_PREFIX ="ocl.types";

//Singleton 
std::shared_ptr<TypesPackage> TypesPackage::instance;

std::shared_ptr<TypesPackage> TypesPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(TypesPackageImpl::create());
		std::dynamic_pointer_cast<TypesPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
