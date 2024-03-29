#include "fUML/impl/fUMLPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EParameter.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EGenericType.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages
#include "fUML/Semantics/impl/SemanticsPackageImpl.hpp"

#include "ecore/ecorePackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace fUML;

void fUMLPackageImpl::initializePackageContents()
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


void fUMLPackageImpl::initializePackageEDataTypes()
{
	
}

