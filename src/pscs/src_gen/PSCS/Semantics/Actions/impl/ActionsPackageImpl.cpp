#include "PSCS/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "PSCS/Semantics/Actions/ActionsFactory.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::Actions;

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
const std::string ActionsPackage::eNS_URI ="http:///PSCS_Semantics/Semantics/Actions.ecore";
const std::string ActionsPackage::eNS_PREFIX ="PSCS_Semantics.Semantics.Actions";

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
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CallOperationActionActivation_Operation_doCall_ParameterValue() const
{
	return m_cS_CallOperationActionActivation_Operation_doCall_ParameterValue;
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
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature() const
{
	return m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature() const
{
	return m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature;
}

// End Class CS_ClearStructuralFeatureActionActivation

// Begin Class CS_ConstructStrategy
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ConstructStrategy_Class() const
{
	return m_cS_ConstructStrategy_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ConstructStrategy_Operation_construct_Operation_PSCS_Object() const
{
	return m_cS_ConstructStrategy_Operation_construct_Operation_PSCS_Object;
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
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature_EJavaObject() const
{
	return m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature() const
{
	return m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature;
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

