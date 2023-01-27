#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "fUML/Semantics/Values/impl/ValuesPackageImpl.hpp"

using namespace fUML::Semantics::Values;

//static initialisation
const std::string ValuesPackage::eNAME ="Values";
const std::string ValuesPackage::eNS_URI ="http:///fUML_Semantics/Semantics/Values.ecore";
const std::string ValuesPackage::eNS_PREFIX ="fUML_Semantics.Semantics.Values";

//Singleton 
std::shared_ptr<ValuesPackage> ValuesPackage::eInstance()
{
	static std::shared_ptr<ValuesPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ValuesPackageImpl::create());
		std::dynamic_pointer_cast<ValuesPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
