#include "types/impl/typesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"

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
	m_any_Class->setName("Any");
	m_any_Class->setSerializable(true);
	m_any_Class->_setID(ANY_CLASS);
	m_boolean_Class->setName("Boolean");
	m_boolean_Class->setSerializable(true);
	m_boolean_Class->_setID(BOOLEAN_CLASS);
	m_integer_Class->setName("Integer");
	m_integer_Class->setSerializable(true);
	m_integer_Class->_setID(INTEGER_CLASS);
	m_real_Class->setName("Real");
	m_real_Class->setSerializable(true);
	m_real_Class->_setID(REAL_CLASS);
	m_string_Class->setName("String");
	m_string_Class->setSerializable(true);
	m_string_Class->_setID(STRING_CLASS);
	m_unlimitedNatural_Class->setName("UnlimitedNatural");
	m_unlimitedNatural_Class->setSerializable(true);
	m_unlimitedNatural_Class->_setID(UNLIMITEDNATURAL_CLASS);
	
}

