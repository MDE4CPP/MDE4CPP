#include "PSCS/Semantics/impl/SemanticsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnumLiteral.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
#include "PSCS/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include "PSCS/Semantics/Loci/impl/LociPackageImpl.hpp"

#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"
 
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

	std::dynamic_pointer_cast<PSCS::Semantics::Actions::ActionsPackageImpl>(getActions_Package())->createPackageContents(getActions_Package());

	std::dynamic_pointer_cast<PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl>(getCommonBehavior_Package())->createPackageContents(getCommonBehavior_Package());

	std::dynamic_pointer_cast<PSCS::Semantics::Loci::LociPackageImpl>(getLoci_Package())->createPackageContents(getLoci_Package());

	std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl>(getStructuredClassifiers_Package())->createPackageContents(getStructuredClassifiers_Package());

}


void SemanticsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
