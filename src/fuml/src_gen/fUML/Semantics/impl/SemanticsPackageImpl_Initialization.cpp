#include "fUML/Semantics/impl/SemanticsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EParameter.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesPackageImpl.hpp"

#include "fUML/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include "fUML/Semantics/Loci/impl/LociPackageImpl.hpp"

#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersPackageImpl.hpp"

#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include "fUML/Semantics/Values/impl/ValuesPackageImpl.hpp"

#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace fUML::Semantics;

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

	std::dynamic_pointer_cast<fUML::Semantics::Actions::ActionsPackageImpl>(getActions_Package())->initializePackageContents();
	std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivitiesPackageImpl>(getActivities_Package())->initializePackageContents();
	std::dynamic_pointer_cast<fUML::Semantics::Classification::ClassificationPackageImpl>(getClassification_Package())->initializePackageContents();
	std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl>(getCommonBehavior_Package())->initializePackageContents();
	std::dynamic_pointer_cast<fUML::Semantics::Loci::LociPackageImpl>(getLoci_Package())->initializePackageContents();
	std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackageImpl>(getSimpleClassifiers_Package())->initializePackageContents();
	std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl>(getStructuredClassifiers_Package())->initializePackageContents();
	std::dynamic_pointer_cast<fUML::Semantics::Values::ValuesPackageImpl>(getValues_Package())->initializePackageContents();
}


void SemanticsPackageImpl::initializePackageEDataTypes()
{
	
}

