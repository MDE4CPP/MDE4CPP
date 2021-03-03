#include "umlReflectionExec/ClauseObject.hpp"

//General Includes
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/Clause.hpp"
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
#include "uml/ExecutableNode.hpp"
#include "umlReflectionExec/ExecutableNodeObject.hpp"
#include "uml/OutputPin.hpp"
#include "umlReflectionExec/OutputPinObject.hpp"
#include "uml/OutputPin.hpp"
#include "umlReflectionExec/OutputPinObject.hpp"
#include "uml/Clause.hpp"
#include "umlReflectionExec/ClauseObject.hpp"
#include "uml/Clause.hpp"
#include "umlReflectionExec/ClauseObject.hpp"
#include "uml/ExecutableNode.hpp"
#include "umlReflectionExec/ExecutableNodeObject.hpp"
#include "uml/Comment.hpp"
#include "umlReflectionExec/CommentObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
//Property Packages Includes


using namespace UML;

ClauseObject::ClauseObject(std::shared_ptr<uml::Clause> _element):
	m_ClauseValue(_element)
{
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_Clause());
}

ClauseObject::ClauseObject(ClauseObject &obj):
	CS_ObjectImpl(obj)
{
	*this = obj;
}

ClauseObject::ClauseObject()
{	
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_Clause());
}

ClauseObject::~ClauseObject()
{
}

std::shared_ptr<ecore::EObject> ClauseObject::copy()
{
	std::shared_ptr<ClauseObject> element(new ClauseObject());
	*element=(*this);
	element->setThisClauseObjectPtr(element);
	return element;
}

ClauseObject& ClauseObject::operator=(const ClauseObject & obj)
{
	UML::ElementObject::operator=(obj);
	return *this;
}


void ClauseObject::destroy()
{	
	m_ClauseValue.reset();

	fUML::Semantics::StructuredClassifiers::ObjectImpl::destroy();
}

std::shared_ptr<uml::Element> ClauseObject::getUmlValue() const
{
	return getClauseValue();
}

std::shared_ptr<uml::Clause> ClauseObject::getClauseValue() const
{
	return m_ClauseValue;
}

void ClauseObject::setUmlValue(std::shared_ptr<uml::Element> _element)
{
	setClauseValue(std::dynamic_pointer_cast<uml::Clause>(_element));
}

void ClauseObject::setClauseValue(std::shared_ptr<uml::Clause> _ClauseElement)
{
	m_ClauseValue = _ClauseElement;
	//set super type values
	UML::ElementObject::setElementValue(_ClauseElement);
}

void ClauseObject::setThisClauseObjectPtr(std::weak_ptr<ClauseObject> thisObjectPtr)
{
	setThisCS_ObjectPtr(thisObjectPtr);
}

bool ClauseObject::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	bool isEqual = false;
	
	std::shared_ptr<ClauseObject> otherClauseObject = std::dynamic_pointer_cast<ClauseObject>(otherValue);

	if(otherClauseObject != nullptr)
	{
		if(this->getClauseValue() == otherClauseObject->getClauseValue())
		{
			isEqual = true;
		}
	}

	return isEqual;
}

std::string ClauseObject::toString()
{
	std::string buffer = "Instance of 'ClauseObject', " + std::to_string(getTypes()->size()) + " types (";
	for(unsigned int i = 0; i < getTypes()->size(); ++i)
	{
		buffer += "type{" + std::to_string(i) + "}: '" + getTypes()->at(i)->getName() + "', ";
	}
	buffer +=")";

	return buffer;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> ClauseObject::getDirectContainers()
{   
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());

	/*Not done for metamodel object classes*/

	return directContainers;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> ClauseObject::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> allLinks(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());

	/*Not done for metamodel object classes*/

	return allLinks;
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ClauseObject::retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end)
{
	/*Not done for metamodel object classes*/

	return nullptr;
}

