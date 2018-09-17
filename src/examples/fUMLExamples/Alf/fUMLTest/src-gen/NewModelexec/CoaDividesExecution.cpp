
#include "CoaDividesExecution.hpp"

#include "QDebug" 
#include "ParameterValue.hpp"


// PrimeChecker <- Class name
// divides <- Operation name
// divides <- Method name
// Boolean is not a pointer
#include "BooleanValue.hpp"


#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"
 
using namespace NewModel;

CoaDividesExecution::CoaDividesExecution()
{
    
}

CoaDividesExecution::~CoaDividesExecution()
{
    
}


CoaDividesExecution::CoaDividesExecution(CoaDividesExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
    
}

ecore::EObject *  CoaDividesExecution::copy()
{
    return new CoaDividesExecution(*this);
}


void CoaDividesExecution::doBody(QList<fUML::ParameterValue *> *inputParameters, QList<fUML::ParameterValue *> *outputParameters)
{
    qDebug()<<"Printing from "<< this->getBehavior()->getName();
    qDebug()<<"__________________________";

    bool isDivisible;


	NewModel::PrimeChecker * target = dynamic_cast<NewModel::PrimeCheckerExecution*>(this->getContext())->getUmlValue();
    Q_ASSERT(target!=nullptr);


    //call assigned operation
    
	 isDivisible =   target->divides();

	//set out/result parameter
    
    fUML::BooleanValue * isDivisibleValue = fUML::FUMLFactory::eInstance()->createBooleanValue();
 	isDivisibleValue->setValue(isDivisible);
    outputParameters->value(0)->getValues()->append(isDivisibleValue);
	
	//set InOut parameters

}

