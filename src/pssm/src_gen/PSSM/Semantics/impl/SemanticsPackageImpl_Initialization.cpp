#include "PSSM/Semantics/impl/SemanticsPackageImpl.hpp"

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

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages
#include "PSSM/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "PSSM/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include "PSSM/Semantics/Loci/impl/LociPackageImpl.hpp"

#include "PSSM/Semantics/StateMachines/impl/StateMachinesPackageImpl.hpp"

#include "PSSM/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include "PSSM/Semantics/Values/impl/ValuesPackageImpl.hpp"

#include "PSSM/PSSMPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSSM::Semantics;

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

	std::dynamic_pointer_cast<PSSM::Semantics::Actions::ActionsPackageImpl>(getActions_Package())->initializePackageContents();
	std::dynamic_pointer_cast<PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl>(getCommonBehavior_Package())->initializePackageContents();
	std::dynamic_pointer_cast<PSSM::Semantics::Loci::LociPackageImpl>(getLoci_Package())->initializePackageContents();
	std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateMachinesPackageImpl>(getStateMachines_Package())->initializePackageContents();
	std::dynamic_pointer_cast<PSSM::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl>(getStructuredClassifiers_Package())->initializePackageContents();
	std::dynamic_pointer_cast<PSSM::Semantics::Values::ValuesPackageImpl>(getValues_Package())->initializePackageContents();
}


void SemanticsPackageImpl::initializePackageEDataTypes()
{
	
}

