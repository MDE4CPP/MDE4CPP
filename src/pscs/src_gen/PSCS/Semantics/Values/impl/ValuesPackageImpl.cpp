#include "PSCS/Semantics/Values/impl/ValuesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "PSCS/Semantics/Values/ValuesFactory.hpp"

//depending model packages
#include "fUML/FUMLPackage.hpp"

using namespace PSCS::Semantics::Values;

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



// Begin Class CS_OpaqueExpressionEvaluation
std::shared_ptr<ecore::EClass> ValuesPackageImpl::getCS_OpaqueExpressionEvaluation_Class() const
{
	return m_cS_OpaqueExpressionEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getCS_OpaqueExpressionEvaluation_Operation_evaluate() const
{
	return m_cS_OpaqueExpressionEvaluation_Operation_evaluate;
}
std::shared_ptr<ecore::EOperation> ValuesPackageImpl::getCS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior() const
{
	return m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior;
}

// End Class CS_OpaqueExpressionEvaluation

