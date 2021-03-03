#include "umlReflectionExec/ClassifierTemplateParameterObject.hpp"

//General Includes
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/ClassifierTemplateParameter.hpp"
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
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/Classifier.hpp"
#include "umlReflectionExec/ClassifierObject.hpp"
#include "uml/Classifier.hpp"
#include "umlReflectionExec/ClassifierObject.hpp"
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
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"


using namespace UML;

ClassifierTemplateParameterObject::ClassifierTemplateParameterObject(std::shared_ptr<uml::ClassifierTemplateParameter> _element):
	m_ClassifierTemplateParameterValue(_element)
{
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_ClassifierTemplateParameter());
}

ClassifierTemplateParameterObject::ClassifierTemplateParameterObject(ClassifierTemplateParameterObject &obj):
	CS_ObjectImpl(obj)
{
	*this = obj;
}

ClassifierTemplateParameterObject::ClassifierTemplateParameterObject()
{	
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_ClassifierTemplateParameter());
}

ClassifierTemplateParameterObject::~ClassifierTemplateParameterObject()
{
}

std::shared_ptr<ecore::EObject> ClassifierTemplateParameterObject::copy()
{
	std::shared_ptr<ClassifierTemplateParameterObject> element(new ClassifierTemplateParameterObject());
	*element=(*this);
	element->setThisClassifierTemplateParameterObjectPtr(element);
	return element;
}

ClassifierTemplateParameterObject& ClassifierTemplateParameterObject::operator=(const ClassifierTemplateParameterObject & obj)
{
	UML::TemplateParameterObject::operator=(obj);
	return *this;
}


void ClassifierTemplateParameterObject::destroy()
{	
	m_ClassifierTemplateParameterValue.reset();

	fUML::Semantics::StructuredClassifiers::ObjectImpl::destroy();
}

std::shared_ptr<uml::Element> ClassifierTemplateParameterObject::getUmlValue() const
{
	return getClassifierTemplateParameterValue();
}

std::shared_ptr<uml::ClassifierTemplateParameter> ClassifierTemplateParameterObject::getClassifierTemplateParameterValue() const
{
	return m_ClassifierTemplateParameterValue;
}

void ClassifierTemplateParameterObject::setUmlValue(std::shared_ptr<uml::Element> _element)
{
	setClassifierTemplateParameterValue(std::dynamic_pointer_cast<uml::ClassifierTemplateParameter>(_element));
}

void ClassifierTemplateParameterObject::setClassifierTemplateParameterValue(std::shared_ptr<uml::ClassifierTemplateParameter> _ClassifierTemplateParameterElement)
{
	m_ClassifierTemplateParameterValue = _ClassifierTemplateParameterElement;
	//set super type values
	UML::TemplateParameterObject::setTemplateParameterValue(_ClassifierTemplateParameterElement);
}

void ClassifierTemplateParameterObject::setThisClassifierTemplateParameterObjectPtr(std::weak_ptr<ClassifierTemplateParameterObject> thisObjectPtr)
{
	setThisCS_ObjectPtr(thisObjectPtr);
}

bool ClassifierTemplateParameterObject::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	bool isEqual = false;
	
	std::shared_ptr<ClassifierTemplateParameterObject> otherClassifierTemplateParameterObject = std::dynamic_pointer_cast<ClassifierTemplateParameterObject>(otherValue);

	if(otherClassifierTemplateParameterObject != nullptr)
	{
		if(this->getClassifierTemplateParameterValue() == otherClassifierTemplateParameterObject->getClassifierTemplateParameterValue())
		{
			isEqual = true;
		}
	}

	return isEqual;
}

std::string ClassifierTemplateParameterObject::toString()
{
	std::string buffer = "Instance of 'ClassifierTemplateParameterObject', " + std::to_string(getTypes()->size()) + " types (";
	for(unsigned int i = 0; i < getTypes()->size(); ++i)
	{
		buffer += "type{" + std::to_string(i) + "}: '" + getTypes()->at(i)->getName() + "', ";
	}
	buffer +=")";

	return buffer;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> ClassifierTemplateParameterObject::getDirectContainers()
{   
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());

	/*Not done for metamodel object classes*/

	return directContainers;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> ClassifierTemplateParameterObject::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> allLinks(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());

	/*Not done for metamodel object classes*/

	return allLinks;
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ClassifierTemplateParameterObject::retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end)
{
	/*Not done for metamodel object classes*/

	return nullptr;
}

