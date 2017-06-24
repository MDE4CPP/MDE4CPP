#include "CoaNextExecution.hpp"
#include <iostream>
#include <memory>
#include <cassert>
#include "ParameterValue.hpp"


// PrimeChecker <- Class name
// next <- Operation name
// fbNext <- Method name
// invalid is not a pointer

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"
 
using namespace CalcModel;

CoaNextExecution::CoaNextExecution()
{
}

CoaNextExecution::~CoaNextExecution()
{
}


CoaNextExecution::CoaNextExecution(CoaNextExecution &obj):
	OpaqueBehaviorExecutionImpl(obj)
{
}

ecore::EObject* CoaNextExecution::copy()
{
    return new CoaNextExecution(*this);
}

void CoaNextExecution::doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters)
{
    DEBUG_MESSAGE(std::cout<<"Printing from "<< this->getBehavior()->getName();)
    DEBUG_MESSAGE(std::cout<<"__________________________";)



	std::shared_ptr<CalcModel::PrimeChecker> target = std::dynamic_pointer_cast<PrimeCheckerExecution>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //call assigned operation
	  target->next();
	
	
	//set out/result parameter
	
	//set InOut parameters
}
