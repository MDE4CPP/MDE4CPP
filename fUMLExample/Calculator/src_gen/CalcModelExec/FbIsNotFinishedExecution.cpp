#include "FbIsNotFinishedExecution.hpp"
#include <iostream>
#include <memory>
#include <cassert>
#include "ParameterValue.hpp"

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"

#include "BooleanValue.hpp"

using namespace CalcModel;

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

void FbIsNotFinishedExecution::doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)

    bool isNotFinished;


	//Call Operation action target
	std::shared_ptr<CalcModel::PrimeChecker> target = std::dynamic_pointer_cast<PrimeCheckerExecution>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------
	
	//Calling the associated operation.
 isNotFinished =   target->isNotFinished();
    //End -----------------------------

	//set return / out parameters
    std::shared_ptr<fUML::BooleanValue> isNotFinishedValue(fUML::FUMLFactory::eInstance()->createBooleanValue());
 	isNotFinishedValue->setValue(isNotFinished);
    outputParameters->at(0)->getValues()->push_back(isNotFinishedValue);

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbIsNotFinished ends its execution ^^^^^" << std::endl;)
}
