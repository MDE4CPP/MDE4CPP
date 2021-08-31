#include "ocl/impl/oclPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "ocl/oclFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
#include "ocl/Evaluations/impl/EvaluationsPackageImpl.hpp"

#include "ocl/Expressions/impl/ExpressionsPackageImpl.hpp"

#include "ocl/Types/impl/TypesPackageImpl.hpp"

#include "ocl/Values/impl/ValuesPackageImpl.hpp"

using namespace ocl;

bool oclPackageImpl::isInited = false;

oclPackageImpl::oclPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( oclFactory::eInstance()));
}

oclPackageImpl::~oclPackageImpl()
{
}

oclPackage* oclPackageImpl::create()
{
	if (isInited)
	{
		return oclPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    oclPackageImpl * metaModelPackage = new oclPackageImpl();
    return metaModelPackage;
}

void oclPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}

std::shared_ptr<Evaluations::EvaluationsPackage> oclPackageImpl::getEvaluations_Package() const
{
	return Evaluations::EvaluationsPackage::eInstance();
} 
std::shared_ptr<Expressions::ExpressionsPackage> oclPackageImpl::getExpressions_Package() const
{
	return Expressions::ExpressionsPackage::eInstance();
} 
std::shared_ptr<Types::TypesPackage> oclPackageImpl::getTypes_Package() const
{
	return Types::TypesPackage::eInstance();
} 
std::shared_ptr<Values::ValuesPackage> oclPackageImpl::getValues_Package() const
{
	return Values::ValuesPackage::eInstance();
} 



