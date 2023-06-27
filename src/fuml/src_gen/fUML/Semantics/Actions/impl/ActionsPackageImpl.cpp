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

//Singleton implementation 
std::shared_ptr<ActionsPackage> ActionsPackage::eInstance()
{
	static std::shared_ptr<ActionsPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ActionsPackageImpl::create());
		std::dynamic_pointer_cast<ActionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string ActionsPackage::eNAME ="Actions";
const std::string ActionsPackage::eNS_URI ="http:///fUML_Semantics/Semantics/Actions.ecore";
const std::string ActionsPackage::eNS_PREFIX ="fUML_Semantics.Semantics.Actions";

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



// Begin Class AcceptEventActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Class() const
{
	return m_acceptEventActionActivation_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Attribute_waiting() const
{
	return m_acceptEventActionActivation_Attribute_waiting;
}

const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Attribute_acceptEventAction() const
{
	return m_acceptEventActionActivation_Attribute_acceptEventAction;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Attribute_eventAccepter() const
{
	return m_acceptEventActionActivation_Attribute_eventAccepter;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_accept_EventOccurrence() const
{
	return m_acceptEventActionActivation_Operation_accept_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_doAction() const
{
	return m_acceptEventActionActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_fire_Token() const
{
	return m_acceptEventActionActivation_Operation_fire_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup() const
{
	return m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_isReady() const
{
	return m_acceptEventActionActivation_Operation_isReady;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_match_EventOccurrence() const
{
	return m_acceptEventActionActivation_Operation_match_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_run() const
{
	return m_acceptEventActionActivation_Operation_run;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_terminate() const
{
	return m_acceptEventActionActivation_Operation_terminate;
}

// End Class AcceptEventActionActivation

// Begin Class AcceptEventActionEventAccepter
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionEventAccepter_Class() const
{
	return m_acceptEventActionEventAccepter_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionEventAccepter_Attribute_actionActivation() const
{
	return m_acceptEventActionEventAccepter_Attribute_actionActivation;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionEventAccepter_Operation_accept_EventOccurrence() const
{
	return m_acceptEventActionEventAccepter_Operation_accept_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionEventAccepter_Operation_match_EventOccurrence() const
{
	return m_acceptEventActionEventAccepter_Operation_match_EventOccurrence;
}

// End Class AcceptEventActionEventAccepter

// Begin Class ActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Class() const
{
	return m_actionActivation_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_firing() const
{
	return m_actionActivation_Attribute_firing;
}

const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_action() const
{
	return m_actionActivation_Attribute_action;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_inputPinActivation() const
{
	return m_actionActivation_Attribute_inputPinActivation;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_outputPinActivation() const
{
	return m_actionActivation_Attribute_outputPinActivation;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_pinActivation() const
{
	return m_actionActivation_Attribute_pinActivation;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance() const
{
	return m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_addPinActivation_PinActivation() const
{
	return m_actionActivation_Operation_addPinActivation_PinActivation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_completeAction() const
{
	return m_actionActivation_Operation_completeAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_createNodeActivations() const
{
	return m_actionActivation_Operation_createNodeActivations;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_doAction() const
{
	return m_actionActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_fire_Token() const
{
	return m_actionActivation_Operation_fire_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_getTokens_InputPin() const
{
	return m_actionActivation_Operation_getTokens_InputPin;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_isFirng() const
{
	return m_actionActivation_Operation_isFirng;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_isReady() const
{
	return m_actionActivation_Operation_isReady;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_isSourceFor_ActivityEdgeInstance() const
{
	return m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_putToken_OutputPin_EJavaObject() const
{
	return m_actionActivation_Operation_putToken_OutputPin_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_putTokens_OutputPin_EJavaObject() const
{
	return m_actionActivation_Operation_putTokens_OutputPin_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_retrievePinActivation_Pin() const
{
	return m_actionActivation_Operation_retrievePinActivation_Pin;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_run() const
{
	return m_actionActivation_Operation_run;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_sendOffers() const
{
	return m_actionActivation_Operation_sendOffers;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_takeOfferedTokens() const
{
	return m_actionActivation_Operation_takeOfferedTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_takeTokens_InputPin() const
{
	return m_actionActivation_Operation_takeTokens_InputPin;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_terminate() const
{
	return m_actionActivation_Operation_terminate;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_valueParticipatesInLink_EJavaObject_Element() const
{
	return m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element;
}

// End Class ActionActivation

// Begin Class AddStructuralFeatureValueActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getAddStructuralFeatureValueActionActivation_Class() const
{
	return m_addStructuralFeatureValueActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getAddStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction() const
{
	return m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAddStructuralFeatureValueActionActivation_Operation_doAction() const
{
	return m_addStructuralFeatureValueActionActivation_Operation_doAction;
}

// End Class AddStructuralFeatureValueActionActivation

// Begin Class CallActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Class() const
{
	return m_callActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Attribute_callAction() const
{
	return m_callActionActivation_Attribute_callAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Operation_doAction() const
{
	return m_callActionActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Operation_doCall_ParameterValue() const
{
	return m_callActionActivation_Operation_doCall_ParameterValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Operation_retrieveCallParameters() const
{
	return m_callActionActivation_Operation_retrieveCallParameters;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Operation_terminate() const
{
	return m_callActionActivation_Operation_terminate;
}

// End Class CallActionActivation

// Begin Class CallBehaviorActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getCallBehaviorActionActivation_Class() const
{
	return m_callBehaviorActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getCallBehaviorActionActivation_Attribute_callBehaviorAction() const
{
	return m_callBehaviorActionActivation_Attribute_callBehaviorAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallBehaviorActionActivation_Operation_doCall_ParameterValue() const
{
	return m_callBehaviorActionActivation_Operation_doCall_ParameterValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallBehaviorActionActivation_Operation_retrieveBehavior() const
{
	return m_callBehaviorActionActivation_Operation_retrieveBehavior;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallBehaviorActionActivation_Operation_retrieveCallParameters() const
{
	return m_callBehaviorActionActivation_Operation_retrieveCallParameters;
}

// End Class CallBehaviorActionActivation

// Begin Class CallOperationActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getCallOperationActionActivation_Class() const
{
	return m_callOperationActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getCallOperationActionActivation_Attribute_callOperationAction() const
{
	return m_callOperationActionActivation_Attribute_callOperationAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallOperationActionActivation_Operation_doCall_ParameterValue() const
{
	return m_callOperationActionActivation_Operation_doCall_ParameterValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallOperationActionActivation_Operation_retrieveBehavior() const
{
	return m_callOperationActionActivation_Operation_retrieveBehavior;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallOperationActionActivation_Operation_retrieveCallParameters() const
{
	return m_callOperationActionActivation_Operation_retrieveCallParameters;
}

// End Class CallOperationActionActivation

// Begin Class ClearStructuralFeatureActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getClearStructuralFeatureActionActivation_Class() const
{
	return m_clearStructuralFeatureActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getClearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction() const
{
	return m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getClearStructuralFeatureActionActivation_Operation_doAction() const
{
	return m_clearStructuralFeatureActionActivation_Operation_doAction;
}

// End Class ClearStructuralFeatureActionActivation

// Begin Class CreateObjectActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getCreateObjectActionActivation_Class() const
{
	return m_createObjectActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getCreateObjectActionActivation_Attribute_createObjectAction() const
{
	return m_createObjectActionActivation_Attribute_createObjectAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCreateObjectActionActivation_Operation_doAction() const
{
	return m_createObjectActionActivation_Operation_doAction;
}

// End Class CreateObjectActionActivation

// Begin Class DestroyObjectActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Class() const
{
	return m_destroyObjectActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Attribute_destroyObjectAction() const
{
	return m_destroyObjectActionActivation_Attribute_destroyObjectAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean() const
{
	return m_destroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Operation_doAction() const
{
	return m_destroyObjectActionActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Operation_objectIsComposite_Element_Element() const
{
	return m_destroyObjectActionActivation_Operation_objectIsComposite_Element_Element;
}

// End Class DestroyObjectActionActivation

// Begin Class ExpansionActivationGroup
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Class() const
{
	return m_expansionActivationGroup_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Attribute_index() const
{
	return m_expansionActivationGroup_Attribute_index;
}

const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Attribute_groupInputs() const
{
	return m_expansionActivationGroup_Attribute_groupInputs;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Attribute_groupOutputs() const
{
	return m_expansionActivationGroup_Attribute_groupOutputs;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Attribute_regionActivation() const
{
	return m_expansionActivationGroup_Attribute_regionActivation;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Attribute_regionInputs() const
{
	return m_expansionActivationGroup_Attribute_regionInputs;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Operation_getActivityExecution() const
{
	return m_expansionActivationGroup_Operation_getActivityExecution;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Operation_getNodeActivation_ActivityNode() const
{
	return m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Operation_resume_ActivityNodeActivation() const
{
	return m_expansionActivationGroup_Operation_resume_ActivityNodeActivation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionActivationGroup_Operation_suspend_ActivityNodeActivation() const
{
	return m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation;
}

// End Class ExpansionActivationGroup

// Begin Class ExpansionNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionNodeActivation_Class() const
{
	return m_expansionNodeActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionNodeActivation_Operation_fire_Token() const
{
	return m_expansionNodeActivation_Operation_fire_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionNodeActivation_Operation_getExpansionRegionActivation() const
{
	return m_expansionNodeActivation_Operation_getExpansionRegionActivation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionNodeActivation_Operation_isReady() const
{
	return m_expansionNodeActivation_Operation_isReady;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionNodeActivation_Operation_receiveOffer() const
{
	return m_expansionNodeActivation_Operation_receiveOffer;
}

// End Class ExpansionNodeActivation

// Begin Class ExpansionRegionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Class() const
{
	return m_expansionRegionActivation_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Attribute_next() const
{
	return m_expansionRegionActivation_Attribute_next;
}

const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Attribute_activationGroups() const
{
	return m_expansionRegionActivation_Attribute_activationGroups;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Attribute_inputExpansionTokens() const
{
	return m_expansionRegionActivation_Attribute_inputExpansionTokens;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Attribute_inputTokens() const
{
	return m_expansionRegionActivation_Attribute_inputTokens;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_doAction() const
{
	return m_expansionRegionActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_doOutput() const
{
	return m_expansionRegionActivation_Operation_doOutput;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_doStructuredActivity() const
{
	return m_expansionRegionActivation_Operation_doStructuredActivity;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode() const
{
	return m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_isSuspended() const
{
	return m_expansionRegionActivation_Operation_isSuspended;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_numberOfValues() const
{
	return m_expansionRegionActivation_Operation_numberOfValues;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_resume_ExpansionActivationGroup() const
{
	return m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_runGroup_ExpansionActivationGroup() const
{
	return m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_runIterative() const
{
	return m_expansionRegionActivation_Operation_runIterative;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_runParallel() const
{
	return m_expansionRegionActivation_Operation_runParallel;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_sendOffers() const
{
	return m_expansionRegionActivation_Operation_sendOffers;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_takeOfferedTokens() const
{
	return m_expansionRegionActivation_Operation_takeOfferedTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_terminate() const
{
	return m_expansionRegionActivation_Operation_terminate;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getExpansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup() const
{
	return m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup;
}

// End Class ExpansionRegionActivation

// Begin Class InputPinActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getInputPinActivation_Class() const
{
	return m_inputPinActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getInputPinActivation_Operation_isReady() const
{
	return m_inputPinActivation_Operation_isReady;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getInputPinActivation_Operation_receiveOffer() const
{
	return m_inputPinActivation_Operation_receiveOffer;
}

// End Class InputPinActivation

// Begin Class InvocationActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getInvocationActionActivation_Class() const
{
	return m_invocationActionActivation_Class;
}




// End Class InvocationActionActivation

// Begin Class OutputPinActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getOutputPinActivation_Class() const
{
	return m_outputPinActivation_Class;
}




// End Class OutputPinActivation

// Begin Class PinActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Class() const
{
	return m_pinActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Attribute_actionActivation() const
{
	return m_pinActivation_Attribute_actionActivation;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Attribute_pin() const
{
	return m_pinActivation_Attribute_pin;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Operation_fire_Token() const
{
	return m_pinActivation_Operation_fire_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Operation_takeOfferedTokens() const
{
	return m_pinActivation_Operation_takeOfferedTokens;
}

// End Class PinActivation

// Begin Class ReadExtentActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getReadExtentActionActivation_Class() const
{
	return m_readExtentActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getReadExtentActionActivation_Attribute_readExtentAction() const
{
	return m_readExtentActionActivation_Attribute_readExtentAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReadExtentActionActivation_Operation_doAction() const
{
	return m_readExtentActionActivation_Operation_doAction;
}

// End Class ReadExtentActionActivation

// Begin Class ReadIsClassifiedObjectActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getReadIsClassifiedObjectActionActivation_Class() const
{
	return m_readIsClassifiedObjectActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getReadIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction() const
{
	return m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReadIsClassifiedObjectActionActivation_Operation_doAction() const
{
	return m_readIsClassifiedObjectActionActivation_Operation_doAction;
}

// End Class ReadIsClassifiedObjectActionActivation

// Begin Class ReadSelfActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getReadSelfActionActivation_Class() const
{
	return m_readSelfActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getReadSelfActionActivation_Attribute_readSelfAction() const
{
	return m_readSelfActionActivation_Attribute_readSelfAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReadSelfActionActivation_Operation_doAction() const
{
	return m_readSelfActionActivation_Operation_doAction;
}

// End Class ReadSelfActionActivation

// Begin Class ReadStructuralFeatureActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getReadStructuralFeatureActionActivation_Class() const
{
	return m_readStructuralFeatureActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getReadStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction() const
{
	return m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReadStructuralFeatureActionActivation_Operation_doAction() const
{
	return m_readStructuralFeatureActionActivation_Operation_doAction;
}

// End Class ReadStructuralFeatureActionActivation

// Begin Class RemoveStructuralFeatureValueActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getRemoveStructuralFeatureValueActionActivation_Class() const
{
	return m_removeStructuralFeatureValueActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getRemoveStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction() const
{
	return m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getRemoveStructuralFeatureValueActionActivation_Operation_doAction() const
{
	return m_removeStructuralFeatureValueActionActivation_Operation_doAction;
}

// End Class RemoveStructuralFeatureValueActionActivation

// Begin Class SendSignalActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getSendSignalActionActivation_Class() const
{
	return m_sendSignalActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getSendSignalActionActivation_Attribute_sendSignalAction() const
{
	return m_sendSignalActionActivation_Attribute_sendSignalAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getSendSignalActionActivation_Operation_doAction() const
{
	return m_sendSignalActionActivation_Operation_doAction;
}

// End Class SendSignalActionActivation

// Begin Class StructuralFeatureActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Class() const
{
	return m_structuralFeatureActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getAssociation_StructuralFeature() const
{
	return m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject() const
{
	return m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject() const
{
	return m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature() const
{
	return m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature;
}

// End Class StructuralFeatureActionActivation

// Begin Class StructuredActivityNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Class() const
{
	return m_structuredActivityNodeActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Attribute_activationGroup() const
{
	return m_structuredActivityNodeActivation_Attribute_activationGroup;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_completeAction() const
{
	return m_structuredActivityNodeActivation_Operation_completeAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_createEdgeInstances() const
{
	return m_structuredActivityNodeActivation_Operation_createEdgeInstances;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_createNodeActivations() const
{
	return m_structuredActivityNodeActivation_Operation_createNodeActivations;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_doAction() const
{
	return m_structuredActivityNodeActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_doStructuredActivity() const
{
	return m_structuredActivityNodeActivation_Operation_doStructuredActivity;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode() const
{
	return m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_getPinValues_OutputPin() const
{
	return m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance() const
{
	return m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_isSuspended() const
{
	return m_structuredActivityNodeActivation_Operation_isSuspended;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode() const
{
	return m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject() const
{
	return m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_resume() const
{
	return m_structuredActivityNodeActivation_Operation_resume;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_terminate() const
{
	return m_structuredActivityNodeActivation_Operation_terminate;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_terminateAll() const
{
	return m_structuredActivityNodeActivation_Operation_terminateAll;
}

// End Class StructuredActivityNodeActivation

// Begin Class ValueSpecificationActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getValueSpecificationActionActivation_Class() const
{
	return m_valueSpecificationActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getValueSpecificationActionActivation_Operation_doAction() const
{
	return m_valueSpecificationActionActivation_Operation_doAction;
}

// End Class ValueSpecificationActionActivation

// Begin Class Values
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getValues_Class() const
{
	return m_values_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::Actions::ActionsPackageImpl::getValues_Attribute_values() const
{
	return m_values_Attribute_values;
}



// End Class Values

// Begin Class WriteStructuralFeatureActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getWriteStructuralFeatureActionActivation_Class() const
{
	return m_writeStructuralFeatureActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getWriteStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt() const
{
	return m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt;
}

// End Class WriteStructuralFeatureActionActivation

