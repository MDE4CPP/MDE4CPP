#include "CalcModelPackageImpl.hpp"

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

#include "Activity.hpp"
#include "ActivityFinalNode.hpp"
#include "ActivityParameterNode.hpp"
#include "CallBehaviorAction.hpp"
#include "CallOperationAction.hpp"
#include "Class.hpp"
#include "ControlFlow.hpp"
#include "DecisionNode.hpp"
#include "ForkNode.hpp"
#include "FunctionBehavior.hpp"
#include "InputPin.hpp"
#include "LiteralBoolean.hpp"
#include "LiteralInteger.hpp"
#include "LiteralString.hpp"
#include "MergeNode.hpp"
#include "ObjectFlow.hpp"
#include "Operation.hpp"
#include "OutputPin.hpp"
#include "Parameter.hpp"
#include "ProfileApplication.hpp"
#include "Property.hpp"
//metamodel factory
#include "CalcModelFactory.hpp"
#include "UmlFactory.hpp"

//depending model packages
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"



using namespace CalcModel;

CalcModelPackageImpl::CalcModelPackageImpl()
{
}

CalcModelPackageImpl::~CalcModelPackageImpl()
{
}

bool CalcModelPackageImpl::isInited = false;

CalcModelPackage* CalcModelPackageImpl::create()
{
	if (isInited)
	{
		return CalcModelPackage::eInstance().get();
	}
	isInited = true;
	
    // Obtain or create and register package, create package meta-data objects
    CalcModelPackageImpl * metaModelPackage = new CalcModelPackageImpl();
	metaModelPackage->initMetaModel();
    metaModelPackage->createPackageContents();
    return metaModelPackage;
}

void CalcModelPackageImpl::init()
{
    // Initialize created meta-data
    initializePackageContents();   
}

void CalcModelPackageImpl::initMetaModel()
{
}

