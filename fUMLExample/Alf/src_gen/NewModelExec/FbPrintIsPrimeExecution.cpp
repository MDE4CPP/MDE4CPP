#include "FbPrintIsPrimeExecution.hpp"
#include <iostream>
#include <cassert>
#include "ParameterValue.hpp"



using namespace NewModel;

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

ecore::EObject* FbPrintIsPrimeExecution::copy() const
{
    return new FbPrintIsPrimeExecution(*this);
}

void FbPrintIsPrimeExecution::doBody(std::vector<fUML::ParameterValue *> *inputParameters, std::vector<fUML::ParameterValue *> *outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)




    //Body of the Opaquebehavior
    //Start ---------------------------
		//Function Behaviour from a Call Behavior Action
   		std::cout<<"Number is prime";
    //End -----------------------------

	//set return / out parameters

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbPrintIsPrime ends its execution ^^^^^" << std::endl;)
}
