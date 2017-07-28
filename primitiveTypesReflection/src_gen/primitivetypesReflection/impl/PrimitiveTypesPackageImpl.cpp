#include "PrimitiveTypesPackageImpl.hpp"

//metamodel classes
#include "Stereotype.hpp"
#include "Generalization.hpp"
#include "Constraint.hpp"
#include "OpaqueExpression.hpp"
#include "EnumerationLiteral.hpp"
#include "PrimitiveType.hpp"
#include "FunctionBehavior.hpp"
#include "Interface.hpp"
#include "Operation.hpp"
#include "Property.hpp"

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
		return PrimitiveTypesPackage::eInstance().get();
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

	struct null_deleter{void operator()(void const *) const {} };
	std::shared_ptr<PrimitiveTypesPackageImpl> primitiveTypes = std::shared_ptr<PrimitiveTypesPackageImpl>(this, null_deleter());
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;
	
	






//Dependency 

	primitiveTypes_Integer.reset(uml::UmlFactory::eInstance()->createPrimitiveType());
	primitiveTypes_Integer->setName("Integer");
	primitiveTypes_Integer->setPackage(primitiveTypes);
	this->getOwnedType()->push_back(primitiveTypes_Integer);
	primitiveTypes_String.reset(uml::UmlFactory::eInstance()->createPrimitiveType());
	primitiveTypes_String->setName("String");
	primitiveTypes_String->setPackage(primitiveTypes);
	this->getOwnedType()->push_back(primitiveTypes_String);
	primitiveTypes_Boolean.reset(uml::UmlFactory::eInstance()->createPrimitiveType());
	primitiveTypes_Boolean->setName("Boolean");
	primitiveTypes_Boolean->setPackage(primitiveTypes);
	this->getOwnedType()->push_back(primitiveTypes_Boolean);
	primitiveTypes_UnlimitedNatural.reset(uml::UmlFactory::eInstance()->createPrimitiveType());
	primitiveTypes_UnlimitedNatural->setName("UnlimitedNatural");
	primitiveTypes_UnlimitedNatural->setPackage(primitiveTypes);
	this->getOwnedType()->push_back(primitiveTypes_UnlimitedNatural);
	primitiveTypes_Real.reset(uml::UmlFactory::eInstance()->createPrimitiveType());
	primitiveTypes_Real->setName("Real");
	primitiveTypes_Real->setPackage(primitiveTypes);
	this->getOwnedType()->push_back(primitiveTypes_Real);
	

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
	struct null_deleter{void operator()(void const *) const {} };
	std::shared_ptr<PrimitiveTypesPackageImpl> primitiveTypes = std::shared_ptr<PrimitiveTypesPackageImpl>(this, null_deleter());
	std::shared_ptr<uml::Generalization> gen = nullptr;
	

	
	
	//initalize ActivityNodes and Edges
}

std::shared_ptr<uml::PrimitiveType> PrimitiveTypesPackageImpl::get_PrimitiveTypes_Boolean()
{
	return primitiveTypes_Boolean;
}
std::shared_ptr<uml::PrimitiveType> PrimitiveTypesPackageImpl::get_PrimitiveTypes_Integer()
{
	return primitiveTypes_Integer;
}
std::shared_ptr<uml::PrimitiveType> PrimitiveTypesPackageImpl::get_PrimitiveTypes_Real()
{
	return primitiveTypes_Real;
}
std::shared_ptr<uml::PrimitiveType> PrimitiveTypesPackageImpl::get_PrimitiveTypes_String()
{
	return primitiveTypes_String;
}
std::shared_ptr<uml::PrimitiveType> PrimitiveTypesPackageImpl::get_PrimitiveTypes_UnlimitedNatural()
{
	return primitiveTypes_UnlimitedNatural;
}


