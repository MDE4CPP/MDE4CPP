#include "Next_callExecution.hpp"
#include <iostream>
#include <cassert>
#include "ParameterValue.hpp"


// PrimeChecker <- Class name
// next <- Operation name
// fbNext <- Method name
// invalid is not a pointer

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"
 
using namespace NewModel;

Next_callExecution::Next_callExecution()
{
}

Next_callExecution::~Next_callExecution()
{
}


Next_callExecution::Next_callExecution(Next_callExecution &obj):
	OpaqueBehaviorExecutionImpl(obj)
{
}

ecore::EObject* Next_callExecution::copy()
{
    return new Next_callExecution(*this);
}

void Next_callExecution::doBody(QList<fUML::ParameterValue *> *inputParameters, QList<fUML::ParameterValue *> *outputParameters)
{
    DEBUG_MESSAGE(std::cout<<"Printing from "<< this->getBehavior()->getName();)
    DEBUG_MESSAGE(std::cout<<"__________________________";)



	NewModel::PrimeChecker * target = dynamic_cast<NewModel::PrimeCheckerExecution*>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //call assigned operation
	  target->next();

	//set out/result parameter
	
	//set InOut parameters
}
