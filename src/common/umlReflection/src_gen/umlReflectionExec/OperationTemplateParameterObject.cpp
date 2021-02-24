#include "umlReflectionExec/OperationTemplateParameterObject.hpp"

//General Includes
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/OperationTemplateParameter.hpp"
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
#include "uml/Operation.hpp"
#include "umlReflectionExec/OperationObject.hpp"
#include "uml/ParameterableElement.hpp"
#include "umlReflectionExec/ParameterableElementObject.hpp"
#include "uml/ParameterableElement.hpp"
#include "umlReflectionExec/ParameterableElementObject.hpp"
#include "uml/ParameterableElement.hpp"
#include "umlReflectionExec/ParameterableElementObject.hpp"
#include "uml/ParameterableElement.hpp"
#include "umlReflectionExec/ParameterableElementObject.hpp"
#include "uml/TemplateSignature.hpp"
#include "umlReflectionExec/TemplateSignatureObject.hpp"
//Property Packages Includes


using namespace UML;

OperationTemplateParameterObject::OperationTemplateParameterObject(std::shared_ptr<uml::OperationTemplateParameter> _element):

	m_OperationTemplateParameterValue(_element)
{		
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_OperationTemplateParameter());
}

OperationTemplateParameterObject::OperationTemplateParameterObject(OperationTemplateParameterObject &obj):
	CS_ObjectImpl(obj)
{
}

OperationTemplateParameterObject::OperationTemplateParameterObject()
{	
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_OperationTemplateParameter());
}

OperationTemplateParameterObject::~OperationTemplateParameterObject()
{
}

std::shared_ptr<ecore::EObject> OperationTemplateParameterObject::copy()
{
	std::shared_ptr<OperationTemplateParameterObject> element(new OperationTemplateParameterObject(*this));
	element->setThisOperationTemplateParameterObjectPtr(element);
	return element;
}

void OperationTemplateParameterObject::destroy()
{	
	m_OperationTemplateParameterValue.reset();

	fUML::Semantics::StructuredClassifiers::ObjectImpl::destroy();
}

std::shared_ptr<uml::Element> OperationTemplateParameterObject::getUmlValue() const
{
	return getOperationTemplateParameterValue();
}

std::shared_ptr<uml::OperationTemplateParameter> OperationTemplateParameterObject::getOperationTemplateParameterValue() const
{
	return m_OperationTemplateParameterValue;
}

void OperationTemplateParameterObject::setUmlValue(std::shared_ptr<uml::Element> _element)
{
	setOperationTemplateParameterValue(std::dynamic_pointer_cast<uml::OperationTemplateParameter>(_element));
}

void OperationTemplateParameterObject::setOperationTemplateParameterValue(std::shared_ptr<uml::OperationTemplateParameter> _OperationTemplateParameterElement)
{
	m_OperationTemplateParameterValue = _OperationTemplateParameterElement;
	//set super type values
	UML::TemplateParameterObject::setTemplateParameterValue(_OperationTemplateParameterElement);
}

void OperationTemplateParameterObject::setThisOperationTemplateParameterObjectPtr(std::weak_ptr<OperationTemplateParameterObject> thisObjectPtr)
{
	setThisCS_ObjectPtr(thisObjectPtr);
}

bool OperationTemplateParameterObject::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	bool isEqual = false;
	
	std::shared_ptr<OperationTemplateParameterObject> otherOperationTemplateParameterObject = std::dynamic_pointer_cast<OperationTemplateParameterObject>(otherValue);

	if(otherOperationTemplateParameterObject != nullptr)
	{
		if(this->getOperationTemplateParameterValue() == otherOperationTemplateParameterObject->getOperationTemplateParameterValue())
		{
			isEqual = true;
		}
	}

	return isEqual;
}

std::string OperationTemplateParameterObject::toString()
{
	std::string buffer = "Instance of 'OperationTemplateParameterObject', " + std::to_string(getTypes()->size()) + " types (";
	for(unsigned int i = 0; i < getTypes()->size(); ++i)
	{
		buffer += "type{" + std::to_string(i) + "}: '" + getTypes()->at(i)->getName() + "', ";
	}
	buffer +=")";

	return buffer;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> OperationTemplateParameterObject::getDirectContainers()
{   
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());

	/*Not done for metamodel object classes*/

	return directContainers;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> OperationTemplateParameterObject::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> allLinks(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());

	/*Not done for metamodel object classes*/

	return allLinks;
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> OperationTemplateParameterObject::retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end)
{
	/*Not done for metamodel object classes*/

	return nullptr;
}

void OperationTemplateParameterObject::removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_OperationTemplateParameterValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside OperationTemplateParameterObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		if (value == nullptr) // clear mode
		{
			m_OperationTemplateParameterValue->getOwnedComment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CommentObject> inputValue = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_OperationTemplateParameterValue->getOwnedComment()->erase(inputValue->getCommentValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_OperationTemplateParameter_parameteredElement())
	{
				m_OperationTemplateParameterValue->getParameteredElement().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_default())
	{
				m_OperationTemplateParameterValue->getDefault().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedDefault())
	{
				m_OperationTemplateParameterValue->getOwnedDefault().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedParameteredElement())
	{
				m_OperationTemplateParameterValue->getOwnedParameteredElement().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_parameteredElement())
	{
				m_OperationTemplateParameterValue->getParameteredElement().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_signature())
	{
				m_OperationTemplateParameterValue->getSignature().reset();

	}
}


