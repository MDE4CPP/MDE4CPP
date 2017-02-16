#include "TypesPackageImpl.hpp"

//metametamodel classes
#include "EAttribute.hpp"
#include "EClass.hpp"
#include "EDataType.hpp"
#include "EEnum.hpp"
#include "EOperation.hpp"
#include "EReference.hpp"

//metamodel factory
#include "TypesFactory.hpp"

//depending model packages

using namespace types;

bool TypesPackageImpl::isInited = false;

TypesPackageImpl::TypesPackageImpl()
{
	setEFactoryInstance(TypesFactory::eInstance());
}

TypesPackageImpl::~TypesPackageImpl()
{
	
	if (booleanEDataType != nullptr)
	{
		delete(booleanEDataType);
		booleanEDataType = nullptr;
	}
	if (integerEDataType != nullptr)
	{
		delete(integerEDataType);
		integerEDataType = nullptr;
	}
	if (realEDataType != nullptr)
	{
		delete(realEDataType);
		realEDataType = nullptr;
	}
	if (stringEDataType != nullptr)
	{
		delete(stringEDataType);
		stringEDataType = nullptr;
	}
	if (unlimitedNaturalEDataType != nullptr)
	{
		delete(unlimitedNaturalEDataType);
		unlimitedNaturalEDataType = nullptr;
	}
	
}

TypesPackage* TypesPackageImpl::create()
{
	if (isInited)
	{
		return TypesPackage::eInstance();
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


	booleanEDataType = createEDataType(BOOLEAN);
	integerEDataType = createEDataType(INTEGER);
	realEDataType = createEDataType(REAL);
	stringEDataType = createEDataType(STRING);
	unlimitedNaturalEDataType = createEDataType(UNLIMITEDNATURAL);
	
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
	
	ecore::EOperation *  op;

 	// Initialize classes and features; add operations and parameters

	initEDataType(booleanEDataType, nullptr, "Boolean", true, true);
	initEDataType(integerEDataType, nullptr, "Integer", true, true);
	initEDataType(realEDataType, nullptr, "Real", true, true);
	initEDataType(stringEDataType, nullptr, "String", true, true);
	initEDataType(unlimitedNaturalEDataType, nullptr, "UnlimitedNatural", true, true);
	
}

ecore::EDataType* TypesPackageImpl::getBoolean() const
{
	assert(booleanEDataType);
	return booleanEDataType;
}
ecore::EDataType* TypesPackageImpl::getInteger() const
{
	assert(integerEDataType);
	return integerEDataType;
}
ecore::EDataType* TypesPackageImpl::getReal() const
{
	assert(realEDataType);
	return realEDataType;
}
ecore::EDataType* TypesPackageImpl::getString() const
{
	assert(stringEDataType);
	return stringEDataType;
}
ecore::EDataType* TypesPackageImpl::getUnlimitedNatural() const
{
	assert(unlimitedNaturalEDataType);
	return unlimitedNaturalEDataType;
}

