#include "FbDividesExecution.hpp"
#include <iostream>
#include <memory>
#include <cassert>
#include "ParameterValue.hpp"

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"

#include "BooleanValue.hpp"

using namespace CalcModel;

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

void FbDividesExecution::doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)

    bool isDivisible;


	//Call Operation action target
	std::shared_ptr<CalcModel::PrimeChecker>target = std::dynamic_pointer_cast<CalcModel::PrimeCheckerExecution>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------
	
	//Calling the associated operation.
 isDivisible =   target->divides();
    //End -----------------------------

	//set return / out parameters
    std::shared_ptr<fUML::BooleanValue> isDivisibleValue(fUML::FUMLFactory::eInstance()->createBooleanValue());
 	isDivisibleValue->setValue(isDivisible);
    outputParameters->at(0)->getValues()->push_back(isDivisibleValue);

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbDivides ends its execution ^^^^^" << std::endl;)
}
