#include "CalcModelExec/FbIsOddExecution.hpp"

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
	std::shared_ptr<FbIsOddExecution> element(new FbIsOddExecution(*this));
	element->setThisExecutionPtr(element);
	return element;
}

void FbIsOddExecution::doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)

   	bool isOdd;


	//Call Operation action target
	std::shared_ptr<CalcModel::PrimeChecker> target = std::dynamic_pointer_cast<PrimeCheckerObject>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------
	
	//Calling the associated operation.
			isOdd = target->isOdd();
    //End -----------------------------

	//set return / out parameters
    std::shared_ptr<fUML::BooleanValue> isOddValue(fUML::FUMLFactory::eInstance()->createBooleanValue());
 	isOddValue->setValue(isOdd);
    outputParameters->at(0)->getValues()->push_back(isOddValue);

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbIsOdd ends its execution ^^^^^" << std::endl;)
}

void FbIsOddExecution::setThisExecutionPtr(std::weak_ptr<FbIsOddExecution> thisExecutionPtr)
{
	setThisOpaqueBehaviorExecutionPtr(thisExecutionPtr);
}
