#include "umlReflectionExec/PropertyObject.hpp"

//General Includes
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/Property.hpp"
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
#include "uml/ConnectorEnd.hpp"
#include "umlReflectionExec/ConnectorEndObject.hpp"
#include "uml/ConnectableElementTemplateParameter.hpp"
#include "umlReflectionExec/ConnectableElementTemplateParameterObject.hpp"
#include "uml/PackageableElement.hpp"
#include "umlReflectionExec/PackageableElementObject.hpp"
#include "uml/Deployment.hpp"
#include "umlReflectionExec/DeploymentObject.hpp"
#include "uml/Comment.hpp"
#include "umlReflectionExec/CommentObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/Classifier.hpp"
#include "umlReflectionExec/ClassifierObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/IntegerValue.hpp"
#include "uml/ValueSpecification.hpp"
#include "umlReflectionExec/ValueSpecificationObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/UnlimitedNaturalValue.hpp"
#include "uml/ValueSpecification.hpp"
#include "umlReflectionExec/ValueSpecificationObject.hpp"
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
#include "uml/TemplateParameter.hpp"
#include "umlReflectionExec/TemplateParameterObject.hpp"
#include "uml/TemplateParameter.hpp"
#include "umlReflectionExec/TemplateParameterObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/EnumerationValue.hpp"
#include "uml/AggregationKind.hpp"
#include "uml/Association.hpp"
#include "umlReflectionExec/AssociationObject.hpp"
#include "uml/Property.hpp"
#include "umlReflectionExec/PropertyObject.hpp"
#include "uml/Class.hpp"
#include "umlReflectionExec/ClassObject.hpp"
#include "uml/DataType.hpp"
#include "umlReflectionExec/DataTypeObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/StringValue.hpp"
#include "uml/ValueSpecification.hpp"
#include "umlReflectionExec/ValueSpecificationObject.hpp"
#include "uml/Interface.hpp"
#include "umlReflectionExec/InterfaceObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/Property.hpp"
#include "umlReflectionExec/PropertyObject.hpp"
#include "uml/Association.hpp"
#include "umlReflectionExec/AssociationObject.hpp"
#include "uml/Property.hpp"
#include "umlReflectionExec/PropertyObject.hpp"
#include "uml/Property.hpp"
#include "umlReflectionExec/PropertyObject.hpp"
#include "uml/Property.hpp"
#include "umlReflectionExec/PropertyObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/RedefinableElement.hpp"
#include "umlReflectionExec/RedefinableElementObject.hpp"
#include "uml/Classifier.hpp"
#include "umlReflectionExec/ClassifierObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/Type.hpp"
#include "umlReflectionExec/TypeObject.hpp"
//Property Packages Includes
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"


using namespace UML;

PropertyObject::PropertyObject(std::shared_ptr<uml::Property> _element):
	m_PropertyValue(_element)
{
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_Property());
}

PropertyObject::PropertyObject(PropertyObject &obj):
	CS_ObjectImpl(obj)
{
	*this = obj;
}

PropertyObject::PropertyObject()
{	
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_Property());
}

PropertyObject::~PropertyObject()
{
}

std::shared_ptr<ecore::EObject> PropertyObject::copy()
{
	std::shared_ptr<PropertyObject> element(new PropertyObject());
	*element=(*this);
	element->setThisPropertyObjectPtr(element);
	return element;
}

PropertyObject& PropertyObject::operator=(const PropertyObject & obj)
{
	UML::ConnectableElementObject::operator=(obj);
	UML::DeploymentTargetObject::operator=(obj);
	UML::StructuralFeatureObject::operator=(obj);
	return *this;
}


void PropertyObject::destroy()
{	
	m_PropertyValue.reset();

	fUML::Semantics::StructuredClassifiers::ObjectImpl::destroy();
}

std::shared_ptr<uml::Element> PropertyObject::getUmlValue() const
{
	return getPropertyValue();
}

std::shared_ptr<uml::Property> PropertyObject::getPropertyValue() const
{
	return m_PropertyValue;
}

void PropertyObject::setUmlValue(std::shared_ptr<uml::Element> _element)
{
	setPropertyValue(std::dynamic_pointer_cast<uml::Property>(_element));
}

