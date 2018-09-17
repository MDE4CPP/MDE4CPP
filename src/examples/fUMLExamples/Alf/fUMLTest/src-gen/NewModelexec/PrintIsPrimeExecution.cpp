
#include "PrintIsPrimeExecution.hpp"

#include "QDebug"
#include "ParameterValue.hpp"
#include <iostream>



 
using namespace NewModel;

PrintIsPrimeExecution::PrintIsPrimeExecution()
{
    
}

PrintIsPrimeExecution::~PrintIsPrimeExecution()
{
    
}


PrintIsPrimeExecution::PrintIsPrimeExecution(PrintIsPrimeExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
    
}

ecore::EObject *  PrintIsPrimeExecution::copy()
{
    return new PrintIsPrimeExecution(*this);
}


void PrintIsPrimeExecution::doBody(QList<fUML::ParameterValue *> *inputParameters, QList<fUML::ParameterValue *> *outputParameters)
{
    qDebug()<<"Printing from "<< this->getBehavior()->getName();
    qDebug()<<"__________________________";




    //Body of the Opaquebehavior
    //Start ---------------------------

		//Function Behaviour from a Call Behavior Action
        std::cout<<"Number is prime";
    //End -----------------------------

	//set return / out parameters


	//set InOut parameters
	qDebug()<< "^^^^^ FB printIsPrime ends its execution ^^^^^";
}

