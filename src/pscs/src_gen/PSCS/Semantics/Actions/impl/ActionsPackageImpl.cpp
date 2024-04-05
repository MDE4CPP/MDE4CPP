#include "PSCS/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"

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




// End Class CS_AcceptEventActionActivation

// Begin Class CS_AddStructuralFeatureValueActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_AddStructuralFeatureValueActionActivation_Class() const
{
	return m_cS_AddStructuralFeatureValueActionActivation_Class;
}




// End Class CS_AddStructuralFeatureValueActionActivation

// Begin Class CS_CallOperationActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CallOperationActionActivation_Class() const
{
	return m_cS_CallOperationActionActivation_Class;
}




// End Class CS_CallOperationActionActivation

// Begin Class CS_ClearStructuralFeatureActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ClearStructuralFeatureActionActivation_Class() const
{
	return m_cS_ClearStructuralFeatureActionActivation_Class;
}




// End Class CS_ClearStructuralFeatureActionActivation

// Begin Class CS_ConstructStrategy
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ConstructStrategy_Class() const
{
	return m_cS_ConstructStrategy_Class;
}




// End Class CS_ConstructStrategy

// Begin Class CS_CreateLinkActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CreateLinkActionActivation_Class() const
{
	return m_cS_CreateLinkActionActivation_Class;
}




// End Class CS_CreateLinkActionActivation

// Begin Class CS_CreateObjectActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_CreateObjectActionActivation_Class() const
{
	return m_cS_CreateObjectActionActivation_Class;
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


// End Class CS_DefaultConstructStrategy

// Begin Class CS_ReadExtentActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ReadExtentActionActivation_Class() const
{
	return m_cS_ReadExtentActionActivation_Class;
}




// End Class CS_ReadExtentActionActivation

// Begin Class CS_ReadSelfActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_ReadSelfActionActivation_Class() const
{
	return m_cS_ReadSelfActionActivation_Class;
}




// End Class CS_ReadSelfActionActivation

// Begin Class CS_RemoveStructuralFeatureValueActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_RemoveStructuralFeatureValueActionActivation_Class() const
{
	return m_cS_RemoveStructuralFeatureValueActionActivation_Class;
}




// End Class CS_RemoveStructuralFeatureValueActionActivation

// Begin Class CS_SendSignalActionActivation
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Actions::ActionsPackageImpl::getCS_SendSignalActionActivation_Class() const
{
	return m_cS_SendSignalActionActivation_Class;
}




// End Class CS_SendSignalActionActivation