void PropertyObject::setPropertyValue(std::shared_ptr<uml::Property> _PropertyElement)
{
	m_PropertyValue = _PropertyElement;
	//set super type values
	UML::ConnectableElementObject::setConnectableElementValue(_PropertyElement);
	UML::DeploymentTargetObject::setDeploymentTargetValue(_PropertyElement);
	UML::StructuralFeatureObject::setStructuralFeatureValue(_PropertyElement);
}

void PropertyObject::setThisPropertyObjectPtr(std::weak_ptr<PropertyObject> thisObjectPtr)
{
	setThisCS_ObjectPtr(thisObjectPtr);
}

bool PropertyObject::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	bool isEqual = false;
	
	std::shared_ptr<PropertyObject> otherPropertyObject = std::dynamic_pointer_cast<PropertyObject>(otherValue);

	if(otherPropertyObject != nullptr)
	{
		if(this->getPropertyValue() == otherPropertyObject->getPropertyValue())
		{
			isEqual = true;
		}
	}

	return isEqual;
}

std::string PropertyObject::toString()
{
	std::string buffer = "Instance of 'PropertyObject', " + std::to_string(getTypes()->size()) + " types (";
	for(unsigned int i = 0; i < getTypes()->size(); ++i)
	{
		buffer += "type{" + std::to_string(i) + "}: '" + getTypes()->at(i)->getName() + "', ";
	}
	buffer +=")";

	return buffer;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> PropertyObject::getDirectContainers()
{   
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());

	/*Not done for metamodel object classes*/

	return directContainers;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> PropertyObject::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> allLinks(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());

	/*Not done for metamodel object classes*/

	return allLinks;
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> PropertyObject::retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end)
{
	/*Not done for metamodel object classes*/

	return nullptr;
}

