#include "fUML/impl/FUMLPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

//depending model packages
#include "fUML/Semantics/impl/SemanticsPackageImpl.hpp"

#include "ecore/EcorePackage.hpp"
#include "types/TypesPackage.hpp"
#include "uml/UmlPackage.hpp"


using namespace fUML;

void FUMLPackageImpl::initializePackageContents()
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

	std::dynamic_pointer_cast<fUML::Semantics::SemanticsPackageImpl>(getSemantics_Package())->initializePackageContents();
}


void FUMLPackageImpl::initializePackageEDataTypes()
{
	
}

