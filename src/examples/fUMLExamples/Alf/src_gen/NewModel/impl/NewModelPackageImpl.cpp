#include "NewModelPackageImpl.hpp"

//metamodel classes
#include "Stereotype.hpp"
#include "Generalization.hpp"
#include "Constraint.hpp"
#include "OpaqueExpression.hpp"
#include "EnumerationLiteral.hpp"
#include "PrimitiveType.hpp"
#include "FunctionBehavior.hpp"

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
#include "NewModelFactory.hpp"
#include "UmlFactory.hpp"

//depending model packages
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"


using namespace NewModel;

NewModelPackageImpl::NewModelPackageImpl()
{
}

NewModelPackageImpl::~NewModelPackageImpl()
{
}

bool NewModelPackageImpl::isInited = false;

NewModelPackage* NewModelPackageImpl::create()
{
	if (isInited)
	{
		return NewModelPackage::eInstance();
	}
	isInited = true;
	
    // Obtain or create and register package, create package meta-data objects
    NewModelPackageImpl * metaModelPackage = new NewModelPackageImpl();
	metaModelPackage->initMetaModel();
    metaModelPackage->createPackageContents();
    return metaModelPackage;
}

void NewModelPackageImpl::init()
{
    // Initialize created meta-data
    initializePackageContents();   
}

void NewModelPackageImpl::initMetaModel()
{
}

