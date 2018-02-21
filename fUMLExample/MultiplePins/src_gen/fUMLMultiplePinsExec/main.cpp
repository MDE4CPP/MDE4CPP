
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
#include "fuml/ParameterValue.hpp"
#include "uml/Activity.hpp"
#include "uml/FunctionBehavior.hpp"
#include "uml/Interface.hpp"
#include "uml/Operation.hpp"
#include "uml/Parameter.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/UmlFactory.hpp"


//include Model package
#include "fUMLMultiplePins/FUMLMultiplePinsPackage.hpp"

#include "fUMLMultiplePins/FUMLMultiplePinsPackage.hpp" 
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"

//OpaqueBehaviourExecutions
#include "fUMLMultiplePinsExec/FbDo1Execution.hpp"
#include "fUMLMultiplePinsExec/FbDoAllExecution.hpp"
#include "fUMLMultiplePinsExec/IstEndeExecution.hpp"


//OpaqueBehaviourExecutions



#include "fuml/Reference.hpp"
#include "fUMLMultiplePins/fUMLMultiplePinsFactory.hpp"
#include "fUMLMultiplePins/fUMLMultiplePinsPackage.hpp"

#include "fUMLMultiplePins/TestClass.hpp"
#include "fUMLMultiplePinsExec/TestClassExecution.hpp"


#include "fUMLMultiplePinsExec/TestClassExecution.hpp"
#include "fUMLMultiplePins/TestClass.hpp"
#include "fUMLMultiplePins/fUMLMultiplePinsFactory.hpp"

using namespace fUMLMultiplePins;

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
	std::shared_ptr<fUMLMultiplePins::TestClass> startParam(fUMLMultiplePins::FUMLMultiplePinsFactory::eInstance()->createTestClass());
	
	
	std::shared_ptr<TestClass> element = fUMLMultiplePins::FUMLMultiplePinsFactory::eInstance()->createTestClass();
	std::shared_ptr<fUML::OpaqueBehaviorExecution> fUMLMultiplePins_TestClass_fbDo1Execution(new fUMLMultiplePins::FbDo1Execution());
	fUMLMultiplePins_TestClass_fbDo1Execution->getTypes()->push_back(fUMLMultiplePins::FUMLMultiplePinsPackage::eInstance()->get_fUMLMultiplePins_TestClass_fbDo1());
	fUMLMultiplePins_TestClass_fbDo1Execution->setLocus(factory->getLocus().lock());
	factory->addPrimitiveBehaviorPrototype(fUMLMultiplePins_TestClass_fbDo1Execution);
	
	std::shared_ptr<fUML::OpaqueBehaviorExecution> fUMLMultiplePins_TestClass_fbDoAllExecution(new fUMLMultiplePins::FbDoAllExecution());
	fUMLMultiplePins_TestClass_fbDoAllExecution->getTypes()->push_back(fUMLMultiplePins::FUMLMultiplePinsPackage::eInstance()->get_fUMLMultiplePins_TestClass_fbDoAll());
	fUMLMultiplePins_TestClass_fbDoAllExecution->setLocus(factory->getLocus().lock());
	factory->addPrimitiveBehaviorPrototype(fUMLMultiplePins_TestClass_fbDoAllExecution);
	
	std::shared_ptr<fUML::OpaqueBehaviorExecution> fUMLMultiplePins_TestClass_istEndeExecution(new fUMLMultiplePins::IstEndeExecution());
	fUMLMultiplePins_TestClass_istEndeExecution->getTypes()->push_back(fUMLMultiplePins::FUMLMultiplePinsPackage::eInstance()->get_fUMLMultiplePins_TestClass_istEnde());
	fUMLMultiplePins_TestClass_istEndeExecution->setLocus(factory->getLocus().lock());
	factory->addPrimitiveBehaviorPrototype(fUMLMultiplePins_TestClass_istEndeExecution);
	
	
	
	
	
	std::shared_ptr<Bag<fUML::ParameterValue> > pList(new Bag<fUML::ParameterValue>());
	//INput parameter startParam 
	std::shared_ptr<fUML::ParameterValue> startParamP(fumlFac->createParameterValue());
	startParamP->setParameter(fUMLMultiplePins::FUMLMultiplePinsPackage::eInstance()->get_fUMLMultiplePins_TestClass_TestMultiplePins_fUMLMultiplePins_TestClass_TestMultiplePins_startParam());
	std::shared_ptr<fUML::Reference> startParamValue(fUML::FUMLFactory::eInstance()->createReference());
	std::shared_ptr<TestClassExecution> startParamUmlLinker(new TestClassExecution(startParam));
	startParamUmlLinker->setLocus(locus);
	startParamValue->setReferent(startParamUmlLinker);
	startParamP->getValues()->push_back(startParamValue);
	pList->push_back(startParamP);
	
	std::shared_ptr<TestClassExecution> object(new TestClassExecution());
	object->setUmlValue(std::dynamic_pointer_cast<fUMLMultiplePins::TestClass>(element));
	object->setLocus(locus);
	std::shared_ptr<Bag<fUML::ParameterValue>> resultPList = locus->getExecutor()->execute(fUMLMultiplePins::FUMLMultiplePinsPackage::eInstance()->get_fUMLMultiplePins_TestClass_TestMultiplePins(), object, pList);
	
	
	
	   

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
