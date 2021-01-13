#include "umlReflectionExec/DestructionOccurrenceSpecificationObject.hpp"

//General Includes
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/DestructionOccurrenceSpecification.hpp"
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
#include "uml/Comment.hpp"
#include "umlReflectionExec/CommentObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/Interaction.hpp"
#include "umlReflectionExec/InteractionObject.hpp"
#include "uml/InteractionOperand.hpp"
#include "umlReflectionExec/InteractionOperandObject.hpp"
#include "uml/GeneralOrdering.hpp"
#include "umlReflectionExec/GeneralOrderingObject.hpp"
#include "uml/Message.hpp"
#include "umlReflectionExec/MessageObject.hpp"
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
#include "uml/Lifeline.hpp"
#include "umlReflectionExec/LifelineObject.hpp"
#include "uml/GeneralOrdering.hpp"
#include "umlReflectionExec/GeneralOrderingObject.hpp"
#include "uml/GeneralOrdering.hpp"
#include "umlReflectionExec/GeneralOrderingObject.hpp"
//Property Packages Includes
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"


using namespace UML;

DestructionOccurrenceSpecificationObject::DestructionOccurrenceSpecificationObject(std::shared_ptr<uml::DestructionOccurrenceSpecification> _element):

	m_DestructionOccurrenceSpecificationValue(_element)
{		
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_DestructionOccurrenceSpecification());
}

DestructionOccurrenceSpecificationObject::DestructionOccurrenceSpecificationObject(DestructionOccurrenceSpecificationObject &obj):
	CS_ObjectImpl(obj)
{
}

DestructionOccurrenceSpecificationObject::DestructionOccurrenceSpecificationObject()
{	
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_DestructionOccurrenceSpecification());
}

DestructionOccurrenceSpecificationObject::~DestructionOccurrenceSpecificationObject()
{
}

std::shared_ptr<ecore::EObject> DestructionOccurrenceSpecificationObject::copy()
{
	std::shared_ptr<DestructionOccurrenceSpecificationObject> element(new DestructionOccurrenceSpecificationObject(*this));
	element->setThisDestructionOccurrenceSpecificationObjectPtr(element);
	return element;
}

void DestructionOccurrenceSpecificationObject::destroy()
{	
	m_DestructionOccurrenceSpecificationValue.reset();

	fUML::Semantics::StructuredClassifiers::ObjectImpl::destroy();
}

std::shared_ptr<uml::Element> DestructionOccurrenceSpecificationObject::getUmlValue() const
{
	return getDestructionOccurrenceSpecificationValue();
}

std::shared_ptr<uml::DestructionOccurrenceSpecification> DestructionOccurrenceSpecificationObject::getDestructionOccurrenceSpecificationValue() const
{
	return m_DestructionOccurrenceSpecificationValue;
}

void DestructionOccurrenceSpecificationObject::setUmlValue(std::shared_ptr<uml::Element> _element)
{
	setDestructionOccurrenceSpecificationValue(std::dynamic_pointer_cast<uml::DestructionOccurrenceSpecification>(_element));
}

void DestructionOccurrenceSpecificationObject::setDestructionOccurrenceSpecificationValue(std::shared_ptr<uml::DestructionOccurrenceSpecification> _DestructionOccurrenceSpecificationElement)
{
	m_DestructionOccurrenceSpecificationValue = _DestructionOccurrenceSpecificationElement;
	//set super type values
	UML::MessageOccurrenceSpecificationObject::setMessageOccurrenceSpecificationValue(_DestructionOccurrenceSpecificationElement);
}

void DestructionOccurrenceSpecificationObject::setThisDestructionOccurrenceSpecificationObjectPtr(std::weak_ptr<DestructionOccurrenceSpecificationObject> thisObjectPtr)
{
	setThisCS_ObjectPtr(thisObjectPtr);
}

