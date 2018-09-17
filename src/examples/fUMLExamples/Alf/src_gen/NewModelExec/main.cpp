#include <iostream>
#include <vector>

#include "FUMLFactory.hpp"
#include "Locus.hpp"
#include "Executor.hpp"
#include "Parameter.hpp"
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
#include "FbIsNotFinishedExecution.hpp"
#include "FbPrintIsPrimeExecution.hpp"
#include "FbPrintNotPrimeExecution.hpp"
#include "FbNextExecution.hpp"
#include "FbDividesExecution.hpp"
#include "FbIsOddExecution.hpp"


using namespace NewModel;

int main()
{	
	DEBUG_MESSAGE(std::cout<<"Main function is executing"<<std::endl;)
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

    fUML::OpaqueBehaviorExecution * newModel_PrimeChecker_fbIsOddExecution =  new NewModel::FbIsOddExecution();
    newModel_PrimeChecker_fbIsOddExecution->getTypes()->push_back(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_fbIsOdd());
    newModel_PrimeChecker_fbIsOddExecution->setLocus(factory->getLocus());
    factory->addPrimitiveBehaviorPrototype(newModel_PrimeChecker_fbIsOddExecution);
    
    fUML::OpaqueBehaviorExecution * newModel_PrimeChecker_fbIsNotFinishedExecution =  new NewModel::FbIsNotFinishedExecution();
    newModel_PrimeChecker_fbIsNotFinishedExecution->getTypes()->push_back(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_fbIsNotFinished());
    newModel_PrimeChecker_fbIsNotFinishedExecution->setLocus(factory->getLocus());
    factory->addPrimitiveBehaviorPrototype(newModel_PrimeChecker_fbIsNotFinishedExecution);
    
    fUML::OpaqueBehaviorExecution * newModel_PrimeChecker_fbDividesExecution =  new NewModel::FbDividesExecution();
    newModel_PrimeChecker_fbDividesExecution->getTypes()->push_back(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_fbDivides());
    newModel_PrimeChecker_fbDividesExecution->setLocus(factory->getLocus());
    factory->addPrimitiveBehaviorPrototype(newModel_PrimeChecker_fbDividesExecution);
    
    fUML::OpaqueBehaviorExecution * newModel_PrimeChecker_fbNextExecution =  new NewModel::FbNextExecution();
    newModel_PrimeChecker_fbNextExecution->getTypes()->push_back(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_fbNext());
    newModel_PrimeChecker_fbNextExecution->setLocus(factory->getLocus());
    factory->addPrimitiveBehaviorPrototype(newModel_PrimeChecker_fbNextExecution);
    
    fUML::OpaqueBehaviorExecution * newModel_PrimeChecker_fbPrintNotPrimeExecution =  new NewModel::FbPrintNotPrimeExecution();
    newModel_PrimeChecker_fbPrintNotPrimeExecution->getTypes()->push_back(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_fbPrintNotPrime());
    newModel_PrimeChecker_fbPrintNotPrimeExecution->setLocus(factory->getLocus());
    factory->addPrimitiveBehaviorPrototype(newModel_PrimeChecker_fbPrintNotPrimeExecution);
    
    fUML::OpaqueBehaviorExecution * newModel_PrimeChecker_fbPrintIsPrimeExecution =  new NewModel::FbPrintIsPrimeExecution();
    newModel_PrimeChecker_fbPrintIsPrimeExecution->getTypes()->push_back(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_fbPrintIsPrime());
    newModel_PrimeChecker_fbPrintIsPrimeExecution->setLocus(factory->getLocus());
    factory->addPrimitiveBehaviorPrototype(newModel_PrimeChecker_fbPrintIsPrimeExecution);
    
    

    std::vector<fUML::ParameterValue *> * pList = new std::vector<fUML::ParameterValue *>();
    
    //INput parameter ActInputNode 
    fUML::ParameterValue * ActInputNodeP = fumlFac->createParameterValue();
    ActInputNodeP->setParameter(NewModel::NewModelPackage::eInstance()->get_NewModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode());
    fUML::Reference * ActInputNodeValue = fUML::FUMLFactory::eInstance()->createReference();
    NewModel::PrimeCheckerExecution * ActInputNodeUmlLinker = new NewModel::PrimeCheckerExecution();
	ActInputNodeUmlLinker = new PrimeCheckerExecution(NewModel::NewModelFactory::eInstance()->createPrimeChecker());
	ActInputNodeUmlLinker->setLocus(locus);
	ActInputNodeValue->setReferent(ActInputNodeUmlLinker);
    ActInputNodeP->getValues()->push_back(ActInputNodeValue);
    pList->push_back(ActInputNodeP);

    std::vector<fUML::ParameterValue *> * resultPList = locus->getExecutor()->execute(NewModel::NewModelPackage::eInstance()->get_NewModel_CheckIfPrime(),nullptr,pList);

	if(nullptr == resultPList)
	{
        std::cerr << "resultPList is null" << std::endl;
        return EXIT_FAILURE;
	}
    if(resultPList->empty())
    {
        DEBUG_MESSAGE(std::cout << "The activity did not return any parameter." << std::endl;)
    }
    else{
        DEBUG_MESSAGE(std::cout << resultPList->size() << std::endl;)
        for(unsigned int parIndex=0; parIndex< resultPList->size(); parIndex++){
            DEBUG_MESSAGE(std::cout << "Parameter " << parIndex <<" name: "<<resultPList->at(parIndex)->getParameter()->getName() << std::endl;)
            if(resultPList->at(parIndex)->getValues()->empty())
            {
                DEBUG_MESSAGE(std::cout<<"\tThe parameter is empty.";)
            }
            else
            {
                DEBUG_MESSAGE(std::cout << "\tsize: " << resultPList->at(parIndex)->getValues()->size() << std::endl;)
                DEBUG_MESSAGE(std::cout << "\tvalue of the first element: " << resultPList->at(parIndex)->getValues()->front()->toString() << std::endl;)
            }
        }
    }
    return EXIT_SUCCESS;
}
