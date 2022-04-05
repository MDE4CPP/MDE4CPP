#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace fUML::Semantics::Actions;

void ActionsPackageImpl::initializePackageContents()
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setNsPrefix(eNS_PREFIX);
	setNsURI(eNS_URI);
	
	// Add supertypes to classes
	m_actionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Class());
	m_addStructuralFeatureValueActionActivation_Class->getESuperTypes()->push_back(getWriteStructuralFeatureActionActivation_Class());
	m_clearStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(getStructuralFeatureActionActivation_Class());
	m_createObjectActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_inputPinActivation_Class->getESuperTypes()->push_back(getPinActivation_Class());
	m_outputPinActivation_Class->getESuperTypes()->push_back(getPinActivation_Class());
	m_pinActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getObjectNodeActivation_Class());
	m_readSelfActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_readStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(getStructuralFeatureActionActivation_Class());
	m_structuralFeatureActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_structuredActivityNodeActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_valueSpecificationActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_writeStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(getStructuralFeatureActionActivation_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeActionActivationContent();
	initializeAddStructuralFeatureValueActionActivationContent();
	initializeClearStructuralFeatureActionActivationContent();
	initializeCreateObjectActionActivationContent();
	initializeInputPinActivationContent();
	initializeOutputPinActivationContent();
	initializePinActivationContent();
	initializeReadSelfActionActivationContent();
	initializeReadStructuralFeatureActionActivationContent();
	initializeStructuralFeatureActionActivationContent();
	initializeStructuredActivityNodeActivationContent();
	initializeValueSpecificationActionActivationContent();
	initializeValuesContent();
	initializeWriteStructuralFeatureActionActivationContent();

	initializePackageEDataTypes();

}

