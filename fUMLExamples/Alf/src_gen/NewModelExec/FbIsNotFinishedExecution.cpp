#include "FbIsNotFinishedExecution.hpp"
#include <iostream>
#include <cassert>
#include "ParameterValue.hpp"

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"

#include "BooleanValue.hpp"

using namespace NewModel;

FbIsNotFinishedExecution::FbIsNotFinishedExecution()
{
}

FbIsNotFinishedExecution::~FbIsNotFinishedExecution()
{
}

FbIsNotFinishedExecution::FbIsNotFinishedExecution(const FbIsNotFinishedExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
}

ecore::EObject* FbIsNotFinishedExecution::copy() const
{
    return new FbIsNotFinishedExecution(*this);
}

void FbIsNotFinishedExecution::doBody(std::vector<fUML::ParameterValue *> *inputParameters, std::vector<fUML::ParameterValue *> *outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)

    bool isNotFinished;


	//Call Operation action target
	NewModel::PrimeChecker * target = dynamic_cast<NewModel::PrimeCheckerExecution*>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------
	
	//Calling the associated operation.
 isNotFinished =   target->isNotFinished();
    //End -----------------------------

	//set return / out parameters
    fUML::BooleanValue * isNotFinishedValue = fUML::FUMLFactory::eInstance()->createBooleanValue();
 	isNotFinishedValue->setValue(isNotFinished);
    outputParameters->at(0)->getValues()->push_back(isNotFinishedValue);

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbIsNotFinished ends its execution ^^^^^" << std::endl;)
}
