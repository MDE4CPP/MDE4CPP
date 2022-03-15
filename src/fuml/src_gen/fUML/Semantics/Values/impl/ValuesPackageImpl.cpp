#include "fUML/Semantics/Values/impl/ValuesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//metamodel factory
#include "fUML/Semantics/Values/ValuesFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

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
std::shared_ptr<ecore::EClass> fUML::Semantics::Values::ValuesPackageImpl::getEvaluation_Class() const
{
	return m_evaluation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Values::ValuesPackageImpl::getEvaluation_Attribute_locus() const
{
	return m_evaluation_Attribute_locus;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Values::ValuesPackageImpl::getEvaluation_Attribute_specification() const
{
	return m_evaluation_Attribute_specification;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Values::ValuesPackageImpl::getEvaluation_Operation_evaluate() const
{
	return m_evaluation_Operation_evaluate;
}

// End Class Evaluation

// Begin Class LiteralBooleanEvaluation
std::shared_ptr<ecore::EClass> fUML::Semantics::Values::ValuesPackageImpl::getLiteralBooleanEvaluation_Class() const
{
	return m_literalBooleanEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Values::ValuesPackageImpl::getLiteralBooleanEvaluation_Operation_evaluate() const
{
	return m_literalBooleanEvaluation_Operation_evaluate;
}

// End Class LiteralBooleanEvaluation

// Begin Class LiteralEvaluation
std::shared_ptr<ecore::EClass> fUML::Semantics::Values::ValuesPackageImpl::getLiteralEvaluation_Class() const
{
	return m_literalEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Values::ValuesPackageImpl::getLiteralEvaluation_Operation_getType_EString() const
{
	return m_literalEvaluation_Operation_getType_EString;
}

// End Class LiteralEvaluation

// Begin Class LiteralIntegerEvaluation
std::shared_ptr<ecore::EClass> fUML::Semantics::Values::ValuesPackageImpl::getLiteralIntegerEvaluation_Class() const
{
	return m_literalIntegerEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Values::ValuesPackageImpl::getLiteralIntegerEvaluation_Operation_evaluate() const
{
	return m_literalIntegerEvaluation_Operation_evaluate;
}

// End Class LiteralIntegerEvaluation

// Begin Class LiteralNullEvaluation
std::shared_ptr<ecore::EClass> fUML::Semantics::Values::ValuesPackageImpl::getLiteralNullEvaluation_Class() const
{
	return m_literalNullEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Values::ValuesPackageImpl::getLiteralNullEvaluation_Operation_evaluate() const
{
	return m_literalNullEvaluation_Operation_evaluate;
}

// End Class LiteralNullEvaluation

// Begin Class LiteralRealEvaluation
std::shared_ptr<ecore::EClass> fUML::Semantics::Values::ValuesPackageImpl::getLiteralRealEvaluation_Class() const
{
	return m_literalRealEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Values::ValuesPackageImpl::getLiteralRealEvaluation_Operation_evaluate() const
{
	return m_literalRealEvaluation_Operation_evaluate;
}

// End Class LiteralRealEvaluation

// Begin Class LiteralStringEvaluation
std::shared_ptr<ecore::EClass> fUML::Semantics::Values::ValuesPackageImpl::getLiteralStringEvaluation_Class() const
{
	return m_literalStringEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Values::ValuesPackageImpl::getLiteralStringEvaluation_Operation_evaluate() const
{
	return m_literalStringEvaluation_Operation_evaluate;
}

// End Class LiteralStringEvaluation

// Begin Class LiteralUnlimitedNaturalEvaluation
std::shared_ptr<ecore::EClass> fUML::Semantics::Values::ValuesPackageImpl::getLiteralUnlimitedNaturalEvaluation_Class() const
{
	return m_literalUnlimitedNaturalEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Values::ValuesPackageImpl::getLiteralUnlimitedNaturalEvaluation_Operation_evaluate() const
{
	return m_literalUnlimitedNaturalEvaluation_Operation_evaluate;
}

// End Class LiteralUnlimitedNaturalEvaluation

