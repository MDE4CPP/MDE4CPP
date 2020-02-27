#include "types/impl/TypesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "types/TypesFactory.hpp"

//depending model packages

using namespace types;

bool TypesPackageImpl::isInited = false;

TypesPackageImpl::TypesPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( TypesFactory::eInstance()));
}

TypesPackageImpl::~TypesPackageImpl()
{
}

TypesPackage* TypesPackageImpl::create()
{
	if (isInited)
	{
		return TypesPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    TypesPackageImpl * metaModelPackage = new TypesPackageImpl();
    return metaModelPackage;
}

void TypesPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



std::shared_ptr<ecore::EDataType> TypesPackageImpl::getBoolean_Class() const
{
	return m_boolean_Class;
}
std::shared_ptr<ecore::EDataType> TypesPackageImpl::getInteger_Class() const
{
	return m_integer_Class;
}
std::shared_ptr<ecore::EDataType> TypesPackageImpl::getReal_Class() const
{
	return m_real_Class;
}
std::shared_ptr<ecore::EDataType> TypesPackageImpl::getString_Class() const
{
	return m_string_Class;
}
std::shared_ptr<ecore::EDataType> TypesPackageImpl::getUnlimitedNatural_Class() const
{
	return m_unlimitedNatural_Class;
}

