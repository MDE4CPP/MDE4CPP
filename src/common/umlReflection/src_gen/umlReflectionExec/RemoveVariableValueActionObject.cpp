#include "umlReflectionExec/RemoveVariableValueActionObject.hpp"

//General Includes
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/RemoveVariableValueAction.hpp"
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
#include "uml/Comment.hpp"
#include "umlReflectionExec/CommentObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/ExceptionHandler.hpp"
#include "umlReflectionExec/ExceptionHandlerObject.hpp"
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
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/InputPin.hpp"
#include "umlReflectionExec/InputPinObject.hpp"
#include "uml/Variable.hpp"
#include "umlReflectionExec/VariableObject.hpp"
#include "uml/InputPin.hpp"
#include "umlReflectionExec/InputPinObject.hpp"
//Property Packages Includes
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"


using namespace UML;

RemoveVariableValueActionObject::RemoveVariableValueActionObject(std::shared_ptr<uml::RemoveVariableValueAction> _element):

	m_RemoveVariableValueActionValue(_element)
{		
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_RemoveVariableValueAction());
}

RemoveVariableValueActionObject::RemoveVariableValueActionObject(RemoveVariableValueActionObject &obj):
	CS_ObjectImpl(obj)
{
}

RemoveVariableValueActionObject::RemoveVariableValueActionObject()
{	
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_RemoveVariableValueAction());
}

RemoveVariableValueActionObject::~RemoveVariableValueActionObject()
{
}

std::shared_ptr<ecore::EObject> RemoveVariableValueActionObject::copy()
{
	std::shared_ptr<RemoveVariableValueActionObject> element(new RemoveVariableValueActionObject(*this));
	element->setThisRemoveVariableValueActionObjectPtr(element);
	return element;
}

void RemoveVariableValueActionObject::destroy()
{	
	m_RemoveVariableValueActionValue.reset();

	fUML::Semantics::StructuredClassifiers::ObjectImpl::destroy();
}

std::shared_ptr<uml::Element> RemoveVariableValueActionObject::getUmlValue() const
{
	return getRemoveVariableValueActionValue();
}

std::shared_ptr<uml::RemoveVariableValueAction> RemoveVariableValueActionObject::getRemoveVariableValueActionValue() const
{
	return m_RemoveVariableValueActionValue;
}

void RemoveVariableValueActionObject::setUmlValue(std::shared_ptr<uml::Element> _element)
{
	setRemoveVariableValueActionValue(std::dynamic_pointer_cast<uml::RemoveVariableValueAction>(_element));
}

void RemoveVariableValueActionObject::setRemoveVariableValueActionValue(std::shared_ptr<uml::RemoveVariableValueAction> _RemoveVariableValueActionElement)
{
	m_RemoveVariableValueActionValue = _RemoveVariableValueActionElement;
	//set super type values
	UML::WriteVariableActionObject::setWriteVariableActionValue(_RemoveVariableValueActionElement);
}

void RemoveVariableValueActionObject::setThisRemoveVariableValueActionObjectPtr(std::weak_ptr<RemoveVariableValueActionObject> thisObjectPtr)
{
	setThisCS_ObjectPtr(thisObjectPtr);
}

bool RemoveVariableValueActionObject::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	bool isEqual = false;
	
	std::shared_ptr<RemoveVariableValueActionObject> otherRemoveVariableValueActionObject = std::dynamic_pointer_cast<RemoveVariableValueActionObject>(otherValue);

	if(otherRemoveVariableValueActionObject != nullptr)
	{
		if(this->getRemoveVariableValueActionValue() == otherRemoveVariableValueActionObject->getRemoveVariableValueActionValue())
		{
			isEqual = true;
		}
	}

	return isEqual;
}

