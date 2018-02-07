#include "CalcModelExec/FbPrintIsPrimeExecution.hpp"
#include <iostream>
#include <memory>
#include <cassert>

#include "fUML/ParameterValue.hpp"



using namespace CalcModel;

FbPrintIsPrimeExecution::FbPrintIsPrimeExecution()
{
}

FbPrintIsPrimeExecution::~FbPrintIsPrimeExecution()
{
}

FbPrintIsPrimeExecution::FbPrintIsPrimeExecution(const FbPrintIsPrimeExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
}

std::shared_ptr<ecore::EObject> FbPrintIsPrimeExecution::copy() const
{
	std::shared_ptr<ecore::EObject> element(new FbPrintIsPrimeExecution(*this));
	return element;
}

void FbPrintIsPrimeExecution::doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)




    //Body of the Opaquebehavior
    //Start ---------------------------
		//Function Behaviour from a Call Behavior Action
   		std::cout<<"Number is prime"<<std::endl;
    //End -----------------------------

	//set return / out parameters

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbPrintIsPrime ends its execution ^^^^^" << std::endl;)
}
