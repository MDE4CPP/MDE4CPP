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

//metamodel factory
#include "fUML/Semantics/Actions/ActionsFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
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

