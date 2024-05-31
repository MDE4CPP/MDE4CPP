#include "PSSM/impl/PSSMPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EReference.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages
#include "PSSM/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include "PSSM/Semantics/impl/SemanticsPackageImpl.hpp"

#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSSM;

void PSSMPackageImpl::initializePackageContents()
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

	std::dynamic_pointer_cast<PSSM::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl>(getMDE4CPP_Extensions_Package())->initializePackageContents();
	std::dynamic_pointer_cast<PSSM::Semantics::SemanticsPackageImpl>(getSemantics_Package())->initializePackageContents();
}


void PSSMPackageImpl::initializePackageEDataTypes()
{
	
}

