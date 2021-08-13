#include "umlReflectionExec/DeploymentSpecificationObject.hpp"

//General Includes
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/DeploymentSpecification.hpp"
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
#include "fUML/Semantics/SimpleClassifiers/StringValue.hpp"
#include "uml/Manifestation.hpp"
#include "umlReflectionExec/ManifestationObject.hpp"
#include "uml/Artifact.hpp"
#include "umlReflectionExec/ArtifactObject.hpp"
#include "uml/Property.hpp"
#include "umlReflectionExec/PropertyObject.hpp"
#include "uml/Operation.hpp"
#include "umlReflectionExec/OperationObject.hpp"
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
#include "uml/Deployment.hpp"
#include "umlReflectionExec/DeploymentObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/StringValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/StringValue.hpp"
#include "uml/Comment.hpp"
#include "umlReflectionExec/CommentObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
#include "uml/Element.hpp"
#include "umlReflectionExec/ElementObject.hpp"
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
#include "uml/TemplateSignature.hpp"
#include "umlReflectionExec/TemplateSignatureObject.hpp"
#include "uml/TemplateBinding.hpp"
#include "umlReflectionExec/TemplateBindingObject.hpp"
#include "uml/Package.hpp"
#include "umlReflectionExec/PackageObject.hpp"
//Property Packages Includes
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"


using namespace UML;

DeploymentSpecificationObject::DeploymentSpecificationObject(std::shared_ptr<uml::DeploymentSpecification> _element):
	m_DeploymentSpecificationValue(_element)
{
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_DeploymentSpecification());
}

DeploymentSpecificationObject::DeploymentSpecificationObject(DeploymentSpecificationObject &obj):
	CS_ObjectImpl(obj)
{
	*this = obj;
}

DeploymentSpecificationObject::DeploymentSpecificationObject()
{	
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_DeploymentSpecification());
}

DeploymentSpecificationObject::~DeploymentSpecificationObject()
{
}

std::shared_ptr<ecore::EObject> DeploymentSpecificationObject::copy()
{
	std::shared_ptr<DeploymentSpecificationObject> element(new DeploymentSpecificationObject());
	*element=(*this);
	element->setThisDeploymentSpecificationObjectPtr(element);
	return element;
}

DeploymentSpecificationObject& DeploymentSpecificationObject::operator=(const DeploymentSpecificationObject & obj)
{
	UML::ArtifactObject::operator=(obj);
	return *this;
}


void DeploymentSpecificationObject::destroy()
{	
	m_DeploymentSpecificationValue.reset();

	fUML::Semantics::StructuredClassifiers::ObjectImpl::destroy();
}

std::shared_ptr<uml::Element> DeploymentSpecificationObject::getUmlValue() const
{
	return getDeploymentSpecificationValue();
}

std::shared_ptr<uml::DeploymentSpecification> DeploymentSpecificationObject::getDeploymentSpecificationValue() const
{
	return m_DeploymentSpecificationValue;
}

void DeploymentSpecificationObject::setUmlValue(std::shared_ptr<uml::Element> _element)
{
	setDeploymentSpecificationValue(std::dynamic_pointer_cast<uml::DeploymentSpecification>(_element));
}

void DeploymentSpecificationObject::setDeploymentSpecificationValue(std::shared_ptr<uml::DeploymentSpecification> _DeploymentSpecificationElement)
{
	m_DeploymentSpecificationValue = _DeploymentSpecificationElement;
	//set super type values
	UML::ArtifactObject::setArtifactValue(_DeploymentSpecificationElement);
}

void DeploymentSpecificationObject::setThisDeploymentSpecificationObjectPtr(std::weak_ptr<DeploymentSpecificationObject> thisObjectPtr)
{
	setThisCS_ObjectPtr(thisObjectPtr);
}