void ActionsPackageImpl::initializeActionActivationContent()
{
	m_actionActivation_Class->setName("ActionActivation");
	m_actionActivation_Class->setAbstract(true);
	m_actionActivation_Class->setInterface(false);
	
	m_actionActivation_Attribute_firing = getActionActivation_Attribute_firing();
	m_actionActivation_Attribute_firing->setName("firing");
		m_actionActivation_Attribute_firing->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Attribute_firing->setLowerBound(1);
	m_actionActivation_Attribute_firing->setUpperBound(1);
	m_actionActivation_Attribute_firing->setTransient(false);
	m_actionActivation_Attribute_firing->setVolatile(false);
	m_actionActivation_Attribute_firing->setChangeable(true);
	m_actionActivation_Attribute_firing->setUnsettable(false);
	m_actionActivation_Attribute_firing->setUnique(true);
	m_actionActivation_Attribute_firing->setDerived(false);
	m_actionActivation_Attribute_firing->setOrdered(false);
	m_actionActivation_Attribute_firing->setID(false);
	{
		std::string defaultValue = "false";
		if (!defaultValue.empty())
		{
		   m_actionActivation_Attribute_firing->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_actionActivation_Attribute_action->setName("action");
	m_actionActivation_Attribute_action->setEType(uml::umlPackage::eInstance()->getAction_Class());
	m_actionActivation_Attribute_action->setLowerBound(1);
	m_actionActivation_Attribute_action->setUpperBound(1);
	m_actionActivation_Attribute_action->setTransient(false);
	m_actionActivation_Attribute_action->setVolatile(false);
	m_actionActivation_Attribute_action->setChangeable(true);
	m_actionActivation_Attribute_action->setUnsettable(false);
	m_actionActivation_Attribute_action->setUnique(true);
	m_actionActivation_Attribute_action->setDerived(false);
	m_actionActivation_Attribute_action->setOrdered(true);
	m_actionActivation_Attribute_action->setContainment(false);
	m_actionActivation_Attribute_action->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_actionActivation_Attribute_action->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_actionActivation_Attribute_inputPinActivation->setName("inputPinActivation");
	m_actionActivation_Attribute_inputPinActivation->setEType(getInputPinActivation_Class());
	m_actionActivation_Attribute_inputPinActivation->setLowerBound(0);
	m_actionActivation_Attribute_inputPinActivation->setUpperBound(-1);
	m_actionActivation_Attribute_inputPinActivation->setTransient(false);
	m_actionActivation_Attribute_inputPinActivation->setVolatile(false);
	m_actionActivation_Attribute_inputPinActivation->setChangeable(true);
	m_actionActivation_Attribute_inputPinActivation->setUnsettable(false);
	m_actionActivation_Attribute_inputPinActivation->setUnique(true);
	m_actionActivation_Attribute_inputPinActivation->setDerived(false);
	m_actionActivation_Attribute_inputPinActivation->setOrdered(false);
	m_actionActivation_Attribute_inputPinActivation->setContainment(false);
	m_actionActivation_Attribute_inputPinActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_actionActivation_Attribute_inputPinActivation->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_actionActivation_Attribute_outputPinActivation->setName("outputPinActivation");
	m_actionActivation_Attribute_outputPinActivation->setEType(getOutputPinActivation_Class());
	m_actionActivation_Attribute_outputPinActivation->setLowerBound(0);
	m_actionActivation_Attribute_outputPinActivation->setUpperBound(-1);
	m_actionActivation_Attribute_outputPinActivation->setTransient(false);
	m_actionActivation_Attribute_outputPinActivation->setVolatile(false);
	m_actionActivation_Attribute_outputPinActivation->setChangeable(true);
	m_actionActivation_Attribute_outputPinActivation->setUnsettable(false);
	m_actionActivation_Attribute_outputPinActivation->setUnique(true);
	m_actionActivation_Attribute_outputPinActivation->setDerived(false);
	m_actionActivation_Attribute_outputPinActivation->setOrdered(false);
	m_actionActivation_Attribute_outputPinActivation->setContainment(false);
	m_actionActivation_Attribute_outputPinActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_actionActivation_Attribute_outputPinActivation->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_actionActivation_Attribute_pinActivation->setName("pinActivation");
	m_actionActivation_Attribute_pinActivation->setEType(getPinActivation_Class());
	m_actionActivation_Attribute_pinActivation->setLowerBound(0);
	m_actionActivation_Attribute_pinActivation->setUpperBound(-1);
	m_actionActivation_Attribute_pinActivation->setTransient(false);
	m_actionActivation_Attribute_pinActivation->setVolatile(false);
	m_actionActivation_Attribute_pinActivation->setChangeable(true);
	m_actionActivation_Attribute_pinActivation->setUnsettable(false);
	m_actionActivation_Attribute_pinActivation->setUnique(true);
	m_actionActivation_Attribute_pinActivation->setDerived(false);
	m_actionActivation_Attribute_pinActivation->setOrdered(false);
	m_actionActivation_Attribute_pinActivation->setContainment(false);
	m_actionActivation_Attribute_pinActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_actionActivation_Attribute_pinActivation->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Actions::ActionsPackage::eInstance()->getPinActivation_Attribute_actionActivation();
		if (otherEnd != nullptr)
	    {
	   		m_actionActivation_Attribute_pinActivation->setEOpposite(otherEnd);
	    }
	}
	
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setName("addOutgoingEdge");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setEType(unknownClass);
	}
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setLowerBound(1);
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setUpperBound(1);
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setUnique(true);
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance);
		parameter->setName("edge");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_addPinActivation_PinActivation->setName("addPinActivation");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_addPinActivation_PinActivation->setEType(unknownClass);
	}
	m_actionActivation_Operation_addPinActivation_PinActivation->setLowerBound(1);
	m_actionActivation_Operation_addPinActivation_PinActivation->setUpperBound(1);
	m_actionActivation_Operation_addPinActivation_PinActivation->setUnique(true);
	m_actionActivation_Operation_addPinActivation_PinActivation->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_addPinActivation_PinActivation);
		parameter->setName("pinActivation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_completeAction->setName("completeAction");
	m_actionActivation_Operation_completeAction->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class());
	m_actionActivation_Operation_completeAction->setLowerBound(0);
	m_actionActivation_Operation_completeAction->setUpperBound(-1);
	m_actionActivation_Operation_completeAction->setUnique(true);
	m_actionActivation_Operation_completeAction->setOrdered(false);
	
	m_actionActivation_Operation_createNodeActivations->setName("createNodeActivations");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_createNodeActivations->setEType(unknownClass);
	}
	m_actionActivation_Operation_createNodeActivations->setLowerBound(1);
	m_actionActivation_Operation_createNodeActivations->setUpperBound(1);
	m_actionActivation_Operation_createNodeActivations->setUnique(true);
	m_actionActivation_Operation_createNodeActivations->setOrdered(false);
	
	m_actionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_actionActivation_Operation_doAction->setLowerBound(1);
	m_actionActivation_Operation_doAction->setUpperBound(1);
	m_actionActivation_Operation_doAction->setUnique(true);
	m_actionActivation_Operation_doAction->setOrdered(false);
	
	m_actionActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_actionActivation_Operation_fire_Token->setLowerBound(1);
	m_actionActivation_Operation_fire_Token->setUpperBound(1);
	m_actionActivation_Operation_fire_Token->setUnique(true);
	m_actionActivation_Operation_fire_Token->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_getTokens_InputPin->setName("getTokens");
	m_actionActivation_Operation_getTokens_InputPin->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_actionActivation_Operation_getTokens_InputPin->setLowerBound(0);
	m_actionActivation_Operation_getTokens_InputPin->setUpperBound(-1);
	m_actionActivation_Operation_getTokens_InputPin->setUnique(true);
	m_actionActivation_Operation_getTokens_InputPin->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_getTokens_InputPin);
		parameter->setName("pin");
		parameter->setEType(uml::umlPackage::eInstance()->getInputPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_isFirng->setName("isFirng");
	m_actionActivation_Operation_isFirng->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_isFirng->setLowerBound(1);
	m_actionActivation_Operation_isFirng->setUpperBound(1);
	m_actionActivation_Operation_isFirng->setUnique(true);
	m_actionActivation_Operation_isFirng->setOrdered(false);
	
	m_actionActivation_Operation_isReady->setName("isReady");
	m_actionActivation_Operation_isReady->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_isReady->setLowerBound(1);
	m_actionActivation_Operation_isReady->setUpperBound(1);
	m_actionActivation_Operation_isReady->setUnique(true);
	m_actionActivation_Operation_isReady->setOrdered(false);
	
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setName("isSourceFor");
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setUnique(true);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstance");
		parameter->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_putToken_OutputPin_EJavaObject->setName("putToken");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_putToken_OutputPin_EJavaObject->setEType(unknownClass);
	}
	m_actionActivation_Operation_putToken_OutputPin_EJavaObject->setLowerBound(1);
	m_actionActivation_Operation_putToken_OutputPin_EJavaObject->setUpperBound(1);
	m_actionActivation_Operation_putToken_OutputPin_EJavaObject->setUnique(true);
	m_actionActivation_Operation_putToken_OutputPin_EJavaObject->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_putToken_OutputPin_EJavaObject);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_putToken_OutputPin_EJavaObject);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_putTokens_OutputPin_EJavaObject->setName("putTokens");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_putTokens_OutputPin_EJavaObject->setEType(unknownClass);
	}
	m_actionActivation_Operation_putTokens_OutputPin_EJavaObject->setLowerBound(1);
	m_actionActivation_Operation_putTokens_OutputPin_EJavaObject->setUpperBound(1);
	m_actionActivation_Operation_putTokens_OutputPin_EJavaObject->setUnique(true);
	m_actionActivation_Operation_putTokens_OutputPin_EJavaObject->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_putTokens_OutputPin_EJavaObject);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_putTokens_OutputPin_EJavaObject);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_retrievePinActivation_Pin->setName("retrievePinActivation");
	m_actionActivation_Operation_retrievePinActivation_Pin->setEType(getPinActivation_Class());
	m_actionActivation_Operation_retrievePinActivation_Pin->setLowerBound(1);
	m_actionActivation_Operation_retrievePinActivation_Pin->setUpperBound(1);
	m_actionActivation_Operation_retrievePinActivation_Pin->setUnique(true);
	m_actionActivation_Operation_retrievePinActivation_Pin->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_retrievePinActivation_Pin);
		parameter->setName("pin");
		parameter->setEType(uml::umlPackage::eInstance()->getPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_run->setName("run");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_run->setEType(unknownClass);
	}
	m_actionActivation_Operation_run->setLowerBound(1);
	m_actionActivation_Operation_run->setUpperBound(1);
	m_actionActivation_Operation_run->setUnique(true);
	m_actionActivation_Operation_run->setOrdered(false);
	
	m_actionActivation_Operation_sendOffers->setName("sendOffers");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_sendOffers->setEType(unknownClass);
	}
	m_actionActivation_Operation_sendOffers->setLowerBound(1);
	m_actionActivation_Operation_sendOffers->setUpperBound(1);
	m_actionActivation_Operation_sendOffers->setUnique(true);
	m_actionActivation_Operation_sendOffers->setOrdered(false);
	
	m_actionActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_actionActivation_Operation_takeOfferedTokens->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class());
	m_actionActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_actionActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_actionActivation_Operation_takeOfferedTokens->setUnique(true);
	m_actionActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	m_actionActivation_Operation_takeTokens_InputPin->setName("takeTokens");
	m_actionActivation_Operation_takeTokens_InputPin->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_actionActivation_Operation_takeTokens_InputPin->setLowerBound(0);
	m_actionActivation_Operation_takeTokens_InputPin->setUpperBound(-1);
	m_actionActivation_Operation_takeTokens_InputPin->setUnique(true);
	m_actionActivation_Operation_takeTokens_InputPin->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_takeTokens_InputPin);
		parameter->setName("pin");
		parameter->setEType(uml::umlPackage::eInstance()->getInputPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_terminate->setEType(unknownClass);
	}
	m_actionActivation_Operation_terminate->setLowerBound(1);
	m_actionActivation_Operation_terminate->setUpperBound(1);
	m_actionActivation_Operation_terminate->setUnique(true);
	m_actionActivation_Operation_terminate->setOrdered(false);
	
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element->setName("valueParticipatesInLink");
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element->setLowerBound(1);
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element->setUpperBound(1);
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element->setUnique(true);
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element);
		parameter->setName("value");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element);
		parameter->setName("link");
		parameter->setEType(uml::umlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeAddStructuralFeatureValueActionActivationContent()
{
	m_addStructuralFeatureValueActionActivation_Class->setName("AddStructuralFeatureValueActionActivation");
	m_addStructuralFeatureValueActionActivation_Class->setAbstract(false);
	m_addStructuralFeatureValueActionActivation_Class->setInterface(false);
	
	
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setName("addStructuralFeatureValueAction");
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setEType(uml::umlPackage::eInstance()->getAddStructuralFeatureValueAction_Class());
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setLowerBound(1);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setUpperBound(1);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setTransient(false);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setVolatile(false);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setChangeable(true);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setUnsettable(false);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setUnique(true);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setDerived(false);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setOrdered(true);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setContainment(false);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_addStructuralFeatureValueActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setLowerBound(0);
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setUpperBound(1);
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setUnique(true);
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setOrdered(true);
	
	
}

void ActionsPackageImpl::initializeClearStructuralFeatureActionActivationContent()
{
	m_clearStructuralFeatureActionActivation_Class->setName("ClearStructuralFeatureActionActivation");
	m_clearStructuralFeatureActionActivation_Class->setAbstract(false);
	m_clearStructuralFeatureActionActivation_Class->setInterface(false);
	
	
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setName("clearStructuralFeatureAction");
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setEType(uml::umlPackage::eInstance()->getClearStructuralFeatureAction_Class());
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setLowerBound(1);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setUpperBound(1);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setTransient(false);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setVolatile(false);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setChangeable(true);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setUnsettable(false);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setUnique(true);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setDerived(false);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setOrdered(true);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setContainment(false);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_clearStructuralFeatureActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_clearStructuralFeatureActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_clearStructuralFeatureActionActivation_Operation_doAction->setLowerBound(0);
	m_clearStructuralFeatureActionActivation_Operation_doAction->setUpperBound(1);
	m_clearStructuralFeatureActionActivation_Operation_doAction->setUnique(true);
	m_clearStructuralFeatureActionActivation_Operation_doAction->setOrdered(true);
	
	
}

void ActionsPackageImpl::initializeCreateObjectActionActivationContent()
{
	m_createObjectActionActivation_Class->setName("CreateObjectActionActivation");
	m_createObjectActionActivation_Class->setAbstract(false);
	m_createObjectActionActivation_Class->setInterface(false);
	
	
	m_createObjectActionActivation_Attribute_createObjectAction->setName("createObjectAction");
	m_createObjectActionActivation_Attribute_createObjectAction->setEType(uml::umlPackage::eInstance()->getCreateObjectAction_Class());
	m_createObjectActionActivation_Attribute_createObjectAction->setLowerBound(1);
	m_createObjectActionActivation_Attribute_createObjectAction->setUpperBound(1);
	m_createObjectActionActivation_Attribute_createObjectAction->setTransient(false);
	m_createObjectActionActivation_Attribute_createObjectAction->setVolatile(false);
	m_createObjectActionActivation_Attribute_createObjectAction->setChangeable(true);
	m_createObjectActionActivation_Attribute_createObjectAction->setUnsettable(false);
	m_createObjectActionActivation_Attribute_createObjectAction->setUnique(true);
	m_createObjectActionActivation_Attribute_createObjectAction->setDerived(false);
	m_createObjectActionActivation_Attribute_createObjectAction->setOrdered(true);
	m_createObjectActionActivation_Attribute_createObjectAction->setContainment(false);
	m_createObjectActionActivation_Attribute_createObjectAction->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_createObjectActionActivation_Attribute_createObjectAction->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_createObjectActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_createObjectActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_createObjectActionActivation_Operation_doAction->setLowerBound(0);
	m_createObjectActionActivation_Operation_doAction->setUpperBound(1);
	m_createObjectActionActivation_Operation_doAction->setUnique(true);
	m_createObjectActionActivation_Operation_doAction->setOrdered(true);
	
	
}

void ActionsPackageImpl::initializeInputPinActivationContent()
{
	m_inputPinActivation_Class->setName("InputPinActivation");
	m_inputPinActivation_Class->setAbstract(false);
	m_inputPinActivation_Class->setInterface(false);
	
	
	
	m_inputPinActivation_Operation_isReady->setName("isReady");
	m_inputPinActivation_Operation_isReady->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_inputPinActivation_Operation_isReady->setLowerBound(1);
	m_inputPinActivation_Operation_isReady->setUpperBound(1);
	m_inputPinActivation_Operation_isReady->setUnique(true);
	m_inputPinActivation_Operation_isReady->setOrdered(false);
	
	m_inputPinActivation_Operation_receiveOffer->setName("receiveOffer");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_inputPinActivation_Operation_receiveOffer->setEType(unknownClass);
	}
	m_inputPinActivation_Operation_receiveOffer->setLowerBound(1);
	m_inputPinActivation_Operation_receiveOffer->setUpperBound(1);
	m_inputPinActivation_Operation_receiveOffer->setUnique(true);
	m_inputPinActivation_Operation_receiveOffer->setOrdered(false);
	
	
}

