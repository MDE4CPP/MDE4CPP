#include "umlReflectionExec/CombinedFragmentObject.hpp"

//General Includes
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/CombinedFragment.hpp"
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
#include "uml/Gate.hpp"
#include "umlReflectionExec/GateObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/EnumerationValue.hpp"
#include "uml/InteractionOperatorKind.hpp"
#include "uml/InteractionOperand.hpp"
#include "umlReflectionExec/InteractionOperandObject.hpp"
#include "uml/Comment.hpp"
#include "umlReflectionExec/CommentObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/Lifeline.hpp"
#include "umlReflectionExec/LifelineObject.hpp"
#include "uml/Interaction.hpp"
#include "umlReflectionExec/InteractionObject.hpp"
#include "uml/InteractionOperand.hpp"
#include "umlReflectionExec/InteractionOperandObject.hpp"
#include "uml/GeneralOrdering.hpp"
#include "umlReflectionExec/GeneralOrderingObject.hpp"
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
//Property Packages Includes
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"


using namespace UML;

CombinedFragmentObject::CombinedFragmentObject(std::shared_ptr<uml::CombinedFragment> _element):

	m_CombinedFragmentValue(_element)
{		
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_CombinedFragment());
}

CombinedFragmentObject::CombinedFragmentObject(CombinedFragmentObject &obj):
	CS_ObjectImpl(obj)
{
}

CombinedFragmentObject::CombinedFragmentObject()
{	
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_CombinedFragment());
}

CombinedFragmentObject::~CombinedFragmentObject()
{
}

std::shared_ptr<ecore::EObject> CombinedFragmentObject::copy()
{
	std::shared_ptr<CombinedFragmentObject> element(new CombinedFragmentObject(*this));
	element->setThisCombinedFragmentObjectPtr(element);
	return element;
}

void CombinedFragmentObject::destroy()
{	
	m_CombinedFragmentValue.reset();

	fUML::Semantics::StructuredClassifiers::ObjectImpl::destroy();
}

std::shared_ptr<uml::Element> CombinedFragmentObject::getUmlValue() const
{
	return getCombinedFragmentValue();
}

std::shared_ptr<uml::CombinedFragment> CombinedFragmentObject::getCombinedFragmentValue() const
{
	return m_CombinedFragmentValue;
}

void CombinedFragmentObject::setUmlValue(std::shared_ptr<uml::Element> _element)
{
	setCombinedFragmentValue(std::dynamic_pointer_cast<uml::CombinedFragment>(_element));
}

void CombinedFragmentObject::setCombinedFragmentValue(std::shared_ptr<uml::CombinedFragment> _CombinedFragmentElement)
{
	m_CombinedFragmentValue = _CombinedFragmentElement;
	//set super type values
	UML::InteractionFragmentObject::setInteractionFragmentValue(_CombinedFragmentElement);
}

void CombinedFragmentObject::setThisCombinedFragmentObjectPtr(std::weak_ptr<CombinedFragmentObject> thisObjectPtr)
{
	setThisCS_ObjectPtr(thisObjectPtr);
}

bool CombinedFragmentObject::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	bool isEqual = false;
	
	std::shared_ptr<CombinedFragmentObject> otherCombinedFragmentObject = std::dynamic_pointer_cast<CombinedFragmentObject>(otherValue);

	if(otherCombinedFragmentObject != nullptr)
	{
		if(this->getCombinedFragmentValue() == otherCombinedFragmentObject->getCombinedFragmentValue())
		{
			isEqual = true;
		}
	}

	return isEqual;
}

std::string CombinedFragmentObject::toString()
{
	std::string buffer = "Instance of 'CombinedFragmentObject', " + std::to_string(getTypes()->size()) + " types (";
	for(unsigned int i = 0; i < getTypes()->size(); ++i)
	{
		buffer += "type{" + std::to_string(i) + "}: '" + getTypes()->at(i)->getName() + "', ";
	}
	buffer +=")";

	return buffer;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> CombinedFragmentObject::getDirectContainers()
{   
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());

	/*Not done for metamodel object classes*/

	return directContainers;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> CombinedFragmentObject::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> allLinks(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());

	/*Not done for metamodel object classes*/

	return allLinks;
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> CombinedFragmentObject::retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end)
{
	/*Not done for metamodel object classes*/

	return nullptr;
}

