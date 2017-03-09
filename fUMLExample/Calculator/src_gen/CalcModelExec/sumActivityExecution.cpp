#include "sumActivityExecution.hpp"

#include <iostream>
#include <cassert>
#include <vector>

#include "fUML/ParameterValue.hpp"
#include "fUML/ActivityParameterNodeActivation.hpp"
#include "fUML/ActivityNodeActivationGroup.hpp"
#include "fUML/Token.hpp"
#include "fUML/ObjectToken.hpp"
#include "fUML/Value.hpp"

#include "uml/Activity.hpp"
#include "uml/Classifier.hpp"

#include "DispatchStrategy.hpp"
#include "Executor.hpp"
#include "ExecutionFactoryL3.hpp"
#include "FirstChoiceStrategy.hpp"
#include "FunctionBehavior.hpp"
#include "FUMLFactory.hpp"
#include "Locus.hpp"

//include Model package
#include "CalcModelPackage.hpp"

invalid

using namespace CalcModel;

sumActivityExecution::sumActivityExecution()
{
}

sumActivityExecution::~sumActivityExecution()
{
}

sumActivityExecution::sumActivityExecution(const sumActivityExecution &obj):
	ActivityExecutionImpl(obj)
{
}

void sumActivityExecution::terminate()
{
    this->getActivationGroup()->terminateAll();
}

ecore::EObject* sumActivityExecution::copy() const
{
    return new sumActivityExecution(*this);
}

void sumActivityExecution::execute()
{
	// Execute the activity for this execution by creating an activity node activation group and activating all the activity nodes in the activity.
	// When this is complete, copy the values on the tokens offered by output parameter nodes to the corresponding output parameters.
	std::shared_ptr<uml::Activity> activity = std::dynamic_pointer_cast<uml::Activity*>(this->getTypes()->front());
	assert(activity != nullptr);

	DEBUG_MESSAGE(std::cout << "[execute] Activity " << activity->getName() << "..." << std::endl;)
	
	if(this->getContext() != nullptr){
		DEBUG_MESSAGE(std::cout << "[execute] context = " << this->getContext()->objectId() << std::endl;)
	}

	this->setActivationGroup(fUML::FUMLFactory::eInstance()->createActivityNodeActivationGroup());
	struct null_deleter{void operator()(void const *) const { } };
	this->getActivationGroup()->setActivityExecution(std::shared_ptr<sumActivityExecution>(this, null_deleter()));
	this->getActivationGroup()->activate(activity->getNode(), activity->getEdge());

	DEBUG_MESSAGE(std::cout << "[execute] Getting output parameter node activations..." << std::endl;)

	std::shared_ptr<std::vector<std::shared_ptr<fUML::ActivityParameterNodeActivation>>> outputActivations =
	this->getActivationGroup()->getOutputParameterNodeActivations();

    assert(outputActivations != nullptr);

	DEBUG_MESSAGE(std::cout << "[execute] There are " << outputActivations->size() << " output parameter node activations." << std::endl;)
	
    for (unsigned int i = 0; i < outputActivations->size(); i++) 
	{
 		std::shared_ptr<fUML::ActivityParameterNodeActivation> outputActivation = outputActivations->at(i);
 		std::shared_ptr<fUML::ParameterValue> parameterValue(fUML::FUMLFactory::eInstance()->createParameterValue());
 		parameterValue->setParameter((dynamic_cast<uml::ActivityParameterNode*>(outputActivation->getNode()))->getParameter());
 		std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> tokens = outputActivation->getTokens();
 		for (unsigned int j = 0; j < tokens->size(); j++) 
		{
            std::shared_ptr<fUML::Token> token = tokens->at(j);
            std::shared_ptr<fUML::Value> value = std::dynamic_pointer_cast<fUML::ObjectToken>(token)->getValue();
 			if (nullptr != value) 
			{
                parameterValue->getValues()->push_back(value);
 			}
 		}
	 	this->setParameterValue(parameterValue);
	}

	DEBUG_MESSAGE(std::cout << "[execute] Activity " << activity->getName() << " completed." << std::endl;)
}

int sumActivityExecution::execute(int op1,int op2)
{
	DEBUG_MESSAGE(std::cout << "Activity sumActivity is executing" << std::endl;)
    fUML::FUMLFactory * fumlFac = fUML::FUMLFactory::eInstance();
    std::shared_ptr<fUML::Locus> locus(fumlFac->createLocus());

    std::shared_ptr<fUML::Executor> executor(fumlFac->createExecutor());
    executor->setLocus(locus);

    std::shared_ptr<fUML::ExecutionFactoryL3> factory(fumlFac->createExecutionFactoryL3());
    factory->setLocus(locus);

    locus->setFactory(factory);
    locus->setExecutor(executor);

    locus->getFactory()->assignStrategy(fumlFac->createFirstChoiceStrategy());
	locus->getFactory()->assignStrategy(fumlFac->createDispatchStrategy());

    invalid


    std::shared_ptr<std::vector<fUML::ParameterValue>>> pList(new std::vector<std::shared_ptr<fUML::ParameterValue>>>());

    
    //INput parameter op1 
	
    std::shared_ptr<fUML::ParameterValue> op1P(fumlFac->createParameterValue());
    op1P->setParameter(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_Calculator_sumActivity_CalcModel_Calculator_sumActivity_op1());
    
	std::shared_ptr<fUML::IntegerValue> op1Value(fUML::FUMLFactory::eInstance()->createIntegerValue());
    op1Value->setValue(1);
    op1P->getValues()->push_back(op1Value);
    pList->push_back(op1P);
    
    //INput parameter op2 
	
    std::shared_ptr<fUML::ParameterValue> op2P(fumlFac->createParameterValue());
    op2P->setParameter(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_Calculator_sumActivity_CalcModel_Calculator_sumActivity_op2());
    
	std::shared_ptr<fUML::IntegerValue> op2Value(fUML::FUMLFactory::eInstance()->createIntegerValue());
    op2Value->setValue(1);
    op2P->getValues()->push_back(op2Value);
    pList->push_back(op2P);

    std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>> resultPList = locus->getExecutor()->execute(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_Calculator_sumActivity(),nullptr,pList);

	// TODO set result parameter (pointers not to set?)
	//The activity has a return parameter
	assert(resultPList->front());
 	std::shared_ptr<fUML::IntegerValue> ret = std::dynamic_pointer_cast<fUML::IntegerValue>(resultPList->front()->getValues()->front());
    assert(ret != nullptr);
    return ret->getValue();
}