void ActionsPackageImpl::initializeOutputPinActivationContent()
{
	m_outputPinActivation_Class->setName("OutputPinActivation");
	m_outputPinActivation_Class->setAbstract(false);
	m_outputPinActivation_Class->setInterface(false);
	
	
	
	
}

void ActionsPackageImpl::initializePinActivationContent()
{
	m_pinActivation_Class->setName("PinActivation");
	m_pinActivation_Class->setAbstract(true);
	m_pinActivation_Class->setInterface(false);
	
	
	m_pinActivation_Attribute_actionActivation->setName("actionActivation");
	m_pinActivation_Attribute_actionActivation->setEType(getActionActivation_Class());
	m_pinActivation_Attribute_actionActivation->setLowerBound(0);
	m_pinActivation_Attribute_actionActivation->setUpperBound(1);
	m_pinActivation_Attribute_actionActivation->setTransient(false);
	m_pinActivation_Attribute_actionActivation->setVolatile(false);
	m_pinActivation_Attribute_actionActivation->setChangeable(true);
	m_pinActivation_Attribute_actionActivation->setUnsettable(false);
	m_pinActivation_Attribute_actionActivation->setUnique(true);
	m_pinActivation_Attribute_actionActivation->setDerived(false);
	m_pinActivation_Attribute_actionActivation->setOrdered(false);
	m_pinActivation_Attribute_actionActivation->setContainment(false);
	m_pinActivation_Attribute_actionActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_pinActivation_Attribute_actionActivation->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Actions::ActionsPackage::eInstance()->getActionActivation_Attribute_pinActivation();
		if (otherEnd != nullptr)
	    {
	   		m_pinActivation_Attribute_actionActivation->setEOpposite(otherEnd);
	    }
	}
	m_pinActivation_Attribute_pin->setName("pin");
	m_pinActivation_Attribute_pin->setEType(uml::umlPackage::eInstance()->getPin_Class());
	m_pinActivation_Attribute_pin->setLowerBound(1);
	m_pinActivation_Attribute_pin->setUpperBound(1);
	m_pinActivation_Attribute_pin->setTransient(false);
	m_pinActivation_Attribute_pin->setVolatile(false);
	m_pinActivation_Attribute_pin->setChangeable(true);
	m_pinActivation_Attribute_pin->setUnsettable(false);
	m_pinActivation_Attribute_pin->setUnique(true);
	m_pinActivation_Attribute_pin->setDerived(false);
	m_pinActivation_Attribute_pin->setOrdered(true);
	m_pinActivation_Attribute_pin->setContainment(false);
	m_pinActivation_Attribute_pin->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_pinActivation_Attribute_pin->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_pinActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_pinActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_pinActivation_Operation_fire_Token->setLowerBound(1);
	m_pinActivation_Operation_fire_Token->setUpperBound(1);
	m_pinActivation_Operation_fire_Token->setUnique(true);
	m_pinActivation_Operation_fire_Token->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pinActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pinActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_pinActivation_Operation_takeOfferedTokens->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class());
	m_pinActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_pinActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_pinActivation_Operation_takeOfferedTokens->setUnique(true);
	m_pinActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	
}

