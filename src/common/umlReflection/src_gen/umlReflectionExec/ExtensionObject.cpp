#include "umlReflectionExec/ExtensionObject.hpp"

//General Includes
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/Extension.hpp"
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
#include "uml/Type.hpp"
#include "umlReflectionExec/TypeObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/Property.hpp"
#include "umlReflectionExec/PropertyObject.hpp"
#include "uml/Property.hpp"
#include "umlReflectionExec/PropertyObject.hpp"
#include "uml/Property.hpp"
#include "umlReflectionExec/PropertyObject.hpp"
#include "uml/Property.hpp"
#include "umlReflectionExec/PropertyObject.hpp"
#include "uml/CollaborationUse.hpp"
#include "umlReflectionExec/CollaborationUseObject.hpp"
#include "uml/Feature.hpp"
#include "umlReflectionExec/FeatureObject.hpp"
#include "uml/Classifier.hpp"
#include "umlReflectionExec/ClassifierObject.hpp"
#include "uml/Generalization.hpp"
#include "umlReflectionExec/GeneralizationObject.hpp"
#include "uml/NamedElement.hpp"
#include "umlReflectionExec/NamedElementObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/RedefinableTemplateSignature.hpp"
#include "umlReflectionExec/RedefinableTemplateSignatureObject.hpp"
#include "uml/UseCase.hpp"
#include "umlReflectionExec/UseCaseObject.hpp"
#include "uml/GeneralizationSet.hpp"
#include "umlReflectionExec/GeneralizationSetObject.hpp"
#include "uml/Classifier.hpp"
#include "umlReflectionExec/ClassifierObject.hpp"
#include "uml/CollaborationUse.hpp"
#include "umlReflectionExec/CollaborationUseObject.hpp"
#include "uml/Substitution.hpp"
#include "umlReflectionExec/SubstitutionObject.hpp"
#include "uml/ClassifierTemplateParameter.hpp"
#include "umlReflectionExec/ClassifierTemplateParameterObject.hpp"
#include "uml/UseCase.hpp"
#include "umlReflectionExec/UseCaseObject.hpp"
#include "uml/Comment.hpp"
#include "umlReflectionExec/CommentObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/Class.hpp"
#include "umlReflectionExec/ClassObject.hpp"
#include "uml/ExtensionEnd.hpp"
#include "umlReflectionExec/ExtensionEndObject.hpp"
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
#include "uml/ElementImport.hpp"
#include "umlReflectionExec/ElementImportObject.hpp"
#include "uml/PackageableElement.hpp"
#include "umlReflectionExec/PackageableElementObject.hpp"
#include "uml/NamedElement.hpp"
#include "umlReflectionExec/NamedElementObject.hpp"
#include "uml/NamedElement.hpp"
#include "umlReflectionExec/NamedElementObject.hpp"
#include "uml/Constraint.hpp"
#include "umlReflectionExec/ConstraintObject.hpp"
#include "uml/PackageImport.hpp"
#include "umlReflectionExec/PackageImportObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/EnumerationValue.hpp"
#include "uml/VisibilityKind.hpp"
#include "uml/TemplateParameter.hpp"
#include "umlReflectionExec/TemplateParameterObject.hpp"
#include "uml/TemplateParameter.hpp"
#include "umlReflectionExec/TemplateParameterObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/RedefinableElement.hpp"
#include "umlReflectionExec/RedefinableElementObject.hpp"
#include "uml/Classifier.hpp"
#include "umlReflectionExec/ClassifierObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/TemplateSignature.hpp"
#include "umlReflectionExec/TemplateSignatureObject.hpp"
#include "uml/TemplateBinding.hpp"
#include "umlReflectionExec/TemplateBindingObject.hpp"
#include "uml/Package.hpp"
#include "umlReflectionExec/PackageObject.hpp"
//Property Packages Includes
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"


using namespace UML;

ExtensionObject::ExtensionObject(std::shared_ptr<uml::Extension> _element):
	m_ExtensionValue(_element)
{
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_Extension());
}

ExtensionObject::ExtensionObject(ExtensionObject &obj):
	CS_ObjectImpl(obj)
{
	*this = obj;
}

