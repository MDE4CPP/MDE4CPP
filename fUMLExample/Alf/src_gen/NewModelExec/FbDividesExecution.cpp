#include "FbDividesExecution.hpp"
#include <iostream>
#include <cassert>
#include "ParameterValue.hpp"

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"

#include "BooleanValue.hpp"

using namespace NewModel;

FbDividesExecution::FbDividesExecution()
{
}

FbDividesExecution::~FbDividesExecution()
{
}

FbDividesExecution::FbDividesExecution(const FbDividesExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
}

ecore::EObject* FbDividesExecution::copy() const
{
    return new FbDividesExecution(*this);
}

void FbDividesExecution::doBody(std::vector<fUML::ParameterValue *> *inputParameters, std::vector<fUML::ParameterValue *> *outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)

    bool isDivisible;


	//Call Operation action target
	NewModel::PrimeChecker * target = dynamic_cast<NewModel::PrimeCheckerExecution*>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------
	
	//Calling the associated operation.
 isDivisible =   target->divides();
    //End -----------------------------

	//set return / out parameters
    fUML::BooleanValue * isDivisibleValue = fUML::FUMLFactory::eInstance()->createBooleanValue();
 	isDivisibleValue->setValue(isDivisible);
    outputParameters->at(0)->getValues()->push_back(isDivisibleValue);

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbDivides ends its execution ^^^^^" << std::endl;)
}
