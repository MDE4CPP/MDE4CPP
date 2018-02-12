#include "types/impl/TypesPackageImpl.hpp"

//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"

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
	metaModelPackage->createPackageContents();
    return metaModelPackage;
}

void TypesPackageImpl::init()
{
    // Initialize created meta-data
    initializePackageContents();   
}

void TypesPackageImpl::createPackageContents()
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;
	struct null_deleter{void operator()(void const *) const { } };

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();


	createPackageEDataTypes(std::shared_ptr<EPackage>(this, null_deleter()), factory);
}


void TypesPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_boolean_EDataType = factory->createEDataType_in_EPackage(package, BOOLEAN_EDATATYPE);
	m_integer_EDataType = factory->createEDataType_in_EPackage(package, INTEGER_EDATATYPE);
	m_real_EDataType = factory->createEDataType_in_EPackage(package, REAL_EDATATYPE);
	m_string_EDataType = factory->createEDataType_in_EPackage(package, STRING_EDATATYPE);
	m_unlimitedNatural_EDataType = factory->createEDataType_in_EPackage(package, UNLIMITEDNATURAL_EDATATYPE);
	
}

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
	m_boolean_EDataType->setInstanceClass(nullptr);
	m_boolean_EDataType->setName("Boolean");
	m_boolean_EDataType->setSerializable(true);
	m_integer_EDataType->setInstanceClass(nullptr);
	m_integer_EDataType->setName("Integer");
	m_integer_EDataType->setSerializable(true);
	m_real_EDataType->setInstanceClass(nullptr);
	m_real_EDataType->setName("Real");
	m_real_EDataType->setSerializable(true);
	m_string_EDataType->setInstanceClass(nullptr);
	m_string_EDataType->setName("String");
	m_string_EDataType->setSerializable(true);
	m_unlimitedNatural_EDataType->setInstanceClass(nullptr);
	m_unlimitedNatural_EDataType->setName("UnlimitedNatural");
	m_unlimitedNatural_EDataType->setSerializable(true);
	
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

