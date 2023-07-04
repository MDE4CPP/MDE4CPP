#include "PSCS/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"

//metamodel factory
#include "PSCS/Semantics/Actions/ActionsFactory.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::Actions;

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



// Begin Class CS_AcceptCallActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_AcceptCallActionActivation_Class() const
{
	return m_cS_AcceptCallActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_AcceptCallActionActivation_Operation_accept_EventOccurrence() const
{
	return m_cS_AcceptCallActionActivation_Operation_accept_EventOccurrence;
}

// End Class CS_AcceptCallActionActivation

// Begin Class CS_AcceptEventActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_AcceptEventActionActivation_Class() const
{
	return m_cS_AcceptEventActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_AcceptEventActionActivation_Operation_accept_EventOccurrence() const
{
	return m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence;
}

// End Class CS_AcceptEventActionActivation

// Begin Class CS_AddStructuralFeatureValueActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_AddStructuralFeatureValueActionActivation_Class() const
{
	return m_cS_AddStructuralFeatureValueActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_AddStructuralFeatureValueActionActivation_Operation_doAction() const
{
	return m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault() const
{
	return m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault;
}

// End Class CS_AddStructuralFeatureValueActionActivation

// Begin Class CS_CallOperationActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CallOperationActionActivation_Class() const
{
	return m_cS_CallOperationActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CallOperationActionActivation_Operation__isCreate_Operation() const
{
	return m_cS_CallOperationActionActivation_Operation__isCreate_Operation;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CallOperationActionActivation_Operation_doAction() const
{
	return m_cS_CallOperationActionActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CallOperationActionActivation_Operation_getCallExecution() const
{
	return m_cS_CallOperationActionActivation_Operation_getCallExecution;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CallOperationActionActivation_Operation_isCreate_Operation() const
{
	return m_cS_CallOperationActionActivation_Operation_isCreate_Operation;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation() const
{
	return m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation() const
{
	return m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation;
}

// End Class CS_CallOperationActionActivation

// Begin Class CS_ClearStructuralFeatureActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ClearStructuralFeatureActionActivation_Class() const
{
	return m_cS_ClearStructuralFeatureActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ClearStructuralFeatureActionActivation_Operation_doAction() const
{
	return m_cS_ClearStructuralFeatureActionActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature() const
{
	return m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature() const
{
	return m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature;
}

// End Class CS_ClearStructuralFeatureActionActivation

// Begin Class CS_ConstructStrategy
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ConstructStrategy_Class() const
{
	return m_cS_ConstructStrategy_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ConstructStrategy_Operation_construct_Operation_CS_Object() const
{
	return m_cS_ConstructStrategy_Operation_construct_Operation_CS_Object;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ConstructStrategy_Operation_getName() const
{
	return m_cS_ConstructStrategy_Operation_getName;
}

// End Class CS_ConstructStrategy

// Begin Class CS_CreateLinkActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CreateLinkActionActivation_Class() const
{
	return m_cS_CreateLinkActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CreateLinkActionActivation_Operation_doAction() const
{
	return m_cS_CreateLinkActionActivation_Operation_doAction;
}

// End Class CS_CreateLinkActionActivation

// Begin Class CS_CreateObjectActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CreateObjectActionActivation_Class() const
{
	return m_cS_CreateObjectActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CreateObjectActionActivation_Operation_doAction() const
{
	return m_cS_CreateObjectActionActivation_Operation_doAction;
}

// End Class CS_CreateObjectActionActivation

// Begin Class CS_DefaultConstructStrategy
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Class() const
{
	return m_cS_DefaultConstructStrategy_Class;
}


const std::shared_ptr<ecore::EReference>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Attribute_defaultAssociation() const
{
	return m_cS_DefaultConstructStrategy_Attribute_defaultAssociation;
}
const std::shared_ptr<ecore::EReference>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Attribute_generatedRealizingClasses() const
{
	return m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses;
}
const std::shared_ptr<ecore::EReference>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Attribute_locus() const
{
	return m_cS_DefaultConstructStrategy_Attribute_locus;
}

const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value() const
{
	return m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Operation_canInstantiate_Property() const
{
	return m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object() const
{
	return m_cS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class() const
{
	return m_cS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector() const
{
	return m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString() const
{
	return m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector() const
{
	return m_cS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd() const
{
	return m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Operation_getDefaultAssociation() const
{
	return m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Operation_getRealizingClass_Interface() const
{
	return m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd() const
{
	return m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus() const
{
	return m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Operation_isArrayPattern_Connector() const
{
	return m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_DefaultConstructStrategy_Operation_isStarPattern_Connector() const
{
	return m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector;
}

// End Class CS_DefaultConstructStrategy

// Begin Class CS_ReadExtentActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ReadExtentActionActivation_Class() const
{
	return m_cS_ReadExtentActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ReadExtentActionActivation_Operation_doAction() const
{
	return m_cS_ReadExtentActionActivation_Operation_doAction;
}

// End Class CS_ReadExtentActionActivation

// Begin Class CS_ReadSelfActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ReadSelfActionActivation_Class() const
{
	return m_cS_ReadSelfActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ReadSelfActionActivation_Operation_doAction() const
{
	return m_cS_ReadSelfActionActivation_Operation_doAction;
}

// End Class CS_ReadSelfActionActivation

// Begin Class CS_RemoveStructuralFeatureValueActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_RemoveStructuralFeatureValueActionActivation_Class() const
{
	return m_cS_RemoveStructuralFeatureValueActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_RemoveStructuralFeatureValueActionActivation_Operation_doAction() const
{
	return m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value() const
{
	return m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature() const
{
	return m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature;
}

// End Class CS_RemoveStructuralFeatureValueActionActivation

// Begin Class CS_SendSignalActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_SendSignalActionActivation_Class() const
{
	return m_cS_SendSignalActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_SendSignalActionActivation_Operation_doAction() const
{
	return m_cS_SendSignalActionActivation_Operation_doAction;
}

// End Class CS_SendSignalActionActivation

