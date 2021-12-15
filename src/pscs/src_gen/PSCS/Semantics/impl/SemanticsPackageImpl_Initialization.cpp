#include "PSCS/Semantics/impl/SemanticsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EPackage.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages
#include "PSCS/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "PSCS/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include "PSCS/Semantics/Loci/impl/LociPackageImpl.hpp"

#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include "PSCS/Semantics/Values/impl/ValuesPackageImpl.hpp"

#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSCS::Semantics;

void SemanticsPackageImpl::initializePackageContents()
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

	std::dynamic_pointer_cast<PSCS::Semantics::Actions::ActionsPackageImpl>(getActions_Package())->initializePackageContents();
	std::dynamic_pointer_cast<PSCS::Semantics::Classification::ClassificationPackageImpl>(getClassification_Package())->initializePackageContents();
	std::dynamic_pointer_cast<PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl>(getCommonBehavior_Package())->initializePackageContents();
	std::dynamic_pointer_cast<PSCS::Semantics::Loci::LociPackageImpl>(getLoci_Package())->initializePackageContents();
	std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl>(getStructuredClassifiers_Package())->initializePackageContents();
	std::dynamic_pointer_cast<PSCS::Semantics::Values::ValuesPackageImpl>(getValues_Package())->initializePackageContents();
}


void SemanticsPackageImpl::initializePackageEDataTypes()
{
	
}

