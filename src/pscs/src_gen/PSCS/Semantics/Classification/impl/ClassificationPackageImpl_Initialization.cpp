#include "PSCS/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EGenericType.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/fUMLPackage.hpp"


using namespace PSCS::Semantics::Classification;

void ClassificationPackageImpl::initializePackageContents()
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

}


void ClassificationPackageImpl::initializePackageEDataTypes()
{
	
}

