#include "CalcModelExec/FbIsNotFinishedExecution.hpp"
#include <iostream>
#include <memory>
#include <cassert>

#include "fUML/ParameterValue.hpp"

#include "CalcModel/PrimeChecker.hpp"
#include "CalcModelExec/PrimeCheckerExecution.hpp"

#include "fUML/BooleanValue.hpp"

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

std::shared_ptr<ecore::EObject> FbIsNotFinishedExecution::copy() const
{
	std::shared_ptr<ecore::EObject> element(new FbIsNotFinishedExecution(*this));
	return element;
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
