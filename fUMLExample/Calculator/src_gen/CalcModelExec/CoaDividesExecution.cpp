#include "CoaDividesExecution.hpp"
#include <iostream>
#include <memory>
#include <cassert>
#include "ParameterValue.hpp"


// PrimeChecker <- Class name
// divides <- Operation name
// fbDivides <- Method name
// Boolean is not a pointer
#include "BooleanValue.hpp"

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"
 
using namespace CalcModel;

CoaDividesExecution::CoaDividesExecution()
{
}

CoaDividesExecution::~CoaDividesExecution()
{
}


CoaDividesExecution::CoaDividesExecution(CoaDividesExecution &obj):
	OpaqueBehaviorExecutionImpl(obj)
{
}

ecore::EObject* CoaDividesExecution::copy()
{
    return new CoaDividesExecution(*this);
}

void CoaDividesExecution::doBody(std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>> inputParameters, std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>> outputParameters)
{
    DEBUG_MESSAGE(std::cout<<"Printing from "<< this->getBehavior()->getName();)
    DEBUG_MESSAGE(std::cout<<"__________________________";)

   	bool isDivisible;


	std::shared_ptr<CalcModel::PrimeChecker> target = std::dynamic_pointer_cast<PrimeCheckerExecution>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //call assigned operation
	 isDivisible =   target->divides();
	
	
	//set out/result parameter
    std::shared_ptr<fUML::BooleanValue> isDivisibleValue(fUML::FUMLFactory::eInstance()->createBooleanValue());
 	isDivisibleValue->setValue(isDivisible);
    outputParameters->at(0)->getValues()->push_back(isDivisibleValue);
	
	//set InOut parameters
}
