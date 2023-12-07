#include "PSSM/Semantics/Values/impl/ValuesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EReference.hpp"

//metamodel factory
#include "PSSM/Semantics/Values/ValuesFactory.hpp"

//depending model packages
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::Values;

//Singleton implementation 
std::shared_ptr<ValuesPackage> ValuesPackage::eInstance()
{
	static std::shared_ptr<ValuesPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ValuesPackageImpl::create());
		std::dynamic_pointer_cast<ValuesPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string ValuesPackage::eNAME ="Values";
const std::string ValuesPackage::eNS_URI ="http:///PSSM/Semantics/Values.ecore";
const std::string ValuesPackage::eNS_PREFIX ="PSSM.Semantics.Values";

bool ValuesPackageImpl::isInited = false;

ValuesPackageImpl::ValuesPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( ValuesFactory::eInstance()));
}

ValuesPackageImpl::~ValuesPackageImpl()
{
}

ValuesPackage* ValuesPackageImpl::create()
{
	if (isInited)
	{
		return ValuesPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    ValuesPackageImpl * metaModelPackage = new ValuesPackageImpl();
    return metaModelPackage;
}

void ValuesPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class SM_OpaqueExpressionEvaluation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::Values::ValuesPackageImpl::getSM_OpaqueExpressionEvaluation_Class() const
{
	return m_sM_OpaqueExpressionEvaluation_Class;
}


const std::shared_ptr<ecore::EReference>& PSSM::Semantics::Values::ValuesPackageImpl::getSM_OpaqueExpressionEvaluation_Attribute_context() const
{
	return m_sM_OpaqueExpressionEvaluation_Attribute_context;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::Values::ValuesPackageImpl::getSM_OpaqueExpressionEvaluation_Attribute_parameterValues() const
{
	return m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::Values::ValuesPackageImpl::getSM_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior() const
{
	return m_sM_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::Values::ValuesPackageImpl::getSM_OpaqueExpressionEvaluation_Operation_getParameterValue_Parameter() const
{
	return m_sM_OpaqueExpressionEvaluation_Operation_getParameterValue_Parameter;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::Values::ValuesPackageImpl::getSM_OpaqueExpressionEvaluation_Operation_initialize_EventOccurrence() const
{
	return m_sM_OpaqueExpressionEvaluation_Operation_initialize_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::Values::ValuesPackageImpl::getSM_OpaqueExpressionEvaluation_Operation_setParameterValue_ParameterValue() const
{
	return m_sM_OpaqueExpressionEvaluation_Operation_setParameterValue_ParameterValue;
}

// End Class SM_OpaqueExpressionEvaluation

