#include "ocl/impl/oclPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages
#include "ocl/Evaluations/impl/EvaluationsPackageImpl.hpp"

#include "ocl/Expressions/impl/ExpressionsPackageImpl.hpp"

#include "ocl/Types/impl/TypesPackageImpl.hpp"

#include "ocl/Values/impl/ValuesPackageImpl.hpp"

#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace ocl;

void oclPackageImpl::initializePackageContents()
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setNsPrefix(eNS_PREFIX);
	setNsURI(eNS_URI);
	
	// Add supertypes to classes
	

 	// Initialize classes and features; add operations and parameters

	initializePackageEDataTypes();

	std::dynamic_pointer_cast<ocl::Evaluations::EvaluationsPackageImpl>(getEvaluations_Package())->initializePackageContents();
	std::dynamic_pointer_cast<ocl::Expressions::ExpressionsPackageImpl>(getExpressions_Package())->initializePackageContents();
	std::dynamic_pointer_cast<ocl::Types::TypesPackageImpl>(getTypes_Package())->initializePackageContents();
	std::dynamic_pointer_cast<ocl::Values::ValuesPackageImpl>(getValues_Package())->initializePackageContents();
}


void oclPackageImpl::initializePackageEDataTypes()
{
	
}