bool DeploymentSpecificationObject::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	bool isEqual = false;
	
	std::shared_ptr<DeploymentSpecificationObject> otherDeploymentSpecificationObject = std::dynamic_pointer_cast<DeploymentSpecificationObject>(otherValue);

	if(otherDeploymentSpecificationObject != nullptr)
	{
		if(this->getDeploymentSpecificationValue() == otherDeploymentSpecificationObject->getDeploymentSpecificationValue())
		{
			isEqual = true;
		}
	}

	return isEqual;
}

std::string DeploymentSpecificationObject::toString()
{
	std::string buffer = "Instance of 'DeploymentSpecificationObject', " + std::to_string(getTypes()->size()) + " types (";
	for(unsigned int i = 0; i < getTypes()->size(); ++i)
	{
		buffer += "type{" + std::to_string(i) + "}: '" + getTypes()->at(i)->getName() + "', ";
	}
	buffer +=")";

	return buffer;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> DeploymentSpecificationObject::getDirectContainers()
{   
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());

	/*Not done for metamodel object classes*/

	return directContainers;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> DeploymentSpecificationObject::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> allLinks(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());

	/*Not done for metamodel object classes*/

	return allLinks;
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> DeploymentSpecificationObject::retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end)
{
	/*Not done for metamodel object classes*/

	return nullptr;
}

