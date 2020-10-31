#include "umlReflectionExec/ClassObject.hpp"

//General Includes
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/Class.hpp"
#include "umlReflection/UMLPackage.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/Class.hpp"
//Includes From Composite Structures
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
#include "uml/UmlPackage.hpp"
#include "uml/Association.hpp"
#include "uml/Connector.hpp"
#include "uml/ConnectorEnd.hpp"
#include "uml/Operation.hpp"
#include "uml/Property.hpp"
#include "uml/Port.hpp"
//Property Includes
#include "uml/Behavior.hpp"
#include "umlReflectionExec/BehaviorObject.hpp"
#include "uml/InterfaceRealization.hpp"
#include "umlReflectionExec/InterfaceRealizationObject.hpp"
#include "uml/Behavior.hpp"
#include "umlReflectionExec/BehaviorObject.hpp"
#include "uml/Extension.hpp"
#include "umlReflectionExec/ExtensionObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/Classifier.hpp"
#include "umlReflectionExec/ClassifierObject.hpp"
#include "uml/Property.hpp"
#include "umlReflectionExec/PropertyObject.hpp"
#include "uml/Operation.hpp"
#include "umlReflectionExec/OperationObject.hpp"
#include "uml/Reception.hpp"
#include "umlReflectionExec/ReceptionObject.hpp"
#include "uml/Class.hpp"
#include "umlReflectionExec/ClassObject.hpp"
#include "uml/Property.hpp"
#include "umlReflectionExec/PropertyObject.hpp"
#include "uml/CollaborationUse.hpp"
#include "umlReflectionExec/CollaborationUseObject.hpp"
#include "uml/Feature.hpp"
#include "umlReflectionExec/FeatureObject.hpp"
#include "uml/Generalization.hpp"
#include "umlReflectionExec/GeneralizationObject.hpp"
#include "uml/NamedElement.hpp"
#include "umlReflectionExec/NamedElementObject.hpp"
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
#include "uml/Port.hpp"
#include "umlReflectionExec/PortObject.hpp"
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
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/RedefinableElement.hpp"
#include "umlReflectionExec/RedefinableElementObject.hpp"
#include "uml/Classifier.hpp"
#include "umlReflectionExec/ClassifierObject.hpp"
#include "uml/Connector.hpp"
#include "umlReflectionExec/ConnectorObject.hpp"
#include "uml/Property.hpp"
#include "umlReflectionExec/PropertyObject.hpp"
#include "uml/ConnectableElement.hpp"
#include "umlReflectionExec/ConnectableElementObject.hpp"
#include "uml/TemplateBinding.hpp"
#include "umlReflectionExec/TemplateBindingObject.hpp"
#include "uml/Package.hpp"
#include "umlReflectionExec/PackageObject.hpp"
//Property Packages Includes
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"


using namespace UML;

ClassObject::ClassObject(std::shared_ptr<uml::Class> _element):

	m_ClassValue(_element)
{		
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_Class());
}

ClassObject::ClassObject(ClassObject &obj):
	CS_ObjectImpl(obj)
{
}

ClassObject::ClassObject()
{	
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_Class());
}

ClassObject::~ClassObject()
{
}

std::shared_ptr<ecore::EObject> ClassObject::copy()
{
	std::shared_ptr<ClassObject> element(new ClassObject(*this));
	element->setThisClassObjectPtr(element);
	return element;
}

void ClassObject::destroy()
{	
	if(m_ClassValue)
	{

	}

	m_ClassValue.reset();

	fUML::Semantics::StructuredClassifiers::ObjectImpl::destroy();
}

std::shared_ptr<uml::Element> ClassObject::getUmlValue() const
{
	return getClassValue();
}

std::shared_ptr<uml::Class> ClassObject::getClassValue() const
{
	return m_ClassValue;
}

void ClassObject::setUmlValue(std::shared_ptr<uml::Element> _element)
{
	setClassValue(std::dynamic_pointer_cast<uml::Class>(_element));
}

