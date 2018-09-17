
#include "NextExecution.hpp"

#include "QDebug"
#include "ParameterValue.hpp"


#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"



 
using namespace NewModel;

NextExecution::NextExecution()
{
    
}

NextExecution::~NextExecution()
{
    
}


NextExecution::NextExecution(NextExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
    
}

ecore::EObject *  NextExecution::copy()
{
    return new NextExecution(*this);
}


void NextExecution::doBody(QList<fUML::ParameterValue *> *inputParameters, QList<fUML::ParameterValue *> *outputParameters)
{
    qDebug()<<"Printing from "<< this->getBehavior()->getName();
    qDebug()<<"__________________________";



	//Call Operation action target
	NewModel::PrimeChecker * target = dynamic_cast<NewModel::PrimeCheckerExecution*>(this->getContext())->getUmlValue();
    Q_ASSERT(target!=nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------

	
	//Calling the associated operation.
  target->next();
    //End -----------------------------

	//set return / out parameters


	//set InOut parameters
	qDebug()<< "^^^^^ FB next ends its execution ^^^^^";
}