void DeploymentSpecificationObject::removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_DeploymentSpecificationValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside DeploymentSpecificationObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_fileName())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_manifestation())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getManifestation()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ManifestationObject> inputValue = std::dynamic_pointer_cast<UML::ManifestationObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getManifestation()->erase(inputValue->getManifestationValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_nestedArtifact())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getNestedArtifact()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ArtifactObject> inputValue = std::dynamic_pointer_cast<UML::ArtifactObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getNestedArtifact()->erase(inputValue->getArtifactValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_ownedAttribute())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getOwnedAttribute()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::PropertyObject> inputValue = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getOwnedAttribute()->erase(inputValue->getPropertyValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_ownedOperation())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getOwnedOperation()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::OperationObject> inputValue = std::dynamic_pointer_cast<UML::OperationObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getOwnedOperation()->erase(inputValue->getOperationValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_collaborationUse())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getCollaborationUse()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CollaborationUseObject> inputValue = std::dynamic_pointer_cast<UML::CollaborationUseObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getCollaborationUse()->erase(inputValue->getCollaborationUseValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_general())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getGeneral()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ClassifierObject> inputValue = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getGeneral()->erase(inputValue->getClassifierValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_generalization())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getGeneralization()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::GeneralizationObject> inputValue = std::dynamic_pointer_cast<UML::GeneralizationObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getGeneralization()->erase(inputValue->getGeneralizationValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_isAbstract())
	{
				m_DeploymentSpecificationValue->setIsAbstract(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_isFinalSpecialization())
	{
				m_DeploymentSpecificationValue->setIsFinalSpecialization(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature())
	{
				m_DeploymentSpecificationValue->getOwnedTemplateSignature().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getOwnedUseCase()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::UseCaseObject> inputValue = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getOwnedUseCase()->erase(inputValue->getUseCaseValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_powertypeExtent())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getPowertypeExtent()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::GeneralizationSetObject> inputValue = std::dynamic_pointer_cast<UML::GeneralizationSetObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getPowertypeExtent()->erase(inputValue->getGeneralizationSetValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_redefinedClassifier())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getRedefinedClassifier()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ClassifierObject> inputValue = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getRedefinedClassifier()->erase(inputValue->getClassifierValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_representation())
	{
				m_DeploymentSpecificationValue->getRepresentation().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getSubstitution()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::SubstitutionObject> inputValue = std::dynamic_pointer_cast<UML::SubstitutionObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getSubstitution()->erase(inputValue->getSubstitutionValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_templateParameter())
	{
				m_DeploymentSpecificationValue->getTemplateParameter().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getUseCase()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::UseCaseObject> inputValue = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getUseCase()->erase(inputValue->getUseCaseValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_DeploymentSpecification_deployment())
	{
				m_DeploymentSpecificationValue->getDeployment().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_DeploymentSpecification_deploymentLocation())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_DeploymentSpecification_executionLocation())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getOwnedComment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CommentObject> inputValue = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getOwnedComment()->erase(inputValue->getCommentValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
				m_DeploymentSpecificationValue->getNameExpression().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_elementImport())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getElementImport()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ElementImportObject> inputValue = std::dynamic_pointer_cast<UML::ElementImportObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getElementImport()->erase(inputValue->getElementImportValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedRule())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getOwnedRule()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ConstraintObject> inputValue = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getOwnedRule()->erase(inputValue->getConstraintValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_packageImport())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getPackageImport()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::PackageImportObject> inputValue = std::dynamic_pointer_cast<UML::PackageImportObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getPackageImport()->erase(inputValue->getPackageImportValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_PackageableElement_visibility())
	{
				m_DeploymentSpecificationValue->setVisibility(uml::VisibilityKind::PUBLIC /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_owningTemplateParameter())
	{
				m_DeploymentSpecificationValue->getOwningTemplateParameter().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_templateParameter())
	{
				m_DeploymentSpecificationValue->getTemplateParameter().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
				m_DeploymentSpecificationValue->setIsLeaf(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_ownedTemplateSignature())
	{
				m_DeploymentSpecificationValue->getOwnedTemplateSignature().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding())
	{
		if (value == nullptr) // clear mode
		{
			m_DeploymentSpecificationValue->getTemplateBinding()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::TemplateBindingObject> inputValue = std::dynamic_pointer_cast<UML::TemplateBindingObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_DeploymentSpecificationValue->getTemplateBinding()->erase(inputValue->getTemplateBindingValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Type_package())
	{
				m_DeploymentSpecificationValue->getPackage().reset();

	}
}


std::shared_ptr<Bag<fUML::Semantics::Values::Value>> DeploymentSpecificationObject::getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_DeploymentSpecificationValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside DeploymentSpecificationObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_fileName())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
		value->setValue(m_DeploymentSpecificationValue->getFileName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_manifestation())
	{
		std::shared_ptr<Subset<uml::Manifestation, uml::Element>> manifestationList = m_DeploymentSpecificationValue->getManifestation();
		Bag<uml::Manifestation>::iterator iter = manifestationList->begin();
		Bag<uml::Manifestation>::iterator end = manifestationList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ManifestationObject> value(new UML::ManifestationObject());
			value->setThisManifestationObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setManifestationValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_nestedArtifact())
	{
		std::shared_ptr<Subset<uml::Artifact, uml::NamedElement>> nestedArtifactList = m_DeploymentSpecificationValue->getNestedArtifact();
		Bag<uml::Artifact>::iterator iter = nestedArtifactList->begin();
		Bag<uml::Artifact>::iterator end = nestedArtifactList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ArtifactObject> value(new UML::ArtifactObject());
			value->setThisArtifactObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setArtifactValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_ownedAttribute())
	{
		std::shared_ptr<Subset<uml::Property, uml::NamedElement, uml::Property>> ownedAttributeList = m_DeploymentSpecificationValue->getOwnedAttribute();
		Bag<uml::Property>::iterator iter = ownedAttributeList->begin();
		Bag<uml::Property>::iterator end = ownedAttributeList->end();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_ownedOperation())
	{
		std::shared_ptr<Subset<uml::Operation, uml::Feature, uml::NamedElement>> ownedOperationList = m_DeploymentSpecificationValue->getOwnedOperation();
		Bag<uml::Operation>::iterator iter = ownedOperationList->begin();
		Bag<uml::Operation>::iterator end = ownedOperationList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::OperationObject> value(new UML::OperationObject());
			value->setThisOperationObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setOperationValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_attribute())
	{
		std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> attributeList = m_DeploymentSpecificationValue->getAttribute();
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
		std::shared_ptr<SubsetUnion<uml::CollaborationUse, uml::Element>> collaborationUseList = m_DeploymentSpecificationValue->getCollaborationUse();
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
		std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> featureList = m_DeploymentSpecificationValue->getFeature();
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
		std::shared_ptr<Bag<uml::Classifier>> generalList = m_DeploymentSpecificationValue->getGeneral();
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
		std::shared_ptr<Subset<uml::Generalization, uml::Element>> generalizationList = m_DeploymentSpecificationValue->getGeneralization();
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
		std::shared_ptr<Subset<uml::NamedElement, uml::NamedElement>> inheritedMemberList = m_DeploymentSpecificationValue->getInheritedMember();
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
		value->setValue(m_DeploymentSpecificationValue->getIsAbstract());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_isFinalSpecialization())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_DeploymentSpecificationValue->getIsFinalSpecialization());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature())
	{
		std::shared_ptr<UML::RedefinableTemplateSignatureObject> value(new UML::RedefinableTemplateSignatureObject());
		value->setThisRedefinableTemplateSignatureObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setRedefinableTemplateSignatureValue(std::dynamic_pointer_cast<uml::RedefinableTemplateSignature>(m_DeploymentSpecificationValue->getOwnedTemplateSignature()));
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase())
	{
		std::shared_ptr<Subset<uml::UseCase, uml::NamedElement>> ownedUseCaseList = m_DeploymentSpecificationValue->getOwnedUseCase();
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
		std::shared_ptr<Bag<uml::GeneralizationSet>> powertypeExtentList = m_DeploymentSpecificationValue->getPowertypeExtent();
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
		std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement>> redefinedClassifierList = m_DeploymentSpecificationValue->getRedefinedClassifier();
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
		value->setCollaborationUseValue(m_DeploymentSpecificationValue->getRepresentation());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution())
	{
		std::shared_ptr<Subset<uml::Substitution, uml::Element>> substitutionList = m_DeploymentSpecificationValue->getSubstitution();
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
		value->setClassifierTemplateParameterValue(std::dynamic_pointer_cast<uml::ClassifierTemplateParameter>(m_DeploymentSpecificationValue->getTemplateParameter()));
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase())
	{
		std::shared_ptr<Bag<uml::UseCase>> useCaseList = m_DeploymentSpecificationValue->getUseCase();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_DeploymentSpecification_deployment())
	{
		std::shared_ptr<UML::DeploymentObject> value(new UML::DeploymentObject());
		value->setThisDeploymentObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setDeploymentValue(m_DeploymentSpecificationValue->getDeployment().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_DeploymentSpecification_deploymentLocation())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
		value->setValue(m_DeploymentSpecificationValue->getDeploymentLocation());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_DeploymentSpecification_executionLocation())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
		value->setValue(m_DeploymentSpecificationValue->getExecutionLocation());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		std::shared_ptr<Subset<uml::Comment, uml::Element>> ownedCommentList = m_DeploymentSpecificationValue->getOwnedComment();
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
		std::shared_ptr<Union<uml::Element>> ownedElementList = m_DeploymentSpecificationValue->getOwnedElement();
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
		value->setElementValue(m_DeploymentSpecificationValue->getOwner().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency())
	{
		std::shared_ptr<Bag<uml::Dependency>> clientDependencyList = m_DeploymentSpecificationValue->getClientDependency();
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
		value->setValue(m_DeploymentSpecificationValue->getName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<UML::StringExpressionObject> value(new UML::StringExpressionObject());
		value->setThisStringExpressionObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setStringExpressionValue(m_DeploymentSpecificationValue->getNameExpression());
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
		value->setNamespaceValue(m_DeploymentSpecificationValue->getNamespace().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_qualifiedName())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
		value->setValue(m_DeploymentSpecificationValue->getQualifiedName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		uml::VisibilityKind visibility = m_DeploymentSpecificationValue->getVisibility();
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
		std::shared_ptr<SubsetUnion<uml::ElementImport, uml::Element>> elementImportList = m_DeploymentSpecificationValue->getElementImport();
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
		std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement>> importedMemberList = m_DeploymentSpecificationValue->getImportedMember();
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
		std::shared_ptr<Union<uml::NamedElement>> memberList = m_DeploymentSpecificationValue->getMember();
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
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> ownedMemberList = m_DeploymentSpecificationValue->getOwnedMember();
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
		std::shared_ptr<SubsetUnion<uml::Constraint, uml::NamedElement>> ownedRuleList = m_DeploymentSpecificationValue->getOwnedRule();
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
		std::shared_ptr<SubsetUnion<uml::PackageImport, uml::Element>> packageImportList = m_DeploymentSpecificationValue->getPackageImport();
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
		uml::VisibilityKind visibility = m_DeploymentSpecificationValue->getVisibility();
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
		value->setTemplateParameterValue(m_DeploymentSpecificationValue->getOwningTemplateParameter().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_templateParameter())
	{
		std::shared_ptr<UML::TemplateParameterObject> value(new UML::TemplateParameterObject());
		value->setThisTemplateParameterObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setTemplateParameterValue(m_DeploymentSpecificationValue->getTemplateParameter());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_DeploymentSpecificationValue->getIsLeaf());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinedElement())
	{
		std::shared_ptr<Union<uml::RedefinableElement>> redefinedElementList = m_DeploymentSpecificationValue->getRedefinedElement();
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
		std::shared_ptr<Union<uml::Classifier>> redefinitionContextList = m_DeploymentSpecificationValue->getRedefinitionContext();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_ownedTemplateSignature())
	{
		std::shared_ptr<UML::TemplateSignatureObject> value(new UML::TemplateSignatureObject());
		value->setThisTemplateSignatureObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setTemplateSignatureValue(m_DeploymentSpecificationValue->getOwnedTemplateSignature());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding())
	{
		std::shared_ptr<Subset<uml::TemplateBinding, uml::Element>> templateBindingList = m_DeploymentSpecificationValue->getTemplateBinding();
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
		value->setPackageValue(m_DeploymentSpecificationValue->getPackage().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	return values;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> DeploymentSpecificationObject::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
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


void DeploymentSpecificationObject::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	if (feature->getMetaElementID() != uml::umlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::umlPackage::PORT_CLASS && feature->getMetaElementID() != uml::umlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_DeploymentSpecificationValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside DeploymentSpecificationObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (values->size() == 0)
	{
		std::cout << __PRETTY_FUNCTION__ << ": no input value given" << std::endl;
		return;
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_fileName())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_DeploymentSpecificationValue->setFileName(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_manifestation())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getManifestation()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ManifestationObject> value = std::dynamic_pointer_cast<UML::ManifestationObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getManifestation()->push_back(value->getManifestationValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_nestedArtifact())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getNestedArtifact()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ArtifactObject> value = std::dynamic_pointer_cast<UML::ArtifactObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getNestedArtifact()->push_back(value->getArtifactValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_ownedAttribute())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getOwnedAttribute()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::PropertyObject> value = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getOwnedAttribute()->push_back(value->getPropertyValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Artifact_ownedOperation())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getOwnedOperation()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::OperationObject> value = std::dynamic_pointer_cast<UML::OperationObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getOwnedOperation()->push_back(value->getOperationValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_collaborationUse())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getCollaborationUse()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CollaborationUseObject> value = std::dynamic_pointer_cast<UML::CollaborationUseObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getCollaborationUse()->push_back(value->getCollaborationUseValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_general())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getGeneral()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ClassifierObject> value = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getGeneral()->push_back(value->getClassifierValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_generalization())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getGeneralization()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::GeneralizationObject> value = std::dynamic_pointer_cast<UML::GeneralizationObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getGeneralization()->push_back(value->getGeneralizationValue());
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
			m_DeploymentSpecificationValue->setIsAbstract(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_isFinalSpecialization())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_DeploymentSpecificationValue->setIsFinalSpecialization(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::RedefinableTemplateSignatureObject> value = std::dynamic_pointer_cast<UML::RedefinableTemplateSignatureObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_DeploymentSpecificationValue->setOwnedTemplateSignature(value->getRedefinableTemplateSignatureValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getOwnedUseCase()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::UseCaseObject> value = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getOwnedUseCase()->push_back(value->getUseCaseValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_powertypeExtent())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getPowertypeExtent()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::GeneralizationSetObject> value = std::dynamic_pointer_cast<UML::GeneralizationSetObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getPowertypeExtent()->push_back(value->getGeneralizationSetValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_redefinedClassifier())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getRedefinedClassifier()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ClassifierObject> value = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getRedefinedClassifier()->push_back(value->getClassifierValue());
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
			m_DeploymentSpecificationValue->setRepresentation(value->getCollaborationUseValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getSubstitution()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::SubstitutionObject> value = std::dynamic_pointer_cast<UML::SubstitutionObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getSubstitution()->push_back(value->getSubstitutionValue());
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
			m_DeploymentSpecificationValue->setTemplateParameter(value->getClassifierTemplateParameterValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getUseCase()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::UseCaseObject> value = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getUseCase()->push_back(value->getUseCaseValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_DeploymentSpecification_deploymentLocation())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_DeploymentSpecificationValue->setDeploymentLocation(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_DeploymentSpecification_executionLocation())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_DeploymentSpecificationValue->setExecutionLocation(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getOwnedComment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CommentObject> value = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getOwnedComment()->push_back(value->getCommentValue());
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
			m_DeploymentSpecificationValue->setName(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::StringExpressionObject> value = std::dynamic_pointer_cast<UML::StringExpressionObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_DeploymentSpecificationValue->setNameExpression(value->getStringExpressionValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(inputValue);
		std::shared_ptr<uml::EnumerationLiteral> literal = enumValue->getLiteral();
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_public())
		{
			m_DeploymentSpecificationValue->setVisibility(uml::VisibilityKind::PUBLIC);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_private())
		{
			m_DeploymentSpecificationValue->setVisibility(uml::VisibilityKind::PRIVATE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_protected())
		{
			m_DeploymentSpecificationValue->setVisibility(uml::VisibilityKind::PROTECTED);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_package())
		{
			m_DeploymentSpecificationValue->setVisibility(uml::VisibilityKind::PACKAGE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_elementImport())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getElementImport()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ElementImportObject> value = std::dynamic_pointer_cast<UML::ElementImportObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getElementImport()->push_back(value->getElementImportValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedRule())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getOwnedRule()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ConstraintObject> value = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getOwnedRule()->push_back(value->getConstraintValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_packageImport())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getPackageImport()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::PackageImportObject> value = std::dynamic_pointer_cast<UML::PackageImportObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getPackageImport()->push_back(value->getPackageImportValue());
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
			m_DeploymentSpecificationValue->setVisibility(uml::VisibilityKind::PUBLIC);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_private())
		{
			m_DeploymentSpecificationValue->setVisibility(uml::VisibilityKind::PRIVATE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_protected())
		{
			m_DeploymentSpecificationValue->setVisibility(uml::VisibilityKind::PROTECTED);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_package())
		{
			m_DeploymentSpecificationValue->setVisibility(uml::VisibilityKind::PACKAGE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_templateParameter())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::TemplateParameterObject> value = std::dynamic_pointer_cast<UML::TemplateParameterObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_DeploymentSpecificationValue->setTemplateParameter(value->getTemplateParameterValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_DeploymentSpecificationValue->setIsLeaf(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_ownedTemplateSignature())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::TemplateSignatureObject> value = std::dynamic_pointer_cast<UML::TemplateSignatureObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_DeploymentSpecificationValue->setOwnedTemplateSignature(value->getTemplateSignatureValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_DeploymentSpecificationValue->getTemplateBinding()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::TemplateBindingObject> value = std::dynamic_pointer_cast<UML::TemplateBindingObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_DeploymentSpecificationValue->getTemplateBinding()->push_back(value->getTemplateBindingValue());
			}
			
			iter++;
		}
	}
}

void DeploymentSpecificationObject::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	this->setFeatureValue(feature, values, position);
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> DeploymentSpecificationObject::retrieveFeatureValues()
{
	std::shared_ptr<uml::Classifier> type = this->getTypes()->at(0);
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAllAttributes();
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	
	unsigned int allAttributesSize = allAttributes->size();

	for(unsigned int i = 0; i < allAttributesSize; i++)
	{
		std::shared_ptr<uml::Property> property = allAttributes->at(i);
		if (property == UML::UMLPackage::eInstance()->get_UML_Artifact_manifestation() && m_DeploymentSpecificationValue->getManifestation() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Artifact_nestedArtifact() && m_DeploymentSpecificationValue->getNestedArtifact() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Artifact_ownedAttribute() && m_DeploymentSpecificationValue->getOwnedAttribute() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Artifact_ownedOperation() && m_DeploymentSpecificationValue->getOwnedOperation() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_attribute() && m_DeploymentSpecificationValue->getAttribute() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_collaborationUse() && m_DeploymentSpecificationValue->getCollaborationUse() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_feature() && m_DeploymentSpecificationValue->getFeature() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_general() && m_DeploymentSpecificationValue->getGeneral() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_generalization() && m_DeploymentSpecificationValue->getGeneralization() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_inheritedMember() && m_DeploymentSpecificationValue->getInheritedMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature() && m_DeploymentSpecificationValue->getOwnedTemplateSignature() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase() && m_DeploymentSpecificationValue->getOwnedUseCase() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_powertypeExtent() && m_DeploymentSpecificationValue->getPowertypeExtent() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_redefinedClassifier() && m_DeploymentSpecificationValue->getRedefinedClassifier() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_representation() && m_DeploymentSpecificationValue->getRepresentation() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution() && m_DeploymentSpecificationValue->getSubstitution() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_templateParameter() && m_DeploymentSpecificationValue->getTemplateParameter() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase() && m_DeploymentSpecificationValue->getUseCase() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_DeploymentSpecification_deployment() && m_DeploymentSpecificationValue->getDeployment().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment() && m_DeploymentSpecificationValue->getOwnedComment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement() && m_DeploymentSpecificationValue->getOwnedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_owner() && m_DeploymentSpecificationValue->getOwner().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency() && m_DeploymentSpecificationValue->getClientDependency() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression() && m_DeploymentSpecificationValue->getNameExpression() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_namespace() && m_DeploymentSpecificationValue->getNamespace().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_elementImport() && m_DeploymentSpecificationValue->getElementImport() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_importedMember() && m_DeploymentSpecificationValue->getImportedMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_member() && m_DeploymentSpecificationValue->getMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedMember() && m_DeploymentSpecificationValue->getOwnedMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedRule() && m_DeploymentSpecificationValue->getOwnedRule() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_packageImport() && m_DeploymentSpecificationValue->getPackageImport() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_owningTemplateParameter() && m_DeploymentSpecificationValue->getOwningTemplateParameter().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_templateParameter() && m_DeploymentSpecificationValue->getTemplateParameter() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinedElement() && m_DeploymentSpecificationValue->getRedefinedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinitionContext() && m_DeploymentSpecificationValue->getRedefinitionContext() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_ownedTemplateSignature() && m_DeploymentSpecificationValue->getOwnedTemplateSignature() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding() && m_DeploymentSpecificationValue->getTemplateBinding() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Type_package() && m_DeploymentSpecificationValue->getPackage().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
	}
	
	return featureValues;
}

