#include "FbNextExecution.hpp"
#include <iostream>
#include <cassert>
#include "ParameterValue.hpp"

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"


using namespace NewModel;

FbNextExecution::FbNextExecution()
{
}

FbNextExecution::~FbNextExecution()
{
}

FbNextExecution::FbNextExecution(const FbNextExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
}

ecore::EObject* FbNextExecution::copy() const
{
    return new FbNextExecution(*this);
}

void FbNextExecution::doBody(std::vector<fUML::ParameterValue *> *inputParameters, std::vector<fUML::ParameterValue *> *outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)



	//Call Operation action target
	NewModel::PrimeChecker * target = dynamic_cast<NewModel::PrimeCheckerExecution*>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------
	
	//Calling the associated operation.
  target->next();
    //End -----------------------------

	//set return / out parameters

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbNext ends its execution ^^^^^" << std::endl;)
}
