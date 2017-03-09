#include "FbIsOddExecution.hpp"
#include <iostream>
#include <cassert>
#include "ParameterValue.hpp"

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"

#include "BooleanValue.hpp"

using namespace NewModel;

FbIsOddExecution::FbIsOddExecution()
{
}

FbIsOddExecution::~FbIsOddExecution()
{
}

FbIsOddExecution::FbIsOddExecution(const FbIsOddExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
}

ecore::EObject* FbIsOddExecution::copy() const
{
    return new FbIsOddExecution(*this);
}

void FbIsOddExecution::doBody(std::vector<fUML::ParameterValue *> *inputParameters, std::vector<fUML::ParameterValue *> *outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)

    bool isOdd;


	//Call Operation action target
	NewModel::PrimeChecker * target = dynamic_cast<NewModel::PrimeCheckerExecution*>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------
	
	//Calling the associated operation.
 isOdd =   target->isOdd();
    //End -----------------------------

	//set return / out parameters
    fUML::BooleanValue * isOddValue = fUML::FUMLFactory::eInstance()->createBooleanValue();
 	isOddValue->setValue(isOdd);
    outputParameters->at(0)->getValues()->push_back(isOddValue);

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbIsOdd ends its execution ^^^^^" << std::endl;)
}
