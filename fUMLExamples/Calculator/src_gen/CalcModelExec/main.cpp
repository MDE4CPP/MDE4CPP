
#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>
#include <memory>
#include <vector>
#include <omp.h>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "fUML/Executor.hpp"
#include "fUML/DispatchStrategy.hpp"
#include "fUML/ExecutionFactoryL3.hpp"
#include "fUML/FirstChoiceStrategy.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/Locus.hpp"
#include "fUML/ParameterValue.hpp"
#include "uml/Activity.hpp"
#include "uml/FunctionBehavior.hpp"
#include "uml/Interface.hpp"
#include "uml/Operation.hpp"
#include "uml/Parameter.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/UmlFactory.hpp"


//include Model package
#include "CalcModel/CalcModelPackage.hpp"

#include "CalcModel/CalcModelPackage.hpp" 
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"

//OpaqueBehaviourExecutions
#include "CalcModelExec/FbDividesExecution.hpp"
#include "CalcModelExec/FbIsNotFinishedExecution.hpp"
#include "CalcModelExec/FbIsOddExecution.hpp"
#include "CalcModelExec/FbNextExecution.hpp"
#include "CalcModelExec/FbPrintIsPrimeExecution.hpp"
#include "CalcModelExec/FbPrintNotPrimeExecution.hpp"


//OpaqueBehaviourExecutions





#include "fUML/Reference.hpp"
#include "CalcModel/CalcModelFactory.hpp"
#include "CalcModel/CalcModelPackage.hpp"

#include "CalcModel/PrimeChecker.hpp"
#include "CalcModelExec/PrimeCheckerObject.hpp"


