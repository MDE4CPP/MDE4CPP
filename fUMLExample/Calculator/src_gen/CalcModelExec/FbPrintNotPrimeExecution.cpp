#include "CalcModelExec/FbPrintNotPrimeExecution.hpp"

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

//Included from function behavior "fbPrintNotPrime"
#include <iostream>



using namespace CalcModel;

FbPrintNotPrimeExecution::FbPrintNotPrimeExecution()
{
}

FbPrintNotPrimeExecution::~FbPrintNotPrimeExecution()
{
}

FbPrintNotPrimeExecution::FbPrintNotPrimeExecution(const FbPrintNotPrimeExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
}

std::shared_ptr<ecore::EObject> FbPrintNotPrimeExecution::copy() const
{
	std::shared_ptr<FbPrintNotPrimeExecution> element(new FbPrintNotPrimeExecution(*this));
	element->setThisExecutionPtr(element);
	return element;
}

void FbPrintNotPrimeExecution::doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)




    //Body of the Opaquebehavior
    //Start ---------------------------
		//Function Behaviour from a Call Behavior Action
   		std::cout<<"Number is not prime";
    //End -----------------------------

	//set return / out parameters

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbPrintNotPrime ends its execution ^^^^^" << std::endl;)
}

void FbPrintNotPrimeExecution::setThisExecutionPtr(std::weak_ptr<FbPrintNotPrimeExecution> thisExecutionPtr)
{
	setThisOpaqueBehaviorExecutionPtr(thisExecutionPtr);
}
