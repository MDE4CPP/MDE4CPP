#include "FbIsOddExecution.hpp"
#include <iostream>
#include <memory>
#include <cassert>
#include "ParameterValue.hpp"

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"

#include "BooleanValue.hpp"

using namespace CalcModel;

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

std::shared_ptr<ecore::EObject> FbIsOddExecution::copy() const
{
	std::shared_ptr<ecore::EObject> element(new FbIsOddExecution(*this));
	return element;
}

void FbIsOddExecution::doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)

    bool isOdd;


	//Call Operation action target
	std::shared_ptr<CalcModel::PrimeChecker> target = std::dynamic_pointer_cast<PrimeCheckerExecution>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------
	
	//Calling the associated operation.
 isOdd =   target->isOdd();
    //End -----------------------------

	//set return / out parameters
    std::shared_ptr<fUML::BooleanValue> isOddValue(fUML::FUMLFactory::eInstance()->createBooleanValue());
 	isOddValue->setValue(isOdd);
    outputParameters->at(0)->getValues()->push_back(isOddValue);

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbIsOdd ends its execution ^^^^^" << std::endl;)
}
