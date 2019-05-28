#include "types/impl/TypesPackageImpl.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//depending model packages

using namespace types;

void TypesPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();


	createPackageEDataTypes(package, factory);
}


void TypesPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_boolean_Class = factory->createEDataType_in_EPackage(package, BOOLEAN_CLASS);
	m_integer_Class = factory->createEDataType_in_EPackage(package, INTEGER_CLASS);
	m_real_Class = factory->createEDataType_in_EPackage(package, REAL_CLASS);
	m_string_Class = factory->createEDataType_in_EPackage(package, STRING_CLASS);
	m_unlimitedNatural_Class = factory->createEDataType_in_EPackage(package, UNLIMITEDNATURAL_CLASS);
	
}
