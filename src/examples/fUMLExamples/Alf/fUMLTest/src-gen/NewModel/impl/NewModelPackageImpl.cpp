
#include "NewModelPackageImpl.hpp"


//metamodel classes
#include "Stereotype.hpp"
#include "Generalization.hpp"
#include "Constraint.hpp"
#include "OpaqueExpression.hpp"
#include "EnumerationLiteral.hpp"
#include "PrimitiveType.hpp"
#include "FunctionBehavior.hpp"

#include "LiteralInteger.hpp"
#include "CallBehaviorAction.hpp"
#include "ControlFlow.hpp"
#include "Property.hpp"
#include "CallOperationAction.hpp"
#include "OutputPin.hpp"
#include "ActivityFinalNode.hpp"
#include "MergeNode.hpp"
#include "ForkNode.hpp"
#include "Activity.hpp"
#include "Class.hpp"
#include "Operation.hpp"
#include "ObjectFlow.hpp"
#include "LiteralBoolean.hpp"
#include "Parameter.hpp"
#include "FunctionBehavior.hpp"
#include "ActivityParameterNode.hpp"
#include "DecisionNode.hpp"
#include "ProfileApplication.hpp"
#include "InputPin.hpp"
#include "LiteralString.hpp"
//metamodel factory
#include "NewModelFactory.hpp"
#include "UmlFactory.hpp"

//depending model packages

#include "PrimitiveTypesPackage.hpp"


