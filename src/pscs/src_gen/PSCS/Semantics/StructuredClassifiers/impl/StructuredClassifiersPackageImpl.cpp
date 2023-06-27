#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"

//metamodel factory
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::StructuredClassifiers;

bool StructuredClassifiersPackageImpl::isInited = false;

StructuredClassifiersPackageImpl::StructuredClassifiersPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( StructuredClassifiersFactory::eInstance()));
}

StructuredClassifiersPackageImpl::~StructuredClassifiersPackageImpl()
{
}

StructuredClassifiersPackage* StructuredClassifiersPackageImpl::create()
{
	if (isInited)
	{
		return StructuredClassifiersPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    StructuredClassifiersPackageImpl * metaModelPackage = new StructuredClassifiersPackageImpl();
    return metaModelPackage;
}

void StructuredClassifiersPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class CS_DefaultRequestPropagationStrategy
std::shared_ptr<ecore::EClass> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_DefaultRequestPropagationStrategy_Class() const
{
	return m_cS_DefaultRequestPropagationStrategy_Class;
}



std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor() const
{
	return m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor;
}

// End Class CS_DefaultRequestPropagationStrategy

// Begin Class CS_DispatchOperationOfInterfaceStrategy
std::shared_ptr<ecore::EClass> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_DispatchOperationOfInterfaceStrategy_Class() const
{
	return m_cS_DispatchOperationOfInterfaceStrategy_Class;
}



std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation() const
{
	return m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation;
}

// End Class CS_DispatchOperationOfInterfaceStrategy

// Begin Class CS_InteractionPoint
std::shared_ptr<ecore::EClass> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_InteractionPoint_Class() const
{
	return m_cS_InteractionPoint_Class;
}


std::shared_ptr<ecore::EReference> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_InteractionPoint_Attribute_definingPort() const
{
	return m_cS_InteractionPoint_Attribute_definingPort;
}
std::shared_ptr<ecore::EReference> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_InteractionPoint_Attribute_owner() const
{
	return m_cS_InteractionPoint_Attribute_owner;
}

std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier() const
{
	return m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_InteractionPoint_Operation_dispatch_Operation() const
{
	return m_cS_InteractionPoint_Operation_dispatch_Operation;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_InteractionPoint_Operation_send_EventOccurrence() const
{
	return m_cS_InteractionPoint_Operation_send_EventOccurrence;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_InteractionPoint_Operation_startBehavior_Class_ParameterValue() const
{
	return m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue;
}

// End Class CS_InteractionPoint

// Begin Class CS_Link
std::shared_ptr<ecore::EClass> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Link_Class() const
{
	return m_cS_Link_Class;
}



std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Link_Operation_getFeature_Value() const
{
	return m_cS_Link_Operation_getFeature_Value;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Link_Operation_hasValueForAFeature_Value() const
{
	return m_cS_Link_Operation_hasValueForAFeature_Value;
}

// End Class CS_Link

// Begin Class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy
std::shared_ptr<ecore::EClass> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class() const
{
	return m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class;
}



std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature() const
{
	return m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt() const
{
	return m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt;
}

// End Class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy

// Begin Class CS_Object
std::shared_ptr<ecore::EClass> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Class() const
{
	return m_cS_Object_Class;
}



std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_checkAllParents_Classifier_Classifier() const
{
	return m_cS_Object_Operation_checkAllParents_Classifier_Classifier;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_contains_Object() const
{
	return m_cS_Object_Operation_contains_Object;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_directlyContains_Object() const
{
	return m_cS_Object_Operation_directlyContains_Object;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint() const
{
	return m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_dispatchIn_Operation_Port() const
{
	return m_cS_Object_Operation_dispatchIn_Operation_Port;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint() const
{
	return m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_dispatchOut_Operation_Port() const
{
	return m_cS_Object_Operation_dispatchOut_Operation_Port;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_getDirectContainers() const
{
	return m_cS_Object_Operation_getDirectContainers;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_getFeatureValue_StructuralFeature() const
{
	return m_cS_Object_Operation_getFeatureValue_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint() const
{
	return m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_getLinks_CS_InteractionPoint() const
{
	return m_cS_Object_Operation_getLinks_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_hasValueForAFeature_Value() const
{
	return m_cS_Object_Operation_hasValueForAFeature_Value;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_isDescendant_Interface_Interface() const
{
	return m_cS_Object_Operation_isDescendant_Interface_Interface;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_isOperationProvided_Reference_Operation() const
{
	return m_cS_Object_Operation_isOperationProvided_Reference_Operation;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_isOperationRequired_Reference_Operation() const
{
	return m_cS_Object_Operation_isOperationRequired_Reference_Operation;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_realizesInterface_Class_Interface() const
{
	return m_cS_Object_Operation_realizesInterface_Class_Interface;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean() const
{
	return m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean() const
{
	return m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint() const
{
	return m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_sendIn_EventOccurrence_Port() const
{
	return m_cS_Object_Operation_sendIn_EventOccurrence_Port;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint() const
{
	return m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_sendOut_EventOccurrence_Port() const
{
	return m_cS_Object_Operation_sendOut_EventOccurrence_Port;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Object_Operation_setFeatureValue_StructuralFeature_EInt() const
{
	return m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt;
}

// End Class CS_Object

// Begin Class CS_Reference
std::shared_ptr<ecore::EClass> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Reference_Class() const
{
	return m_cS_Reference_Class;
}


std::shared_ptr<ecore::EReference> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Reference_Attribute_compositeReferent() const
{
	return m_cS_Reference_Attribute_compositeReferent;
}

std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Reference_Operation__copy() const
{
	return m_cS_Reference_Operation__copy;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint() const
{
	return m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Reference_Operation_dispatchIn_Operation_Port() const
{
	return m_cS_Reference_Operation_dispatchIn_Operation_Port;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Reference_Operation_dispatchOut_Operation_Port() const
{
	return m_cS_Reference_Operation_dispatchOut_Operation_Port;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint() const
{
	return m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint() const
{
	return m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Reference_Operation_sendIn_EventOccurrence_Port() const
{
	return m_cS_Reference_Operation_sendIn_EventOccurrence_Port;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Reference_Operation_sendOut_EventOccurrence_Port() const
{
	return m_cS_Reference_Operation_sendOut_EventOccurrence_Port;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint() const
{
	return m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint;
}

// End Class CS_Reference

// Begin Class CS_RequestPropagationStrategy
std::shared_ptr<ecore::EClass> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_RequestPropagationStrategy_Class() const
{
	return m_cS_RequestPropagationStrategy_Class;
}



std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_RequestPropagationStrategy_Operation_getName() const
{
	return m_cS_RequestPropagationStrategy_Operation_getName;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor() const
{
	return m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor;
}

// End Class CS_RequestPropagationStrategy

// Begin Class CS_StructuralFeatureOfInterfaceAccessStrategy
std::shared_ptr<ecore::EClass> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_StructuralFeatureOfInterfaceAccessStrategy_Class() const
{
	return m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class;
}



std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName() const
{
	return m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature() const
{
	return m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer() const
{
	return m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer;
}

// End Class CS_StructuralFeatureOfInterfaceAccessStrategy
std::shared_ptr<ecore::EEnum> PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_LinkKind_Class() const
{
	return m_cS_LinkKind_Class;
}

