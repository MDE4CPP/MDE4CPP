#include "FoundationalModelLibrary/PrimitiveBehaviors/BooleanFunctions/impl/BooleanFunctionsPackageImpl.hpp"

//meta meta model classes
#include "uml/FunctionBehavior.hpp"
#include "uml/LiteralInteger.hpp"
#include "uml/Parameter.hpp"
#include "uml/PrimitiveType.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/VisibilityKind.hpp"
//meta meta model factory
#include "uml/umlFactory.hpp"

//metamodel factory
#include "FoundationalModelLibrary/PrimitiveBehaviors/BooleanFunctions/BooleanFunctionsFactory.hpp"

//depending model packages
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"

//Superpackage
#include "FoundationalModelLibrary/PrimitiveBehaviors/PrimitiveBehaviorsPackage.hpp"



using namespace FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions;

//Singleton implemenation
std::shared_ptr<BooleanFunctionsPackage> BooleanFunctionsPackage::eInstance()
{
	static std::shared_ptr<BooleanFunctionsPackage> instance;
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(BooleanFunctionsPackageImpl::create());
		std::dynamic_pointer_cast<BooleanFunctionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialization
const std::string BooleanFunctionsPackage::eNAME ="BooleanFunctions";
const std::string BooleanFunctionsPackage::eNS_URI ="";
const std::string BooleanFunctionsPackage::eNS_PREFIX ="PrimitiveBehaviors";

BooleanFunctionsPackageImpl::BooleanFunctionsPackageImpl()
{
}

BooleanFunctionsPackageImpl::~BooleanFunctionsPackageImpl()
{
}

bool BooleanFunctionsPackageImpl::isInited = false;

BooleanFunctionsPackage* BooleanFunctionsPackageImpl::create()
{
	if (isInited)
	{
		return BooleanFunctionsPackage::eInstance().get();
	}
	isInited = true;
	
    // Obtain or create and register package, create package meta-data objects
    BooleanFunctionsPackageImpl * metaModelPackage = new BooleanFunctionsPackageImpl();
    return metaModelPackage;
}

void BooleanFunctionsPackageImpl::init(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions)
{
    // Initialize created meta-data
	setThisPackagePtr(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions);
	initMetaModel();
    createPackageContents(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions);
    initializePackageContents(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions);   
}

void BooleanFunctionsPackageImpl::initMetaModel()
{
}

void BooleanFunctionsPackageImpl::createPackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions)
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<uml::umlFactory> factory = uml::umlFactory::eInstance();

	createPackageActivities(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, factory);
	createPackageAssociations(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, factory);
	createPackageClasses(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, factory);
	createPackageDataTypes(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, factory);
	createPackageDependencies(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, factory);
	createPackageEnumerationLiterals(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, factory);
	createPackageEvents(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, factory);
	createPackageValueSpecifications(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, factory);
	createPackageInstanceSpecifications(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, factory);
	createPackageInterfaces(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, factory);
	createPackageInterfaceRealizations(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, factory);
	createPackagePrimitiveTypes(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, factory);
	createPackageSignals(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, factory);
	createPackageStereotypes(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, factory);
}

void BooleanFunctionsPackageImpl::createPackageActivities(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}


void BooleanFunctionsPackageImpl::createPackageAssociations(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void BooleanFunctionsPackageImpl::createPackageClasses(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory)
{
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;


//-------------------------------------------
//Opaque Behaviors

	//Xor
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor);
	
	//And
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And);
	
	//ToBoolean
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean);
	
	//Not
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not);
	
	//Or
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or);
	
	//Implies
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies);
	
	//ToString
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString);
	
}

void BooleanFunctionsPackageImpl::createPackageSignals(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory)
{
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;

}