#include "PrimitiveTypesPackage.hpp"



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
	if (isInited) return NewModelPackage::eInstance();
	isInited = true;
	
    // Obtain or create and register package
    NewModelPackageImpl * metaModelPackage = new NewModelPackageImpl();
	metaModelPackage->initMetaModel();

 	// Create package meta-data objects
    metaModelPackage->createPackageContents();
	// Update the registry and return the package
    
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
	if (isCreated) return;
		isCreated = true;
	
	uml::Package * newModel = this;

	uml::Constraint * con = nullptr;
	uml::OpaqueExpression * oe = nullptr;

	newModel_PrimeChecker = uml::UmlFactory::eInstance()->createClass();
	newModel_PrimeChecker->setName("PrimeChecker");
	newModel_PrimeChecker->setIsAbstract(false);
	newModel_PrimeChecker->setPackage(newModel);
	newModel->getPackagedElement()->append(newModel_PrimeChecker);
	
	//constraints
	
	
	
	//generate Nested Activities
	
	
	
	
	
	newModel_PrimeChecker_number = uml::UmlFactory::eInstance()->createProperty();
	newModel_PrimeChecker_number->setName("number");
	newModel_PrimeChecker_number->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	newModel_PrimeChecker_number->setLower(1);
	newModel_PrimeChecker_number->setUpper(1);
	newModel_PrimeChecker->getOwnedAttribute()->append(newModel_PrimeChecker_number);
	newModel_PrimeChecker_number->setClass(newModel_PrimeChecker);
	
	
	newModel_PrimeChecker_divider = uml::UmlFactory::eInstance()->createProperty();
	newModel_PrimeChecker_divider->setName("divider");
	newModel_PrimeChecker_divider->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	newModel_PrimeChecker_divider->setLower(1);
	newModel_PrimeChecker_divider->setUpper(1);
	newModel_PrimeChecker->getOwnedAttribute()->append(newModel_PrimeChecker_divider);
	newModel_PrimeChecker_divider->setClass(newModel_PrimeChecker);
	
	
	
	newModel_PrimeChecker_divides_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_divides_->setName("divides");
	newModel_PrimeChecker_divides_isDivisible = uml::UmlFactory::eInstance()->createParameter();
	newModel_PrimeChecker_divides_isDivisible->setName("isDivisible");
	newModel_PrimeChecker_divides_isDivisible->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	newModel_PrimeChecker_divides_isDivisible->setLower(1);
	newModel_PrimeChecker_divides_isDivisible->setUpper(1);
	newModel_PrimeChecker_divides_isDivisible->setDirection(uml::ParameterDirectionKind::RETURN);
	
	newModel_PrimeChecker_divides_->getOwnedParameter()->append(newModel_PrimeChecker_divides_isDivisible);
	
	
	newModel_PrimeChecker->getOwnedOperation()->append(newModel_PrimeChecker_divides_); 
	
	newModel_PrimeChecker_next_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_next_->setName("next");
	
	
	newModel_PrimeChecker->getOwnedOperation()->append(newModel_PrimeChecker_next_); 
	
	newModel_PrimeChecker_printIsPrime_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_printIsPrime_->setName("printIsPrime");
	
	
	newModel_PrimeChecker->getOwnedOperation()->append(newModel_PrimeChecker_printIsPrime_); 
	
	newModel_PrimeChecker_printNotPrime_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_printNotPrime_->setName("printNotPrime");
	
	
	newModel_PrimeChecker->getOwnedOperation()->append(newModel_PrimeChecker_printNotPrime_); 
	
	newModel_PrimeChecker_isOdd_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_isOdd_->setName("isOdd");
	newModel_PrimeChecker_isOdd_isOdd = uml::UmlFactory::eInstance()->createParameter();
	newModel_PrimeChecker_isOdd_isOdd->setName("isOdd");
	newModel_PrimeChecker_isOdd_isOdd->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	newModel_PrimeChecker_isOdd_isOdd->setLower(1);
	newModel_PrimeChecker_isOdd_isOdd->setUpper(1);
	newModel_PrimeChecker_isOdd_isOdd->setDirection(uml::ParameterDirectionKind::RETURN);
	
	newModel_PrimeChecker_isOdd_->getOwnedParameter()->append(newModel_PrimeChecker_isOdd_isOdd);
	
	
	newModel_PrimeChecker->getOwnedOperation()->append(newModel_PrimeChecker_isOdd_); 
	
	newModel_PrimeChecker_isNotFinished_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_isNotFinished_->setName("isNotFinished");
	newModel_PrimeChecker_isNotFinished_isNotFinished = uml::UmlFactory::eInstance()->createParameter();
	newModel_PrimeChecker_isNotFinished_isNotFinished->setName("isNotFinished");
	newModel_PrimeChecker_isNotFinished_isNotFinished->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	newModel_PrimeChecker_isNotFinished_isNotFinished->setLower(1);
	newModel_PrimeChecker_isNotFinished_isNotFinished->setUpper(1);
	newModel_PrimeChecker_isNotFinished_isNotFinished->setDirection(uml::ParameterDirectionKind::RETURN);
	
	newModel_PrimeChecker_isNotFinished_->getOwnedParameter()->append(newModel_PrimeChecker_isNotFinished_isNotFinished);
	
	
	newModel_PrimeChecker->getOwnedOperation()->append(newModel_PrimeChecker_isNotFinished_); 
	
	
	newModel_PrimeChecker_isOdd = uml::UmlFactory::eInstance()->createFunctionBehavior();
	newModel_PrimeChecker_isOdd->setName("isOdd");
	newModel_PrimeChecker->getOwnedBehavior()->append(newModel_PrimeChecker_isOdd);
	
	
	newModel_PrimeChecker_isOdd_isOdd = uml::UmlFactory::eInstance()->createParameter();
	newModel_PrimeChecker_isOdd_isOdd->setName("isOdd");
	newModel_PrimeChecker_isOdd_isOdd->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	newModel_PrimeChecker_isOdd_isOdd->setLower(1);
	newModel_PrimeChecker_isOdd_isOdd->setUpper(1);
	newModel_PrimeChecker_isOdd_isOdd->setDirection(uml::ParameterDirectionKind::RETURN);
	
	newModel_PrimeChecker_isOdd->getOwnedParameter()->append(newModel_PrimeChecker_isOdd_isOdd);
	
	newModel_PrimeChecker_isNotFinished = uml::UmlFactory::eInstance()->createFunctionBehavior();
	newModel_PrimeChecker_isNotFinished->setName("isNotFinished");
	newModel_PrimeChecker->getOwnedBehavior()->append(newModel_PrimeChecker_isNotFinished);
	
	
	newModel_PrimeChecker_isNotFinished_isNotFinished = uml::UmlFactory::eInstance()->createParameter();
	newModel_PrimeChecker_isNotFinished_isNotFinished->setName("isNotFinished");
	newModel_PrimeChecker_isNotFinished_isNotFinished->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	newModel_PrimeChecker_isNotFinished_isNotFinished->setLower(1);
	newModel_PrimeChecker_isNotFinished_isNotFinished->setUpper(1);
	newModel_PrimeChecker_isNotFinished_isNotFinished->setDirection(uml::ParameterDirectionKind::RETURN);
	
	newModel_PrimeChecker_isNotFinished->getOwnedParameter()->append(newModel_PrimeChecker_isNotFinished_isNotFinished);
	
	newModel_PrimeChecker_next = uml::UmlFactory::eInstance()->createFunctionBehavior();
	newModel_PrimeChecker_next->setName("next");
	newModel_PrimeChecker->getOwnedBehavior()->append(newModel_PrimeChecker_next);
	
	
	
	newModel_PrimeChecker_divides = uml::UmlFactory::eInstance()->createFunctionBehavior();
	newModel_PrimeChecker_divides->setName("divides");
	newModel_PrimeChecker->getOwnedBehavior()->append(newModel_PrimeChecker_divides);
	
	
	newModel_PrimeChecker_divides_isDivisible = uml::UmlFactory::eInstance()->createParameter();
	newModel_PrimeChecker_divides_isDivisible->setName("isDivisible");
	newModel_PrimeChecker_divides_isDivisible->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	newModel_PrimeChecker_divides_isDivisible->setLower(1);
	newModel_PrimeChecker_divides_isDivisible->setUpper(1);
	newModel_PrimeChecker_divides_isDivisible->setDirection(uml::ParameterDirectionKind::RETURN);
	
	newModel_PrimeChecker_divides->getOwnedParameter()->append(newModel_PrimeChecker_divides_isDivisible);
	
	newModel_PrimeChecker_printIsPrime = uml::UmlFactory::eInstance()->createFunctionBehavior();
	newModel_PrimeChecker_printIsPrime->setName("printIsPrime");
	newModel_PrimeChecker->getOwnedBehavior()->append(newModel_PrimeChecker_printIsPrime);
	
	
	
	newModel_PrimeChecker_PrintNotPrime = uml::UmlFactory::eInstance()->createFunctionBehavior();
	newModel_PrimeChecker_PrintNotPrime->setName("PrintNotPrime");
	newModel_PrimeChecker->getOwnedBehavior()->append(newModel_PrimeChecker_PrintNotPrime);
	
	
	
	


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
	
	newModel_CheckIfPrime->getOwnedParameter()->append(newModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode);
	
	
	
	newModel->getPackagedElement()->append(newModel_CheckIfPrime);
	//Node
	newModel_CheckIfPrimeMerge = uml::UmlFactory::eInstance()->createMergeNode();
	newModel_CheckIfPrimeMerge->setName("Merge");
	newModel_CheckIfPrimeMerge->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimenext_call = uml::UmlFactory::eInstance()->createCallOperationAction();
	newModel_CheckIfPrimenext_call->setName("next_call");
	newModel_CheckIfPrimenext_call->setActivity(newModel_CheckIfPrime);
	//CallOperationAction next_call
	next_calltarget = uml::UmlFactory::eInstance()->createInputPin();
	next_calltarget->setName("target");
	
	
	newModel_PrimeChecker_next_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_next_->setName("next");
	
	
	newModel_CheckIfPrimecoaDivides = uml::UmlFactory::eInstance()->createCallOperationAction();
	newModel_CheckIfPrimecoaDivides->setName("coaDivides");
	newModel_CheckIfPrimecoaDivides->setActivity(newModel_CheckIfPrime);
	//CallOperationAction coaDivides
	coaDividestarget = uml::UmlFactory::eInstance()->createInputPin();
	coaDividestarget->setName("target");
	
	coaDividesisDivisible = uml::UmlFactory::eInstance()->createOutputPin();
	coaDividesisDivisible->setName("isDivisible");
	
	newModel_PrimeChecker_divides_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_divides_->setName("divides");
	
	
	newModel_CheckIfPrimeprimeChecker = uml::UmlFactory::eInstance()->createActivityParameterNode();
	newModel_CheckIfPrimeprimeChecker->setName("primeChecker");
	newModel_CheckIfPrimeprimeChecker->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimecbaPrintIsPrime = uml::UmlFactory::eInstance()->createCallBehaviorAction();
	newModel_CheckIfPrimecbaPrintIsPrime->setName("cbaPrintIsPrime");
	newModel_CheckIfPrimecbaPrintIsPrime->setActivity(newModel_CheckIfPrime);
	//CallBehaviorAction cbaPrintIsPrime
	newModel_CheckIfPrimecbaPrintIsPrime->setBehavior(newModel_PrimeChecker_printIsPrime);
	newModel_CheckIfPrimecbaPrintIsPrime->setIsSynchronous(true); //imposed by the fUML specification
	
	newModel_CheckIfPrimeFork1 = uml::UmlFactory::eInstance()->createForkNode();
	newModel_CheckIfPrimeFork1->setName("Fork1");
	newModel_CheckIfPrimeFork1->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimeisNotFinished = uml::UmlFactory::eInstance()->createDecisionNode();
	newModel_CheckIfPrimeisNotFinished->setName("isNotFinished");
	newModel_CheckIfPrimeisNotFinished->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimeIsOdd = uml::UmlFactory::eInstance()->createDecisionNode();
	newModel_CheckIfPrimeIsOdd->setName("IsOdd");
	newModel_CheckIfPrimeIsOdd->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimecbaPrintNotPrime2 = uml::UmlFactory::eInstance()->createCallBehaviorAction();
	newModel_CheckIfPrimecbaPrintNotPrime2->setName("cbaPrintNotPrime2");
	newModel_CheckIfPrimecbaPrintNotPrime2->setActivity(newModel_CheckIfPrime);
	//CallBehaviorAction cbaPrintNotPrime2
	newModel_CheckIfPrimecbaPrintNotPrime2->setBehavior(newModel_PrimeChecker_PrintNotPrime);
	newModel_CheckIfPrimecbaPrintNotPrime2->setIsSynchronous(true); //imposed by the fUML specification
	
	newModel_CheckIfPrimecbaPrintNotPrime = uml::UmlFactory::eInstance()->createCallBehaviorAction();
	newModel_CheckIfPrimecbaPrintNotPrime->setName("cbaPrintNotPrime");
	newModel_CheckIfPrimecbaPrintNotPrime->setActivity(newModel_CheckIfPrime);
	//CallBehaviorAction cbaPrintNotPrime
	newModel_CheckIfPrimecbaPrintNotPrime->setBehavior(newModel_PrimeChecker_PrintNotPrime);
	newModel_CheckIfPrimecbaPrintNotPrime->setIsSynchronous(true); //imposed by the fUML specification
	
	newModel_CheckIfPrimeActivityFinal3 = uml::UmlFactory::eInstance()->createActivityFinalNode();
	newModel_CheckIfPrimeActivityFinal3->setName("ActivityFinal3");
	newModel_CheckIfPrimeActivityFinal3->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimecoaIsNotFinished = uml::UmlFactory::eInstance()->createCallOperationAction();
	newModel_CheckIfPrimecoaIsNotFinished->setName("coaIsNotFinished");
	newModel_CheckIfPrimecoaIsNotFinished->setActivity(newModel_CheckIfPrime);
	//CallOperationAction coaIsNotFinished
	coaIsNotFinishedtarget = uml::UmlFactory::eInstance()->createInputPin();
	coaIsNotFinishedtarget->setName("target");
	
	coaIsNotFinishedisNotFinished = uml::UmlFactory::eInstance()->createOutputPin();
	coaIsNotFinishedisNotFinished->setName("isNotFinished");
	
	newModel_PrimeChecker_isNotFinished_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_isNotFinished_->setName("isNotFinished");
	
	
	newModel_CheckIfPrimedivides = uml::UmlFactory::eInstance()->createDecisionNode();
	newModel_CheckIfPrimedivides->setName("divides");
	newModel_CheckIfPrimedivides->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimecoaIsOdd = uml::UmlFactory::eInstance()->createCallOperationAction();
	newModel_CheckIfPrimecoaIsOdd->setName("coaIsOdd");
	newModel_CheckIfPrimecoaIsOdd->setActivity(newModel_CheckIfPrime);
	//CallOperationAction coaIsOdd
	coaIsOddtarget = uml::UmlFactory::eInstance()->createInputPin();
	coaIsOddtarget->setName("target");
	
	coaIsOddisOdd = uml::UmlFactory::eInstance()->createOutputPin();
	coaIsOddisOdd->setName("isOdd");
	
	newModel_PrimeChecker_isOdd_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_isOdd_->setName("isOdd");
	
	
	newModel_CheckIfPrimeActivityFinal1 = uml::UmlFactory::eInstance()->createActivityFinalNode();
	newModel_CheckIfPrimeActivityFinal1->setName("ActivityFinal1");
	newModel_CheckIfPrimeActivityFinal1->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimeActivityFinal2 = uml::UmlFactory::eInstance()->createActivityFinalNode();
	newModel_CheckIfPrimeActivityFinal2->setName("ActivityFinal2");
	newModel_CheckIfPrimeActivityFinal2->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrimecoaNext = uml::UmlFactory::eInstance()->createCallOperationAction();
	newModel_CheckIfPrimecoaNext->setName("coaNext");
	newModel_CheckIfPrimecoaNext->setActivity(newModel_CheckIfPrime);
	//CallOperationAction coaNext
	coaNexttarget = uml::UmlFactory::eInstance()->createInputPin();
	coaNexttarget->setName("target");
	
	
	newModel_PrimeChecker_next_ = uml::UmlFactory::eInstance()->createOperation();
	newModel_PrimeChecker_next_->setName("next");
	
	
	
	//flow
	oF_NewModel_CheckIfPrimeFork1_next_calltarget = uml::UmlFactory::eInstance()->createObjectFlow();
	oF_NewModel_CheckIfPrimeFork1_next_calltarget->setName("");
	oF_NewModel_CheckIfPrimeFork1_next_calltarget->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(oF_NewModel_CheckIfPrimeFork1_next_calltarget);
	oF_NewModel_CheckIfPrimeFork1_coaIsOddtarget = uml::UmlFactory::eInstance()->createObjectFlow();
	oF_NewModel_CheckIfPrimeFork1_coaIsOddtarget->setName("");
	oF_NewModel_CheckIfPrimeFork1_coaIsOddtarget->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(oF_NewModel_CheckIfPrimeFork1_coaIsOddtarget);
	oF_NewModel_CheckIfPrimeFork1_coaNexttarget = uml::UmlFactory::eInstance()->createObjectFlow();
	oF_NewModel_CheckIfPrimeFork1_coaNexttarget->setName("");
	oF_NewModel_CheckIfPrimeFork1_coaNexttarget->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(oF_NewModel_CheckIfPrimeFork1_coaNexttarget);
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2 = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2->setName("");
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2);
	oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1 = uml::UmlFactory::eInstance()->createObjectFlow();
	oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1->setName("");
	oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1);
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides->setName("");
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides);
	newModel_CheckIfPrimeifIsNotFinished = uml::UmlFactory::eInstance()->createObjectFlow();
	newModel_CheckIfPrimeifIsNotFinished->setName("ifIsNotFinished");
	newModel_CheckIfPrimeifIsNotFinished->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(newModel_CheckIfPrimeifIsNotFinished);
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call->setName("");
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call);
	newModel_CheckIfPrimeifIsOdd = uml::UmlFactory::eInstance()->createObjectFlow();
	newModel_CheckIfPrimeifIsOdd->setName("ifIsOdd");
	newModel_CheckIfPrimeifIsOdd->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(newModel_CheckIfPrimeifIsOdd);
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2 = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2->setName("");
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2);
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3 = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3->setName("");
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3);
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime->setName("");
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime);
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished->setName("");
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished);
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1 = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1->setName("");
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1);
	newModel_CheckIfPrimeifDivides = uml::UmlFactory::eInstance()->createObjectFlow();
	newModel_CheckIfPrimeifDivides->setName("ifDivides");
	newModel_CheckIfPrimeifDivides->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(newModel_CheckIfPrimeifDivides);
	oF_NewModel_CheckIfPrimeFork1_coaDividestarget = uml::UmlFactory::eInstance()->createObjectFlow();
	oF_NewModel_CheckIfPrimeFork1_coaDividestarget->setName("");
	oF_NewModel_CheckIfPrimeFork1_coaDividestarget->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(oF_NewModel_CheckIfPrimeFork1_coaDividestarget);
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge->setName("");
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge);
	oF_NewModel_CheckIfPrimeFork1_coaIsNotFinishedtarget = uml::UmlFactory::eInstance()->createObjectFlow();
	oF_NewModel_CheckIfPrimeFork1_coaIsNotFinishedtarget->setName("");
	oF_NewModel_CheckIfPrimeFork1_coaIsNotFinishedtarget->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(oF_NewModel_CheckIfPrimeFork1_coaIsNotFinishedtarget);
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge->setName("");
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge);
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime = uml::UmlFactory::eInstance()->createControlFlow();
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime->setName("");
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime->setActivity(newModel_CheckIfPrime);
	newModel_CheckIfPrime->getEdge()->append(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime);
	



cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime_weight_LiteralInteger =  uml::UmlFactory::eInstance()->createLiteralInteger();
cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime_weight_LiteralInteger->setValue(0);

cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1_weight_LiteralInteger =  uml::UmlFactory::eInstance()->createLiteralInteger();
cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1_weight_LiteralInteger->setValue(0);

cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call_guard_LiteralBoolean =  uml::UmlFactory::eInstance()->createLiteralBoolean();
cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call_guard_LiteralBoolean->setValue(false);

cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge_guard_LiteralBoolean =  uml::UmlFactory::eInstance()->createLiteralBoolean();
cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge_guard_LiteralBoolean->setValue(true);

newModel_PrimeChecker_number_defaultValue_LiteralInteger =  uml::UmlFactory::eInstance()->createLiteralInteger();
newModel_PrimeChecker_number_defaultValue_LiteralInteger->setValue(9949);

newModel_PrimeChecker_divides_isDivisible_defaultValue_LiteralString =  uml::UmlFactory::eInstance()->createLiteralString();
newModel_PrimeChecker_divides_isDivisible_defaultValue_LiteralString->setValue("");

newModel_PrimeChecker_divides_isDivisible_defaultValue_LiteralString =  uml::UmlFactory::eInstance()->createLiteralString();
newModel_PrimeChecker_divides_isDivisible_defaultValue_LiteralString->setValue("");

cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call_weight_LiteralInteger =  uml::UmlFactory::eInstance()->createLiteralInteger();
cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call_weight_LiteralInteger->setValue(0);

cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge_guard_LiteralBoolean =  uml::UmlFactory::eInstance()->createLiteralBoolean();
cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge_guard_LiteralBoolean->setValue(true);

cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime_weight_LiteralInteger =  uml::UmlFactory::eInstance()->createLiteralInteger();
cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime_weight_LiteralInteger->setValue(0);

newModel_CheckIfPrimeprimeChecker_upperBound_LiteralInteger =  uml::UmlFactory::eInstance()->createLiteralInteger();
newModel_CheckIfPrimeprimeChecker_upperBound_LiteralInteger->setValue(1);

newModel_PrimeChecker_divider_defaultValue_LiteralInteger =  uml::UmlFactory::eInstance()->createLiteralInteger();
newModel_PrimeChecker_divider_defaultValue_LiteralInteger->setValue(3);

cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides_guard_LiteralBoolean =  uml::UmlFactory::eInstance()->createLiteralBoolean();
cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides_guard_LiteralBoolean->setValue(true);

cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime_guard_LiteralBoolean =  uml::UmlFactory::eInstance()->createLiteralBoolean();
cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime_guard_LiteralBoolean->setValue(true);

cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2_guard_LiteralBoolean =  uml::UmlFactory::eInstance()->createLiteralBoolean();
cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2_guard_LiteralBoolean->setValue(false);

cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished_weight_LiteralInteger =  uml::UmlFactory::eInstance()->createLiteralInteger();
cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished_weight_LiteralInteger->setValue(0);

cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished_guard_LiteralBoolean =  uml::UmlFactory::eInstance()->createLiteralBoolean();
cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished_guard_LiteralBoolean->setValue(true);

cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides_weight_LiteralInteger =  uml::UmlFactory::eInstance()->createLiteralInteger();
cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides_weight_LiteralInteger->setValue(0);

cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime_guard_LiteralBoolean =  uml::UmlFactory::eInstance()->createLiteralBoolean();
cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime_guard_LiteralBoolean->setValue(false);

cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1_guard_LiteralBoolean =  uml::UmlFactory::eInstance()->createLiteralBoolean();
cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1_guard_LiteralBoolean->setValue(true);

cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3_weight_LiteralInteger =  uml::UmlFactory::eInstance()->createLiteralInteger();
cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3_weight_LiteralInteger->setValue(0);

newModel_PrimeChecker_isOdd_isOdd_defaultValue_LiteralString =  uml::UmlFactory::eInstance()->createLiteralString();
newModel_PrimeChecker_isOdd_isOdd_defaultValue_LiteralString->setValue("");

newModel_PrimeChecker_isOdd_isOdd_defaultValue_LiteralString =  uml::UmlFactory::eInstance()->createLiteralString();
newModel_PrimeChecker_isOdd_isOdd_defaultValue_LiteralString->setValue("");

cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2_guard_LiteralBoolean =  uml::UmlFactory::eInstance()->createLiteralBoolean();
cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2_guard_LiteralBoolean->setValue(true);

cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3_guard_LiteralBoolean =  uml::UmlFactory::eInstance()->createLiteralBoolean();
cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3_guard_LiteralBoolean->setValue(true);

cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2_weight_LiteralInteger =  uml::UmlFactory::eInstance()->createLiteralInteger();
cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2_weight_LiteralInteger->setValue(0);





uml::EnumerationLiteral * lit = nullptr;


}





