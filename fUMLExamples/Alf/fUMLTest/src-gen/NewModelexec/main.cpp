#include "QDebug"

#include "FUMLFactory.hpp"
#include "Locus.hpp"
#include "Executor.hpp"
#include "ExecutionFactoryL3.hpp"
#include "FirstChoiceStrategy.hpp"
#include "DispatchStrategy.hpp"
#include "FunctionBehavior.hpp"
#include "Activity.hpp"
#include "Reference.hpp"
#include "NewModelFactory.hpp"

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"

#include "ParameterValue.hpp"


//include Model package
#include "NewModelPackage.hpp"

#include "NewModelPackage.hpp"
#include "NewModelPackage.hpp"
#include "NewModelPackage.hpp"
#include "NewModelPackage.hpp"
#include "NewModelPackage.hpp"
#include "NewModelPackage.hpp"


//OpaqueBehaviourExecutions
#include "PrintNotPrimeExecution.hpp"
#include "IsNotFinishedExecution.hpp"
#include "DividesExecution.hpp"
#include "IsOddExecution.hpp"
#include "NextExecution.hpp"
#include "PrintIsPrimeExecution.hpp"


using namespace NewModel;

int main()
{	
	qDebug()<<"Main function is executing";
    fUML::FUMLFactory * fumlFac = fUML::FUMLFactory::eInstance();
    fUML::Locus  * locus = fumlFac->createLocus();

    fUML::Executor * executor = fumlFac->createExecutor();
    executor->setLocus(locus);

    fUML::ExecutionFactoryL3 * factory = fumlFac->createExecutionFactoryL3();
    factory->setLocus(locus);

    locus->setFactory(factory);
    locus->setExecutor(executor);

    locus->getFactory()->assignStrategy(fumlFac->createFirstChoiceStrategy());
	locus->getFactory()->assignStrategy(fumlFac->createDispatchStrategy());

    //Executor will execute the first Activity

	/*
    fUML::ActivityExecution * newModel_CheckIfPrimeExecution = new CheckIfPrimeExecution();
    newModel_CheckIfPrimeExecution->getTypes()->append(NewModel::NewModelPackage::eInstance()->get_NewModel_CheckIfPrime());
    newModel_CheckIfPrimeExecution->setLocus(factory->getLocus());
    newModel_CheckIfPrimeExecution->execute();
	*/

    fUML::OpaqueBehaviorExecution * newModel_PrimeChecker_printIsPrimeExecution =  new PrintIsPrimeExecution();
    newModel_PrimeChecker_printIsPrimeExecution->getTypes()->append(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_printIsPrime());
    newModel_PrimeChecker_printIsPrimeExecution->setLocus(factory->getLocus());
    factory->addPrimitiveBehaviorPrototype(newModel_PrimeChecker_printIsPrimeExecution);
    
    fUML::OpaqueBehaviorExecution * newModel_PrimeChecker_nextExecution =  new NextExecution();
    newModel_PrimeChecker_nextExecution->getTypes()->append(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_next());
    newModel_PrimeChecker_nextExecution->setLocus(factory->getLocus());
    factory->addPrimitiveBehaviorPrototype(newModel_PrimeChecker_nextExecution);
    
    fUML::OpaqueBehaviorExecution * newModel_PrimeChecker_dividesExecution =  new DividesExecution();
    newModel_PrimeChecker_dividesExecution->getTypes()->append(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_divides());
    newModel_PrimeChecker_dividesExecution->setLocus(factory->getLocus());
    factory->addPrimitiveBehaviorPrototype(newModel_PrimeChecker_dividesExecution);
    
    fUML::OpaqueBehaviorExecution * newModel_PrimeChecker_isNotFinishedExecution =  new IsNotFinishedExecution();
    newModel_PrimeChecker_isNotFinishedExecution->getTypes()->append(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_isNotFinished());
    newModel_PrimeChecker_isNotFinishedExecution->setLocus(factory->getLocus());
    factory->addPrimitiveBehaviorPrototype(newModel_PrimeChecker_isNotFinishedExecution);
    
    fUML::OpaqueBehaviorExecution * newModel_PrimeChecker_isOddExecution =  new IsOddExecution();
    newModel_PrimeChecker_isOddExecution->getTypes()->append(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_isOdd());
    newModel_PrimeChecker_isOddExecution->setLocus(factory->getLocus());
    factory->addPrimitiveBehaviorPrototype(newModel_PrimeChecker_isOddExecution);
    
    fUML::OpaqueBehaviorExecution * newModel_PrimeChecker_PrintNotPrimeExecution =  new PrintNotPrimeExecution();
    newModel_PrimeChecker_PrintNotPrimeExecution->getTypes()->append(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_PrintNotPrime());
    newModel_PrimeChecker_PrintNotPrimeExecution->setLocus(factory->getLocus());
    factory->addPrimitiveBehaviorPrototype(newModel_PrimeChecker_PrintNotPrimeExecution);
    
    

    QList<fUML::ParameterValue *> * pList = new QList<fUML::ParameterValue *>();

    
    //INput parameter ActInputNode 
    fUML::ParameterValue * ActInputNodeP = fumlFac->createParameterValue();
    ActInputNodeP->setParameter(NewModel::NewModelPackage::eInstance()->get_NewModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode());
    fUML::Reference * ActInputNodeValue = fUML::FUMLFactory::eInstance()->createReference();
    NewModel::PrimeCheckerExecution * ActInputNodeUmlLinker = new NewModel::PrimeCheckerExecution();
	ActInputNodeUmlLinker = new PrimeCheckerExecution(NewModel::NewModelFactory::eInstance()->createPrimeChecker());
	ActInputNodeUmlLinker->setLocus(locus);
	ActInputNodeValue->setReferent(ActInputNodeUmlLinker);
    ActInputNodeP->getValues()->append(ActInputNodeValue);
    pList->append(ActInputNodeP);

    QList<fUML::ParameterValue *> * resultPList = locus->getExecutor()->execute(NewModel::NewModelPackage::eInstance()->get_NewModel_CheckIfPrime(),nullptr,pList);

	if(nullptr == resultPList)
	{
        qWarning("resultPList is null");
        return EXIT_FAILURE;
	}
    if(resultPList->isEmpty())
    {
        qDebug()<< "The activity didn't return any parameter.";
    }
    else{
        qDebug() << resultPList->size();
        for(int parIndex=0; parIndex< resultPList->size(); parIndex++){
            qDebug() << "Parameter " << parIndex <<" name: "<<resultPList->value(parIndex)->getParameter()->getName();
            if(resultPList->value(parIndex)->getValues()->isEmpty())
            {
                qDebug()<<"\tThe parameter is empty.";
            }
            else
            {
                qDebug() << "\tsize: " << resultPList->value(parIndex)->getValues()->size();
                qDebug() << "\tvalue of the first element: " << resultPList->value(parIndex)->getValues()->first()->toString();
            }
        }
    }
    return EXIT_SUCCESS;
}

