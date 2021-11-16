#include "ocl/impl/oclPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnumLiteral.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
#include "ocl/Evaluations/impl/EvaluationsPackageImpl.hpp"

#include "ocl/Expressions/impl/ExpressionsPackageImpl.hpp"

#include "ocl/Types/impl/TypesPackageImpl.hpp"

#include "ocl/Values/impl/ValuesPackageImpl.hpp"
 
using namespace ocl;

void oclPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();


	createPackageEDataTypes(package, factory);

	std::dynamic_pointer_cast<ocl::Evaluations::EvaluationsPackageImpl>(getEvaluations_Package())->createPackageContents(getEvaluations_Package());

	std::dynamic_pointer_cast<ocl::Expressions::ExpressionsPackageImpl>(getExpressions_Package())->createPackageContents(getExpressions_Package());

	std::dynamic_pointer_cast<ocl::Types::TypesPackageImpl>(getTypes_Package())->createPackageContents(getTypes_Package());

	std::dynamic_pointer_cast<ocl::Values::ValuesPackageImpl>(getValues_Package())->createPackageContents(getValues_Package());

}


void oclPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
