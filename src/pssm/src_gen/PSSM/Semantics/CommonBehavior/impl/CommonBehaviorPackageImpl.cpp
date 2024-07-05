#include "PSSM/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"

//metamodel factory
#include "PSSM/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"

//depending model packages
#include "PSSM/PSSMPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::CommonBehavior;

//Singleton implementation 
std::shared_ptr<CommonBehaviorPackage> CommonBehaviorPackage::eInstance()
{
	static std::shared_ptr<CommonBehaviorPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(CommonBehaviorPackageImpl::create());
		std::dynamic_pointer_cast<CommonBehaviorPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string CommonBehaviorPackage::eNAME ="CommonBehavior";
const std::string CommonBehaviorPackage::eNS_URI ="http:///PSSM/Semantics/CommonBehavior.ecore";
const std::string CommonBehaviorPackage::eNS_PREFIX ="PSSM.Semantics.CommonBehavior";

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



// Begin Class CallEventExecution
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Class() const
{
	return m_callEventExecution_Class;
}

const std::shared_ptr<ecore::EAttribute>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Attribute_callerSuspended() const
{
	return m_callEventExecution_Attribute_callerSuspended;
}

const std::shared_ptr<ecore::EReference>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Attribute_behavior() const
{
	return m_callEventExecution_Attribute_behavior;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Attribute_callerContext() const
{
	return m_callEventExecution_Attribute_callerContext;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Attribute_operation() const
{
	return m_callEventExecution_Attribute_operation;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation__send_CallEventOccurrence() const
{
	return m_callEventExecution_Operation__send_CallEventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation__suspend() const
{
	return m_callEventExecution_Operation__suspend;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_execute() const
{
	return m_callEventExecution_Operation_execute;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_getInputParameterValues() const
{
	return m_callEventExecution_Operation_getInputParameterValues;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_releaseCaller() const
{
	return m_callEventExecution_Operation_releaseCaller;
}

// End Class CallEventExecution

// Begin Class CallEventOccurrence
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Class() const
{
	return m_callEventOccurrence_Class;
}


const std::shared_ptr<ecore::EReference>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Attribute_execution() const
{
	return m_callEventOccurrence_Attribute_execution;
}


// End Class CallEventOccurrence

// Begin Class EventTriggeredExecution
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventTriggeredExecution_Class() const
{
	return m_eventTriggeredExecution_Class;
}


const std::shared_ptr<ecore::EReference>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventTriggeredExecution_Attribute_triggeringEventOccurrence() const
{
	return m_eventTriggeredExecution_Attribute_triggeringEventOccurrence;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventTriggeredExecution_Attribute_wrappedExecution() const
{
	return m_eventTriggeredExecution_Attribute_wrappedExecution;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventTriggeredExecution_Operation_execute() const
{
	return m_eventTriggeredExecution_Operation_execute;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventTriggeredExecution_Operation_finalize() const
{
	return m_eventTriggeredExecution_Operation_finalize;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventTriggeredExecution_Operation_initialize_Behavior() const
{
	return m_eventTriggeredExecution_Operation_initialize_Behavior;
}

// End Class EventTriggeredExecution

// Begin Class SM_ObjectActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSM_ObjectActivation_Class() const
{
	return m_sM_ObjectActivation_Class;
}


const std::shared_ptr<ecore::EReference>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSM_ObjectActivation_Attribute_deferredEventPool() const
{
	return m_sM_ObjectActivation_Attribute_deferredEventPool;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSM_ObjectActivation_Operation_getDeferredEventInsertionIndex() const
{
	return m_sM_ObjectActivation_Operation_getDeferredEventInsertionIndex;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSM_ObjectActivation_Operation_getNextCompletionEvent() const
{
	return m_sM_ObjectActivation_Operation_getNextCompletionEvent;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSM_ObjectActivation_Operation_registerCompletionEvent_StateActivation() const
{
	return m_sM_ObjectActivation_Operation_registerCompletionEvent_StateActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSM_ObjectActivation_Operation_registerDeferredEvent_EventOccurrence_StateActivation() const
{
	return m_sM_ObjectActivation_Operation_registerDeferredEvent_EventOccurrence_StateActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSM_ObjectActivation_Operation_releaseDeferredEvents_StateActivation() const
{
	return m_sM_ObjectActivation_Operation_releaseDeferredEvents_StateActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSM_ObjectActivation_Operation_retrieveNextEvent() const
{
	return m_sM_ObjectActivation_Operation_retrieveNextEvent;
}

// End Class SM_ObjectActivation

