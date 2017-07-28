#include <iostream>
#include <memory>
#include <vector>
#include <omp.h>

#include "FUMLFactory.hpp"
#include "Locus.hpp"
#include "Executor.hpp"
#include "Parameter.hpp"
#include "ExecutionFactoryL3.hpp"
#include "FirstChoiceStrategy.hpp"
#include "DispatchStrategy.hpp"
#include "FunctionBehavior.hpp"
#include "Activity.hpp"
#include "SubsetUnion.hpp"
#include "UmlFactory.hpp"
#include "Operation.hpp"
#include "Interface.hpp"
#include "PrimitiveType.hpp"

#include "ParameterValue.hpp"

//include Model package
#include "CalcModelPackage.hpp"

#include "CalcModelPackage.hpp" 
#include "PrimitiveTypesPackage.hpp"

//OpaqueBehaviourExecutions
#include "FbIsNotFinishedExecution.hpp"
#include "FbPrintNotPrimeExecution.hpp"
#include "FbPrintIsPrimeExecution.hpp"
#include "FbNextExecution.hpp"
#include "FbDividesExecution.hpp"
#include "FbIsOddExecution.hpp"


//OpaqueBehaviourExecutions






#include "Reference.hpp"
#include "CalcModelFactory.hpp"

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"



using namespace CalcModel;

int main()
{	

	//OMP parallelization.
	omp_set_num_threads(omp_get_num_procs());

	DEBUG_MESSAGE(std::cout<<"Main function is executing"<<std::endl;)
	std::shared_ptr<fUML::FUMLFactory> fumlFac(fUML::FUMLFactory::eInstance());
	std::shared_ptr<fUML::Locus> locus(fumlFac->createLocus());
	
	std::shared_ptr<fUML::Executor> executor(fumlFac->createExecutor());
	executor->setLocus(locus);
	
	std::shared_ptr<fUML::ExecutionFactoryL3> factory(fumlFac->createExecutionFactoryL3());
	factory->setLocus(locus);
	
	locus->setFactory(factory);
	locus->setExecutor(executor);
	
	locus->getFactory()->assignStrategy(std::shared_ptr<fUML::FirstChoiceStrategy>(fumlFac->createFirstChoiceStrategy()));
	locus->getFactory()->assignStrategy(std::shared_ptr<fUML::DispatchStrategy>(fumlFac->createDispatchStrategy()));

    //Executor will execute the first Activity
	std::shared_ptr<CalcModel::PrimeChecker> actInputNode(CalcModel::CalcModelFactory::eInstance()->createPrimeChecker());
	
	
	std::shared_ptr<fUML::OpaqueBehaviorExecution> calcModel_PrimeChecker_fbIsOddExecution(new CalcModel::FbIsOddExecution());
	calcModel_PrimeChecker_fbIsOddExecution->getTypes()->push_back(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbIsOdd());
	calcModel_PrimeChecker_fbIsOddExecution->setLocus(factory->getLocus());
	factory->addPrimitiveBehaviorPrototype(calcModel_PrimeChecker_fbIsOddExecution);
	
	std::shared_ptr<fUML::OpaqueBehaviorExecution> calcModel_PrimeChecker_fbPrintIsPrimeExecution(new CalcModel::FbPrintIsPrimeExecution());
	calcModel_PrimeChecker_fbPrintIsPrimeExecution->getTypes()->push_back(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbPrintIsPrime());
	calcModel_PrimeChecker_fbPrintIsPrimeExecution->setLocus(factory->getLocus());
	factory->addPrimitiveBehaviorPrototype(calcModel_PrimeChecker_fbPrintIsPrimeExecution);
	
	std::shared_ptr<fUML::OpaqueBehaviorExecution> calcModel_PrimeChecker_fbNextExecution(new CalcModel::FbNextExecution());
	calcModel_PrimeChecker_fbNextExecution->getTypes()->push_back(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbNext());
	calcModel_PrimeChecker_fbNextExecution->setLocus(factory->getLocus());
	factory->addPrimitiveBehaviorPrototype(calcModel_PrimeChecker_fbNextExecution);
	
	std::shared_ptr<fUML::OpaqueBehaviorExecution> calcModel_PrimeChecker_fbPrintNotPrimeExecution(new CalcModel::FbPrintNotPrimeExecution());
	calcModel_PrimeChecker_fbPrintNotPrimeExecution->getTypes()->push_back(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbPrintNotPrime());
	calcModel_PrimeChecker_fbPrintNotPrimeExecution->setLocus(factory->getLocus());
	factory->addPrimitiveBehaviorPrototype(calcModel_PrimeChecker_fbPrintNotPrimeExecution);
	
	std::shared_ptr<fUML::OpaqueBehaviorExecution> calcModel_PrimeChecker_fbIsNotFinishedExecution(new CalcModel::FbIsNotFinishedExecution());
	calcModel_PrimeChecker_fbIsNotFinishedExecution->getTypes()->push_back(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbIsNotFinished());
	calcModel_PrimeChecker_fbIsNotFinishedExecution->setLocus(factory->getLocus());
	factory->addPrimitiveBehaviorPrototype(calcModel_PrimeChecker_fbIsNotFinishedExecution);
	
	std::shared_ptr<fUML::OpaqueBehaviorExecution> calcModel_PrimeChecker_fbDividesExecution(new CalcModel::FbDividesExecution());
	calcModel_PrimeChecker_fbDividesExecution->getTypes()->push_back(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbDivides());
	calcModel_PrimeChecker_fbDividesExecution->setLocus(factory->getLocus());
	factory->addPrimitiveBehaviorPrototype(calcModel_PrimeChecker_fbDividesExecution);
	
	
	
	
	
	std::shared_ptr<Bag<fUML::ParameterValue> > pList(new Bag<fUML::ParameterValue>());
	//INput parameter ActInputNode 
	std::shared_ptr<fUML::ParameterValue> ActInputNodeP(fumlFac->createParameterValue());
	ActInputNodeP->setParameter(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode());
	std::shared_ptr<fUML::Reference> ActInputNodeValue(fUML::FUMLFactory::eInstance()->createReference());
	std::shared_ptr<PrimeCheckerExecution> ActInputNodeUmlLinker(new PrimeCheckerExecution(actInputNode));
	ActInputNodeUmlLinker->setLocus(locus);
	ActInputNodeValue->setReferent(ActInputNodeUmlLinker);
	ActInputNodeP->getValues()->push_back(ActInputNodeValue);
	pList->push_back(ActInputNodeP);
	
	std::shared_ptr<Bag<fUML::ParameterValue> > resultPList = locus->getExecutor()->execute(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_CheckIfPrime(), nullptr, pList);
	
	
	
	   

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
        for(unsigned int parIndex=0; parIndex< resultPList->size(); parIndex++)
{
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
