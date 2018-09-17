
#include "Next_callExecution.hpp"

#include "QDebug" 
#include "ParameterValue.hpp"


// PrimeChecker <- Class name
// next <- Operation name
// next <- Method name
// invalid is not a pointer

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"
 
using namespace NewModel;

Next_callExecution::Next_callExecution()
{
    
}

Next_callExecution::~Next_callExecution()
{
    
}


Next_callExecution::Next_callExecution(Next_callExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
    
}

ecore::EObject *  Next_callExecution::copy()
{
    return new Next_callExecution(*this);
}


void Next_callExecution::doBody(QList<fUML::ParameterValue *> *inputParameters, QList<fUML::ParameterValue *> *outputParameters)
{
    qDebug()<<"Printing from "<< this->getBehavior()->getName();
    qDebug()<<"__________________________";



	NewModel::PrimeChecker * target = dynamic_cast<NewModel::PrimeCheckerExecution*>(this->getContext())->getUmlValue();
    Q_ASSERT(target!=nullptr);


    //call assigned operation
    
	  target->next();

	//set out/result parameter
    
	
	//set InOut parameters

}

