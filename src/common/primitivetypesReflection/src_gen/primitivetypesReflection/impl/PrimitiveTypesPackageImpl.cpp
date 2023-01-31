#include "primitivetypesReflection/impl/PrimitiveTypesPackageImpl.hpp"

//meta meta model classes
#include "uml/Comment.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/ProfileApplication.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/VisibilityKind.hpp"
//meta meta model factory
#include "uml/umlFactory.hpp"


//depending model packages



//Stereotypes
#include "ecore/EDataType.hpp"
#include "ecore/EPackage.hpp"

using namespace PrimitiveTypes;

//Singleton implemenation
std::shared_ptr<PrimitiveTypesPackage> PrimitiveTypesPackage::eInstance()
{
	static std::shared_ptr<PrimitiveTypesPackage> instance;
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(PrimitiveTypesPackageImpl::create());
		std::dynamic_pointer_cast<PrimitiveTypesPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialization
const std::string PrimitiveTypesPackage::eNAME ="PrimitiveTypes";
const std::string PrimitiveTypesPackage::eNS_URI ="http://www.omg.org/spec/PrimitiveTypes/20131001";
const std::string PrimitiveTypesPackage::eNS_PREFIX ="";

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
    return metaModelPackage;
}

void PrimitiveTypesPackageImpl::init(std::shared_ptr<uml::Package> primitiveTypes)
{
    // Initialize created meta-data
	setThisPackagePtr(primitiveTypes);
	initMetaModel();
    createPackageContents(primitiveTypes);
    initializePackageContents(primitiveTypes);   
}

void PrimitiveTypesPackageImpl::initMetaModel()
{
}

void PrimitiveTypesPackageImpl::createPackageContents(std::shared_ptr<uml::Package> primitiveTypes)
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<uml::umlFactory> factory = uml::umlFactory::eInstance();

	createPackageActivities(primitiveTypes, factory);
	createPackageAssociations(primitiveTypes, factory);
	createPackageClasses(primitiveTypes, factory);
	createPackageDataTypes(primitiveTypes, factory);
	createPackageDependencies(primitiveTypes, factory);
	createPackageEnumerationLiterals(primitiveTypes, factory);
	createPackageValueSpecifications(primitiveTypes, factory);
	createPackageInstanceSpecifications(primitiveTypes, factory);
	createPackageInterfaces(primitiveTypes, factory);
	createPackageInterfaceRealizations(primitiveTypes, factory);
	createPackagePrimitiveTypes(primitiveTypes, factory);
	createPackageStereotypes(primitiveTypes, factory);
}

void PrimitiveTypesPackageImpl::createPackageActivities(std::shared_ptr<uml::Package> primitiveTypes, std::shared_ptr<uml::umlFactory> factory)
{
}


void PrimitiveTypesPackageImpl::createPackageAssociations(std::shared_ptr<uml::Package> primitiveTypes, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveTypesPackageImpl::createPackageClasses(std::shared_ptr<uml::Package> primitiveTypes, std::shared_ptr<uml::umlFactory> factory)
{
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;


//-------------------------------------------
//Opaque Behaviors

}

void PrimitiveTypesPackageImpl::createPackageDataTypes(std::shared_ptr<uml::Package> primitiveTypes, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveTypesPackageImpl::createPackageDependencies(std::shared_ptr<uml::Package> primitiveTypes, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveTypesPackageImpl::createPackageEnumerationLiterals(std::shared_ptr<uml::Package> primitiveTypes, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveTypesPackageImpl::createPackageInstanceSpecifications(std::shared_ptr<uml::Package> primitiveTypes, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveTypesPackageImpl::createPackageInterfaceRealizations(std::shared_ptr<uml::Package> primitiveTypes, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveTypesPackageImpl::createPackageInterfaces(std::shared_ptr<uml::Package> primitiveTypes, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveTypesPackageImpl::createPackagePrimitiveTypes(std::shared_ptr<uml::Package> primitiveTypes, std::shared_ptr<uml::umlFactory> factory)
{
	primitiveTypes_Boolean = factory->createPrimitiveType_as_ownedType_in_Package(primitiveTypes);
	primitiveTypes_Boolean->setName("Boolean");

	primitiveTypes_Integer = factory->createPrimitiveType_as_ownedType_in_Package(primitiveTypes);
	primitiveTypes_Integer->setName("Integer");

	primitiveTypes_Real = factory->createPrimitiveType_as_ownedType_in_Package(primitiveTypes);
	primitiveTypes_Real->setName("Real");

	primitiveTypes_String = factory->createPrimitiveType_as_ownedType_in_Package(primitiveTypes);
	primitiveTypes_String->setName("String");

	primitiveTypes_UnlimitedNatural = factory->createPrimitiveType_as_ownedType_in_Package(primitiveTypes);
	primitiveTypes_UnlimitedNatural->setName("UnlimitedNatural");
}

void PrimitiveTypesPackageImpl::createPackageStereotypes(std::shared_ptr<uml::Package> primitiveTypes, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveTypesPackageImpl::createPackageValueSpecifications(std::shared_ptr<uml::Package> primitiveTypes, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveTypesPackageImpl::initializePackageContents(std::shared_ptr<uml::Package> primitiveTypes)
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	this->setName(eNAME);
	this->setURI(eNS_URI);

	initializePackageActivities();
	initializePackageAssociations();
	initializePackageClasses();
	initializePackageDataTypes();
	initializePackageDependencies();
	initializePackageInstanceSpecifications();
	initializePackageInterfaceRealizations();
	initializePackageInterfaces();
	initializePackageNestedPackages();
	initializePackageStereotypes();
	initializePackageValueSpecifications();
	
}

//ActivityNodes and Edges
void PrimitiveTypesPackageImpl::initializePackageActivities()
{
}


void PrimitiveTypesPackageImpl::initializePackageAssociations()
{
}

void PrimitiveTypesPackageImpl::initializePackageClasses()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;


//-------------------------------------------
//Opaque Behaviors

}

void PrimitiveTypesPackageImpl::initializePackageDataTypes()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;

}

void PrimitiveTypesPackageImpl::initializePackageDependencies()
{
}

void PrimitiveTypesPackageImpl::initializePackageInstanceSpecifications()
{
}


void PrimitiveTypesPackageImpl::initializePackageInterfaceRealizations()
{
}

void PrimitiveTypesPackageImpl::initializePackageInterfaces()
{
}

void PrimitiveTypesPackageImpl::initializePackageNestedPackages()
{
}

void PrimitiveTypesPackageImpl::initializePackageStereotypes()
{
}

void PrimitiveTypesPackageImpl::initializePackageValueSpecifications()
{
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




