
#include "IsOddExecution.hpp"

#include "QDebug"
#include "ParameterValue.hpp"


#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"

#include "BooleanValue.hpp"



 
using namespace NewModel;

IsOddExecution::IsOddExecution()
{
    
}

IsOddExecution::~IsOddExecution()
{
    
}


IsOddExecution::IsOddExecution(IsOddExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
    
}

ecore::EObject *  IsOddExecution::copy()
{
    return new IsOddExecution(*this);
}


void IsOddExecution::doBody(QList<fUML::ParameterValue *> *inputParameters, QList<fUML::ParameterValue *> *outputParameters)
{
    qDebug()<<"Printing from "<< this->getBehavior()->getName();
    qDebug()<<"__________________________";

    bool isOdd;


	//Call Operation action target
	NewModel::PrimeChecker * target = dynamic_cast<NewModel::PrimeCheckerExecution*>(this->getContext())->getUmlValue();
    Q_ASSERT(target!=nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------

	
	//Calling the associated operation.
 isOdd =   target->isOdd();
    //End -----------------------------

	//set return / out parameters
    fUML::BooleanValue * isOddValue = fUML::FUMLFactory::eInstance()->createBooleanValue();
 	isOddValue->setValue(isOdd);
    outputParameters->value(0)->getValues()->append(isOddValue);


	//set InOut parameters
	qDebug()<< "^^^^^ FB isOdd ends its execution ^^^^^";
}