ExtensionObject::ExtensionObject()
{	
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_Extension());
}

ExtensionObject::~ExtensionObject()
{
}

std::shared_ptr<ecore::EObject> ExtensionObject::copy()
{
	std::shared_ptr<ExtensionObject> element(new ExtensionObject());
	*element=(*this);
	element->setThisExtensionObjectPtr(element);
	return element;
}

ExtensionObject& ExtensionObject::operator=(const ExtensionObject & obj)
{
	UML::AssociationObject::operator=(obj);
	return *this;
}


void ExtensionObject::destroy()
{	
	m_ExtensionValue.reset();

	fUML::Semantics::StructuredClassifiers::ObjectImpl::destroy();
}

std::shared_ptr<uml::Element> ExtensionObject::getUmlValue() const
{
	return getExtensionValue();
}

std::shared_ptr<uml::Extension> ExtensionObject::getExtensionValue() const
{
	return m_ExtensionValue;
}

void ExtensionObject::setUmlValue(std::shared_ptr<uml::Element> _element)
{
	setExtensionValue(std::dynamic_pointer_cast<uml::Extension>(_element));
}

void ExtensionObject::setExtensionValue(std::shared_ptr<uml::Extension> _ExtensionElement)
{
	m_ExtensionValue = _ExtensionElement;
	//set super type values
	UML::AssociationObject::setAssociationValue(_ExtensionElement);
}

void ExtensionObject::setThisExtensionObjectPtr(std::weak_ptr<ExtensionObject> thisObjectPtr)
{
	setThisCS_ObjectPtr(thisObjectPtr);
}

bool ExtensionObject::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	bool isEqual = false;
	
	std::shared_ptr<ExtensionObject> otherExtensionObject = std::dynamic_pointer_cast<ExtensionObject>(otherValue);

	if(otherExtensionObject != nullptr)
	{
		if(this->getExtensionValue() == otherExtensionObject->getExtensionValue())
		{
			isEqual = true;
		}
	}

	return isEqual;
}

std::string ExtensionObject::toString()
{
	std::string buffer = "Instance of 'ExtensionObject', " + std::to_string(getTypes()->size()) + " types (";
	for(unsigned int i = 0; i < getTypes()->size(); ++i)
	{
		buffer += "type{" + std::to_string(i) + "}: '" + getTypes()->at(i)->getName() + "', ";
	}
	buffer +=")";

	return buffer;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> ExtensionObject::getDirectContainers()
{   
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());

	/*Not done for metamodel object classes*/

	return directContainers;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> ExtensionObject::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> allLinks(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());

	/*Not done for metamodel object classes*/

	return allLinks;
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ExtensionObject::retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end)
{
	/*Not done for metamodel object classes*/

	return nullptr;
}

