#include "fUML/Semantics/Values/impl/ValuesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "fUML/Semantics/Values/ValuesFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "fUML/FUMLPackage.hpp"
#include "uml/UmlPackage.hpp"

using namespace fUML::Semantics::Values;

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



// Begin Class Evaluation
std::shared_ptr<ecore::EClass> ValuesPackageImpl::getEvaluation_Class() const
{
	return m_evaluation_Class;
}


std::shared_ptr<ecore::EReference> ValuesPackageImpl::getEvaluation_Attribute_locus() const
{
	return m_evaluation_Attribute_locus;
}
std::shared_ptr<ecore::EReference> ValuesPackageImpl::getEvaluation_Attribute_specification() const
{
	return m_evaluation_Attribute_specification;
}

std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getEvaluation_Operation_evaluate() const
{
	return m_evaluation_Operation_evaluate;
}

// End Class Evaluation

// Begin Class LiteralBooleanEvaluation
std::shared_ptr<ecore::EClass> ValuesPackageImpl::getLiteralBooleanEvaluation_Class() const
{
	return m_literalBooleanEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getLiteralBooleanEvaluation_Operation_evaluate() const
{
	return m_literalBooleanEvaluation_Operation_evaluate;
}

// End Class LiteralBooleanEvaluation

// Begin Class LiteralEvaluation
std::shared_ptr<ecore::EClass> ValuesPackageImpl::getLiteralEvaluation_Class() const
{
	return m_literalEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getLiteralEvaluation_Operation_getType_EString() const
{
	return m_literalEvaluation_Operation_getType_EString;
}

// End Class LiteralEvaluation

// Begin Class LiteralIntegerEvaluation
std::shared_ptr<ecore::EClass> ValuesPackageImpl::getLiteralIntegerEvaluation_Class() const
{
	return m_literalIntegerEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getLiteralIntegerEvaluation_Operation_evaluate() const
{
	return m_literalIntegerEvaluation_Operation_evaluate;
}

// End Class LiteralIntegerEvaluation

// Begin Class LiteralNullEvaluation
std::shared_ptr<ecore::EClass> ValuesPackageImpl::getLiteralNullEvaluation_Class() const
{
	return m_literalNullEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getLiteralNullEvaluation_Operation_evaluate() const
{
	return m_literalNullEvaluation_Operation_evaluate;
}

// End Class LiteralNullEvaluation

// Begin Class LiteralRealEvaluation
std::shared_ptr<ecore::EClass> ValuesPackageImpl::getLiteralRealEvaluation_Class() const
{
	return m_literalRealEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getLiteralRealEvaluation_Operation_evaluate() const
{
	return m_literalRealEvaluation_Operation_evaluate;
}

// End Class LiteralRealEvaluation

// Begin Class LiteralStringEvaluation
std::shared_ptr<ecore::EClass> ValuesPackageImpl::getLiteralStringEvaluation_Class() const
{
	return m_literalStringEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getLiteralStringEvaluation_Operation_evaluate() const
{
	return m_literalStringEvaluation_Operation_evaluate;
}

// End Class LiteralStringEvaluation

// Begin Class LiteralUnlimitedNaturalEvaluation
std::shared_ptr<ecore::EClass> ValuesPackageImpl::getLiteralUnlimitedNaturalEvaluation_Class() const
{
	return m_literalUnlimitedNaturalEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getLiteralUnlimitedNaturalEvaluation_Operation_evaluate() const
{
	return m_literalUnlimitedNaturalEvaluation_Operation_evaluate;
}

// End Class LiteralUnlimitedNaturalEvaluation

// Begin Class Value
std::shared_ptr<ecore::EClass> ValuesPackageImpl::getValue_Class() const
{
	return m_value_Class;
}



std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getValue_Operation__copy() const
{
	return m_value_Operation__copy;
}
std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getValue_Operation_checkAllParents_Classifier_Classifier() const
{
	return m_value_Operation_checkAllParents_Classifier_Classifier;
}
std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getValue_Operation_equals_Value() const
{
	return m_value_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getValue_Operation_getTypes() const
{
	return m_value_Operation_getTypes;
}
std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getValue_Operation_hasTypes_Classifier() const
{
	return m_value_Operation_hasTypes_Classifier;
}
std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getValue_Operation_objectId() const
{
	return m_value_Operation_objectId;
}
std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getValue_Operation_specify() const
{
	return m_value_Operation_specify;
}
std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getValue_Operation_toString() const
{
	return m_value_Operation_toString;
}

// End Class Value

