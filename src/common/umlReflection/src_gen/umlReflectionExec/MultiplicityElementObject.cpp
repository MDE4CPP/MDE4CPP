#include "umlReflectionExec/MultiplicityElementObject.hpp"

//General Includes
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/MultiplicityElement.hpp"
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
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/IntegerValue.hpp"
#include "uml/ValueSpecification.hpp"
#include "umlReflectionExec/ValueSpecificationObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/UnlimitedNaturalValue.hpp"
#include "uml/ValueSpecification.hpp"
#include "umlReflectionExec/ValueSpecificationObject.hpp"
//Property Packages Includes
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"


using namespace UML;

MultiplicityElementObject::MultiplicityElementObject(std::shared_ptr<uml::MultiplicityElement> _element):

	m_MultiplicityElementValue(_element)
{		
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_MultiplicityElement());
}

MultiplicityElementObject::MultiplicityElementObject(MultiplicityElementObject &obj):
	CS_ObjectImpl(obj)
{
}

MultiplicityElementObject::MultiplicityElementObject()
{	
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_MultiplicityElement());
}

MultiplicityElementObject::~MultiplicityElementObject()
{
}

std::shared_ptr<ecore::EObject> MultiplicityElementObject::copy()
{
	std::shared_ptr<MultiplicityElementObject> element(new MultiplicityElementObject(*this));
	element->setThisMultiplicityElementObjectPtr(element);
	return element;
}

void MultiplicityElementObject::destroy()
{	
	m_MultiplicityElementValue.reset();

	fUML::Semantics::StructuredClassifiers::ObjectImpl::destroy();
}

std::shared_ptr<uml::Element> MultiplicityElementObject::getUmlValue() const
{
	return getMultiplicityElementValue();
}

std::shared_ptr<uml::MultiplicityElement> MultiplicityElementObject::getMultiplicityElementValue() const
{
	return m_MultiplicityElementValue;
}

void MultiplicityElementObject::setUmlValue(std::shared_ptr<uml::Element> _element)
{
	setMultiplicityElementValue(std::dynamic_pointer_cast<uml::MultiplicityElement>(_element));
}

void MultiplicityElementObject::setMultiplicityElementValue(std::shared_ptr<uml::MultiplicityElement> _MultiplicityElementElement)
{
	m_MultiplicityElementValue = _MultiplicityElementElement;
	//set super type values
	UML::ElementObject::setElementValue(_MultiplicityElementElement);
}

void MultiplicityElementObject::setThisMultiplicityElementObjectPtr(std::weak_ptr<MultiplicityElementObject> thisObjectPtr)
{
	setThisCS_ObjectPtr(thisObjectPtr);
}

bool MultiplicityElementObject::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	bool isEqual = false;
	
	std::shared_ptr<MultiplicityElementObject> otherMultiplicityElementObject = std::dynamic_pointer_cast<MultiplicityElementObject>(otherValue);

	if(otherMultiplicityElementObject != nullptr)
	{
		if(this->getMultiplicityElementValue() == otherMultiplicityElementObject->getMultiplicityElementValue())
		{
			isEqual = true;
		}
	}

	return isEqual;
}

std::string MultiplicityElementObject::toString()
{
	std::string buffer = "Instance of 'MultiplicityElementObject', " + std::to_string(getTypes()->size()) + " types (";
	for(unsigned int i = 0; i < getTypes()->size(); ++i)
	{
		buffer += "type{" + std::to_string(i) + "}: '" + getTypes()->at(i)->getName() + "', ";
	}
	buffer +=")";

	return buffer;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> MultiplicityElementObject::getDirectContainers()
{   
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());

	/*Not done for metamodel object classes*/

	return directContainers;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> MultiplicityElementObject::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> allLinks(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());

	/*Not done for metamodel object classes*/

	return allLinks;
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> MultiplicityElementObject::retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end)
{
	/*Not done for metamodel object classes*/

	return nullptr;
}

