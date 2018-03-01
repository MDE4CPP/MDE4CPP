#include "CalcModelExec/FbPrintNotPrimeExecution.hpp"
#include <iostream>
#include <memory>
#include <cassert>

#include "fUML/ParameterValue.hpp"



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
	std::shared_ptr<ecore::EObject> element(new FbPrintNotPrimeExecution(*this));
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
