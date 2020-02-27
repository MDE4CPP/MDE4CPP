#include "Actions/ActionsPackage.hpp"
#include "Actions/impl/ActionsPackageImpl.hpp"

using namespace Actions;

//static initialisation
const std::string ActionsPackage::eNAME ="Actions";
const std::string ActionsPackage::eNS_URI ="http:///PSCS_Semantics/Semantics/Actions.ecore";
const std::string ActionsPackage::eNS_PREFIX ="PSCS_Semantics.Semantics.Actions";

//Singleton 
std::shared_ptr<ActionsPackage> ActionsPackage::instance;

std::shared_ptr<ActionsPackage>ActionsPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ActionsPackageImpl::create());
		std::dynamic_pointer_cast<ActionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