void ClauseObject::removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ClauseValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ClauseObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_body())
	{
		if (value == nullptr) // clear mode
		{
			m_ClauseValue->getBody()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ExecutableNodeObject> inputValue = std::dynamic_pointer_cast<UML::ExecutableNodeObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClauseValue->getBody()->erase(inputValue->getExecutableNodeValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_bodyOutput())
	{
		if (value == nullptr) // clear mode
		{
			m_ClauseValue->getBodyOutput()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::OutputPinObject> inputValue = std::dynamic_pointer_cast<UML::OutputPinObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClauseValue->getBodyOutput()->erase(inputValue->getOutputPinValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_decider())
	{
				m_ClauseValue->getDecider().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_predecessorClause())
	{
		if (value == nullptr) // clear mode
		{
			m_ClauseValue->getPredecessorClause()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ClauseObject> inputValue = std::dynamic_pointer_cast<UML::ClauseObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClauseValue->getPredecessorClause()->erase(inputValue->getClauseValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_successorClause())
	{
		if (value == nullptr) // clear mode
		{
			m_ClauseValue->getSuccessorClause()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ClauseObject> inputValue = std::dynamic_pointer_cast<UML::ClauseObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClauseValue->getSuccessorClause()->erase(inputValue->getClauseValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_test())
	{
		if (value == nullptr) // clear mode
		{
			m_ClauseValue->getTest()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ExecutableNodeObject> inputValue = std::dynamic_pointer_cast<UML::ExecutableNodeObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClauseValue->getTest()->erase(inputValue->getExecutableNodeValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		if (value == nullptr) // clear mode
		{
			m_ClauseValue->getOwnedComment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CommentObject> inputValue = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClauseValue->getOwnedComment()->erase(inputValue->getCommentValue());
			}
		}
	}
}


std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ClauseObject::getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ClauseValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ClauseObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_body())
	{
		std::shared_ptr<Bag<uml::ExecutableNode>> bodyList = m_ClauseValue->getBody();
		Bag<uml::ExecutableNode>::iterator iter = bodyList->begin();
		Bag<uml::ExecutableNode>::iterator end = bodyList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ExecutableNodeObject> value(new UML::ExecutableNodeObject());
			value->setThisExecutableNodeObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setExecutableNodeValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_bodyOutput())
	{
		std::shared_ptr<Bag<uml::OutputPin>> bodyOutputList = m_ClauseValue->getBodyOutput();
		Bag<uml::OutputPin>::iterator iter = bodyOutputList->begin();
		Bag<uml::OutputPin>::iterator end = bodyOutputList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::OutputPinObject> value(new UML::OutputPinObject());
			value->setThisOutputPinObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setOutputPinValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_decider())
	{
		std::shared_ptr<UML::OutputPinObject> value(new UML::OutputPinObject());
		value->setThisOutputPinObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setOutputPinValue(m_ClauseValue->getDecider());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_predecessorClause())
	{
		std::shared_ptr<Bag<uml::Clause>> predecessorClauseList = m_ClauseValue->getPredecessorClause();
		Bag<uml::Clause>::iterator iter = predecessorClauseList->begin();
		Bag<uml::Clause>::iterator end = predecessorClauseList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ClauseObject> value(new UML::ClauseObject());
			value->setThisClauseObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setClauseValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_successorClause())
	{
		std::shared_ptr<Bag<uml::Clause>> successorClauseList = m_ClauseValue->getSuccessorClause();
		Bag<uml::Clause>::iterator iter = successorClauseList->begin();
		Bag<uml::Clause>::iterator end = successorClauseList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ClauseObject> value(new UML::ClauseObject());
			value->setThisClauseObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setClauseValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_test())
	{
		std::shared_ptr<Bag<uml::ExecutableNode>> testList = m_ClauseValue->getTest();
		Bag<uml::ExecutableNode>::iterator iter = testList->begin();
		Bag<uml::ExecutableNode>::iterator end = testList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ExecutableNodeObject> value(new UML::ExecutableNodeObject());
			value->setThisExecutableNodeObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setExecutableNodeValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		std::shared_ptr<Bag<uml::Comment>> ownedCommentList = m_ClauseValue->getOwnedComment();
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
		std::shared_ptr<Bag<uml::Element>> ownedElementList = m_ClauseValue->getOwnedElement();
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
		value->setElementValue(m_ClauseValue->getOwner().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	return values;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> ClauseObject::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
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


void ClauseObject::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ClauseValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ClauseObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (values->size() == 0)
	{
		std::cout << __PRETTY_FUNCTION__ << ": no input value given" << std::endl;
		return;
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_body())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClauseValue->getBody()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ExecutableNodeObject> value = std::dynamic_pointer_cast<UML::ExecutableNodeObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClauseValue->getBody()->push_back(value->getExecutableNodeValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_bodyOutput())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClauseValue->getBodyOutput()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::OutputPinObject> value = std::dynamic_pointer_cast<UML::OutputPinObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClauseValue->getBodyOutput()->push_back(value->getOutputPinValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_decider())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::OutputPinObject> value = std::dynamic_pointer_cast<UML::OutputPinObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ClauseValue->setDecider(value->getOutputPinValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_predecessorClause())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClauseValue->getPredecessorClause()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ClauseObject> value = std::dynamic_pointer_cast<UML::ClauseObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClauseValue->getPredecessorClause()->push_back(value->getClauseValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_successorClause())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClauseValue->getSuccessorClause()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ClauseObject> value = std::dynamic_pointer_cast<UML::ClauseObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClauseValue->getSuccessorClause()->push_back(value->getClauseValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Clause_test())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClauseValue->getTest()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ExecutableNodeObject> value = std::dynamic_pointer_cast<UML::ExecutableNodeObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClauseValue->getTest()->push_back(value->getExecutableNodeValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClauseValue->getOwnedComment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CommentObject> value = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClauseValue->getOwnedComment()->push_back(value->getCommentValue());
			}
			
			iter++;
		}
	}
}

void ClauseObject::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	this->setFeatureValue(feature, values, position);
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> ClauseObject::retrieveFeatureValues()
{
	std::shared_ptr<uml::Classifier> type = this->getTypes()->at(0);
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAllAttributes();
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	
	unsigned int allAttributesSize = allAttributes->size();

	for(unsigned int i = 0; i < allAttributesSize; i++)
	{
		std::shared_ptr<uml::Property> property = allAttributes->at(i);
		if (property == UML::UMLPackage::eInstance()->get_UML_Clause_body() && m_ClauseValue->getBody() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Clause_bodyOutput() && m_ClauseValue->getBodyOutput() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Clause_decider() && m_ClauseValue->getDecider() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Clause_predecessorClause() && m_ClauseValue->getPredecessorClause() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Clause_successorClause() && m_ClauseValue->getSuccessorClause() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Clause_test() && m_ClauseValue->getTest() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment() && m_ClauseValue->getOwnedComment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement() && m_ClauseValue->getOwnedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_owner() && m_ClauseValue->getOwner().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
	}
	
	return featureValues;
}