void CalcModelPackageImpl::createPackageContents()
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;

	struct null_deleter{void operator()(void const *) const {} };
	std::shared_ptr<CalcModelPackageImpl> calcModel = std::shared_ptr<CalcModelPackageImpl>(this, null_deleter());
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;
	
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge = uml::UmlFactory::eInstance()->createLiteralBoolean_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge));
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge->setValue(true);
	
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2 = uml::UmlFactory::eInstance()->createLiteralBoolean_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2));
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2->setValue(false);
	
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides = uml::UmlFactory::eInstance()->createLiteralBoolean_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides));
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides->setValue(true);
	
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides_weight_LiteralInteger_CF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides));
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides_weight_LiteralInteger_CF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides->setValue(0);
	
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3 = uml::UmlFactory::eInstance()->createLiteralBoolean_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3));
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3->setValue(true);
	
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3_weight_LiteralInteger_CF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3 = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3));
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3_weight_LiteralInteger_CF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3->setValue(0);
	
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1 = uml::UmlFactory::eInstance()->createLiteralBoolean_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1));
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1->setValue(true);
	
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1_weight_LiteralInteger_CF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1 = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1));
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1_weight_LiteralInteger_CF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1->setValue(0);
	
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2 = uml::UmlFactory::eInstance()->createLiteralBoolean_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2));
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2->setValue(true);
	
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2_weight_LiteralInteger_CF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2 = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2));
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2_weight_LiteralInteger_CF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2->setValue(0);
	
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime = uml::UmlFactory::eInstance()->createLiteralBoolean_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime));
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime->setValue(true);
	
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime_weight_LiteralInteger_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime));
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime_weight_LiteralInteger_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime->setValue(0);
	
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call = uml::UmlFactory::eInstance()->createLiteralBoolean_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call));
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call->setValue(false);
	
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call_weight_LiteralInteger_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call));
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call_weight_LiteralInteger_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call->setValue(0);
	
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge = uml::UmlFactory::eInstance()->createLiteralBoolean_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge));
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge->setValue(true);
	
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime = uml::UmlFactory::eInstance()->createLiteralBoolean_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime));
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime->setValue(false);
	
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime_weight_LiteralInteger_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime));
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime_weight_LiteralInteger_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime->setValue(0);
	
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished = uml::UmlFactory::eInstance()->createLiteralBoolean_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished));
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished->setValue(true);
	
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished_weight_LiteralInteger_CF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished));
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished_weight_LiteralInteger_CF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished->setValue(0);
	
	calcModel_CheckIfPrimeprimeChecker_upperBound_LiteralInteger_CalcModel_CheckIfPrimeprimeChecker = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(calcModel_CheckIfPrimeprimeChecker));
	calcModel_CheckIfPrimeprimeChecker_upperBound_LiteralInteger_CalcModel_CheckIfPrimeprimeChecker->setValue(1);
	
	calcModel_PrimeChecker_divider_defaultValue_LiteralInteger_CalcModel_PrimeChecker_divider = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(calcModel_PrimeChecker_divider));
	calcModel_PrimeChecker_divider_defaultValue_LiteralInteger_CalcModel_PrimeChecker_divider->setValue(3);
	
	calcModel_PrimeChecker_divides_isDivisible_defaultValue_LiteralString_CalcModel_PrimeChecker_divides_isDivisible = uml::UmlFactory::eInstance()->createLiteralString_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(calcModel_PrimeChecker_divides_isDivisible));
	calcModel_PrimeChecker_divides_isDivisible_defaultValue_LiteralString_CalcModel_PrimeChecker_divides_isDivisible->setValue("");
	
	calcModel_PrimeChecker_fbDivides_isDivisible_defaultValue_LiteralString_CalcModel_PrimeChecker_fbDivides_isDivisible = uml::UmlFactory::eInstance()->createLiteralString_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(calcModel_PrimeChecker_fbDivides_isDivisible));
	calcModel_PrimeChecker_fbDivides_isDivisible_defaultValue_LiteralString_CalcModel_PrimeChecker_fbDivides_isDivisible->setValue("");
	
	calcModel_PrimeChecker_fbIsOdd_isOdd_defaultValue_LiteralString_CalcModel_PrimeChecker_fbIsOdd_isOdd = uml::UmlFactory::eInstance()->createLiteralString_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(calcModel_PrimeChecker_fbIsOdd_isOdd));
	calcModel_PrimeChecker_fbIsOdd_isOdd_defaultValue_LiteralString_CalcModel_PrimeChecker_fbIsOdd_isOdd->setValue("");
	
	calcModel_PrimeChecker_isOdd_isOdd_defaultValue_LiteralString_CalcModel_PrimeChecker_isOdd_isOdd = uml::UmlFactory::eInstance()->createLiteralString_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(calcModel_PrimeChecker_isOdd_isOdd));
	calcModel_PrimeChecker_isOdd_isOdd_defaultValue_LiteralString_CalcModel_PrimeChecker_isOdd_isOdd->setValue("");
	
	calcModel_PrimeChecker_number_defaultValue_LiteralInteger_CalcModel_PrimeChecker_number = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(calcModel_PrimeChecker_number));
	calcModel_PrimeChecker_number_defaultValue_LiteralInteger_CalcModel_PrimeChecker_number->setValue(8191);
	
	


	calcModel_PrimeChecker = uml::UmlFactory::eInstance()->createClass_in_Package(calcModel);
	calcModel_PrimeChecker->setName("PrimeChecker");
	calcModel_PrimeChecker->setIsAbstract(false);
	
	//constraints
	
	
	calcModel_PrimeChecker_divider = uml::UmlFactory::eInstance()->createProperty_in_Class(calcModel_PrimeChecker);
	
	calcModel_PrimeChecker_divider->setName("divider");
	calcModel_PrimeChecker_divider->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	calcModel_PrimeChecker_divider->setLower(1);
	calcModel_PrimeChecker_divider->setUpper(1);
	
	calcModel_PrimeChecker_divider->setDefaultValue(calcModel_PrimeChecker_divider_defaultValue_LiteralInteger_CalcModel_PrimeChecker_divider);
	
	calcModel_PrimeChecker_number = uml::UmlFactory::eInstance()->createProperty_in_Class(calcModel_PrimeChecker);
	
	calcModel_PrimeChecker_number->setName("number");
	calcModel_PrimeChecker_number->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	calcModel_PrimeChecker_number->setLower(1);
	calcModel_PrimeChecker_number->setUpper(1);
	
	calcModel_PrimeChecker_number->setDefaultValue(calcModel_PrimeChecker_number_defaultValue_LiteralInteger_CalcModel_PrimeChecker_number);
	
	
	calcModel_PrimeChecker_divides_ = uml::UmlFactory::eInstance()->createOperation_in_Class(calcModel_PrimeChecker);calcModel_PrimeChecker_divides_->setName("divides");
	//Operation
	calcModel_PrimeChecker_divides_isDivisible = uml::UmlFactory::eInstance()->createParameter_in_Operation(calcModel_PrimeChecker_divides_);
	
	calcModel_PrimeChecker_divides_isDivisible->setName("isDivisible");
	calcModel_PrimeChecker_divides_isDivisible->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	calcModel_PrimeChecker_divides_isDivisible->setLower(1);
	calcModel_PrimeChecker_divides_isDivisible->setUpper(1);
	calcModel_PrimeChecker_divides_isDivisible->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	calcModel_PrimeChecker_isNotFinished_ = uml::UmlFactory::eInstance()->createOperation_in_Class(calcModel_PrimeChecker);calcModel_PrimeChecker_isNotFinished_->setName("isNotFinished");
	//Operation
	calcModel_PrimeChecker_isNotFinished_isNotFinished = uml::UmlFactory::eInstance()->createParameter_in_Operation(calcModel_PrimeChecker_isNotFinished_);
	
	calcModel_PrimeChecker_isNotFinished_isNotFinished->setName("isNotFinished");
	calcModel_PrimeChecker_isNotFinished_isNotFinished->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	calcModel_PrimeChecker_isNotFinished_isNotFinished->setLower(1);
	calcModel_PrimeChecker_isNotFinished_isNotFinished->setUpper(1);
	calcModel_PrimeChecker_isNotFinished_isNotFinished->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	calcModel_PrimeChecker_isOdd_ = uml::UmlFactory::eInstance()->createOperation_in_Class(calcModel_PrimeChecker);calcModel_PrimeChecker_isOdd_->setName("isOdd");
	//Operation
	calcModel_PrimeChecker_isOdd_isOdd = uml::UmlFactory::eInstance()->createParameter_in_Operation(calcModel_PrimeChecker_isOdd_);
	
	calcModel_PrimeChecker_isOdd_isOdd->setName("isOdd");
	calcModel_PrimeChecker_isOdd_isOdd->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	calcModel_PrimeChecker_isOdd_isOdd->setLower(1);
	calcModel_PrimeChecker_isOdd_isOdd->setUpper(1);
	calcModel_PrimeChecker_isOdd_isOdd->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	calcModel_PrimeChecker_next_ = uml::UmlFactory::eInstance()->createOperation_in_Class(calcModel_PrimeChecker);calcModel_PrimeChecker_next_->setName("next");
	
	calcModel_PrimeChecker_printIsPrime_ = uml::UmlFactory::eInstance()->createOperation_in_Class(calcModel_PrimeChecker);calcModel_PrimeChecker_printIsPrime_->setName("printIsPrime");
	
	calcModel_PrimeChecker_printNotPrime_ = uml::UmlFactory::eInstance()->createOperation_in_Class(calcModel_PrimeChecker);calcModel_PrimeChecker_printNotPrime_->setName("printNotPrime");
	
	
	calcModel_PrimeChecker_fbNext = uml::UmlFactory::eInstance()->createFunctionBehavior_in_BehavioredClassifier(calcModel_PrimeChecker);
	calcModel_PrimeChecker_fbNext->setName("fbNext");
	
	
	calcModel_PrimeChecker_fbIsNotFinished = uml::UmlFactory::eInstance()->createFunctionBehavior_in_BehavioredClassifier(calcModel_PrimeChecker);
	calcModel_PrimeChecker_fbIsNotFinished->setName("fbIsNotFinished");
	
	//FunctionBehavior
	calcModel_PrimeChecker_fbIsNotFinished_isNotFinished = uml::UmlFactory::eInstance()->createParameter_in_Behavior(calcModel_PrimeChecker_fbIsNotFinished);
	
	calcModel_PrimeChecker_fbIsNotFinished_isNotFinished->setName("isNotFinished");
	calcModel_PrimeChecker_fbIsNotFinished_isNotFinished->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	calcModel_PrimeChecker_fbIsNotFinished_isNotFinished->setLower(1);
	calcModel_PrimeChecker_fbIsNotFinished_isNotFinished->setUpper(1);
	calcModel_PrimeChecker_fbIsNotFinished_isNotFinished->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	calcModel_PrimeChecker_fbIsOdd = uml::UmlFactory::eInstance()->createFunctionBehavior_in_BehavioredClassifier(calcModel_PrimeChecker);
	calcModel_PrimeChecker_fbIsOdd->setName("fbIsOdd");
	
	//FunctionBehavior
	calcModel_PrimeChecker_fbIsOdd_isOdd = uml::UmlFactory::eInstance()->createParameter_in_Behavior(calcModel_PrimeChecker_fbIsOdd);
	
	calcModel_PrimeChecker_fbIsOdd_isOdd->setName("isOdd");
	calcModel_PrimeChecker_fbIsOdd_isOdd->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	calcModel_PrimeChecker_fbIsOdd_isOdd->setLower(1);
	calcModel_PrimeChecker_fbIsOdd_isOdd->setUpper(1);
	calcModel_PrimeChecker_fbIsOdd_isOdd->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	calcModel_PrimeChecker_fbDivides = uml::UmlFactory::eInstance()->createFunctionBehavior_in_BehavioredClassifier(calcModel_PrimeChecker);
	calcModel_PrimeChecker_fbDivides->setName("fbDivides");
	
	//FunctionBehavior
	calcModel_PrimeChecker_fbDivides_isDivisible = uml::UmlFactory::eInstance()->createParameter_in_Behavior(calcModel_PrimeChecker_fbDivides);
	
	calcModel_PrimeChecker_fbDivides_isDivisible->setName("isDivisible");
	calcModel_PrimeChecker_fbDivides_isDivisible->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	calcModel_PrimeChecker_fbDivides_isDivisible->setLower(1);
	calcModel_PrimeChecker_fbDivides_isDivisible->setUpper(1);
	calcModel_PrimeChecker_fbDivides_isDivisible->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	calcModel_PrimeChecker_fbPrintNotPrime = uml::UmlFactory::eInstance()->createFunctionBehavior_in_BehavioredClassifier(calcModel_PrimeChecker);
	calcModel_PrimeChecker_fbPrintNotPrime->setName("fbPrintNotPrime");
	
	
	calcModel_PrimeChecker_fbPrintIsPrime = uml::UmlFactory::eInstance()->createFunctionBehavior_in_BehavioredClassifier(calcModel_PrimeChecker);
	calcModel_PrimeChecker_fbPrintIsPrime->setName("fbPrintIsPrime");
	
	
	




	calcModel_CheckIfPrime = uml::UmlFactory::eInstance()->createActivity_in_Package(calcModel);
	calcModel_CheckIfPrime->setName("CheckIfPrime");
	
	//parameter
	//Activity
	calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode = uml::UmlFactory::eInstance()->createParameter_in_Behavior(calcModel_CheckIfPrime);
	
	calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode->setName("ActInputNode");
	calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode->setType(get_CalcModel_PrimeChecker());
	calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode->setLower(1);
	calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode->setUpper(1);
	calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode->setDirection(uml::ParameterDirectionKind::IN);
	
	
	
	//Node
	calcModel_CheckIfPrimeActivityFinal1 = uml::UmlFactory::eInstance()->createActivityFinalNode_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeActivityFinal1->setName("ActivityFinal1");
	calcModel_CheckIfPrimeActivityFinal2 = uml::UmlFactory::eInstance()->createActivityFinalNode_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeActivityFinal2->setName("ActivityFinal2");
	calcModel_CheckIfPrimeActivityFinal3 = uml::UmlFactory::eInstance()->createActivityFinalNode_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeActivityFinal3->setName("ActivityFinal3");
	calcModel_CheckIfPrimeFork1 = uml::UmlFactory::eInstance()->createForkNode_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeFork1->setName("Fork1");
	calcModel_CheckIfPrimeIsOdd = uml::UmlFactory::eInstance()->createDecisionNode_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeIsOdd->setName("IsOdd");
	calcModel_CheckIfPrimeMerge = uml::UmlFactory::eInstance()->createMergeNode_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeMerge->setName("Merge");
	calcModel_CheckIfPrimecbaPrintIsPrime = uml::UmlFactory::eInstance()->createCallBehaviorAction_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimecbaPrintIsPrime->setName("cbaPrintIsPrime");
	//CallBehaviorAction cbaPrintIsPrime
	calcModel_CheckIfPrimecbaPrintIsPrime->setBehavior(calcModel_PrimeChecker_fbPrintIsPrime);
	calcModel_CheckIfPrimecbaPrintIsPrime->setIsSynchronous(true); //imposed by the fUML specification
	
	calcModel_CheckIfPrimecbaPrintNotPrime = uml::UmlFactory::eInstance()->createCallBehaviorAction_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimecbaPrintNotPrime->setName("cbaPrintNotPrime");
	//CallBehaviorAction cbaPrintNotPrime
	calcModel_CheckIfPrimecbaPrintNotPrime->setBehavior(calcModel_PrimeChecker_fbPrintNotPrime);
	calcModel_CheckIfPrimecbaPrintNotPrime->setIsSynchronous(true); //imposed by the fUML specification
	
	calcModel_CheckIfPrimecbaPrintNotPrime2 = uml::UmlFactory::eInstance()->createCallBehaviorAction_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimecbaPrintNotPrime2->setName("cbaPrintNotPrime2");
	//CallBehaviorAction cbaPrintNotPrime2
	calcModel_CheckIfPrimecbaPrintNotPrime2->setBehavior(calcModel_PrimeChecker_fbPrintNotPrime);
	calcModel_CheckIfPrimecbaPrintNotPrime2->setIsSynchronous(true); //imposed by the fUML specification
	
	calcModel_CheckIfPrimecoaDivides = uml::UmlFactory::eInstance()->createCallOperationAction_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimecoaDivides->setName("coaDivides");
	//CallOperationAction coaDivides
	//Pin owner type: CallOperationAction
	inputPin_coaDividestarget = uml::UmlFactory::eInstance()->createInputPin_in_CallOperationAction(calcModel_CheckIfPrimecoaDivides);
	inputPin_coaDividestarget->setName("target");
	
	//Pin owner type: CallOperationAction
	outputPin_coaDividesisDivisible = uml::UmlFactory::eInstance()->createOutputPin_in_CallAction(calcModel_CheckIfPrimecoaDivides);
	outputPin_coaDividesisDivisible->setName("isDivisible");
	
	calcModel_PrimeChecker_divides_ = uml::UmlFactory::eInstance()->createOperation_in_Class(calcModel_PrimeChecker); //TODO: check if used 
	calcModel_PrimeChecker_divides_->setName("divides");
	
	
	calcModel_CheckIfPrimecoaIsNotFinished = uml::UmlFactory::eInstance()->createCallOperationAction_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimecoaIsNotFinished->setName("coaIsNotFinished");
	//CallOperationAction coaIsNotFinished
	//Pin owner type: CallOperationAction
	inputPin_coaIsNotFinishedtarget = uml::UmlFactory::eInstance()->createInputPin_in_CallOperationAction(calcModel_CheckIfPrimecoaIsNotFinished);
	inputPin_coaIsNotFinishedtarget->setName("target");
	
	//Pin owner type: CallOperationAction
	outputPin_coaIsNotFinishedisNotFinished = uml::UmlFactory::eInstance()->createOutputPin_in_CallAction(calcModel_CheckIfPrimecoaIsNotFinished);
	outputPin_coaIsNotFinishedisNotFinished->setName("isNotFinished");
	
	calcModel_PrimeChecker_isNotFinished_ = uml::UmlFactory::eInstance()->createOperation_in_Class(calcModel_PrimeChecker); //TODO: check if used 
	calcModel_PrimeChecker_isNotFinished_->setName("isNotFinished");
	
	
	calcModel_CheckIfPrimecoaIsOdd = uml::UmlFactory::eInstance()->createCallOperationAction_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimecoaIsOdd->setName("coaIsOdd");
	//CallOperationAction coaIsOdd
	//Pin owner type: CallOperationAction
	inputPin_coaIsOddtarget = uml::UmlFactory::eInstance()->createInputPin_in_CallOperationAction(calcModel_CheckIfPrimecoaIsOdd);
	inputPin_coaIsOddtarget->setName("target");
	
	//Pin owner type: CallOperationAction
	outputPin_coaIsOddisOdd = uml::UmlFactory::eInstance()->createOutputPin_in_CallAction(calcModel_CheckIfPrimecoaIsOdd);
	outputPin_coaIsOddisOdd->setName("isOdd");
	
	calcModel_PrimeChecker_isOdd_ = uml::UmlFactory::eInstance()->createOperation_in_Class(calcModel_PrimeChecker); //TODO: check if used 
	calcModel_PrimeChecker_isOdd_->setName("isOdd");
	
	
	calcModel_CheckIfPrimedivides = uml::UmlFactory::eInstance()->createDecisionNode_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimedivides->setName("divides");
	calcModel_CheckIfPrimeisNotFinished = uml::UmlFactory::eInstance()->createDecisionNode_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeisNotFinished->setName("isNotFinished");
	calcModel_CheckIfPrimenext_call = uml::UmlFactory::eInstance()->createCallOperationAction_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimenext_call->setName("next_call");
	//CallOperationAction next_call
	//Pin owner type: CallOperationAction
	inputPin_next_calltarget = uml::UmlFactory::eInstance()->createInputPin_in_CallOperationAction(calcModel_CheckIfPrimenext_call);
	inputPin_next_calltarget->setName("target");
	
	
	calcModel_PrimeChecker_next_ = uml::UmlFactory::eInstance()->createOperation_in_Class(calcModel_PrimeChecker); //TODO: check if used 
	calcModel_PrimeChecker_next_->setName("next");
	
	
	calcModel_CheckIfPrimeprimeChecker = uml::UmlFactory::eInstance()->createActivityParameterNode_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeprimeChecker->setName("primeChecker");
	
	//flow
	calcModel_CheckIfPrimeifDivides = uml::UmlFactory::eInstance()->createObjectFlow_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeifDivides->setName("ifDivides");
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call = uml::UmlFactory::eInstance()->createControlFlow_in_Activity(calcModel_CheckIfPrime);
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call->setName("");
	oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1 = uml::UmlFactory::eInstance()->createObjectFlow_in_Activity(calcModel_CheckIfPrime);
	oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1->setName("");
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget = uml::UmlFactory::eInstance()->createObjectFlow_in_Activity(calcModel_CheckIfPrime);
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget->setName("");
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides = uml::UmlFactory::eInstance()->createControlFlow_in_Activity(calcModel_CheckIfPrime);
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides->setName("");
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge = uml::UmlFactory::eInstance()->createControlFlow_in_Activity(calcModel_CheckIfPrime);
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge->setName("");
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime = uml::UmlFactory::eInstance()->createControlFlow_in_Activity(calcModel_CheckIfPrime);
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime->setName("");
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1 = uml::UmlFactory::eInstance()->createControlFlow_in_Activity(calcModel_CheckIfPrime);
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1->setName("");
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3 = uml::UmlFactory::eInstance()->createControlFlow_in_Activity(calcModel_CheckIfPrime);
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3->setName("");
	calcModel_CheckIfPrimeifIsOdd = uml::UmlFactory::eInstance()->createObjectFlow_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeifIsOdd->setName("ifIsOdd");
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime = uml::UmlFactory::eInstance()->createControlFlow_in_Activity(calcModel_CheckIfPrime);
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime->setName("");
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget = uml::UmlFactory::eInstance()->createObjectFlow_in_Activity(calcModel_CheckIfPrime);
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget->setName("");
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2 = uml::UmlFactory::eInstance()->createControlFlow_in_Activity(calcModel_CheckIfPrime);
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2->setName("");
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished = uml::UmlFactory::eInstance()->createControlFlow_in_Activity(calcModel_CheckIfPrime);
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished->setName("");
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaDividestarget = uml::UmlFactory::eInstance()->createObjectFlow_in_Activity(calcModel_CheckIfPrime);
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaDividestarget->setName("");
	oF_CalcModel_CheckIfPrimeFork1_InputPin_next_calltarget = uml::UmlFactory::eInstance()->createObjectFlow_in_Activity(calcModel_CheckIfPrime);
	oF_CalcModel_CheckIfPrimeFork1_InputPin_next_calltarget->setName("");
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge = uml::UmlFactory::eInstance()->createControlFlow_in_Activity(calcModel_CheckIfPrime);
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge->setName("");
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2 = uml::UmlFactory::eInstance()->createControlFlow_in_Activity(calcModel_CheckIfPrime);
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2->setName("");
	calcModel_CheckIfPrimeifIsNotFinished = uml::UmlFactory::eInstance()->createObjectFlow_in_Activity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeifIsNotFinished->setName("ifIsNotFinished");
	

