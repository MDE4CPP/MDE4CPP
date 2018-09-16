#include "FbPrintNotPrimeExecution.hpp"
#include <iostream>
#include <cassert>
#include "ParameterValue.hpp"



using namespace NewModel;

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

ecore::EObject* FbPrintNotPrimeExecution::copy() const
{
    return new FbPrintNotPrimeExecution(*this);
}

void FbPrintNotPrimeExecution::doBody(std::vector<fUML::ParameterValue *> *inputParameters, std::vector<fUML::ParameterValue *> *outputParameters)
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
