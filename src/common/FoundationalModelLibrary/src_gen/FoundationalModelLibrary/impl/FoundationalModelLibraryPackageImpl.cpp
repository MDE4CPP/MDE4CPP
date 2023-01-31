#include "FoundationalModelLibrary/impl/FoundationalModelLibraryPackageImpl.hpp"

//meta meta model classes
#include "uml/PackageImport.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/VisibilityKind.hpp"
//meta meta model factory
#include "uml/umlFactory.hpp"

//metamodel factory
#include "FoundationalModelLibrary/FoundationalModelLibraryFactory.hpp"

//depending model packages


//Subpackages
#include "FoundationalModelLibrary/BasicInputOutput/impl/BasicInputOutputPackageImpl.hpp"
#include "FoundationalModelLibrary/Common/impl/CommonPackageImpl.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/impl/PrimitiveBehaviorsPackageImpl.hpp"


using namespace FoundationalModelLibrary;

//Singleton implemenation
std::shared_ptr<FoundationalModelLibraryPackage> FoundationalModelLibraryPackage::eInstance()
{
	static std::shared_ptr<FoundationalModelLibraryPackage> instance;
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(FoundationalModelLibraryPackageImpl::create());
		std::dynamic_pointer_cast<FoundationalModelLibraryPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialization
const std::string FoundationalModelLibraryPackage::eNAME ="FoundationalModelLibrary";
const std::string FoundationalModelLibraryPackage::eNS_URI ="https://www.omg.org/spec/FUML/20150801";
const std::string FoundationalModelLibraryPackage::eNS_PREFIX ="";

FoundationalModelLibraryPackageImpl::FoundationalModelLibraryPackageImpl()
{
}

FoundationalModelLibraryPackageImpl::~FoundationalModelLibraryPackageImpl()
{
}

bool FoundationalModelLibraryPackageImpl::isInited = false;

FoundationalModelLibraryPackage* FoundationalModelLibraryPackageImpl::create()
{
	if (isInited)
	{
		return FoundationalModelLibraryPackage::eInstance().get();
	}
	isInited = true;
	
    // Obtain or create and register package, create package meta-data objects
    FoundationalModelLibraryPackageImpl * metaModelPackage = new FoundationalModelLibraryPackageImpl();
    return metaModelPackage;
}

void FoundationalModelLibraryPackageImpl::init(std::shared_ptr<uml::Package> foundationalModelLibrary)
{
    // Initialize created meta-data
	setThisPackagePtr(foundationalModelLibrary);
	initMetaModel();
    createPackageContents(foundationalModelLibrary);
    initializePackageContents(foundationalModelLibrary);   
}

void FoundationalModelLibraryPackageImpl::initMetaModel()
{
}

void FoundationalModelLibraryPackageImpl::createPackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary)
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<uml::umlFactory> factory = uml::umlFactory::eInstance();

	createPackageActivities(foundationalModelLibrary, factory);
	createPackageAssociations(foundationalModelLibrary, factory);
	createPackageClasses(foundationalModelLibrary, factory);
	createPackageDataTypes(foundationalModelLibrary, factory);
	createPackageDependencies(foundationalModelLibrary, factory);
	createPackageEnumerationLiterals(foundationalModelLibrary, factory);
	createPackageValueSpecifications(foundationalModelLibrary, factory);
	createPackageInstanceSpecifications(foundationalModelLibrary, factory);
	createPackageInterfaces(foundationalModelLibrary, factory);
	createPackageInterfaceRealizations(foundationalModelLibrary, factory);
	createPackagePrimitiveTypes(foundationalModelLibrary, factory);
	createPackageStereotypes(foundationalModelLibrary, factory);
}

void FoundationalModelLibraryPackageImpl::createPackageActivities(std::shared_ptr<uml::Package> foundationalModelLibrary, std::shared_ptr<uml::umlFactory> factory)
{
}


void FoundationalModelLibraryPackageImpl::createPackageAssociations(std::shared_ptr<uml::Package> foundationalModelLibrary, std::shared_ptr<uml::umlFactory> factory)
{
}