void NewModelPackageImpl::initializePackageContents()
{

	if (isInitialized) return;
		isInitialized = true;

	 // Initialize package

	setName(eNAME);
	setURI(eNS_URI);

	



	// Add supertypes to classes

	uml::Generalization * gen = nullptr;
	
	
	
 
	newModel_PrimeChecker_isNotFinished_->getMethod()->append(newModel_PrimeChecker_isNotFinished);
	newModel_PrimeChecker_isOdd_->getMethod()->append(newModel_PrimeChecker_isOdd);
	newModel_PrimeChecker_printNotPrime_->getMethod()->append(newModel_PrimeChecker_PrintNotPrime);
	newModel_PrimeChecker_printIsPrime_->getMethod()->append(newModel_PrimeChecker_printIsPrime);
	newModel_PrimeChecker_divides_->getMethod()->append(newModel_PrimeChecker_divides);
	newModel_PrimeChecker_next_->getMethod()->append(newModel_PrimeChecker_next);
	
	
	//initalize ActivityNodes and Edges
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimeIsOdd);
	
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimecoaIsNotFinished);
	newModel_CheckIfPrimecoaIsNotFinished->setOperation(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_isNotFinished_());
	newModel_CheckIfPrimecoaIsNotFinished->getArgument()->append(coaIsNotFinishedtarget);
	
	newModel_CheckIfPrimecoaIsNotFinished->getResult()->append(coaIsNotFinishedisNotFinished);
	
	newModel_CheckIfPrimecoaIsNotFinished->setTarget(NewModel::NewModelPackage::eInstance()->get_coaIsNotFinishedtarget());
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimeFork1);
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimenext_call);
	newModel_CheckIfPrimenext_call->setOperation(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_next_());
	newModel_CheckIfPrimenext_call->getArgument()->append(next_calltarget);
	
	
	newModel_CheckIfPrimenext_call->setTarget(NewModel::NewModelPackage::eInstance()->get_next_calltarget());
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimeisNotFinished);
	
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimedivides);
	
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimeActivityFinal2);
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimecoaDivides);
	newModel_CheckIfPrimecoaDivides->setOperation(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_divides_());
	newModel_CheckIfPrimecoaDivides->getArgument()->append(coaDividestarget);
	
	newModel_CheckIfPrimecoaDivides->getResult()->append(coaDividesisDivisible);
	
	newModel_CheckIfPrimecoaDivides->setTarget(NewModel::NewModelPackage::eInstance()->get_coaDividestarget());
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimeActivityFinal1);
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimecoaNext);
	newModel_CheckIfPrimecoaNext->setOperation(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_next_());
	newModel_CheckIfPrimecoaNext->getArgument()->append(coaNexttarget);
	
	
	newModel_CheckIfPrimecoaNext->setTarget(NewModel::NewModelPackage::eInstance()->get_coaNexttarget());
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimeActivityFinal3);
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimecbaPrintIsPrime);
	newModel_CheckIfPrimecbaPrintIsPrime->setBehavior(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_printIsPrime());
	
	
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimeMerge);
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimeprimeChecker);
	newModel_CheckIfPrimeprimeChecker->setParameter(newModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode);
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimecbaPrintNotPrime);
	newModel_CheckIfPrimecbaPrintNotPrime->setBehavior(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_PrintNotPrime());
	
	
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimecbaPrintNotPrime2);
	newModel_CheckIfPrimecbaPrintNotPrime2->setBehavior(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_PrintNotPrime());
	
	
	
	newModel_CheckIfPrime->getNode()->append(newModel_CheckIfPrimecoaIsOdd);
	newModel_CheckIfPrimecoaIsOdd->setOperation(NewModel::NewModelPackage::eInstance()->get_NewModel_PrimeChecker_isOdd_());
	newModel_CheckIfPrimecoaIsOdd->getArgument()->append(coaIsOddtarget);
	
	newModel_CheckIfPrimecoaIsOdd->getResult()->append(coaIsOddisOdd);
	
	newModel_CheckIfPrimecoaIsOdd->setTarget(NewModel::NewModelPackage::eInstance()->get_coaIsOddtarget());
	
	
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished->setSource(newModel_CheckIfPrimenext_call);
	newModel_CheckIfPrimenext_call->getOutgoing()->append(cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished);
	
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished->setTarget(newModel_CheckIfPrimecoaIsNotFinished);
	newModel_CheckIfPrimecoaIsNotFinished->getIncoming()->append(cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished);
	
	cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished->setGuard(cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished_guard_LiteralBoolean);
	
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge->setSource(newModel_CheckIfPrimeIsOdd);
	newModel_CheckIfPrimeIsOdd->getOutgoing()->append(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge);
	
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge->setTarget(newModel_CheckIfPrimeMerge);
	newModel_CheckIfPrimeMerge->getIncoming()->append(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge);
	
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge->setGuard(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge_guard_LiteralBoolean);
	
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2->setSource(newModel_CheckIfPrimeIsOdd);
	newModel_CheckIfPrimeIsOdd->getOutgoing()->append(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2);
	
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2->setTarget(newModel_CheckIfPrimecbaPrintNotPrime2);
	newModel_CheckIfPrimecbaPrintNotPrime2->getIncoming()->append(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2);
	
	cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2->setGuard(cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2_guard_LiteralBoolean);
	
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge->setSource(newModel_CheckIfPrimeisNotFinished);
	newModel_CheckIfPrimeisNotFinished->getOutgoing()->append(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge);
	
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge->setTarget(newModel_CheckIfPrimeMerge);
	newModel_CheckIfPrimeMerge->getIncoming()->append(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge);
	
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge->setGuard(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge_guard_LiteralBoolean);
	
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2->setSource(newModel_CheckIfPrimecbaPrintNotPrime);
	newModel_CheckIfPrimecbaPrintNotPrime->getOutgoing()->append(cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2);
	
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2->setTarget(newModel_CheckIfPrimeActivityFinal2);
	newModel_CheckIfPrimeActivityFinal2->getIncoming()->append(cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2);
	
	cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2->setGuard(cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2_guard_LiteralBoolean);
	
	newModel_CheckIfPrimeifIsOdd->setSource(coaIsOddisOdd);
	coaIsOddisOdd->getOutgoing()->append(newModel_CheckIfPrimeifIsOdd);
	
	newModel_CheckIfPrimeifIsOdd->setTarget(newModel_CheckIfPrimeIsOdd);
	newModel_CheckIfPrimeIsOdd->getIncoming()->append(newModel_CheckIfPrimeifIsOdd);
	
	
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call->setSource(newModel_CheckIfPrimedivides);
	newModel_CheckIfPrimedivides->getOutgoing()->append(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call);
	
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call->setTarget(newModel_CheckIfPrimenext_call);
	newModel_CheckIfPrimenext_call->getIncoming()->append(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call);
	
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call->setGuard(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call_guard_LiteralBoolean);
	
	oF_NewModel_CheckIfPrimeFork1_coaDividestarget->setSource(newModel_CheckIfPrimeFork1);
	newModel_CheckIfPrimeFork1->getOutgoing()->append(oF_NewModel_CheckIfPrimeFork1_coaDividestarget);
	
	oF_NewModel_CheckIfPrimeFork1_coaDividestarget->setTarget(coaDividestarget);
	coaDividestarget->getIncoming()->append(oF_NewModel_CheckIfPrimeFork1_coaDividestarget);
	
	
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides->setSource(newModel_CheckIfPrimeMerge);
	newModel_CheckIfPrimeMerge->getOutgoing()->append(cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides);
	
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides->setTarget(newModel_CheckIfPrimecoaDivides);
	newModel_CheckIfPrimecoaDivides->getIncoming()->append(cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides);
	
	cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides->setGuard(cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides_guard_LiteralBoolean);
	
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1->setSource(newModel_CheckIfPrimecbaPrintNotPrime2);
	newModel_CheckIfPrimecbaPrintNotPrime2->getOutgoing()->append(cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1);
	
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1->setTarget(newModel_CheckIfPrimeActivityFinal1);
	newModel_CheckIfPrimeActivityFinal1->getIncoming()->append(cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1);
	
	cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1->setGuard(cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1_guard_LiteralBoolean);
	
	oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1->setSource(newModel_CheckIfPrimeprimeChecker);
	newModel_CheckIfPrimeprimeChecker->getOutgoing()->append(oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1);
	
	oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1->setTarget(newModel_CheckIfPrimeFork1);
	newModel_CheckIfPrimeFork1->getIncoming()->append(oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1);
	
	
	newModel_CheckIfPrimeifDivides->setSource(coaDividesisDivisible);
	coaDividesisDivisible->getOutgoing()->append(newModel_CheckIfPrimeifDivides);
	
	newModel_CheckIfPrimeifDivides->setTarget(newModel_CheckIfPrimedivides);
	newModel_CheckIfPrimedivides->getIncoming()->append(newModel_CheckIfPrimeifDivides);
	
	
	oF_NewModel_CheckIfPrimeFork1_coaIsNotFinishedtarget->setSource(newModel_CheckIfPrimeFork1);
	newModel_CheckIfPrimeFork1->getOutgoing()->append(oF_NewModel_CheckIfPrimeFork1_coaIsNotFinishedtarget);
	
	oF_NewModel_CheckIfPrimeFork1_coaIsNotFinishedtarget->setTarget(coaIsNotFinishedtarget);
	coaIsNotFinishedtarget->getIncoming()->append(oF_NewModel_CheckIfPrimeFork1_coaIsNotFinishedtarget);
	
	
	oF_NewModel_CheckIfPrimeFork1_coaIsOddtarget->setSource(newModel_CheckIfPrimeFork1);
	newModel_CheckIfPrimeFork1->getOutgoing()->append(oF_NewModel_CheckIfPrimeFork1_coaIsOddtarget);
	
	oF_NewModel_CheckIfPrimeFork1_coaIsOddtarget->setTarget(coaIsOddtarget);
	coaIsOddtarget->getIncoming()->append(oF_NewModel_CheckIfPrimeFork1_coaIsOddtarget);
	
	
	oF_NewModel_CheckIfPrimeFork1_coaNexttarget->setSource(newModel_CheckIfPrimeFork1);
	newModel_CheckIfPrimeFork1->getOutgoing()->append(oF_NewModel_CheckIfPrimeFork1_coaNexttarget);
	
	oF_NewModel_CheckIfPrimeFork1_coaNexttarget->setTarget(coaNexttarget);
	coaNexttarget->getIncoming()->append(oF_NewModel_CheckIfPrimeFork1_coaNexttarget);
	
	
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime->setSource(newModel_CheckIfPrimeisNotFinished);
	newModel_CheckIfPrimeisNotFinished->getOutgoing()->append(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime);
	
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime->setTarget(newModel_CheckIfPrimecbaPrintIsPrime);
	newModel_CheckIfPrimecbaPrintIsPrime->getIncoming()->append(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime);
	
	cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime->setGuard(cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime_guard_LiteralBoolean);
	
	newModel_CheckIfPrimeifIsNotFinished->setSource(coaIsNotFinishedisNotFinished);
	coaIsNotFinishedisNotFinished->getOutgoing()->append(newModel_CheckIfPrimeifIsNotFinished);
	
	newModel_CheckIfPrimeifIsNotFinished->setTarget(newModel_CheckIfPrimeisNotFinished);
	newModel_CheckIfPrimeisNotFinished->getIncoming()->append(newModel_CheckIfPrimeifIsNotFinished);
	
	
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime->setSource(newModel_CheckIfPrimedivides);
	newModel_CheckIfPrimedivides->getOutgoing()->append(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime);
	
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime->setTarget(newModel_CheckIfPrimecbaPrintNotPrime);
	newModel_CheckIfPrimecbaPrintNotPrime->getIncoming()->append(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime);
	
	cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime->setGuard(cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime_guard_LiteralBoolean);
	
	oF_NewModel_CheckIfPrimeFork1_next_calltarget->setSource(newModel_CheckIfPrimeFork1);
	newModel_CheckIfPrimeFork1->getOutgoing()->append(oF_NewModel_CheckIfPrimeFork1_next_calltarget);
	
	oF_NewModel_CheckIfPrimeFork1_next_calltarget->setTarget(next_calltarget);
	next_calltarget->getIncoming()->append(oF_NewModel_CheckIfPrimeFork1_next_calltarget);
	
	
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3->setSource(newModel_CheckIfPrimecbaPrintIsPrime);
	newModel_CheckIfPrimecbaPrintIsPrime->getOutgoing()->append(cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3);
	
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3->setTarget(newModel_CheckIfPrimeActivityFinal3);
	newModel_CheckIfPrimeActivityFinal3->getIncoming()->append(cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3);
	
	cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3->setGuard(cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3_guard_LiteralBoolean);
	
	

}


