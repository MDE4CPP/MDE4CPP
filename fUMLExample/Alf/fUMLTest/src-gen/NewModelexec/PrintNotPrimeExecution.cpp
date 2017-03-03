
#include "PrintNotPrimeExecution.hpp"

#include "QDebug"
#include "ParameterValue.hpp"

#include <iostream>


 
using namespace NewModel;

PrintNotPrimeExecution::PrintNotPrimeExecution()
{
    
}

PrintNotPrimeExecution::~PrintNotPrimeExecution()
{
    
}


PrintNotPrimeExecution::PrintNotPrimeExecution(PrintNotPrimeExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
    
}

ecore::EObject *  PrintNotPrimeExecution::copy()
{
    return new PrintNotPrimeExecution(*this);
}


void PrintNotPrimeExecution::doBody(QList<fUML::ParameterValue *> *inputParameters, QList<fUML::ParameterValue *> *outputParameters)
{
    qDebug()<<"Printing from "<< this->getBehavior()->getName();
    qDebug()<<"__________________________";




    //Body of the Opaquebehavior
    //Start ---------------------------

		//Function Behaviour from a Call Behavior Action
        std::cout<<"Number is not prime";
    //End -----------------------------

	//set return / out parameters


	//set InOut parameters
	qDebug()<< "^^^^^ FB PrintNotPrime ends its execution ^^^^^";
}