#include "CalcModelExec/PrimeCheckerObject.hpp"
#include "CalcModel/PrimeChecker.hpp"
#include "CalcModel/CalcModelFactory.hpp"

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
	
	std::shared_ptr<fUML::ExecutionFactoryL3> factory(fumlFac->createExecutionFactoryL3_in_Locus(locus));
	//factory->setLocus(locus);
	//locus->setFactory(factory);
	
	locus->setExecutor(executor);
	
	locus->getFactory()->assignStrategy(std::shared_ptr<fUML::FirstChoiceStrategy>(fumlFac->createFirstChoiceStrategy()));
	locus->getFactory()->assignStrategy(std::shared_ptr<fUML::DispatchStrategy>(fumlFac->createDispatchStrategy()));

    //Executor will execute the first Activity
	std::shared_ptr<CalcModel::PrimeChecker> actInputNode(CalcModel::CalcModelFactory::eInstance()->createPrimeChecker());
	
	
	std::shared_ptr<PrimeChecker> element = CalcModel::CalcModelFactory::eInstance()->createPrimeChecker();
	std::shared_ptr<CalcModel::FbDividesExecution> calcModel_PrimeChecker_fbDividesExecution(new CalcModel::FbDividesExecution());
	calcModel_PrimeChecker_fbDividesExecution->setThisExecutionPtr(calcModel_PrimeChecker_fbDividesExecution);
	calcModel_PrimeChecker_fbDividesExecution->getTypes()->push_back(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbDivides());
	calcModel_PrimeChecker_fbDividesExecution->setLocus(factory->getLocus().lock());
	factory->addPrimitiveBehaviorPrototype(calcModel_PrimeChecker_fbDividesExecution);
	
	std::shared_ptr<CalcModel::FbIsNotFinishedExecution> calcModel_PrimeChecker_fbIsNotFinishedExecution(new CalcModel::FbIsNotFinishedExecution());
	calcModel_PrimeChecker_fbIsNotFinishedExecution->setThisExecutionPtr(calcModel_PrimeChecker_fbIsNotFinishedExecution);
	calcModel_PrimeChecker_fbIsNotFinishedExecution->getTypes()->push_back(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbIsNotFinished());
	calcModel_PrimeChecker_fbIsNotFinishedExecution->setLocus(factory->getLocus().lock());
	factory->addPrimitiveBehaviorPrototype(calcModel_PrimeChecker_fbIsNotFinishedExecution);
	
	std::shared_ptr<CalcModel::FbIsOddExecution> calcModel_PrimeChecker_fbIsOddExecution(new CalcModel::FbIsOddExecution());
	calcModel_PrimeChecker_fbIsOddExecution->setThisExecutionPtr(calcModel_PrimeChecker_fbIsOddExecution);
	calcModel_PrimeChecker_fbIsOddExecution->getTypes()->push_back(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbIsOdd());
	calcModel_PrimeChecker_fbIsOddExecution->setLocus(factory->getLocus().lock());
	factory->addPrimitiveBehaviorPrototype(calcModel_PrimeChecker_fbIsOddExecution);
	
	std::shared_ptr<CalcModel::FbNextExecution> calcModel_PrimeChecker_fbNextExecution(new CalcModel::FbNextExecution());
	calcModel_PrimeChecker_fbNextExecution->setThisExecutionPtr(calcModel_PrimeChecker_fbNextExecution);
	calcModel_PrimeChecker_fbNextExecution->getTypes()->push_back(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbNext());
	calcModel_PrimeChecker_fbNextExecution->setLocus(factory->getLocus().lock());
	factory->addPrimitiveBehaviorPrototype(calcModel_PrimeChecker_fbNextExecution);
	
	std::shared_ptr<CalcModel::FbPrintIsPrimeExecution> calcModel_PrimeChecker_fbPrintIsPrimeExecution(new CalcModel::FbPrintIsPrimeExecution());
	calcModel_PrimeChecker_fbPrintIsPrimeExecution->setThisExecutionPtr(calcModel_PrimeChecker_fbPrintIsPrimeExecution);
	calcModel_PrimeChecker_fbPrintIsPrimeExecution->getTypes()->push_back(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbPrintIsPrime());
	calcModel_PrimeChecker_fbPrintIsPrimeExecution->setLocus(factory->getLocus().lock());
	factory->addPrimitiveBehaviorPrototype(calcModel_PrimeChecker_fbPrintIsPrimeExecution);
	
	std::shared_ptr<CalcModel::FbPrintNotPrimeExecution> calcModel_PrimeChecker_fbPrintNotPrimeExecution(new CalcModel::FbPrintNotPrimeExecution());
	calcModel_PrimeChecker_fbPrintNotPrimeExecution->setThisExecutionPtr(calcModel_PrimeChecker_fbPrintNotPrimeExecution);
	calcModel_PrimeChecker_fbPrintNotPrimeExecution->getTypes()->push_back(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbPrintNotPrime());
	calcModel_PrimeChecker_fbPrintNotPrimeExecution->setLocus(factory->getLocus().lock());
	factory->addPrimitiveBehaviorPrototype(calcModel_PrimeChecker_fbPrintNotPrimeExecution);
	
	
	
	
	
	std::shared_ptr<Bag<fUML::ParameterValue> > pList(new Bag<fUML::ParameterValue>());
	//INput parameter actInputNode 
	std::shared_ptr<fUML::ParameterValue> actInputNodeP(fumlFac->createParameterValue());
	actInputNodeP->setParameter(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_CheckIfPrime_CalcModel_PrimeChecker_CheckIfPrime_actInputNode());
	std::shared_ptr<fUML::Reference> actInputNodeValue(fUML::FUMLFactory::eInstance()->createReference());
	std::shared_ptr<PrimeCheckerObject> actInputNodeUmlLinker(new PrimeCheckerObject(actInputNode));
	actInputNodeUmlLinker->setThisPrimeCheckerObjectPtr(actInputNodeUmlLinker);
	actInputNodeUmlLinker->setLocus(locus);
	actInputNodeValue->setReferent(actInputNodeUmlLinker);
	actInputNodeP->getValues()->push_back(actInputNodeValue);
	pList->push_back(actInputNodeP);
	
	std::shared_ptr<PrimeCheckerObject> object(new PrimeCheckerObject());
	object->setThisPrimeCheckerObjectPtr(object);
	object->setUmlValue(std::dynamic_pointer_cast<CalcModel::PrimeChecker>(element));
	object->setLocus(locus);
	std::shared_ptr<Bag<fUML::ParameterValue>> resultPList = locus->getExecutor()->execute(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_CheckIfPrime(), object, pList);
	
	
	
	   

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
