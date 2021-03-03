#include "umlReflectionExec/CallBehaviorActionObject.hpp"

//General Includes
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/CallBehaviorAction.hpp"
#include "umlReflection/UMLPackage.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/Class.hpp"
//Includes From Composite Structures
/*Not done for metamodel object classes*/
//Execution Engine Includes
#include "abstractDataTypes/Any.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Link.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_InteractionPoint.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/ChoiceStrategy.hpp"
//UML Includes
#include "uml/umlPackage.hpp"
#include "uml/Association.hpp"
#include "uml/Connector.hpp"
#include "uml/ConnectorEnd.hpp"
#include "uml/Operation.hpp"
#include "uml/Property.hpp"
#include "uml/Port.hpp"
//Property Includes
#include "uml/Classifier.hpp"
#include "umlReflectionExec/ClassifierObject.hpp"
#include "uml/InputPin.hpp"
#include "umlReflectionExec/InputPinObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/Constraint.hpp"
#include "umlReflectionExec/ConstraintObject.hpp"
#include "uml/Constraint.hpp"
#include "umlReflectionExec/ConstraintObject.hpp"
#include "uml/OutputPin.hpp"
#include "umlReflectionExec/OutputPinObject.hpp"
#include "uml/Activity.hpp"
#include "umlReflectionExec/ActivityObject.hpp"
#include "uml/ActivityGroup.hpp"
#include "umlReflectionExec/ActivityGroupObject.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "umlReflectionExec/InterruptibleActivityRegionObject.hpp"
#include "uml/ActivityPartition.hpp"
#include "umlReflectionExec/ActivityPartitionObject.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "umlReflectionExec/StructuredActivityNodeObject.hpp"
#include "uml/ActivityEdge.hpp"
#include "umlReflectionExec/ActivityEdgeObject.hpp"
#include "uml/ActivityEdge.hpp"
#include "umlReflectionExec/ActivityEdgeObject.hpp"
#include "uml/ActivityNode.hpp"
#include "umlReflectionExec/ActivityNodeObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/OutputPin.hpp"
#include "umlReflectionExec/OutputPinObject.hpp"
#include "uml/Behavior.hpp"
#include "umlReflectionExec/BehaviorObject.hpp"
#include "uml/Comment.hpp"
#include "umlReflectionExec/CommentObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/ExceptionHandler.hpp"
#include "umlReflectionExec/ExceptionHandlerObject.hpp"
#include "uml/InputPin.hpp"
#include "umlReflectionExec/InputPinObject.hpp"
#include "uml/Port.hpp"
#include "umlReflectionExec/PortObject.hpp"
#include "uml/Dependency.hpp"
#include "umlReflectionExec/DependencyObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/StringValue.hpp"
#include "uml/StringExpression.hpp"
#include "umlReflectionExec/StringExpressionObject.hpp"
#include "uml/Namespace.hpp"
#include "umlReflectionExec/NamespaceObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/StringValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/EnumerationValue.hpp"
#include "uml/VisibilityKind.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/RedefinableElement.hpp"
#include "umlReflectionExec/RedefinableElementObject.hpp"
#include "uml/Classifier.hpp"
#include "umlReflectionExec/ClassifierObject.hpp"
//Property Packages Includes
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"


using namespace UML;

CallBehaviorActionObject::CallBehaviorActionObject(std::shared_ptr<uml::CallBehaviorAction> _element):
	m_CallBehaviorActionValue(_element)
{
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_CallBehaviorAction());
}

CallBehaviorActionObject::CallBehaviorActionObject(CallBehaviorActionObject &obj):
	CS_ObjectImpl(obj)
{
	*this = obj;
}

CallBehaviorActionObject::CallBehaviorActionObject()
{	
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_CallBehaviorAction());
}

CallBehaviorActionObject::~CallBehaviorActionObject()
{
}

std::shared_ptr<ecore::EObject> CallBehaviorActionObject::copy()
{
	std::shared_ptr<CallBehaviorActionObject> element(new CallBehaviorActionObject());
	*element=(*this);
	element->setThisCallBehaviorActionObjectPtr(element);
	return element;
}

