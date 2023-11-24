#include "FoundationalModelLibraryExecutionFactoryImpl.hpp"
#include <iostream>

#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

//Model includes
#include "FoundationalModelLibrary/BasicInputOutput/BasicInputOutputPackage.hpp"

//fUML includes
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
//ActivityNodeActivation includes
#include "fUML/Semantics/Activities/ActivityParameterNodeActivation.hpp"
#include "fUML/Semantics/Actions/CreateObjectActionActivation.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/CallOperationActionActivation.hpp"

//ActivityEdgeInstance include
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

//UML includes
#include "uml/Activity.hpp"
//ActivityNode includes
#include "uml/InputPin.hpp"
#include "uml/CreateObjectAction.hpp"
#include "uml/CallOperationAction.hpp"
#include "uml/ActivityParameterNode.hpp"
#include "uml/OutputPin.hpp"
//ActivityEdge includes
#include "uml/ObjectFlow.hpp"

using namespace FoundationalModelLibrary;

//*********************************
// Constructor / Destructor
//*********************************
FoundationalModelLibraryExecutionFactoryImpl::FoundationalModelLibraryExecutionFactoryImpl()
{
}

FoundationalModelLibraryExecutionFactoryImpl::~FoundationalModelLibraryExecutionFactoryImpl()
{
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> FoundationalModelLibraryExecutionFactoryImpl::createExecution(const std::shared_ptr<uml::Behavior>& behavior, const std::shared_ptr<uml::Element>& context)
{
	switch(behavior->_getID())
	{
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::BASICINPUTOUTPUT_ACTIVITY_WRITELINE:
		{
			if(!m_foundationalModelLibrary_BasicInputOutput_WriteLineExecutionPrototype)
			{
				this->createFoundationalModelLibrary_BasicInputOutput_WriteLineExecutionPrototype();
			}
			return m_foundationalModelLibrary_BasicInputOutput_WriteLineExecutionPrototype;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::BASICINPUTOUTPUT_ACTIVITY_READLINE:
		{
			if(!m_foundationalModelLibrary_BasicInputOutput_ReadLineExecutionPrototype)
			{
				this->createFoundationalModelLibrary_BasicInputOutput_ReadLineExecutionPrototype();
			}
			return m_foundationalModelLibrary_BasicInputOutput_ReadLineExecutionPrototype;
		}
	}


	return nullptr;
}

void FoundationalModelLibraryExecutionFactoryImpl::createFoundationalModelLibrary_BasicInputOutput_WriteLineExecutionPrototype()
{
	std::shared_ptr<uml::Activity> activity = FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_WriteLine();
	m_foundationalModelLibrary_BasicInputOutput_WriteLineExecutionPrototype = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityExecution();
	m_foundationalModelLibrary_BasicInputOutput_WriteLineExecutionPrototype->getTypes()->push_back(activity);
	
	this->getLocus().lock()->add(m_foundationalModelLibrary_BasicInputOutput_WriteLineExecutionPrototype);
	m_foundationalModelLibrary_BasicInputOutput_WriteLineExecutionPrototype->setLocus(this->getLocus().lock());
	
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> newActivationGroup=fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityNodeActivationGroup_as_activationGroup_in_ActivityExecution(m_foundationalModelLibrary_BasicInputOutput_WriteLineExecutionPrototype);
	
	//Create ActivityNodeActivations
	//Create ActivityNodeActivation for ActivityParameterNode 'value'
	DEBUG_INFO("Creating ActivityParameterNodeActivation for ActivityParameterNode 'value'.")
	std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> foundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value_ActivityParameterNodeActivation = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityParameterNodeActivation();
	foundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value_ActivityParameterNodeActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value());
	foundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value_ActivityParameterNodeActivation->setRunning(false);
	newActivationGroup->addNodeActivation(foundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value_ActivityParameterNodeActivation);
	
	//Create ActivityNodeActivation for CallOperationAction 'Call_writeLine'
	DEBUG_INFO("Creating CallOperationActionActivation for CallOperationAction 'Call_writeLine'.")
	std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> foundationalModelLibrary_BasicInputOutput_WriteLine_CallOperationAction_Call_writeLine_CallOperationActionActivation = fUML::Semantics::Actions::ActionsFactory::eInstance()->createCallOperationActionActivation();
	foundationalModelLibrary_BasicInputOutput_WriteLine_CallOperationAction_Call_writeLine_CallOperationActionActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_WriteLine_CallOperationAction_Call_writeLine());
	foundationalModelLibrary_BasicInputOutput_WriteLine_CallOperationAction_Call_writeLine_CallOperationActionActivation->setRunning(false);
	newActivationGroup->addNodeActivation(foundationalModelLibrary_BasicInputOutput_WriteLine_CallOperationAction_Call_writeLine_CallOperationActionActivation);
		//Create PinActivation for InputPin 'Call_writeLine::value'
		std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> inputPin_WriteLine_WriteLine_Call_writeLine_value_InputPinActivation = fUML::Semantics::Actions::ActionsFactory::eInstance()->createInputPinActivation();
		inputPin_WriteLine_WriteLine_Call_writeLine_value_InputPinActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_InputPin_WriteLine_WriteLine_Call_writeLine_value());
		inputPin_WriteLine_WriteLine_Call_writeLine_value_InputPinActivation->setRunning(false);
		foundationalModelLibrary_BasicInputOutput_WriteLine_CallOperationAction_Call_writeLine_CallOperationActionActivation->addPinActivation(inputPin_WriteLine_WriteLine_Call_writeLine_value_InputPinActivation);
		newActivationGroup->addNodeActivation(inputPin_WriteLine_WriteLine_Call_writeLine_value_InputPinActivation);
		//Create PinActivation for InputPin 'Call_writeLine::target'
		std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> inputPin_WriteLine_WriteLine_Call_writeLine_target_InputPinActivation = fUML::Semantics::Actions::ActionsFactory::eInstance()->createInputPinActivation();
		inputPin_WriteLine_WriteLine_Call_writeLine_target_InputPinActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_InputPin_WriteLine_WriteLine_Call_writeLine_target());
		inputPin_WriteLine_WriteLine_Call_writeLine_target_InputPinActivation->setRunning(false);
		foundationalModelLibrary_BasicInputOutput_WriteLine_CallOperationAction_Call_writeLine_CallOperationActionActivation->addPinActivation(inputPin_WriteLine_WriteLine_Call_writeLine_target_InputPinActivation);
		newActivationGroup->addNodeActivation(inputPin_WriteLine_WriteLine_Call_writeLine_target_InputPinActivation);
		//Create PinActivation for OutputPin 'Call_writeLine::errorStatus'
		std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> outputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_OutputPinActivation = fUML::Semantics::Actions::ActionsFactory::eInstance()->createOutputPinActivation();
		outputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_OutputPinActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_OutputPin_WriteLine_WriteLine_Call_writeLine_errorStatus());
		outputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_OutputPinActivation->setRunning(false);
		foundationalModelLibrary_BasicInputOutput_WriteLine_CallOperationAction_Call_writeLine_CallOperationActionActivation->addPinActivation(outputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_OutputPinActivation);
		newActivationGroup->addNodeActivation(outputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_OutputPinActivation);
	
	//Create ActivityNodeActivation for CreateObjectAction 'Create_StandardOutputChannel'
	DEBUG_INFO("Creating CreateObjectActionActivation for CreateObjectAction 'Create_StandardOutputChannel'.")
	std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> foundationalModelLibrary_BasicInputOutput_WriteLine_CreateObjectAction_Create_StandardOutputChannel_CreateObjectActionActivation = fUML::Semantics::Actions::ActionsFactory::eInstance()->createCreateObjectActionActivation();
	foundationalModelLibrary_BasicInputOutput_WriteLine_CreateObjectAction_Create_StandardOutputChannel_CreateObjectActionActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_WriteLine_CreateObjectAction_Create_StandardOutputChannel());
	foundationalModelLibrary_BasicInputOutput_WriteLine_CreateObjectAction_Create_StandardOutputChannel_CreateObjectActionActivation->setRunning(false);
	newActivationGroup->addNodeActivation(foundationalModelLibrary_BasicInputOutput_WriteLine_CreateObjectAction_Create_StandardOutputChannel_CreateObjectActionActivation);
		//Create PinActivation for OutputPin 'Create_StandardOutputChannel::result'
		std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> outputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_OutputPinActivation = fUML::Semantics::Actions::ActionsFactory::eInstance()->createOutputPinActivation();
		outputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_OutputPinActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_OutputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result());
		outputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_OutputPinActivation->setRunning(false);
		foundationalModelLibrary_BasicInputOutput_WriteLine_CreateObjectAction_Create_StandardOutputChannel_CreateObjectActionActivation->addPinActivation(outputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_OutputPinActivation);
		newActivationGroup->addNodeActivation(outputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_OutputPinActivation);
	
	//Create ActivityNodeActivation for ActivityParameterNode 'errorStatus'
	DEBUG_INFO("Creating ActivityParameterNodeActivation for ActivityParameterNode 'errorStatus'.")
	std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> foundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus_ActivityParameterNodeActivation = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityParameterNodeActivation();
	foundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus_ActivityParameterNodeActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus());
	foundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus_ActivityParameterNodeActivation->setRunning(false);
	newActivationGroup->addNodeActivation(foundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus_ActivityParameterNodeActivation);
	
	//Create ActivityEdgeInstances
	//Create ActivityEdgeInstance for ObjectFlow 'oF_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value_InputPin_WriteLine_WriteLine_Call_writeLine_value'
	DEBUG_INFO("Creating EdgeInstance for ObjectFlow 'oF_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value_InputPin_WriteLine_WriteLine_Call_writeLine_value'.")
	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> oF_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value_InputPin_WriteLine_WriteLine_Call_writeLine_value_EdgeInstance = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityEdgeInstance();
	oF_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value_InputPin_WriteLine_WriteLine_Call_writeLine_value_EdgeInstance->setEdge(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_OF_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value_InputPin_WriteLine_WriteLine_Call_writeLine_value());
	newActivationGroup->addEdgeInstance(oF_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value_InputPin_WriteLine_WriteLine_Call_writeLine_value_EdgeInstance);
	foundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value_ActivityParameterNodeActivation->addOutgoingEdge(oF_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value_InputPin_WriteLine_WriteLine_Call_writeLine_value_EdgeInstance);
	inputPin_WriteLine_WriteLine_Call_writeLine_value_InputPinActivation->addIncomingEdge(oF_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value_InputPin_WriteLine_WriteLine_Call_writeLine_value_EdgeInstance);
	
	//Create ActivityEdgeInstance for ObjectFlow 'oF_OutputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_InputPin_WriteLine_WriteLine_Call_writeLine_target'
	DEBUG_INFO("Creating EdgeInstance for ObjectFlow 'oF_OutputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_InputPin_WriteLine_WriteLine_Call_writeLine_target'.")
	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> oF_OutputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_InputPin_WriteLine_WriteLine_Call_writeLine_target_EdgeInstance = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityEdgeInstance();
	oF_OutputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_InputPin_WriteLine_WriteLine_Call_writeLine_target_EdgeInstance->setEdge(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_OF_OutputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_InputPin_WriteLine_WriteLine_Call_writeLine_target());
	newActivationGroup->addEdgeInstance(oF_OutputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_InputPin_WriteLine_WriteLine_Call_writeLine_target_EdgeInstance);
	outputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_OutputPinActivation->addOutgoingEdge(oF_OutputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_InputPin_WriteLine_WriteLine_Call_writeLine_target_EdgeInstance);
	inputPin_WriteLine_WriteLine_Call_writeLine_target_InputPinActivation->addIncomingEdge(oF_OutputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_InputPin_WriteLine_WriteLine_Call_writeLine_target_EdgeInstance);
	
	//Create ActivityEdgeInstance for ObjectFlow 'oF_OutputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus'
	DEBUG_INFO("Creating EdgeInstance for ObjectFlow 'oF_OutputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus'.")
	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> oF_OutputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus_EdgeInstance = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityEdgeInstance();
	oF_OutputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus_EdgeInstance->setEdge(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_OF_OutputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus());
	newActivationGroup->addEdgeInstance(oF_OutputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus_EdgeInstance);
	outputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_OutputPinActivation->addOutgoingEdge(oF_OutputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus_EdgeInstance);
	foundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus_ActivityParameterNodeActivation->addIncomingEdge(oF_OutputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus_EdgeInstance);
}
void FoundationalModelLibraryExecutionFactoryImpl::createFoundationalModelLibrary_BasicInputOutput_ReadLineExecutionPrototype()
{
	std::shared_ptr<uml::Activity> activity = FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_ReadLine();
	m_foundationalModelLibrary_BasicInputOutput_ReadLineExecutionPrototype = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityExecution();
	m_foundationalModelLibrary_BasicInputOutput_ReadLineExecutionPrototype->getTypes()->push_back(activity);
	
	this->getLocus().lock()->add(m_foundationalModelLibrary_BasicInputOutput_ReadLineExecutionPrototype);
	m_foundationalModelLibrary_BasicInputOutput_ReadLineExecutionPrototype->setLocus(this->getLocus().lock());
	
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> newActivationGroup=fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityNodeActivationGroup_as_activationGroup_in_ActivityExecution(m_foundationalModelLibrary_BasicInputOutput_ReadLineExecutionPrototype);
	
	//Create ActivityNodeActivations
	//Create ActivityNodeActivation for ActivityParameterNode 'errorStatus'
	DEBUG_INFO("Creating ActivityParameterNodeActivation for ActivityParameterNode 'errorStatus'.")
	std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> foundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus_ActivityParameterNodeActivation = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityParameterNodeActivation();
	foundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus_ActivityParameterNodeActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus());
	foundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus_ActivityParameterNodeActivation->setRunning(false);
	newActivationGroup->addNodeActivation(foundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus_ActivityParameterNodeActivation);
	
	//Create ActivityNodeActivation for ActivityParameterNode 'result'
	DEBUG_INFO("Creating ActivityParameterNodeActivation for ActivityParameterNode 'result'.")
	std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> foundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result_ActivityParameterNodeActivation = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityParameterNodeActivation();
	foundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result_ActivityParameterNodeActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result());
	foundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result_ActivityParameterNodeActivation->setRunning(false);
	newActivationGroup->addNodeActivation(foundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result_ActivityParameterNodeActivation);
	
	//Create ActivityNodeActivation for CreateObjectAction 'Create_StandardInputChannel'
	DEBUG_INFO("Creating CreateObjectActionActivation for CreateObjectAction 'Create_StandardInputChannel'.")
	std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> foundationalModelLibrary_BasicInputOutput_ReadLine_CreateObjectAction_Create_StandardInputChannel_CreateObjectActionActivation = fUML::Semantics::Actions::ActionsFactory::eInstance()->createCreateObjectActionActivation();
	foundationalModelLibrary_BasicInputOutput_ReadLine_CreateObjectAction_Create_StandardInputChannel_CreateObjectActionActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_ReadLine_CreateObjectAction_Create_StandardInputChannel());
	foundationalModelLibrary_BasicInputOutput_ReadLine_CreateObjectAction_Create_StandardInputChannel_CreateObjectActionActivation->setRunning(false);
	newActivationGroup->addNodeActivation(foundationalModelLibrary_BasicInputOutput_ReadLine_CreateObjectAction_Create_StandardInputChannel_CreateObjectActionActivation);
		//Create PinActivation for OutputPin 'Create_StandardInputChannel::result'
		std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> outputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_OutputPinActivation = fUML::Semantics::Actions::ActionsFactory::eInstance()->createOutputPinActivation();
		outputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_OutputPinActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_OutputPin_ReadLine_ReadLine_Create_StandardInputChannel_result());
		outputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_OutputPinActivation->setRunning(false);
		foundationalModelLibrary_BasicInputOutput_ReadLine_CreateObjectAction_Create_StandardInputChannel_CreateObjectActionActivation->addPinActivation(outputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_OutputPinActivation);
		newActivationGroup->addNodeActivation(outputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_OutputPinActivation);
	
	//Create ActivityNodeActivation for CallOperationAction 'Call_readLine'
	DEBUG_INFO("Creating CallOperationActionActivation for CallOperationAction 'Call_readLine'.")
	std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> foundationalModelLibrary_BasicInputOutput_ReadLine_CallOperationAction_Call_readLine_CallOperationActionActivation = fUML::Semantics::Actions::ActionsFactory::eInstance()->createCallOperationActionActivation();
	foundationalModelLibrary_BasicInputOutput_ReadLine_CallOperationAction_Call_readLine_CallOperationActionActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_ReadLine_CallOperationAction_Call_readLine());
	foundationalModelLibrary_BasicInputOutput_ReadLine_CallOperationAction_Call_readLine_CallOperationActionActivation->setRunning(false);
	newActivationGroup->addNodeActivation(foundationalModelLibrary_BasicInputOutput_ReadLine_CallOperationAction_Call_readLine_CallOperationActionActivation);
		//Create PinActivation for InputPin 'Call_readLine::target'
		std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> inputPin_ReadLine_ReadLine_Call_readLine_target_InputPinActivation = fUML::Semantics::Actions::ActionsFactory::eInstance()->createInputPinActivation();
		inputPin_ReadLine_ReadLine_Call_readLine_target_InputPinActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_InputPin_ReadLine_ReadLine_Call_readLine_target());
		inputPin_ReadLine_ReadLine_Call_readLine_target_InputPinActivation->setRunning(false);
		foundationalModelLibrary_BasicInputOutput_ReadLine_CallOperationAction_Call_readLine_CallOperationActionActivation->addPinActivation(inputPin_ReadLine_ReadLine_Call_readLine_target_InputPinActivation);
		newActivationGroup->addNodeActivation(inputPin_ReadLine_ReadLine_Call_readLine_target_InputPinActivation);
		//Create PinActivation for OutputPin 'Call_readLine::ReturnResult'
		std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> outputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_OutputPinActivation = fUML::Semantics::Actions::ActionsFactory::eInstance()->createOutputPinActivation();
		outputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_OutputPinActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_OutputPin_ReadLine_ReadLine_Call_readLine_ReturnResult());
		outputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_OutputPinActivation->setRunning(false);
		foundationalModelLibrary_BasicInputOutput_ReadLine_CallOperationAction_Call_readLine_CallOperationActionActivation->addPinActivation(outputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_OutputPinActivation);
		newActivationGroup->addNodeActivation(outputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_OutputPinActivation);
		//Create PinActivation for OutputPin 'Call_readLine::errorStatus'
		std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> outputPin_ReadLine_ReadLine_Call_readLine_errorStatus_OutputPinActivation = fUML::Semantics::Actions::ActionsFactory::eInstance()->createOutputPinActivation();
		outputPin_ReadLine_ReadLine_Call_readLine_errorStatus_OutputPinActivation->setNode(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_OutputPin_ReadLine_ReadLine_Call_readLine_errorStatus());
		outputPin_ReadLine_ReadLine_Call_readLine_errorStatus_OutputPinActivation->setRunning(false);
		foundationalModelLibrary_BasicInputOutput_ReadLine_CallOperationAction_Call_readLine_CallOperationActionActivation->addPinActivation(outputPin_ReadLine_ReadLine_Call_readLine_errorStatus_OutputPinActivation);
		newActivationGroup->addNodeActivation(outputPin_ReadLine_ReadLine_Call_readLine_errorStatus_OutputPinActivation);
	
	//Create ActivityEdgeInstances
	//Create ActivityEdgeInstance for ObjectFlow 'oF_OutputPin_ReadLine_ReadLine_Call_readLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus'
	DEBUG_INFO("Creating EdgeInstance for ObjectFlow 'oF_OutputPin_ReadLine_ReadLine_Call_readLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus'.")
	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> oF_OutputPin_ReadLine_ReadLine_Call_readLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus_EdgeInstance = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityEdgeInstance();
	oF_OutputPin_ReadLine_ReadLine_Call_readLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus_EdgeInstance->setEdge(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_OF_OutputPin_ReadLine_ReadLine_Call_readLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus());
	newActivationGroup->addEdgeInstance(oF_OutputPin_ReadLine_ReadLine_Call_readLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus_EdgeInstance);
	outputPin_ReadLine_ReadLine_Call_readLine_errorStatus_OutputPinActivation->addOutgoingEdge(oF_OutputPin_ReadLine_ReadLine_Call_readLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus_EdgeInstance);
	foundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus_ActivityParameterNodeActivation->addIncomingEdge(oF_OutputPin_ReadLine_ReadLine_Call_readLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus_EdgeInstance);
	
	//Create ActivityEdgeInstance for ObjectFlow 'oF_OutputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result'
	DEBUG_INFO("Creating EdgeInstance for ObjectFlow 'oF_OutputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result'.")
	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> oF_OutputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result_EdgeInstance = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityEdgeInstance();
	oF_OutputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result_EdgeInstance->setEdge(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_OF_OutputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result());
	newActivationGroup->addEdgeInstance(oF_OutputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result_EdgeInstance);
	outputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_OutputPinActivation->addOutgoingEdge(oF_OutputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result_EdgeInstance);
	foundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result_ActivityParameterNodeActivation->addIncomingEdge(oF_OutputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result_EdgeInstance);
	
	//Create ActivityEdgeInstance for ObjectFlow 'oF_OutputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_InputPin_ReadLine_ReadLine_Call_readLine_target'
	DEBUG_INFO("Creating EdgeInstance for ObjectFlow 'oF_OutputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_InputPin_ReadLine_ReadLine_Call_readLine_target'.")
	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> oF_OutputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_InputPin_ReadLine_ReadLine_Call_readLine_target_EdgeInstance = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityEdgeInstance();
	oF_OutputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_InputPin_ReadLine_ReadLine_Call_readLine_target_EdgeInstance->setEdge(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_OF_OutputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_InputPin_ReadLine_ReadLine_Call_readLine_target());
	newActivationGroup->addEdgeInstance(oF_OutputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_InputPin_ReadLine_ReadLine_Call_readLine_target_EdgeInstance);
	outputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_OutputPinActivation->addOutgoingEdge(oF_OutputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_InputPin_ReadLine_ReadLine_Call_readLine_target_EdgeInstance);
	inputPin_ReadLine_ReadLine_Call_readLine_target_InputPinActivation->addIncomingEdge(oF_OutputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_InputPin_ReadLine_ReadLine_Call_readLine_target_EdgeInstance);
}


void FoundationalModelLibraryExecutionFactoryImpl::setThisExecutionFactoryPtr(std::weak_ptr</*PSCS::Semantics::Loci::CS_ExecutionFactory*/fUML::Semantics::Loci::ExecutionFactory> thisExecutionFactoryPtr)
{
	/*PSCS::Semantics::Loci::CS_ExecutionFactoryImpl::setThisExecutionFactoryPtr(thisExecutionFactoryPtr)*/ fUML::Semantics::Loci::ExecutionFactoryImpl::setThisExecutionFactoryPtr(thisExecutionFactoryPtr);
}
