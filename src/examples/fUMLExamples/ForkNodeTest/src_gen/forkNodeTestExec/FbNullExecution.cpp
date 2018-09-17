#include "forkNodeTestExec/FbNullExecution.hpp"

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






using namespace forkNodeTest;

FbNullExecution::FbNullExecution()
{
}

FbNullExecution::~FbNullExecution()
{
}

FbNullExecution::FbNullExecution(const FbNullExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
}

std::shared_ptr<ecore::EObject> FbNullExecution::copy() const
{
	std::shared_ptr<FbNullExecution> element(new FbNullExecution(*this));
	element->setThisExecutionPtr(element);
	return element;
}

void FbNullExecution::doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)




    //Body of the Opaquebehavior
    //Start ---------------------------
		//Function Behaviour from a Call Behavior Action false

   		;
    //End -----------------------------

	//set return / out parameters

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbNull ends its execution ^^^^^" << std::endl;)
}

void FbNullExecution::setThisExecutionPtr(std::weak_ptr<FbNullExecution> thisExecutionPtr)
{
	setThisOpaqueBehaviorExecutionPtr(thisExecutionPtr);
}
