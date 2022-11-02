#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//metamodel factory
#include "fUML/Semantics/Actions/ActionsFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

bool ActionsPackageImpl::isInited = false;

ActionsPackageImpl::ActionsPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( ActionsFactory::eInstance()));
}

ActionsPackageImpl::~ActionsPackageImpl()
{
}

ActionsPackage* ActionsPackageImpl::create()
{
	if (isInited)
	{
		return ActionsPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    ActionsPackageImpl * metaModelPackage = new ActionsPackageImpl();
    return metaModelPackage;
}

void ActionsPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class ActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Class() const
{
	return m_actionActivation_Class;
}

std::shared_ptr<ecore::EAttribute> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_firing() const
{
	return m_actionActivation_Attribute_firing;
}

std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_action() const
{
	return m_actionActivation_Attribute_action;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_inputPinActivation() const
{
	return m_actionActivation_Attribute_inputPinActivation;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_outputPinActivation() const
{
	return m_actionActivation_Attribute_outputPinActivation;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_pinActivation() const
{
	return m_actionActivation_Attribute_pinActivation;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance() const
{
	return m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_addPinActivation_PinActivation() const
{
	return m_actionActivation_Operation_addPinActivation_PinActivation;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_completeAction() const
{
	return m_actionActivation_Operation_completeAction;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_createNodeActivations() const
{
	return m_actionActivation_Operation_createNodeActivations;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_doAction() const
{
	return m_actionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_fire_Token() const
{
	return m_actionActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_getTokens_InputPin() const
{
	return m_actionActivation_Operation_getTokens_InputPin;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_isFirng() const
{
	return m_actionActivation_Operation_isFirng;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_isReady() const
{
	return m_actionActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_isSourceFor_ActivityEdgeInstance() const
{
	return m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_putToken_OutputPin_EJavaObject() const
{
	return m_actionActivation_Operation_putToken_OutputPin_EJavaObject;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_putTokens_OutputPin_EJavaObject() const
{
	return m_actionActivation_Operation_putTokens_OutputPin_EJavaObject;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_retrievePinActivation_Pin() const
{
	return m_actionActivation_Operation_retrievePinActivation_Pin;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_run() const
{
	return m_actionActivation_Operation_run;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_sendOffers() const
{
	return m_actionActivation_Operation_sendOffers;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_takeOfferedTokens() const
{
	return m_actionActivation_Operation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_takeTokens_InputPin() const
{
	return m_actionActivation_Operation_takeTokens_InputPin;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_terminate() const
{
	return m_actionActivation_Operation_terminate;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_valueParticipatesInLink_EJavaObject_Element() const
{
	return m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element;
}

// End Class ActionActivation

// Begin Class AddStructuralFeatureValueActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getAddStructuralFeatureValueActionActivation_Class() const
{
	return m_addStructuralFeatureValueActionActivation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getAddStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction() const
{
	return m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getAddStructuralFeatureValueActionActivation_Operation_doAction() const
{
	return m_addStructuralFeatureValueActionActivation_Operation_doAction;
}

// End Class AddStructuralFeatureValueActionActivation

// Begin Class CallActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Class() const
{
	return m_callActionActivation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Attribute_callAction() const
{
	return m_callActionActivation_Attribute_callAction;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Operation_doAction() const
{
	return m_callActionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Operation_doCall_ParameterValue() const
{
	return m_callActionActivation_Operation_doCall_ParameterValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Operation_retrieveBehavior() const
{
	return m_callActionActivation_Operation_retrieveBehavior;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Operation_terminate() const
{
	return m_callActionActivation_Operation_terminate;
}

// End Class CallActionActivation

// Begin Class CallBehaviorActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getCallBehaviorActionActivation_Class() const
{
	return m_callBehaviorActionActivation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getCallBehaviorActionActivation_Attribute_callBehaviorAction() const
{
	return m_callBehaviorActionActivation_Attribute_callBehaviorAction;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getCallBehaviorActionActivation_Operation_doCall_ParameterValue() const
{
	return m_callBehaviorActionActivation_Operation_doCall_ParameterValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getCallBehaviorActionActivation_Operation_retrieveBehavior() const
{
	return m_callBehaviorActionActivation_Operation_retrieveBehavior;
}

// End Class CallBehaviorActionActivation

// Begin Class CallOperationActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getCallOperationActionActivation_Class() const
{
	return m_callOperationActionActivation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getCallOperationActionActivation_Attribute_callOperationAction() const
{
	return m_callOperationActionActivation_Attribute_callOperationAction;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getCallOperationActionActivation_Operation_doCall_ParameterValue() const
{
	return m_callOperationActionActivation_Operation_doCall_ParameterValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getCallOperationActionActivation_Operation_retrieveBehavior() const
{
	return m_callOperationActionActivation_Operation_retrieveBehavior;
}

// End Class CallOperationActionActivation

// Begin Class ClearStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getClearStructuralFeatureActionActivation_Class() const
{
	return m_clearStructuralFeatureActionActivation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getClearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction() const
{
	return m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getClearStructuralFeatureActionActivation_Operation_doAction() const
{
	return m_clearStructuralFeatureActionActivation_Operation_doAction;
}

// End Class ClearStructuralFeatureActionActivation

// Begin Class CreateObjectActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getCreateObjectActionActivation_Class() const
{
	return m_createObjectActionActivation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getCreateObjectActionActivation_Attribute_createObjectAction() const
{
	return m_createObjectActionActivation_Attribute_createObjectAction;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getCreateObjectActionActivation_Operation_doAction() const
{
	return m_createObjectActionActivation_Operation_doAction;
}

// End Class CreateObjectActionActivation

// Begin Class DestroyObjectActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Class() const
{
	return m_destroyObjectActionActivation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Attribute_destroyObjectAction() const
{
	return m_destroyObjectActionActivation_Attribute_destroyObjectAction;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean() const
{
	return m_destroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Operation_doAction() const
{
	return m_destroyObjectActionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Operation_objectIsComposite_Element_Element() const
{
	return m_destroyObjectActionActivation_Operation_objectIsComposite_Element_Element;
}

// End Class DestroyObjectActionActivation

// Begin Class ExpansionActivationGroup
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Class() const
{
	return m_expansionActivationGroup_Class;
}

std::shared_ptr<ecore::EAttribute> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Attribute_index() const
{
	return m_expansionActivationGroup_Attribute_index;
}

std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Attribute_groupInputs() const
{
	return m_expansionActivationGroup_Attribute_groupInputs;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Attribute_groupOutputs() const
{
	return m_expansionActivationGroup_Attribute_groupOutputs;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Attribute_regionActivation() const
{
	return m_expansionActivationGroup_Attribute_regionActivation;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Attribute_regionInputs() const
{
	return m_expansionActivationGroup_Attribute_regionInputs;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Operation_getActivityExecution() const
{
	return m_expansionActivationGroup_Operation_getActivityExecution;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Operation_getNodeActivation_ActivityNode() const
{
	return m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Operation_resume_ActivityNodeActivation() const
{
	return m_expansionActivationGroup_Operation_resume_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Operation_suspend_ActivityNodeActivation() const
{
	return m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation;
}

// End Class ExpansionActivationGroup

// Begin Class ExpansionNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionNodeActivation_Class() const
{
	return m_expansionNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionNodeActivation_Operation_fire_Token() const
{
	return m_expansionNodeActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionNodeActivation_Operation_getExpansionRegionActivation() const
{
	return m_expansionNodeActivation_Operation_getExpansionRegionActivation;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionNodeActivation_Operation_isReady() const
{
	return m_expansionNodeActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionNodeActivation_Operation_receiveOffer() const
{
	return m_expansionNodeActivation_Operation_receiveOffer;
}

// End Class ExpansionNodeActivation

// Begin Class ExpansionRegionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Class() const
{
	return m_expansionRegionActivation_Class;
}

std::shared_ptr<ecore::EAttribute> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Attribute_next() const
{
	return m_expansionRegionActivation_Attribute_next;
}

std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Attribute_activationGroups() const
{
	return m_expansionRegionActivation_Attribute_activationGroups;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Attribute_inputExpansionTokens() const
{
	return m_expansionRegionActivation_Attribute_inputExpansionTokens;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Attribute_inputTokens() const
{
	return m_expansionRegionActivation_Attribute_inputTokens;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_doAction() const
{
	return m_expansionRegionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_doOutput() const
{
	return m_expansionRegionActivation_Operation_doOutput;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_doStructuredActivity() const
{
	return m_expansionRegionActivation_Operation_doStructuredActivity;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode() const
{
	return m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_isSuspended() const
{
	return m_expansionRegionActivation_Operation_isSuspended;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_numberOfValues() const
{
	return m_expansionRegionActivation_Operation_numberOfValues;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_resume_ExpansionActivationGroup() const
{
	return m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_runGroup_ExpansionActivationGroup() const
{
	return m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_runIterative() const
{
	return m_expansionRegionActivation_Operation_runIterative;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_runParallel() const
{
	return m_expansionRegionActivation_Operation_runParallel;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_sendOffers() const
{
	return m_expansionRegionActivation_Operation_sendOffers;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_takeOfferedTokens() const
{
	return m_expansionRegionActivation_Operation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_terminate() const
{
	return m_expansionRegionActivation_Operation_terminate;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup() const
{
	return m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup;
}

// End Class ExpansionRegionActivation

// Begin Class InputPinActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getInputPinActivation_Class() const
{
	return m_inputPinActivation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getInputPinActivation_Operation_isReady() const
{
	return m_inputPinActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getInputPinActivation_Operation_receiveOffer() const
{
	return m_inputPinActivation_Operation_receiveOffer;
}

// End Class InputPinActivation

// Begin Class InvocationActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getInvocationActionActivation_Class() const
{
	return m_invocationActionActivation_Class;
}




// End Class InvocationActionActivation

// Begin Class OutputPinActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getOutputPinActivation_Class() const
{
	return m_outputPinActivation_Class;
}




// End Class OutputPinActivation

// Begin Class PinActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Class() const
{
	return m_pinActivation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Attribute_actionActivation() const
{
	return m_pinActivation_Attribute_actionActivation;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Attribute_pin() const
{
	return m_pinActivation_Attribute_pin;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Operation_fire_Token() const
{
	return m_pinActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Operation_takeOfferedTokens() const
{
	return m_pinActivation_Operation_takeOfferedTokens;
}

// End Class PinActivation

// Begin Class ReadSelfActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getReadSelfActionActivation_Class() const
{
	return m_readSelfActionActivation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getReadSelfActionActivation_Attribute_readSelfAction() const
{
	return m_readSelfActionActivation_Attribute_readSelfAction;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getReadSelfActionActivation_Operation_doAction() const
{
	return m_readSelfActionActivation_Operation_doAction;
}

// End Class ReadSelfActionActivation

// Begin Class ReadStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getReadStructuralFeatureActionActivation_Class() const
{
	return m_readStructuralFeatureActionActivation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getReadStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction() const
{
	return m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getReadStructuralFeatureActionActivation_Operation_doAction() const
{
	return m_readStructuralFeatureActionActivation_Operation_doAction;
}

// End Class ReadStructuralFeatureActionActivation

// Begin Class RemoveStructuralFeatureValueActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getRemoveStructuralFeatureValueActionActivation_Class() const
{
	return m_removeStructuralFeatureValueActionActivation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getRemoveStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction() const
{
	return m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getRemoveStructuralFeatureValueActionActivation_Operation_doAction() const
{
	return m_removeStructuralFeatureValueActionActivation_Operation_doAction;
}

// End Class RemoveStructuralFeatureValueActionActivation

// Begin Class StructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Class() const
{
	return m_structuralFeatureActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getAssociation_StructuralFeature() const
{
	return m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject() const
{
	return m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject() const
{
	return m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature() const
{
	return m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature;
}

// End Class StructuralFeatureActionActivation

// Begin Class StructuredActivityNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Class() const
{
	return m_structuredActivityNodeActivation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Attribute_activationGroup() const
{
	return m_structuredActivityNodeActivation_Attribute_activationGroup;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_completeAction() const
{
	return m_structuredActivityNodeActivation_Operation_completeAction;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_createEdgeInstances() const
{
	return m_structuredActivityNodeActivation_Operation_createEdgeInstances;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_createNodeActivations() const
{
	return m_structuredActivityNodeActivation_Operation_createNodeActivations;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_doAction() const
{
	return m_structuredActivityNodeActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_doStructuredActivity() const
{
	return m_structuredActivityNodeActivation_Operation_doStructuredActivity;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode() const
{
	return m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_getPinValues_OutputPin() const
{
	return m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance() const
{
	return m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_isSuspended() const
{
	return m_structuredActivityNodeActivation_Operation_isSuspended;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode() const
{
	return m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject() const
{
	return m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_resume() const
{
	return m_structuredActivityNodeActivation_Operation_resume;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_terminate() const
{
	return m_structuredActivityNodeActivation_Operation_terminate;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_terminateAll() const
{
	return m_structuredActivityNodeActivation_Operation_terminateAll;
}

// End Class StructuredActivityNodeActivation

// Begin Class ValueSpecificationActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getValueSpecificationActionActivation_Class() const
{
	return m_valueSpecificationActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getValueSpecificationActionActivation_Operation_doAction() const
{
	return m_valueSpecificationActionActivation_Operation_doAction;
}

// End Class ValueSpecificationActionActivation

// Begin Class Values
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getValues_Class() const
{
	return m_values_Class;
}

std::shared_ptr<ecore::EAttribute> fUML::Semantics::Actions::ActionsPackageImpl::getValues_Attribute_values() const
{
	return m_values_Attribute_values;
}



// End Class Values

// Begin Class WriteStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Actions::ActionsPackageImpl::getWriteStructuralFeatureActionActivation_Class() const
{
	return m_writeStructuralFeatureActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Actions::ActionsPackageImpl::getWriteStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt() const
{
	return m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt;
}

// End Class WriteStructuralFeatureActionActivation