void ClassifierTemplateParameterObject::removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ClassifierTemplateParameterValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ClassifierTemplateParameterObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (feature == UML::UMLPackage::eInstance()->get_UML_ClassifierTemplateParameter_allowSubstitutable())
	{
				m_ClassifierTemplateParameterValue->setAllowSubstitutable(true /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ClassifierTemplateParameter_constrainingClassifier())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassifierTemplateParameterValue->getConstrainingClassifier()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ClassifierObject> inputValue = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassifierTemplateParameterValue->getConstrainingClassifier()->erase(inputValue->getClassifierValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ClassifierTemplateParameter_parameteredElement())
	{
				m_ClassifierTemplateParameterValue->getParameteredElement().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassifierTemplateParameterValue->getOwnedComment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CommentObject> inputValue = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassifierTemplateParameterValue->getOwnedComment()->erase(inputValue->getCommentValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_default())
	{
				m_ClassifierTemplateParameterValue->getDefault().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedDefault())
	{
				m_ClassifierTemplateParameterValue->getOwnedDefault().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedParameteredElement())
	{
				m_ClassifierTemplateParameterValue->getOwnedParameteredElement().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_parameteredElement())
	{
				m_ClassifierTemplateParameterValue->getParameteredElement().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_signature())
	{
				m_ClassifierTemplateParameterValue->getSignature().reset();

	}
}


std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ClassifierTemplateParameterObject::getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ClassifierTemplateParameterValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ClassifierTemplateParameterObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
	if (feature == UML::UMLPackage::eInstance()->get_UML_ClassifierTemplateParameter_allowSubstitutable())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ClassifierTemplateParameterValue->getAllowSubstitutable());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ClassifierTemplateParameter_constrainingClassifier())
	{
		std::shared_ptr<Bag<uml::Classifier>> constrainingClassifierList = m_ClassifierTemplateParameterValue->getConstrainingClassifier();
		Bag<uml::Classifier>::iterator iter = constrainingClassifierList->begin();
		Bag<uml::Classifier>::iterator end = constrainingClassifierList->end();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_ClassifierTemplateParameter_parameteredElement())
	{
		std::shared_ptr<UML::ClassifierObject> value(new UML::ClassifierObject());
		value->setThisClassifierObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setClassifierValue(std::dynamic_pointer_cast<uml::Classifier>(m_ClassifierTemplateParameterValue->getParameteredElement()));
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		std::shared_ptr<Bag<uml::Comment>> ownedCommentList = m_ClassifierTemplateParameterValue->getOwnedComment();
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
		std::shared_ptr<Bag<uml::Element>> ownedElementList = m_ClassifierTemplateParameterValue->getOwnedElement();
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
		value->setElementValue(m_ClassifierTemplateParameterValue->getOwner().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_default())
	{
		std::shared_ptr<UML::ParameterableElementObject> value(new UML::ParameterableElementObject());
		value->setThisParameterableElementObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setParameterableElementValue(m_ClassifierTemplateParameterValue->getDefault());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedDefault())
	{
		std::shared_ptr<UML::ParameterableElementObject> value(new UML::ParameterableElementObject());
		value->setThisParameterableElementObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setParameterableElementValue(m_ClassifierTemplateParameterValue->getOwnedDefault());
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
		value->setParameterableElementValue(m_ClassifierTemplateParameterValue->getOwnedParameteredElement());
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
		value->setParameterableElementValue(m_ClassifierTemplateParameterValue->getParameteredElement());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_signature())
	{
		std::shared_ptr<UML::TemplateSignatureObject> value(new UML::TemplateSignatureObject());
		value->setThisTemplateSignatureObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setTemplateSignatureValue(m_ClassifierTemplateParameterValue->getSignature().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	return values;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> ClassifierTemplateParameterObject::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
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


void ClassifierTemplateParameterObject::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ClassifierTemplateParameterValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ClassifierTemplateParameterObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (values->size() == 0)
	{
		std::cout << __PRETTY_FUNCTION__ << ": no input value given" << std::endl;
		return;
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ClassifierTemplateParameter_allowSubstitutable())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ClassifierTemplateParameterValue->setAllowSubstitutable(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ClassifierTemplateParameter_constrainingClassifier())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassifierTemplateParameterValue->getConstrainingClassifier()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ClassifierObject> value = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassifierTemplateParameterValue->getConstrainingClassifier()->push_back(value->getClassifierValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ClassifierTemplateParameter_parameteredElement())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ClassifierObject> value = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ClassifierTemplateParameterValue->setParameteredElement(value->getClassifierValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassifierTemplateParameterValue->getOwnedComment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CommentObject> value = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassifierTemplateParameterValue->getOwnedComment()->push_back(value->getCommentValue());
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
			m_ClassifierTemplateParameterValue->setDefault(value->getParameterableElementValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedDefault())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ParameterableElementObject> value = std::dynamic_pointer_cast<UML::ParameterableElementObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ClassifierTemplateParameterValue->setOwnedDefault(value->getParameterableElementValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedParameteredElement())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ParameterableElementObject> value = std::dynamic_pointer_cast<UML::ParameterableElementObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ClassifierTemplateParameterValue->setOwnedParameteredElement(value->getParameterableElementValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_parameteredElement())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ParameterableElementObject> value = std::dynamic_pointer_cast<UML::ParameterableElementObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ClassifierTemplateParameterValue->setParameteredElement(value->getParameterableElementValue());
		}
		
	}
}

void ClassifierTemplateParameterObject::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	this->setFeatureValue(feature, values, position);
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> ClassifierTemplateParameterObject::retrieveFeatureValues()
{
	std::shared_ptr<uml::Classifier> type = this->getTypes()->at(0);
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAllAttributes();
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	
	unsigned int allAttributesSize = allAttributes->size();

	for(unsigned int i = 0; i < allAttributesSize; i++)
	{
		std::shared_ptr<uml::Property> property = allAttributes->at(i);
		if (property == UML::UMLPackage::eInstance()->get_UML_ClassifierTemplateParameter_constrainingClassifier() && m_ClassifierTemplateParameterValue->getConstrainingClassifier() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ClassifierTemplateParameter_parameteredElement() && m_ClassifierTemplateParameterValue->getParameteredElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment() && m_ClassifierTemplateParameterValue->getOwnedComment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement() && m_ClassifierTemplateParameterValue->getOwnedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_owner() && m_ClassifierTemplateParameterValue->getOwner().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_default() && m_ClassifierTemplateParameterValue->getDefault() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedDefault() && m_ClassifierTemplateParameterValue->getOwnedDefault() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_ownedParameteredElement() && m_ClassifierTemplateParameterValue->getOwnedParameteredElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_parameteredElement() && m_ClassifierTemplateParameterValue->getParameteredElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateParameter_signature() && m_ClassifierTemplateParameterValue->getSignature().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
	}
	
	return featureValues;
}

