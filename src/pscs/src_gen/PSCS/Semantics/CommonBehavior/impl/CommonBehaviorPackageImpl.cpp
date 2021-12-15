#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAnnotation.hpp"

//metamodel factory
#include "PSCS/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::CommonBehavior;

bool CommonBehaviorPackageImpl::isInited = false;

CommonBehaviorPackageImpl::CommonBehaviorPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( CommonBehaviorFactory::eInstance()));
}

CommonBehaviorPackageImpl::~CommonBehaviorPackageImpl()
{
}

CommonBehaviorPackage* CommonBehaviorPackageImpl::create()
{
	if (isInited)
	{
		return CommonBehaviorPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    CommonBehaviorPackageImpl * metaModelPackage = new CommonBehaviorPackageImpl();
    return metaModelPackage;
}

void CommonBehaviorPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class CS_CallEventExecution
std::shared_ptr<ecore::EClass> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_CallEventExecution_Class() const
{
	return m_cS_CallEventExecution_Class;
}


std::shared_ptr<ecore::EReference> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_CallEventExecution_Attribute_interactionPoint() const
{
	return m_cS_CallEventExecution_Attribute_interactionPoint;
}

std::shared_ptr<ecore::EOperation> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_CallEventExecution_Operation__copy() const
{
	return m_cS_CallEventExecution_Operation__copy;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_CallEventExecution_Operation_createEventOccurrence() const
{
	return m_cS_CallEventExecution_Operation_createEventOccurrence;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_CallEventExecution_Operation_new_() const
{
	return m_cS_CallEventExecution_Operation_new_;
}

// End Class CS_CallEventExecution

// Begin Class CS_EventOccurrence
std::shared_ptr<ecore::EClass> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_EventOccurrence_Class() const
{
	return m_cS_EventOccurrence_Class;
}

std::shared_ptr<ecore::EAttribute> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_EventOccurrence_Attribute_propagationInward() const
{
	return m_cS_EventOccurrence_Attribute_propagationInward;
}

std::shared_ptr<ecore::EReference> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_EventOccurrence_Attribute_interactionPoint() const
{
	return m_cS_EventOccurrence_Attribute_interactionPoint;
}
std::shared_ptr<ecore::EReference> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_EventOccurrence_Attribute_onPort() const
{
	return m_cS_EventOccurrence_Attribute_onPort;
}
std::shared_ptr<ecore::EReference> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_EventOccurrence_Attribute_wrappedEventOccurrence() const
{
	return m_cS_EventOccurrence_Attribute_wrappedEventOccurrence;
}

std::shared_ptr<ecore::EOperation> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_EventOccurrence_Operation_doSend() const
{
	return m_cS_EventOccurrence_Operation_doSend;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_EventOccurrence_Operation_getParameterValues() const
{
	return m_cS_EventOccurrence_Operation_getParameterValues;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_EventOccurrence_Operation_match_Trigger() const
{
	return m_cS_EventOccurrence_Operation_match_Trigger;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_EventOccurrence_Operation_sendInTo_CS_Reference_Port() const
{
	return m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port() const
{
	return m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port;
}

// End Class CS_EventOccurrence