//Dependency 

	

}

void CalcModelPackageImpl::initializePackageContents()
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
	std::shared_ptr<CalcModelPackageImpl> calcModel = std::shared_ptr<CalcModelPackageImpl>(this, null_deleter());
	std::shared_ptr<uml::Generalization> gen = nullptr;
	
	
	

	calcModel_PrimeChecker_printIsPrime_->getMethod()->push_back(calcModel_PrimeChecker_fbPrintIsPrime);
	calcModel_PrimeChecker_isOdd_->getMethod()->push_back(calcModel_PrimeChecker_fbIsOdd);
	calcModel_PrimeChecker_printNotPrime_->getMethod()->push_back(calcModel_PrimeChecker_fbPrintNotPrime);
	calcModel_PrimeChecker_isNotFinished_->getMethod()->push_back(calcModel_PrimeChecker_fbIsNotFinished);
	calcModel_PrimeChecker_next_->getMethod()->push_back(calcModel_PrimeChecker_fbNext);
	calcModel_PrimeChecker_divides_->getMethod()->push_back(calcModel_PrimeChecker_fbDivides);
	
	
	//initalize ActivityNodes and Edges
	
	
	
	
	
	
	calcModel_CheckIfPrimecbaPrintIsPrime->setBehavior(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbPrintIsPrime());
	
	
	
	calcModel_CheckIfPrimecbaPrintNotPrime->setBehavior(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbPrintNotPrime());
	
	
	
	calcModel_CheckIfPrimecoaDivides->setOperation(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_divides_());
	calcModel_CheckIfPrimecoaDivides->getInput()->push_back(inputPin_coaDividestarget);
	
	
	
	calcModel_CheckIfPrimecoaIsNotFinished->setOperation(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_isNotFinished_());
	calcModel_CheckIfPrimecoaIsNotFinished->getInput()->push_back(inputPin_coaIsNotFinishedtarget);
	
	
	
	calcModel_CheckIfPrimecoaIsOdd->setOperation(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_isOdd_());
	calcModel_CheckIfPrimecoaIsOdd->getInput()->push_back(inputPin_coaIsOddtarget);
	
	
	
	calcModel_CheckIfPrimecbaPrintNotPrime2->setBehavior(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbPrintNotPrime());
	
	
	
	calcModel_CheckIfPrimenext_call->setOperation(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_next_());
	calcModel_CheckIfPrimenext_call->getInput()->push_back(inputPin_next_calltarget);
	
	
	
	
	
	
	
	
	calcModel_CheckIfPrimeprimeChecker->setParameter(calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode);
	
	
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime->setSource(calcModel_CheckIfPrimeisNotFinished);
	calcModel_CheckIfPrimeisNotFinished->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime);
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime->setTarget(calcModel_CheckIfPrimecbaPrintIsPrime);
	calcModel_CheckIfPrimecbaPrintIsPrime->getIncoming()->push_back(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime);
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime->setGuard(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime);
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge->setSource(calcModel_CheckIfPrimeisNotFinished);
	calcModel_CheckIfPrimeisNotFinished->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge);
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge->setTarget(calcModel_CheckIfPrimeMerge);
	calcModel_CheckIfPrimeMerge->getIncoming()->push_back(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge);
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge->setGuard(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge);
	calcModel_CheckIfPrimeifIsOdd->setSource(outputPin_coaIsOddisOdd);
	outputPin_coaIsOddisOdd->getOutgoing()->push_back(calcModel_CheckIfPrimeifIsOdd);
	calcModel_CheckIfPrimeifIsOdd->setTarget(calcModel_CheckIfPrimeIsOdd);
	calcModel_CheckIfPrimeIsOdd->getIncoming()->push_back(calcModel_CheckIfPrimeifIsOdd);
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished->setSource(calcModel_CheckIfPrimenext_call);
	calcModel_CheckIfPrimenext_call->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished);
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished->setTarget(calcModel_CheckIfPrimecoaIsNotFinished);
	calcModel_CheckIfPrimecoaIsNotFinished->getIncoming()->push_back(cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished);
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished->setGuard(cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished);
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call->setSource(calcModel_CheckIfPrimedivides);
	calcModel_CheckIfPrimedivides->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call);
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call->setTarget(calcModel_CheckIfPrimenext_call);
	calcModel_CheckIfPrimenext_call->getIncoming()->push_back(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call);
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call->setGuard(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call);
	calcModel_CheckIfPrimeifIsNotFinished->setSource(outputPin_coaIsNotFinishedisNotFinished);
	outputPin_coaIsNotFinishedisNotFinished->getOutgoing()->push_back(calcModel_CheckIfPrimeifIsNotFinished);
	calcModel_CheckIfPrimeifIsNotFinished->setTarget(calcModel_CheckIfPrimeisNotFinished);
	calcModel_CheckIfPrimeisNotFinished->getIncoming()->push_back(calcModel_CheckIfPrimeifIsNotFinished);
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2->setSource(calcModel_CheckIfPrimecbaPrintNotPrime);
	calcModel_CheckIfPrimecbaPrintNotPrime->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2);
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2->setTarget(calcModel_CheckIfPrimeActivityFinal2);
	calcModel_CheckIfPrimeActivityFinal2->getIncoming()->push_back(cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2);
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2->setGuard(cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2);
	oF_CalcModel_CheckIfPrimeFork1_InputPin_next_calltarget->setSource(calcModel_CheckIfPrimeFork1);
	calcModel_CheckIfPrimeFork1->getOutgoing()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_next_calltarget);
	oF_CalcModel_CheckIfPrimeFork1_InputPin_next_calltarget->setTarget(inputPin_next_calltarget);
	inputPin_next_calltarget->getIncoming()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_next_calltarget);
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2->setSource(calcModel_CheckIfPrimeIsOdd);
	calcModel_CheckIfPrimeIsOdd->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2);
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2->setTarget(calcModel_CheckIfPrimecbaPrintNotPrime2);
	calcModel_CheckIfPrimecbaPrintNotPrime2->getIncoming()->push_back(cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2);
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2->setGuard(cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2);
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget->setSource(calcModel_CheckIfPrimeFork1);
	calcModel_CheckIfPrimeFork1->getOutgoing()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget);
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget->setTarget(inputPin_coaIsNotFinishedtarget);
	inputPin_coaIsNotFinishedtarget->getIncoming()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget);
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaDividestarget->setSource(calcModel_CheckIfPrimeFork1);
	calcModel_CheckIfPrimeFork1->getOutgoing()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_coaDividestarget);
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaDividestarget->setTarget(inputPin_coaDividestarget);
	inputPin_coaDividestarget->getIncoming()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_coaDividestarget);
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge->setSource(calcModel_CheckIfPrimeIsOdd);
	calcModel_CheckIfPrimeIsOdd->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge);
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge->setTarget(calcModel_CheckIfPrimeMerge);
	calcModel_CheckIfPrimeMerge->getIncoming()->push_back(cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge);
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge->setGuard(cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge);
	calcModel_CheckIfPrimeifDivides->setSource(outputPin_coaDividesisDivisible);
	outputPin_coaDividesisDivisible->getOutgoing()->push_back(calcModel_CheckIfPrimeifDivides);
	calcModel_CheckIfPrimeifDivides->setTarget(calcModel_CheckIfPrimedivides);
	calcModel_CheckIfPrimedivides->getIncoming()->push_back(calcModel_CheckIfPrimeifDivides);
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3->setSource(calcModel_CheckIfPrimecbaPrintIsPrime);
	calcModel_CheckIfPrimecbaPrintIsPrime->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3);
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3->setTarget(calcModel_CheckIfPrimeActivityFinal3);
	calcModel_CheckIfPrimeActivityFinal3->getIncoming()->push_back(cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3);
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3->setGuard(cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3);
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget->setSource(calcModel_CheckIfPrimeFork1);
	calcModel_CheckIfPrimeFork1->getOutgoing()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget);
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget->setTarget(inputPin_coaIsOddtarget);
	inputPin_coaIsOddtarget->getIncoming()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget);
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime->setSource(calcModel_CheckIfPrimedivides);
	calcModel_CheckIfPrimedivides->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime);
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime->setTarget(calcModel_CheckIfPrimecbaPrintNotPrime);
	calcModel_CheckIfPrimecbaPrintNotPrime->getIncoming()->push_back(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime);
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime->setGuard(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime);
	oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1->setSource(calcModel_CheckIfPrimeprimeChecker);
	calcModel_CheckIfPrimeprimeChecker->getOutgoing()->push_back(oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1);
	oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1->setTarget(calcModel_CheckIfPrimeFork1);
	calcModel_CheckIfPrimeFork1->getIncoming()->push_back(oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1);
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1->setSource(calcModel_CheckIfPrimecbaPrintNotPrime2);
	calcModel_CheckIfPrimecbaPrintNotPrime2->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1);
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1->setTarget(calcModel_CheckIfPrimeActivityFinal1);
	calcModel_CheckIfPrimeActivityFinal1->getIncoming()->push_back(cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1);
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1->setGuard(cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1);
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides->setSource(calcModel_CheckIfPrimeMerge);
	calcModel_CheckIfPrimeMerge->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides);
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides->setTarget(calcModel_CheckIfPrimecoaDivides);
	calcModel_CheckIfPrimecoaDivides->getIncoming()->push_back(cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides);
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides->setGuard(cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides);
	
}

