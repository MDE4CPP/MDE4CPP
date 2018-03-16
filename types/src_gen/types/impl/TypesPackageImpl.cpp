#include "types/impl/TypesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EDataType.hpp"

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

std::shared_ptr<ecore::EDataType> TypesPackageImpl::getBoolean_EDataType() const
{
	return m_boolean_EDataType;
}
std::shared_ptr<ecore::EDataType> TypesPackageImpl::getInteger_EDataType() const
{
	return m_integer_EDataType;
}
std::shared_ptr<ecore::EDataType> TypesPackageImpl::getReal_EDataType() const
{
	return m_real_EDataType;
}
std::shared_ptr<ecore::EDataType> TypesPackageImpl::getString_EDataType() const
{
	return m_string_EDataType;
}
std::shared_ptr<ecore::EDataType> TypesPackageImpl::getUnlimitedNatural_EDataType() const
{
	return m_unlimitedNatural_EDataType;
}

