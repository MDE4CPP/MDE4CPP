#include "FoundationalModelLibrary/PrimitiveBehaviors/impl/PrimitiveBehaviorsPackageImpl.hpp"

//meta meta model classes

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/VisibilityKind.hpp"
//meta meta model factory
#include "uml/umlFactory.hpp"

//metamodel factory
#include "FoundationalModelLibrary/PrimitiveBehaviors/PrimitiveBehaviorsFactory.hpp"

//depending model packages

//Superpackage
#include "FoundationalModelLibrary/FoundationalModelLibraryPackage.hpp"

//Subpackages
#include "FoundationalModelLibrary/PrimitiveBehaviors/BooleanFunctions/impl/BooleanFunctionsPackageImpl.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/IntegerFunctions/impl/IntegerFunctionsPackageImpl.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/RealFunctions/impl/RealFunctionsPackageImpl.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/StringFunctions/impl/StringFunctionsPackageImpl.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/UnlimitedNaturalFunctions/impl/UnlimitedNaturalFunctionsPackageImpl.hpp"


using namespace FoundationalModelLibrary::PrimitiveBehaviors;

PrimitiveBehaviorsPackageImpl::PrimitiveBehaviorsPackageImpl()
{
}

PrimitiveBehaviorsPackageImpl::~PrimitiveBehaviorsPackageImpl()
{
}

bool PrimitiveBehaviorsPackageImpl::isInited = false;

PrimitiveBehaviorsPackage* PrimitiveBehaviorsPackageImpl::create()
{
	if (isInited)
	{
		return PrimitiveBehaviorsPackage::eInstance().get();
	}
	isInited = true;
	
    // Obtain or create and register package, create package meta-data objects
    PrimitiveBehaviorsPackageImpl * metaModelPackage = new PrimitiveBehaviorsPackageImpl();
    return metaModelPackage;
}

void PrimitiveBehaviorsPackageImpl::init(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors)
{
    // Initialize created meta-data
	setThisPackagePtr(foundationalModelLibrary_PrimitiveBehaviors);
	initMetaModel();
    createPackageContents(foundationalModelLibrary_PrimitiveBehaviors);
    initializePackageContents(foundationalModelLibrary_PrimitiveBehaviors);   
}

void PrimitiveBehaviorsPackageImpl::initMetaModel()
{
}

void PrimitiveBehaviorsPackageImpl::createPackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors)
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<uml::umlFactory> factory = uml::umlFactory::eInstance();

	createPackageActivities(foundationalModelLibrary_PrimitiveBehaviors, factory);
	createPackageAssociations(foundationalModelLibrary_PrimitiveBehaviors, factory);
	createPackageClasses(foundationalModelLibrary_PrimitiveBehaviors, factory);
	createPackageDataTypes(foundationalModelLibrary_PrimitiveBehaviors, factory);
	createPackageDependencies(foundationalModelLibrary_PrimitiveBehaviors, factory);
	createPackageEnumerationLiterals(foundationalModelLibrary_PrimitiveBehaviors, factory);
	createPackageValueSpecifications(foundationalModelLibrary_PrimitiveBehaviors, factory);
	createPackageInstanceSpecifications(foundationalModelLibrary_PrimitiveBehaviors, factory);
	createPackageInterfaces(foundationalModelLibrary_PrimitiveBehaviors, factory);
	createPackageInterfaceRealizations(foundationalModelLibrary_PrimitiveBehaviors, factory);
	createPackagePrimitiveTypes(foundationalModelLibrary_PrimitiveBehaviors, factory);
	createPackageStereotypes(foundationalModelLibrary_PrimitiveBehaviors, factory);
}

void PrimitiveBehaviorsPackageImpl::createPackageActivities(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors, std::shared_ptr<uml::umlFactory> factory)
{
}


void PrimitiveBehaviorsPackageImpl::createPackageAssociations(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveBehaviorsPackageImpl::createPackageClasses(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors, std::shared_ptr<uml::umlFactory> factory)
{
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;


//-------------------------------------------
//Opaque Behaviors

}

void PrimitiveBehaviorsPackageImpl::createPackageDataTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveBehaviorsPackageImpl::createPackageDependencies(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveBehaviorsPackageImpl::createPackageEnumerationLiterals(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveBehaviorsPackageImpl::createPackageInstanceSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveBehaviorsPackageImpl::createPackageInterfaceRealizations(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveBehaviorsPackageImpl::createPackageInterfaces(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveBehaviorsPackageImpl::createPackagePrimitiveTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveBehaviorsPackageImpl::createPackageStereotypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveBehaviorsPackageImpl::createPackageValueSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors, std::shared_ptr<uml::umlFactory> factory)
{
}

void PrimitiveBehaviorsPackageImpl::initializePackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors)
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
void PrimitiveBehaviorsPackageImpl::initializePackageActivities()
{
}


void PrimitiveBehaviorsPackageImpl::initializePackageAssociations()
{
}

void PrimitiveBehaviorsPackageImpl::initializePackageClasses()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;


//-------------------------------------------
//Opaque Behaviors

}

void PrimitiveBehaviorsPackageImpl::initializePackageDataTypes()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;

}

void PrimitiveBehaviorsPackageImpl::initializePackageDependencies()
{
}

void PrimitiveBehaviorsPackageImpl::initializePackageInstanceSpecifications()
{
}


void PrimitiveBehaviorsPackageImpl::initializePackageInterfaceRealizations()
{
}

void PrimitiveBehaviorsPackageImpl::initializePackageInterfaces()
{
}

void PrimitiveBehaviorsPackageImpl::initializePackageNestedPackages()
{
	this->getNestedPackage()->add(getBooleanFunctions_Package());
	this->getNestedPackage()->add(getIntegerFunctions_Package());
	this->getNestedPackage()->add(getRealFunctions_Package());
	this->getNestedPackage()->add(getStringFunctions_Package());
	this->getNestedPackage()->add(getUnlimitedNaturalFunctions_Package());
}

void PrimitiveBehaviorsPackageImpl::initializePackageStereotypes()
{
}

void PrimitiveBehaviorsPackageImpl::initializePackageValueSpecifications()
{
}




std::shared_ptr<BooleanFunctions::BooleanFunctionsPackage> PrimitiveBehaviorsPackageImpl::getBooleanFunctions_Package() const
{
	return BooleanFunctions::BooleanFunctionsPackage::eInstance();
} 
std::shared_ptr<IntegerFunctions::IntegerFunctionsPackage> PrimitiveBehaviorsPackageImpl::getIntegerFunctions_Package() const
{
	return IntegerFunctions::IntegerFunctionsPackage::eInstance();
} 
std::shared_ptr<RealFunctions::RealFunctionsPackage> PrimitiveBehaviorsPackageImpl::getRealFunctions_Package() const
{
	return RealFunctions::RealFunctionsPackage::eInstance();
} 
std::shared_ptr<StringFunctions::StringFunctionsPackage> PrimitiveBehaviorsPackageImpl::getStringFunctions_Package() const
{
	return StringFunctions::StringFunctionsPackage::eInstance();
} 
std::shared_ptr<UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage> PrimitiveBehaviorsPackageImpl::getUnlimitedNaturalFunctions_Package() const
{
	return UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::eInstance();
} 