std::string RemoveVariableValueActionObject::toString()
{
	std::string buffer = "Instance of 'RemoveVariableValueActionObject', " + std::to_string(getTypes()->size()) + " types (";
	for(unsigned int i = 0; i < getTypes()->size(); ++i)
	{
		buffer += "type{" + std::to_string(i) + "}: '" + getTypes()->at(i)->getName() + "', ";
	}
	buffer +=")";

	return buffer;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> RemoveVariableValueActionObject::getDirectContainers()
{   
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());

	/*Not done for metamodel object classes*/

	return directContainers;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> RemoveVariableValueActionObject::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> allLinks(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());

	/*Not done for metamodel object classes*/

	return allLinks;
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> RemoveVariableValueActionObject::retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end)
{
	/*Not done for metamodel object classes*/

	return nullptr;
}

void RemoveVariableValueActionObject::removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_RemoveVariableValueActionValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside RemoveVariableValueActionObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_isLocallyReentrant())
	{
				m_RemoveVariableValueActionValue->setIsLocallyReentrant(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_localPostcondition())
	{
		if (value == nullptr) // clear mode
		{
			m_RemoveVariableValueActionValue->getLocalPostcondition()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ConstraintObject> inputValue = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_RemoveVariableValueActionValue->getLocalPostcondition()->erase(inputValue->getConstraintValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_localPrecondition())
	{
		if (value == nullptr) // clear mode
		{
			m_RemoveVariableValueActionValue->getLocalPrecondition()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ConstraintObject> inputValue = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_RemoveVariableValueActionValue->getLocalPrecondition()->erase(inputValue->getConstraintValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_activity())
	{
				m_RemoveVariableValueActionValue->getActivity().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inInterruptibleRegion())
	{
		if (value == nullptr) // clear mode
		{
			m_RemoveVariableValueActionValue->getInInterruptibleRegion()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::InterruptibleActivityRegionObject> inputValue = std::dynamic_pointer_cast<UML::InterruptibleActivityRegionObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_RemoveVariableValueActionValue->getInInterruptibleRegion()->erase(inputValue->getInterruptibleActivityRegionValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inPartition())
	{
		if (value == nullptr) // clear mode
		{
			m_RemoveVariableValueActionValue->getInPartition()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ActivityPartitionObject> inputValue = std::dynamic_pointer_cast<UML::ActivityPartitionObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_RemoveVariableValueActionValue->getInPartition()->erase(inputValue->getActivityPartitionValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inStructuredNode())
	{
				m_RemoveVariableValueActionValue->getInStructuredNode().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_incoming())
	{
		if (value == nullptr) // clear mode
		{
			m_RemoveVariableValueActionValue->getIncoming()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ActivityEdgeObject> inputValue = std::dynamic_pointer_cast<UML::ActivityEdgeObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_RemoveVariableValueActionValue->getIncoming()->erase(inputValue->getActivityEdgeValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_outgoing())
	{
		if (value == nullptr) // clear mode
		{
			m_RemoveVariableValueActionValue->getOutgoing()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ActivityEdgeObject> inputValue = std::dynamic_pointer_cast<UML::ActivityEdgeObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_RemoveVariableValueActionValue->getOutgoing()->erase(inputValue->getActivityEdgeValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_redefinedNode())
	{
		if (value == nullptr) // clear mode
		{
			m_RemoveVariableValueActionValue->getRedefinedNode()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ActivityNodeObject> inputValue = std::dynamic_pointer_cast<UML::ActivityNodeObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_RemoveVariableValueActionValue->getRedefinedNode()->erase(inputValue->getActivityNodeValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		if (value == nullptr) // clear mode
		{
			m_RemoveVariableValueActionValue->getOwnedComment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CommentObject> inputValue = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_RemoveVariableValueActionValue->getOwnedComment()->erase(inputValue->getCommentValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ExecutableNode_handler())
	{
		if (value == nullptr) // clear mode
		{
			m_RemoveVariableValueActionValue->getHandler()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ExceptionHandlerObject> inputValue = std::dynamic_pointer_cast<UML::ExceptionHandlerObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_RemoveVariableValueActionValue->getHandler()->erase(inputValue->getExceptionHandlerValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
				m_RemoveVariableValueActionValue->getNameExpression().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
				m_RemoveVariableValueActionValue->setIsLeaf(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RemoveVariableValueAction_isRemoveDuplicates())
	{
				m_RemoveVariableValueActionValue->setIsRemoveDuplicates(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RemoveVariableValueAction_removeAt())
	{
				m_RemoveVariableValueActionValue->getRemoveAt().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_VariableAction_variable())
	{
				m_RemoveVariableValueActionValue->getVariable().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_WriteVariableAction_value())
	{
				m_RemoveVariableValueActionValue->getValue().reset();

	}
}


std::shared_ptr<Bag<fUML::Semantics::Values::Value>> RemoveVariableValueActionObject::getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_RemoveVariableValueActionValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside RemoveVariableValueActionObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_context())
	{
		std::shared_ptr<UML::ClassifierObject> value(new UML::ClassifierObject());
		value->setThisClassifierObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setClassifierValue(m_RemoveVariableValueActionValue->getContext());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_input())
	{
		std::shared_ptr<Bag<uml::InputPin>> inputList = m_RemoveVariableValueActionValue->getInput();
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
		value->setValue(m_RemoveVariableValueActionValue->getIsLocallyReentrant());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_localPostcondition())
	{
		std::shared_ptr<Bag<uml::Constraint>> localPostconditionList = m_RemoveVariableValueActionValue->getLocalPostcondition();
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
		std::shared_ptr<Bag<uml::Constraint>> localPreconditionList = m_RemoveVariableValueActionValue->getLocalPrecondition();
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
		std::shared_ptr<Bag<uml::OutputPin>> outputList = m_RemoveVariableValueActionValue->getOutput();
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
		value->setActivityValue(m_RemoveVariableValueActionValue->getActivity().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inGroup())
	{
		std::shared_ptr<Bag<uml::ActivityGroup>> inGroupList = m_RemoveVariableValueActionValue->getInGroup();
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
		std::shared_ptr<Bag<uml::InterruptibleActivityRegion>> inInterruptibleRegionList = m_RemoveVariableValueActionValue->getInInterruptibleRegion();
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
		std::shared_ptr<Bag<uml::ActivityPartition>> inPartitionList = m_RemoveVariableValueActionValue->getInPartition();
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
		value->setStructuredActivityNodeValue(m_RemoveVariableValueActionValue->getInStructuredNode().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_incoming())
	{
		std::shared_ptr<Bag<uml::ActivityEdge>> incomingList = m_RemoveVariableValueActionValue->getIncoming();
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
		std::shared_ptr<Bag<uml::ActivityEdge>> outgoingList = m_RemoveVariableValueActionValue->getOutgoing();
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
		std::shared_ptr<Bag<uml::ActivityNode>> redefinedNodeList = m_RemoveVariableValueActionValue->getRedefinedNode();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		std::shared_ptr<Bag<uml::Comment>> ownedCommentList = m_RemoveVariableValueActionValue->getOwnedComment();
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
		std::shared_ptr<Bag<uml::Element>> ownedElementList = m_RemoveVariableValueActionValue->getOwnedElement();
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
		value->setElementValue(m_RemoveVariableValueActionValue->getOwner().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ExecutableNode_handler())
	{
		std::shared_ptr<Bag<uml::ExceptionHandler>> handlerList = m_RemoveVariableValueActionValue->getHandler();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency())
	{
		std::shared_ptr<Bag<uml::Dependency>> clientDependencyList = m_RemoveVariableValueActionValue->getClientDependency();
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
		value->setValue(m_RemoveVariableValueActionValue->getName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<UML::StringExpressionObject> value(new UML::StringExpressionObject());
		value->setThisStringExpressionObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setStringExpressionValue(m_RemoveVariableValueActionValue->getNameExpression());
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
		value->setNamespaceValue(m_RemoveVariableValueActionValue->getNamespace().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_qualifiedName())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
		value->setValue(m_RemoveVariableValueActionValue->getQualifiedName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		uml::VisibilityKind visibility = m_RemoveVariableValueActionValue->getVisibility();
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
		value->setValue(m_RemoveVariableValueActionValue->getIsLeaf());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinedElement())
	{
		std::shared_ptr<Bag<uml::RedefinableElement>> redefinedElementList = m_RemoveVariableValueActionValue->getRedefinedElement();
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
		std::shared_ptr<Bag<uml::Classifier>> redefinitionContextList = m_RemoveVariableValueActionValue->getRedefinitionContext();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_RemoveVariableValueAction_isRemoveDuplicates())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_RemoveVariableValueActionValue->getIsRemoveDuplicates());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RemoveVariableValueAction_removeAt())
	{
		std::shared_ptr<UML::InputPinObject> value(new UML::InputPinObject());
		value->setThisInputPinObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setInputPinValue(m_RemoveVariableValueActionValue->getRemoveAt());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_VariableAction_variable())
	{
		std::shared_ptr<UML::VariableObject> value(new UML::VariableObject());
		value->setThisVariableObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setVariableValue(m_RemoveVariableValueActionValue->getVariable());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_WriteVariableAction_value())
	{
		std::shared_ptr<UML::InputPinObject> value(new UML::InputPinObject());
		value->setThisInputPinObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setInputPinValue(m_RemoveVariableValueActionValue->getValue());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	return values;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> RemoveVariableValueActionObject::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
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


void RemoveVariableValueActionObject::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_RemoveVariableValueActionValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside RemoveVariableValueActionObject (property: " << feature->getName() << ")" << std::endl;
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
			m_RemoveVariableValueActionValue->setIsLocallyReentrant(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_localPostcondition())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_RemoveVariableValueActionValue->getLocalPostcondition()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ConstraintObject> value = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_RemoveVariableValueActionValue->getLocalPostcondition()->push_back(value->getConstraintValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Action_localPrecondition())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_RemoveVariableValueActionValue->getLocalPrecondition()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ConstraintObject> value = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_RemoveVariableValueActionValue->getLocalPrecondition()->push_back(value->getConstraintValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inInterruptibleRegion())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_RemoveVariableValueActionValue->getInInterruptibleRegion()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::InterruptibleActivityRegionObject> value = std::dynamic_pointer_cast<UML::InterruptibleActivityRegionObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_RemoveVariableValueActionValue->getInInterruptibleRegion()->push_back(value->getInterruptibleActivityRegionValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inPartition())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_RemoveVariableValueActionValue->getInPartition()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ActivityPartitionObject> value = std::dynamic_pointer_cast<UML::ActivityPartitionObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_RemoveVariableValueActionValue->getInPartition()->push_back(value->getActivityPartitionValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_incoming())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_RemoveVariableValueActionValue->getIncoming()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ActivityEdgeObject> value = std::dynamic_pointer_cast<UML::ActivityEdgeObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_RemoveVariableValueActionValue->getIncoming()->push_back(value->getActivityEdgeValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_outgoing())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_RemoveVariableValueActionValue->getOutgoing()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ActivityEdgeObject> value = std::dynamic_pointer_cast<UML::ActivityEdgeObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_RemoveVariableValueActionValue->getOutgoing()->push_back(value->getActivityEdgeValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ActivityNode_redefinedNode())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_RemoveVariableValueActionValue->getRedefinedNode()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ActivityNodeObject> value = std::dynamic_pointer_cast<UML::ActivityNodeObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_RemoveVariableValueActionValue->getRedefinedNode()->push_back(value->getActivityNodeValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_RemoveVariableValueActionValue->getOwnedComment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CommentObject> value = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_RemoveVariableValueActionValue->getOwnedComment()->push_back(value->getCommentValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ExecutableNode_handler())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_RemoveVariableValueActionValue->getHandler()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ExceptionHandlerObject> value = std::dynamic_pointer_cast<UML::ExceptionHandlerObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_RemoveVariableValueActionValue->getHandler()->push_back(value->getExceptionHandlerValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_RemoveVariableValueActionValue->setName(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::StringExpressionObject> value = std::dynamic_pointer_cast<UML::StringExpressionObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_RemoveVariableValueActionValue->setNameExpression(value->getStringExpressionValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(inputValue);
		std::shared_ptr<uml::EnumerationLiteral> literal = enumValue->getLiteral();
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_public())
		{
			m_RemoveVariableValueActionValue->setVisibility(uml::VisibilityKind::PUBLIC);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_private())
		{
			m_RemoveVariableValueActionValue->setVisibility(uml::VisibilityKind::PRIVATE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_protected())
		{
			m_RemoveVariableValueActionValue->setVisibility(uml::VisibilityKind::PROTECTED);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_package())
		{
			m_RemoveVariableValueActionValue->setVisibility(uml::VisibilityKind::PACKAGE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_RemoveVariableValueActionValue->setIsLeaf(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RemoveVariableValueAction_isRemoveDuplicates())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_RemoveVariableValueActionValue->setIsRemoveDuplicates(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RemoveVariableValueAction_removeAt())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::InputPinObject> value = std::dynamic_pointer_cast<UML::InputPinObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_RemoveVariableValueActionValue->setRemoveAt(value->getInputPinValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_VariableAction_variable())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::VariableObject> value = std::dynamic_pointer_cast<UML::VariableObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_RemoveVariableValueActionValue->setVariable(value->getVariableValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_WriteVariableAction_value())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::InputPinObject> value = std::dynamic_pointer_cast<UML::InputPinObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_RemoveVariableValueActionValue->setValue(value->getInputPinValue());
		}
		
	}
}

void RemoveVariableValueActionObject::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	this->setFeatureValue(feature, values, position);
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> RemoveVariableValueActionObject::retrieveFeatureValues()
{
	std::shared_ptr<uml::Classifier> type = this->getTypes()->at(0);
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAllAttributes();
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	
	unsigned int allAttributesSize = allAttributes->size();

	for(unsigned int i = 0; i < allAttributesSize; i++)
	{
		std::shared_ptr<uml::Property> property = allAttributes->at(i);
		if (property == UML::UMLPackage::eInstance()->get_UML_Action_context() && m_RemoveVariableValueActionValue->getContext() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Action_input() && m_RemoveVariableValueActionValue->getInput() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Action_localPostcondition() && m_RemoveVariableValueActionValue->getLocalPostcondition() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Action_localPrecondition() && m_RemoveVariableValueActionValue->getLocalPrecondition() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Action_output() && m_RemoveVariableValueActionValue->getOutput() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_activity() && m_RemoveVariableValueActionValue->getActivity().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inGroup() && m_RemoveVariableValueActionValue->getInGroup() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inInterruptibleRegion() && m_RemoveVariableValueActionValue->getInInterruptibleRegion() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inPartition() && m_RemoveVariableValueActionValue->getInPartition() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_inStructuredNode() && m_RemoveVariableValueActionValue->getInStructuredNode().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_incoming() && m_RemoveVariableValueActionValue->getIncoming() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_outgoing() && m_RemoveVariableValueActionValue->getOutgoing() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ActivityNode_redefinedNode() && m_RemoveVariableValueActionValue->getRedefinedNode() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment() && m_RemoveVariableValueActionValue->getOwnedComment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement() && m_RemoveVariableValueActionValue->getOwnedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_owner() && m_RemoveVariableValueActionValue->getOwner().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ExecutableNode_handler() && m_RemoveVariableValueActionValue->getHandler() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency() && m_RemoveVariableValueActionValue->getClientDependency() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression() && m_RemoveVariableValueActionValue->getNameExpression() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_namespace() && m_RemoveVariableValueActionValue->getNamespace().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinedElement() && m_RemoveVariableValueActionValue->getRedefinedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinitionContext() && m_RemoveVariableValueActionValue->getRedefinitionContext() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RemoveVariableValueAction_removeAt() && m_RemoveVariableValueActionValue->getRemoveAt() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_VariableAction_variable() && m_RemoveVariableValueActionValue->getVariable() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_WriteVariableAction_value() && m_RemoveVariableValueActionValue->getValue() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
	}
	
	return featureValues;
}

