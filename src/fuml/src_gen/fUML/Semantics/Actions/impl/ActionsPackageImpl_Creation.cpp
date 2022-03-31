#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

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

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace fUML::Semantics::Actions;

void ActionsPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createActionActivationContent(package, factory);
	createAddStructuralFeatureValueActionActivationContent(package, factory);
	createClearStructuralFeatureActionActivationContent(package, factory);
	createCreateObjectActionActivationContent(package, factory);
	createInputPinActivationContent(package, factory);
	createOutputPinActivationContent(package, factory);
	createPinActivationContent(package, factory);
	createReadSelfActionActivationContent(package, factory);
	createStructuralFeatureActionActivationContent(package, factory);
	createValueSpecificationActionActivationContent(package, factory);
	createValuesContent(package, factory);
	createWriteStructuralFeatureActionActivationContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ActionsPackageImpl::createActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_actionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIONACTIVATION_CLASS);
	m_actionActivation_Attribute_firing = factory->createEAttribute_as_eAttributes_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_ATTRIBUTE_FIRING);
	
	m_actionActivation_Attribute_action = factory->createEReference_as_eReferences_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_ATTRIBUTE_ACTION);
	m_actionActivation_Attribute_inputPinActivation = factory->createEReference_as_eReferences_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION);
	m_actionActivation_Attribute_outputPinActivation = factory->createEReference_as_eReferences_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION);
	m_actionActivation_Attribute_pinActivation = factory->createEReference_as_eReferences_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_ATTRIBUTE_PINACTIVATION);
	
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ADDOUTGOINGEDGE_ACTIVITYEDGEINSTANCE);
	m_actionActivation_Operation_addPinActivation_PinActivation = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ADDPINACTIVATION_PINACTIVATION);
	m_actionActivation_Operation_completeAction = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_COMPLETEACTION);
	m_actionActivation_Operation_createNodeActivations = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_CREATENODEACTIVATIONS);
	m_actionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_DOACTION);
	m_actionActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_FIRE_TOKEN);
	m_actionActivation_Operation_getTokens_InputPin = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_GETTOKENS_INPUTPIN);
	m_actionActivation_Operation_isFirng = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ISFIRNG);
	m_actionActivation_Operation_isReady = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ISREADY);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE);
	m_actionActivation_Operation_putToken_OutputPin_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_PUTTOKEN_OUTPUTPIN_EJAVAOBJECT);
	m_actionActivation_Operation_putTokens_OutputPin_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_PUTTOKENS_OUTPUTPIN_EJAVAOBJECT);
	m_actionActivation_Operation_retrievePinActivation_Pin = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_RETRIEVEPINACTIVATION_PIN);
	m_actionActivation_Operation_run = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_RUN);
	m_actionActivation_Operation_sendOffers = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_SENDOFFERS);
	m_actionActivation_Operation_takeOfferedTokens = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	m_actionActivation_Operation_takeTokens_InputPin = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_TAKETOKENS_INPUTPIN);
	m_actionActivation_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_TERMINATE);
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_VALUEPARTICIPATESINLINK_EJAVAOBJECT_ELEMENT);
	
}

void ActionsPackageImpl::createAddStructuralFeatureValueActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_addStructuralFeatureValueActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS);
	
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction = factory->createEReference_as_eReferences_in_EClass(m_addStructuralFeatureValueActionActivation_Class, ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION);
	
	m_addStructuralFeatureValueActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_addStructuralFeatureValueActionActivation_Class, ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createClearStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_clearStructuralFeatureActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction = factory->createEReference_as_eReferences_in_EClass(m_clearStructuralFeatureActionActivation_Class, CLEARSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION);
	
	m_clearStructuralFeatureActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_clearStructuralFeatureActionActivation_Class, CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createCreateObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_createObjectActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CREATEOBJECTACTIONACTIVATION_CLASS);
	
	m_createObjectActionActivation_Attribute_createObjectAction = factory->createEReference_as_eReferences_in_EClass(m_createObjectActionActivation_Class, CREATEOBJECTACTIONACTIVATION_ATTRIBUTE_CREATEOBJECTACTION);
	
	m_createObjectActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_createObjectActionActivation_Class, CREATEOBJECTACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createInputPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_inputPinActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INPUTPINACTIVATION_CLASS);
	
	
	m_inputPinActivation_Operation_isReady = factory->createEOperation_as_eOperations_in_EClass(m_inputPinActivation_Class, INPUTPINACTIVATION_OPERATION_ISREADY);
	m_inputPinActivation_Operation_receiveOffer = factory->createEOperation_as_eOperations_in_EClass(m_inputPinActivation_Class, INPUTPINACTIVATION_OPERATION_RECEIVEOFFER);
	
}

void ActionsPackageImpl::createOutputPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_outputPinActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OUTPUTPINACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_pinActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PINACTIVATION_CLASS);
	
	m_pinActivation_Attribute_actionActivation = factory->createEReference_as_eReferences_in_EClass(m_pinActivation_Class, PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION);
	m_pinActivation_Attribute_pin = factory->createEReference_as_eReferences_in_EClass(m_pinActivation_Class, PINACTIVATION_ATTRIBUTE_PIN);
	
	m_pinActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_pinActivation_Class, PINACTIVATION_OPERATION_FIRE_TOKEN);
	m_pinActivation_Operation_takeOfferedTokens = factory->createEOperation_as_eOperations_in_EClass(m_pinActivation_Class, PINACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	
}

void ActionsPackageImpl::createReadSelfActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_readSelfActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, READSELFACTIONACTIVATION_CLASS);
	
	m_readSelfActionActivation_Attribute_readSelfAction = factory->createEReference_as_eReferences_in_EClass(m_readSelfActionActivation_Class, READSELFACTIONACTIVATION_ATTRIBUTE_READSELFACTION);
	
	m_readSelfActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_readSelfActionActivation_Class, READSELFACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_structuralFeatureActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature = factory->createEOperation_as_eOperations_in_EClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETASSOCIATION_STRUCTURALFEATURE);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKS_ASSOCIATION_EJAVAOBJECT);
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKSFORENDVALUE_ASSOCIATION_EJAVAOBJECT);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature = factory->createEOperation_as_eOperations_in_EClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETOPPOSITEEND_ASSOCIATION_STRUCTURALFEATURE);
	
}

void ActionsPackageImpl::createValueSpecificationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_valueSpecificationActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VALUESPECIFICATIONACTIONACTIVATION_CLASS);
	
	
	m_valueSpecificationActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_valueSpecificationActionActivation_Class, VALUESPECIFICATIONACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createValuesContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_values_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VALUES_CLASS);
	m_values_Attribute_values = factory->createEAttribute_as_eAttributes_in_EClass(m_values_Class, VALUES_ATTRIBUTE_VALUES);
	
	
	
}

void ActionsPackageImpl::createWriteStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_writeStructuralFeatureActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, WRITESTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt = factory->createEOperation_as_eOperations_in_EClass(m_writeStructuralFeatureActionActivation_Class, WRITESTRUCTURALFEATUREACTIONACTIVATION_OPERATION_POSITION_EJAVAOBJECT_EINT);
	
}

void ActionsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
