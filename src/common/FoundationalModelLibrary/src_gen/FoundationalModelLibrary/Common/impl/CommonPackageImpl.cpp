#include "FoundationalModelLibrary/Common/impl/CommonPackageImpl.hpp"

//meta meta model classes
#include "uml/Class.hpp"
#include "uml/DataType.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Property.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/VisibilityKind.hpp"
//meta meta model factory
#include "uml/umlFactory.hpp"

//metamodel factory
#include "FoundationalModelLibrary/Common/CommonFactory.hpp"

//depending model packages
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"

//Superpackage
#include "FoundationalModelLibrary/FoundationalModelLibraryPackage.hpp"



using namespace FoundationalModelLibrary::Common;

//Singleton implemenation
std::shared_ptr<CommonPackage> CommonPackage::eInstance()
{
	static std::shared_ptr<CommonPackage> instance;
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(CommonPackageImpl::create());
		std::dynamic_pointer_cast<CommonPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialization
const std::string CommonPackage::eNAME ="Common";
const std::string CommonPackage::eNS_URI ="";
const std::string CommonPackage::eNS_PREFIX ="FoundationalModelLibrary";

CommonPackageImpl::CommonPackageImpl()
{
}

CommonPackageImpl::~CommonPackageImpl()
{
}

bool CommonPackageImpl::isInited = false;

CommonPackage* CommonPackageImpl::create()
{
	if (isInited)
	{
		return CommonPackage::eInstance().get();
	}
	isInited = true;
	
    // Obtain or create and register package, create package meta-data objects
    CommonPackageImpl * metaModelPackage = new CommonPackageImpl();
    return metaModelPackage;
}

void CommonPackageImpl::init(std::shared_ptr<uml::Package> foundationalModelLibrary_Common)
{
    // Initialize created meta-data
	setThisPackagePtr(foundationalModelLibrary_Common);
	initMetaModel();
    createPackageContents(foundationalModelLibrary_Common);
    initializePackageContents(foundationalModelLibrary_Common);   
}

void CommonPackageImpl::initMetaModel()
{
}

void CommonPackageImpl::createPackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_Common)
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<uml::umlFactory> factory = uml::umlFactory::eInstance();

	createPackageActivities(foundationalModelLibrary_Common, factory);
	createPackageAssociations(foundationalModelLibrary_Common, factory);
	createPackageClasses(foundationalModelLibrary_Common, factory);
	createPackageDataTypes(foundationalModelLibrary_Common, factory);
	createPackageDependencies(foundationalModelLibrary_Common, factory);
	createPackageEnumerationLiterals(foundationalModelLibrary_Common, factory);
	createPackageValueSpecifications(foundationalModelLibrary_Common, factory);
	createPackageInstanceSpecifications(foundationalModelLibrary_Common, factory);
	createPackageInterfaces(foundationalModelLibrary_Common, factory);
	createPackageInterfaceRealizations(foundationalModelLibrary_Common, factory);
	createPackagePrimitiveTypes(foundationalModelLibrary_Common, factory);
	createPackageStereotypes(foundationalModelLibrary_Common, factory);
}

void CommonPackageImpl::createPackageActivities(std::shared_ptr<uml::Package> foundationalModelLibrary_Common, std::shared_ptr<uml::umlFactory> factory)
{
}


void CommonPackageImpl::createPackageAssociations(std::shared_ptr<uml::Package> foundationalModelLibrary_Common, std::shared_ptr<uml::umlFactory> factory)
{
}

void CommonPackageImpl::createPackageClasses(std::shared_ptr<uml::Package> foundationalModelLibrary_Common, std::shared_ptr<uml::umlFactory> factory)
{
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;

	//Listener
	foundationalModelLibrary_Common_Listener = factory->createClass_as_ownedType_in_Package(foundationalModelLibrary_Common, FoundationalModelLibrary::Common::CommonPackage::LISTENER_CLASS);
	

//-------------------------------------------
//Opaque Behaviors

}

void CommonPackageImpl::createPackageDataTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_Common, std::shared_ptr<uml::umlFactory> factory)
{
	//Status
	foundationalModelLibrary_Common_Status = factory->createDataType_as_ownedType_in_Package(foundationalModelLibrary_Common, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
    // Status attributes
	//code
	foundationalModelLibrary_Common_Status_code = factory->createProperty_as_ownedAttribute_in_DataType(foundationalModelLibrary_Common_Status);
	//context
	foundationalModelLibrary_Common_Status_context = factory->createProperty_as_ownedAttribute_in_DataType(foundationalModelLibrary_Common_Status);
	//description
	foundationalModelLibrary_Common_Status_description = factory->createProperty_as_ownedAttribute_in_DataType(foundationalModelLibrary_Common_Status);
}

void CommonPackageImpl::createPackageDependencies(std::shared_ptr<uml::Package> foundationalModelLibrary_Common, std::shared_ptr<uml::umlFactory> factory)
{
}

void CommonPackageImpl::createPackageEnumerationLiterals(std::shared_ptr<uml::Package> foundationalModelLibrary_Common, std::shared_ptr<uml::umlFactory> factory)
{
}

void CommonPackageImpl::createPackageInstanceSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_Common, std::shared_ptr<uml::umlFactory> factory)
{
}

