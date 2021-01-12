#include "types/impl/typesPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//depending model packages
//include subpackages 
 
using namespace types;

void typesPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();


	createPackageEDataTypes(package, factory);

}


void typesPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_boolean_Class = factory->createEDataType_in_EPackage(package, BOOLEAN_CLASS);
	m_integer_Class = factory->createEDataType_in_EPackage(package, INTEGER_CLASS);
	m_real_Class = factory->createEDataType_in_EPackage(package, REAL_CLASS);
	m_string_Class = factory->createEDataType_in_EPackage(package, STRING_CLASS);
	m_unlimitedNatural_Class = factory->createEDataType_in_EPackage(package, UNLIMITEDNATURAL_CLASS);
	
}
