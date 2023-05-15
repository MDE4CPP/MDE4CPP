#include "FoundationalModelLibrary/PrimitiveBehaviors/RealFunctions/impl/RealFunctionsPackageImpl.hpp"

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
#include "FoundationalModelLibrary/PrimitiveBehaviors/RealFunctions/RealFunctionsFactory.hpp"

//depending model packages
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"

//Superpackage
#include "FoundationalModelLibrary/PrimitiveBehaviors/PrimitiveBehaviorsPackage.hpp"



using namespace FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions;

//Singleton implemenation
std::shared_ptr<RealFunctionsPackage> RealFunctionsPackage::eInstance()
{
	static std::shared_ptr<RealFunctionsPackage> instance;
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(RealFunctionsPackageImpl::create());
		std::dynamic_pointer_cast<RealFunctionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialization
const std::string RealFunctionsPackage::eNAME ="RealFunctions";
const std::string RealFunctionsPackage::eNS_URI ="";
const std::string RealFunctionsPackage::eNS_PREFIX ="PrimitiveBehaviors";

RealFunctionsPackageImpl::RealFunctionsPackageImpl()
{
}

RealFunctionsPackageImpl::~RealFunctionsPackageImpl()
{
}

bool RealFunctionsPackageImpl::isInited = false;

RealFunctionsPackage* RealFunctionsPackageImpl::create()
{
	if (isInited)
	{
		return RealFunctionsPackage::eInstance().get();
	}
	isInited = true;
	
    // Obtain or create and register package, create package meta-data objects
    RealFunctionsPackageImpl * metaModelPackage = new RealFunctionsPackageImpl();
    return metaModelPackage;
}

void RealFunctionsPackageImpl::init(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions)
{
    // Initialize created meta-data
	setThisPackagePtr(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	initMetaModel();
    createPackageContents(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
    initializePackageContents(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);   
}

void RealFunctionsPackageImpl::initMetaModel()
{
}

void RealFunctionsPackageImpl::createPackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions)
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<uml::umlFactory> factory = uml::umlFactory::eInstance();

	createPackageActivities(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, factory);
	createPackageAssociations(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, factory);
	createPackageClasses(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, factory);
	createPackageDataTypes(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, factory);
	createPackageDependencies(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, factory);
	createPackageEnumerationLiterals(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, factory);
	createPackageValueSpecifications(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, factory);
	createPackageInstanceSpecifications(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, factory);
	createPackageInterfaces(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, factory);
	createPackageInterfaceRealizations(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, factory);
	createPackagePrimitiveTypes(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, factory);
	createPackageStereotypes(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, factory);
}

void RealFunctionsPackageImpl::createPackageActivities(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}


void RealFunctionsPackageImpl::createPackageAssociations(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void RealFunctionsPackageImpl::createPackageClasses(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory)
{
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;


//-------------------------------------------
//Opaque Behaviors

	//greaterThan
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan);
	
	//times
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times);
	
	//Round
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round);
	
	//greaterOrEqual
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual);
	
	//ToInteger
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger);
	
	//ToString
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString);
	
	//Max
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max);
	
	//Min
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min);
	
	//Floor
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor);
	
	//divide
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide);
	
	//minus
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus);
	
	//Neg
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg);
	
	//lessThan
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan);
	
	//lessOrEqual
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual);
	
	//ToReal
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal);
	
	//Abs
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs);
	
	//plus
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus);
	
	//Inv
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv);
	
}

void RealFunctionsPackageImpl::createPackageDataTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void RealFunctionsPackageImpl::createPackageDependencies(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void RealFunctionsPackageImpl::createPackageEnumerationLiterals(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void RealFunctionsPackageImpl::createPackageInstanceSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void RealFunctionsPackageImpl::createPackageInterfaceRealizations(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void RealFunctionsPackageImpl::createPackageInterfaces(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void RealFunctionsPackageImpl::createPackagePrimitiveTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void RealFunctionsPackageImpl::createPackageStereotypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void RealFunctionsPackageImpl::createPackageValueSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory)
{
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result_lowerValue_LiteralInteger_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result = factory->createLiteralInteger_as_ownedElement_in_Element(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result_lowerValue_LiteralInteger_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result = factory->createLiteralInteger_as_ownedElement_in_Element(foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result);
	
}

void RealFunctionsPackageImpl::initializePackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions)
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
	initializePackageInstanceSpecifications();
	initializePackageInterfaceRealizations();
	initializePackageInterfaces();
	initializePackageNestedPackages();
	initializePackageStereotypes();
	initializePackageValueSpecifications();
	
}

//ActivityNodes and Edges
void RealFunctionsPackageImpl::initializePackageActivities()
{
}


void RealFunctionsPackageImpl::initializePackageAssociations()
{
}

void RealFunctionsPackageImpl::initializePackageClasses()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;


//-------------------------------------------
//Opaque Behaviors

	//greaterThan
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan->setName("greaterThan");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_GREATERTHAN);
	
	
	//times
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times->setName("times");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_TIMES);
	
	
	//Round
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round->setName("Round");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_ROUND);
	
	
	//greaterOrEqual
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual->setName("greaterOrEqual");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_GREATEROREQUAL);
	
	
	//ToInteger
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger->setName("ToInteger");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_TOINTEGER);
	
	
	//ToString
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString->setName("ToString");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING);
	
	
	//Max
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max->setName("Max");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_MAX);
	
	
	//Min
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min->setName("Min");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_MIN);
	
	
	//Floor
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor->setName("Floor");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_FLOOR);
	
	
	//divide
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide->setName("divide");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result->setLower(0);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_DIVIDE);
	
	
	//minus
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus->setName("minus");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_MINUS);
	
	
	//Neg
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg->setName("Neg");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_NEG);
	
	
	//lessThan
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan->setName("lessThan");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_LESSTHAN);
	
	
	//lessOrEqual
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual->setName("lessOrEqual");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_LESSOREQUAL);
	
	
	//ToReal
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal->setName("ToReal");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result->setLower(0);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_TOREAL);
	
	
	//Abs
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs->setName("Abs");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_ABS);
	
	
	//plus
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus->setName("plus");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_PLUS);
	
	
	//Inv
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv->setName("Inv");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real());
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv->_setID(REALFUNCTIONS_FUNCTIONBEHAVIOR_INV);
	
	
}

void RealFunctionsPackageImpl::initializePackageDataTypes()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;

}

void RealFunctionsPackageImpl::initializePackageDependencies()
{
}

void RealFunctionsPackageImpl::initializePackageInstanceSpecifications()
{
}


void RealFunctionsPackageImpl::initializePackageInterfaceRealizations()
{
}

void RealFunctionsPackageImpl::initializePackageInterfaces()
{
}

void RealFunctionsPackageImpl::initializePackageNestedPackages()
{
}

void RealFunctionsPackageImpl::initializePackageStereotypes()
{
}

void RealFunctionsPackageImpl::initializePackageValueSpecifications()
{
	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result_lowerValue_LiteralInteger_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result->setValue(0);

	foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result_lowerValue_LiteralInteger_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result->setValue(0);
}

std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_x;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_x;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_x;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_x;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_y;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_x;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_y;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_x;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_x;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_x;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_x;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_x;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_x;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_y;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_x;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_y;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_x;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_y;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_x;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_y;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_x;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_y;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_x;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_y;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_x;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_y;
}
std::shared_ptr<uml::FunctionBehavior> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_result;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_x;
}
std::shared_ptr<uml::Parameter> RealFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_y;
}




