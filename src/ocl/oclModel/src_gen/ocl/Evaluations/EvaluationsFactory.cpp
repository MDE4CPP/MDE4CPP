#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"

using namespace ocl::Evaluations;
				 
//static initialisation
std::shared_ptr<EvaluationsFactory> EvaluationsFactory::instance;

std::shared_ptr<EvaluationsFactory> EvaluationsFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(EvaluationsFactoryImpl::create());
	}	
	return instance;
}
