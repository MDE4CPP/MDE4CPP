#include "types/impl/typesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages



using namespace types;

void typesPackageImpl::initializePackageContents()
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


void typesPackageImpl::initializePackageEDataTypes()
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