CallBehaviorActionObject& CallBehaviorActionObject::operator=(const CallBehaviorActionObject & obj)
{
	UML::CallActionObject::operator=(obj);
	return *this;
}


void CallBehaviorActionObject::destroy()
{	
	m_CallBehaviorActionValue.reset();

	fUML::Semantics::StructuredClassifiers::ObjectImpl::destroy();
}

std::shared_ptr<uml::Element> CallBehaviorActionObject::getUmlValue() const
{
	return getCallBehaviorActionValue();
}

std::shared_ptr<uml::CallBehaviorAction> CallBehaviorActionObject::getCallBehaviorActionValue() const
{
	return m_CallBehaviorActionValue;
}

void CallBehaviorActionObject::setUmlValue(std::shared_ptr<uml::Element> _element)
{
	setCallBehaviorActionValue(std::dynamic_pointer_cast<uml::CallBehaviorAction>(_element));
}

void CallBehaviorActionObject::setCallBehaviorActionValue(std::shared_ptr<uml::CallBehaviorAction> _CallBehaviorActionElement)
{
	m_CallBehaviorActionValue = _CallBehaviorActionElement;
	//set super type values
	UML::CallActionObject::setCallActionValue(_CallBehaviorActionElement);
}

void CallBehaviorActionObject::setThisCallBehaviorActionObjectPtr(std::weak_ptr<CallBehaviorActionObject> thisObjectPtr)
{
	setThisCS_ObjectPtr(thisObjectPtr);
}

bool CallBehaviorActionObject::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	bool isEqual = false;
	
	std::shared_ptr<CallBehaviorActionObject> otherCallBehaviorActionObject = std::dynamic_pointer_cast<CallBehaviorActionObject>(otherValue);

	if(otherCallBehaviorActionObject != nullptr)
	{
		if(this->getCallBehaviorActionValue() == otherCallBehaviorActionObject->getCallBehaviorActionValue())
		{
			isEqual = true;
		}
	}

	return isEqual;
}

std::string CallBehaviorActionObject::toString()
{
	std::string buffer = "Instance of 'CallBehaviorActionObject', " + std::to_string(getTypes()->size()) + " types (";
	for(unsigned int i = 0; i < getTypes()->size(); ++i)
	{
		buffer += "type{" + std::to_string(i) + "}: '" + getTypes()->at(i)->getName() + "', ";
	}
	buffer +=")";

	return buffer;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> CallBehaviorActionObject::getDirectContainers()
{   
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());

	/*Not done for metamodel object classes*/

	return directContainers;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> CallBehaviorActionObject::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> allLinks(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());

	/*Not done for metamodel object classes*/

	return allLinks;
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> CallBehaviorActionObject::retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end)
{
	/*Not done for metamodel object classes*/

	return nullptr;
}