void ActionsPackageImpl::initializeReadSelfActionActivationContent()
{
	m_readSelfActionActivation_Class->setName("ReadSelfActionActivation");
	m_readSelfActionActivation_Class->setAbstract(false);
	m_readSelfActionActivation_Class->setInterface(false);
	
	
	m_readSelfActionActivation_Attribute_readSelfAction->setName("readSelfAction");
	m_readSelfActionActivation_Attribute_readSelfAction->setEType(uml::umlPackage::eInstance()->getReadSelfAction_Class());
	m_readSelfActionActivation_Attribute_readSelfAction->setLowerBound(1);
	m_readSelfActionActivation_Attribute_readSelfAction->setUpperBound(1);
	m_readSelfActionActivation_Attribute_readSelfAction->setTransient(false);
	m_readSelfActionActivation_Attribute_readSelfAction->setVolatile(false);
	m_readSelfActionActivation_Attribute_readSelfAction->setChangeable(true);
	m_readSelfActionActivation_Attribute_readSelfAction->setUnsettable(false);
	m_readSelfActionActivation_Attribute_readSelfAction->setUnique(true);
	m_readSelfActionActivation_Attribute_readSelfAction->setDerived(false);
	m_readSelfActionActivation_Attribute_readSelfAction->setOrdered(true);
	m_readSelfActionActivation_Attribute_readSelfAction->setContainment(false);
	m_readSelfActionActivation_Attribute_readSelfAction->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_readSelfActionActivation_Attribute_readSelfAction->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_readSelfActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_readSelfActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_readSelfActionActivation_Operation_doAction->setLowerBound(0);
	m_readSelfActionActivation_Operation_doAction->setUpperBound(1);
	m_readSelfActionActivation_Operation_doAction->setUnique(true);
	m_readSelfActionActivation_Operation_doAction->setOrdered(true);
	
	
}

