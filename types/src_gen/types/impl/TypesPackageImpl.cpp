#include "types/impl/TypesPackageImpl.hpp"

//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EOperation.hpp"
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
	
	booleanEDataType.reset();
	integerEDataType.reset();
	realEDataType.reset();
	stringEDataType.reset();
	unlimitedNaturalEDataType.reset();
	
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


	booleanEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), BOOLEAN);
	integerEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INTEGER);
	realEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), REAL);
	stringEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), STRING);
	unlimitedNaturalEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), UNLIMITEDNATURAL);
	
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
	
	std::shared_ptr<ecore::EOperation> op;

 	// Initialize classes and features; add operations and parameters

	initEDataType(booleanEDataType, nullptr, "Boolean", true, true);
	initEDataType(integerEDataType, nullptr, "Integer", true, true);
	initEDataType(realEDataType, nullptr, "Real", true, true);
	initEDataType(stringEDataType, nullptr, "String", true, true);
	initEDataType(unlimitedNaturalEDataType, nullptr, "UnlimitedNatural", true, true);
	
}

std::shared_ptr<ecore::EDataType> TypesPackageImpl::getBoolean() const
{
	assert(booleanEDataType);
	return booleanEDataType;
}
std::shared_ptr<ecore::EDataType> TypesPackageImpl::getInteger() const
{
	assert(integerEDataType);
	return integerEDataType;
}
std::shared_ptr<ecore::EDataType> TypesPackageImpl::getReal() const
{
	assert(realEDataType);
	return realEDataType;
}
std::shared_ptr<ecore::EDataType> TypesPackageImpl::getString() const
{
	assert(stringEDataType);
	return stringEDataType;
}
std::shared_ptr<ecore::EDataType> TypesPackageImpl::getUnlimitedNatural() const
{
	assert(unlimitedNaturalEDataType);
	return unlimitedNaturalEDataType;
}

