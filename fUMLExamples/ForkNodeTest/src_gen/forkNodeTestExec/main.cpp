
#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>
#include <memory>
#include <vector>

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
#include "forkNodeTest/ForkNodeTestPackage.hpp"

#include "forkNodeTest/ForkNodeTestPackage.hpp" 

//OpaqueBehaviourExecutions
#include "forkNodeTestExec/FbNullExecution.hpp"






#include "forkNodeTestExec/ForkClassObject.hpp"
#include "forkNodeTest/ForkClass.hpp"
#include "forkNodeTest/ForkNodeTestFactory.hpp"

using namespace forkNodeTest;

int main()
{	
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
	
	std::shared_ptr<ForkClass> element = forkNodeTest::ForkNodeTestFactory::eInstance()->createForkClass();
	std::shared_ptr<forkNodeTest::FbNullExecution> forkNodeTest_forkClass_fbNullExecution(new forkNodeTest::FbNullExecution());
	forkNodeTest_forkClass_fbNullExecution->setThisExecutionPtr(forkNodeTest_forkClass_fbNullExecution);
	forkNodeTest_forkClass_fbNullExecution->getTypes()->push_back(forkNodeTest::ForkNodeTestPackage::eInstance()->get_forkNodeTest_forkClass_fbNull());
	forkNodeTest_forkClass_fbNullExecution->setLocus(factory->getLocus().lock());
	factory->addPrimitiveBehaviorPrototype(forkNodeTest_forkClass_fbNullExecution);
	
	
	
	
	std::shared_ptr<Bag<fUML::ParameterValue> > pList(new Bag<fUML::ParameterValue>());
	std::shared_ptr<ForkClassObject> object(new ForkClassObject());
	object->setThisForkClassObjectPtr(object);
	object->setUmlValue(std::dynamic_pointer_cast<forkNodeTest::ForkClass>(element));
	object->setLocus(locus);
	std::shared_ptr<Bag<fUML::ParameterValue>> resultPList = locus->getExecutor()->execute(forkNodeTest::ForkNodeTestPackage::eInstance()->get_forkNodeTest_forkClass_forkNodeTest(), object, pList);
	
	
	   

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
