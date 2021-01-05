#include "PSCS/Semantics/Values/ValuesPackage.hpp"
#include "PSCS/Semantics/Values/impl/ValuesPackageImpl.hpp"

using namespace PSCS::Semantics::Values;

//static initialisation
const std::string ValuesPackage::eNAME ="Values";
const std::string ValuesPackage::eNS_URI ="http:///PSCS_Semantics/Semantics/Values.ecore";
const std::string ValuesPackage::eNS_PREFIX ="PSCS_Semantics.Semantics.Values";

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
