#include "fUMLMultiplePinsExec/FbDoAllExecution.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <cassert>
#include <iostream>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp" 
#include "fUML/FUMLFactory.hpp"
#include "fUML/ParameterValue.hpp"
#include "uml/Behavior.hpp"


#include "fUMLMultiplePins/TestClass.hpp"
#include "fUMLMultiplePinsExec/TestClassExecution.hpp"

#include "fUML/IntegerValue.hpp"

using namespace fUMLMultiplePins;

FbDoAllExecution::FbDoAllExecution()
{
}

FbDoAllExecution::~FbDoAllExecution()
{
}

FbDoAllExecution::FbDoAllExecution(const FbDoAllExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
}

std::shared_ptr<ecore::EObject> FbDoAllExecution::copy() const
{
	std::shared_ptr<ecore::EObject> element(new FbDoAllExecution(*this));
	return element;
}

void FbDoAllExecution::doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)

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

    std::shared_ptr<fUML::IntegerValue> param_0Value = std::dynamic_pointer_cast<fUML::IntegerValue>(inputParameters->at(0)->getValues()->front());

	param_0 = param_0Value->getValue();
    std::shared_ptr<fUML::IntegerValue> param_1Value = std::dynamic_pointer_cast<fUML::IntegerValue>(inputParameters->at(1)->getValues()->front());

	param_1 = param_1Value->getValue();
    std::shared_ptr<fUML::IntegerValue> param_2Value = std::dynamic_pointer_cast<fUML::IntegerValue>(inputParameters->at(2)->getValues()->front());

	param_2 = param_2Value->getValue();
    std::shared_ptr<fUML::IntegerValue> param_3Value = std::dynamic_pointer_cast<fUML::IntegerValue>(inputParameters->at(3)->getValues()->front());

	param_3 = param_3Value->getValue();
    std::shared_ptr<fUML::IntegerValue> param_4Value = std::dynamic_pointer_cast<fUML::IntegerValue>(inputParameters->at(4)->getValues()->front());

	param_4 = param_4Value->getValue();
    std::shared_ptr<fUML::IntegerValue> param_5Value = std::dynamic_pointer_cast<fUML::IntegerValue>(inputParameters->at(5)->getValues()->front());

	param_5 = param_5Value->getValue();
    std::shared_ptr<fUML::IntegerValue> param_6Value = std::dynamic_pointer_cast<fUML::IntegerValue>(inputParameters->at(6)->getValues()->front());

	param_6 = param_6Value->getValue();
    std::shared_ptr<fUML::IntegerValue> param_7Value = std::dynamic_pointer_cast<fUML::IntegerValue>(inputParameters->at(7)->getValues()->front());

	param_7 = param_7Value->getValue();
    std::shared_ptr<fUML::IntegerValue> param_8Value = std::dynamic_pointer_cast<fUML::IntegerValue>(inputParameters->at(8)->getValues()->front());

	param_8 = param_8Value->getValue();
    std::shared_ptr<fUML::IntegerValue> param_9Value = std::dynamic_pointer_cast<fUML::IntegerValue>(inputParameters->at(9)->getValues()->front());

	param_9 = param_9Value->getValue();

	//Call Operation action target
	std::shared_ptr<fUMLMultiplePins::TestClass> target = std::dynamic_pointer_cast<TestClassExecution>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //Body of the Opaquebehavior
    //Start ---------------------------
	
	//Calling the associated operation.
	target->doAll(param_0,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    //End -----------------------------

	//set return / out parameters

	//set InOut parameters
	//Simple type
 	param_0Value->setValue(param_0);
    //outputParameters->push_back(inputParameters->at(0));
	//Simple type
 	param_1Value->setValue(param_1);
    //outputParameters->push_back(inputParameters->at(1));
	//Simple type
 	param_2Value->setValue(param_2);
    //outputParameters->push_back(inputParameters->at(2));
	//Simple type
 	param_3Value->setValue(param_3);
    //outputParameters->push_back(inputParameters->at(3));
	//Simple type
 	param_4Value->setValue(param_4);
    //outputParameters->push_back(inputParameters->at(4));
	//Simple type
 	param_5Value->setValue(param_5);
    //outputParameters->push_back(inputParameters->at(5));
	//Simple type
 	param_6Value->setValue(param_6);
    //outputParameters->push_back(inputParameters->at(6));
	//Simple type
 	param_7Value->setValue(param_7);
    //outputParameters->push_back(inputParameters->at(7));
	//Simple type
 	param_8Value->setValue(param_8);
    //outputParameters->push_back(inputParameters->at(8));
	//Simple type
 	param_9Value->setValue(param_9);
    //outputParameters->push_back(inputParameters->at(9));
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB fbDoAll ends its execution ^^^^^" << std::endl;)
}
