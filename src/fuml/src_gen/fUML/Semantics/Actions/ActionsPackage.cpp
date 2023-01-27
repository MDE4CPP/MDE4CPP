#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

using namespace fUML::Semantics::Actions;

//static initialisation
const std::string ActionsPackage::eNAME ="Actions";
const std::string ActionsPackage::eNS_URI ="http:///fUML_Semantics/Semantics/Actions.ecore";
const std::string ActionsPackage::eNS_PREFIX ="fUML_Semantics.Semantics.Actions";

//Singleton 
std::shared_ptr<ActionsPackage> ActionsPackage::eInstance()
{
	static std::shared_ptr<ActionsPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ActionsPackageImpl::create());
		std::dynamic_pointer_cast<ActionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