std::shared_ptr<Bag<fUML::Semantics::Values::Value>> OperationTemplateParameterObject::getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_OperationTemplateParameterValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside OperationTemplateParameterObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		std::shared_ptr<Bag<uml::Comment>> ownedCommentList = m_OperationTemplateParameterValue->getOwnedComment();
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
		std::shared_ptr<Bag<uml::Element>> ownedElementList = m_OperationTemplateParameterValue->getOwnedElement();
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
		value->setElementValue(m_OperationTemplateParameterValue->getOwner().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_OperationTemplateParameter_parameteredElement())
	{
		std::shared_ptr<UML::OperationObject> value(new UML::OperationObject());
		value->setThisOperationObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setOperationValue(std::dynamic_pointer_cast<uml::Operation>(m_OperationTemplateParameterValue->getParameteredElement()));
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_default())
	{
		std::shared_ptr<UML::ParameterableElementObject> value(new UML::ParameterableElementObject());
		value->setThisParameterableElementObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setParameterableElementValue(m_OperationTemplateParameterValue->getDefault());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedDefault())
	{
		std::shared_ptr<UML::ParameterableElementObject> value(new UML::ParameterableElementObject());
		value->setThisParameterableElementObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setParameterableElementValue(m_OperationTemplateParameterValue->getOwnedDefault());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedParameteredElement())
	{
		std::shared_ptr<UML::ParameterableElementObject> value(new UML::ParameterableElementObject());
		value->setThisParameterableElementObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setParameterableElementValue(m_OperationTemplateParameterValue->getOwnedParameteredElement());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_parameteredElement())
	{
		std::shared_ptr<UML::ParameterableElementObject> value(new UML::ParameterableElementObject());
		value->setThisParameterableElementObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setParameterableElementValue(m_OperationTemplateParameterValue->getParameteredElement());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_signature())
	{
		std::shared_ptr<UML::TemplateSignatureObject> value(new UML::TemplateSignatureObject());
		value->setThisTemplateSignatureObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setTemplateSignatureValue(m_OperationTemplateParameterValue->getSignature().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	return values;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> OperationTemplateParameterObject::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
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


void OperationTemplateParameterObject::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_OperationTemplateParameterValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside OperationTemplateParameterObject (property: " << feature->getName() << ")" << std::endl;
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
		m_OperationTemplateParameterValue->getOwnedComment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CommentObject> value = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_OperationTemplateParameterValue->getOwnedComment()->push_back(value->getCommentValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_OperationTemplateParameter_parameteredElement())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::OperationObject> value = std::dynamic_pointer_cast<UML::OperationObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_OperationTemplateParameterValue->setParameteredElement(value->getOperationValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_default())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ParameterableElementObject> value = std::dynamic_pointer_cast<UML::ParameterableElementObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_OperationTemplateParameterValue->setDefault(value->getParameterableElementValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedDefault())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ParameterableElementObject> value = std::dynamic_pointer_cast<UML::ParameterableElementObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_OperationTemplateParameterValue->setOwnedDefault(value->getParameterableElementValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedParameteredElement())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ParameterableElementObject> value = std::dynamic_pointer_cast<UML::ParameterableElementObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_OperationTemplateParameterValue->setOwnedParameteredElement(value->getParameterableElementValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_parameteredElement())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ParameterableElementObject> value = std::dynamic_pointer_cast<UML::ParameterableElementObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_OperationTemplateParameterValue->setParameteredElement(value->getParameterableElementValue());
		}
		
	}
}

void OperationTemplateParameterObject::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	this->setFeatureValue(feature, values, position);
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> OperationTemplateParameterObject::retrieveFeatureValues()
{
	std::shared_ptr<uml::Classifier> type = this->getTypes()->at(0);
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAllAttributes();
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	
	unsigned int allAttributesSize = allAttributes->size();

	for(unsigned int i = 0; i < allAttributesSize; i++)
	{
		std::shared_ptr<uml::Property> property = allAttributes->at(i);
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment() && m_OperationTemplateParameterValue->getOwnedComment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement() && m_OperationTemplateParameterValue->getOwnedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_owner() && m_OperationTemplateParameterValue->getOwner().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_OperationTemplateParameter_parameteredElement() && m_OperationTemplateParameterValue->getParameteredElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_default() && m_OperationTemplateParameterValue->getDefault() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedDefault() && m_OperationTemplateParameterValue->getOwnedDefault() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedParameteredElement() && m_OperationTemplateParameterValue->getOwnedParameteredElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_parameteredElement() && m_OperationTemplateParameterValue->getParameteredElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_signature() && m_OperationTemplateParameterValue->getSignature().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
	}
	
	return featureValues;
}