uml::ActivityFinalNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeActivityFinal2()
{
	return newModel_CheckIfPrimeActivityFinal2;
}
uml::CallOperationAction* NewModelPackageImpl::get_NewModel_CheckIfPrimecoaNext()
{
	return newModel_CheckIfPrimecoaNext;
}
uml::FunctionBehavior* NewModelPackageImpl::get_NewModel_PrimeChecker_isOdd()
{
	return newModel_PrimeChecker_isOdd;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime()
{
	return cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimecbaPrintNotPrime;
}
uml::Parameter* NewModelPackageImpl::get_NewModel_PrimeChecker_isOdd_isOdd()
{
	return newModel_PrimeChecker_isOdd_isOdd;
}
uml::Operation* NewModelPackageImpl::get_NewModel_PrimeChecker_printNotPrime_()
{
	return newModel_PrimeChecker_printNotPrime_;
}
uml::Property* NewModelPackageImpl::get_NewModel_PrimeChecker_divider()
{
	return newModel_PrimeChecker_divider;
}
uml::InputPin* NewModelPackageImpl::get_coaNexttarget()
{
	return coaNexttarget;
}
uml::Parameter* NewModelPackageImpl::get_NewModel_PrimeChecker_isNotFinished_isNotFinished()
{
	return newModel_PrimeChecker_isNotFinished_isNotFinished;
}
uml::Operation* NewModelPackageImpl::get_NewModel_PrimeChecker_isOdd_()
{
	return newModel_PrimeChecker_isOdd_;
}
uml::Operation* NewModelPackageImpl::get_NewModel_PrimeChecker_isNotFinished_()
{
	return newModel_PrimeChecker_isNotFinished_;
}
uml::ObjectFlow* NewModelPackageImpl::get_OF_NewModel_CheckIfPrimeFork1_coaIsNotFinishedtarget()
{
	return oF_NewModel_CheckIfPrimeFork1_coaIsNotFinishedtarget;
}
uml::Operation* NewModelPackageImpl::get_NewModel_PrimeChecker_next_()
{
	return newModel_PrimeChecker_next_;
}
uml::FunctionBehavior* NewModelPackageImpl::get_NewModel_PrimeChecker_divides()
{
	return newModel_PrimeChecker_divides;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call()
{
	return cF_NewModel_CheckIfPrimedivides_NewModel_CheckIfPrimenext_call;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime()
{
	return cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimecbaPrintIsPrime;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished()
{
	return cF_NewModel_CheckIfPrimenext_call_NewModel_CheckIfPrimecoaIsNotFinished;
}
uml::CallOperationAction* NewModelPackageImpl::get_NewModel_CheckIfPrimenext_call()
{
	return newModel_CheckIfPrimenext_call;
}
uml::FunctionBehavior* NewModelPackageImpl::get_NewModel_PrimeChecker_PrintNotPrime()
{
	return newModel_PrimeChecker_PrintNotPrime;
}
uml::ObjectFlow* NewModelPackageImpl::get_OF_NewModel_CheckIfPrimeFork1_next_calltarget()
{
	return oF_NewModel_CheckIfPrimeFork1_next_calltarget;
}
uml::Parameter* NewModelPackageImpl::get_NewModel_PrimeChecker_divides_isDivisible()
{
	return newModel_PrimeChecker_divides_isDivisible;
}
uml::Activity* NewModelPackageImpl::get_NewModel_CheckIfPrime()
{
	return newModel_CheckIfPrime;
}
uml::OutputPin* NewModelPackageImpl::get_coaIsOddisOdd()
{
	return coaIsOddisOdd;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2()
{
	return cF_NewModel_CheckIfPrimecbaPrintNotPrime_NewModel_CheckIfPrimeActivityFinal2;
}
uml::ObjectFlow* NewModelPackageImpl::get_OF_NewModel_CheckIfPrimeFork1_coaNexttarget()
{
	return oF_NewModel_CheckIfPrimeFork1_coaNexttarget;
}
uml::ObjectFlow* NewModelPackageImpl::get_NewModel_CheckIfPrimeifIsNotFinished()
{
	return newModel_CheckIfPrimeifIsNotFinished;
}
uml::Operation* NewModelPackageImpl::get_NewModel_PrimeChecker_printIsPrime_()
{
	return newModel_PrimeChecker_printIsPrime_;
}
uml::ActivityFinalNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeActivityFinal1()
{
	return newModel_CheckIfPrimeActivityFinal1;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1()
{
	return cF_NewModel_CheckIfPrimecbaPrintNotPrime2_NewModel_CheckIfPrimeActivityFinal1;
}
uml::InputPin* NewModelPackageImpl::get_coaIsOddtarget()
{
	return coaIsOddtarget;
}
uml::ObjectFlow* NewModelPackageImpl::get_OF_NewModel_CheckIfPrimeFork1_coaDividestarget()
{
	return oF_NewModel_CheckIfPrimeFork1_coaDividestarget;
}
uml::ObjectFlow* NewModelPackageImpl::get_NewModel_CheckIfPrimeifDivides()
{
	return newModel_CheckIfPrimeifDivides;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3()
{
	return cF_NewModel_CheckIfPrimecbaPrintIsPrime_NewModel_CheckIfPrimeActivityFinal3;
}
uml::MergeNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeMerge()
{
	return newModel_CheckIfPrimeMerge;
}
uml::FunctionBehavior* NewModelPackageImpl::get_NewModel_PrimeChecker_next()
{
	return newModel_PrimeChecker_next;
}
uml::OutputPin* NewModelPackageImpl::get_coaDividesisDivisible()
{
	return coaDividesisDivisible;
}
uml::ActivityFinalNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeActivityFinal3()
{
	return newModel_CheckIfPrimeActivityFinal3;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2()
{
	return cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimecbaPrintNotPrime2;
}
uml::InputPin* NewModelPackageImpl::get_next_calltarget()
{
	return next_calltarget;
}
uml::OutputPin* NewModelPackageImpl::get_coaIsNotFinishedisNotFinished()
{
	return coaIsNotFinishedisNotFinished;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides()
{
	return cF_NewModel_CheckIfPrimeMerge_NewModel_CheckIfPrimecoaDivides;
}
uml::CallBehaviorAction* NewModelPackageImpl::get_NewModel_CheckIfPrimecbaPrintIsPrime()
{
	return newModel_CheckIfPrimecbaPrintIsPrime;
}
uml::InputPin* NewModelPackageImpl::get_coaDividestarget()
{
	return coaDividestarget;
}
uml::CallOperationAction* NewModelPackageImpl::get_NewModel_CheckIfPrimecoaDivides()
{
	return newModel_CheckIfPrimecoaDivides;
}
uml::Parameter* NewModelPackageImpl::get_NewModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode()
{
	return newModel_CheckIfPrime_NewModel_CheckIfPrime_ActInputNode;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge()
{
	return cF_NewModel_CheckIfPrimeIsOdd_NewModel_CheckIfPrimeMerge;
}
uml::ObjectFlow* NewModelPackageImpl::get_NewModel_CheckIfPrimeifIsOdd()
{
	return newModel_CheckIfPrimeifIsOdd;
}
uml::ActivityParameterNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeprimeChecker()
{
	return newModel_CheckIfPrimeprimeChecker;
}
uml::CallBehaviorAction* NewModelPackageImpl::get_NewModel_CheckIfPrimecbaPrintNotPrime()
{
	return newModel_CheckIfPrimecbaPrintNotPrime;
}
uml::ObjectFlow* NewModelPackageImpl::get_OF_NewModel_CheckIfPrimeFork1_coaIsOddtarget()
{
	return oF_NewModel_CheckIfPrimeFork1_coaIsOddtarget;
}
uml::Class* NewModelPackageImpl::get_NewModel_PrimeChecker()
{
	return newModel_PrimeChecker;
}
uml::ControlFlow* NewModelPackageImpl::get_CF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge()
{
	return cF_NewModel_CheckIfPrimeisNotFinished_NewModel_CheckIfPrimeMerge;
}
uml::Operation* NewModelPackageImpl::get_NewModel_PrimeChecker_divides_()
{
	return newModel_PrimeChecker_divides_;
}
uml::ObjectFlow* NewModelPackageImpl::get_OF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1()
{
	return oF_NewModel_CheckIfPrimeprimeChecker_NewModel_CheckIfPrimeFork1;
}
uml::FunctionBehavior* NewModelPackageImpl::get_NewModel_PrimeChecker_printIsPrime()
{
	return newModel_PrimeChecker_printIsPrime;
}
uml::Property* NewModelPackageImpl::get_NewModel_PrimeChecker_number()
{
	return newModel_PrimeChecker_number;
}
uml::FunctionBehavior* NewModelPackageImpl::get_NewModel_PrimeChecker_isNotFinished()
{
	return newModel_PrimeChecker_isNotFinished;
}
uml::DecisionNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeIsOdd()
{
	return newModel_CheckIfPrimeIsOdd;
}
uml::ForkNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeFork1()
{
	return newModel_CheckIfPrimeFork1;
}
uml::CallOperationAction* NewModelPackageImpl::get_NewModel_CheckIfPrimecoaIsOdd()
{
	return newModel_CheckIfPrimecoaIsOdd;
}
uml::CallBehaviorAction* NewModelPackageImpl::get_NewModel_CheckIfPrimecbaPrintNotPrime2()
{
	return newModel_CheckIfPrimecbaPrintNotPrime2;
}
uml::DecisionNode* NewModelPackageImpl::get_NewModel_CheckIfPrimeisNotFinished()
{
	return newModel_CheckIfPrimeisNotFinished;
}
uml::DecisionNode* NewModelPackageImpl::get_NewModel_CheckIfPrimedivides()
{
	return newModel_CheckIfPrimedivides;
}
uml::CallOperationAction* NewModelPackageImpl::get_NewModel_CheckIfPrimecoaIsNotFinished()
{
	return newModel_CheckIfPrimecoaIsNotFinished;
}
uml::InputPin* NewModelPackageImpl::get_coaIsNotFinishedtarget()
{
	return coaIsNotFinishedtarget;
}



