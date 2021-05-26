#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Evaluations/impl/EvaluationsPackageImpl.hpp"

using namespace ocl::Evaluations;

//static initialisation
const std::string EvaluationsPackage::eNAME ="Evaluations";
const std::string EvaluationsPackage::eNS_URI ="http://ocl4cpp/ocl/evaluations.ecore";
const std::string EvaluationsPackage::eNS_PREFIX ="ocl.evaluations";

//Singleton 
std::shared_ptr<EvaluationsPackage> EvaluationsPackage::instance;

std::shared_ptr<EvaluationsPackage> EvaluationsPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(EvaluationsPackageImpl::create());
		std::dynamic_pointer_cast<EvaluationsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
