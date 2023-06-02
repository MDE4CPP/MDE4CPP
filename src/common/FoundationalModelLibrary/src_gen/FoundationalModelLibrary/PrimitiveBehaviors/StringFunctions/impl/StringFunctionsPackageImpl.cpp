#include "FoundationalModelLibrary/PrimitiveBehaviors/StringFunctions/impl/StringFunctionsPackageImpl.hpp"

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
#include "FoundationalModelLibrary/PrimitiveBehaviors/StringFunctions/StringFunctionsFactory.hpp"

//depending model packages
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"

//Superpackage
#include "FoundationalModelLibrary/PrimitiveBehaviors/PrimitiveBehaviorsPackage.hpp"



using namespace FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions;

//Singleton implemenation
std::shared_ptr<StringFunctionsPackage> StringFunctionsPackage::eInstance()
{
	static std::shared_ptr<StringFunctionsPackage> instance;
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(StringFunctionsPackageImpl::create());
		std::dynamic_pointer_cast<StringFunctionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialization
const std::string StringFunctionsPackage::eNAME ="StringFunctions";
const std::string StringFunctionsPackage::eNS_URI ="";
const std::string StringFunctionsPackage::eNS_PREFIX ="PrimitiveBehaviors";

StringFunctionsPackageImpl::StringFunctionsPackageImpl()
{
}

StringFunctionsPackageImpl::~StringFunctionsPackageImpl()
{
}

bool StringFunctionsPackageImpl::isInited = false;

StringFunctionsPackage* StringFunctionsPackageImpl::create()
{
	if (isInited)
	{
		return StringFunctionsPackage::eInstance().get();
	}
	isInited = true;
	
    // Obtain or create and register package, create package meta-data objects
    StringFunctionsPackageImpl * metaModelPackage = new StringFunctionsPackageImpl();
    return metaModelPackage;
}

void StringFunctionsPackageImpl::init(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions)
{
    // Initialize created meta-data
	setThisPackagePtr(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions);
	initMetaModel();
    createPackageContents(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions);
    initializePackageContents(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions);   
}

void StringFunctionsPackageImpl::initMetaModel()
{
}

void StringFunctionsPackageImpl::createPackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions)
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<uml::umlFactory> factory = uml::umlFactory::eInstance();

	createPackageActivities(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, factory);
	createPackageAssociations(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, factory);
	createPackageClasses(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, factory);
	createPackageDataTypes(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, factory);
	createPackageDependencies(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, factory);
	createPackageEnumerationLiterals(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, factory);
	createPackageValueSpecifications(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, factory);
	createPackageInstanceSpecifications(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, factory);
	createPackageInterfaces(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, factory);
	createPackageInterfaceRealizations(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, factory);
	createPackagePrimitiveTypes(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, factory);
	createPackageStereotypes(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, factory);
}

void StringFunctionsPackageImpl::createPackageActivities(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}


void StringFunctionsPackageImpl::createPackageAssociations(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void StringFunctionsPackageImpl::createPackageClasses(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, std::shared_ptr<uml::umlFactory> factory)
{
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;


//-------------------------------------------
//Opaque Behaviors

	//Size
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size);
	
	//Substring
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_lower = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_upper = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring);
	
	//Concat
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat = factory->createFunctionBehavior_as_ownedType_in_Package(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_x = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_y = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_result = factory->createParameter_as_ownedParameter_in_Behavior(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat);
	
}

void StringFunctionsPackageImpl::createPackageDataTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void StringFunctionsPackageImpl::createPackageDependencies(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void StringFunctionsPackageImpl::createPackageEnumerationLiterals(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void StringFunctionsPackageImpl::createPackageInstanceSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void StringFunctionsPackageImpl::createPackageInterfaceRealizations(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void StringFunctionsPackageImpl::createPackageInterfaces(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void StringFunctionsPackageImpl::createPackagePrimitiveTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void StringFunctionsPackageImpl::createPackageStereotypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, std::shared_ptr<uml::umlFactory> factory)
{
}

void StringFunctionsPackageImpl::createPackageValueSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions, std::shared_ptr<uml::umlFactory> factory)
{
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_result_lowerValue_LiteralInteger_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_result = factory->createLiteralInteger_as_ownedElement_in_Element(foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_result);
	
}

void StringFunctionsPackageImpl::initializePackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_StringFunctions)
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
void StringFunctionsPackageImpl::initializePackageActivities()
{
}


void StringFunctionsPackageImpl::initializePackageAssociations()
{
}

void StringFunctionsPackageImpl::initializePackageClasses()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;


//-------------------------------------------
//Opaque Behaviors

	//Size
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size->setName("Size");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size->_setID(STRINGFUNCTIONS_FUNCTIONBEHAVIOR_SIZE);
	
	
	//Substring
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring->setName("Substring");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter lower
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_lower->setName("lower");
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_lower->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_lower->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_lower->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_lower->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter upper
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_upper->setName("upper");
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_upper->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_upper->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_upper->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_upper->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_result->setLower(0);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring->_setID(STRINGFUNCTIONS_FUNCTIONBEHAVIOR_SUBSTRING);
	
	
	//Concat
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat->setName("Concat");
	// parameter x
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_x->setName("x");
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_x->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_x->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_x->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_x->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter y
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_y->setName("y");
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_y->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_y->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_y->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_y->setDirection(uml::ParameterDirectionKind::IN);
	
	// parameter result
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_result->setName("result");
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_result->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_result->setLower(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_result->setUpper(1);
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_result->setDirection(uml::ParameterDirectionKind::RETURN);
	
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat->_setID(STRINGFUNCTIONS_FUNCTIONBEHAVIOR_CONCAT);
	
	
}

void StringFunctionsPackageImpl::initializePackageDataTypes()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;

}

void StringFunctionsPackageImpl::initializePackageDependencies()
{
}

void StringFunctionsPackageImpl::initializePackageInstanceSpecifications()
{
}


void StringFunctionsPackageImpl::initializePackageInterfaceRealizations()
{
}

void StringFunctionsPackageImpl::initializePackageInterfaces()
{
}

void StringFunctionsPackageImpl::initializePackageNestedPackages()
{
}

void StringFunctionsPackageImpl::initializePackageStereotypes()
{
}

void StringFunctionsPackageImpl::initializePackageValueSpecifications()
{
	foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_result_lowerValue_LiteralInteger_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_result->setValue(0);
}

const std::shared_ptr<uml::FunctionBehavior>& StringFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat()
{
	return foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat;
}
const std::shared_ptr<uml::Parameter>& StringFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_result;
}
const std::shared_ptr<uml::Parameter>& StringFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_x;
}
const std::shared_ptr<uml::Parameter>& StringFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_y()
{
	return foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_y;
}
const std::shared_ptr<uml::FunctionBehavior>& StringFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size()
{
	return foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size;
}
const std::shared_ptr<uml::Parameter>& StringFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_result;
}
const std::shared_ptr<uml::Parameter>& StringFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_x;
}
const std::shared_ptr<uml::FunctionBehavior>& StringFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring()
{
	return foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring;
}
const std::shared_ptr<uml::Parameter>& StringFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_lower()
{
	return foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_lower;
}
const std::shared_ptr<uml::Parameter>& StringFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_result()
{
	return foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_result;
}
const std::shared_ptr<uml::Parameter>& StringFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_upper()
{
	return foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_upper;
}
const std::shared_ptr<uml::Parameter>& StringFunctionsPackageImpl::get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_x()
{
	return foundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_x;
}