void CombinedFragmentObject::removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_CombinedFragmentValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside CombinedFragmentObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (feature == UML::UMLPackage::eInstance()->get_UML_CombinedFragment_cfragmentGate())
	{
		if (value == nullptr) // clear mode
		{
			m_CombinedFragmentValue->getCfragmentGate()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::GateObject> inputValue = std::dynamic_pointer_cast<UML::GateObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CombinedFragmentValue->getCfragmentGate()->erase(inputValue->getGateValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CombinedFragment_interactionOperator())
	{
				m_CombinedFragmentValue->setInteractionOperator(uml::InteractionOperatorKind::SEQ /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CombinedFragment_operand())
	{
		if (value == nullptr) // clear mode
		{
			m_CombinedFragmentValue->getOperand()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::InteractionOperandObject> inputValue = std::dynamic_pointer_cast<UML::InteractionOperandObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CombinedFragmentValue->getOperand()->erase(inputValue->getInteractionOperandValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		if (value == nullptr) // clear mode
		{
			m_CombinedFragmentValue->getOwnedComment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CommentObject> inputValue = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CombinedFragmentValue->getOwnedComment()->erase(inputValue->getCommentValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_covered())
	{
		if (value == nullptr) // clear mode
		{
			m_CombinedFragmentValue->getCovered()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::LifelineObject> inputValue = std::dynamic_pointer_cast<UML::LifelineObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CombinedFragmentValue->getCovered()->erase(inputValue->getLifelineValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_enclosingInteraction())
	{
				m_CombinedFragmentValue->getEnclosingInteraction().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_enclosingOperand())
	{
				m_CombinedFragmentValue->getEnclosingOperand().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_generalOrdering())
	{
		if (value == nullptr) // clear mode
		{
			m_CombinedFragmentValue->getGeneralOrdering()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::GeneralOrderingObject> inputValue = std::dynamic_pointer_cast<UML::GeneralOrderingObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_CombinedFragmentValue->getGeneralOrdering()->erase(inputValue->getGeneralOrderingValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
				m_CombinedFragmentValue->getNameExpression().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
				// no default value defined, clear not realized

	}
}


std::shared_ptr<Bag<fUML::Semantics::Values::Value>> CombinedFragmentObject::getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_CombinedFragmentValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside CombinedFragmentObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
	if (feature == UML::UMLPackage::eInstance()->get_UML_CombinedFragment_cfragmentGate())
	{
		std::shared_ptr<Bag<uml::Gate>> cfragmentGateList = m_CombinedFragmentValue->getCfragmentGate();
		Bag<uml::Gate>::iterator iter = cfragmentGateList->begin();
		Bag<uml::Gate>::iterator end = cfragmentGateList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::GateObject> value(new UML::GateObject());
			value->setThisGateObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setGateValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CombinedFragment_interactionOperator())
	{
		uml::InteractionOperatorKind interactionOperator = m_CombinedFragmentValue->getInteractionOperator();
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createEnumerationValue();
		if (interactionOperator == uml::InteractionOperatorKind::SEQ)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_seq());
		}
		if (interactionOperator == uml::InteractionOperatorKind::ALT)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_alt());
		}
		if (interactionOperator == uml::InteractionOperatorKind::OPT)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_opt());
		}
		if (interactionOperator == uml::InteractionOperatorKind::BREAK)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_break());
		}
		if (interactionOperator == uml::InteractionOperatorKind::PAR)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_par());
		}
		if (interactionOperator == uml::InteractionOperatorKind::STRICT)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_strict());
		}
		if (interactionOperator == uml::InteractionOperatorKind::LOOP)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_loop());
		}
		if (interactionOperator == uml::InteractionOperatorKind::CRITICAL)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_critical());
		}
		if (interactionOperator == uml::InteractionOperatorKind::NEG)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_neg());
		}
		if (interactionOperator == uml::InteractionOperatorKind::ASSERT)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_assert());
		}
		if (interactionOperator == uml::InteractionOperatorKind::IGNORE)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_ignore());
		}
		if (interactionOperator == uml::InteractionOperatorKind::CONSIDER)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_consider());
		}
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CombinedFragment_operand())
	{
		std::shared_ptr<Bag<uml::InteractionOperand>> operandList = m_CombinedFragmentValue->getOperand();
		Bag<uml::InteractionOperand>::iterator iter = operandList->begin();
		Bag<uml::InteractionOperand>::iterator end = operandList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::InteractionOperandObject> value(new UML::InteractionOperandObject());
			value->setThisInteractionOperandObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setInteractionOperandValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		std::shared_ptr<Bag<uml::Comment>> ownedCommentList = m_CombinedFragmentValue->getOwnedComment();
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
		std::shared_ptr<Bag<uml::Element>> ownedElementList = m_CombinedFragmentValue->getOwnedElement();
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
		value->setElementValue(m_CombinedFragmentValue->getOwner().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_covered())
	{
		std::shared_ptr<Bag<uml::Lifeline>> coveredList = m_CombinedFragmentValue->getCovered();
		Bag<uml::Lifeline>::iterator iter = coveredList->begin();
		Bag<uml::Lifeline>::iterator end = coveredList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::LifelineObject> value(new UML::LifelineObject());
			value->setThisLifelineObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setLifelineValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_enclosingInteraction())
	{
		std::shared_ptr<UML::InteractionObject> value(new UML::InteractionObject());
		value->setThisInteractionObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setInteractionValue(m_CombinedFragmentValue->getEnclosingInteraction().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_enclosingOperand())
	{
		std::shared_ptr<UML::InteractionOperandObject> value(new UML::InteractionOperandObject());
		value->setThisInteractionOperandObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setInteractionOperandValue(m_CombinedFragmentValue->getEnclosingOperand().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_generalOrdering())
	{
		std::shared_ptr<Bag<uml::GeneralOrdering>> generalOrderingList = m_CombinedFragmentValue->getGeneralOrdering();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency())
	{
		std::shared_ptr<Bag<uml::Dependency>> clientDependencyList = m_CombinedFragmentValue->getClientDependency();
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
		value->setValue(m_CombinedFragmentValue->getName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<UML::StringExpressionObject> value(new UML::StringExpressionObject());
		value->setThisStringExpressionObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setStringExpressionValue(m_CombinedFragmentValue->getNameExpression());
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
		value->setNamespaceValue(m_CombinedFragmentValue->getNamespace().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_qualifiedName())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
		value->setValue(m_CombinedFragmentValue->getQualifiedName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		uml::VisibilityKind visibility = m_CombinedFragmentValue->getVisibility();
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
	return values;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> CombinedFragmentObject::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
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


void CombinedFragmentObject::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_CombinedFragmentValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside CombinedFragmentObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (values->size() == 0)
	{
		std::cout << __PRETTY_FUNCTION__ << ": no input value given" << std::endl;
		return;
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CombinedFragment_cfragmentGate())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CombinedFragmentValue->getCfragmentGate()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::GateObject> value = std::dynamic_pointer_cast<UML::GateObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CombinedFragmentValue->getCfragmentGate()->push_back(value->getGateValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CombinedFragment_interactionOperator())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(inputValue);
		std::shared_ptr<uml::EnumerationLiteral> literal = enumValue->getLiteral();
		if (literal == UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_seq())
		{
			m_CombinedFragmentValue->setInteractionOperator(uml::InteractionOperatorKind::SEQ);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_alt())
		{
			m_CombinedFragmentValue->setInteractionOperator(uml::InteractionOperatorKind::ALT);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_opt())
		{
			m_CombinedFragmentValue->setInteractionOperator(uml::InteractionOperatorKind::OPT);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_break())
		{
			m_CombinedFragmentValue->setInteractionOperator(uml::InteractionOperatorKind::BREAK);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_par())
		{
			m_CombinedFragmentValue->setInteractionOperator(uml::InteractionOperatorKind::PAR);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_strict())
		{
			m_CombinedFragmentValue->setInteractionOperator(uml::InteractionOperatorKind::STRICT);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_loop())
		{
			m_CombinedFragmentValue->setInteractionOperator(uml::InteractionOperatorKind::LOOP);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_critical())
		{
			m_CombinedFragmentValue->setInteractionOperator(uml::InteractionOperatorKind::CRITICAL);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_neg())
		{
			m_CombinedFragmentValue->setInteractionOperator(uml::InteractionOperatorKind::NEG);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_assert())
		{
			m_CombinedFragmentValue->setInteractionOperator(uml::InteractionOperatorKind::ASSERT);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_ignore())
		{
			m_CombinedFragmentValue->setInteractionOperator(uml::InteractionOperatorKind::IGNORE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_InteractionOperatorKind_consider())
		{
			m_CombinedFragmentValue->setInteractionOperator(uml::InteractionOperatorKind::CONSIDER);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_CombinedFragment_operand())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CombinedFragmentValue->getOperand()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::InteractionOperandObject> value = std::dynamic_pointer_cast<UML::InteractionOperandObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CombinedFragmentValue->getOperand()->push_back(value->getInteractionOperandValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CombinedFragmentValue->getOwnedComment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CommentObject> value = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CombinedFragmentValue->getOwnedComment()->push_back(value->getCommentValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_covered())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CombinedFragmentValue->getCovered()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::LifelineObject> value = std::dynamic_pointer_cast<UML::LifelineObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CombinedFragmentValue->getCovered()->push_back(value->getLifelineValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_generalOrdering())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_CombinedFragmentValue->getGeneralOrdering()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::GeneralOrderingObject> value = std::dynamic_pointer_cast<UML::GeneralOrderingObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_CombinedFragmentValue->getGeneralOrdering()->push_back(value->getGeneralOrderingValue());
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
			m_CombinedFragmentValue->setName(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::StringExpressionObject> value = std::dynamic_pointer_cast<UML::StringExpressionObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_CombinedFragmentValue->setNameExpression(value->getStringExpressionValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(inputValue);
		std::shared_ptr<uml::EnumerationLiteral> literal = enumValue->getLiteral();
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_public())
		{
			m_CombinedFragmentValue->setVisibility(uml::VisibilityKind::PUBLIC);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_private())
		{
			m_CombinedFragmentValue->setVisibility(uml::VisibilityKind::PRIVATE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_protected())
		{
			m_CombinedFragmentValue->setVisibility(uml::VisibilityKind::PROTECTED);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_package())
		{
			m_CombinedFragmentValue->setVisibility(uml::VisibilityKind::PACKAGE);
		}
		
	}
}

void CombinedFragmentObject::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	this->setFeatureValue(feature, values, position);
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> CombinedFragmentObject::retrieveFeatureValues()
{
	std::shared_ptr<uml::Classifier> type = this->getTypes()->at(0);
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAllAttributes();
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	
	unsigned int allAttributesSize = allAttributes->size();

	for(unsigned int i = 0; i < allAttributesSize; i++)
	{
		std::shared_ptr<uml::Property> property = allAttributes->at(i);
		if (property == UML::UMLPackage::eInstance()->get_UML_CombinedFragment_cfragmentGate() && m_CombinedFragmentValue->getCfragmentGate() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_CombinedFragment_operand() && m_CombinedFragmentValue->getOperand() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment() && m_CombinedFragmentValue->getOwnedComment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement() && m_CombinedFragmentValue->getOwnedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_owner() && m_CombinedFragmentValue->getOwner().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_covered() && m_CombinedFragmentValue->getCovered() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_enclosingInteraction() && m_CombinedFragmentValue->getEnclosingInteraction().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_enclosingOperand() && m_CombinedFragmentValue->getEnclosingOperand().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_InteractionFragment_generalOrdering() && m_CombinedFragmentValue->getGeneralOrdering() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency() && m_CombinedFragmentValue->getClientDependency() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression() && m_CombinedFragmentValue->getNameExpression() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_namespace() && m_CombinedFragmentValue->getNamespace().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
	}
	
	return featureValues;
}

