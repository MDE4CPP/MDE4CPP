#include "types/impl/TypesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

//depending model packages

using namespace types;

void TypesPackageImpl::initializePackageContents()
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


void TypesPackageImpl::initializePackageEDataTypes()
{
	m_boolean_Class->setName("Boolean");
	m_boolean_Class->setSerializable(true);
	m_integer_Class->setName("Integer");
	m_integer_Class->setSerializable(true);
	m_real_Class->setName("Real");
	m_real_Class->setSerializable(true);
	m_string_Class->setName("String");
	m_string_Class->setSerializable(true);
	m_unlimitedNatural_Class->setName("UnlimitedNatural");
	m_unlimitedNatural_Class->setSerializable(true);
	
}

