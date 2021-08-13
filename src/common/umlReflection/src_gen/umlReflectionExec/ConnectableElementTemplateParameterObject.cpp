#include "umlReflectionExec/ConnectableElementTemplateParameterObject.hpp"

//General Includes
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/ConnectableElementTemplateParameter.hpp"
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
#include "uml/ConnectableElement.hpp"
#include "umlReflectionExec/ConnectableElementObject.hpp"
#include "uml/Comment.hpp"
#include "umlReflectionExec/CommentObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
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

ConnectableElementTemplateParameterObject::ConnectableElementTemplateParameterObject(std::shared_ptr<uml::ConnectableElementTemplateParameter> _element):
	m_ConnectableElementTemplateParameterValue(_element)
{
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_ConnectableElementTemplateParameter());
}

ConnectableElementTemplateParameterObject::ConnectableElementTemplateParameterObject(ConnectableElementTemplateParameterObject &obj):
	CS_ObjectImpl(obj)
{
	*this = obj;
}

ConnectableElementTemplateParameterObject::ConnectableElementTemplateParameterObject()
{	
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_ConnectableElementTemplateParameter());
}

ConnectableElementTemplateParameterObject::~ConnectableElementTemplateParameterObject()
{
}

std::shared_ptr<ecore::EObject> ConnectableElementTemplateParameterObject::copy()
{
	std::shared_ptr<ConnectableElementTemplateParameterObject> element(new ConnectableElementTemplateParameterObject());
	*element=(*this);
	element->setThisConnectableElementTemplateParameterObjectPtr(element);
	return element;
}

ConnectableElementTemplateParameterObject& ConnectableElementTemplateParameterObject::operator=(const ConnectableElementTemplateParameterObject & obj)
{
	UML::TemplateParameterObject::operator=(obj);
	return *this;
}


void ConnectableElementTemplateParameterObject::destroy()
{	
	m_ConnectableElementTemplateParameterValue.reset();

	fUML::Semantics::StructuredClassifiers::ObjectImpl::destroy();
}

std::shared_ptr<uml::Element> ConnectableElementTemplateParameterObject::getUmlValue() const
{
	return getConnectableElementTemplateParameterValue();
}

std::shared_ptr<uml::ConnectableElementTemplateParameter> ConnectableElementTemplateParameterObject::getConnectableElementTemplateParameterValue() const
{
	return m_ConnectableElementTemplateParameterValue;
}

void ConnectableElementTemplateParameterObject::setUmlValue(std::shared_ptr<uml::Element> _element)
{
	setConnectableElementTemplateParameterValue(std::dynamic_pointer_cast<uml::ConnectableElementTemplateParameter>(_element));
}

void ConnectableElementTemplateParameterObject::setConnectableElementTemplateParameterValue(std::shared_ptr<uml::ConnectableElementTemplateParameter> _ConnectableElementTemplateParameterElement)
{
	m_ConnectableElementTemplateParameterValue = _ConnectableElementTemplateParameterElement;
	//set super type values
	UML::TemplateParameterObject::setTemplateParameterValue(_ConnectableElementTemplateParameterElement);
}

void ConnectableElementTemplateParameterObject::setThisConnectableElementTemplateParameterObjectPtr(std::weak_ptr<ConnectableElementTemplateParameterObject> thisObjectPtr)
{
	setThisCS_ObjectPtr(thisObjectPtr);
}

bool ConnectableElementTemplateParameterObject::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	bool isEqual = false;
	
	std::shared_ptr<ConnectableElementTemplateParameterObject> otherConnectableElementTemplateParameterObject = std::dynamic_pointer_cast<ConnectableElementTemplateParameterObject>(otherValue);

	if(otherConnectableElementTemplateParameterObject != nullptr)
	{
		if(this->getConnectableElementTemplateParameterValue() == otherConnectableElementTemplateParameterObject->getConnectableElementTemplateParameterValue())
		{
			isEqual = true;
		}
	}

	return isEqual;
}

std::string ConnectableElementTemplateParameterObject::toString()
{
	std::string buffer = "Instance of 'ConnectableElementTemplateParameterObject', " + std::to_string(getTypes()->size()) + " types (";
	for(unsigned int i = 0; i < getTypes()->size(); ++i)
	{
		buffer += "type{" + std::to_string(i) + "}: '" + getTypes()->at(i)->getName() + "', ";
	}
	buffer +=")";

	return buffer;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> ConnectableElementTemplateParameterObject::getDirectContainers()
{   
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());

	/*Not done for metamodel object classes*/

	return directContainers;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> ConnectableElementTemplateParameterObject::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> allLinks(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());

	/*Not done for metamodel object classes*/

	return allLinks;
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ConnectableElementTemplateParameterObject::retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end)
{
	/*Not done for metamodel object classes*/

	return nullptr;
}

