#include "PrimitiveTypesPackageImpl.hpp"

//metamodel classes
#include "Stereotype.hpp"
#include "Generalization.hpp"
#include "Constraint.hpp"
#include "OpaqueExpression.hpp"
#include "EnumerationLiteral.hpp"
#include "PrimitiveType.hpp"
#include "FunctionBehavior.hpp"

#include "Comment.hpp"
#include "PrimitiveType.hpp"
#include "ProfileApplication.hpp"
//metamodel factory
#include "UmlFactory.hpp"

//depending model packages


using namespace PrimitiveTypes;

PrimitiveTypesPackageImpl::PrimitiveTypesPackageImpl()
{
}

PrimitiveTypesPackageImpl::~PrimitiveTypesPackageImpl()
{
}

bool PrimitiveTypesPackageImpl::isInited = false;

PrimitiveTypesPackage* PrimitiveTypesPackageImpl::create()
{
	if (isInited)
	{
		return PrimitiveTypesPackage::eInstance();
	}
	isInited = true;
	
    // Obtain or create and register package, create package meta-data objects
    PrimitiveTypesPackageImpl * metaModelPackage = new PrimitiveTypesPackageImpl();
	metaModelPackage->initMetaModel();
    metaModelPackage->createPackageContents();
    return metaModelPackage;
}

void PrimitiveTypesPackageImpl::init()
{
    // Initialize created meta-data
    initializePackageContents();   
}

void PrimitiveTypesPackageImpl::initMetaModel()
{
}

void PrimitiveTypesPackageImpl::createPackageContents()
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;
	
	uml::Package * primitiveTypes = this;
	uml::Constraint * con = nullptr;
	uml::OpaqueExpression * oe = nullptr;
	
	






//Dependency 

	primitiveTypes_Real =  uml::UmlFactory::eInstance()->createPrimitiveType();
	primitiveTypes_Real->setName("Real");
	primitiveTypes_Real->setPackage(this);
	this->getOwnedType()->push_back(primitiveTypes_Real);
	primitiveTypes_String =  uml::UmlFactory::eInstance()->createPrimitiveType();
	primitiveTypes_String->setName("String");
	primitiveTypes_String->setPackage(this);
	this->getOwnedType()->push_back(primitiveTypes_String);
	primitiveTypes_UnlimitedNatural =  uml::UmlFactory::eInstance()->createPrimitiveType();
	primitiveTypes_UnlimitedNatural->setName("UnlimitedNatural");
	primitiveTypes_UnlimitedNatural->setPackage(this);
	this->getOwnedType()->push_back(primitiveTypes_UnlimitedNatural);
	primitiveTypes_Boolean =  uml::UmlFactory::eInstance()->createPrimitiveType();
	primitiveTypes_Boolean->setName("Boolean");
	primitiveTypes_Boolean->setPackage(this);
	this->getOwnedType()->push_back(primitiveTypes_Boolean);
	primitiveTypes_Integer =  uml::UmlFactory::eInstance()->createPrimitiveType();
	primitiveTypes_Integer->setName("Integer");
	primitiveTypes_Integer->setPackage(this);
	this->getOwnedType()->push_back(primitiveTypes_Integer);
	

}

void PrimitiveTypesPackageImpl::initializePackageContents()
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setURI(eNS_URI);

	// Add supertypes to classes
	uml::Generalization * gen = nullptr;
	

	
	
	//initalize ActivityNodes and Edges
}

uml::PrimitiveType* PrimitiveTypesPackageImpl::get_PrimitiveTypes_Boolean()
{
	return primitiveTypes_Boolean;
}
uml::PrimitiveType* PrimitiveTypesPackageImpl::get_PrimitiveTypes_Integer()
{
	return primitiveTypes_Integer;
}
uml::PrimitiveType* PrimitiveTypesPackageImpl::get_PrimitiveTypes_Real()
{
	return primitiveTypes_Real;
}
uml::PrimitiveType* PrimitiveTypesPackageImpl::get_PrimitiveTypes_String()
{
	return primitiveTypes_String;
}
uml::PrimitiveType* PrimitiveTypesPackageImpl::get_PrimitiveTypes_UnlimitedNatural()
{
	return primitiveTypes_UnlimitedNatural;
}