void ActionsPackageImpl::initializeReadStructuralFeatureActionActivationContent()
{
	m_readStructuralFeatureActionActivation_Class->setName("ReadStructuralFeatureActionActivation");
	m_readStructuralFeatureActionActivation_Class->setAbstract(false);
	m_readStructuralFeatureActionActivation_Class->setInterface(false);
	
	
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setName("readStructuralFeatureAction");
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setEType(uml::umlPackage::eInstance()->getReadStructuralFeatureAction_Class());
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setLowerBound(1);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setUpperBound(1);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setTransient(false);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setVolatile(false);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setChangeable(true);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setUnsettable(false);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setUnique(true);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setDerived(false);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setOrdered(true);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setContainment(false);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_readStructuralFeatureActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_readStructuralFeatureActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_readStructuralFeatureActionActivation_Operation_doAction->setLowerBound(0);
	m_readStructuralFeatureActionActivation_Operation_doAction->setUpperBound(1);
	m_readStructuralFeatureActionActivation_Operation_doAction->setUnique(true);
	m_readStructuralFeatureActionActivation_Operation_doAction->setOrdered(true);
	
	
}

void ActionsPackageImpl::initializeStructuralFeatureActionActivationContent()
{
	m_structuralFeatureActionActivation_Class->setName("StructuralFeatureActionActivation");
	m_structuralFeatureActionActivation_Class->setAbstract(true);
	m_structuralFeatureActionActivation_Class->setInterface(false);
	
	
	
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setName("getAssociation");
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setEType(uml::umlPackage::eInstance()->getAssociation_Class());
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setLowerBound(0);
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setUpperBound(1);
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject->setName("getMatchingLinks");
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject->setEType(uml::umlPackage::eInstance()->getElement_Class());
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject->setLowerBound(0);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject->setUpperBound(-1);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject);
		parameter->setName("association");
		parameter->setEType(uml::umlPackage::eInstance()->getAssociation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject);
		parameter->setName("end");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject);
		parameter->setName("oppositeValue");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject->setName("getMatchingLinksForEndValue");
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject->setEType(uml::umlPackage::eInstance()->getElement_Class());
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject->setLowerBound(0);
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject->setUpperBound(-1);
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject);
		parameter->setName("association");
		parameter->setEType(uml::umlPackage::eInstance()->getAssociation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject);
		parameter->setName("end");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject);
		parameter->setName("oppositeValue");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject);
		parameter->setName("endValue");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setName("getOppositeEnd");
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setEType(uml::umlPackage::eInstance()->getProperty_Class());
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setLowerBound(1);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setUpperBound(1);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature);
		parameter->setName("association");
		parameter->setEType(uml::umlPackage::eInstance()->getAssociation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature);
		parameter->setName("end");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeStructuredActivityNodeActivationContent()
{
	m_structuredActivityNodeActivation_Class->setName("StructuredActivityNodeActivation");
	m_structuredActivityNodeActivation_Class->setAbstract(false);
	m_structuredActivityNodeActivation_Class->setInterface(false);
	
	
	m_structuredActivityNodeActivation_Attribute_activationGroup->setName("activationGroup");
	m_structuredActivityNodeActivation_Attribute_activationGroup->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Class());
	m_structuredActivityNodeActivation_Attribute_activationGroup->setLowerBound(1);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setUpperBound(1);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setTransient(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setVolatile(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setChangeable(true);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setUnsettable(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setUnique(true);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setDerived(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setOrdered(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setContainment(true);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_structuredActivityNodeActivation_Attribute_activationGroup->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Attribute_containingNodeActivation();
		if (otherEnd != nullptr)
	    {
	   		m_structuredActivityNodeActivation_Attribute_activationGroup->setEOpposite(otherEnd);
	    }
	}
	
	m_structuredActivityNodeActivation_Operation_completeAction->setName("completeAction");
	m_structuredActivityNodeActivation_Operation_completeAction->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class());
	m_structuredActivityNodeActivation_Operation_completeAction->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_completeAction->setUpperBound(-1);
	m_structuredActivityNodeActivation_Operation_completeAction->setUnique(true);
	m_structuredActivityNodeActivation_Operation_completeAction->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setName("createEdgeInstances");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_createEdgeInstances->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setUnique(true);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setName("createNodeActivations");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_createNodeActivations->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setUnique(true);
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_doAction->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_doAction->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_doAction->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_doAction->setUnique(true);
	m_structuredActivityNodeActivation_Operation_doAction->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setName("doStructuredActivity");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_doStructuredActivity->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setUnique(true);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Class());
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setUnique(true);
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::umlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setName("getPinValues");
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setUpperBound(-1);
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setUnique(true);
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin);
		parameter->setName("pin");
		parameter->setEType(uml::umlPackage::eInstance()->getOutputPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setName("isSourceFor");
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setUnique(true);
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstance");
		parameter->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_isSuspended->setName("isSuspended");
	m_structuredActivityNodeActivation_Operation_isSuspended->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_structuredActivityNodeActivation_Operation_isSuspended->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_isSuspended->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_isSuspended->setUnique(true);
	m_structuredActivityNodeActivation_Operation_isSuspended->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setName("makeActivityNodeList");
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setEType(uml::umlPackage::eInstance()->getActivityNode_Class());
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setUpperBound(-1);
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setUnique(true);
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode);
		parameter->setName("nodes");
		parameter->setEType(uml::umlPackage::eInstance()->getExecutableNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject->setName("putPinValues");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject->setUnique(true);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_resume->setName("resume");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_resume->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_resume->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_resume->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_resume->setUnique(true);
	m_structuredActivityNodeActivation_Operation_resume->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_terminate->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_terminate->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_terminate->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_terminate->setUnique(true);
	m_structuredActivityNodeActivation_Operation_terminate->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_terminateAll->setName("terminateAll");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_terminateAll->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_terminateAll->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_terminateAll->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_terminateAll->setUnique(true);
	m_structuredActivityNodeActivation_Operation_terminateAll->setOrdered(false);
	
	
}

void ActionsPackageImpl::initializeValueSpecificationActionActivationContent()
{
	m_valueSpecificationActionActivation_Class->setName("ValueSpecificationActionActivation");
	m_valueSpecificationActionActivation_Class->setAbstract(false);
	m_valueSpecificationActionActivation_Class->setInterface(false);
	
	
	
	m_valueSpecificationActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_valueSpecificationActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_valueSpecificationActionActivation_Operation_doAction->setLowerBound(0);
	m_valueSpecificationActionActivation_Operation_doAction->setUpperBound(1);
	m_valueSpecificationActionActivation_Operation_doAction->setUnique(true);
	m_valueSpecificationActionActivation_Operation_doAction->setOrdered(true);
	
	
}

void ActionsPackageImpl::initializeValuesContent()
{
	m_values_Class->setName("Values");
	m_values_Class->setAbstract(false);
	m_values_Class->setInterface(false);
	
	m_values_Attribute_values = getValues_Attribute_values();
	m_values_Attribute_values->setName("values");
		m_values_Attribute_values->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_values_Attribute_values->setLowerBound(0);
	m_values_Attribute_values->setUpperBound(-1);
	m_values_Attribute_values->setTransient(false);
	m_values_Attribute_values->setVolatile(false);
	m_values_Attribute_values->setChangeable(true);
	m_values_Attribute_values->setUnsettable(false);
	m_values_Attribute_values->setUnique(true);
	m_values_Attribute_values->setDerived(false);
	m_values_Attribute_values->setOrdered(true);
	m_values_Attribute_values->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_values_Attribute_values->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void ActionsPackageImpl::initializeWriteStructuralFeatureActionActivationContent()
{
	m_writeStructuralFeatureActionActivation_Class->setName("WriteStructuralFeatureActionActivation");
	m_writeStructuralFeatureActionActivation_Class->setAbstract(true);
	m_writeStructuralFeatureActionActivation_Class->setInterface(false);
	
	
	
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt->setName("position");
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt->setLowerBound(1);
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt->setUpperBound(1);
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt->setUnique(true);
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt);
		parameter->setName("value");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt);
		parameter->setName("list");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt);
		parameter->setName("startAt");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializePackageEDataTypes()
{
	
}