void ExtensionObject::removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ExtensionValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ExtensionObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (feature == UML::UMLPackage::eInstance()->get_UML_Association_isDerived())
	{
				m_ExtensionValue->setIsDerived(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Association_memberEnd())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getMemberEnd()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::PropertyObject> inputValue = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getMemberEnd()->erase(inputValue->getPropertyValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Association_navigableOwnedEnd())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getNavigableOwnedEnd()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::PropertyObject> inputValue = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getNavigableOwnedEnd()->erase(inputValue->getPropertyValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Association_ownedEnd())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getOwnedEnd()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::PropertyObject> inputValue = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getOwnedEnd()->erase(inputValue->getPropertyValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_collaborationUse())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getCollaborationUse()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CollaborationUseObject> inputValue = std::dynamic_pointer_cast<UML::CollaborationUseObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getCollaborationUse()->erase(inputValue->getCollaborationUseValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_general())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getGeneral()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ClassifierObject> inputValue = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getGeneral()->erase(inputValue->getClassifierValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_generalization())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getGeneralization()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::GeneralizationObject> inputValue = std::dynamic_pointer_cast<UML::GeneralizationObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getGeneralization()->erase(inputValue->getGeneralizationValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_isAbstract())
	{
				m_ExtensionValue->setIsAbstract(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_isFinalSpecialization())
	{
				m_ExtensionValue->setIsFinalSpecialization(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature())
	{
				m_ExtensionValue->getOwnedTemplateSignature().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getOwnedUseCase()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::UseCaseObject> inputValue = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getOwnedUseCase()->erase(inputValue->getUseCaseValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_powertypeExtent())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getPowertypeExtent()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::GeneralizationSetObject> inputValue = std::dynamic_pointer_cast<UML::GeneralizationSetObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getPowertypeExtent()->erase(inputValue->getGeneralizationSetValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_redefinedClassifier())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getRedefinedClassifier()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ClassifierObject> inputValue = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getRedefinedClassifier()->erase(inputValue->getClassifierValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_representation())
	{
				m_ExtensionValue->getRepresentation().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getSubstitution()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::SubstitutionObject> inputValue = std::dynamic_pointer_cast<UML::SubstitutionObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getSubstitution()->erase(inputValue->getSubstitutionValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_templateParameter())
	{
				m_ExtensionValue->getTemplateParameter().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getUseCase()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::UseCaseObject> inputValue = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getUseCase()->erase(inputValue->getUseCaseValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getOwnedComment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CommentObject> inputValue = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getOwnedComment()->erase(inputValue->getCommentValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Extension_ownedEnd())
	{
				m_ExtensionValue->getOwnedEnd().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
				m_ExtensionValue->getNameExpression().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_elementImport())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getElementImport()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ElementImportObject> inputValue = std::dynamic_pointer_cast<UML::ElementImportObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getElementImport()->erase(inputValue->getElementImportValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedRule())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getOwnedRule()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ConstraintObject> inputValue = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getOwnedRule()->erase(inputValue->getConstraintValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_packageImport())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getPackageImport()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::PackageImportObject> inputValue = std::dynamic_pointer_cast<UML::PackageImportObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getPackageImport()->erase(inputValue->getPackageImportValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_PackageableElement_visibility())
	{
				m_ExtensionValue->setVisibility(uml::VisibilityKind::PUBLIC /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_owningTemplateParameter())
	{
				m_ExtensionValue->getOwningTemplateParameter().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_templateParameter())
	{
				m_ExtensionValue->getTemplateParameter().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
				m_ExtensionValue->setIsLeaf(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_ownedTemplateSignature())
	{
				m_ExtensionValue->getOwnedTemplateSignature().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding())
	{
		if (value == nullptr) // clear mode
		{
			m_ExtensionValue->getTemplateBinding()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::TemplateBindingObject> inputValue = std::dynamic_pointer_cast<UML::TemplateBindingObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ExtensionValue->getTemplateBinding()->erase(inputValue->getTemplateBindingValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Type_package())
	{
				m_ExtensionValue->getPackage().reset();

	}
}


std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ExtensionObject::getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ExtensionValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ExtensionObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
	if (feature == UML::UMLPackage::eInstance()->get_UML_Association_endType())
	{
		std::shared_ptr<Subset<uml::Type, uml::Element>> endTypeList = m_ExtensionValue->getEndType();
		Bag<uml::Type>::iterator iter = endTypeList->begin();
		Bag<uml::Type>::iterator end = endTypeList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::TypeObject> value(new UML::TypeObject());
			value->setThisTypeObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setTypeValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Association_isDerived())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ExtensionValue->getIsDerived());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Association_memberEnd())
	{
		std::shared_ptr<SubsetUnion<uml::Property, uml::NamedElement>> memberEndList = m_ExtensionValue->getMemberEnd();
		Bag<uml::Property>::iterator iter = memberEndList->begin();
		Bag<uml::Property>::iterator end = memberEndList->end();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Association_navigableOwnedEnd())
	{
		std::shared_ptr<Subset<uml::Property, uml::Property /*Subset does not reference a union*/>> navigableOwnedEndList = m_ExtensionValue->getNavigableOwnedEnd();
		Bag<uml::Property>::iterator iter = navigableOwnedEndList->begin();
		Bag<uml::Property>::iterator end = navigableOwnedEndList->end();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Association_ownedEnd())
	{
		std::shared_ptr<SubsetUnion<uml::Property, uml::Feature, uml::NamedElement, uml::Property /*Subset does not reference a union*/>> ownedEndList = m_ExtensionValue->getOwnedEnd();
		Bag<uml::Property>::iterator iter = ownedEndList->begin();
		Bag<uml::Property>::iterator end = ownedEndList->end();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_attribute())
	{
		std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> attributeList = m_ExtensionValue->getAttribute();
		Bag<uml::Property>::iterator iter = attributeList->begin();
		Bag<uml::Property>::iterator end = attributeList->end();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_collaborationUse())
	{
		std::shared_ptr<SubsetUnion<uml::CollaborationUse, uml::Element>> collaborationUseList = m_ExtensionValue->getCollaborationUse();
		Bag<uml::CollaborationUse>::iterator iter = collaborationUseList->begin();
		Bag<uml::CollaborationUse>::iterator end = collaborationUseList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::CollaborationUseObject> value(new UML::CollaborationUseObject());
			value->setThisCollaborationUseObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setCollaborationUseValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_feature())
	{
		std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> featureList = m_ExtensionValue->getFeature();
		Bag<uml::Feature>::iterator iter = featureList->begin();
		Bag<uml::Feature>::iterator end = featureList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::FeatureObject> value(new UML::FeatureObject());
			value->setThisFeatureObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setFeatureValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_general())
	{
		std::shared_ptr<Bag<uml::Classifier>> generalList = m_ExtensionValue->getGeneral();
		Bag<uml::Classifier>::iterator iter = generalList->begin();
		Bag<uml::Classifier>::iterator end = generalList->end();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_generalization())
	{
		std::shared_ptr<Subset<uml::Generalization, uml::Element>> generalizationList = m_ExtensionValue->getGeneralization();
		Bag<uml::Generalization>::iterator iter = generalizationList->begin();
		Bag<uml::Generalization>::iterator end = generalizationList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::GeneralizationObject> value(new UML::GeneralizationObject());
			value->setThisGeneralizationObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setGeneralizationValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_inheritedMember())
	{
		std::shared_ptr<Subset<uml::NamedElement, uml::NamedElement>> inheritedMemberList = m_ExtensionValue->getInheritedMember();
		Bag<uml::NamedElement>::iterator iter = inheritedMemberList->begin();
		Bag<uml::NamedElement>::iterator end = inheritedMemberList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::NamedElementObject> value(new UML::NamedElementObject());
			value->setThisNamedElementObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setNamedElementValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_isAbstract())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ExtensionValue->getIsAbstract());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_isFinalSpecialization())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ExtensionValue->getIsFinalSpecialization());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature())
	{
		std::shared_ptr<UML::RedefinableTemplateSignatureObject> value(new UML::RedefinableTemplateSignatureObject());
		value->setThisRedefinableTemplateSignatureObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setRedefinableTemplateSignatureValue(std::dynamic_pointer_cast<uml::RedefinableTemplateSignature>(m_ExtensionValue->getOwnedTemplateSignature()));
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase())
	{
		std::shared_ptr<Subset<uml::UseCase, uml::NamedElement>> ownedUseCaseList = m_ExtensionValue->getOwnedUseCase();
		Bag<uml::UseCase>::iterator iter = ownedUseCaseList->begin();
		Bag<uml::UseCase>::iterator end = ownedUseCaseList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::UseCaseObject> value(new UML::UseCaseObject());
			value->setThisUseCaseObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setUseCaseValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_powertypeExtent())
	{
		std::shared_ptr<Bag<uml::GeneralizationSet>> powertypeExtentList = m_ExtensionValue->getPowertypeExtent();
		Bag<uml::GeneralizationSet>::iterator iter = powertypeExtentList->begin();
		Bag<uml::GeneralizationSet>::iterator end = powertypeExtentList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::GeneralizationSetObject> value(new UML::GeneralizationSetObject());
			value->setThisGeneralizationSetObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setGeneralizationSetValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_redefinedClassifier())
	{
		std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement>> redefinedClassifierList = m_ExtensionValue->getRedefinedClassifier();
		Bag<uml::Classifier>::iterator iter = redefinedClassifierList->begin();
		Bag<uml::Classifier>::iterator end = redefinedClassifierList->end();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_representation())
	{
		std::shared_ptr<UML::CollaborationUseObject> value(new UML::CollaborationUseObject());
		value->setThisCollaborationUseObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setCollaborationUseValue(m_ExtensionValue->getRepresentation());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution())
	{
		std::shared_ptr<Subset<uml::Substitution, uml::Element>> substitutionList = m_ExtensionValue->getSubstitution();
		Bag<uml::Substitution>::iterator iter = substitutionList->begin();
		Bag<uml::Substitution>::iterator end = substitutionList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::SubstitutionObject> value(new UML::SubstitutionObject());
			value->setThisSubstitutionObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setSubstitutionValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_templateParameter())
	{
		std::shared_ptr<UML::ClassifierTemplateParameterObject> value(new UML::ClassifierTemplateParameterObject());
		value->setThisClassifierTemplateParameterObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setClassifierTemplateParameterValue(std::dynamic_pointer_cast<uml::ClassifierTemplateParameter>(m_ExtensionValue->getTemplateParameter()));
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase())
	{
		std::shared_ptr<Bag<uml::UseCase>> useCaseList = m_ExtensionValue->getUseCase();
		Bag<uml::UseCase>::iterator iter = useCaseList->begin();
		Bag<uml::UseCase>::iterator end = useCaseList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::UseCaseObject> value(new UML::UseCaseObject());
			value->setThisUseCaseObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setUseCaseValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		std::shared_ptr<Subset<uml::Comment, uml::Element>> ownedCommentList = m_ExtensionValue->getOwnedComment();
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
		std::shared_ptr<Union<uml::Element>> ownedElementList = m_ExtensionValue->getOwnedElement();
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
		value->setElementValue(m_ExtensionValue->getOwner().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Extension_isRequired())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ExtensionValue->getIsRequired());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Extension_metaclass())
	{
		std::shared_ptr<UML::ClassObject> value(new UML::ClassObject());
		value->setThisClassObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setClassValue(m_ExtensionValue->getMetaclass());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Extension_ownedEnd())
	{
		std::cout << __PRETTY_FUNCTION__ << ": multiplicity conflict between property 'ownedEnd[1..1]' and redefined property 'ownedEnd[0..-1]'" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency())
	{
		std::shared_ptr<Bag<uml::Dependency>> clientDependencyList = m_ExtensionValue->getClientDependency();
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
		value->setValue(m_ExtensionValue->getName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<UML::StringExpressionObject> value(new UML::StringExpressionObject());
		value->setThisStringExpressionObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setStringExpressionValue(m_ExtensionValue->getNameExpression());
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
		value->setNamespaceValue(m_ExtensionValue->getNamespace().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_qualifiedName())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
		value->setValue(m_ExtensionValue->getQualifiedName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		uml::VisibilityKind visibility = m_ExtensionValue->getVisibility();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_elementImport())
	{
		std::shared_ptr<SubsetUnion<uml::ElementImport, uml::Element>> elementImportList = m_ExtensionValue->getElementImport();
		Bag<uml::ElementImport>::iterator iter = elementImportList->begin();
		Bag<uml::ElementImport>::iterator end = elementImportList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ElementImportObject> value(new UML::ElementImportObject());
			value->setThisElementImportObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setElementImportValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_importedMember())
	{
		std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement>> importedMemberList = m_ExtensionValue->getImportedMember();
		Bag<uml::PackageableElement>::iterator iter = importedMemberList->begin();
		Bag<uml::PackageableElement>::iterator end = importedMemberList->end();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_member())
	{
		std::shared_ptr<Union<uml::NamedElement>> memberList = m_ExtensionValue->getMember();
		Bag<uml::NamedElement>::iterator iter = memberList->begin();
		Bag<uml::NamedElement>::iterator end = memberList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::NamedElementObject> value(new UML::NamedElementObject());
			value->setThisNamedElementObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setNamedElementValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedMember())
	{
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> ownedMemberList = m_ExtensionValue->getOwnedMember();
		Bag<uml::NamedElement>::iterator iter = ownedMemberList->begin();
		Bag<uml::NamedElement>::iterator end = ownedMemberList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::NamedElementObject> value(new UML::NamedElementObject());
			value->setThisNamedElementObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setNamedElementValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedRule())
	{
		std::shared_ptr<SubsetUnion<uml::Constraint, uml::NamedElement>> ownedRuleList = m_ExtensionValue->getOwnedRule();
		Bag<uml::Constraint>::iterator iter = ownedRuleList->begin();
		Bag<uml::Constraint>::iterator end = ownedRuleList->end();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_packageImport())
	{
		std::shared_ptr<SubsetUnion<uml::PackageImport, uml::Element>> packageImportList = m_ExtensionValue->getPackageImport();
		Bag<uml::PackageImport>::iterator iter = packageImportList->begin();
		Bag<uml::PackageImport>::iterator end = packageImportList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::PackageImportObject> value(new UML::PackageImportObject());
			value->setThisPackageImportObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setPackageImportValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_PackageableElement_visibility())
	{
		uml::VisibilityKind visibility = m_ExtensionValue->getVisibility();
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
		value->setTemplateParameterValue(m_ExtensionValue->getOwningTemplateParameter().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_templateParameter())
	{
		std::shared_ptr<UML::TemplateParameterObject> value(new UML::TemplateParameterObject());
		value->setThisTemplateParameterObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setTemplateParameterValue(m_ExtensionValue->getTemplateParameter());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ExtensionValue->getIsLeaf());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinedElement())
	{
		std::shared_ptr<Union<uml::RedefinableElement>> redefinedElementList = m_ExtensionValue->getRedefinedElement();
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
		std::shared_ptr<Union<uml::Classifier>> redefinitionContextList = m_ExtensionValue->getRedefinitionContext();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Relationship_relatedElement())
	{
		std::shared_ptr<Union<uml::Element>> relatedElementList = m_ExtensionValue->getRelatedElement();
		Bag<uml::Element>::iterator iter = relatedElementList->begin();
		Bag<uml::Element>::iterator end = relatedElementList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ElementObject> value(new UML::ElementObject());
			value->setThisElementObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setElementValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_ownedTemplateSignature())
	{
		std::shared_ptr<UML::TemplateSignatureObject> value(new UML::TemplateSignatureObject());
		value->setThisTemplateSignatureObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setTemplateSignatureValue(m_ExtensionValue->getOwnedTemplateSignature());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding())
	{
		std::shared_ptr<Subset<uml::TemplateBinding, uml::Element>> templateBindingList = m_ExtensionValue->getTemplateBinding();
		Bag<uml::TemplateBinding>::iterator iter = templateBindingList->begin();
		Bag<uml::TemplateBinding>::iterator end = templateBindingList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::TemplateBindingObject> value(new UML::TemplateBindingObject());
			value->setThisTemplateBindingObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setTemplateBindingValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Type_package())
	{
		std::shared_ptr<UML::PackageObject> value(new UML::PackageObject());
		value->setThisPackageObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setPackageValue(m_ExtensionValue->getPackage().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	return values;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> ExtensionObject::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
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


void ExtensionObject::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ExtensionValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ExtensionObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (values->size() == 0)
	{
		std::cout << __PRETTY_FUNCTION__ << ": no input value given" << std::endl;
		return;
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Association_isDerived())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ExtensionValue->setIsDerived(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Association_memberEnd())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getMemberEnd()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::PropertyObject> value = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getMemberEnd()->push_back(value->getPropertyValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Association_navigableOwnedEnd())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getNavigableOwnedEnd()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::PropertyObject> value = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getNavigableOwnedEnd()->push_back(value->getPropertyValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Association_ownedEnd())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getOwnedEnd()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::PropertyObject> value = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getOwnedEnd()->push_back(value->getPropertyValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_collaborationUse())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getCollaborationUse()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CollaborationUseObject> value = std::dynamic_pointer_cast<UML::CollaborationUseObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getCollaborationUse()->push_back(value->getCollaborationUseValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_general())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getGeneral()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ClassifierObject> value = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getGeneral()->push_back(value->getClassifierValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_generalization())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getGeneralization()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::GeneralizationObject> value = std::dynamic_pointer_cast<UML::GeneralizationObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getGeneralization()->push_back(value->getGeneralizationValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_isAbstract())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ExtensionValue->setIsAbstract(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_isFinalSpecialization())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ExtensionValue->setIsFinalSpecialization(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::RedefinableTemplateSignatureObject> value = std::dynamic_pointer_cast<UML::RedefinableTemplateSignatureObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ExtensionValue->setOwnedTemplateSignature(value->getRedefinableTemplateSignatureValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getOwnedUseCase()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::UseCaseObject> value = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getOwnedUseCase()->push_back(value->getUseCaseValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_powertypeExtent())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getPowertypeExtent()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::GeneralizationSetObject> value = std::dynamic_pointer_cast<UML::GeneralizationSetObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getPowertypeExtent()->push_back(value->getGeneralizationSetValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_redefinedClassifier())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getRedefinedClassifier()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ClassifierObject> value = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getRedefinedClassifier()->push_back(value->getClassifierValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_representation())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::CollaborationUseObject> value = std::dynamic_pointer_cast<UML::CollaborationUseObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ExtensionValue->setRepresentation(value->getCollaborationUseValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getSubstitution()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::SubstitutionObject> value = std::dynamic_pointer_cast<UML::SubstitutionObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getSubstitution()->push_back(value->getSubstitutionValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_templateParameter())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ClassifierTemplateParameterObject> value = std::dynamic_pointer_cast<UML::ClassifierTemplateParameterObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ExtensionValue->setTemplateParameter(value->getClassifierTemplateParameterValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getUseCase()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::UseCaseObject> value = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getUseCase()->push_back(value->getUseCaseValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getOwnedComment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CommentObject> value = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getOwnedComment()->push_back(value->getCommentValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Extension_ownedEnd())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::ExtensionEndObject> value = std::dynamic_pointer_cast<UML::ExtensionEndObject>(reference->getReferent());
		if (value != nullptr)
		{
				std::cout << __PRETTY_FUNCTION__ << ": multiplicity conflict between property 'ownedEnd[1..1]' and redefined property 'ownedEnd[0..-1]'" << std::endl;
				exit(EXIT_FAILURE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ExtensionValue->setName(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::StringExpressionObject> value = std::dynamic_pointer_cast<UML::StringExpressionObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ExtensionValue->setNameExpression(value->getStringExpressionValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(inputValue);
		std::shared_ptr<uml::EnumerationLiteral> literal = enumValue->getLiteral();
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_public())
		{
			m_ExtensionValue->setVisibility(uml::VisibilityKind::PUBLIC);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_private())
		{
			m_ExtensionValue->setVisibility(uml::VisibilityKind::PRIVATE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_protected())
		{
			m_ExtensionValue->setVisibility(uml::VisibilityKind::PROTECTED);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_package())
		{
			m_ExtensionValue->setVisibility(uml::VisibilityKind::PACKAGE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_elementImport())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getElementImport()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ElementImportObject> value = std::dynamic_pointer_cast<UML::ElementImportObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getElementImport()->push_back(value->getElementImportValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedRule())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getOwnedRule()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ConstraintObject> value = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getOwnedRule()->push_back(value->getConstraintValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_packageImport())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getPackageImport()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::PackageImportObject> value = std::dynamic_pointer_cast<UML::PackageImportObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getPackageImport()->push_back(value->getPackageImportValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_PackageableElement_visibility())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(inputValue);
		std::shared_ptr<uml::EnumerationLiteral> literal = enumValue->getLiteral();
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_public())
		{
			m_ExtensionValue->setVisibility(uml::VisibilityKind::PUBLIC);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_private())
		{
			m_ExtensionValue->setVisibility(uml::VisibilityKind::PRIVATE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_protected())
		{
			m_ExtensionValue->setVisibility(uml::VisibilityKind::PROTECTED);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_package())
		{
			m_ExtensionValue->setVisibility(uml::VisibilityKind::PACKAGE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_templateParameter())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::TemplateParameterObject> value = std::dynamic_pointer_cast<UML::TemplateParameterObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ExtensionValue->setTemplateParameter(value->getTemplateParameterValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ExtensionValue->setIsLeaf(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_ownedTemplateSignature())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::TemplateSignatureObject> value = std::dynamic_pointer_cast<UML::TemplateSignatureObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ExtensionValue->setOwnedTemplateSignature(value->getTemplateSignatureValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ExtensionValue->getTemplateBinding()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::TemplateBindingObject> value = std::dynamic_pointer_cast<UML::TemplateBindingObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ExtensionValue->getTemplateBinding()->push_back(value->getTemplateBindingValue());
			}
			
			iter++;
		}
	}
}

void ExtensionObject::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	this->setFeatureValue(feature, values, position);
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> ExtensionObject::retrieveFeatureValues()
{
	std::shared_ptr<uml::Classifier> type = this->getTypes()->at(0);
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAllAttributes();
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	
	unsigned int allAttributesSize = allAttributes->size();

	for(unsigned int i = 0; i < allAttributesSize; i++)
	{
		std::shared_ptr<uml::Property> property = allAttributes->at(i);
		if (property == UML::UMLPackage::eInstance()->get_UML_Association_endType() && m_ExtensionValue->getEndType() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Association_memberEnd() && m_ExtensionValue->getMemberEnd() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Association_navigableOwnedEnd() && m_ExtensionValue->getNavigableOwnedEnd() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Association_ownedEnd() && m_ExtensionValue->getOwnedEnd() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_attribute() && m_ExtensionValue->getAttribute() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_collaborationUse() && m_ExtensionValue->getCollaborationUse() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_feature() && m_ExtensionValue->getFeature() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_general() && m_ExtensionValue->getGeneral() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_generalization() && m_ExtensionValue->getGeneralization() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_inheritedMember() && m_ExtensionValue->getInheritedMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature() && m_ExtensionValue->getOwnedTemplateSignature() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase() && m_ExtensionValue->getOwnedUseCase() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_powertypeExtent() && m_ExtensionValue->getPowertypeExtent() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_redefinedClassifier() && m_ExtensionValue->getRedefinedClassifier() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_representation() && m_ExtensionValue->getRepresentation() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution() && m_ExtensionValue->getSubstitution() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_templateParameter() && m_ExtensionValue->getTemplateParameter() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase() && m_ExtensionValue->getUseCase() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment() && m_ExtensionValue->getOwnedComment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement() && m_ExtensionValue->getOwnedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_owner() && m_ExtensionValue->getOwner().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Extension_metaclass() && m_ExtensionValue->getMetaclass() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Extension_ownedEnd() && m_ExtensionValue->getOwnedEnd() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency() && m_ExtensionValue->getClientDependency() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression() && m_ExtensionValue->getNameExpression() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_namespace() && m_ExtensionValue->getNamespace().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_elementImport() && m_ExtensionValue->getElementImport() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_importedMember() && m_ExtensionValue->getImportedMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_member() && m_ExtensionValue->getMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedMember() && m_ExtensionValue->getOwnedMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedRule() && m_ExtensionValue->getOwnedRule() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_packageImport() && m_ExtensionValue->getPackageImport() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_owningTemplateParameter() && m_ExtensionValue->getOwningTemplateParameter().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_templateParameter() && m_ExtensionValue->getTemplateParameter() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinedElement() && m_ExtensionValue->getRedefinedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinitionContext() && m_ExtensionValue->getRedefinitionContext() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Relationship_relatedElement() && m_ExtensionValue->getRelatedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_ownedTemplateSignature() && m_ExtensionValue->getOwnedTemplateSignature() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding() && m_ExtensionValue->getTemplateBinding() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Type_package() && m_ExtensionValue->getPackage().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
	}
	
	return featureValues;
}

