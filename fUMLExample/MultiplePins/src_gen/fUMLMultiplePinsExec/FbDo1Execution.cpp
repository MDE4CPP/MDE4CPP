#include "fUMLMultiplePinsExec/FbDo1Execution.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <cassert>
#include <iostream>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp" 
#include "fUML/ParameterValue.hpp"


#include "fUMLMultiplePins/TestClass.hpp"
#include "fUMLMultiplePinsExec/TestClassExecution.hpp"

#include "fUML/Reference.hpp"
#include "fUMLMultiplePins/TestClass.hpp"
#include "fUMLMultiplePinsExec/TestClassExecution.hpp"
#include "fUML/IntegerValue.hpp"

using namespace fUMLMultiplePins;

FbDo1Execution::FbDo1Execution()
{
}

FbDo1Execution::~FbDo1Execution()
{
}

FbDo1Execution::FbDo1Execution(const FbDo1Execution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
}

std::shared_ptr<ecore::EObject> FbDo1Execution::copy() const
{
	std::shared_ptr<ecore::EObject> element(new FbDo1Execution(*this));
	return element;
}

void FbDo1Execution::doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)

   	std::shared_ptr<fUMLMultiplePins::TestClass> input_1;
   	int param_0;
   	int param_1;
   	int param_2;
   	int param_3;
   	int param_4;
   	int param_5;
   	int param_6;
   	int param_7;
   	int param_8;
   	int param_9;

    std::shared_ptr<fUML::Reference> input_1Value = std::dynamic_pointer_cast<fUML::Reference>(inputParameters->at(0)->getValues()->front());

	input_1 = std::dynamic_pointer_cast<TestClassExecution>(input_1Value->getReferent())->getUmlValue();
	assert(input_1 != nullptr);

	//Call Operation action target
	std::shared_ptr<fUMLMultiplePins::TestClass> target = std::dynamic_pointer_cast<TestClassExecution>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------
	
	//Calling the associated operation.
	target->do1(input_1,param_0,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    //End -----------------------------

	//set return / out parameters
    std::shared_ptr<fUML::IntegerValue> param_0Value(fUML::FUMLFactory::eInstance()->createIntegerValue());
 	param_0Value->setValue(param_0);
    outputParameters->at(0)->getValues()->push_back(param_0Value);
    std::shared_ptr<fUML::IntegerValue> param_1Value(fUML::FUMLFactory::eInstance()->createIntegerValue());
 	param_1Value->setValue(param_1);
    outputParameters->at(1)->getValues()->push_back(param_1Value);
    std::shared_ptr<fUML::IntegerValue> param_2Value(fUML::FUMLFactory::eInstance()->createIntegerValue());
 	param_2Value->setValue(param_2);
    outputParameters->at(2)->getValues()->push_back(param_2Value);
    std::shared_ptr<fUML::IntegerValue> param_3Value(fUML::FUMLFactory::eInstance()->createIntegerValue());
 	param_3Value->setValue(param_3);
    outputParameters->at(3)->getValues()->push_back(param_3Value);
    std::shared_ptr<fUML::IntegerValue> param_4Value(fUML::FUMLFactory::eInstance()->createIntegerValue());
 	param_4Value->setValue(param_4);
    outputParameters->at(4)->getValues()->push_back(param_4Value);
    std::shared_ptr<fUML::IntegerValue> param_5Value(fUML::FUMLFactory::eInstance()->createIntegerValue());
 	param_5Value->setValue(param_5);
    outputParameters->at(5)->getValues()->push_back(param_5Value);
    std::shared_ptr<fUML::IntegerValue> param_6Value(fUML::FUMLFactory::eInstance()->createIntegerValue());
 	param_6Value->setValue(param_6);
    outputParameters->at(6)->getValues()->push_back(param_6Value);
    std::shared_ptr<fUML::IntegerValue> param_7Value(fUML::FUMLFactory::eInstance()->createIntegerValue());
 	param_7Value->setValue(param_7);
    outputParameters->at(7)->getValues()->push_back(param_7Value);
    std::shared_ptr<fUML::IntegerValue> param_8Value(fUML::FUMLFactory::eInstance()->createIntegerValue());
 	param_8Value->setValue(param_8);
    outputParameters->at(8)->getValues()->push_back(param_8Value);
    std::shared_ptr<fUML::IntegerValue> param_9Value(fUML::FUMLFactory::eInstance()->createIntegerValue());
 	param_9Value->setValue(param_9);
    outputParameters->at(9)->getValues()->push_back(param_9Value);

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbDo1 ends its execution ^^^^^" << std::endl;)
}
