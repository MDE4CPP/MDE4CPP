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
	
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge.reset(uml::UmlFactory::eInstance()->createLiteralBoolean());
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge->setValue(true);
	
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2.reset(uml::UmlFactory::eInstance()->createLiteralBoolean());
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2->setValue(false);
	
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides.reset(uml::UmlFactory::eInstance()->createLiteralBoolean());
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides->setValue(true);
	
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides_weight_LiteralInteger_CF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides.reset(uml::UmlFactory::eInstance()->createLiteralInteger());
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides_weight_LiteralInteger_CF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides->setValue(0);
	
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3.reset(uml::UmlFactory::eInstance()->createLiteralBoolean());
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3->setValue(true);
	
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3_weight_LiteralInteger_CF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3.reset(uml::UmlFactory::eInstance()->createLiteralInteger());
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3_weight_LiteralInteger_CF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3->setValue(0);
	
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1.reset(uml::UmlFactory::eInstance()->createLiteralBoolean());
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1->setValue(true);
	
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1_weight_LiteralInteger_CF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1.reset(uml::UmlFactory::eInstance()->createLiteralInteger());
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1_weight_LiteralInteger_CF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1->setValue(0);
	
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2.reset(uml::UmlFactory::eInstance()->createLiteralBoolean());
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2->setValue(true);
	
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2_weight_LiteralInteger_CF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2.reset(uml::UmlFactory::eInstance()->createLiteralInteger());
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2_weight_LiteralInteger_CF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2->setValue(0);
	
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime.reset(uml::UmlFactory::eInstance()->createLiteralBoolean());
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime->setValue(true);
	
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime_weight_LiteralInteger_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime.reset(uml::UmlFactory::eInstance()->createLiteralInteger());
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime_weight_LiteralInteger_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime->setValue(0);
	
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call.reset(uml::UmlFactory::eInstance()->createLiteralBoolean());
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call->setValue(false);
	
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call_weight_LiteralInteger_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call.reset(uml::UmlFactory::eInstance()->createLiteralInteger());
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call_weight_LiteralInteger_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call->setValue(0);
	
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge.reset(uml::UmlFactory::eInstance()->createLiteralBoolean());
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge->setValue(true);
	
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime.reset(uml::UmlFactory::eInstance()->createLiteralBoolean());
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime->setValue(false);
	
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime_weight_LiteralInteger_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime.reset(uml::UmlFactory::eInstance()->createLiteralInteger());
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime_weight_LiteralInteger_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime->setValue(0);
	
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished.reset(uml::UmlFactory::eInstance()->createLiteralBoolean());
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished->setValue(true);
	
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished_weight_LiteralInteger_CF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished.reset(uml::UmlFactory::eInstance()->createLiteralInteger());
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished_weight_LiteralInteger_CF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished->setValue(0);
	
	calcModel_CheckIfPrimeprimeChecker_upperBound_LiteralInteger_CalcModel_CheckIfPrimeprimeChecker.reset(uml::UmlFactory::eInstance()->createLiteralInteger());
	calcModel_CheckIfPrimeprimeChecker_upperBound_LiteralInteger_CalcModel_CheckIfPrimeprimeChecker->setValue(1);
	
	calcModel_PrimeChecker_divider_defaultValue_LiteralInteger_CalcModel_PrimeChecker_divider.reset(uml::UmlFactory::eInstance()->createLiteralInteger());
	calcModel_PrimeChecker_divider_defaultValue_LiteralInteger_CalcModel_PrimeChecker_divider->setValue(3);
	
	calcModel_PrimeChecker_divides_isDivisible_defaultValue_LiteralString_CalcModel_PrimeChecker_divides_isDivisible.reset(uml::UmlFactory::eInstance()->createLiteralString());
	calcModel_PrimeChecker_divides_isDivisible_defaultValue_LiteralString_CalcModel_PrimeChecker_divides_isDivisible->setValue("");
	
	calcModel_PrimeChecker_fbDivides_isDivisible_defaultValue_LiteralString_CalcModel_PrimeChecker_fbDivides_isDivisible.reset(uml::UmlFactory::eInstance()->createLiteralString());
	calcModel_PrimeChecker_fbDivides_isDivisible_defaultValue_LiteralString_CalcModel_PrimeChecker_fbDivides_isDivisible->setValue("");
	
	calcModel_PrimeChecker_fbIsOdd_isOdd_defaultValue_LiteralString_CalcModel_PrimeChecker_fbIsOdd_isOdd.reset(uml::UmlFactory::eInstance()->createLiteralString());
	calcModel_PrimeChecker_fbIsOdd_isOdd_defaultValue_LiteralString_CalcModel_PrimeChecker_fbIsOdd_isOdd->setValue("");
	
	calcModel_PrimeChecker_isOdd_isOdd_defaultValue_LiteralString_CalcModel_PrimeChecker_isOdd_isOdd.reset(uml::UmlFactory::eInstance()->createLiteralString());
	calcModel_PrimeChecker_isOdd_isOdd_defaultValue_LiteralString_CalcModel_PrimeChecker_isOdd_isOdd->setValue("");
	
	calcModel_PrimeChecker_number_defaultValue_LiteralInteger_CalcModel_PrimeChecker_number.reset(uml::UmlFactory::eInstance()->createLiteralInteger());
	calcModel_PrimeChecker_number_defaultValue_LiteralInteger_CalcModel_PrimeChecker_number->setValue(8191);
	
	


	calcModel_PrimeChecker.reset(uml::UmlFactory::eInstance()->createClass());
	calcModel_PrimeChecker->setName("PrimeChecker");
	calcModel_PrimeChecker->setIsAbstract(false);
	calcModel_PrimeChecker->setPackage(calcModel);
	calcModel->getPackagedElement()->push_back(calcModel_PrimeChecker);
	
	//constraints
	
	
	calcModel_PrimeChecker_divider.reset(uml::UmlFactory::eInstance()->createProperty());
	calcModel_PrimeChecker_divider->setName("divider");
	calcModel_PrimeChecker_divider->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	calcModel_PrimeChecker_divider->setLower(1);
	calcModel_PrimeChecker_divider->setUpper(1);
	calcModel_PrimeChecker->getOwnedAttribute()->push_back(calcModel_PrimeChecker_divider);
	calcModel_PrimeChecker_divider->setClass(calcModel_PrimeChecker);
	calcModel_PrimeChecker_divider->setDefaultValue(calcModel_PrimeChecker_divider_defaultValue_LiteralInteger_CalcModel_PrimeChecker_divider);
	
	calcModel_PrimeChecker_number.reset(uml::UmlFactory::eInstance()->createProperty());
	calcModel_PrimeChecker_number->setName("number");
	calcModel_PrimeChecker_number->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	calcModel_PrimeChecker_number->setLower(1);
	calcModel_PrimeChecker_number->setUpper(1);
	calcModel_PrimeChecker->getOwnedAttribute()->push_back(calcModel_PrimeChecker_number);
	calcModel_PrimeChecker_number->setClass(calcModel_PrimeChecker);
	calcModel_PrimeChecker_number->setDefaultValue(calcModel_PrimeChecker_number_defaultValue_LiteralInteger_CalcModel_PrimeChecker_number);
	
	
	calcModel_PrimeChecker_divides_.reset(uml::UmlFactory::eInstance()->createOperation());
	calcModel_PrimeChecker_divides_->setName("divides");
	calcModel_PrimeChecker_divides_isDivisible.reset(uml::UmlFactory::eInstance()->createParameter());
	calcModel_PrimeChecker_divides_isDivisible->setName("isDivisible");
	calcModel_PrimeChecker_divides_isDivisible->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	calcModel_PrimeChecker_divides_isDivisible->setLower(1);
	calcModel_PrimeChecker_divides_isDivisible->setUpper(1);
	calcModel_PrimeChecker_divides_isDivisible->setDirection(uml::ParameterDirectionKind::RETURN);
	
	calcModel_PrimeChecker_divides_->getOwnedParameter()->push_back(calcModel_PrimeChecker_divides_isDivisible);
	
	
	calcModel_PrimeChecker->getOwnedOperation()->push_back(calcModel_PrimeChecker_divides_); 
	calcModel_PrimeChecker_isNotFinished_.reset(uml::UmlFactory::eInstance()->createOperation());
	calcModel_PrimeChecker_isNotFinished_->setName("isNotFinished");
	calcModel_PrimeChecker_isNotFinished_isNotFinished.reset(uml::UmlFactory::eInstance()->createParameter());
	calcModel_PrimeChecker_isNotFinished_isNotFinished->setName("isNotFinished");
	calcModel_PrimeChecker_isNotFinished_isNotFinished->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	calcModel_PrimeChecker_isNotFinished_isNotFinished->setLower(1);
	calcModel_PrimeChecker_isNotFinished_isNotFinished->setUpper(1);
	calcModel_PrimeChecker_isNotFinished_isNotFinished->setDirection(uml::ParameterDirectionKind::RETURN);
	
	calcModel_PrimeChecker_isNotFinished_->getOwnedParameter()->push_back(calcModel_PrimeChecker_isNotFinished_isNotFinished);
	
	
	calcModel_PrimeChecker->getOwnedOperation()->push_back(calcModel_PrimeChecker_isNotFinished_); 
	calcModel_PrimeChecker_isOdd_.reset(uml::UmlFactory::eInstance()->createOperation());
	calcModel_PrimeChecker_isOdd_->setName("isOdd");
	calcModel_PrimeChecker_isOdd_isOdd.reset(uml::UmlFactory::eInstance()->createParameter());
	calcModel_PrimeChecker_isOdd_isOdd->setName("isOdd");
	calcModel_PrimeChecker_isOdd_isOdd->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	calcModel_PrimeChecker_isOdd_isOdd->setLower(1);
	calcModel_PrimeChecker_isOdd_isOdd->setUpper(1);
	calcModel_PrimeChecker_isOdd_isOdd->setDirection(uml::ParameterDirectionKind::RETURN);
	
	calcModel_PrimeChecker_isOdd_->getOwnedParameter()->push_back(calcModel_PrimeChecker_isOdd_isOdd);
	
	
	calcModel_PrimeChecker->getOwnedOperation()->push_back(calcModel_PrimeChecker_isOdd_); 
	calcModel_PrimeChecker_next_.reset(uml::UmlFactory::eInstance()->createOperation());
	calcModel_PrimeChecker_next_->setName("next");
	
	
	calcModel_PrimeChecker->getOwnedOperation()->push_back(calcModel_PrimeChecker_next_); 
	calcModel_PrimeChecker_printIsPrime_.reset(uml::UmlFactory::eInstance()->createOperation());
	calcModel_PrimeChecker_printIsPrime_->setName("printIsPrime");
	
	
	calcModel_PrimeChecker->getOwnedOperation()->push_back(calcModel_PrimeChecker_printIsPrime_); 
	calcModel_PrimeChecker_printNotPrime_.reset(uml::UmlFactory::eInstance()->createOperation());
	calcModel_PrimeChecker_printNotPrime_->setName("printNotPrime");
	
	
	calcModel_PrimeChecker->getOwnedOperation()->push_back(calcModel_PrimeChecker_printNotPrime_); 
	
	calcModel_PrimeChecker_fbIsNotFinished.reset(uml::UmlFactory::eInstance()->createFunctionBehavior());
	calcModel_PrimeChecker_fbIsNotFinished->setName("fbIsNotFinished");
	calcModel_PrimeChecker->getOwnedBehavior()->push_back(calcModel_PrimeChecker_fbIsNotFinished);
	
	calcModel_PrimeChecker_fbIsNotFinished_isNotFinished.reset(uml::UmlFactory::eInstance()->createParameter());
	calcModel_PrimeChecker_fbIsNotFinished_isNotFinished->setName("isNotFinished");
	calcModel_PrimeChecker_fbIsNotFinished_isNotFinished->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	calcModel_PrimeChecker_fbIsNotFinished_isNotFinished->setLower(1);
	calcModel_PrimeChecker_fbIsNotFinished_isNotFinished->setUpper(1);
	calcModel_PrimeChecker_fbIsNotFinished_isNotFinished->setDirection(uml::ParameterDirectionKind::RETURN);
	
	calcModel_PrimeChecker_fbIsNotFinished->getOwnedParameter()->push_back(calcModel_PrimeChecker_fbIsNotFinished_isNotFinished);
	
	calcModel_PrimeChecker_fbDivides.reset(uml::UmlFactory::eInstance()->createFunctionBehavior());
	calcModel_PrimeChecker_fbDivides->setName("fbDivides");
	calcModel_PrimeChecker->getOwnedBehavior()->push_back(calcModel_PrimeChecker_fbDivides);
	
	calcModel_PrimeChecker_fbDivides_isDivisible.reset(uml::UmlFactory::eInstance()->createParameter());
	calcModel_PrimeChecker_fbDivides_isDivisible->setName("isDivisible");
	calcModel_PrimeChecker_fbDivides_isDivisible->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	calcModel_PrimeChecker_fbDivides_isDivisible->setLower(1);
	calcModel_PrimeChecker_fbDivides_isDivisible->setUpper(1);
	calcModel_PrimeChecker_fbDivides_isDivisible->setDirection(uml::ParameterDirectionKind::RETURN);
	
	calcModel_PrimeChecker_fbDivides->getOwnedParameter()->push_back(calcModel_PrimeChecker_fbDivides_isDivisible);
	
	calcModel_PrimeChecker_fbPrintIsPrime.reset(uml::UmlFactory::eInstance()->createFunctionBehavior());
	calcModel_PrimeChecker_fbPrintIsPrime->setName("fbPrintIsPrime");
	calcModel_PrimeChecker->getOwnedBehavior()->push_back(calcModel_PrimeChecker_fbPrintIsPrime);
	
	
	calcModel_PrimeChecker_fbPrintNotPrime.reset(uml::UmlFactory::eInstance()->createFunctionBehavior());
	calcModel_PrimeChecker_fbPrintNotPrime->setName("fbPrintNotPrime");
	calcModel_PrimeChecker->getOwnedBehavior()->push_back(calcModel_PrimeChecker_fbPrintNotPrime);
	
	
	calcModel_PrimeChecker_fbIsOdd.reset(uml::UmlFactory::eInstance()->createFunctionBehavior());
	calcModel_PrimeChecker_fbIsOdd->setName("fbIsOdd");
	calcModel_PrimeChecker->getOwnedBehavior()->push_back(calcModel_PrimeChecker_fbIsOdd);
	
	calcModel_PrimeChecker_fbIsOdd_isOdd.reset(uml::UmlFactory::eInstance()->createParameter());
	calcModel_PrimeChecker_fbIsOdd_isOdd->setName("isOdd");
	calcModel_PrimeChecker_fbIsOdd_isOdd->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	calcModel_PrimeChecker_fbIsOdd_isOdd->setLower(1);
	calcModel_PrimeChecker_fbIsOdd_isOdd->setUpper(1);
	calcModel_PrimeChecker_fbIsOdd_isOdd->setDirection(uml::ParameterDirectionKind::RETURN);
	
	calcModel_PrimeChecker_fbIsOdd->getOwnedParameter()->push_back(calcModel_PrimeChecker_fbIsOdd_isOdd);
	
	calcModel_PrimeChecker_fbNext.reset(uml::UmlFactory::eInstance()->createFunctionBehavior());
	calcModel_PrimeChecker_fbNext->setName("fbNext");
	calcModel_PrimeChecker->getOwnedBehavior()->push_back(calcModel_PrimeChecker_fbNext);
	
	
	




	calcModel_CheckIfPrime.reset(uml::UmlFactory::eInstance()->createActivity());
	calcModel_CheckIfPrime->setName("CheckIfPrime");
	calcModel_CheckIfPrime->setPackage(calcModel);
	
	//parameter
	calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode.reset(uml::UmlFactory::eInstance()->createParameter());
	calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode->setName("ActInputNode");
	calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode->setType(get_CalcModel_PrimeChecker());
	calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode->setLower(1);
	calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode->setUpper(1);
	calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode->setDirection(uml::ParameterDirectionKind::IN);
	
	calcModel_CheckIfPrime->getOwnedParameter()->push_back(calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode);
	
	
	calcModel->getPackagedElement()->push_back(calcModel_CheckIfPrime);
	//Node
	calcModel_CheckIfPrimeActivityFinal1.reset(uml::UmlFactory::eInstance()->createActivityFinalNode());
	calcModel_CheckIfPrimeActivityFinal1->setName("ActivityFinal1");
	calcModel_CheckIfPrimeActivityFinal1->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeActivityFinal2.reset(uml::UmlFactory::eInstance()->createActivityFinalNode());
	calcModel_CheckIfPrimeActivityFinal2->setName("ActivityFinal2");
	calcModel_CheckIfPrimeActivityFinal2->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeActivityFinal3.reset(uml::UmlFactory::eInstance()->createActivityFinalNode());
	calcModel_CheckIfPrimeActivityFinal3->setName("ActivityFinal3");
	calcModel_CheckIfPrimeActivityFinal3->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeFork1.reset(uml::UmlFactory::eInstance()->createForkNode());
	calcModel_CheckIfPrimeFork1->setName("Fork1");
	calcModel_CheckIfPrimeFork1->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeIsOdd.reset(uml::UmlFactory::eInstance()->createDecisionNode());
	calcModel_CheckIfPrimeIsOdd->setName("IsOdd");
	calcModel_CheckIfPrimeIsOdd->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeMerge.reset(uml::UmlFactory::eInstance()->createMergeNode());
	calcModel_CheckIfPrimeMerge->setName("Merge");
	calcModel_CheckIfPrimeMerge->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimecbaPrintIsPrime.reset(uml::UmlFactory::eInstance()->createCallBehaviorAction());
	calcModel_CheckIfPrimecbaPrintIsPrime->setName("cbaPrintIsPrime");
	calcModel_CheckIfPrimecbaPrintIsPrime->setActivity(calcModel_CheckIfPrime);
	//CallBehaviorAction cbaPrintIsPrime
	calcModel_CheckIfPrimecbaPrintIsPrime->setBehavior(calcModel_PrimeChecker_fbPrintIsPrime);
	calcModel_CheckIfPrimecbaPrintIsPrime->setIsSynchronous(true); //imposed by the fUML specification
	
	calcModel_CheckIfPrimecbaPrintNotPrime.reset(uml::UmlFactory::eInstance()->createCallBehaviorAction());
	calcModel_CheckIfPrimecbaPrintNotPrime->setName("cbaPrintNotPrime");
	calcModel_CheckIfPrimecbaPrintNotPrime->setActivity(calcModel_CheckIfPrime);
	//CallBehaviorAction cbaPrintNotPrime
	calcModel_CheckIfPrimecbaPrintNotPrime->setBehavior(calcModel_PrimeChecker_fbPrintNotPrime);
	calcModel_CheckIfPrimecbaPrintNotPrime->setIsSynchronous(true); //imposed by the fUML specification
	
	calcModel_CheckIfPrimecbaPrintNotPrime2.reset(uml::UmlFactory::eInstance()->createCallBehaviorAction());
	calcModel_CheckIfPrimecbaPrintNotPrime2->setName("cbaPrintNotPrime2");
	calcModel_CheckIfPrimecbaPrintNotPrime2->setActivity(calcModel_CheckIfPrime);
	//CallBehaviorAction cbaPrintNotPrime2
	calcModel_CheckIfPrimecbaPrintNotPrime2->setBehavior(calcModel_PrimeChecker_fbPrintNotPrime);
	calcModel_CheckIfPrimecbaPrintNotPrime2->setIsSynchronous(true); //imposed by the fUML specification
	
	calcModel_CheckIfPrimecoaDivides.reset(uml::UmlFactory::eInstance()->createCallOperationAction());
	calcModel_CheckIfPrimecoaDivides->setName("coaDivides");
	calcModel_CheckIfPrimecoaDivides->setActivity(calcModel_CheckIfPrime);
	//CallOperationAction coaDivides
	inputPin_coaDividestarget.reset(uml::UmlFactory::eInstance()->createInputPin());
	inputPin_coaDividestarget->setName("target");
	
	outputPin_coaDividesisDivisible.reset(uml::UmlFactory::eInstance()->createOutputPin());
	outputPin_coaDividesisDivisible->setName("isDivisible");
	
	calcModel_PrimeChecker_divides_.reset(uml::UmlFactory::eInstance()->createOperation());
	calcModel_PrimeChecker_divides_->setName("divides");
	
	
	calcModel_CheckIfPrimecoaIsNotFinished.reset(uml::UmlFactory::eInstance()->createCallOperationAction());
	calcModel_CheckIfPrimecoaIsNotFinished->setName("coaIsNotFinished");
	calcModel_CheckIfPrimecoaIsNotFinished->setActivity(calcModel_CheckIfPrime);
	//CallOperationAction coaIsNotFinished
	inputPin_coaIsNotFinishedtarget.reset(uml::UmlFactory::eInstance()->createInputPin());
	inputPin_coaIsNotFinishedtarget->setName("target");
	
	outputPin_coaIsNotFinishedisNotFinished.reset(uml::UmlFactory::eInstance()->createOutputPin());
	outputPin_coaIsNotFinishedisNotFinished->setName("isNotFinished");
	
	calcModel_PrimeChecker_isNotFinished_.reset(uml::UmlFactory::eInstance()->createOperation());
	calcModel_PrimeChecker_isNotFinished_->setName("isNotFinished");
	
	
	calcModel_CheckIfPrimecoaIsOdd.reset(uml::UmlFactory::eInstance()->createCallOperationAction());
	calcModel_CheckIfPrimecoaIsOdd->setName("coaIsOdd");
	calcModel_CheckIfPrimecoaIsOdd->setActivity(calcModel_CheckIfPrime);
	//CallOperationAction coaIsOdd
	inputPin_coaIsOddtarget.reset(uml::UmlFactory::eInstance()->createInputPin());
	inputPin_coaIsOddtarget->setName("target");
	
	outputPin_coaIsOddisOdd.reset(uml::UmlFactory::eInstance()->createOutputPin());
	outputPin_coaIsOddisOdd->setName("isOdd");
	
	calcModel_PrimeChecker_isOdd_.reset(uml::UmlFactory::eInstance()->createOperation());
	calcModel_PrimeChecker_isOdd_->setName("isOdd");
	
	
	calcModel_CheckIfPrimecoaNext.reset(uml::UmlFactory::eInstance()->createCallOperationAction());
	calcModel_CheckIfPrimecoaNext->setName("coaNext");
	calcModel_CheckIfPrimecoaNext->setActivity(calcModel_CheckIfPrime);
	//CallOperationAction coaNext
	inputPin_coaNexttarget.reset(uml::UmlFactory::eInstance()->createInputPin());
	inputPin_coaNexttarget->setName("target");
	
	
	calcModel_PrimeChecker_next_.reset(uml::UmlFactory::eInstance()->createOperation());
	calcModel_PrimeChecker_next_->setName("next");
	
	
	calcModel_CheckIfPrimedivides.reset(uml::UmlFactory::eInstance()->createDecisionNode());
	calcModel_CheckIfPrimedivides->setName("divides");
	calcModel_CheckIfPrimedivides->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimeisNotFinished.reset(uml::UmlFactory::eInstance()->createDecisionNode());
	calcModel_CheckIfPrimeisNotFinished->setName("isNotFinished");
	calcModel_CheckIfPrimeisNotFinished->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrimenext_call.reset(uml::UmlFactory::eInstance()->createCallOperationAction());
	calcModel_CheckIfPrimenext_call->setName("next_call");
	calcModel_CheckIfPrimenext_call->setActivity(calcModel_CheckIfPrime);
	//CallOperationAction next_call
	inputPin_next_calltarget.reset(uml::UmlFactory::eInstance()->createInputPin());
	inputPin_next_calltarget->setName("target");
	
	
	calcModel_PrimeChecker_next_.reset(uml::UmlFactory::eInstance()->createOperation());
	calcModel_PrimeChecker_next_->setName("next");
	
	
	calcModel_CheckIfPrimeprimeChecker.reset(uml::UmlFactory::eInstance()->createActivityParameterNode());
	calcModel_CheckIfPrimeprimeChecker->setName("primeChecker");
	calcModel_CheckIfPrimeprimeChecker->setActivity(calcModel_CheckIfPrime);
	
	//flow
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1.reset(uml::UmlFactory::eInstance()->createControlFlow());
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1->setName("");
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1);calcModel_CheckIfPrimeifIsOdd.reset(uml::UmlFactory::eInstance()->createObjectFlow());
	calcModel_CheckIfPrimeifIsOdd->setName("ifIsOdd");
	calcModel_CheckIfPrimeifIsOdd->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(calcModel_CheckIfPrimeifIsOdd);cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge.reset(uml::UmlFactory::eInstance()->createControlFlow());
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge->setName("");
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimeMerge);cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime.reset(uml::UmlFactory::eInstance()->createControlFlow());
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime->setName("");
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime);cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2.reset(uml::UmlFactory::eInstance()->createControlFlow());
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2->setName("");
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(cF_CalcModel_CheckIfPrimecbaPrintNotPrime_CalcModel_CheckIfPrimeActivityFinal2);calcModel_CheckIfPrimeifDivides.reset(uml::UmlFactory::eInstance()->createObjectFlow());
	calcModel_CheckIfPrimeifDivides->setName("ifDivides");
	calcModel_CheckIfPrimeifDivides->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(calcModel_CheckIfPrimeifDivides);cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2.reset(uml::UmlFactory::eInstance()->createControlFlow());
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2->setName("");
	cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(cF_CalcModel_CheckIfPrimeIsOdd_CalcModel_CheckIfPrimecbaPrintNotPrime2);oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget.reset(uml::UmlFactory::eInstance()->createObjectFlow());
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget->setName("");
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget);cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime.reset(uml::UmlFactory::eInstance()->createControlFlow());
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime->setName("");
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimecbaPrintNotPrime);calcModel_CheckIfPrimeifIsNotFinished.reset(uml::UmlFactory::eInstance()->createObjectFlow());
	calcModel_CheckIfPrimeifIsNotFinished->setName("ifIsNotFinished");
	calcModel_CheckIfPrimeifIsNotFinished->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(calcModel_CheckIfPrimeifIsNotFinished);cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides.reset(uml::UmlFactory::eInstance()->createControlFlow());
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides->setName("");
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides);cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge.reset(uml::UmlFactory::eInstance()->createControlFlow());
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge->setName("");
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge);oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1.reset(uml::UmlFactory::eInstance()->createObjectFlow());
	oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1->setName("");
	oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1);cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3.reset(uml::UmlFactory::eInstance()->createControlFlow());
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3->setName("");
	cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(cF_CalcModel_CheckIfPrimecbaPrintIsPrime_CalcModel_CheckIfPrimeActivityFinal3);oF_CalcModel_CheckIfPrimeFork1_InputPin_next_calltarget.reset(uml::UmlFactory::eInstance()->createObjectFlow());
	oF_CalcModel_CheckIfPrimeFork1_InputPin_next_calltarget->setName("");
	oF_CalcModel_CheckIfPrimeFork1_InputPin_next_calltarget->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_next_calltarget);oF_CalcModel_CheckIfPrimeFork1_InputPin_coaNexttarget.reset(uml::UmlFactory::eInstance()->createObjectFlow());
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaNexttarget->setName("");
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaNexttarget->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_coaNexttarget);cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call.reset(uml::UmlFactory::eInstance()->createControlFlow());
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call->setName("");
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call);oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget.reset(uml::UmlFactory::eInstance()->createObjectFlow());
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget->setName("");
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget);cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished.reset(uml::UmlFactory::eInstance()->createControlFlow());
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished->setName("");
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished);oF_CalcModel_CheckIfPrimeFork1_InputPin_coaDividestarget.reset(uml::UmlFactory::eInstance()->createObjectFlow());
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaDividestarget->setName("");
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaDividestarget->setActivity(calcModel_CheckIfPrime);
	calcModel_CheckIfPrime->getEdge()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_coaDividestarget);

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
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimecoaDivides);
	calcModel_CheckIfPrimecoaDivides->setOperation(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_divides_());
	calcModel_CheckIfPrimecoaDivides->getArgument()->push_back(inputPin_coaDividestarget);
	
	calcModel_CheckIfPrimecoaDivides->getResult()->push_back(outputPin_coaDividesisDivisible);
	
	calcModel_CheckIfPrimecoaDivides->setTarget(CalcModel::CalcModelPackage::eInstance()->get_InputPin_coaDividestarget());
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimecoaIsNotFinished);
	calcModel_CheckIfPrimecoaIsNotFinished->setOperation(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_isNotFinished_());
	calcModel_CheckIfPrimecoaIsNotFinished->getArgument()->push_back(inputPin_coaIsNotFinishedtarget);
	
	calcModel_CheckIfPrimecoaIsNotFinished->getResult()->push_back(outputPin_coaIsNotFinishedisNotFinished);
	
	calcModel_CheckIfPrimecoaIsNotFinished->setTarget(CalcModel::CalcModelPackage::eInstance()->get_InputPin_coaIsNotFinishedtarget());
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimeActivityFinal1);
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimeprimeChecker);
	calcModel_CheckIfPrimeprimeChecker->setParameter(calcModel_CheckIfPrime_CalcModel_CheckIfPrime_ActInputNode);
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimecbaPrintNotPrime);
	calcModel_CheckIfPrimecbaPrintNotPrime->setBehavior(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbPrintNotPrime());
	
	
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimedivides);
	
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimeFork1);
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimeActivityFinal2);
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimecoaNext);
	calcModel_CheckIfPrimecoaNext->setOperation(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_next_());
	calcModel_CheckIfPrimecoaNext->getArgument()->push_back(inputPin_coaNexttarget);
	
	
	calcModel_CheckIfPrimecoaNext->setTarget(CalcModel::CalcModelPackage::eInstance()->get_InputPin_coaNexttarget());
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimecoaIsOdd);
	calcModel_CheckIfPrimecoaIsOdd->setOperation(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_isOdd_());
	calcModel_CheckIfPrimecoaIsOdd->getArgument()->push_back(inputPin_coaIsOddtarget);
	
	calcModel_CheckIfPrimecoaIsOdd->getResult()->push_back(outputPin_coaIsOddisOdd);
	
	calcModel_CheckIfPrimecoaIsOdd->setTarget(CalcModel::CalcModelPackage::eInstance()->get_InputPin_coaIsOddtarget());
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimecbaPrintNotPrime2);
	calcModel_CheckIfPrimecbaPrintNotPrime2->setBehavior(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbPrintNotPrime());
	
	
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimenext_call);
	calcModel_CheckIfPrimenext_call->setOperation(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_next_());
	calcModel_CheckIfPrimenext_call->getArgument()->push_back(inputPin_next_calltarget);
	
	
	calcModel_CheckIfPrimenext_call->setTarget(CalcModel::CalcModelPackage::eInstance()->get_InputPin_next_calltarget());
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimeIsOdd);
	
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimeActivityFinal3);
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimeisNotFinished);
	
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimeMerge);
	
	calcModel_CheckIfPrime->getNode()->push_back(calcModel_CheckIfPrimecbaPrintIsPrime);
	calcModel_CheckIfPrimecbaPrintIsPrime->setBehavior(CalcModel::CalcModelPackage::eInstance()->get_CalcModel_PrimeChecker_fbPrintIsPrime());
	
	
	
	
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime->setSource(calcModel_CheckIfPrimeisNotFinished);
	calcModel_CheckIfPrimeisNotFinished->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime);
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime->setTarget(calcModel_CheckIfPrimecbaPrintIsPrime);
	calcModel_CheckIfPrimecbaPrintIsPrime->getIncoming()->push_back(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime);
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime->setGuard(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimecbaPrintIsPrime);
	calcModel_CheckIfPrimeifIsOdd->setSource(outputPin_coaIsOddisOdd);
	outputPin_coaIsOddisOdd->getOutgoing()->push_back(calcModel_CheckIfPrimeifIsOdd);
	calcModel_CheckIfPrimeifIsOdd->setTarget(calcModel_CheckIfPrimeIsOdd);
	calcModel_CheckIfPrimeIsOdd->getIncoming()->push_back(calcModel_CheckIfPrimeifIsOdd);
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge->setSource(calcModel_CheckIfPrimeisNotFinished);
	calcModel_CheckIfPrimeisNotFinished->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge);
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge->setTarget(calcModel_CheckIfPrimeMerge);
	calcModel_CheckIfPrimeMerge->getIncoming()->push_back(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge);
	cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge->setGuard(cF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeisNotFinished_CalcModel_CheckIfPrimeMerge);
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished->setSource(calcModel_CheckIfPrimenext_call);
	calcModel_CheckIfPrimenext_call->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished);
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished->setTarget(calcModel_CheckIfPrimecoaIsNotFinished);
	calcModel_CheckIfPrimecoaIsNotFinished->getIncoming()->push_back(cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished);
	cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished->setGuard(cF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimenext_call_CalcModel_CheckIfPrimecoaIsNotFinished);
	calcModel_CheckIfPrimeifIsNotFinished->setSource(outputPin_coaIsNotFinishedisNotFinished);
	outputPin_coaIsNotFinishedisNotFinished->getOutgoing()->push_back(calcModel_CheckIfPrimeifIsNotFinished);
	calcModel_CheckIfPrimeifIsNotFinished->setTarget(calcModel_CheckIfPrimeisNotFinished);
	calcModel_CheckIfPrimeisNotFinished->getIncoming()->push_back(calcModel_CheckIfPrimeifIsNotFinished);
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call->setSource(calcModel_CheckIfPrimedivides);
	calcModel_CheckIfPrimedivides->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call);
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call->setTarget(calcModel_CheckIfPrimenext_call);
	calcModel_CheckIfPrimenext_call->getIncoming()->push_back(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call);
	cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call->setGuard(cF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimedivides_CalcModel_CheckIfPrimenext_call);
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
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1->setSource(calcModel_CheckIfPrimecbaPrintNotPrime2);
	calcModel_CheckIfPrimecbaPrintNotPrime2->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1);
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1->setTarget(calcModel_CheckIfPrimeActivityFinal1);
	calcModel_CheckIfPrimeActivityFinal1->getIncoming()->push_back(cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1);
	cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1->setGuard(cF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimecbaPrintNotPrime2_CalcModel_CheckIfPrimeActivityFinal1);
	oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1->setSource(calcModel_CheckIfPrimeprimeChecker);
	calcModel_CheckIfPrimeprimeChecker->getOutgoing()->push_back(oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1);
	oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1->setTarget(calcModel_CheckIfPrimeFork1);
	calcModel_CheckIfPrimeFork1->getIncoming()->push_back(oF_CalcModel_CheckIfPrimeprimeChecker_CalcModel_CheckIfPrimeFork1);
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides->setSource(calcModel_CheckIfPrimeMerge);
	calcModel_CheckIfPrimeMerge->getOutgoing()->push_back(cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides);
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides->setTarget(calcModel_CheckIfPrimecoaDivides);
	calcModel_CheckIfPrimecoaDivides->getIncoming()->push_back(cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides);
	cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides->setGuard(cF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides_guard_LiteralBoolean_CF_CalcModel_CheckIfPrimeMerge_CalcModel_CheckIfPrimecoaDivides);
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaNexttarget->setSource(calcModel_CheckIfPrimeFork1);
	calcModel_CheckIfPrimeFork1->getOutgoing()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_coaNexttarget);
	oF_CalcModel_CheckIfPrimeFork1_InputPin_coaNexttarget->setTarget(inputPin_coaNexttarget);
	inputPin_coaNexttarget->getIncoming()->push_back(oF_CalcModel_CheckIfPrimeFork1_InputPin_coaNexttarget);
	
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
std::shared_ptr<uml::CallOperationAction> CalcModelPackageImpl::get_CalcModel_CheckIfPrimecoaNext()
{
	return calcModel_CheckIfPrimecoaNext;
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
std::shared_ptr<uml::Parameter> CalcModelPackageImpl::get_CalcModel_PrimeChecker_divides_isDivisible()
{
	return calcModel_PrimeChecker_divides_isDivisible;
}
std::shared_ptr<uml::Operation> CalcModelPackageImpl::get_CalcModel_PrimeChecker_divides_()
{
	return calcModel_PrimeChecker_divides_;
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
std::shared_ptr<uml::Parameter> CalcModelPackageImpl::get_CalcModel_PrimeChecker_isNotFinished_isNotFinished()
{
	return calcModel_PrimeChecker_isNotFinished_isNotFinished;
}
std::shared_ptr<uml::Operation> CalcModelPackageImpl::get_CalcModel_PrimeChecker_isNotFinished_()
{
	return calcModel_PrimeChecker_isNotFinished_;
}
std::shared_ptr<uml::Parameter> CalcModelPackageImpl::get_CalcModel_PrimeChecker_isOdd_isOdd()
{
	return calcModel_PrimeChecker_isOdd_isOdd;
}
std::shared_ptr<uml::Operation> CalcModelPackageImpl::get_CalcModel_PrimeChecker_isOdd_()
{
	return calcModel_PrimeChecker_isOdd_;
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
std::shared_ptr<uml::InputPin> CalcModelPackageImpl::get_InputPin_coaNexttarget()
{
	return inputPin_coaNexttarget;
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
std::shared_ptr<uml::ObjectFlow> CalcModelPackageImpl::get_OF_CalcModel_CheckIfPrimeFork1_InputPin_coaNexttarget()
{
	return oF_CalcModel_CheckIfPrimeFork1_InputPin_coaNexttarget;
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


