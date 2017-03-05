#include "TypesPackage.hpp"
#include "impl/TypesPackageImpl.hpp"

using namespace types;

//static initialisation
const std::string TypesPackage::eNAME ="types";
const std::string TypesPackage::eNS_URI ="http://www.eclipse.org/uml2/5.0.0/Types";
const std::string TypesPackage::eNS_PREFIX ="types";

//Singleton 
std::shared_ptr<TypesPackage> TypesPackage::instance;

std::shared_ptr<TypesPackage> TypesPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(TypesPackageImpl::create());
		std::dynamic_pointer_cast<TypesPackageImpl>(instance)->init();
	}	
	return instance;
}