bool DestructionOccurrenceSpecificationObject::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	bool isEqual = false;
	
	std::shared_ptr<DestructionOccurrenceSpecificationObject> otherDestructionOccurrenceSpecificationObject = std::dynamic_pointer_cast<DestructionOccurrenceSpecificationObject>(otherValue);

	if(otherDestructionOccurrenceSpecificationObject != nullptr)
	{
		if(this->getDestructionOccurrenceSpecificationValue() == otherDestructionOccurrenceSpecificationObject->getDestructionOccurrenceSpecificationValue())
		{
			isEqual = true;
		}
	}

	return isEqual;
}

std::string DestructionOccurrenceSpecificationObject::toString()
{
	std::string buffer = "Instance of 'DestructionOccurrenceSpecificationObject', " + std::to_string(getTypes()->size()) + " types (";
	for(unsigned int i = 0; i < getTypes()->size(); ++i)
	{
		buffer += "type{" + std::to_string(i) + "}: '" + getTypes()->at(i)->getName() + "', ";
	}
	buffer +=")";

	return buffer;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> DestructionOccurrenceSpecificationObject::getDirectContainers()
{   
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());

	/*Not done for metamodel object classes*/

	return directContainers;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> DestructionOccurrenceSpecificationObject::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> allLinks(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());

	/*Not done for metamodel object classes*/

	return allLinks;
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> DestructionOccurrenceSpecificationObject::retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end)
{
	/*Not done for metamodel object classes*/

	return nullptr;
}

