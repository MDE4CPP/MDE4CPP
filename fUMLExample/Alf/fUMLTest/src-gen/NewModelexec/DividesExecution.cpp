
#include "DividesExecution.hpp"

#include "QDebug"
#include "ParameterValue.hpp"


#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"

#include "BooleanValue.hpp"



 
using namespace NewModel;

DividesExecution::DividesExecution()
{
    
}

DividesExecution::~DividesExecution()
{
    
}


DividesExecution::DividesExecution(DividesExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
    
}

ecore::EObject *  DividesExecution::copy()
{
    return new DividesExecution(*this);
}


void DividesExecution::doBody(QList<fUML::ParameterValue *> *inputParameters, QList<fUML::ParameterValue *> *outputParameters)
{
    qDebug()<<"Printing from "<< this->getBehavior()->getName();
    qDebug()<<"__________________________";

    bool isDivisible;


	//Call Operation action target
	NewModel::PrimeChecker * target = dynamic_cast<NewModel::PrimeCheckerExecution*>(this->getContext())->getUmlValue();
    Q_ASSERT(target!=nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------

	
	//Calling the associated operation.
 isDivisible =   target->divides();
    //End -----------------------------

	//set return / out parameters
    fUML::BooleanValue * isDivisibleValue = fUML::FUMLFactory::eInstance()->createBooleanValue();
 	isDivisibleValue->setValue(isDivisible);
    outputParameters->value(0)->getValues()->append(isDivisibleValue);


	//set InOut parameters
	qDebug()<< "^^^^^ FB divides ends its execution ^^^^^";
}