void PropertyObject::removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_PropertyValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside PropertyObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (feature == UML::UMLPackage::eInstance()->get_UML_ConnectableElement_templateParameter())
	{
				m_PropertyValue->getTemplateParameter().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_DeploymentTarget_deployment())
	{
		if (value == nullptr) // clear mode
		{
			m_PropertyValue->getDeployment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::DeploymentObject> inputValue = std::dynamic_pointer_cast<UML::DeploymentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_PropertyValue->getDeployment()->erase(inputValue->getDeploymentValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		if (value == nullptr) // clear mode
		{
			m_PropertyValue->getOwnedComment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CommentObject> inputValue = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_PropertyValue->getOwnedComment()->erase(inputValue->getCommentValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Feature_isStatic())
	{
				m_PropertyValue->setIsStatic(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_isOrdered())
	{
				m_PropertyValue->setIsOrdered(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_isUnique())
	{
				m_PropertyValue->setIsUnique(true /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_lower())
	{
				m_PropertyValue->setLower(1 /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_lowerValue())
	{
				m_PropertyValue->getLowerValue().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_upper())
	{
				m_PropertyValue->setUpper(1 /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_upperValue())
	{
				m_PropertyValue->getUpperValue().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
				m_PropertyValue->getNameExpression().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_owningTemplateParameter())
	{
				m_PropertyValue->getOwningTemplateParameter().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_templateParameter())
	{
				m_PropertyValue->getTemplateParameter().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_aggregation())
	{
				m_PropertyValue->setAggregation(uml::AggregationKind::NONE /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_association())
	{
				m_PropertyValue->getAssociation().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_associationEnd())
	{
				m_PropertyValue->getAssociationEnd().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_class())
	{
				m_PropertyValue->getClass().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_datatype())
	{
				m_PropertyValue->getDatatype().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_default())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_defaultValue())
	{
				m_PropertyValue->getDefaultValue().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_interface())
	{
				m_PropertyValue->getInterface().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_isComposite())
	{
				m_PropertyValue->setIsComposite(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_isDerived())
	{
				m_PropertyValue->setIsDerived(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_isDerivedUnion())
	{
				m_PropertyValue->setIsDerivedUnion(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_isID())
	{
				m_PropertyValue->setIsID(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_opposite())
	{
				m_PropertyValue->getOpposite().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_owningAssociation())
	{
				m_PropertyValue->getOwningAssociation().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_qualifier())
	{
		if (value == nullptr) // clear mode
		{
			m_PropertyValue->getQualifier()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::PropertyObject> inputValue = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_PropertyValue->getQualifier()->erase(inputValue->getPropertyValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_redefinedProperty())
	{
		if (value == nullptr) // clear mode
		{
			m_PropertyValue->getRedefinedProperty()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::PropertyObject> inputValue = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_PropertyValue->getRedefinedProperty()->erase(inputValue->getPropertyValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_subsettedProperty())
	{
		if (value == nullptr) // clear mode
		{
			m_PropertyValue->getSubsettedProperty()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::PropertyObject> inputValue = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_PropertyValue->getSubsettedProperty()->erase(inputValue->getPropertyValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
				m_PropertyValue->setIsLeaf(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_StructuralFeature_isReadOnly())
	{
				m_PropertyValue->setIsReadOnly(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TypedElement_type())
	{
				m_PropertyValue->getType().reset();

	}
}


std::shared_ptr<Bag<fUML::Semantics::Values::Value>> PropertyObject::getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_PropertyValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside PropertyObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
	if (feature == UML::UMLPackage::eInstance()->get_UML_ConnectableElement_end())
	{
		std::shared_ptr<Bag<uml::ConnectorEnd>> endList = m_PropertyValue->getEnd();
		Bag<uml::ConnectorEnd>::iterator iter = endList->begin();
		Bag<uml::ConnectorEnd>::iterator end = endList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ConnectorEndObject> value(new UML::ConnectorEndObject());
			value->setThisConnectorEndObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setConnectorEndValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ConnectableElement_templateParameter())
	{
		std::shared_ptr<UML::ConnectableElementTemplateParameterObject> value(new UML::ConnectableElementTemplateParameterObject());
		value->setThisConnectableElementTemplateParameterObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setConnectableElementTemplateParameterValue(std::dynamic_pointer_cast<uml::ConnectableElementTemplateParameter>(m_PropertyValue->getTemplateParameter()));
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_DeploymentTarget_deployedElement())
	{
		std::shared_ptr<Bag<uml::PackageableElement>> deployedElementList = m_PropertyValue->getDeployedElement();
		Bag<uml::PackageableElement>::iterator iter = deployedElementList->begin();
		Bag<uml::PackageableElement>::iterator end = deployedElementList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::PackageableElementObject> value(new UML::PackageableElementObject());
			value->setThisPackageableElementObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setPackageableElementValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_DeploymentTarget_deployment())
	{
		std::shared_ptr<Subset<uml::Deployment, uml::Element>> deploymentList = m_PropertyValue->getDeployment();
		Bag<uml::Deployment>::iterator iter = deploymentList->begin();
		Bag<uml::Deployment>::iterator end = deploymentList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::DeploymentObject> value(new UML::DeploymentObject());
			value->setThisDeploymentObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setDeploymentValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		std::shared_ptr<Subset<uml::Comment, uml::Element>> ownedCommentList = m_PropertyValue->getOwnedComment();
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
		std::shared_ptr<Union<uml::Element>> ownedElementList = m_PropertyValue->getOwnedElement();
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
		value->setElementValue(m_PropertyValue->getOwner().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Feature_featuringClassifier())
	{
		std::shared_ptr<Union<uml::Classifier>> featuringClassifierList = m_PropertyValue->getFeaturingClassifier();
		Bag<uml::Classifier>::iterator iter = featuringClassifierList->begin();
		Bag<uml::Classifier>::iterator end = featuringClassifierList->end();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Feature_isStatic())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_PropertyValue->getIsStatic());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_isOrdered())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_PropertyValue->getIsOrdered());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_isUnique())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_PropertyValue->getIsUnique());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_lower())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
		value->setValue(m_PropertyValue->getLower());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_lowerValue())
	{
		std::shared_ptr<UML::ValueSpecificationObject> value(new UML::ValueSpecificationObject());
		value->setThisValueSpecificationObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setValueSpecificationValue(m_PropertyValue->getLowerValue());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_upper())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createUnlimitedNaturalValue();
		value->setValue(m_PropertyValue->getUpper());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_upperValue())
	{
		std::shared_ptr<UML::ValueSpecificationObject> value(new UML::ValueSpecificationObject());
		value->setThisValueSpecificationObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setValueSpecificationValue(m_PropertyValue->getUpperValue());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency())
	{
		std::shared_ptr<Bag<uml::Dependency>> clientDependencyList = m_PropertyValue->getClientDependency();
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
		value->setValue(m_PropertyValue->getName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<UML::StringExpressionObject> value(new UML::StringExpressionObject());
		value->setThisStringExpressionObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setStringExpressionValue(m_PropertyValue->getNameExpression());
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
		value->setNamespaceValue(m_PropertyValue->getNamespace().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_qualifiedName())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
		value->setValue(m_PropertyValue->getQualifiedName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		uml::VisibilityKind visibility = m_PropertyValue->getVisibility();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_owningTemplateParameter())
	{
		std::shared_ptr<UML::TemplateParameterObject> value(new UML::TemplateParameterObject());
		value->setThisTemplateParameterObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setTemplateParameterValue(m_PropertyValue->getOwningTemplateParameter().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_templateParameter())
	{
		std::shared_ptr<UML::TemplateParameterObject> value(new UML::TemplateParameterObject());
		value->setThisTemplateParameterObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setTemplateParameterValue(m_PropertyValue->getTemplateParameter());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_aggregation())
	{
		uml::AggregationKind aggregation = m_PropertyValue->getAggregation();
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createEnumerationValue();
		if (aggregation == uml::AggregationKind::NONE)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_AggregationKind_none());
		}
		if (aggregation == uml::AggregationKind::SHARED)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_AggregationKind_shared());
		}
		if (aggregation == uml::AggregationKind::COMPOSITE)
		{
			value->setLiteral(UML::UMLPackage::eInstance()->get_UML_AggregationKind_composite());
		}
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_association())
	{
		std::shared_ptr<UML::AssociationObject> value(new UML::AssociationObject());
		value->setThisAssociationObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setAssociationValue(m_PropertyValue->getAssociation());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_associationEnd())
	{
		std::shared_ptr<UML::PropertyObject> value(new UML::PropertyObject());
		value->setThisPropertyObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setPropertyValue(m_PropertyValue->getAssociationEnd().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_class())
	{
		std::shared_ptr<UML::ClassObject> value(new UML::ClassObject());
		value->setThisClassObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setClassValue(m_PropertyValue->getClass().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_datatype())
	{
		std::shared_ptr<UML::DataTypeObject> value(new UML::DataTypeObject());
		value->setThisDataTypeObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setDataTypeValue(m_PropertyValue->getDatatype().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_default())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
		value->setValue(m_PropertyValue->getDefault());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_defaultValue())
	{
		std::shared_ptr<UML::ValueSpecificationObject> value(new UML::ValueSpecificationObject());
		value->setThisValueSpecificationObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setValueSpecificationValue(m_PropertyValue->getDefaultValue());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_interface())
	{
		std::shared_ptr<UML::InterfaceObject> value(new UML::InterfaceObject());
		value->setThisInterfaceObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setInterfaceValue(m_PropertyValue->getInterface().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_isComposite())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_PropertyValue->getIsComposite());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_isDerived())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_PropertyValue->getIsDerived());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_isDerivedUnion())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_PropertyValue->getIsDerivedUnion());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_isID())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_PropertyValue->getIsID());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_opposite())
	{
		std::shared_ptr<UML::PropertyObject> value(new UML::PropertyObject());
		value->setThisPropertyObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setPropertyValue(m_PropertyValue->getOpposite());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_owningAssociation())
	{
		std::shared_ptr<UML::AssociationObject> value(new UML::AssociationObject());
		value->setThisAssociationObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setAssociationValue(m_PropertyValue->getOwningAssociation().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_qualifier())
	{
		std::shared_ptr<Subset<uml::Property, uml::Element>> qualifierList = m_PropertyValue->getQualifier();
		Bag<uml::Property>::iterator iter = qualifierList->begin();
		Bag<uml::Property>::iterator end = qualifierList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::PropertyObject> value(new UML::PropertyObject());
			value->setThisPropertyObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setPropertyValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_redefinedProperty())
	{
		std::shared_ptr<SubsetUnion<uml::Property, uml::RedefinableElement>> redefinedPropertyList = m_PropertyValue->getRedefinedProperty();
		Bag<uml::Property>::iterator iter = redefinedPropertyList->begin();
		Bag<uml::Property>::iterator end = redefinedPropertyList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::PropertyObject> value(new UML::PropertyObject());
			value->setThisPropertyObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setPropertyValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_subsettedProperty())
	{
		std::shared_ptr<Bag<uml::Property>> subsettedPropertyList = m_PropertyValue->getSubsettedProperty();
		Bag<uml::Property>::iterator iter = subsettedPropertyList->begin();
		Bag<uml::Property>::iterator end = subsettedPropertyList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::PropertyObject> value(new UML::PropertyObject());
			value->setThisPropertyObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setPropertyValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_PropertyValue->getIsLeaf());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinedElement())
	{
		std::shared_ptr<Union<uml::RedefinableElement>> redefinedElementList = m_PropertyValue->getRedefinedElement();
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
		std::shared_ptr<Union<uml::Classifier>> redefinitionContextList = m_PropertyValue->getRedefinitionContext();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_StructuralFeature_isReadOnly())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_PropertyValue->getIsReadOnly());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TypedElement_type())
	{
		std::shared_ptr<UML::TypeObject> value(new UML::TypeObject());
		value->setThisTypeObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setTypeValue(m_PropertyValue->getType());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	return values;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> PropertyObject::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
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


void PropertyObject::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_PropertyValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside PropertyObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (values->size() == 0)
	{
		std::cout << __PRETTY_FUNCTION__ << ": no input value given" << std::endl;
		return;
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ConnectableElement_templateParameter())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ConnectableElementTemplateParameterObject> value = std::dynamic_pointer_cast<UML::ConnectableElementTemplateParameterObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_PropertyValue->setTemplateParameter(value->getConnectableElementTemplateParameterValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_DeploymentTarget_deployment())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_PropertyValue->getDeployment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::DeploymentObject> value = std::dynamic_pointer_cast<UML::DeploymentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_PropertyValue->getDeployment()->push_back(value->getDeploymentValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_PropertyValue->getOwnedComment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CommentObject> value = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_PropertyValue->getOwnedComment()->push_back(value->getCommentValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Feature_isStatic())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_PropertyValue->setIsStatic(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_isOrdered())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_PropertyValue->setIsOrdered(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_isUnique())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_PropertyValue->setIsUnique(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_lower())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::IntegerValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_PropertyValue->setLower(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_lowerValue())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ValueSpecificationObject> value = std::dynamic_pointer_cast<UML::ValueSpecificationObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_PropertyValue->setLowerValue(value->getValueSpecificationValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_upper())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_PropertyValue->setUpper(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_upperValue())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ValueSpecificationObject> value = std::dynamic_pointer_cast<UML::ValueSpecificationObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_PropertyValue->setUpperValue(value->getValueSpecificationValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_PropertyValue->setName(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::StringExpressionObject> value = std::dynamic_pointer_cast<UML::StringExpressionObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_PropertyValue->setNameExpression(value->getStringExpressionValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(inputValue);
		std::shared_ptr<uml::EnumerationLiteral> literal = enumValue->getLiteral();
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_public())
		{
			m_PropertyValue->setVisibility(uml::VisibilityKind::PUBLIC);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_private())
		{
			m_PropertyValue->setVisibility(uml::VisibilityKind::PRIVATE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_protected())
		{
			m_PropertyValue->setVisibility(uml::VisibilityKind::PROTECTED);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_package())
		{
			m_PropertyValue->setVisibility(uml::VisibilityKind::PACKAGE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_templateParameter())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::TemplateParameterObject> value = std::dynamic_pointer_cast<UML::TemplateParameterObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_PropertyValue->setTemplateParameter(value->getTemplateParameterValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_aggregation())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(inputValue);
		std::shared_ptr<uml::EnumerationLiteral> literal = enumValue->getLiteral();
		if (literal == UML::UMLPackage::eInstance()->get_UML_AggregationKind_none())
		{
			m_PropertyValue->setAggregation(uml::AggregationKind::NONE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_AggregationKind_shared())
		{
			m_PropertyValue->setAggregation(uml::AggregationKind::SHARED);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_AggregationKind_composite())
		{
			m_PropertyValue->setAggregation(uml::AggregationKind::COMPOSITE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_association())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::AssociationObject> value = std::dynamic_pointer_cast<UML::AssociationObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_PropertyValue->setAssociation(value->getAssociationValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_default())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_PropertyValue->setDefault(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_defaultValue())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ValueSpecificationObject> value = std::dynamic_pointer_cast<UML::ValueSpecificationObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_PropertyValue->setDefaultValue(value->getValueSpecificationValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_isComposite())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_PropertyValue->setIsComposite(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_isDerived())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_PropertyValue->setIsDerived(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_isDerivedUnion())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_PropertyValue->setIsDerivedUnion(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_isID())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_PropertyValue->setIsID(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_opposite())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::PropertyObject> value = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_PropertyValue->setOpposite(value->getPropertyValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_qualifier())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_PropertyValue->getQualifier()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::PropertyObject> value = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_PropertyValue->getQualifier()->push_back(value->getPropertyValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_redefinedProperty())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_PropertyValue->getRedefinedProperty()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::PropertyObject> value = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_PropertyValue->getRedefinedProperty()->push_back(value->getPropertyValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Property_subsettedProperty())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_PropertyValue->getSubsettedProperty()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::PropertyObject> value = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_PropertyValue->getSubsettedProperty()->push_back(value->getPropertyValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_PropertyValue->setIsLeaf(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_StructuralFeature_isReadOnly())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_PropertyValue->setIsReadOnly(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TypedElement_type())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::TypeObject> value = std::dynamic_pointer_cast<UML::TypeObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_PropertyValue->setType(value->getTypeValue());
		}
		
	}
}

void PropertyObject::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	this->setFeatureValue(feature, values, position);
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> PropertyObject::retrieveFeatureValues()
{
	std::shared_ptr<uml::Classifier> type = this->getTypes()->at(0);
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAllAttributes();
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	
	unsigned int allAttributesSize = allAttributes->size();

	for(unsigned int i = 0; i < allAttributesSize; i++)
	{
		std::shared_ptr<uml::Property> property = allAttributes->at(i);
		if (property == UML::UMLPackage::eInstance()->get_UML_ConnectableElement_end() && m_PropertyValue->getEnd() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ConnectableElement_templateParameter() && m_PropertyValue->getTemplateParameter() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_DeploymentTarget_deployedElement() && m_PropertyValue->getDeployedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_DeploymentTarget_deployment() && m_PropertyValue->getDeployment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment() && m_PropertyValue->getOwnedComment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement() && m_PropertyValue->getOwnedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_owner() && m_PropertyValue->getOwner().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Feature_featuringClassifier() && m_PropertyValue->getFeaturingClassifier() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_lowerValue() && m_PropertyValue->getLowerValue() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_MultiplicityElement_upperValue() && m_PropertyValue->getUpperValue() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency() && m_PropertyValue->getClientDependency() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression() && m_PropertyValue->getNameExpression() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_namespace() && m_PropertyValue->getNamespace().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_owningTemplateParameter() && m_PropertyValue->getOwningTemplateParameter().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_templateParameter() && m_PropertyValue->getTemplateParameter() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Property_association() && m_PropertyValue->getAssociation() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Property_associationEnd() && m_PropertyValue->getAssociationEnd().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Property_class() && m_PropertyValue->getClass().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Property_datatype() && m_PropertyValue->getDatatype().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Property_defaultValue() && m_PropertyValue->getDefaultValue() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Property_interface() && m_PropertyValue->getInterface().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Property_opposite() && m_PropertyValue->getOpposite() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Property_owningAssociation() && m_PropertyValue->getOwningAssociation().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Property_qualifier() && m_PropertyValue->getQualifier() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Property_redefinedProperty() && m_PropertyValue->getRedefinedProperty() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Property_subsettedProperty() && m_PropertyValue->getSubsettedProperty() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinedElement() && m_PropertyValue->getRedefinedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinitionContext() && m_PropertyValue->getRedefinitionContext() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TypedElement_type() && m_PropertyValue->getType() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
	}
	
	return featureValues;
}