void NewModelPackageImpl::createPackageContents()
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;
	
	uml::Package * newModel = this;
	uml::Constraint * con = nullptr;
	uml::OpaqueExpression * oe = nullptr;
	
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge =  uml::UmlFactory::eInstance()->createLiteralBoolean();
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge->setValue(true);
	
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2 =  uml::UmlFactory::eInstance()->createLiteralBoolean();
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2->setValue(false);
	
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides =  uml::UmlFactory::eInstance()->createLiteralBoolean();
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides->setValue(true);
	
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides_weight_LiteralInteger_CF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides =  uml::UmlFactory::eInstance()->createLiteralInteger();
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides_weight_LiteralInteger_CF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides->setValue(0);
	
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3_guard_LiteralBoolean_CF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3 =  uml::UmlFactory::eInstance()->createLiteralBoolean();
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3_guard_LiteralBoolean_CF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3->setValue(true);
	
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3_weight_LiteralInteger_CF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3 =  uml::UmlFactory::eInstance()->createLiteralInteger();
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3_weight_LiteralInteger_CF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3->setValue(0);
	
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1_guard_LiteralBoolean_CF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1 =  uml::UmlFactory::eInstance()->createLiteralBoolean();
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1_guard_LiteralBoolean_CF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1->setValue(true);
	
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1_weight_LiteralInteger_CF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1 =  uml::UmlFactory::eInstance()->createLiteralInteger();
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1_weight_LiteralInteger_CF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1->setValue(0);
	
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2_guard_LiteralBoolean_CF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2 =  uml::UmlFactory::eInstance()->createLiteralBoolean();
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2_guard_LiteralBoolean_CF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2->setValue(true);
	
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2_weight_LiteralInteger_CF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2 =  uml::UmlFactory::eInstance()->createLiteralInteger();
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2_weight_LiteralInteger_CF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2->setValue(0);
	
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime_guard_LiteralBoolean_CF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime =  uml::UmlFactory::eInstance()->createLiteralBoolean();
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime_guard_LiteralBoolean_CF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime->setValue(true);
	
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime_weight_LiteralInteger_CF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime =  uml::UmlFactory::eInstance()->createLiteralInteger();
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime_weight_LiteralInteger_CF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime->setValue(0);
	
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call_guard_LiteralBoolean_CF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call =  uml::UmlFactory::eInstance()->createLiteralBoolean();
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call_guard_LiteralBoolean_CF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call->setValue(false);
	
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call_weight_LiteralInteger_CF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call =  uml::UmlFactory::eInstance()->createLiteralInteger();
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call_weight_LiteralInteger_CF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call->setValue(0);
	
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge =  uml::UmlFactory::eInstance()->createLiteralBoolean();
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge->setValue(true);
	
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime =  uml::UmlFactory::eInstance()->createLiteralBoolean();
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime->setValue(false);
	
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime_weight_LiteralInteger_CF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime =  uml::UmlFactory::eInstance()->createLiteralInteger();
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime_weight_LiteralInteger_CF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime->setValue(0);
	
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished_guard_LiteralBoolean_CF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished =  uml::UmlFactory::eInstance()->createLiteralBoolean();
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished_guard_LiteralBoolean_CF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished->setValue(true);
	
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished_weight_LiteralInteger_CF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished =  uml::UmlFactory::eInstance()->createLiteralInteger();
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished_weight_LiteralInteger_CF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished->setValue(0);
	
	newModel_CheckIfPrimeprimeChecker_upperBound_LiteralInteger_NewModel_CheckIfPrimeprimeChecker =  uml::UmlFactory::eInstance()->createLiteralInteger();
	newModel_CheckIfPrimeprimeChecker_upperBound_LiteralInteger_NewModel_CheckIfPrimeprimeChecker->setValue(1);
	
	newModel_PrimeChecker_divider_defaultValue_LiteralInteger_NewModel_PrimeChecker_divider =  uml::UmlFactory::eInstance()->createLiteralInteger();
	newModel_PrimeChecker_divider_defaultValue_LiteralInteger_NewModel_PrimeChecker_divider->setValue(3);
	
	newModel_PrimeChecker_divides_isDivisible_defaultValue_LiteralString_NewModel_PrimeChecker_divides_isDivisible =  uml::UmlFactory::eInstance()->createLiteralString();
	newModel_PrimeChecker_divides_isDivisible_defaultValue_LiteralString_NewModel_PrimeChecker_divides_isDivisible->setValue("");
	
	newModel_PrimeChecker_fbDivides_isDivisible_defaultValue_LiteralString_NewModel_PrimeChecker_fbDivides_isDivisible =  uml::UmlFactory::eInstance()->createLiteralString();
	newModel_PrimeChecker_fbDivides_isDivisible_defaultValue_LiteralString_NewModel_PrimeChecker_fbDivides_isDivisible->setValue("");
	
	newModel_PrimeChecker_fbIsOdd_isOdd_defaultValue_LiteralString_NewModel_PrimeChecker_fbIsOdd_isOdd =  uml::UmlFactory::eInstance()->createLiteralString();
	newModel_PrimeChecker_fbIsOdd_isOdd_defaultValue_LiteralString_NewModel_PrimeChecker_fbIsOdd_isOdd->setValue("");
	
	newModel_PrimeChecker_isOdd_isOdd_defaultValue_LiteralString_NewModel_PrimeChecker_isOdd_isOdd =  uml::UmlFactory::eInstance()->createLiteralString();
	newModel_PrimeChecker_isOdd_isOdd_defaultValue_LiteralString_NewModel_PrimeChecker_isOdd_isOdd->setValue("");
	
	newModel_PrimeChecker_number_defaultValue_LiteralInteger_NewModel_PrimeChecker_number =  uml::UmlFactory::eInstance()->createLiteralInteger();
	newModel_PrimeChecker_number_defaultValue_LiteralInteger_NewModel_PrimeChecker_number->setValue(8191);
	
	


	newModel_PrimeChecker = uml::UmlFactory::eInstance()->createClass();
	newModel_PrimeChecker->setName("PrimeChecker");
	newModel_PrimeChecker->setIsAbstract(false);
	newModel_PrimeChecker->setPackage(newModel);
	newModel->getPackagedElement()->push_back(newModel_PrimeChecker);
	
	//constraints
	
	
	newModel_PrimeChecker_divider = uml::UmlFactory::eInstance()->createProperty();
	newModel_PrimeChecker_divider->setName("divider");
	newModel_PrimeChecker_divider->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	newModel_PrimeChecker_divider->setLower(1);
	newModel_PrimeChecker_divider->setUpper(1);
	newModel_PrimeChecker->getOwnedAttribute()->push_back(newModel_PrimeChecker_divider);
	newModel_PrimeChecker_divider->setClass(newModel_PrimeChecker);
	newModel_PrimeChecker_divider->setDefaultValue(newModel_PrimeChecker_divider_defaultValue_LiteralInteger_NewModel_PrimeChecker_divider);
	
	newModel_PrimeChecker_number = uml::UmlFactory::eInstance()->createProperty();
	newModel_PrimeChecker_number->setName("number");
	newModel_PrimeChecker_number->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	newModel_PrimeChecker_number->setLower(1);
	newModel_PrimeChecker_number->setUpper(1);
	newModel_PrimeChecker->getOwnedAttribute()->push_back(newModel_PrimeChecker_number);
	newModel_PrimeChecker_number->setClass(newModel_PrimeChecker);
	newModel_PrimeChecker_number->setDefaultValue(newModel_PrimeChecker_number_defaultValue_LiteralInteger_NewModel_PrimeChecker_number);
	
	
	newModel_PrimeChecker_divides_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_divides_->setName("divides");
	newModel_PrimeChecker_divides_isDivisible = uml::UmlFactory::eInstance()->createParameter();
	newModel_PrimeChecker_divides_isDivisible->setName("isDivisible");
	newModel_PrimeChecker_divides_isDivisible->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	newModel_PrimeChecker_divides_isDivisible->setLower(1);
	newModel_PrimeChecker_divides_isDivisible->setUpper(1);
	newModel_PrimeChecker_divides_isDivisible->setDirection(uml::ParameterDirectionKind::RETURN);
	
	newModel_PrimeChecker_divides_->getOwnedParameter()->push_back(newModel_PrimeChecker_divides_isDivisible);
	
	
	newModel_PrimeChecker->getOwnedOperation()->push_back(newModel_PrimeChecker_divides_); 
	newModel_PrimeChecker_isNotFinished_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_isNotFinished_->setName("isNotFinished");
	newModel_PrimeChecker_isNotFinished_isNotFinished = uml::UmlFactory::eInstance()->createParameter();
	newModel_PrimeChecker_isNotFinished_isNotFinished->setName("isNotFinished");
	newModel_PrimeChecker_isNotFinished_isNotFinished->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	newModel_PrimeChecker_isNotFinished_isNotFinished->setLower(1);
	newModel_PrimeChecker_isNotFinished_isNotFinished->setUpper(1);
	newModel_PrimeChecker_isNotFinished_isNotFinished->setDirection(uml::ParameterDirectionKind::RETURN);
	
	newModel_PrimeChecker_isNotFinished_->getOwnedParameter()->push_back(newModel_PrimeChecker_isNotFinished_isNotFinished);
	
	
	newModel_PrimeChecker->getOwnedOperation()->push_back(newModel_PrimeChecker_isNotFinished_); 
	newModel_PrimeChecker_isOdd_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_isOdd_->setName("isOdd");
	newModel_PrimeChecker_isOdd_isOdd = uml::UmlFactory::eInstance()->createParameter();
	newModel_PrimeChecker_isOdd_isOdd->setName("isOdd");
	newModel_PrimeChecker_isOdd_isOdd->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	newModel_PrimeChecker_isOdd_isOdd->setLower(1);
	newModel_PrimeChecker_isOdd_isOdd->setUpper(1);
	newModel_PrimeChecker_isOdd_isOdd->setDirection(uml::ParameterDirectionKind::RETURN);
	
	newModel_PrimeChecker_isOdd_->getOwnedParameter()->push_back(newModel_PrimeChecker_isOdd_isOdd);
	
	
	newModel_PrimeChecker->getOwnedOperation()->push_back(newModel_PrimeChecker_isOdd_); 
	newModel_PrimeChecker_next_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_next_->setName("next");
	
	
	newModel_PrimeChecker->getOwnedOperation()->push_back(newModel_PrimeChecker_next_); 
	newModel_PrimeChecker_printIsPrime_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_printIsPrime_->setName("printIsPrime");
	
	
	newModel_PrimeChecker->getOwnedOperation()->push_back(newModel_PrimeChecker_printIsPrime_); 
	newModel_PrimeChecker_printNotPrime_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_printNotPrime_->setName("printNotPrime");
	
	
	newModel_PrimeChecker->getOwnedOperation()->push_back(newModel_PrimeChecker_printNotPrime_); 
	
	newModel_PrimeChecker_fbPrintNotPrime = uml::UmlFactory::eInstance()->createFunctionBehavior();
	newModel_PrimeChecker_fbPrintNotPrime->setName("fbPrintNotPrime");
	newModel_PrimeChecker->getOwnedBehavior()->push_back(newModel_PrimeChecker_fbPrintNotPrime);
	
	
	newModel_PrimeChecker_fbDivides = uml::UmlFactory::eInstance()->createFunctionBehavior();
	newModel_PrimeChecker_fbDivides->setName("fbDivides");
	newModel_PrimeChecker->getOwnedBehavior()->push_back(newModel_PrimeChecker_fbDivides);
	
	newModel_PrimeChecker_fbDivides_isDivisible = uml::UmlFactory::eInstance()->createParameter();
	newModel_PrimeChecker_fbDivides_isDivisible->setName("isDivisible");
	newModel_PrimeChecker_fbDivides_isDivisible->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	newModel_PrimeChecker_fbDivides_isDivisible->setLower(1);
	newModel_PrimeChecker_fbDivides_isDivisible->setUpper(1);
	newModel_PrimeChecker_fbDivides_isDivisible->setDirection(uml::ParameterDirectionKind::RETURN);
	
	newModel_PrimeChecker_fbDivides->getOwnedParameter()->push_back(newModel_PrimeChecker_fbDivides_isDivisible);
	
	newModel_PrimeChecker_fbPrintIsPrime = uml::UmlFactory::eInstance()->createFunctionBehavior();
	newModel_PrimeChecker_fbPrintIsPrime->setName("fbPrintIsPrime");
	newModel_PrimeChecker->getOwnedBehavior()->push_back(newModel_PrimeChecker_fbPrintIsPrime);
	
	
	newModel_PrimeChecker_fbIsNotFinished = uml::UmlFactory::eInstance()->createFunctionBehavior();
	newModel_PrimeChecker_fbIsNotFinished->setName("fbIsNotFinished");
	newModel_PrimeChecker->getOwnedBehavior()->push_back(newModel_PrimeChecker_fbIsNotFinished);
	
	newModel_PrimeChecker_fbIsNotFinished_isNotFinished = uml::UmlFactory::eInstance()->createParameter();
	newModel_PrimeChecker_fbIsNotFinished_isNotFinished->setName("isNotFinished");
	newModel_PrimeChecker_fbIsNotFinished_isNotFinished->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	newModel_PrimeChecker_fbIsNotFinished_isNotFinished->setLower(1);
	newModel_PrimeChecker_fbIsNotFinished_isNotFinished->setUpper(1);
	newModel_PrimeChecker_fbIsNotFinished_isNotFinished->setDirection(uml::ParameterDirectionKind::RETURN);
	
	newModel_PrimeChecker_fbIsNotFinished->getOwnedParameter()->push_back(newModel_PrimeChecker_fbIsNotFinished_isNotFinished);
	
	newModel_PrimeChecker_fbNext = uml::UmlFactory::eInstance()->createFunctionBehavior();
	newModel_PrimeChecker_fbNext->setName("fbNext");
	newModel_PrimeChecker->getOwnedBehavior()->push_back(newModel_PrimeChecker_fbNext);
	
	
	newModel_PrimeChecker_fbIsOdd = uml::UmlFactory::eInstance()->createFunctionBehavior();
	newModel_PrimeChecker_fbIsOdd->setName("fbIsOdd");
	newModel_PrimeChecker->getOwnedBehavior()->push_back(newModel_PrimeChecker_fbIsOdd);
	
	newModel_PrimeChecker_fbIsOdd_isOdd = uml::UmlFactory::eInstance()->createParameter();
	newModel_PrimeChecker_fbIsOdd_isOdd->setName("isOdd");
	newModel_PrimeChecker_fbIsOdd_isOdd->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	newModel_PrimeChecker_fbIsOdd_isOdd->setLower(1);
	newModel_PrimeChecker_fbIsOdd_isOdd->setUpper(1);
	newModel_PrimeChecker_fbIsOdd_isOdd->setDirection(uml::ParameterDirectionKind::RETURN);
	
	newModel_PrimeChecker_fbIsOdd->getOwnedParameter()->push_back(newModel_PrimeChecker_fbIsOdd_isOdd);
	
	




	newModel_CheckIfPrime = uml::UmlFactory::eInstance()->createActivity();
	newModel_CheckIfPrime->setName("CheckIfPrime");
	newModel_CheckIfPrime->setPackage(newModel);
	
	//parameter
	newModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode = uml::UmlFactory::eInstance()->createParameter();
	newModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode->setName("ActInputNode");
	newModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode->setType(get_NewModel_PrimeChecker());
	newModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode->setLower(1);
	newModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode->setUpper(1);
	newModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode->setDirection(uml::ParameterDirectionKind::IN);
	
	newModel_CheckIfPrime->getOwnedParameter()->push_back(newModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode);
	
	
	newModel->getPackagedElement()->push_back(newModel_CheckIfPrime);
	//Node
	newModel_CheckIfPrimeActivityFinal1 = uml::UmlFactory::eInstance()->createActivityFinalNode();
	newModel_CheckIfPrimeActivityFinal1->setName("ActivityFinal1");
	newModel_CheckIfPrimeActivityFinal1->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimeActivityFinal2 = uml::UmlFactory::eInstance()->createActivityFinalNode();
	newModel_CheckIfPrimeActivityFinal2->setName("ActivityFinal2");
	newModel_CheckIfPrimeActivityFinal2->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimeActivityFinal3 = uml::UmlFactory::eInstance()->createActivityFinalNode();
	newModel_CheckIfPrimeActivityFinal3->setName("ActivityFinal3");
	newModel_CheckIfPrimeActivityFinal3->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimeFork1 = uml::UmlFactory::eInstance()->createForkNode();
	newModel_CheckIfPrimeFork1->setName("Fork1");
	newModel_CheckIfPrimeFork1->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimeIsOdd = uml::UmlFactory::eInstance()->createDecisionNode();
	newModel_CheckIfPrimeIsOdd->setName("IsOdd");
	newModel_CheckIfPrimeIsOdd->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimeMerge = uml::UmlFactory::eInstance()->createMergeNode();
	newModel_CheckIfPrimeMerge->setName("Merge");
	newModel_CheckIfPrimeMerge->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimecbaPrintIsPrime = uml::UmlFactory::eInstance()->createCallBehaviorAction();
	newModel_CheckIfPrimecbaPrintIsPrime->setName("cbaPrintIsPrime");
	newModel_CheckIfPrimecbaPrintIsPrime->setActivity(newModel_CheckIfPrime);
	//CallBehaviorAction cbaPrintIsPrime
	newModel_CheckIfPrimecbaPrintIsPrime->setBehavior(newModel_PrimeChecker_fbPrintIsPrime);
	newModel_CheckIfPrimecbaPrintIsPrime->setIsSynchronous(true); //imposed by the fUML specification
	
	newModel_CheckIfPrimecbaPrintNotPrime = uml::UmlFactory::eInstance()->createCallBehaviorAction();
	newModel_CheckIfPrimecbaPrintNotPrime->setName("cbaPrintNotPrime");
	newModel_CheckIfPrimecbaPrintNotPrime->setActivity(newModel_CheckIfPrime);
	//CallBehaviorAction cbaPrintNotPrime
	newModel_CheckIfPrimecbaPrintNotPrime->setBehavior(newModel_PrimeChecker_fbPrintNotPrime);
	newModel_CheckIfPrimecbaPrintNotPrime->setIsSynchronous(true); //imposed by the fUML specification
	
	newModel_CheckIfPrimecbaPrintNotPrime2 = uml::UmlFactory::eInstance()->createCallBehaviorAction();
	newModel_CheckIfPrimecbaPrintNotPrime2->setName("cbaPrintNotPrime2");
	newModel_CheckIfPrimecbaPrintNotPrime2->setActivity(newModel_CheckIfPrime);
	//CallBehaviorAction cbaPrintNotPrime2
	newModel_CheckIfPrimecbaPrintNotPrime2->setBehavior(newModel_PrimeChecker_fbPrintNotPrime);
	newModel_CheckIfPrimecbaPrintNotPrime2->setIsSynchronous(true); //imposed by the fUML specification
	
	newModel_CheckIfPrimecoaDivides = uml::UmlFactory::eInstance()->createCallOperationAction();
	newModel_CheckIfPrimecoaDivides->setName("coaDivides");
	newModel_CheckIfPrimecoaDivides->setActivity(newModel_CheckIfPrime);
	//CallOperationAction coaDivides
	inputPin_coaDividestarget = uml::UmlFactory::eInstance()->createInputPin();
	inputPin_coaDividestarget->setName("target");
	
	outputPin_coaDividesisDivisible = uml::UmlFactory::eInstance()->createOutputPin();
	outputPin_coaDividesisDivisible->setName("isDivisible");
	
	newModel_PrimeChecker_divides_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_divides_->setName("divides");
	
	newModel_CheckIfPrimecoaIsNotFinished = uml::UmlFactory::eInstance()->createCallOperationAction();
	newModel_CheckIfPrimecoaIsNotFinished->setName("coaIsNotFinished");
	newModel_CheckIfPrimecoaIsNotFinished->setActivity(newModel_CheckIfPrime);
	//CallOperationAction coaIsNotFinished
	inputPin_coaIsNotFinishedtarget = uml::UmlFactory::eInstance()->createInputPin();
	inputPin_coaIsNotFinishedtarget->setName("target");
	
	outputPin_coaIsNotFinishedisNotFinished = uml::UmlFactory::eInstance()->createOutputPin();
	outputPin_coaIsNotFinishedisNotFinished->setName("isNotFinished");
	
	newModel_PrimeChecker_isNotFinished_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_isNotFinished_->setName("isNotFinished");
	
	newModel_CheckIfPrimecoaIsOdd = uml::UmlFactory::eInstance()->createCallOperationAction();
	newModel_CheckIfPrimecoaIsOdd->setName("coaIsOdd");
	newModel_CheckIfPrimecoaIsOdd->setActivity(newModel_CheckIfPrime);
	//CallOperationAction coaIsOdd
	inputPin_coaIsOddtarget = uml::UmlFactory::eInstance()->createInputPin();
	inputPin_coaIsOddtarget->setName("target");
	
	outputPin_coaIsOddisOdd = uml::UmlFactory::eInstance()->createOutputPin();
	outputPin_coaIsOddisOdd->setName("isOdd");
	
	newModel_PrimeChecker_isOdd_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_isOdd_->setName("isOdd");
	
	newModel_CheckIfPrimecoaNext = uml::UmlFactory::eInstance()->createCallOperationAction();
	newModel_CheckIfPrimecoaNext->setName("coaNext");
	newModel_CheckIfPrimecoaNext->setActivity(newModel_CheckIfPrime);
	//CallOperationAction coaNext
	inputPin_coaNexttarget = uml::UmlFactory::eInstance()->createInputPin();
	inputPin_coaNexttarget->setName("target");
	
	
	newModel_PrimeChecker_next_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_next_->setName("next");
	
	newModel_CheckIfPrimedivides = uml::UmlFactory::eInstance()->createDecisionNode();
	newModel_CheckIfPrimedivides->setName("divides");
	newModel_CheckIfPrimedivides->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimeisNotFinished = uml::UmlFactory::eInstance()->createDecisionNode();
	newModel_CheckIfPrimeisNotFinished->setName("isNotFinished");
	newModel_CheckIfPrimeisNotFinished->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimenext_call = uml::UmlFactory::eInstance()->createCallOperationAction();
	newModel_CheckIfPrimenext_call->setName("next_call");
	newModel_CheckIfPrimenext_call->setActivity(newModel_CheckIfPrime);
	//CallOperationAction next_call
	inputPin_next_calltarget = uml::UmlFactory::eInstance()->createInputPin();
	inputPin_next_calltarget->setName("target");
	
	
	newModel_PrimeChecker_next_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_next_->setName("next");
	
	newModel_CheckIfPrimeprimeChecker = uml::UmlFactory::eInstance()->createActivityParameterNode();
	newModel_CheckIfPrimeprimeChecker->setName("primeChecker");
	newModel_CheckIfPrimeprimeChecker->setActivity(newModel_CheckIfPrime);
	
	//flow
	newModel_CheckIfPrimeifIsOdd = uml::UmlFactory::eInstance()->createObjectFlow();
	newModel_CheckIfPrimeifIsOdd->setName("ifIsOdd");
	newModel_CheckIfPrimeifIsOdd->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(newModel_CheckIfPrimeifIsOdd);oF_NewModel_CheckIfPrimeFork1_InputPin_next_calltarget = uml::UmlFactory::eInstance()->createObjectFlow();
	oF_NewModel_CheckIfPrimeFork1_InputPin_next_calltarget->setName("");
	oF_NewModel_CheckIfPrimeFork1_InputPin_next_calltarget->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_next_calltarget);oF_NewModel_CheckIfPrimeFork1_InputPin_coaDividestarget = uml::UmlFactory::eInstance()->createObjectFlow();
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaDividestarget->setName("");
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaDividestarget->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_coaDividestarget);newModel_CheckIfPrimeifDivides = uml::UmlFactory::eInstance()->createObjectFlow();
	newModel_CheckIfPrimeifDivides->setName("ifDivides");
	newModel_CheckIfPrimeifDivides->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(newModel_CheckIfPrimeifDivides);cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1 = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1->setName("");
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1);oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1 = uml::UmlFactory::eInstance()->createObjectFlow();
	oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1->setName("");
	oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1);cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge->setName("");
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge);cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides->setName("");
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides);cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime->setName("");
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime);cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3 = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3->setName("");
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3);oF_NewModel_CheckIfPrimeFork1_InputPin_coaNexttarget = uml::UmlFactory::eInstance()->createObjectFlow();
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaNexttarget->setName("");
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaNexttarget->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_coaNexttarget);cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2 = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2->setName("");
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2);cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2 = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2->setName("");
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2);cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime->setName("");
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime);oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget = uml::UmlFactory::eInstance()->createObjectFlow();
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget->setName("");
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget);cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge->setName("");
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge);oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget = uml::UmlFactory::eInstance()->createObjectFlow();
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget->setName("");
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget);cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call->setName("");
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call);cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished->setName("");
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished);newModel_CheckIfPrimeifIsNotFinished = uml::UmlFactory::eInstance()->createObjectFlow();
	newModel_CheckIfPrimeifIsNotFinished->setName("ifIsNotFinished");
	newModel_CheckIfPrimeifIsNotFinished->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->push_back(newModel_CheckIfPrimeifIsNotFinished);