void DestructionOccurrenceSpecificationObject::removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_DestructionOccurrenceSpecificationValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside DestructionOccurrenceSpecificationObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		if (value == nullptr) // clear mode
		{
			m_DestructionOccurrenceSpecificationValue->getOwnedComment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CommentObject> inputValue = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DestructionOccurrenceSpecificationValue->getOwnedComment()->erase(inputValue->getCommentValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_enclosingInteraction())
	{
				m_DestructionOccurrenceSpecificationValue->getEnclosingInteraction().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_enclosingOperand())
	{
				m_DestructionOccurrenceSpecificationValue->getEnclosingOperand().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_generalOrdering())
	{
		if (value == nullptr) // clear mode
		{
			m_DestructionOccurrenceSpecificationValue->getGeneralOrdering()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::GeneralOrderingObject> inputValue = std::dynamic_pointer_cast<UML::GeneralOrderingObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DestructionOccurrenceSpecificationValue->getGeneralOrdering()->erase(inputValue->getGeneralOrderingValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MessageEnd_message())
	{
				m_DestructionOccurrenceSpecificationValue->getMessage().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
				m_DestructionOccurrenceSpecificationValue->getNameExpression().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_OccurrenceSpecification_covered())
	{
				m_DestructionOccurrenceSpecificationValue->getCovered().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_OccurrenceSpecification_toAfter())
	{
		if (value == nullptr) // clear mode
		{
			m_DestructionOccurrenceSpecificationValue->getToAfter()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::GeneralOrderingObject> inputValue = std::dynamic_pointer_cast<UML::GeneralOrderingObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DestructionOccurrenceSpecificationValue->getToAfter()->erase(inputValue->getGeneralOrderingValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_OccurrenceSpecification_toBefore())
	{
		if (value == nullptr) // clear mode
		{
			m_DestructionOccurrenceSpecificationValue->getToBefore()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::GeneralOrderingObject> inputValue = std::dynamic_pointer_cast<UML::GeneralOrderingObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DestructionOccurrenceSpecificationValue->getToBefore()->erase(inputValue->getGeneralOrderingValue());
			}
		}
	}
}


std::shared_ptr<Bag<fUML::Semantics::Values::Value>> DestructionOccurrenceSpecificationObject::getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_DestructionOccurrenceSpecificationValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside DestructionOccurrenceSpecificationObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		std::shared_ptr<Bag<uml::Comment>> ownedCommentList = m_DestructionOccurrenceSpecificationValue->getOwnedComment();
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
		std::shared_ptr<Bag<uml::Element>> ownedElementList = m_DestructionOccurrenceSpecificationValue->getOwnedElement();
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
		value->setElementValue(m_DestructionOccurrenceSpecificationValue->getOwner().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_enclosingInteraction())
	{
		std::shared_ptr<UML::InteractionObject> value(new UML::InteractionObject());
		value->setThisInteractionObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setInteractionValue(m_DestructionOccurrenceSpecificationValue->getEnclosingInteraction().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_enclosingOperand())
	{
		std::shared_ptr<UML::InteractionOperandObject> value(new UML::InteractionOperandObject());
		value->setThisInteractionOperandObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setInteractionOperandValue(m_DestructionOccurrenceSpecificationValue->getEnclosingOperand().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_generalOrdering())
	{
		std::shared_ptr<Bag<uml::GeneralOrdering>> generalOrderingList = m_DestructionOccurrenceSpecificationValue->getGeneralOrdering();
		Bag<uml::GeneralOrdering>::iterator iter = generalOrderingList->begin();
		Bag<uml::GeneralOrdering>::iterator end = generalOrderingList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::GeneralOrderingObject> value(new UML::GeneralOrderingObject());
			value->setThisGeneralOrderingObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setGeneralOrderingValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MessageEnd_message())
	{
		std::shared_ptr<UML::MessageObject> value(new UML::MessageObject());
		value->setThisMessageObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setMessageValue(m_DestructionOccurrenceSpecificationValue->getMessage());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency())
	{
		std::shared_ptr<Bag<uml::Dependency>> clientDependencyList = m_DestructionOccurrenceSpecificationValue->getClientDependency();
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
		value->setValue(m_DestructionOccurrenceSpecificationValue->getName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<UML::StringExpressionObject> value(new UML::StringExpressionObject());
		value->setThisStringExpressionObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setStringExpressionValue(m_DestructionOccurrenceSpecificationValue->getNameExpression());
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
		value->setNamespaceValue(m_DestructionOccurrenceSpecificationValue->getNamespace().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_qualifiedName())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
		value->setValue(m_DestructionOccurrenceSpecificationValue->getQualifiedName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		uml::VisibilityKind visibility = m_DestructionOccurrenceSpecificationValue->getVisibility();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_OccurrenceSpecification_covered())
	{
		std::cout << __PRETTY_FUNCTION__ << ": multiplicity conflict between property 'covered[1..1]' and redefined property 'covered[0..-1]'" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_OccurrenceSpecification_toAfter())
	{
		std::shared_ptr<Bag<uml::GeneralOrdering>> toAfterList = m_DestructionOccurrenceSpecificationValue->getToAfter();
		Bag<uml::GeneralOrdering>::iterator iter = toAfterList->begin();
		Bag<uml::GeneralOrdering>::iterator end = toAfterList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::GeneralOrderingObject> value(new UML::GeneralOrderingObject());
			value->setThisGeneralOrderingObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setGeneralOrderingValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_OccurrenceSpecification_toBefore())
	{
		std::shared_ptr<Bag<uml::GeneralOrdering>> toBeforeList = m_DestructionOccurrenceSpecificationValue->getToBefore();
		Bag<uml::GeneralOrdering>::iterator iter = toBeforeList->begin();
		Bag<uml::GeneralOrdering>::iterator end = toBeforeList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::GeneralOrderingObject> value(new UML::GeneralOrderingObject());
			value->setThisGeneralOrderingObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setGeneralOrderingValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	return values;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> DestructionOccurrenceSpecificationObject::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
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


void DestructionOccurrenceSpecificationObject::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_DestructionOccurrenceSpecificationValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside DestructionOccurrenceSpecificationObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (values->size() == 0)
	{
		std::cout << __PRETTY_FUNCTION__ << ": no input value given" << std::endl;
		return;
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DestructionOccurrenceSpecificationValue->getOwnedComment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CommentObject> value = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DestructionOccurrenceSpecificationValue->getOwnedComment()->push_back(value->getCommentValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_generalOrdering())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DestructionOccurrenceSpecificationValue->getGeneralOrdering()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::GeneralOrderingObject> value = std::dynamic_pointer_cast<UML::GeneralOrderingObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DestructionOccurrenceSpecificationValue->getGeneralOrdering()->push_back(value->getGeneralOrderingValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MessageEnd_message())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::MessageObject> value = std::dynamic_pointer_cast<UML::MessageObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_DestructionOccurrenceSpecificationValue->setMessage(value->getMessageValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_DestructionOccurrenceSpecificationValue->setName(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::StringExpressionObject> value = std::dynamic_pointer_cast<UML::StringExpressionObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_DestructionOccurrenceSpecificationValue->setNameExpression(value->getStringExpressionValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(inputValue);
		std::shared_ptr<uml::EnumerationLiteral> literal = enumValue->getLiteral();
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_public())
		{
			m_DestructionOccurrenceSpecificationValue->setVisibility(uml::VisibilityKind::PUBLIC);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_private())
		{
			m_DestructionOccurrenceSpecificationValue->setVisibility(uml::VisibilityKind::PRIVATE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_protected())
		{
			m_DestructionOccurrenceSpecificationValue->setVisibility(uml::VisibilityKind::PROTECTED);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_package())
		{
			m_DestructionOccurrenceSpecificationValue->setVisibility(uml::VisibilityKind::PACKAGE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_OccurrenceSpecification_covered())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::LifelineObject> value = std::dynamic_pointer_cast<UML::LifelineObject>(reference->getReferent());
		if (value != nullptr)
		{
				std::cout << __PRETTY_FUNCTION__ << ": multiplicity conflict between property 'covered[1..1]' and redefined property 'covered[0..-1]'" << std::endl;
				exit(EXIT_FAILURE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_OccurrenceSpecification_toAfter())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DestructionOccurrenceSpecificationValue->getToAfter()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::GeneralOrderingObject> value = std::dynamic_pointer_cast<UML::GeneralOrderingObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DestructionOccurrenceSpecificationValue->getToAfter()->push_back(value->getGeneralOrderingValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_OccurrenceSpecification_toBefore())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DestructionOccurrenceSpecificationValue->getToBefore()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::GeneralOrderingObject> value = std::dynamic_pointer_cast<UML::GeneralOrderingObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DestructionOccurrenceSpecificationValue->getToBefore()->push_back(value->getGeneralOrderingValue());
			}
			
			iter++;
		}
	}
}

void DestructionOccurrenceSpecificationObject::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	this->setFeatureValue(feature, values, position);
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> DestructionOccurrenceSpecificationObject::retrieveFeatureValues()
{
	std::shared_ptr<uml::Classifier> type = this->getTypes()->at(0);
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAllAttributes();
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	
	unsigned int allAttributesSize = allAttributes->size();

	for(unsigned int i = 0; i < allAttributesSize; i++)
	{
		std::shared_ptr<uml::Property> property = allAttributes->at(i);
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment() && m_DestructionOccurrenceSpecificationValue->getOwnedComment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement() && m_DestructionOccurrenceSpecificationValue->getOwnedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_owner() && m_DestructionOccurrenceSpecificationValue->getOwner().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_enclosingInteraction() && m_DestructionOccurrenceSpecificationValue->getEnclosingInteraction().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_enclosingOperand() && m_DestructionOccurrenceSpecificationValue->getEnclosingOperand().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_generalOrdering() && m_DestructionOccurrenceSpecificationValue->getGeneralOrdering() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_MessageEnd_message() && m_DestructionOccurrenceSpecificationValue->getMessage() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency() && m_DestructionOccurrenceSpecificationValue->getClientDependency() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression() && m_DestructionOccurrenceSpecificationValue->getNameExpression() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_namespace() && m_DestructionOccurrenceSpecificationValue->getNamespace().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_OccurrenceSpecification_covered() && m_DestructionOccurrenceSpecificationValue->getCovered() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_OccurrenceSpecification_toAfter() && m_DestructionOccurrenceSpecificationValue->getToAfter() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_OccurrenceSpecification_toBefore() && m_DestructionOccurrenceSpecificationValue->getToBefore() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
	}
	
	return featureValues;
}

