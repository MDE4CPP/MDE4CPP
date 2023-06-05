#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

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
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::CommonBehavior;

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
const std::string CommonBehaviorPackage::eNS_URI ="http:///fUML_Semantics/Semantics/CommonBehavior.ecore";
const std::string CommonBehaviorPackage::eNS_PREFIX ="fUML_Semantics.Semantics.CommonBehavior";

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



// Begin Class EventAccepter
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventAccepter_Class() const
{
	return m_eventAccepter_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventAccepter_Operation_accept_Element() const
{
	return m_eventAccepter_Operation_accept_Element;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventAccepter_Operation_match_Element() const
{
	return m_eventAccepter_Operation_match_Element;
}

// End Class EventAccepter

// Begin Class EventOccurrence
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Class() const
{
	return m_eventOccurrence_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Attribute_target() const
{
	return m_eventOccurrence_Attribute_target;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_doSend() const
{
	return m_eventOccurrence_Operation_doSend;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_getParameterValues() const
{
	return m_eventOccurrence_Operation_getParameterValues;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_match_Trigger() const
{
	return m_eventOccurrence_Operation_match_Trigger;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_matchAny_Trigger() const
{
	return m_eventOccurrence_Operation_matchAny_Trigger;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_sendTo_Element() const
{
	return m_eventOccurrence_Operation_sendTo_Element;
}

// End Class EventOccurrence

// Begin Class Execution
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Class() const
{
	return m_execution_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_behavior() const
{
	return m_execution_Attribute_behavior;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_context() const
{
	return m_execution_Attribute_context;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_locus() const
{
	return m_execution_Attribute_locus;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_parameterValues() const
{
	return m_execution_Attribute_parameterValues;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_types() const
{
	return m_execution_Attribute_types;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation__copy() const
{
	return m_execution_Operation__copy;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_destroy() const
{
	return m_execution_Operation_destroy;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_execute() const
{
	return m_execution_Operation_execute;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_getOutputParameterValues() const
{
	return m_execution_Operation_getOutputParameterValues;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_getParameterValue_Parameter() const
{
	return m_execution_Operation_getParameterValue_Parameter;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_new_() const
{
	return m_execution_Operation_new_;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_setParameterValue_ParameterValue() const
{
	return m_execution_Operation_setParameterValue_ParameterValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_terminate() const
{
	return m_execution_Operation_terminate;
}

// End Class Execution

// Begin Class ParameterValue
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Class() const
{
	return m_parameterValue_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Attribute_values() const
{
	return m_parameterValue_Attribute_values;
}

const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Attribute_parameter() const
{
	return m_parameterValue_Attribute_parameter;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Operation__copy() const
{
	return m_parameterValue_Operation__copy;
}

// End Class ParameterValue