void FoundationalModelLibraryPackageImpl::createPackageClasses(std::shared_ptr<uml::Package> foundationalModelLibrary, std::shared_ptr<uml::umlFactory> factory)
{
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;


//-------------------------------------------
//Opaque Behaviors

}

void FoundationalModelLibraryPackageImpl::createPackageDataTypes(std::shared_ptr<uml::Package> foundationalModelLibrary, std::shared_ptr<uml::umlFactory> factory)
{
}

void FoundationalModelLibraryPackageImpl::createPackageDependencies(std::shared_ptr<uml::Package> foundationalModelLibrary, std::shared_ptr<uml::umlFactory> factory)
{
}

void FoundationalModelLibraryPackageImpl::createPackageEnumerationLiterals(std::shared_ptr<uml::Package> foundationalModelLibrary, std::shared_ptr<uml::umlFactory> factory)
{
}

void FoundationalModelLibraryPackageImpl::createPackageInstanceSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary, std::shared_ptr<uml::umlFactory> factory)
{
}

void FoundationalModelLibraryPackageImpl::createPackageInterfaceRealizations(std::shared_ptr<uml::Package> foundationalModelLibrary, std::shared_ptr<uml::umlFactory> factory)
{
}

void FoundationalModelLibraryPackageImpl::createPackageInterfaces(std::shared_ptr<uml::Package> foundationalModelLibrary, std::shared_ptr<uml::umlFactory> factory)
{
}

void FoundationalModelLibraryPackageImpl::createPackagePrimitiveTypes(std::shared_ptr<uml::Package> foundationalModelLibrary, std::shared_ptr<uml::umlFactory> factory)
{
}

void FoundationalModelLibraryPackageImpl::createPackageStereotypes(std::shared_ptr<uml::Package> foundationalModelLibrary, std::shared_ptr<uml::umlFactory> factory)
{
}

void FoundationalModelLibraryPackageImpl::createPackageValueSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary, std::shared_ptr<uml::umlFactory> factory)
{
}

void FoundationalModelLibraryPackageImpl::initializePackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary)
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
void FoundationalModelLibraryPackageImpl::initializePackageActivities()
{
}


void FoundationalModelLibraryPackageImpl::initializePackageAssociations()
{
}

void FoundationalModelLibraryPackageImpl::initializePackageClasses()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;


//-------------------------------------------
//Opaque Behaviors

}

void FoundationalModelLibraryPackageImpl::initializePackageDataTypes()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;

}

void FoundationalModelLibraryPackageImpl::initializePackageDependencies()
{
}

void FoundationalModelLibraryPackageImpl::initializePackageInstanceSpecifications()
{
}


void FoundationalModelLibraryPackageImpl::initializePackageInterfaceRealizations()
{
}

void FoundationalModelLibraryPackageImpl::initializePackageInterfaces()
{
}

void FoundationalModelLibraryPackageImpl::initializePackageNestedPackages()
{
	this->getNestedPackage()->add(getBasicInputOutput_Package());
	this->getNestedPackage()->add(getCommon_Package());
	this->getNestedPackage()->add(getPrimitiveBehaviors_Package());
}

void FoundationalModelLibraryPackageImpl::initializePackageStereotypes()
{
}

void FoundationalModelLibraryPackageImpl::initializePackageValueSpecifications()
{
}




std::shared_ptr<BasicInputOutput::BasicInputOutputPackage> FoundationalModelLibraryPackageImpl::getBasicInputOutput_Package() const
{
	return BasicInputOutput::BasicInputOutputPackage::eInstance();
} 
std::shared_ptr<Common::CommonPackage> FoundationalModelLibraryPackageImpl::getCommon_Package() const
{
	return Common::CommonPackage::eInstance();
} 
std::shared_ptr<PrimitiveBehaviors::PrimitiveBehaviorsPackage> FoundationalModelLibraryPackageImpl::getPrimitiveBehaviors_Package() const
{
	return PrimitiveBehaviors::PrimitiveBehaviorsPackage::eInstance();
} 