void CommonPackageImpl::createPackageInterfaceRealizations(std::shared_ptr<uml::Package> foundationalModelLibrary_Common, std::shared_ptr<uml::umlFactory> factory)
{
}

void CommonPackageImpl::createPackageInterfaces(std::shared_ptr<uml::Package> foundationalModelLibrary_Common, std::shared_ptr<uml::umlFactory> factory)
{
}

void CommonPackageImpl::createPackagePrimitiveTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_Common, std::shared_ptr<uml::umlFactory> factory)
{
}

void CommonPackageImpl::createPackageStereotypes(std::shared_ptr<uml::Package> foundationalModelLibrary_Common, std::shared_ptr<uml::umlFactory> factory)
{
}

void CommonPackageImpl::createPackageValueSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_Common, std::shared_ptr<uml::umlFactory> factory)
{
}

void CommonPackageImpl::initializePackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_Common)
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	this->setName(eNAME);
	this->setURI(eNS_URI);
	this->setNestingPackage(FoundationalModelLibrary::FoundationalModelLibraryPackage::eInstance());

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
void CommonPackageImpl::initializePackageActivities()
{
}


void CommonPackageImpl::initializePackageAssociations()
{
}

void CommonPackageImpl::initializePackageClasses()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;

	//	class Listener
	foundationalModelLibrary_Common_Listener->setName("Listener");
	foundationalModelLibrary_Common_Listener->setIsAbstract(true);
	foundationalModelLibrary_Common_Listener->_setID(LISTENER_CLASS);
	

//-------------------------------------------
//Opaque Behaviors

}

void CommonPackageImpl::initializePackageDataTypes()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;

	//DataType Status
	foundationalModelLibrary_Common_Status->setName("Status");
	foundationalModelLibrary_Common_Status->setIsAbstract(false);
	foundationalModelLibrary_Common_Status->_setID(STATUS_DATATYPE);
	
    // Status attributes
	//code
	foundationalModelLibrary_Common_Status_code->setName("code");
	foundationalModelLibrary_Common_Status_code->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	foundationalModelLibrary_Common_Status_code->setLower(1);
	foundationalModelLibrary_Common_Status_code->setUpper(1);
	foundationalModelLibrary_Common_Status_code->setIsUnique(true);
	foundationalModelLibrary_Common_Status_code->setAggregation(uml::AggregationKind::NONE);
	foundationalModelLibrary_Common_Status_code->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	foundationalModelLibrary_Common_Status_code->_setID(STATUS_PROPERTY_CODE);
	
	//context
	foundationalModelLibrary_Common_Status_context->setName("context");
	foundationalModelLibrary_Common_Status_context->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	foundationalModelLibrary_Common_Status_context->setLower(1);
	foundationalModelLibrary_Common_Status_context->setUpper(1);
	foundationalModelLibrary_Common_Status_context->setIsUnique(true);
	foundationalModelLibrary_Common_Status_context->setAggregation(uml::AggregationKind::NONE);
	foundationalModelLibrary_Common_Status_context->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	foundationalModelLibrary_Common_Status_context->_setID(STATUS_PROPERTY_CONTEXT);
	
	//description
	foundationalModelLibrary_Common_Status_description->setName("description");
	foundationalModelLibrary_Common_Status_description->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	foundationalModelLibrary_Common_Status_description->setLower(1);
	foundationalModelLibrary_Common_Status_description->setUpper(1);
	foundationalModelLibrary_Common_Status_description->setIsUnique(true);
	foundationalModelLibrary_Common_Status_description->setAggregation(uml::AggregationKind::NONE);
	foundationalModelLibrary_Common_Status_description->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	foundationalModelLibrary_Common_Status_description->_setID(STATUS_PROPERTY_DESCRIPTION);
	

}

void CommonPackageImpl::initializePackageDependencies()
{
}

void CommonPackageImpl::initializePackageInstanceSpecifications()
{
}


void CommonPackageImpl::initializePackageInterfaceRealizations()
{
}

void CommonPackageImpl::initializePackageInterfaces()
{
}

void CommonPackageImpl::initializePackageNestedPackages()
{
}

void CommonPackageImpl::initializePackageStereotypes()
{
}

void CommonPackageImpl::initializePackageValueSpecifications()
{
}

const std::shared_ptr<uml::Class>& CommonPackageImpl::get_FoundationalModelLibrary_Common_Listener()
{
	return foundationalModelLibrary_Common_Listener;
}
const std::shared_ptr<uml::DataType>& CommonPackageImpl::get_FoundationalModelLibrary_Common_Status()
{
	return foundationalModelLibrary_Common_Status;
}
const std::shared_ptr<uml::Property>& CommonPackageImpl::get_FoundationalModelLibrary_Common_Status_code()
{
	return foundationalModelLibrary_Common_Status_code;
}
const std::shared_ptr<uml::Property>& CommonPackageImpl::get_FoundationalModelLibrary_Common_Status_context()
{
	return foundationalModelLibrary_Common_Status_context;
}
const std::shared_ptr<uml::Property>& CommonPackageImpl::get_FoundationalModelLibrary_Common_Status_description()
{
	return foundationalModelLibrary_Common_Status_description;
}




