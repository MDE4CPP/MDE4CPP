
#include "CoaIsOddExecution.hpp"

#include "QDebug" 
#include "ParameterValue.hpp"


// PrimeChecker <- Class name
// isOdd <- Operation name
// isOdd <- Method name
// Boolean is not a pointer
#include "BooleanValue.hpp"


#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"
 
using namespace NewModel;

CoaIsOddExecution::CoaIsOddExecution()
{
    
}

CoaIsOddExecution::~CoaIsOddExecution()
{
    
}


CoaIsOddExecution::CoaIsOddExecution(CoaIsOddExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
    
}

ecore::EObject *  CoaIsOddExecution::copy()
{
    return new CoaIsOddExecution(*this);
}


void CoaIsOddExecution::doBody(QList<fUML::ParameterValue *> *inputParameters, QList<fUML::ParameterValue *> *outputParameters)
{
    qDebug()<<"Printing from "<< this->getBehavior()->getName();
    qDebug()<<"__________________________";

    bool isOdd;


	NewModel::PrimeChecker * target = dynamic_cast<NewModel::PrimeCheckerExecution*>(this->getContext())->getUmlValue();
    Q_ASSERT(target!=nullptr);


    //call assigned operation
    
	 isOdd =   target->isOdd();

	//set out/result parameter
    
    fUML::BooleanValue * isOddValue = fUML::FUMLFactory::eInstance()->createBooleanValue();
 	isOddValue->setValue(isOdd);
    outputParameters->value(0)->getValues()->append(isOddValue);
	
	//set InOut parameters

}