//Dependency 

	

}

void NewModelPackageImpl::initializePackageContents()
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
	uml::Generalization * gen = nullptr;
	
	
	

	newModel_PrimeChecker_next_->getMethod()->push_back(newModel_PrimeChecker_fbNext);
	newModel_PrimeChecker_printIsPrime_->getMethod()->push_back(newModel_PrimeChecker_fbPrintIsPrime);
	newModel_PrimeChecker_isNotFinished_->getMethod()->push_back(newModel_PrimeChecker_fbIsNotFinished);
	newModel_PrimeChecker_divides_->getMethod()->push_back(newModel_PrimeChecker_fbDivides);
	newModel_PrimeChecker_isOdd_->getMethod()->push_back(newModel_PrimeChecker_fbIsOdd);
	newModel_PrimeChecker_printNotPrime_->getMethod()->push_back(newModel_PrimeChecker_fbPrintNotPrime);
	
	
	//initalize ActivityNodes and Edges
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimeprimeChecker);
	newModel_CheckIfPrimeprimeChecker->setParameter(newModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode);
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimeFork1);
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimecoaNext);
	newModel_CheckIfPrimecoaNext->setOperation(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_next_());
	newModel_CheckIfPrimecoaNext->getArgument()->push_back(inputPin_coaNexttarget);
	
	
	newModel_CheckIfPrimecoaNext->setTarget(NewModel::NewModelPackage::eInstance()->get_InputPin_coaNexttarget());
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimenext_call);
	newModel_CheckIfPrimenext_call->setOperation(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_next_());
	newModel_CheckIfPrimenext_call->getArgument()->push_back(inputPin_next_calltarget);
	
	
	newModel_CheckIfPrimenext_call->setTarget(NewModel::NewModelPackage::eInstance()->get_InputPin_next_calltarget());
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimeMerge);
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimeisNotFinished);
	
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimecbaPrintNotPrime);
	newModel_CheckIfPrimecbaPrintNotPrime->setBehavior(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_fbPrintNotPrime());
	
	
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimecoaDivides);
	newModel_CheckIfPrimecoaDivides->setOperation(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_divides_());
	newModel_CheckIfPrimecoaDivides->getArgument()->push_back(inputPin_coaDividestarget);
	
	newModel_CheckIfPrimecoaDivides->getResult()->push_back(outputPin_coaDividesisDivisible);
	
	newModel_CheckIfPrimecoaDivides->setTarget(NewModel::NewModelPackage::eInstance()->get_InputPin_coaDividestarget());
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimeActivityFinal2);
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimeActivityFinal1);
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimecoaIsNotFinished);
	newModel_CheckIfPrimecoaIsNotFinished->setOperation(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_isNotFinished_());
	newModel_CheckIfPrimecoaIsNotFinished->getArgument()->push_back(inputPin_coaIsNotFinishedtarget);
	
	newModel_CheckIfPrimecoaIsNotFinished->getResult()->push_back(outputPin_coaIsNotFinishedisNotFinished);
	
	newModel_CheckIfPrimecoaIsNotFinished->setTarget(NewModel::NewModelPackage::eInstance()->get_InputPin_coaIsNotFinishedtarget());
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimeIsOdd);
	
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimecoaIsOdd);
	newModel_CheckIfPrimecoaIsOdd->setOperation(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_isOdd_());
	newModel_CheckIfPrimecoaIsOdd->getArgument()->push_back(inputPin_coaIsOddtarget);
	
	newModel_CheckIfPrimecoaIsOdd->getResult()->push_back(outputPin_coaIsOddisOdd);
	
	newModel_CheckIfPrimecoaIsOdd->setTarget(NewModel::NewModelPackage::eInstance()->get_InputPin_coaIsOddtarget());
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimecbaPrintIsPrime);
	newModel_CheckIfPrimecbaPrintIsPrime->setBehavior(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_fbPrintIsPrime());
	
	
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimeActivityFinal3);
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimecbaPrintNotPrime2);
	newModel_CheckIfPrimecbaPrintNotPrime2->setBehavior(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_fbPrintNotPrime());
	
	
	
	newModel_CheckIfPrime->getNode()->push_back(newModel_CheckIfPrimedivides);
	
	
	
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge->setSource(newModel_CheckIfPrimeisNotFinished);
	newModel_CheckIfPrimeisNotFinished->getOutgoing()->push_back(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge);
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge->setTarget(newModel_CheckIfPrimeMerge);
	newModel_CheckIfPrimeMerge->getIncoming()->push_back(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge);
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge->setGuard(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge);
	newModel_CheckIfPrimeifIsOdd->setSource(outputPin_coaIsOddisOdd);
	outputPin_coaIsOddisOdd->getOutgoing()->push_back(newModel_CheckIfPrimeifIsOdd);
	newModel_CheckIfPrimeifIsOdd->setTarget(newModel_CheckIfPrimeIsOdd);
	newModel_CheckIfPrimeIsOdd->getIncoming()->push_back(newModel_CheckIfPrimeifIsOdd);
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge->setSource(newModel_CheckIfPrimeIsOdd);
	newModel_CheckIfPrimeIsOdd->getOutgoing()->push_back(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge);
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge->setTarget(newModel_CheckIfPrimeMerge);
	newModel_CheckIfPrimeMerge->getIncoming()->push_back(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge);
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge->setGuard(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge);
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2->setSource(newModel_CheckIfPrimeIsOdd);
	newModel_CheckIfPrimeIsOdd->getOutgoing()->push_back(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2);
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2->setTarget(newModel_CheckIfPrimecbaPrintNotPrime2);
	newModel_CheckIfPrimecbaPrintNotPrime2->getIncoming()->push_back(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2);
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2->setGuard(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2);
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime->setSource(newModel_CheckIfPrimeisNotFinished);
	newModel_CheckIfPrimeisNotFinished->getOutgoing()->push_back(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime);
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime->setTarget(newModel_CheckIfPrimecbaPrintIsPrime);
	newModel_CheckIfPrimecbaPrintIsPrime->getIncoming()->push_back(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime);
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime->setGuard(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime);
	oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1->setSource(newModel_CheckIfPrimeprimeChecker);
	newModel_CheckIfPrimeprimeChecker->getOutgoing()->push_back(oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1);
	oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1->setTarget(newModel_CheckIfPrimeFork1);
	newModel_CheckIfPrimeFork1->getIncoming()->push_back(oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1);
	newModel_CheckIfPrimeifIsNotFinished->setSource(outputPin_coaIsNotFinishedisNotFinished);
	outputPin_coaIsNotFinishedisNotFinished->getOutgoing()->push_back(newModel_CheckIfPrimeifIsNotFinished);
	newModel_CheckIfPrimeifIsNotFinished->setTarget(newModel_CheckIfPrimeisNotFinished);
	newModel_CheckIfPrimeisNotFinished->getIncoming()->push_back(newModel_CheckIfPrimeifIsNotFinished);
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1->setSource(newModel_CheckIfPrimecbaPrintNotPrime2);
	newModel_CheckIfPrimecbaPrintNotPrime2->getOutgoing()->push_back(cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1);
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1->setTarget(newModel_CheckIfPrimeActivityFinal1);
	newModel_CheckIfPrimeActivityFinal1->getIncoming()->push_back(cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1);
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1->setGuard(cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1_guard_LiteralBoolean_CF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1);
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call->setSource(newModel_CheckIfPrimedivides);
	newModel_CheckIfPrimedivides->getOutgoing()->push_back(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call);
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call->setTarget(newModel_CheckIfPrimenext_call);
	newModel_CheckIfPrimenext_call->getIncoming()->push_back(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call);
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call->setGuard(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call_guard_LiteralBoolean_CF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call);
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3->setSource(newModel_CheckIfPrimecbaPrintIsPrime);
	newModel_CheckIfPrimecbaPrintIsPrime->getOutgoing()->push_back(cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3);
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3->setTarget(newModel_CheckIfPrimeActivityFinal3);
	newModel_CheckIfPrimeActivityFinal3->getIncoming()->push_back(cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3);
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3->setGuard(cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3_guard_LiteralBoolean_CF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3);
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaNexttarget->setSource(newModel_CheckIfPrimeFork1);
	newModel_CheckIfPrimeFork1->getOutgoing()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_coaNexttarget);
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaNexttarget->setTarget(inputPin_coaNexttarget);
	inputPin_coaNexttarget->getIncoming()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_coaNexttarget);
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget->setSource(newModel_CheckIfPrimeFork1);
	newModel_CheckIfPrimeFork1->getOutgoing()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget);
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget->setTarget(inputPin_coaIsNotFinishedtarget);
	inputPin_coaIsNotFinishedtarget->getIncoming()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget);
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2->setSource(newModel_CheckIfPrimecbaPrintNotPrime);
	newModel_CheckIfPrimecbaPrintNotPrime->getOutgoing()->push_back(cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2);
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2->setTarget(newModel_CheckIfPrimeActivityFinal2);
	newModel_CheckIfPrimeActivityFinal2->getIncoming()->push_back(cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2);
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2->setGuard(cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2_guard_LiteralBoolean_CF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2);
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished->setSource(newModel_CheckIfPrimenext_call);
	newModel_CheckIfPrimenext_call->getOutgoing()->push_back(cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished);
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished->setTarget(newModel_CheckIfPrimecoaIsNotFinished);
	newModel_CheckIfPrimecoaIsNotFinished->getIncoming()->push_back(cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished);
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished->setGuard(cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished_guard_LiteralBoolean_CF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished);
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaDividestarget->setSource(newModel_CheckIfPrimeFork1);
	newModel_CheckIfPrimeFork1->getOutgoing()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_coaDividestarget);
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaDividestarget->setTarget(inputPin_coaDividestarget);
	inputPin_coaDividestarget->getIncoming()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_coaDividestarget);
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime->setSource(newModel_CheckIfPrimedivides);
	newModel_CheckIfPrimedivides->getOutgoing()->push_back(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime);
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime->setTarget(newModel_CheckIfPrimecbaPrintNotPrime);
	newModel_CheckIfPrimecbaPrintNotPrime->getIncoming()->push_back(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime);
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime->setGuard(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime_guard_LiteralBoolean_CF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime);
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget->setSource(newModel_CheckIfPrimeFork1);
	newModel_CheckIfPrimeFork1->getOutgoing()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget);
	oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget->setTarget(inputPin_coaIsOddtarget);
	inputPin_coaIsOddtarget->getIncoming()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget);
	oF_NewModel_CheckIfPrimeFork1_InputPin_next_calltarget->setSource(newModel_CheckIfPrimeFork1);
	newModel_CheckIfPrimeFork1->getOutgoing()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_next_calltarget);
	oF_NewModel_CheckIfPrimeFork1_InputPin_next_calltarget->setTarget(inputPin_next_calltarget);
	inputPin_next_calltarget->getIncoming()->push_back(oF_NewModel_CheckIfPrimeFork1_InputPin_next_calltarget);
	newModel_CheckIfPrimeifDivides->setSource(outputPin_coaDividesisDivisible);
	outputPin_coaDividesisDivisible->getOutgoing()->push_back(newModel_CheckIfPrimeifDivides);
	newModel_CheckIfPrimeifDivides->setTarget(newModel_CheckIfPrimedivides);
	newModel_CheckIfPrimedivides->getIncoming()->push_back(newModel_CheckIfPrimeifDivides);
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides->setSource(newModel_CheckIfPrimeMerge);
	newModel_CheckIfPrimeMerge->getOutgoing()->push_back(cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides);
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides->setTarget(newModel_CheckIfPrimecoaDivides);
	newModel_CheckIfPrimecoaDivides->getIncoming()->push_back(cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides);
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides->setGuard(cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides_guard_LiteralBoolean_CF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides);
	
}

uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge()
{
	return cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2()
{
	return cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides()
{
	return cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3()
{
	return cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1()
{
	return cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2()
{
	return cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime()
{
	return cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call()
{
	return cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge()
{
	return cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime()
{
	return cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished()
{
	return cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished;
}
uml::InputPin* NewModelPackageImpl::get_InputPin_coaDividestarget()
{
	return inputPin_coaDividestarget;
}
uml::InputPin* NewModelPackageImpl::get_InputPin_coaIsNotFinishedtarget()
{
	return inputPin_coaIsNotFinishedtarget;
}
uml::InputPin* NewModelPackageImpl::get_InputPin_coaIsOddtarget()
{
	return inputPin_coaIsOddtarget;
}
uml::InputPin* NewModelPackageImpl::get_InputPin_coaNexttarget()
{
	return inputPin_coaNexttarget;
}
uml::InputPin* NewModelPackageImpl::get_InputPin_next_calltarget()
{
	return inputPin_next_calltarget;
}
uml::Activity* NewModelPackageImpl::get_NewModel_CheckIfPrime()
{
	return newModel_CheckIfPrime;
}
uml::ActivityFinalNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeActivityFinal1()
{
	return newModel_CheckIfPrimeActivityFinal1;
}
uml::ActivityFinalNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeActivityFinal2()
{
	return newModel_CheckIfPrimeActivityFinal2;
}
uml::ActivityFinalNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeActivityFinal3()
{
	return newModel_CheckIfPrimeActivityFinal3;
}
uml::ForkNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeFork1()
{
	return newModel_CheckIfPrimeFork1;
}
uml::DecisionNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeIsOdd()
{
	return newModel_CheckIfPrimeIsOdd;
}
uml::MergeNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeMerge()
{
	return newModel_CheckIfPrimeMerge;
}
uml::Parameter* NewModelPackageImpl::get_NewModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode()
{
	return newModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode;
}
uml::CallBehaviorAction* NewModelPackageImpl::get_NewModel_CheckIfPrimecbaPrintIsPrime()
{
	return newModel_CheckIfPrimecbaPrintIsPrime;
}
uml::CallBehaviorAction* NewModelPackageImpl::get_NewModel_CheckIfPrimecbaPrintNotPrime()
{
	return newModel_CheckIfPrimecbaPrintNotPrime;
}
uml::CallBehaviorAction* NewModelPackageImpl::get_NewModel_CheckIfPrimecbaPrintNotPrime2()
{
	return newModel_CheckIfPrimecbaPrintNotPrime2;
}
uml::CallOperationAction* NewModelPackageImpl::get_NewModel_CheckIfPrimecoaDivides()
{
	return newModel_CheckIfPrimecoaDivides;
}
uml::CallOperationAction* NewModelPackageImpl::get_NewModel_CheckIfPrimecoaIsNotFinished()
{
	return newModel_CheckIfPrimecoaIsNotFinished;
}
uml::CallOperationAction* NewModelPackageImpl::get_NewModel_CheckIfPrimecoaIsOdd()
{
	return newModel_CheckIfPrimecoaIsOdd;
}
uml::CallOperationAction* NewModelPackageImpl::get_NewModel_CheckIfPrimecoaNext()
{
	return newModel_CheckIfPrimecoaNext;
}
uml::DecisionNode* NewModelPackageImpl::get_NewModel_CheckIfPrimedivides()
{
	return newModel_CheckIfPrimedivides;
}
uml::ObjectFlow* NewModelPackageImpl::get_NewModel_CheckIfPrimeifDivides()
{
	return newModel_CheckIfPrimeifDivides;
}
uml::ObjectFlow* NewModelPackageImpl::get_NewModel_CheckIfPrimeifIsNotFinished()
{
	return newModel_CheckIfPrimeifIsNotFinished;
}
uml::ObjectFlow* NewModelPackageImpl::get_NewModel_CheckIfPrimeifIsOdd()
{
	return newModel_CheckIfPrimeifIsOdd;
}
uml::DecisionNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeisNotFinished()
{
	return newModel_CheckIfPrimeisNotFinished;
}
uml::CallOperationAction* NewModelPackageImpl::get_NewModel_CheckIfPrimenext_call()
{
	return newModel_CheckIfPrimenext_call;
}
uml::ActivityParameterNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeprimeChecker()
{
	return newModel_CheckIfPrimeprimeChecker;
}
uml::Class* NewModelPackageImpl::get_NewModel_PrimeChecker()
{
	return newModel_PrimeChecker;
}
uml::Property* NewModelPackageImpl::get_NewModel_PrimeChecker_divider()
{
	return newModel_PrimeChecker_divider;
}
uml::Parameter* NewModelPackageImpl::get_NewModel_PrimeChecker_divides_isDivisible()
{
	return newModel_PrimeChecker_divides_isDivisible;
}
uml::Operation* NewModelPackageImpl::get_NewModel_PrimeChecker_divides_()
{
	return newModel_PrimeChecker_divides_;
}
uml::FunctionBehavior* NewModelPackageImpl::get_NewModel_PrimeChecker_fbDivides()
{
	return newModel_PrimeChecker_fbDivides;
}
uml::Parameter* NewModelPackageImpl::get_NewModel_PrimeChecker_fbDivides_isDivisible()
{
	return newModel_PrimeChecker_fbDivides_isDivisible;
}
uml::FunctionBehavior* NewModelPackageImpl::get_NewModel_PrimeChecker_fbIsNotFinished()
{
	return newModel_PrimeChecker_fbIsNotFinished;
}
uml::Parameter* NewModelPackageImpl::get_NewModel_PrimeChecker_fbIsNotFinished_isNotFinished()
{
	return newModel_PrimeChecker_fbIsNotFinished_isNotFinished;
}
uml::FunctionBehavior* NewModelPackageImpl::get_NewModel_PrimeChecker_fbIsOdd()
{
	return newModel_PrimeChecker_fbIsOdd;
}
uml::Parameter* NewModelPackageImpl::get_NewModel_PrimeChecker_fbIsOdd_isOdd()
{
	return newModel_PrimeChecker_fbIsOdd_isOdd;
}
uml::FunctionBehavior* NewModelPackageImpl::get_NewModel_PrimeChecker_fbNext()
{
	return newModel_PrimeChecker_fbNext;
}
uml::FunctionBehavior* NewModelPackageImpl::get_NewModel_PrimeChecker_fbPrintIsPrime()
{
	return newModel_PrimeChecker_fbPrintIsPrime;
}
uml::FunctionBehavior* NewModelPackageImpl::get_NewModel_PrimeChecker_fbPrintNotPrime()
{
	return newModel_PrimeChecker_fbPrintNotPrime;
}
uml::Parameter* NewModelPackageImpl::get_NewModel_PrimeChecker_isNotFinished_isNotFinished()
{
	return newModel_PrimeChecker_isNotFinished_isNotFinished;
}
uml::Operation* NewModelPackageImpl::get_NewModel_PrimeChecker_isNotFinished_()
{
	return newModel_PrimeChecker_isNotFinished_;
}
uml::Parameter* NewModelPackageImpl::get_NewModel_PrimeChecker_isOdd_isOdd()
{
	return newModel_PrimeChecker_isOdd_isOdd;
}
uml::Operation* NewModelPackageImpl::get_NewModel_PrimeChecker_isOdd_()
{
	return newModel_PrimeChecker_isOdd_;
}
uml::Operation* NewModelPackageImpl::get_NewModel_PrimeChecker_next_()
{
	return newModel_PrimeChecker_next_;
}
uml::Property* NewModelPackageImpl::get_NewModel_PrimeChecker_number()
{
	return newModel_PrimeChecker_number;
}
uml::Operation* NewModelPackageImpl::get_NewModel_PrimeChecker_printIsPrime_()
{
	return newModel_PrimeChecker_printIsPrime_;
}
uml::Operation* NewModelPackageImpl::get_NewModel_PrimeChecker_printNotPrime_()
{
	return newModel_PrimeChecker_printNotPrime_;
}
uml::ObjectFlow* NewModelPackageImpl::get_OF_NewModel_CheckIfPrimeFork1_InputPin_coaDividestarget()
{
	return oF_NewModel_CheckIfPrimeFork1_InputPin_coaDividestarget;
}
uml::ObjectFlow* NewModelPackageImpl::get_OF_NewModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget()
{
	return oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsNotFinishedtarget;
}
uml::ObjectFlow* NewModelPackageImpl::get_OF_NewModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget()
{
	return oF_NewModel_CheckIfPrimeFork1_InputPin_coaIsOddtarget;
}
uml::ObjectFlow* NewModelPackageImpl::get_OF_NewModel_CheckIfPrimeFork1_InputPin_coaNexttarget()
{
	return oF_NewModel_CheckIfPrimeFork1_InputPin_coaNexttarget;
}
uml::ObjectFlow* NewModelPackageImpl::get_OF_NewModel_CheckIfPrimeFork1_InputPin_next_calltarget()
{
	return oF_NewModel_CheckIfPrimeFork1_InputPin_next_calltarget;
}
uml::ObjectFlow* NewModelPackageImpl::get_OF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1()
{
	return oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1;
}
uml::OutputPin* NewModelPackageImpl::get_OutputPin_coaDividesisDivisible()
{
	return outputPin_coaDividesisDivisible;
}
uml::OutputPin* NewModelPackageImpl::get_OutputPin_coaIsNotFinishedisNotFinished()
{
	return outputPin_coaIsNotFinishedisNotFinished;
}
uml::OutputPin* NewModelPackageImpl::get_OutputPin_coaIsOddisOdd()
{
	return outputPin_coaIsOddisOdd;
}


