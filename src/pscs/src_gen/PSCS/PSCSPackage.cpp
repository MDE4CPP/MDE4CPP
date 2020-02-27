#include "PSCS/PSCSPackage.hpp"
#include "PSCS/impl/PSCSPackageImpl.hpp"

using namespace PSCS;

//static initialisation
const std::string PSCSPackage::eNAME ="PSCS";
const std::string PSCSPackage::eNS_URI ="http://www.omg.org/spec/PSCS/20180801";
const std::string PSCSPackage::eNS_PREFIX ="PSCS_Semantics";

//Singleton 
std::shared_ptr<PSCSPackage> PSCSPackage::instance;

std::shared_ptr<PSCSPackage> PSCSPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(PSCSPackageImpl::create());
		std::dynamic_pointer_cast<PSCSPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