std::shared_ptr<uml::ControlFlow> CalcModelPackageImpl::get_CF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge()
{
	return cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge;
}
std::shared_ptr<uml::ControlFlow> CalcModelPackageImpl::get_CF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2()
{
	return cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2;
}
std::shared_ptr<uml::ControlFlow> CalcModelPackageImpl::get_CF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides()
{
	return cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides;
}
std::shared_ptr<uml::ControlFlow> CalcModelPackageImpl::get_CF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3()
{
	return cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3;
}
std::shared_ptr<uml::ControlFlow> CalcModelPackageImpl::get_CF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1()
{
	return cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1;
}
std::shared_ptr<uml::ControlFlow> CalcModelPackageImpl::get_CF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2()
{
	return cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2;
}
std::shared_ptr<uml::ControlFlow> CalcModelPackageImpl::get_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime()
{
	return cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime;
}
std::shared_ptr<uml::ControlFlow> CalcModelPackageImpl::get_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call()
{
	return cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call;
}
std::shared_ptr<uml::ControlFlow> CalcModelPackageImpl::get_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge()
{
	return cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge;
}
std::shared_ptr<uml::ControlFlow> CalcModelPackageImpl::get_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime()
{
	return cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime;
}
std::shared_ptr<uml::ControlFlow> CalcModelPackageImpl::get_CF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished()
{
	return cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished;
}
std::shared_ptr<uml::Activity> CalcModelPackageImpl::get_CalcModel_CheckIfPrime()
{
	return calcModel_CheckIfPrime;
}
std::shared_ptr<uml::ActivityFinalNode> CalcModelPackageImpl::get_CalcModel_CheckIfPrimeActivityFinal1()
{
	return calcModel_CheckIfPrimeActivityFinal1;
}
std::shared_ptr<uml::ActivityFinalNode> CalcModelPackageImpl::get_CalcModel_CheckIfPrimeActivityFinal2()
{
	return calcModel_CheckIfPrimeActivityFinal2;
}
std::shared_ptr<uml::ActivityFinalNode> CalcModelPackageImpl::get_CalcModel_CheckIfPrimeActivityFinal3()
{
	return calcModel_CheckIfPrimeActivityFinal3;
}
std::shared_ptr<uml::ForkNode> CalcModelPackageImpl::get_CalcModel_CheckIfPrimeFork1()
{
	return calcModel_CheckIfPrimeFork1;
}
std::shared_ptr<uml::DecisionNode> CalcModelPackageImpl::get_CalcModel_CheckIfPrimeIsOdd()
{
	return calcModel_CheckIfPrimeIsOdd;
}
std::shared_ptr<uml::MergeNode> CalcModelPackageImpl::get_CalcModel_CheckIfPrimeMerge()
{
	return calcModel_CheckIfPrimeMerge;
}
std::shared_ptr<uml::Parameter> CalcModelPackageImpl::get_CalcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode()
{
	return calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode;
}
std::shared_ptr<uml::CallBehaviorAction> CalcModelPackageImpl::get_CalcModel_CheckIfPrimecbaPrintIsPrime()
{
	return calcModel_CheckIfPrimecbaPrintIsPrime;
}
std::shared_ptr<uml::CallBehaviorAction> CalcModelPackageImpl::get_CalcModel_CheckIfPrimecbaPrintNotPrime()
{
	return calcModel_CheckIfPrimecbaPrintNotPrime;
}
std::shared_ptr<uml::CallBehaviorAction> CalcModelPackageImpl::get_CalcModel_CheckIfPrimecbaPrintNotPrime2()
{
	return calcModel_CheckIfPrimecbaPrintNotPrime2;
}
std::shared_ptr<uml::CallOperationAction> CalcModelPackageImpl::get_CalcModel_CheckIfPrimecoaDivides()
{
	return calcModel_CheckIfPrimecoaDivides;
}
std::shared_ptr<uml::CallOperationAction> CalcModelPackageImpl::get_CalcModel_CheckIfPrimecoaIsNotFinished()
{
	return calcModel_CheckIfPrimecoaIsNotFinished;
}
std::shared_ptr<uml::CallOperationAction> CalcModelPackageImpl::get_CalcModel_CheckIfPrimecoaIsOdd()
{
	return calcModel_CheckIfPrimecoaIsOdd;
}
std::shared_ptr<uml::DecisionNode> CalcModelPackageImpl::get_CalcModel_CheckIfPrimedivides()
{
	return calcModel_CheckIfPrimedivides;
}
std::shared_ptr<uml::ObjectFlow> CalcModelPackageImpl::get_CalcModel_CheckIfPrimeifDivides()
{
	return calcModel_CheckIfPrimeifDivides;
}
std::shared_ptr<uml::ObjectFlow> CalcModelPackageImpl::get_CalcModel_CheckIfPrimeifIsNotFinished()
{
	return calcModel_CheckIfPrimeifIsNotFinished;
}
std::shared_ptr<uml::ObjectFlow> CalcModelPackageImpl::get_CalcModel_CheckIfPrimeifIsOdd()
{
	return calcModel_CheckIfPrimeifIsOdd;
}
std::shared_ptr<uml::DecisionNode> CalcModelPackageImpl::get_CalcModel_CheckIfPrimeisNotFinished()
{
	return calcModel_CheckIfPrimeisNotFinished;
}
std::shared_ptr<uml::CallOperationAction> CalcModelPackageImpl::get_CalcModel_CheckIfPrimenext_call()
{
	return calcModel_CheckIfPrimenext_call;
}
std::shared_ptr<uml::ActivityParameterNode> CalcModelPackageImpl::get_CalcModel_CheckIfPrimeprimeChecker()
{
	return calcModel_CheckIfPrimeprimeChecker;
}
std::shared_ptr<uml::Class> CalcModelPackageImpl::get_CalcModel_PrimeChecker()
{
	return calcModel_PrimeChecker;
}
std::shared_ptr<uml::Property> CalcModelPackageImpl::get_CalcModel_PrimeChecker_divider()
{
	return calcModel_PrimeChecker_divider;
}
std::shared_ptr<uml::Operation> CalcModelPackageImpl::get_CalcModel_PrimeChecker_divides_()
{
	return calcModel_PrimeChecker_divides_;
}
std::shared_ptr<uml::Parameter> CalcModelPackageImpl::get_CalcModel_PrimeChecker_divides_isDivisible()
{
	return calcModel_PrimeChecker_divides_isDivisible;
}
std::shared_ptr<uml::FunctionBehavior> CalcModelPackageImpl::get_CalcModel_PrimeChecker_fbDivides()
{
	return calcModel_PrimeChecker_fbDivides;
}
std::shared_ptr<uml::Parameter> CalcModelPackageImpl::get_CalcModel_PrimeChecker_fbDivides_isDivisible()
{
	return calcModel_PrimeChecker_fbDivides_isDivisible;
}
std::shared_ptr<uml::FunctionBehavior> CalcModelPackageImpl::get_CalcModel_PrimeChecker_fbIsNotFinished()
{
	return calcModel_PrimeChecker_fbIsNotFinished;
}
std::shared_ptr<uml::Parameter> CalcModelPackageImpl::get_CalcModel_PrimeChecker_fbIsNotFinished_isNotFinished()
{
	return calcModel_PrimeChecker_fbIsNotFinished_isNotFinished;
}
std::shared_ptr<uml::FunctionBehavior> CalcModelPackageImpl::get_CalcModel_PrimeChecker_fbIsOdd()
{
	return calcModel_PrimeChecker_fbIsOdd;
}
std::shared_ptr<uml::Parameter> CalcModelPackageImpl::get_CalcModel_PrimeChecker_fbIsOdd_isOdd()
{
	return calcModel_PrimeChecker_fbIsOdd_isOdd;
}
std::shared_ptr<uml::FunctionBehavior> CalcModelPackageImpl::get_CalcModel_PrimeChecker_fbNext()
{
	return calcModel_PrimeChecker_fbNext;
}
std::shared_ptr<uml::FunctionBehavior> CalcModelPackageImpl::get_CalcModel_PrimeChecker_fbPrintIsPrime()
{
	return calcModel_PrimeChecker_fbPrintIsPrime;
}
std::shared_ptr<uml::FunctionBehavior> CalcModelPackageImpl::get_CalcModel_PrimeChecker_fbPrintNotPrime()
{
	return calcModel_PrimeChecker_fbPrintNotPrime;
}
std::shared_ptr<uml::Operation> CalcModelPackageImpl::get_CalcModel_PrimeChecker_isNotFinished_()
{
	return calcModel_PrimeChecker_isNotFinished_;
}
std::shared_ptr<uml::Parameter> CalcModelPackageImpl::get_CalcModel_PrimeChecker_isNotFinished_isNotFinished()
{
	return calcModel_PrimeChecker_isNotFinished_isNotFinished;
}
std::shared_ptr<uml::Operation> CalcModelPackageImpl::get_CalcModel_PrimeChecker_isOdd_()
{
	return calcModel_PrimeChecker_isOdd_;
}
std::shared_ptr<uml::Parameter> CalcModelPackageImpl::get_CalcModel_PrimeChecker_isOdd_isOdd()
{
	return calcModel_PrimeChecker_isOdd_isOdd;
}
std::shared_ptr<uml::Operation> CalcModelPackageImpl::get_CalcModel_PrimeChecker_next_()
{
	return calcModel_PrimeChecker_next_;
}
std::shared_ptr<uml::Property> CalcModelPackageImpl::get_CalcModel_PrimeChecker_number()
{
	return calcModel_PrimeChecker_number;
}
std::shared_ptr<uml::Operation> CalcModelPackageImpl::get_CalcModel_PrimeChecker_printIsPrime_()
{
	return calcModel_PrimeChecker_printIsPrime_;
}
std::shared_ptr<uml::Operation> CalcModelPackageImpl::get_CalcModel_PrimeChecker_printNotPrime_()
{
	return calcModel_PrimeChecker_printNotPrime_;
}
std::shared_ptr<uml::InputPin> CalcModelPackageImpl::get_InputPin_coaDividestarget()
{
	return inputPin_coaDividestarget;
}
std::shared_ptr<uml::InputPin> CalcModelPackageImpl::get_InputPin_coaIsNotFinishedtarget()
{
	return inputPin_coaIsNotFinishedtarget;
}
std::shared_ptr<uml::InputPin> CalcModelPackageImpl::get_InputPin_coaIsOddtarget()
{
	return inputPin_coaIsOddtarget;
}
std::shared_ptr<uml::InputPin> CalcModelPackageImpl::get_InputPin_next_calltarget()
{
	return inputPin_next_calltarget;
}
std::shared_ptr<uml::ObjectFlow> CalcModelPackageImpl::get_OF_CalcModel_CheckIfPrimeFork1_InputPin_coaDividestarget()
{
	return oF_CalcModel_CheckIfPrimeFork1_InputPin_coaDividestarget;
}
std::shared_ptr<uml::ObjectFlow> CalcModelPackageImpl::get_OF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget()
{
	return oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget;
}
std::shared_ptr<uml::ObjectFlow> CalcModelPackageImpl::get_OF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget()
{
	return oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget;
}
std::shared_ptr<uml::ObjectFlow> CalcModelPackageImpl::get_OF_CalcModel_CheckIfPrimeFork1_InputPin_next_calltarget()
{
	return oF_CalcModel_CheckIfPrimeFork1_InputPin_next_calltarget;
}
std::shared_ptr<uml::ObjectFlow> CalcModelPackageImpl::get_OF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1()
{
	return oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1;
}
std::shared_ptr<uml::OutputPin> CalcModelPackageImpl::get_OutputPin_coaDividesisDivisible()
{
	return outputPin_coaDividesisDivisible;
}
std::shared_ptr<uml::OutputPin> CalcModelPackageImpl::get_OutputPin_coaIsNotFinishedisNotFinished()
{
	return outputPin_coaIsNotFinishedisNotFinished;
}
std::shared_ptr<uml::OutputPin> CalcModelPackageImpl::get_OutputPin_coaIsOddisOdd()
{
	return outputPin_coaIsOddisOdd;
}


