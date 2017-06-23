#include "PrimitiveTypesPackage.hpp"
#include "impl/PrimitiveTypesPackageImpl.hpp"

using namespace PrimitiveTypes;

//static initialisation
const std::string PrimitiveTypesPackage::eNAME ="PrimitiveTypes";
const std::string PrimitiveTypesPackage::eNS_URI ="http://www.omg.org/spec/PrimitiveTypes/20131001";
const std::string PrimitiveTypesPackage::eNS_PREFIX ="";

//Singleton 
std::shared_ptr<PrimitiveTypesPackage> PrimitiveTypesPackage::instance;

std::shared_ptr<PrimitiveTypesPackage> PrimitiveTypesPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(PrimitiveTypesPackageImpl::create());
		std::dynamic_pointer_cast<PrimitiveTypesPackageImpl>(instance)->init();
	}	
	return instance;
}