void ClassObject::setClassValue(std::shared_ptr<uml::Class> _ClassElement)
{
	m_ClassValue = _ClassElement;
	//set super type values
	UML::BehavioredClassifierObject::setBehavioredClassifierValue(_ClassElement);
	UML::EncapsulatedClassifierObject::setEncapsulatedClassifierValue(_ClassElement);
}

void ClassObject::setThisClassObjectPtr(std::weak_ptr<ClassObject> thisObjectPtr)
{
	setThisCS_ObjectPtr(thisObjectPtr);
}

bool ClassObject::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	bool isEqual = false;
	
	std::shared_ptr<ClassObject> otherClassObject = std::dynamic_pointer_cast<ClassObject>(otherValue);

	if(otherClassObject != nullptr)
	{
		if(this->getClassValue() == otherClassObject->getClassValue())
		{
			isEqual = true;
		}
	}

	return isEqual;
}

std::string ClassObject::toString()
{
	std::string buffer = "Instance of 'ClassObject', " + std::to_string(getTypes()->size()) + " types (";
	for(unsigned int i = 0; i < getTypes()->size(); ++i)
	{
		buffer += "type{" + std::to_string(i) + "}: '" + getTypes()->at(i)->getName() + "', ";
	}
	buffer +=")";

	return buffer;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> ClassObject::getDirectContainers()
{   
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());
	return directContainers;
}


std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> ClassObject::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> allLinks(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());
	
	//Retrieve all metamodel elements
	std::shared_ptr<Bag<uml::Element>> modelMembers = UML::UMLPackage::eInstance()->allOwnedElements();
	std::shared_ptr<Bag<uml::Connector>> connectors(new Bag<uml::Connector>());
	std::shared_ptr<uml::Port> definingPort = interactionPoint->getDefiningPort();
	
	//Filter model elements for connectors that are connected to interactionPoints' definingPort
	unsigned int membersSize = modelMembers->size();
	for(unsigned int i = 0; i < membersSize; i++)
	{
		std::shared_ptr<uml::Connector> elementAsConnector = std::dynamic_pointer_cast<uml::Connector>(modelMembers->at(i));
		if(elementAsConnector != nullptr)
		{
			std::shared_ptr<uml::ConnectorEnd> end1 = elementAsConnector->getEnd()->at(0);
			std::shared_ptr<uml::ConnectorEnd> end2 = elementAsConnector->getEnd()->at(1);
			
			if((end1->getRole() == definingPort) || (end2->getRole() == definingPort))
			{
				connectors->add(elementAsConnector);
			}
		}
	}

	
	//For each connector that is connected to interactionPoints' definingPort:
	//- retrieve FeatureValue of otherEnd
	//-	create Link and add both interactionPoint as well as retrieved FeatureValue of otherEnd to the links' featureValues property
	//- add Link to allLinks
	unsigned int connectorsSize = connectors->size();
	for(unsigned int i = 0; i < connectorsSize; i++)
	{
		std::shared_ptr<uml::Connector> currentConnector = connectors->at(i);
		unsigned int definingEndIndex = 0, otherEndIndex = 1;
		std::shared_ptr<uml::ConnectorEnd> definingEnd = currentConnector->getEnd()->at(0);
		std::shared_ptr<uml::ConnectorEnd> otherEnd = currentConnector->getEnd()->at(1);
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> otherEndValues(new Bag<fUML::Semantics::Values::Value>());
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> definingEndValues(new Bag<fUML::Semantics::Values::Value>());
		
		definingEndValues->add(interactionPoint);

		if(definingPort == otherEnd->getRole())
		{
			definingEndIndex = 1;
			otherEndIndex = 0; 
			definingEnd = currentConnector->getEnd()->at(1);; 
			otherEnd = currentConnector->getEnd()->at(0);;
		}
		
		std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> dummyBag(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
		otherEndValues = interactionPoint->getReferent()->getValues(currentConnector->getType()->getMemberEnd()->at(otherEndIndex), dummyBag);
			
		//If other end of connector is a port, the corresponding FeatureValue has to be retrieved as CS_InteractionPoint from its owner
		//instead of being retrieved from this connector end as just a CS_Reference
		if(std::dynamic_pointer_cast<uml::Port>(otherEnd->getRole()) != nullptr)
		{
			//otherEndValues->at(0) is passed to retrieve the ports owner later on
			otherEndValues = this->retrieveEndValueAsInteractionPoint(otherEndValues->at(0), otherEnd);
		}
			
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> newLink = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Link();
		newLink->setType(currentConnector->getType());
		newLink->assignFeatureValue(newLink->getType()->getMemberEnd()->at(definingEndIndex), definingEndValues, -1);
		newLink->assignFeatureValue(newLink->getType()->getMemberEnd()->at(otherEndIndex), otherEndValues, -1);
			
		allLinks->add(newLink);
	}
	
	return allLinks;
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ClassObject::retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end)
{
	return nullptr;
}

