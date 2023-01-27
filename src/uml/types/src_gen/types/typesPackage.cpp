#include "types/typesPackage.hpp"
#include "types/impl/typesPackageImpl.hpp"

using namespace types;

//static initialisation
const std::string typesPackage::eNAME ="types";
const std::string typesPackage::eNS_URI ="http://www.eclipse.org/uml2/5.0.0/Types";
const std::string typesPackage::eNS_PREFIX ="types";

//Singleton 
std::shared_ptr<typesPackage> typesPackage::eInstance()
{
	static std::shared_ptr<typesPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(typesPackageImpl::create());
		std::dynamic_pointer_cast<typesPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
