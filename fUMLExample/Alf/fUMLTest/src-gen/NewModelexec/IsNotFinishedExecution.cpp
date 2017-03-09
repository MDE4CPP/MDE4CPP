
#include "IsNotFinishedExecution.hpp"

#include "QDebug"
#include "ParameterValue.hpp"


#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"

#include "BooleanValue.hpp"



 
using namespace NewModel;

IsNotFinishedExecution::IsNotFinishedExecution()
{
    
}

IsNotFinishedExecution::~IsNotFinishedExecution()
{
    
}


IsNotFinishedExecution::IsNotFinishedExecution(IsNotFinishedExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
    
}

ecore::EObject *  IsNotFinishedExecution::copy()
{
    return new IsNotFinishedExecution(*this);
}


void IsNotFinishedExecution::doBody(QList<fUML::ParameterValue *> *inputParameters, QList<fUML::ParameterValue *> *outputParameters)
{
    qDebug()<<"Printing from "<< this->getBehavior()->getName();
    qDebug()<<"__________________________";

    bool isNotFinished;


	//Call Operation action target
	NewModel::PrimeChecker * target = dynamic_cast<NewModel::PrimeCheckerExecution*>(this->getContext())->getUmlValue();
    Q_ASSERT(target!=nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------

	
	//Calling the associated operation.
 isNotFinished =   target->isNotFinished();
    //End -----------------------------

	//set return / out parameters
    fUML::BooleanValue * isNotFinishedValue = fUML::FUMLFactory::eInstance()->createBooleanValue();
 	isNotFinishedValue->setValue(isNotFinished);
    outputParameters->value(0)->getValues()->append(isNotFinishedValue);


	//set InOut parameters
	qDebug()<< "^^^^^ FB isNotFinished ends its execution ^^^^^";
}

