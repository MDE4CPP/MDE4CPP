#include "CoaIsNotFinishedExecution.hpp"
#include <iostream>
#include <memory>
#include <cassert>
#include "ParameterValue.hpp"


// PrimeChecker <- Class name
// isNotFinished <- Operation name
// fbIsNotFinished <- Method name
// Boolean is not a pointer
#include "BooleanValue.hpp"

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"
 
using namespace CalcModel;

CoaIsNotFinishedExecution::CoaIsNotFinishedExecution()
{
}

CoaIsNotFinishedExecution::~CoaIsNotFinishedExecution()
{
}


CoaIsNotFinishedExecution::CoaIsNotFinishedExecution(CoaIsNotFinishedExecution &obj):
	OpaqueBehaviorExecutionImpl(obj)
{
}

ecore::EObject* CoaIsNotFinishedExecution::copy()
{
    return new CoaIsNotFinishedExecution(*this);
}

void CoaIsNotFinishedExecution::doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters)
{
    DEBUG_MESSAGE(std::cout<<"Printing from "<< this->getBehavior()->getName();)
    DEBUG_MESSAGE(std::cout<<"__________________________";)

   	bool isNotFinished;


	std::shared_ptr<CalcModel::PrimeChecker> target = std::dynamic_pointer_cast<PrimeCheckerExecution>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //call assigned operation
	 isNotFinished =   target->isNotFinished();
	
	
	//set out/result parameter
    std::shared_ptr<fUML::BooleanValue> isNotFinishedValue(fUML::FUMLFactory::eInstance()->createBooleanValue());
 	isNotFinishedValue->setValue(isNotFinished);
    outputParameters->at(0)->getValues()->push_back(isNotFinishedValue);
	
	//set InOut parameters
}
