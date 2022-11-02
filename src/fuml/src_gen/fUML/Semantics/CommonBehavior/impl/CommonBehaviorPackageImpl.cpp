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



// Begin Class Execution
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Class() const
{
	return m_execution_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_behavior() const
{
	return m_execution_Attribute_behavior;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_context() const
{
	return m_execution_Attribute_context;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_locus() const
{
	return m_execution_Attribute_locus;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_parameterValues() const
{
	return m_execution_Attribute_parameterValues;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_types() const
{
	return m_execution_Attribute_types;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation__copy() const
{
	return m_execution_Operation__copy;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_destroy() const
{
	return m_execution_Operation_destroy;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_execute() const
{
	return m_execution_Operation_execute;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_getOutputParameterValues() const
{
	return m_execution_Operation_getOutputParameterValues;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_getParameterValue_Parameter() const
{
	return m_execution_Operation_getParameterValue_Parameter;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_new_() const
{
	return m_execution_Operation_new_;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_setParameterValue_ParameterValue() const
{
	return m_execution_Operation_setParameterValue_ParameterValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_terminate() const
{
	return m_execution_Operation_terminate;
}

// End Class Execution

// Begin Class ParameterValue
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Class() const
{
	return m_parameterValue_Class;
}

std::shared_ptr<ecore::EAttribute> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Attribute_values() const
{
	return m_parameterValue_Attribute_values;
}

std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Attribute_parameter() const
{
	return m_parameterValue_Attribute_parameter;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Operation__copy() const
{
	return m_parameterValue_Operation__copy;
}

// End Class ParameterValue

