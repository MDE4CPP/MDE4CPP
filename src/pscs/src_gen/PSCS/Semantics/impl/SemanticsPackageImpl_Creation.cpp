#include "PSCS/Semantics/impl/SemanticsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
#include "PSCS/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

#include "PSCS/Semantics/Loci/impl/LociPackageImpl.hpp"

#include "PSCS/Semantics/Values/impl/ValuesPackageImpl.hpp"
 
using namespace PSCS::Semantics;

void SemanticsPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();


	createPackageEDataTypes(package, factory);

	std::dynamic_pointer_cast<PSCS::Semantics::Classification::ClassificationPackageImpl>(getClassification_Package())->createPackageContents(getClassification_Package());

	std::dynamic_pointer_cast<PSCS::Semantics::Loci::LociPackageImpl>(getLoci_Package())->createPackageContents(getLoci_Package());

	std::dynamic_pointer_cast<PSCS::Semantics::Values::ValuesPackageImpl>(getValues_Package())->createPackageContents(getValues_Package());

}


void SemanticsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
