#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/Activities/impl/ActivitiesPackageImpl.hpp"

using namespace fUML::Semantics::Activities;

//static initialisation
const std::string ActivitiesPackage::eNAME ="Activities";
const std::string ActivitiesPackage::eNS_URI ="http:///fUML_Semantics/Semantics/Activities.ecore";
const std::string ActivitiesPackage::eNS_PREFIX ="fUML_Semantics.Semantics.Activities";

//Singleton 
std::shared_ptr<ActivitiesPackage> ActivitiesPackage::eInstance()
{
	static std::shared_ptr<ActivitiesPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ActivitiesPackageImpl::create());
		std::dynamic_pointer_cast<ActivitiesPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