void MultiplicityElementObject::removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_MultiplicityElementValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside MultiplicityElementObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		if (value == nullptr) // clear mode
		{
			m_MultiplicityElementValue->getOwnedComment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CommentObject> inputValue = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_MultiplicityElementValue->getOwnedComment()->erase(inputValue->getCommentValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_isOrdered())
	{
				m_MultiplicityElementValue->setIsOrdered(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_isUnique())
	{
				m_MultiplicityElementValue->setIsUnique(true /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_lower())
	{
				m_MultiplicityElementValue->setLower(1 /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_lowerValue())
	{
				m_MultiplicityElementValue->getLowerValue().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_upper())
	{
				m_MultiplicityElementValue->setUpper(1 /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_upperValue())
	{
				m_MultiplicityElementValue->getUpperValue().reset();

	}
}


std::shared_ptr<Bag<fUML::Semantics::Values::Value>> MultiplicityElementObject::getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_MultiplicityElementValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside MultiplicityElementObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		std::shared_ptr<Bag<uml::Comment>> ownedCommentList = m_MultiplicityElementValue->getOwnedComment();
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
		std::shared_ptr<Bag<uml::Element>> ownedElementList = m_MultiplicityElementValue->getOwnedElement();
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
		value->setElementValue(m_MultiplicityElementValue->getOwner().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_isOrdered())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_MultiplicityElementValue->getIsOrdered());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_isUnique())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_MultiplicityElementValue->getIsUnique());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_lower())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
		value->setValue(m_MultiplicityElementValue->getLower());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_lowerValue())
	{
		std::shared_ptr<UML::ValueSpecificationObject> value(new UML::ValueSpecificationObject());
		value->setThisValueSpecificationObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setValueSpecificationValue(m_MultiplicityElementValue->getLowerValue());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_upper())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createUnlimitedNaturalValue();
		value->setValue(m_MultiplicityElementValue->getUpper());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_upperValue())
	{
		std::shared_ptr<UML::ValueSpecificationObject> value(new UML::ValueSpecificationObject());
		value->setThisValueSpecificationObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setValueSpecificationValue(m_MultiplicityElementValue->getUpperValue());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	return values;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> MultiplicityElementObject::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
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


void MultiplicityElementObject::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_MultiplicityElementValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside MultiplicityElementObject (property: " << feature->getName() << ")" << std::endl;
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
		m_MultiplicityElementValue->getOwnedComment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CommentObject> value = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_MultiplicityElementValue->getOwnedComment()->push_back(value->getCommentValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_isOrdered())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_MultiplicityElementValue->setIsOrdered(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_isUnique())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_MultiplicityElementValue->setIsUnique(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_lower())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::IntegerValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_MultiplicityElementValue->setLower(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_lowerValue())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ValueSpecificationObject> value = std::dynamic_pointer_cast<UML::ValueSpecificationObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_MultiplicityElementValue->setLowerValue(value->getValueSpecificationValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_upper())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_MultiplicityElementValue->setUpper(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_upperValue())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ValueSpecificationObject> value = std::dynamic_pointer_cast<UML::ValueSpecificationObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_MultiplicityElementValue->setUpperValue(value->getValueSpecificationValue());
		}
		
	}
}

void MultiplicityElementObject::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	this->setFeatureValue(feature, values, position);
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> MultiplicityElementObject::retrieveFeatureValues()
{
	std::shared_ptr<uml::Classifier> type = this->getTypes()->at(0);
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAllAttributes();
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	
	unsigned int allAttributesSize = allAttributes->size();

	for(unsigned int i = 0; i < allAttributesSize; i++)
	{
		std::shared_ptr<uml::Property> property = allAttributes->at(i);
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment() && m_MultiplicityElementValue->getOwnedComment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement() && m_MultiplicityElementValue->getOwnedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_owner() && m_MultiplicityElementValue->getOwner().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_lowerValue() && m_MultiplicityElementValue->getLowerValue() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_upperValue() && m_MultiplicityElementValue->getUpperValue() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
	}
	
	return featureValues;
}

