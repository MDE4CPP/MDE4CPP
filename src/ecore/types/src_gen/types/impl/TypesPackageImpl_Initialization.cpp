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
	m_boolean_EDataType->setName("Boolean");
	m_boolean_EDataType->setSerializable(true);
	m_integer_EDataType->setName("Integer");
	m_integer_EDataType->setSerializable(true);
	m_real_EDataType->setName("Real");
	m_real_EDataType->setSerializable(true);
	m_string_EDataType->setName("String");
	m_string_EDataType->setSerializable(true);
	m_unlimitedNatural_EDataType->setName("UnlimitedNatural");
	m_unlimitedNatural_EDataType->setSerializable(true);
	
}
