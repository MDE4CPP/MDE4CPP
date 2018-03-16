#include "CalcModelExec/FbDividesExecution.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <cassert>
#include <iostream>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp" 
#include "fUML/FUMLFactory.hpp"
#include "fUML/ParameterValue.hpp"
#include "uml/Behavior.hpp"


#include "CalcModel/PrimeChecker.hpp"
#include "CalcModelExec/PrimeCheckerObject.hpp"

#include "fUML/BooleanValue.hpp"

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

std::shared_ptr<ecore::EObject> FbDividesExecution::copy() const
{
	std::shared_ptr<FbDividesExecution> element(new FbDividesExecution(*this));
	element->setThisExecutionPtr(element);
	return element;
}

void FbDividesExecution::doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)

   	bool isDivisible;


	//Call Operation action target
	std::shared_ptr<CalcModel::PrimeChecker> target = std::dynamic_pointer_cast<PrimeCheckerObject>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------
	
	//Calling the associated operation.
			isDivisible = target->divides();
    //End -----------------------------

	//set return / out parameters
    std::shared_ptr<fUML::BooleanValue> isDivisibleValue(fUML::FUMLFactory::eInstance()->createBooleanValue());
 	isDivisibleValue->setValue(isDivisible);
    outputParameters->at(0)->getValues()->push_back(isDivisibleValue);

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbDivides ends its execution ^^^^^" << std::endl;)
}

void FbDividesExecution::setThisExecutionPtr(std::weak_ptr<FbDividesExecution> thisExecutionPtr)
{
	setThisOpaqueBehaviorExecutionPtr(thisExecutionPtr);
}