void ClassObject::removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	if (feature->getMetaElementID() != uml::UmlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::UmlPackage::PORT_CLASS && feature->getMetaElementID() != uml::UmlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ClassValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ClassObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_classifierBehavior())
	{
				m_ClassValue->getClassifierBehavior().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_interfaceRealization())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getInterfaceRealization()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::InterfaceRealizationObject> inputValue = std::dynamic_pointer_cast<UML::InterfaceRealizationObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getInterfaceRealization()->erase(inputValue->getInterfaceRealizationValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_ownedBehavior())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getOwnedBehavior()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::BehaviorObject> inputValue = std::dynamic_pointer_cast<UML::BehaviorObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getOwnedBehavior()->erase(inputValue->getBehaviorValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_isAbstract())
	{
				m_ClassValue->setIsAbstract(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_isActive())
	{
				m_ClassValue->setIsActive(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_nestedClassifier())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getNestedClassifier()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ClassifierObject> inputValue = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getNestedClassifier()->erase(inputValue->getClassifierValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedAttribute())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getOwnedAttribute()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::PropertyObject> inputValue = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getOwnedAttribute()->erase(inputValue->getPropertyValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedOperation())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getOwnedOperation()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::OperationObject> inputValue = std::dynamic_pointer_cast<UML::OperationObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getOwnedOperation()->erase(inputValue->getOperationValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedReception())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getOwnedReception()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ReceptionObject> inputValue = std::dynamic_pointer_cast<UML::ReceptionObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getOwnedReception()->erase(inputValue->getReceptionValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_superClass())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getSuperClass()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ClassObject> inputValue = std::dynamic_pointer_cast<UML::ClassObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getSuperClass()->erase(inputValue->getClassValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_collaborationUse())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getCollaborationUse()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CollaborationUseObject> inputValue = std::dynamic_pointer_cast<UML::CollaborationUseObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getCollaborationUse()->erase(inputValue->getCollaborationUseValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_generalization())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getGeneralization()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::GeneralizationObject> inputValue = std::dynamic_pointer_cast<UML::GeneralizationObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getGeneralization()->erase(inputValue->getGeneralizationValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_isFinalSpecialization())
	{
				m_ClassValue->setIsFinalSpecialization(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature())
	{
				m_ClassValue->getOwnedTemplateSignature().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getOwnedUseCase()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::UseCaseObject> inputValue = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getOwnedUseCase()->erase(inputValue->getUseCaseValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_powertypeExtent())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getPowertypeExtent()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::GeneralizationSetObject> inputValue = std::dynamic_pointer_cast<UML::GeneralizationSetObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getPowertypeExtent()->erase(inputValue->getGeneralizationSetValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_redefinedClassifier())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getRedefinedClassifier()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ClassifierObject> inputValue = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getRedefinedClassifier()->erase(inputValue->getClassifierValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_representation())
	{
				m_ClassValue->getRepresentation().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getSubstitution()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::SubstitutionObject> inputValue = std::dynamic_pointer_cast<UML::SubstitutionObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getSubstitution()->erase(inputValue->getSubstitutionValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_templateParameter())
	{
				m_ClassValue->getTemplateParameter().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getUseCase()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::UseCaseObject> inputValue = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getUseCase()->erase(inputValue->getUseCaseValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getOwnedComment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CommentObject> inputValue = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getOwnedComment()->erase(inputValue->getCommentValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
				m_ClassValue->getNameExpression().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_elementImport())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getElementImport()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ElementImportObject> inputValue = std::dynamic_pointer_cast<UML::ElementImportObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getElementImport()->erase(inputValue->getElementImportValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedRule())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getOwnedRule()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ConstraintObject> inputValue = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getOwnedRule()->erase(inputValue->getConstraintValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_packageImport())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getPackageImport()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::PackageImportObject> inputValue = std::dynamic_pointer_cast<UML::PackageImportObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getPackageImport()->erase(inputValue->getPackageImportValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_PackageableElement_visibility())
	{
				m_ClassValue->setVisibility(uml::VisibilityKind::PUBLIC /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_owningTemplateParameter())
	{
				m_ClassValue->getOwningTemplateParameter().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
				m_ClassValue->setIsLeaf(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_StructuredClassifier_ownedConnector())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getOwnedConnector()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ConnectorObject> inputValue = std::dynamic_pointer_cast<UML::ConnectorObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getOwnedConnector()->erase(inputValue->getConnectorValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding())
	{
		if (value == nullptr) // clear mode
		{
			m_ClassValue->getTemplateBinding()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::TemplateBindingObject> inputValue = std::dynamic_pointer_cast<UML::TemplateBindingObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ClassValue->getTemplateBinding()->erase(inputValue->getTemplateBindingValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Type_package())
	{
				m_ClassValue->getPackage().reset();

	}
}


std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ClassObject::getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	if (feature->getMetaElementID() != uml::UmlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::UmlPackage::PORT_CLASS && feature->getMetaElementID() != uml::UmlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ClassValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ClassObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_classifierBehavior())
	{
		std::shared_ptr<UML::BehaviorObject> value(new UML::BehaviorObject());
		value->setThisBehaviorObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setBehaviorValue(m_ClassValue->getClassifierBehavior());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_interfaceRealization())
	{
		std::shared_ptr<Bag<uml::InterfaceRealization>> interfaceRealizationList = m_ClassValue->getInterfaceRealization();
		Bag<uml::InterfaceRealization>::iterator iter = interfaceRealizationList->begin();
		Bag<uml::InterfaceRealization>::iterator end = interfaceRealizationList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::InterfaceRealizationObject> value(new UML::InterfaceRealizationObject());
			value->setThisInterfaceRealizationObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setInterfaceRealizationValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_ownedBehavior())
	{
		std::shared_ptr<Bag<uml::Behavior>> ownedBehaviorList = m_ClassValue->getOwnedBehavior();
		Bag<uml::Behavior>::iterator iter = ownedBehaviorList->begin();
		Bag<uml::Behavior>::iterator end = ownedBehaviorList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::BehaviorObject> value(new UML::BehaviorObject());
			value->setThisBehaviorObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setBehaviorValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_extension())
	{
		std::shared_ptr<Bag<uml::Extension>> extensionList = m_ClassValue->getExtension();
		Bag<uml::Extension>::iterator iter = extensionList->begin();
		Bag<uml::Extension>::iterator end = extensionList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ExtensionObject> value(new UML::ExtensionObject());
			value->setThisExtensionObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setExtensionValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_isAbstract())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ClassValue->getIsAbstract());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_isActive())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ClassValue->getIsActive());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_nestedClassifier())
	{
		std::shared_ptr<Bag<uml::Classifier>> nestedClassifierList = m_ClassValue->getNestedClassifier();
		Bag<uml::Classifier>::iterator iter = nestedClassifierList->begin();
		Bag<uml::Classifier>::iterator end = nestedClassifierList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ClassifierObject> value(new UML::ClassifierObject());
			value->setThisClassifierObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setClassifierValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedAttribute())
	{
		std::shared_ptr<Bag<uml::Property>> ownedAttributeList = m_ClassValue->getOwnedAttribute();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedOperation())
	{
		std::shared_ptr<Bag<uml::Operation>> ownedOperationList = m_ClassValue->getOwnedOperation();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedReception())
	{
		std::shared_ptr<Bag<uml::Reception>> ownedReceptionList = m_ClassValue->getOwnedReception();
		Bag<uml::Reception>::iterator iter = ownedReceptionList->begin();
		Bag<uml::Reception>::iterator end = ownedReceptionList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ReceptionObject> value(new UML::ReceptionObject());
			value->setThisReceptionObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setReceptionValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_superClass())
	{
		std::shared_ptr<Bag<uml::Class>> superClassList = m_ClassValue->getSuperClass();
		Bag<uml::Class>::iterator iter = superClassList->begin();
		Bag<uml::Class>::iterator end = superClassList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ClassObject> value(new UML::ClassObject());
			value->setThisClassObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setClassValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_attribute())
	{
		std::shared_ptr<Bag<uml::Property>> attributeList = m_ClassValue->getAttribute();
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
		std::shared_ptr<Bag<uml::CollaborationUse>> collaborationUseList = m_ClassValue->getCollaborationUse();
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
		std::shared_ptr<Bag<uml::Feature>> featureList = m_ClassValue->getFeature();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_generalization())
	{
		std::shared_ptr<Bag<uml::Generalization>> generalizationList = m_ClassValue->getGeneralization();
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
		std::shared_ptr<Bag<uml::NamedElement>> inheritedMemberList = m_ClassValue->getInheritedMember();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_isFinalSpecialization())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ClassValue->getIsFinalSpecialization());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature())
	{
		std::shared_ptr<UML::RedefinableTemplateSignatureObject> value(new UML::RedefinableTemplateSignatureObject());
		value->setThisRedefinableTemplateSignatureObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setRedefinableTemplateSignatureValue(std::dynamic_pointer_cast<uml::RedefinableTemplateSignature>(m_ClassValue->getOwnedTemplateSignature()));
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase())
	{
		std::shared_ptr<Bag<uml::UseCase>> ownedUseCaseList = m_ClassValue->getOwnedUseCase();
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
		std::shared_ptr<Bag<uml::GeneralizationSet>> powertypeExtentList = m_ClassValue->getPowertypeExtent();
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
		std::shared_ptr<Bag<uml::Classifier>> redefinedClassifierList = m_ClassValue->getRedefinedClassifier();
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
		value->setCollaborationUseValue(m_ClassValue->getRepresentation());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution())
	{
		std::shared_ptr<Bag<uml::Substitution>> substitutionList = m_ClassValue->getSubstitution();
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
		value->setClassifierTemplateParameterValue(std::dynamic_pointer_cast<uml::ClassifierTemplateParameter>(m_ClassValue->getTemplateParameter()));
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase())
	{
		std::shared_ptr<Bag<uml::UseCase>> useCaseList = m_ClassValue->getUseCase();
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
		std::shared_ptr<Bag<uml::Comment>> ownedCommentList = m_ClassValue->getOwnedComment();
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
		std::shared_ptr<Bag<uml::Element>> ownedElementList = m_ClassValue->getOwnedElement();
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
		value->setElementValue(m_ClassValue->getOwner().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_EncapsulatedClassifier_ownedPort())
	{
		std::shared_ptr<Bag<uml::Port>> ownedPortList = m_ClassValue->getOwnedPort();
		Bag<uml::Port>::iterator iter = ownedPortList->begin();
		Bag<uml::Port>::iterator end = ownedPortList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::PortObject> value(new UML::PortObject());
			value->setThisPortObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setPortValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency())
	{
		std::shared_ptr<Bag<uml::Dependency>> clientDependencyList = m_ClassValue->getClientDependency();
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
		value->setValue(m_ClassValue->getName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<UML::StringExpressionObject> value(new UML::StringExpressionObject());
		value->setThisStringExpressionObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setStringExpressionValue(m_ClassValue->getNameExpression());
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
		value->setNamespaceValue(m_ClassValue->getNamespace().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_qualifiedName())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
		value->setValue(m_ClassValue->getQualifiedName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		uml::VisibilityKind visibility = m_ClassValue->getVisibility();
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
		std::shared_ptr<Bag<uml::ElementImport>> elementImportList = m_ClassValue->getElementImport();
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
		std::shared_ptr<Bag<uml::PackageableElement>> importedMemberList = m_ClassValue->getImportedMember();
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
		std::shared_ptr<Bag<uml::NamedElement>> memberList = m_ClassValue->getMember();
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
		std::shared_ptr<Bag<uml::NamedElement>> ownedMemberList = m_ClassValue->getOwnedMember();
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
		std::shared_ptr<Bag<uml::Constraint>> ownedRuleList = m_ClassValue->getOwnedRule();
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
		std::shared_ptr<Bag<uml::PackageImport>> packageImportList = m_ClassValue->getPackageImport();
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
		uml::VisibilityKind visibility = m_ClassValue->getVisibility();
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
		value->setTemplateParameterValue(m_ClassValue->getOwningTemplateParameter().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ClassValue->getIsLeaf());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinedElement())
	{
		std::shared_ptr<Bag<uml::RedefinableElement>> redefinedElementList = m_ClassValue->getRedefinedElement();
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
		std::shared_ptr<Bag<uml::Classifier>> redefinitionContextList = m_ClassValue->getRedefinitionContext();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_StructuredClassifier_ownedConnector())
	{
		std::shared_ptr<Bag<uml::Connector>> ownedConnectorList = m_ClassValue->getOwnedConnector();
		Bag<uml::Connector>::iterator iter = ownedConnectorList->begin();
		Bag<uml::Connector>::iterator end = ownedConnectorList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ConnectorObject> value(new UML::ConnectorObject());
			value->setThisConnectorObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setConnectorValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_StructuredClassifier_part())
	{
		std::shared_ptr<Bag<uml::Property>> partList = m_ClassValue->getPart();
		Bag<uml::Property>::iterator iter = partList->begin();
		Bag<uml::Property>::iterator end = partList->end();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_StructuredClassifier_role())
	{
		std::shared_ptr<Bag<uml::ConnectableElement>> roleList = m_ClassValue->getRole();
		Bag<uml::ConnectableElement>::iterator iter = roleList->begin();
		Bag<uml::ConnectableElement>::iterator end = roleList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ConnectableElementObject> value(new UML::ConnectableElementObject());
			value->setThisConnectableElementObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setConnectableElementValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding())
	{
		std::shared_ptr<Bag<uml::TemplateBinding>> templateBindingList = m_ClassValue->getTemplateBinding();
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
		value->setPackageValue(m_ClassValue->getPackage().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	return values;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> ClassObject::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
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


void ClassObject::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	if (feature->getMetaElementID() != uml::UmlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::UmlPackage::PORT_CLASS && feature->getMetaElementID() != uml::UmlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ClassValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ClassObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (values->size() == 0)
	{
		std::cout << __PRETTY_FUNCTION__ << ": no input value given" << std::endl;
		return;
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_classifierBehavior())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::BehaviorObject> value = std::dynamic_pointer_cast<UML::BehaviorObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ClassValue->setClassifierBehavior(value->getBehaviorValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_interfaceRealization())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getInterfaceRealization()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::InterfaceRealizationObject> value = std::dynamic_pointer_cast<UML::InterfaceRealizationObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getInterfaceRealization()->push_back(value->getInterfaceRealizationValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_ownedBehavior())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getOwnedBehavior()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::BehaviorObject> value = std::dynamic_pointer_cast<UML::BehaviorObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getOwnedBehavior()->push_back(value->getBehaviorValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_isAbstract())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ClassValue->setIsAbstract(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_isActive())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ClassValue->setIsActive(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_nestedClassifier())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getNestedClassifier()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ClassifierObject> value = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getNestedClassifier()->push_back(value->getClassifierValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedAttribute())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getOwnedAttribute()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::PropertyObject> value = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getOwnedAttribute()->push_back(value->getPropertyValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedOperation())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getOwnedOperation()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::OperationObject> value = std::dynamic_pointer_cast<UML::OperationObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getOwnedOperation()->push_back(value->getOperationValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedReception())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getOwnedReception()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ReceptionObject> value = std::dynamic_pointer_cast<UML::ReceptionObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getOwnedReception()->push_back(value->getReceptionValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_superClass())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getSuperClass()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ClassObject> value = std::dynamic_pointer_cast<UML::ClassObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getSuperClass()->push_back(value->getClassValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_collaborationUse())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getCollaborationUse()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CollaborationUseObject> value = std::dynamic_pointer_cast<UML::CollaborationUseObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getCollaborationUse()->push_back(value->getCollaborationUseValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_generalization())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getGeneralization()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::GeneralizationObject> value = std::dynamic_pointer_cast<UML::GeneralizationObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getGeneralization()->push_back(value->getGeneralizationValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_isFinalSpecialization())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ClassValue->setIsFinalSpecialization(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::RedefinableTemplateSignatureObject> value = std::dynamic_pointer_cast<UML::RedefinableTemplateSignatureObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ClassValue->setOwnedTemplateSignature(value->getRedefinableTemplateSignatureValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getOwnedUseCase()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::UseCaseObject> value = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getOwnedUseCase()->push_back(value->getUseCaseValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_powertypeExtent())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getPowertypeExtent()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::GeneralizationSetObject> value = std::dynamic_pointer_cast<UML::GeneralizationSetObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getPowertypeExtent()->push_back(value->getGeneralizationSetValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_redefinedClassifier())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getRedefinedClassifier()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ClassifierObject> value = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getRedefinedClassifier()->push_back(value->getClassifierValue());
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
			m_ClassValue->setRepresentation(value->getCollaborationUseValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getSubstitution()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::SubstitutionObject> value = std::dynamic_pointer_cast<UML::SubstitutionObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getSubstitution()->push_back(value->getSubstitutionValue());
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
			m_ClassValue->setTemplateParameter(value->getClassifierTemplateParameterValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getUseCase()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::UseCaseObject> value = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getUseCase()->push_back(value->getUseCaseValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getOwnedComment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CommentObject> value = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getOwnedComment()->push_back(value->getCommentValue());
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
			m_ClassValue->setName(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::StringExpressionObject> value = std::dynamic_pointer_cast<UML::StringExpressionObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ClassValue->setNameExpression(value->getStringExpressionValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(inputValue);
		std::shared_ptr<uml::EnumerationLiteral> literal = enumValue->getLiteral();
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_public())
		{
			m_ClassValue->setVisibility(uml::VisibilityKind::PUBLIC);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_private())
		{
			m_ClassValue->setVisibility(uml::VisibilityKind::PRIVATE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_protected())
		{
			m_ClassValue->setVisibility(uml::VisibilityKind::PROTECTED);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_package())
		{
			m_ClassValue->setVisibility(uml::VisibilityKind::PACKAGE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_elementImport())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getElementImport()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ElementImportObject> value = std::dynamic_pointer_cast<UML::ElementImportObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getElementImport()->push_back(value->getElementImportValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedRule())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getOwnedRule()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ConstraintObject> value = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getOwnedRule()->push_back(value->getConstraintValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_packageImport())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getPackageImport()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::PackageImportObject> value = std::dynamic_pointer_cast<UML::PackageImportObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getPackageImport()->push_back(value->getPackageImportValue());
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
			m_ClassValue->setVisibility(uml::VisibilityKind::PUBLIC);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_private())
		{
			m_ClassValue->setVisibility(uml::VisibilityKind::PRIVATE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_protected())
		{
			m_ClassValue->setVisibility(uml::VisibilityKind::PROTECTED);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_package())
		{
			m_ClassValue->setVisibility(uml::VisibilityKind::PACKAGE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ClassValue->setIsLeaf(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_StructuredClassifier_ownedConnector())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getOwnedConnector()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ConnectorObject> value = std::dynamic_pointer_cast<UML::ConnectorObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getOwnedConnector()->push_back(value->getConnectorValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ClassValue->getTemplateBinding()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::TemplateBindingObject> value = std::dynamic_pointer_cast<UML::TemplateBindingObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ClassValue->getTemplateBinding()->push_back(value->getTemplateBindingValue());
			}
			
			iter++;
		}
	}
}

void ClassObject::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	this->setFeatureValue(feature, values, position);
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> ClassObject::retrieveFeatureValues()
{
	std::shared_ptr<uml::Classifier> type = this->getTypes()->at(0);
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAllAttributes();
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	
	unsigned int allAttributesSize = allAttributes->size();

	for(unsigned int i = 0; i < allAttributesSize; i++)
	{
		std::shared_ptr<uml::Property> property = allAttributes->at(i);
		if (property == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_classifierBehavior() && m_ClassValue->getClassifierBehavior() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_interfaceRealization() && m_ClassValue->getInterfaceRealization() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_ownedBehavior() && m_ClassValue->getOwnedBehavior() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Class_extension() && m_ClassValue->getExtension() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Class_nestedClassifier() && m_ClassValue->getNestedClassifier() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Class_ownedAttribute() && m_ClassValue->getOwnedAttribute() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Class_ownedOperation() && m_ClassValue->getOwnedOperation() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Class_ownedReception() && m_ClassValue->getOwnedReception() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Class_superClass() && m_ClassValue->getSuperClass() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_attribute() && m_ClassValue->getAttribute() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_collaborationUse() && m_ClassValue->getCollaborationUse() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_feature() && m_ClassValue->getFeature() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_generalization() && m_ClassValue->getGeneralization() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_inheritedMember() && m_ClassValue->getInheritedMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature() && m_ClassValue->getOwnedTemplateSignature() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase() && m_ClassValue->getOwnedUseCase() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_powertypeExtent() && m_ClassValue->getPowertypeExtent() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_redefinedClassifier() && m_ClassValue->getRedefinedClassifier() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_representation() && m_ClassValue->getRepresentation() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution() && m_ClassValue->getSubstitution() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_templateParameter() && m_ClassValue->getTemplateParameter() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase() && m_ClassValue->getUseCase() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment() && m_ClassValue->getOwnedComment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement() && m_ClassValue->getOwnedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_owner() && m_ClassValue->getOwner().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_EncapsulatedClassifier_ownedPort() && m_ClassValue->getOwnedPort() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency() && m_ClassValue->getClientDependency() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression() && m_ClassValue->getNameExpression() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_namespace() && m_ClassValue->getNamespace().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_elementImport() && m_ClassValue->getElementImport() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_importedMember() && m_ClassValue->getImportedMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_member() && m_ClassValue->getMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedMember() && m_ClassValue->getOwnedMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedRule() && m_ClassValue->getOwnedRule() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_packageImport() && m_ClassValue->getPackageImport() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_owningTemplateParameter() && m_ClassValue->getOwningTemplateParameter().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinedElement() && m_ClassValue->getRedefinedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinitionContext() && m_ClassValue->getRedefinitionContext() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_StructuredClassifier_ownedConnector() && m_ClassValue->getOwnedConnector() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_StructuredClassifier_part() && m_ClassValue->getPart() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_StructuredClassifier_role() && m_ClassValue->getRole() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding() && m_ClassValue->getTemplateBinding() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Type_package() && m_ClassValue->getPackage().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
	}
	
	return featureValues;
}