void ConnectableElementTemplateParameterObject::removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ConnectableElementTemplateParameterValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ConnectableElementTemplateParameterObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (feature == UML::UMLPackage::eInstance()->get_UML_ConnectableElementTemplateParameter_parameteredElement())
	{
				m_ConnectableElementTemplateParameterValue->getParameteredElement().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		if (value == nullptr) // clear mode
		{
			m_ConnectableElementTemplateParameterValue->getOwnedComment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CommentObject> inputValue = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ConnectableElementTemplateParameterValue->getOwnedComment()->erase(inputValue->getCommentValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_default())
	{
				m_ConnectableElementTemplateParameterValue->getDefault().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedDefault())
	{
				m_ConnectableElementTemplateParameterValue->getOwnedDefault().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedParameteredElement())
	{
				m_ConnectableElementTemplateParameterValue->getOwnedParameteredElement().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_parameteredElement())
	{
				m_ConnectableElementTemplateParameterValue->getParameteredElement().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_signature())
	{
				m_ConnectableElementTemplateParameterValue->getSignature().reset();

	}
}


std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ConnectableElementTemplateParameterObject::getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ConnectableElementTemplateParameterValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ConnectableElementTemplateParameterObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
	if (feature == UML::UMLPackage::eInstance()->get_UML_ConnectableElementTemplateParameter_parameteredElement())
	{
		std::shared_ptr<UML::ConnectableElementObject> value(new UML::ConnectableElementObject());
		value->setThisConnectableElementObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setConnectableElementValue(std::dynamic_pointer_cast<uml::ConnectableElement>(m_ConnectableElementTemplateParameterValue->getParameteredElement()));
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		std::shared_ptr<Subset<uml::Comment, uml::Element>> ownedCommentList = m_ConnectableElementTemplateParameterValue->getOwnedComment();
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
		std::shared_ptr<Union<uml::Element>> ownedElementList = m_ConnectableElementTemplateParameterValue->getOwnedElement();
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
		value->setElementValue(m_ConnectableElementTemplateParameterValue->getOwner().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_default())
	{
		std::shared_ptr<UML::ParameterableElementObject> value(new UML::ParameterableElementObject());
		value->setThisParameterableElementObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setParameterableElementValue(m_ConnectableElementTemplateParameterValue->getDefault());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedDefault())
	{
		std::shared_ptr<UML::ParameterableElementObject> value(new UML::ParameterableElementObject());
		value->setThisParameterableElementObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setParameterableElementValue(m_ConnectableElementTemplateParameterValue->getOwnedDefault());
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
		value->setParameterableElementValue(m_ConnectableElementTemplateParameterValue->getOwnedParameteredElement());
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
		value->setParameterableElementValue(m_ConnectableElementTemplateParameterValue->getParameteredElement());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_signature())
	{
		std::shared_ptr<UML::TemplateSignatureObject> value(new UML::TemplateSignatureObject());
		value->setThisTemplateSignatureObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setTemplateSignatureValue(m_ConnectableElementTemplateParameterValue->getSignature().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	return values;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> ConnectableElementTemplateParameterObject::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
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


void ConnectableElementTemplateParameterObject::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ConnectableElementTemplateParameterValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ConnectableElementTemplateParameterObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (values->size() == 0)
	{
		std::cout << __PRETTY_FUNCTION__ << ": no input value given" << std::endl;
		return;
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ConnectableElementTemplateParameter_parameteredElement())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ConnectableElementObject> value = std::dynamic_pointer_cast<UML::ConnectableElementObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ConnectableElementTemplateParameterValue->setParameteredElement(value->getConnectableElementValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ConnectableElementTemplateParameterValue->getOwnedComment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CommentObject> value = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ConnectableElementTemplateParameterValue->getOwnedComment()->push_back(value->getCommentValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_default())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ParameterableElementObject> value = std::dynamic_pointer_cast<UML::ParameterableElementObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ConnectableElementTemplateParameterValue->setDefault(value->getParameterableElementValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedDefault())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ParameterableElementObject> value = std::dynamic_pointer_cast<UML::ParameterableElementObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ConnectableElementTemplateParameterValue->setOwnedDefault(value->getParameterableElementValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedParameteredElement())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ParameterableElementObject> value = std::dynamic_pointer_cast<UML::ParameterableElementObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ConnectableElementTemplateParameterValue->setOwnedParameteredElement(value->getParameterableElementValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_parameteredElement())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ParameterableElementObject> value = std::dynamic_pointer_cast<UML::ParameterableElementObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ConnectableElementTemplateParameterValue->setParameteredElement(value->getParameterableElementValue());
		}
		
	}
}

void ConnectableElementTemplateParameterObject::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	this->setFeatureValue(feature, values, position);
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> ConnectableElementTemplateParameterObject::retrieveFeatureValues()
{
	std::shared_ptr<uml::Classifier> type = this->getTypes()->at(0);
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAllAttributes();
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	
	unsigned int allAttributesSize = allAttributes->size();

	for(unsigned int i = 0; i < allAttributesSize; i++)
	{
		std::shared_ptr<uml::Property> property = allAttributes->at(i);
		if (property == UML::UMLPackage::eInstance()->get_UML_ConnectableElementTemplateParameter_parameteredElement() && m_ConnectableElementTemplateParameterValue->getParameteredElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment() && m_ConnectableElementTemplateParameterValue->getOwnedComment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement() && m_ConnectableElementTemplateParameterValue->getOwnedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_owner() && m_ConnectableElementTemplateParameterValue->getOwner().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_default() && m_ConnectableElementTemplateParameterValue->getDefault() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedDefault() && m_ConnectableElementTemplateParameterValue->getOwnedDefault() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedParameteredElement() && m_ConnectableElementTemplateParameterValue->getOwnedParameteredElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_parameteredElement() && m_ConnectableElementTemplateParameterValue->getParameteredElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_signature() && m_ConnectableElementTemplateParameterValue->getSignature().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
	}
	
	return featureValues;
}