void CallBehaviorActionObject::removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_CallBehaviorActionValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside CallBehaviorActionObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_isLocallyReentrant())
	{
				m_CallBehaviorActionValue->setIsLocallyReentrant(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_localPostcondition())
	{
		if (value == nullptr) // clear mode
		{
			m_CallBehaviorActionValue->getLocalPostcondition()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ConstraintObject> inputValue = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CallBehaviorActionValue->getLocalPostcondition()->erase(inputValue->getConstraintValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_localPrecondition())
	{
		if (value == nullptr) // clear mode
		{
			m_CallBehaviorActionValue->getLocalPrecondition()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ConstraintObject> inputValue = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CallBehaviorActionValue->getLocalPrecondition()->erase(inputValue->getConstraintValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_activity())
	{
				m_CallBehaviorActionValue->getActivity().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inInterruptibleRegion())
	{
		if (value == nullptr) // clear mode
		{
			m_CallBehaviorActionValue->getInInterruptibleRegion()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::InterruptibleActivityRegionObject> inputValue = std::dynamic_pointer_cast<UML::InterruptibleActivityRegionObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CallBehaviorActionValue->getInInterruptibleRegion()->erase(inputValue->getInterruptibleActivityRegionValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inPartition())
	{
		if (value == nullptr) // clear mode
		{
			m_CallBehaviorActionValue->getInPartition()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ActivityPartitionObject> inputValue = std::dynamic_pointer_cast<UML::ActivityPartitionObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CallBehaviorActionValue->getInPartition()->erase(inputValue->getActivityPartitionValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inStructuredNode())
	{
				m_CallBehaviorActionValue->getInStructuredNode().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_incoming())
	{
		if (value == nullptr) // clear mode
		{
			m_CallBehaviorActionValue->getIncoming()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ActivityEdgeObject> inputValue = std::dynamic_pointer_cast<UML::ActivityEdgeObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CallBehaviorActionValue->getIncoming()->erase(inputValue->getActivityEdgeValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_outgoing())
	{
		if (value == nullptr) // clear mode
		{
			m_CallBehaviorActionValue->getOutgoing()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ActivityEdgeObject> inputValue = std::dynamic_pointer_cast<UML::ActivityEdgeObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CallBehaviorActionValue->getOutgoing()->erase(inputValue->getActivityEdgeValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_redefinedNode())
	{
		if (value == nullptr) // clear mode
		{
			m_CallBehaviorActionValue->getRedefinedNode()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ActivityNodeObject> inputValue = std::dynamic_pointer_cast<UML::ActivityNodeObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CallBehaviorActionValue->getRedefinedNode()->erase(inputValue->getActivityNodeValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CallAction_isSynchronous())
	{
				m_CallBehaviorActionValue->setIsSynchronous(true /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CallAction_result())
	{
		if (value == nullptr) // clear mode
		{
			m_CallBehaviorActionValue->getResult()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::OutputPinObject> inputValue = std::dynamic_pointer_cast<UML::OutputPinObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CallBehaviorActionValue->getResult()->erase(inputValue->getOutputPinValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CallBehaviorAction_behavior())
	{
				m_CallBehaviorActionValue->getBehavior().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		if (value == nullptr) // clear mode
		{
			m_CallBehaviorActionValue->getOwnedComment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CommentObject> inputValue = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CallBehaviorActionValue->getOwnedComment()->erase(inputValue->getCommentValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ExecutableNode_handler())
	{
		if (value == nullptr) // clear mode
		{
			m_CallBehaviorActionValue->getHandler()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ExceptionHandlerObject> inputValue = std::dynamic_pointer_cast<UML::ExceptionHandlerObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CallBehaviorActionValue->getHandler()->erase(inputValue->getExceptionHandlerValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InvocationAction_argument())
	{
		if (value == nullptr) // clear mode
		{
			m_CallBehaviorActionValue->getArgument()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::InputPinObject> inputValue = std::dynamic_pointer_cast<UML::InputPinObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CallBehaviorActionValue->getArgument()->erase(inputValue->getInputPinValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InvocationAction_onPort())
	{
				m_CallBehaviorActionValue->getOnPort().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
				m_CallBehaviorActionValue->getNameExpression().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
				m_CallBehaviorActionValue->setIsLeaf(false /*defined default value*/);

	}
}


std::shared_ptr<Bag<fUML::Semantics::Values::Value>> CallBehaviorActionObject::getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_CallBehaviorActionValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside CallBehaviorActionObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_context())
	{
		std::shared_ptr<UML::ClassifierObject> value(new UML::ClassifierObject());
		value->setThisClassifierObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setClassifierValue(m_CallBehaviorActionValue->getContext());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_input())
	{
		std::shared_ptr<Bag<uml::InputPin>> inputList = m_CallBehaviorActionValue->getInput();
		Bag<uml::InputPin>::iterator iter = inputList->begin();
		Bag<uml::InputPin>::iterator end = inputList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::InputPinObject> value(new UML::InputPinObject());
			value->setThisInputPinObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setInputPinValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_isLocallyReentrant())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_CallBehaviorActionValue->getIsLocallyReentrant());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_localPostcondition())
	{
		std::shared_ptr<Bag<uml::Constraint>> localPostconditionList = m_CallBehaviorActionValue->getLocalPostcondition();
		Bag<uml::Constraint>::iterator iter = localPostconditionList->begin();
		Bag<uml::Constraint>::iterator end = localPostconditionList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ConstraintObject> value(new UML::ConstraintObject());
			value->setThisConstraintObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setConstraintValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_localPrecondition())
	{
		std::shared_ptr<Bag<uml::Constraint>> localPreconditionList = m_CallBehaviorActionValue->getLocalPrecondition();
		Bag<uml::Constraint>::iterator iter = localPreconditionList->begin();
		Bag<uml::Constraint>::iterator end = localPreconditionList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ConstraintObject> value(new UML::ConstraintObject());
			value->setThisConstraintObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setConstraintValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_output())
	{
		std::shared_ptr<Bag<uml::OutputPin>> outputList = m_CallBehaviorActionValue->getOutput();
		Bag<uml::OutputPin>::iterator iter = outputList->begin();
		Bag<uml::OutputPin>::iterator end = outputList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::OutputPinObject> value(new UML::OutputPinObject());
			value->setThisOutputPinObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setOutputPinValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_activity())
	{
		std::shared_ptr<UML::ActivityObject> value(new UML::ActivityObject());
		value->setThisActivityObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setActivityValue(m_CallBehaviorActionValue->getActivity().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inGroup())
	{
		std::shared_ptr<Bag<uml::ActivityGroup>> inGroupList = m_CallBehaviorActionValue->getInGroup();
		Bag<uml::ActivityGroup>::iterator iter = inGroupList->begin();
		Bag<uml::ActivityGroup>::iterator end = inGroupList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ActivityGroupObject> value(new UML::ActivityGroupObject());
			value->setThisActivityGroupObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setActivityGroupValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inInterruptibleRegion())
	{
		std::shared_ptr<Bag<uml::InterruptibleActivityRegion>> inInterruptibleRegionList = m_CallBehaviorActionValue->getInInterruptibleRegion();
		Bag<uml::InterruptibleActivityRegion>::iterator iter = inInterruptibleRegionList->begin();
		Bag<uml::InterruptibleActivityRegion>::iterator end = inInterruptibleRegionList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::InterruptibleActivityRegionObject> value(new UML::InterruptibleActivityRegionObject());
			value->setThisInterruptibleActivityRegionObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setInterruptibleActivityRegionValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inPartition())
	{
		std::shared_ptr<Bag<uml::ActivityPartition>> inPartitionList = m_CallBehaviorActionValue->getInPartition();
		Bag<uml::ActivityPartition>::iterator iter = inPartitionList->begin();
		Bag<uml::ActivityPartition>::iterator end = inPartitionList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ActivityPartitionObject> value(new UML::ActivityPartitionObject());
			value->setThisActivityPartitionObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setActivityPartitionValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inStructuredNode())
	{
		std::shared_ptr<UML::StructuredActivityNodeObject> value(new UML::StructuredActivityNodeObject());
		value->setThisStructuredActivityNodeObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setStructuredActivityNodeValue(m_CallBehaviorActionValue->getInStructuredNode().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_incoming())
	{
		std::shared_ptr<Bag<uml::ActivityEdge>> incomingList = m_CallBehaviorActionValue->getIncoming();
		Bag<uml::ActivityEdge>::iterator iter = incomingList->begin();
		Bag<uml::ActivityEdge>::iterator end = incomingList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ActivityEdgeObject> value(new UML::ActivityEdgeObject());
			value->setThisActivityEdgeObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setActivityEdgeValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_outgoing())
	{
		std::shared_ptr<Bag<uml::ActivityEdge>> outgoingList = m_CallBehaviorActionValue->getOutgoing();
		Bag<uml::ActivityEdge>::iterator iter = outgoingList->begin();
		Bag<uml::ActivityEdge>::iterator end = outgoingList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ActivityEdgeObject> value(new UML::ActivityEdgeObject());
			value->setThisActivityEdgeObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setActivityEdgeValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_redefinedNode())
	{
		std::shared_ptr<Bag<uml::ActivityNode>> redefinedNodeList = m_CallBehaviorActionValue->getRedefinedNode();
		Bag<uml::ActivityNode>::iterator iter = redefinedNodeList->begin();
		Bag<uml::ActivityNode>::iterator end = redefinedNodeList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ActivityNodeObject> value(new UML::ActivityNodeObject());
			value->setThisActivityNodeObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setActivityNodeValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CallAction_isSynchronous())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_CallBehaviorActionValue->getIsSynchronous());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CallAction_result())
	{
		std::shared_ptr<Bag<uml::OutputPin>> resultList = m_CallBehaviorActionValue->getResult();
		Bag<uml::OutputPin>::iterator iter = resultList->begin();
		Bag<uml::OutputPin>::iterator end = resultList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::OutputPinObject> value(new UML::OutputPinObject());
			value->setThisOutputPinObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setOutputPinValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CallBehaviorAction_behavior())
	{
		std::shared_ptr<UML::BehaviorObject> value(new UML::BehaviorObject());
		value->setThisBehaviorObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setBehaviorValue(m_CallBehaviorActionValue->getBehavior());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		std::shared_ptr<Bag<uml::Comment>> ownedCommentList = m_CallBehaviorActionValue->getOwnedComment();
		Bag<uml::Comment>::iterator iter = ownedCommentList->begin();
		Bag<uml::Comment>::iterator end = ownedCommentList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::CommentObject> value(new UML::CommentObject());
			value->setThisCommentObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setCommentValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement())
	{
		std::shared_ptr<Bag<uml::Element>> ownedElementList = m_CallBehaviorActionValue->getOwnedElement();
		Bag<uml::Element>::iterator iter = ownedElementList->begin();
		Bag<uml::Element>::iterator end = ownedElementList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ElementObject> value(new UML::ElementObject());
			value->setThisElementObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setElementValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_owner())
	{
		std::shared_ptr<UML::ElementObject> value(new UML::ElementObject());
		value->setThisElementObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setElementValue(m_CallBehaviorActionValue->getOwner().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ExecutableNode_handler())
	{
		std::shared_ptr<Bag<uml::ExceptionHandler>> handlerList = m_CallBehaviorActionValue->getHandler();
		Bag<uml::ExceptionHandler>::iterator iter = handlerList->begin();
		Bag<uml::ExceptionHandler>::iterator end = handlerList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ExceptionHandlerObject> value(new UML::ExceptionHandlerObject());
			value->setThisExceptionHandlerObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setExceptionHandlerValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InvocationAction_argument())
	{
		std::shared_ptr<Bag<uml::InputPin>> argumentList = m_CallBehaviorActionValue->getArgument();
		Bag<uml::InputPin>::iterator iter = argumentList->begin();
		Bag<uml::InputPin>::iterator end = argumentList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::InputPinObject> value(new UML::InputPinObject());
			value->setThisInputPinObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setInputPinValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InvocationAction_onPort())
	{
		std::shared_ptr<UML::PortObject> value(new UML::PortObject());
		value->setThisPortObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setPortValue(m_CallBehaviorActionValue->getOnPort());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency())
	{
		std::shared_ptr<Bag<uml::Dependency>> clientDependencyList = m_CallBehaviorActionValue->getClientDependency();
		Bag<uml::Dependency>::iterator iter = clientDependencyList->begin();
		Bag<uml::Dependency>::iterator end = clientDependencyList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::DependencyObject> value(new UML::DependencyObject());
			value->setThisDependencyObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setDependencyValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
		value->setValue(m_CallBehaviorActionValue->getName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<UML::StringExpressionObject> value(new UML::StringExpressionObject());
		value->setThisStringExpressionObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setStringExpressionValue(m_CallBehaviorActionValue->getNameExpression());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_namespace())
	{
		std::shared_ptr<UML::NamespaceObject> value(new UML::NamespaceObject());
		value->setThisNamespaceObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setNamespaceValue(m_CallBehaviorActionValue->getNamespace().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_qualifiedName())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
		value->setValue(m_CallBehaviorActionValue->getQualifiedName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		uml::VisibilityKind visibility = m_CallBehaviorActionValue->getVisibility();
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createEnumerationValue();
		if (visibility == uml::VisibilityKind::PUBLIC)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_VisibilityKind_public());
		}
		if (visibility == uml::VisibilityKind::PRIVATE)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_VisibilityKind_private());
		}
		if (visibility == uml::VisibilityKind::PROTECTED)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_VisibilityKind_protected());
		}
		if (visibility == uml::VisibilityKind::PACKAGE)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_VisibilityKind_package());
		}
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_CallBehaviorActionValue->getIsLeaf());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinedElement())
	{
		std::shared_ptr<Bag<uml::RedefinableElement>> redefinedElementList = m_CallBehaviorActionValue->getRedefinedElement();
		Bag<uml::RedefinableElement>::iterator iter = redefinedElementList->begin();
		Bag<uml::RedefinableElement>::iterator end = redefinedElementList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::RedefinableElementObject> value(new UML::RedefinableElementObject());
			value->setThisRedefinableElementObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setRedefinableElementValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinitionContext())
	{
		std::shared_ptr<Bag<uml::Classifier>> redefinitionContextList = m_CallBehaviorActionValue->getRedefinitionContext();
		Bag<uml::Classifier>::iterator iter = redefinitionContextList->begin();
		Bag<uml::Classifier>::iterator end = redefinitionContextList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ClassifierObject> value(new UML::ClassifierObject());
			value->setThisClassifierObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setClassifierValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	return values;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> CallBehaviorActionObject::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue(fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createFeatureValue());
	featureValue->setFeature(feature);

	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = this->getValues(feature, featureValues);
	
	unsigned int valuesSize = values->size();
	for(unsigned int i = 0; i < valuesSize; i++)
	{
		featureValue->getValues()->add(values->at(i));
	}

	return featureValue;
}


void CallBehaviorActionObject::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_CallBehaviorActionValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside CallBehaviorActionObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (values->size() == 0)
	{
		std::cout << __PRETTY_FUNCTION__ << ": no input value given" << std::endl;
		return;
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_isLocallyReentrant())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_CallBehaviorActionValue->setIsLocallyReentrant(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_localPostcondition())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CallBehaviorActionValue->getLocalPostcondition()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ConstraintObject> value = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CallBehaviorActionValue->getLocalPostcondition()->push_back(value->getConstraintValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_localPrecondition())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CallBehaviorActionValue->getLocalPrecondition()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ConstraintObject> value = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CallBehaviorActionValue->getLocalPrecondition()->push_back(value->getConstraintValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inInterruptibleRegion())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CallBehaviorActionValue->getInInterruptibleRegion()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::InterruptibleActivityRegionObject> value = std::dynamic_pointer_cast<UML::InterruptibleActivityRegionObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CallBehaviorActionValue->getInInterruptibleRegion()->push_back(value->getInterruptibleActivityRegionValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inPartition())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CallBehaviorActionValue->getInPartition()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ActivityPartitionObject> value = std::dynamic_pointer_cast<UML::ActivityPartitionObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CallBehaviorActionValue->getInPartition()->push_back(value->getActivityPartitionValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_incoming())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CallBehaviorActionValue->getIncoming()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ActivityEdgeObject> value = std::dynamic_pointer_cast<UML::ActivityEdgeObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CallBehaviorActionValue->getIncoming()->push_back(value->getActivityEdgeValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_outgoing())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CallBehaviorActionValue->getOutgoing()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ActivityEdgeObject> value = std::dynamic_pointer_cast<UML::ActivityEdgeObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CallBehaviorActionValue->getOutgoing()->push_back(value->getActivityEdgeValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_redefinedNode())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CallBehaviorActionValue->getRedefinedNode()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ActivityNodeObject> value = std::dynamic_pointer_cast<UML::ActivityNodeObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CallBehaviorActionValue->getRedefinedNode()->push_back(value->getActivityNodeValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CallAction_isSynchronous())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_CallBehaviorActionValue->setIsSynchronous(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CallAction_result())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CallBehaviorActionValue->getResult()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::OutputPinObject> value = std::dynamic_pointer_cast<UML::OutputPinObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CallBehaviorActionValue->getResult()->push_back(value->getOutputPinValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CallBehaviorAction_behavior())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::BehaviorObject> value = std::dynamic_pointer_cast<UML::BehaviorObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_CallBehaviorActionValue->setBehavior(value->getBehaviorValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CallBehaviorActionValue->getOwnedComment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CommentObject> value = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CallBehaviorActionValue->getOwnedComment()->push_back(value->getCommentValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ExecutableNode_handler())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CallBehaviorActionValue->getHandler()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ExceptionHandlerObject> value = std::dynamic_pointer_cast<UML::ExceptionHandlerObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CallBehaviorActionValue->getHandler()->push_back(value->getExceptionHandlerValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InvocationAction_argument())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CallBehaviorActionValue->getArgument()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::InputPinObject> value = std::dynamic_pointer_cast<UML::InputPinObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CallBehaviorActionValue->getArgument()->push_back(value->getInputPinValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InvocationAction_onPort())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::PortObject> value = std::dynamic_pointer_cast<UML::PortObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_CallBehaviorActionValue->setOnPort(value->getPortValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_CallBehaviorActionValue->setName(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::StringExpressionObject> value = std::dynamic_pointer_cast<UML::StringExpressionObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_CallBehaviorActionValue->setNameExpression(value->getStringExpressionValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(inputValue);
		std::shared_ptr<uml::EnumerationLiteral> literal = enumValue->getLiteral();
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_public())
		{
			m_CallBehaviorActionValue->setVisibility(uml::VisibilityKind::PUBLIC);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_private())
		{
			m_CallBehaviorActionValue->setVisibility(uml::VisibilityKind::PRIVATE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_protected())
		{
			m_CallBehaviorActionValue->setVisibility(uml::VisibilityKind::PROTECTED);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_package())
		{
			m_CallBehaviorActionValue->setVisibility(uml::VisibilityKind::PACKAGE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_CallBehaviorActionValue->setIsLeaf(valueObject->isValue());
		}
		
	}
}

void CallBehaviorActionObject::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	this->setFeatureValue(feature, values, position);
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> CallBehaviorActionObject::retrieveFeatureValues()
{
	std::shared_ptr<uml::Classifier> type = this->getTypes()->at(0);
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAllAttributes();
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	
	unsigned int allAttributesSize = allAttributes->size();

	for(unsigned int i = 0; i < allAttributesSize; i++)
	{
		std::shared_ptr<uml::Property> property = allAttributes->at(i);
		if (property == UML::UMLPackage::eInstance()->get_UML_Action_context() && m_CallBehaviorActionValue->getContext() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Action_input() && m_CallBehaviorActionValue->getInput() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Action_localPostcondition() && m_CallBehaviorActionValue->getLocalPostcondition() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Action_localPrecondition() && m_CallBehaviorActionValue->getLocalPrecondition() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Action_output() && m_CallBehaviorActionValue->getOutput() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_activity() && m_CallBehaviorActionValue->getActivity().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inGroup() && m_CallBehaviorActionValue->getInGroup() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inInterruptibleRegion() && m_CallBehaviorActionValue->getInInterruptibleRegion() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inPartition() && m_CallBehaviorActionValue->getInPartition() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inStructuredNode() && m_CallBehaviorActionValue->getInStructuredNode().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_incoming() && m_CallBehaviorActionValue->getIncoming() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_outgoing() && m_CallBehaviorActionValue->getOutgoing() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_redefinedNode() && m_CallBehaviorActionValue->getRedefinedNode() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_CallAction_result() && m_CallBehaviorActionValue->getResult() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_CallBehaviorAction_behavior() && m_CallBehaviorActionValue->getBehavior() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment() && m_CallBehaviorActionValue->getOwnedComment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement() && m_CallBehaviorActionValue->getOwnedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_owner() && m_CallBehaviorActionValue->getOwner().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ExecutableNode_handler() && m_CallBehaviorActionValue->getHandler() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_InvocationAction_argument() && m_CallBehaviorActionValue->getArgument() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_InvocationAction_onPort() && m_CallBehaviorActionValue->getOnPort() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency() && m_CallBehaviorActionValue->getClientDependency() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression() && m_CallBehaviorActionValue->getNameExpression() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_namespace() && m_CallBehaviorActionValue->getNamespace().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinedElement() && m_CallBehaviorActionValue->getRedefinedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinitionContext() && m_CallBehaviorActionValue->getRedefinitionContext() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
	}
	
	return featureValues;
}

