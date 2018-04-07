#include "CalcModelExec/FbNextExecution.hpp"

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


using namespace CalcModel;

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

std::shared_ptr<ecore::EObject> FbNextExecution::copy() const
{
	std::shared_ptr<FbNextExecution> element(new FbNextExecution(*this));
	element->setThisExecutionPtr(element);
	return element;
}

void FbNextExecution::doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)



	//Call Operation action target
	std::shared_ptr<CalcModel::PrimeChecker> target = std::dynamic_pointer_cast<PrimeCheckerObject>(this->getContext())->getUmlValue();
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

void FbNextExecution::setThisExecutionPtr(std::weak_ptr<FbNextExecution> thisExecutionPtr)
{
	setThisOpaqueBehaviorExecutionPtr(thisExecutionPtr);
}