void BooleanFunctionsPackageImpl::createPackageDataTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void BooleanFunctionsPackageImpl::createPackageDependencies(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void BooleanFunctionsPackageImpl::createPackageEnumerationLiterals(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void BooleanFunctionsPackageImpl::createPackageEvents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void BooleanFunctionsPackageImpl::createPackageInstanceSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void BooleanFunctionsPackageImpl::createPackageInterfaceRealizations(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void BooleanFunctionsPackageImpl::createPackageInterfaces(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void BooleanFunctionsPackageImpl::createPackagePrimitiveTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void BooleanFunctionsPackageImpl::createPackageStereotypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void BooleanFunctionsPackageImpl::createPackageValueSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory)
{
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result_lowerValue_LiteralInteger_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result = factory->createLiteralInteger_as_ownedElement_in_Element(foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result);
	
}

void BooleanFunctionsPackageImpl::initializePackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions)
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	this->setName(eNAME);
	this->setURI(eNS_URI);
	this->setNestingPackage(FoundationalModelLibrary::PrimitiveBehaviors::PrimitiveBehaviorsPackage::eInstance());

	initializePackageActivities();
	initializePackageAssociations();
	initializePackageClasses();
	initializePackageDataTypes();
	initializePackageDependencies();
	initializePackageEvents();
	initializePackageInstanceSpecifications();
	initializePackageInterfaceRealizations();
	initializePackageInterfaces();
	initializePackageNestedPackages();
	initializePackageSignals();
	initializePackageStereotypes();
	initializePackageValueSpecifications();
	
}

//ActivityNodes and Edges
void BooleanFunctionsPackageImpl::initializePackageActivities()
{
}


void BooleanFunctionsPackageImpl::initializePackageAssociations()
{
}

void BooleanFunctionsPackageImpl::initializePackageClasses()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;


//-------------------------------------------
//Opaque Behaviors

	//Xor
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor->setName("Xor");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor->_setID(BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_XOR);
	
	
	//And
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And->setName("And");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And->_setID(BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_AND);
	
	
	//ToBoolean
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean->setName("ToBoolean");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result->setLower(0);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean->_setID(BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_TOBOOLEAN);
	
	
	//Not
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not->setName("Not");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not->_setID(BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_NOT);
	
	
	//Or
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or->setName("Or");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or->_setID(BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_OR);
	
	
	//Implies
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies->setName("Implies");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies->_setID(BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_IMPLIES);
	
	
	//ToString
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString->setName("ToString");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString->_setID(BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING);
	
	
}

void BooleanFunctionsPackageImpl::initializePackageSignals()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;


//-------------------------------------------
//Opaque Behaviors

	//Xor
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor->setName("Xor");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor->_setID(BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_XOR);
	
	
	//And
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And->setName("And");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And->_setID(BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_AND);
	
	
	//ToBoolean
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean->setName("ToBoolean");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result->setLower(0);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean->_setID(BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_TOBOOLEAN);
	
	
	//Not
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not->setName("Not");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not->_setID(BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_NOT);
	
	
	//Or
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or->setName("Or");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or->_setID(BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_OR);
	
	
	//Implies
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies->setName("Implies");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies->_setID(BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_IMPLIES);
	
	
	//ToString
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString->setName("ToString");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString->_setID(BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING);
	
	
}

void BooleanFunctionsPackageImpl::initializePackageDataTypes()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;

}

void BooleanFunctionsPackageImpl::initializePackageDependencies()
{
}

void BooleanFunctionsPackageImpl::initializePackageEvents()
{
}

void BooleanFunctionsPackageImpl::initializePackageInstanceSpecifications()
{
}


void BooleanFunctionsPackageImpl::initializePackageInterfaceRealizations()
{
}

void BooleanFunctionsPackageImpl::initializePackageInterfaces()
{
}

void BooleanFunctionsPackageImpl::initializePackageNestedPackages()
{
}

void BooleanFunctionsPackageImpl::initializePackageStereotypes()
{
}

void BooleanFunctionsPackageImpl::initializePackageValueSpecifications()
{
	foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result_lowerValue_LiteralInteger_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result->setValue(0);
}

const std::shared_ptr<uml::FunctionBehavior>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y;
}
const std::shared_ptr<uml::FunctionBehavior>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y;
}
const std::shared_ptr<uml::FunctionBehavior>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x;
}
const std::shared_ptr<uml::FunctionBehavior>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y;
}
const std::shared_ptr<uml::FunctionBehavior>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x;
}
const std::shared_ptr<uml::FunctionBehavior>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x;
}
const std::shared_ptr<uml::FunctionBehavior>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x;
}
const std::shared_ptr<uml::Parameter>& BooleanFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y;
}




