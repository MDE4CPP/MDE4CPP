#include "umlReflectionExec/ActivityObject.hpp"

//General Includes
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/Activity.hpp"
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
#include "uml/ActivityEdge.hpp"
#include "umlReflectionExec/ActivityEdgeObject.hpp"
#include "uml/ActivityGroup.hpp"
#include "umlReflectionExec/ActivityGroupObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/ActivityNode.hpp"
#include "umlReflectionExec/ActivityNodeObject.hpp"
#include "uml/ActivityGroup.hpp"
#include "umlReflectionExec/ActivityGroupObject.hpp"
#include "uml/ActivityNode.hpp"
#include "umlReflectionExec/ActivityNodeObject.hpp"
#include "uml/ActivityPartition.hpp"
#include "umlReflectionExec/ActivityPartitionObject.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "umlReflectionExec/StructuredActivityNodeObject.hpp"
#include "uml/Variable.hpp"
#include "umlReflectionExec/VariableObject.hpp"
#include "uml/BehavioredClassifier.hpp"
#include "umlReflectionExec/BehavioredClassifierObject.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/Parameter.hpp"
#include "umlReflectionExec/ParameterObject.hpp"
#include "uml/ParameterSet.hpp"
#include "umlReflectionExec/ParameterSetObject.hpp"
#include "uml/Constraint.hpp"
#include "umlReflectionExec/ConstraintObject.hpp"
#include "uml/Constraint.hpp"
#include "umlReflectionExec/ConstraintObject.hpp"
#include "uml/Behavior.hpp"
#include "umlReflectionExec/BehaviorObject.hpp"
#include "uml/BehavioralFeature.hpp"
#include "umlReflectionExec/BehavioralFeatureObject.hpp"
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

ActivityObject::ActivityObject(std::shared_ptr<uml::Activity> _element):

	m_ActivityValue(_element)
{		
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_Activity());
}

ActivityObject::ActivityObject(ActivityObject &obj):
	CS_ObjectImpl(obj)
{
}

ActivityObject::ActivityObject()
{	
	this->getTypes()->insert(this->getTypes()->begin(), UML::UMLPackage::eInstance()->get_UML_Activity());
}

ActivityObject::~ActivityObject()
{
}

std::shared_ptr<ecore::EObject> ActivityObject::copy()
{
	std::shared_ptr<ActivityObject> element(new ActivityObject(*this));
	element->setThisActivityObjectPtr(element);
	return element;
}

void ActivityObject::destroy()
{	
	if(m_ActivityValue)
	{

	}

	m_ActivityValue.reset();

	fUML::Semantics::StructuredClassifiers::ObjectImpl::destroy();
}

std::shared_ptr<uml::Element> ActivityObject::getUmlValue() const
{
	return getActivityValue();
}

std::shared_ptr<uml::Activity> ActivityObject::getActivityValue() const
{
	return m_ActivityValue;
}

void ActivityObject::setUmlValue(std::shared_ptr<uml::Element> _element)
{
	setActivityValue(std::dynamic_pointer_cast<uml::Activity>(_element));
}

void ActivityObject::setActivityValue(std::shared_ptr<uml::Activity> _ActivityElement)
{
	m_ActivityValue = _ActivityElement;
	//set super type values
	UML::BehaviorObject::setBehaviorValue(_ActivityElement);
}

void ActivityObject::setThisActivityObjectPtr(std::weak_ptr<ActivityObject> thisObjectPtr)
{
	setThisCS_ObjectPtr(thisObjectPtr);
}

bool ActivityObject::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	bool isEqual = false;
	
	std::shared_ptr<ActivityObject> otherActivityObject = std::dynamic_pointer_cast<ActivityObject>(otherValue);

	if(otherActivityObject != nullptr)
	{
		if(this->getActivityValue() == otherActivityObject->getActivityValue())
		{
			isEqual = true;
		}
	}

	return isEqual;
}

std::string ActivityObject::toString()
{
	std::string buffer = "Instance of 'ActivityObject', " + std::to_string(getTypes()->size()) + " types (";
	for(unsigned int i = 0; i < getTypes()->size(); ++i)
	{
		buffer += "type{" + std::to_string(i) + "}: '" + getTypes()->at(i)->getName() + "', ";
	}
	buffer +=")";

	return buffer;
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> ActivityObject::getDirectContainers()
{   
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());
	return directContainers;
}


std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> ActivityObject::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
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

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ActivityObject::retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end)
{
	return nullptr;
}

void ActivityObject::removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	if (feature->getMetaElementID() != uml::UmlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::UmlPackage::PORT_CLASS && feature->getMetaElementID() != uml::UmlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ActivityValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ActivityObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_edge())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getEdge()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ActivityEdgeObject> inputValue = std::dynamic_pointer_cast<UML::ActivityEdgeObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getEdge()->erase(inputValue->getActivityEdgeValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_group())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getGroup()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ActivityGroupObject> inputValue = std::dynamic_pointer_cast<UML::ActivityGroupObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getGroup()->erase(inputValue->getActivityGroupValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_isReadOnly())
	{
				m_ActivityValue->setIsReadOnly(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_isSingleExecution())
	{
				m_ActivityValue->setIsSingleExecution(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_node())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getNode()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ActivityNodeObject> inputValue = std::dynamic_pointer_cast<UML::ActivityNodeObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getNode()->erase(inputValue->getActivityNodeValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_ownedGroup())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getOwnedGroup()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ActivityGroupObject> inputValue = std::dynamic_pointer_cast<UML::ActivityGroupObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getOwnedGroup()->erase(inputValue->getActivityGroupValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_ownedNode())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getOwnedNode()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ActivityNodeObject> inputValue = std::dynamic_pointer_cast<UML::ActivityNodeObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getOwnedNode()->erase(inputValue->getActivityNodeValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_partition())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getPartition()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ActivityPartitionObject> inputValue = std::dynamic_pointer_cast<UML::ActivityPartitionObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getPartition()->erase(inputValue->getActivityPartitionValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_structuredNode())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getStructuredNode()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::StructuredActivityNodeObject> inputValue = std::dynamic_pointer_cast<UML::StructuredActivityNodeObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getStructuredNode()->erase(inputValue->getStructuredActivityNodeValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_variable())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getVariable()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::VariableObject> inputValue = std::dynamic_pointer_cast<UML::VariableObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getVariable()->erase(inputValue->getVariableValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_isReentrant())
	{
				m_ActivityValue->setIsReentrant(true /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_ownedParameter())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getOwnedParameter()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ParameterObject> inputValue = std::dynamic_pointer_cast<UML::ParameterObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getOwnedParameter()->erase(inputValue->getParameterValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_ownedParameterSet())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getOwnedParameterSet()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ParameterSetObject> inputValue = std::dynamic_pointer_cast<UML::ParameterSetObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getOwnedParameterSet()->erase(inputValue->getParameterSetValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_postcondition())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getPostcondition()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ConstraintObject> inputValue = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getPostcondition()->erase(inputValue->getConstraintValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_precondition())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getPrecondition()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ConstraintObject> inputValue = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getPrecondition()->erase(inputValue->getConstraintValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_redefinedBehavior())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getRedefinedBehavior()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::BehaviorObject> inputValue = std::dynamic_pointer_cast<UML::BehaviorObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getRedefinedBehavior()->erase(inputValue->getBehaviorValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_specification())
	{
				m_ActivityValue->getSpecification().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_classifierBehavior())
	{
				m_ActivityValue->getClassifierBehavior().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_interfaceRealization())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getInterfaceRealization()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::InterfaceRealizationObject> inputValue = std::dynamic_pointer_cast<UML::InterfaceRealizationObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getInterfaceRealization()->erase(inputValue->getInterfaceRealizationValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_ownedBehavior())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getOwnedBehavior()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::BehaviorObject> inputValue = std::dynamic_pointer_cast<UML::BehaviorObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getOwnedBehavior()->erase(inputValue->getBehaviorValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_isAbstract())
	{
				m_ActivityValue->setIsAbstract(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_isActive())
	{
				m_ActivityValue->setIsActive(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_nestedClassifier())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getNestedClassifier()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ClassifierObject> inputValue = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getNestedClassifier()->erase(inputValue->getClassifierValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedAttribute())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getOwnedAttribute()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::PropertyObject> inputValue = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getOwnedAttribute()->erase(inputValue->getPropertyValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedOperation())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getOwnedOperation()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::OperationObject> inputValue = std::dynamic_pointer_cast<UML::OperationObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getOwnedOperation()->erase(inputValue->getOperationValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedReception())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getOwnedReception()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ReceptionObject> inputValue = std::dynamic_pointer_cast<UML::ReceptionObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getOwnedReception()->erase(inputValue->getReceptionValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_superClass())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getSuperClass()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ClassObject> inputValue = std::dynamic_pointer_cast<UML::ClassObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getSuperClass()->erase(inputValue->getClassValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_collaborationUse())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getCollaborationUse()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CollaborationUseObject> inputValue = std::dynamic_pointer_cast<UML::CollaborationUseObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getCollaborationUse()->erase(inputValue->getCollaborationUseValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_generalization())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getGeneralization()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::GeneralizationObject> inputValue = std::dynamic_pointer_cast<UML::GeneralizationObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getGeneralization()->erase(inputValue->getGeneralizationValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_isFinalSpecialization())
	{
				m_ActivityValue->setIsFinalSpecialization(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature())
	{
				m_ActivityValue->getOwnedTemplateSignature().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getOwnedUseCase()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::UseCaseObject> inputValue = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getOwnedUseCase()->erase(inputValue->getUseCaseValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_powertypeExtent())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getPowertypeExtent()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::GeneralizationSetObject> inputValue = std::dynamic_pointer_cast<UML::GeneralizationSetObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getPowertypeExtent()->erase(inputValue->getGeneralizationSetValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_redefinedClassifier())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getRedefinedClassifier()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ClassifierObject> inputValue = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getRedefinedClassifier()->erase(inputValue->getClassifierValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_representation())
	{
				m_ActivityValue->getRepresentation().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getSubstitution()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::SubstitutionObject> inputValue = std::dynamic_pointer_cast<UML::SubstitutionObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getSubstitution()->erase(inputValue->getSubstitutionValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_templateParameter())
	{
				m_ActivityValue->getTemplateParameter().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getUseCase()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::UseCaseObject> inputValue = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getUseCase()->erase(inputValue->getUseCaseValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getOwnedComment()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::CommentObject> inputValue = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getOwnedComment()->erase(inputValue->getCommentValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_name())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
				m_ActivityValue->getNameExpression().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
				// no default value defined, clear not realized

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_elementImport())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getElementImport()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ElementImportObject> inputValue = std::dynamic_pointer_cast<UML::ElementImportObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getElementImport()->erase(inputValue->getElementImportValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedRule())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getOwnedRule()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ConstraintObject> inputValue = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getOwnedRule()->erase(inputValue->getConstraintValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_packageImport())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getPackageImport()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::PackageImportObject> inputValue = std::dynamic_pointer_cast<UML::PackageImportObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getPackageImport()->erase(inputValue->getPackageImportValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_PackageableElement_visibility())
	{
				m_ActivityValue->setVisibility(uml::VisibilityKind::PUBLIC /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_owningTemplateParameter())
	{
				m_ActivityValue->getOwningTemplateParameter().reset();

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
				m_ActivityValue->setIsLeaf(false /*defined default value*/);

	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_StructuredClassifier_ownedConnector())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getOwnedConnector()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::ConnectorObject> inputValue = std::dynamic_pointer_cast<UML::ConnectorObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getOwnedConnector()->erase(inputValue->getConnectorValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding())
	{
		if (value == nullptr) // clear mode
		{
			m_ActivityValue->getTemplateBinding()->clear();
		}
		else
		{
			/* Should use PSCS::CS_Reference but dynamic_pointer_cast fails --> using fUML::Reference instead
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value); */
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value);
			std::shared_ptr<UML::TemplateBindingObject> inputValue = std::dynamic_pointer_cast<UML::TemplateBindingObject>(reference->getReferent());
			if (inputValue != nullptr)
			{
				m_ActivityValue->getTemplateBinding()->erase(inputValue->getTemplateBindingValue());
			}
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Type_package())
	{
				m_ActivityValue->getPackage().reset();

	}
}


std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ActivityObject::getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	if (feature->getMetaElementID() != uml::UmlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::UmlPackage::PORT_CLASS && feature->getMetaElementID() != uml::UmlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ActivityValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ActivityObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_edge())
	{
		std::shared_ptr<Bag<uml::ActivityEdge>> edgeList = m_ActivityValue->getEdge();
		Bag<uml::ActivityEdge>::iterator iter = edgeList->begin();
		Bag<uml::ActivityEdge>::iterator end = edgeList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ActivityEdgeObject> value(new UML::ActivityEdgeObject());
			value->setThisActivityEdgeObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setActivityEdgeValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_group())
	{
		std::shared_ptr<Bag<uml::ActivityGroup>> groupList = m_ActivityValue->getGroup();
		Bag<uml::ActivityGroup>::iterator iter = groupList->begin();
		Bag<uml::ActivityGroup>::iterator end = groupList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ActivityGroupObject> value(new UML::ActivityGroupObject());
			value->setThisActivityGroupObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setActivityGroupValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_isReadOnly())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ActivityValue->getIsReadOnly());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_isSingleExecution())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ActivityValue->getIsSingleExecution());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_node())
	{
		std::shared_ptr<Bag<uml::ActivityNode>> nodeList = m_ActivityValue->getNode();
		Bag<uml::ActivityNode>::iterator iter = nodeList->begin();
		Bag<uml::ActivityNode>::iterator end = nodeList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ActivityNodeObject> value(new UML::ActivityNodeObject());
			value->setThisActivityNodeObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setActivityNodeValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_ownedGroup())
	{
		std::shared_ptr<Bag<uml::ActivityGroup>> ownedGroupList = m_ActivityValue->getOwnedGroup();
		Bag<uml::ActivityGroup>::iterator iter = ownedGroupList->begin();
		Bag<uml::ActivityGroup>::iterator end = ownedGroupList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ActivityGroupObject> value(new UML::ActivityGroupObject());
			value->setThisActivityGroupObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setActivityGroupValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_ownedNode())
	{
		std::shared_ptr<Bag<uml::ActivityNode>> ownedNodeList = m_ActivityValue->getOwnedNode();
		Bag<uml::ActivityNode>::iterator iter = ownedNodeList->begin();
		Bag<uml::ActivityNode>::iterator end = ownedNodeList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ActivityNodeObject> value(new UML::ActivityNodeObject());
			value->setThisActivityNodeObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setActivityNodeValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_partition())
	{
		std::shared_ptr<Bag<uml::ActivityPartition>> partitionList = m_ActivityValue->getPartition();
		Bag<uml::ActivityPartition>::iterator iter = partitionList->begin();
		Bag<uml::ActivityPartition>::iterator end = partitionList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ActivityPartitionObject> value(new UML::ActivityPartitionObject());
			value->setThisActivityPartitionObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setActivityPartitionValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_structuredNode())
	{
		std::shared_ptr<Bag<uml::StructuredActivityNode>> structuredNodeList = m_ActivityValue->getStructuredNode();
		Bag<uml::StructuredActivityNode>::iterator iter = structuredNodeList->begin();
		Bag<uml::StructuredActivityNode>::iterator end = structuredNodeList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::StructuredActivityNodeObject> value(new UML::StructuredActivityNodeObject());
			value->setThisStructuredActivityNodeObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setStructuredActivityNodeValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_variable())
	{
		std::shared_ptr<Bag<uml::Variable>> variableList = m_ActivityValue->getVariable();
		Bag<uml::Variable>::iterator iter = variableList->begin();
		Bag<uml::Variable>::iterator end = variableList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::VariableObject> value(new UML::VariableObject());
			value->setThisVariableObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setVariableValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_context())
	{
		std::shared_ptr<UML::BehavioredClassifierObject> value(new UML::BehavioredClassifierObject());
		value->setThisBehavioredClassifierObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setBehavioredClassifierValue(m_ActivityValue->getContext());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_isReentrant())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ActivityValue->getIsReentrant());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_ownedParameter())
	{
		std::shared_ptr<Bag<uml::Parameter>> ownedParameterList = m_ActivityValue->getOwnedParameter();
		Bag<uml::Parameter>::iterator iter = ownedParameterList->begin();
		Bag<uml::Parameter>::iterator end = ownedParameterList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ParameterObject> value(new UML::ParameterObject());
			value->setThisParameterObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setParameterValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_ownedParameterSet())
	{
		std::shared_ptr<Bag<uml::ParameterSet>> ownedParameterSetList = m_ActivityValue->getOwnedParameterSet();
		Bag<uml::ParameterSet>::iterator iter = ownedParameterSetList->begin();
		Bag<uml::ParameterSet>::iterator end = ownedParameterSetList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::ParameterSetObject> value(new UML::ParameterSetObject());
			value->setThisParameterSetObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setParameterSetValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			reference->setCompositeReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_postcondition())
	{
		std::shared_ptr<Bag<uml::Constraint>> postconditionList = m_ActivityValue->getPostcondition();
		Bag<uml::Constraint>::iterator iter = postconditionList->begin();
		Bag<uml::Constraint>::iterator end = postconditionList->end();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_precondition())
	{
		std::shared_ptr<Bag<uml::Constraint>> preconditionList = m_ActivityValue->getPrecondition();
		Bag<uml::Constraint>::iterator iter = preconditionList->begin();
		Bag<uml::Constraint>::iterator end = preconditionList->end();
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
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_redefinedBehavior())
	{
		std::shared_ptr<Bag<uml::Behavior>> redefinedBehaviorList = m_ActivityValue->getRedefinedBehavior();
		Bag<uml::Behavior>::iterator iter = redefinedBehaviorList->begin();
		Bag<uml::Behavior>::iterator end = redefinedBehaviorList->end();
		while (iter != end)
		{
			std::shared_ptr<UML::BehaviorObject> value(new UML::BehaviorObject());
			value->setThisBehaviorObjectPtr(value);
			value->setLocus(this->getLocus());
			value->setBehaviorValue(*iter);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setReferent(value);
			values->add(reference);
			iter++;
		} 
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_specification())
	{
		std::shared_ptr<UML::BehavioralFeatureObject> value(new UML::BehavioralFeatureObject());
		value->setThisBehavioralFeatureObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setBehavioralFeatureValue(m_ActivityValue->getSpecification());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_classifierBehavior())
	{
		std::shared_ptr<UML::BehaviorObject> value(new UML::BehaviorObject());
		value->setThisBehaviorObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setBehaviorValue(m_ActivityValue->getClassifierBehavior());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_interfaceRealization())
	{
		std::shared_ptr<Bag<uml::InterfaceRealization>> interfaceRealizationList = m_ActivityValue->getInterfaceRealization();
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
		std::shared_ptr<Bag<uml::Behavior>> ownedBehaviorList = m_ActivityValue->getOwnedBehavior();
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
		std::shared_ptr<Bag<uml::Extension>> extensionList = m_ActivityValue->getExtension();
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
		value->setValue(m_ActivityValue->getIsAbstract());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_isActive())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ActivityValue->getIsActive());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_nestedClassifier())
	{
		std::shared_ptr<Bag<uml::Classifier>> nestedClassifierList = m_ActivityValue->getNestedClassifier();
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
		std::shared_ptr<Bag<uml::Property>> ownedAttributeList = m_ActivityValue->getOwnedAttribute();
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
		std::shared_ptr<Bag<uml::Operation>> ownedOperationList = m_ActivityValue->getOwnedOperation();
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
		std::shared_ptr<Bag<uml::Reception>> ownedReceptionList = m_ActivityValue->getOwnedReception();
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
		std::shared_ptr<Bag<uml::Class>> superClassList = m_ActivityValue->getSuperClass();
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
		std::shared_ptr<Bag<uml::Property>> attributeList = m_ActivityValue->getAttribute();
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
		std::shared_ptr<Bag<uml::CollaborationUse>> collaborationUseList = m_ActivityValue->getCollaborationUse();
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
		std::shared_ptr<Bag<uml::Feature>> featureList = m_ActivityValue->getFeature();
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
		std::shared_ptr<Bag<uml::Generalization>> generalizationList = m_ActivityValue->getGeneralization();
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
		std::shared_ptr<Bag<uml::NamedElement>> inheritedMemberList = m_ActivityValue->getInheritedMember();
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
		value->setValue(m_ActivityValue->getIsFinalSpecialization());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature())
	{
		std::shared_ptr<UML::RedefinableTemplateSignatureObject> value(new UML::RedefinableTemplateSignatureObject());
		value->setThisRedefinableTemplateSignatureObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setRedefinableTemplateSignatureValue(std::dynamic_pointer_cast<uml::RedefinableTemplateSignature>(m_ActivityValue->getOwnedTemplateSignature()));
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		reference->setCompositeReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase())
	{
		std::shared_ptr<Bag<uml::UseCase>> ownedUseCaseList = m_ActivityValue->getOwnedUseCase();
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
		std::shared_ptr<Bag<uml::GeneralizationSet>> powertypeExtentList = m_ActivityValue->getPowertypeExtent();
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
		std::shared_ptr<Bag<uml::Classifier>> redefinedClassifierList = m_ActivityValue->getRedefinedClassifier();
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
		value->setCollaborationUseValue(m_ActivityValue->getRepresentation());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution())
	{
		std::shared_ptr<Bag<uml::Substitution>> substitutionList = m_ActivityValue->getSubstitution();
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
		value->setClassifierTemplateParameterValue(std::dynamic_pointer_cast<uml::ClassifierTemplateParameter>(m_ActivityValue->getTemplateParameter()));
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase())
	{
		std::shared_ptr<Bag<uml::UseCase>> useCaseList = m_ActivityValue->getUseCase();
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
		std::shared_ptr<Bag<uml::Comment>> ownedCommentList = m_ActivityValue->getOwnedComment();
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
		std::shared_ptr<Bag<uml::Element>> ownedElementList = m_ActivityValue->getOwnedElement();
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
		value->setElementValue(m_ActivityValue->getOwner().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_EncapsulatedClassifier_ownedPort())
	{
		std::shared_ptr<Bag<uml::Port>> ownedPortList = m_ActivityValue->getOwnedPort();
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
		std::shared_ptr<Bag<uml::Dependency>> clientDependencyList = m_ActivityValue->getClientDependency();
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
		value->setValue(m_ActivityValue->getName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<UML::StringExpressionObject> value(new UML::StringExpressionObject());
		value->setThisStringExpressionObjectPtr(value);
		value->setLocus(this->getLocus());
		value->setStringExpressionValue(m_ActivityValue->getNameExpression());
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
		value->setNamespaceValue(m_ActivityValue->getNamespace().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_qualifiedName())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
		value->setValue(m_ActivityValue->getQualifiedName());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		uml::VisibilityKind visibility = m_ActivityValue->getVisibility();
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
		std::shared_ptr<Bag<uml::ElementImport>> elementImportList = m_ActivityValue->getElementImport();
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
		std::shared_ptr<Bag<uml::PackageableElement>> importedMemberList = m_ActivityValue->getImportedMember();
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
		std::shared_ptr<Bag<uml::NamedElement>> memberList = m_ActivityValue->getMember();
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
		std::shared_ptr<Bag<uml::NamedElement>> ownedMemberList = m_ActivityValue->getOwnedMember();
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
		std::shared_ptr<Bag<uml::Constraint>> ownedRuleList = m_ActivityValue->getOwnedRule();
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
		std::shared_ptr<Bag<uml::PackageImport>> packageImportList = m_ActivityValue->getPackageImport();
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
		uml::VisibilityKind visibility = m_ActivityValue->getVisibility();
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
		value->setTemplateParameterValue(m_ActivityValue->getOwningTemplateParameter().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
		value->setValue(m_ActivityValue->getIsLeaf());
		values->add(value);
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinedElement())
	{
		std::shared_ptr<Bag<uml::RedefinableElement>> redefinedElementList = m_ActivityValue->getRedefinedElement();
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
		std::shared_ptr<Bag<uml::Classifier>> redefinitionContextList = m_ActivityValue->getRedefinitionContext();
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
		std::shared_ptr<Bag<uml::Connector>> ownedConnectorList = m_ActivityValue->getOwnedConnector();
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
		std::shared_ptr<Bag<uml::Property>> partList = m_ActivityValue->getPart();
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
		std::shared_ptr<Bag<uml::ConnectableElement>> roleList = m_ActivityValue->getRole();
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
		std::shared_ptr<Bag<uml::TemplateBinding>> templateBindingList = m_ActivityValue->getTemplateBinding();
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
		value->setPackageValue(m_ActivityValue->getPackage().lock());
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setReferent(value);
		values->add(reference);
	}
	return values;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> ActivityObject::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
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


void ActivityObject::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	if (feature->getMetaElementID() != uml::UmlPackage::PROPERTY_CLASS && feature->getMetaElementID() != uml::UmlPackage::PORT_CLASS && feature->getMetaElementID() != uml::UmlPackage::EXTENSIONEND_CLASS)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": feature is null or not kind of uml::Property" << std::endl;
		throw "feature is null or not kind of uml::Property";
	}

	if (m_ActivityValue == nullptr)
	{
		std::cerr << __PRETTY_FUNCTION__ << ": no value stored inside ActivityObject (property: " << feature->getName() << ")" << std::endl;
		throw "NullPointerException";	
	}

	if (values->size() == 0)
	{
		std::cout << __PRETTY_FUNCTION__ << ": no input value given" << std::endl;
		return;
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_edge())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getEdge()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ActivityEdgeObject> value = std::dynamic_pointer_cast<UML::ActivityEdgeObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getEdge()->push_back(value->getActivityEdgeValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_group())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getGroup()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ActivityGroupObject> value = std::dynamic_pointer_cast<UML::ActivityGroupObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getGroup()->push_back(value->getActivityGroupValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_isReadOnly())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ActivityValue->setIsReadOnly(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_isSingleExecution())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ActivityValue->setIsSingleExecution(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_node())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getNode()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ActivityNodeObject> value = std::dynamic_pointer_cast<UML::ActivityNodeObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getNode()->push_back(value->getActivityNodeValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_ownedGroup())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getOwnedGroup()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ActivityGroupObject> value = std::dynamic_pointer_cast<UML::ActivityGroupObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getOwnedGroup()->push_back(value->getActivityGroupValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_ownedNode())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getOwnedNode()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ActivityNodeObject> value = std::dynamic_pointer_cast<UML::ActivityNodeObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getOwnedNode()->push_back(value->getActivityNodeValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_partition())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getPartition()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ActivityPartitionObject> value = std::dynamic_pointer_cast<UML::ActivityPartitionObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getPartition()->push_back(value->getActivityPartitionValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_structuredNode())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getStructuredNode()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::StructuredActivityNodeObject> value = std::dynamic_pointer_cast<UML::StructuredActivityNodeObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getStructuredNode()->push_back(value->getStructuredActivityNodeValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Activity_variable())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getVariable()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::VariableObject> value = std::dynamic_pointer_cast<UML::VariableObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getVariable()->push_back(value->getVariableValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_isReentrant())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ActivityValue->setIsReentrant(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_ownedParameter())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getOwnedParameter()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ParameterObject> value = std::dynamic_pointer_cast<UML::ParameterObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getOwnedParameter()->push_back(value->getParameterValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_ownedParameterSet())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getOwnedParameterSet()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ParameterSetObject> value = std::dynamic_pointer_cast<UML::ParameterSetObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getOwnedParameterSet()->push_back(value->getParameterSetValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_postcondition())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getPostcondition()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ConstraintObject> value = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getPostcondition()->push_back(value->getConstraintValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_precondition())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getPrecondition()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ConstraintObject> value = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getPrecondition()->push_back(value->getConstraintValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_redefinedBehavior())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getRedefinedBehavior()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::BehaviorObject> value = std::dynamic_pointer_cast<UML::BehaviorObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getRedefinedBehavior()->push_back(value->getBehaviorValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Behavior_specification())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::BehavioralFeatureObject> value = std::dynamic_pointer_cast<UML::BehavioralFeatureObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ActivityValue->setSpecification(value->getBehavioralFeatureValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_classifierBehavior())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::BehaviorObject> value = std::dynamic_pointer_cast<UML::BehaviorObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ActivityValue->setClassifierBehavior(value->getBehaviorValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_interfaceRealization())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getInterfaceRealization()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::InterfaceRealizationObject> value = std::dynamic_pointer_cast<UML::InterfaceRealizationObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getInterfaceRealization()->push_back(value->getInterfaceRealizationValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_ownedBehavior())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getOwnedBehavior()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::BehaviorObject> value = std::dynamic_pointer_cast<UML::BehaviorObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getOwnedBehavior()->push_back(value->getBehaviorValue());
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
			m_ActivityValue->setIsAbstract(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_isActive())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ActivityValue->setIsActive(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_nestedClassifier())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getNestedClassifier()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ClassifierObject> value = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getNestedClassifier()->push_back(value->getClassifierValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedAttribute())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getOwnedAttribute()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::PropertyObject> value = std::dynamic_pointer_cast<UML::PropertyObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getOwnedAttribute()->push_back(value->getPropertyValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedOperation())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getOwnedOperation()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::OperationObject> value = std::dynamic_pointer_cast<UML::OperationObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getOwnedOperation()->push_back(value->getOperationValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_ownedReception())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getOwnedReception()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ReceptionObject> value = std::dynamic_pointer_cast<UML::ReceptionObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getOwnedReception()->push_back(value->getReceptionValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Class_superClass())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getSuperClass()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ClassObject> value = std::dynamic_pointer_cast<UML::ClassObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getSuperClass()->push_back(value->getClassValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_collaborationUse())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getCollaborationUse()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CollaborationUseObject> value = std::dynamic_pointer_cast<UML::CollaborationUseObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getCollaborationUse()->push_back(value->getCollaborationUseValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_generalization())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getGeneralization()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::GeneralizationObject> value = std::dynamic_pointer_cast<UML::GeneralizationObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getGeneralization()->push_back(value->getGeneralizationValue());
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
			m_ActivityValue->setIsFinalSpecialization(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::RedefinableTemplateSignatureObject> value = std::dynamic_pointer_cast<UML::RedefinableTemplateSignatureObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ActivityValue->setOwnedTemplateSignature(value->getRedefinableTemplateSignatureValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getOwnedUseCase()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::UseCaseObject> value = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getOwnedUseCase()->push_back(value->getUseCaseValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_powertypeExtent())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getPowertypeExtent()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::GeneralizationSetObject> value = std::dynamic_pointer_cast<UML::GeneralizationSetObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getPowertypeExtent()->push_back(value->getGeneralizationSetValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_redefinedClassifier())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getRedefinedClassifier()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ClassifierObject> value = std::dynamic_pointer_cast<UML::ClassifierObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getRedefinedClassifier()->push_back(value->getClassifierValue());
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
			m_ActivityValue->setRepresentation(value->getCollaborationUseValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getSubstitution()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::SubstitutionObject> value = std::dynamic_pointer_cast<UML::SubstitutionObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getSubstitution()->push_back(value->getSubstitutionValue());
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
			m_ActivityValue->setTemplateParameter(value->getClassifierTemplateParameterValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getUseCase()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::UseCaseObject> value = std::dynamic_pointer_cast<UML::UseCaseObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getUseCase()->push_back(value->getUseCaseValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getOwnedComment()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::CommentObject> value = std::dynamic_pointer_cast<UML::CommentObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getOwnedComment()->push_back(value->getCommentValue());
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
			m_ActivityValue->setName(valueObject->getValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
		std::shared_ptr<UML::StringExpressionObject> value = std::dynamic_pointer_cast<UML::StringExpressionObject>(reference->getReferent());
		if (value != nullptr)
		{
			m_ActivityValue->setNameExpression(value->getStringExpressionValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_NamedElement_visibility())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(inputValue);
		std::shared_ptr<uml::EnumerationLiteral> literal = enumValue->getLiteral();
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_public())
		{
			m_ActivityValue->setVisibility(uml::VisibilityKind::PUBLIC);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_private())
		{
			m_ActivityValue->setVisibility(uml::VisibilityKind::PRIVATE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_protected())
		{
			m_ActivityValue->setVisibility(uml::VisibilityKind::PROTECTED);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_package())
		{
			m_ActivityValue->setVisibility(uml::VisibilityKind::PACKAGE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_elementImport())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getElementImport()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ElementImportObject> value = std::dynamic_pointer_cast<UML::ElementImportObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getElementImport()->push_back(value->getElementImportValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedRule())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getOwnedRule()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ConstraintObject> value = std::dynamic_pointer_cast<UML::ConstraintObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getOwnedRule()->push_back(value->getConstraintValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_Namespace_packageImport())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getPackageImport()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::PackageImportObject> value = std::dynamic_pointer_cast<UML::PackageImportObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getPackageImport()->push_back(value->getPackageImportValue());
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
			m_ActivityValue->setVisibility(uml::VisibilityKind::PUBLIC);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_private())
		{
			m_ActivityValue->setVisibility(uml::VisibilityKind::PRIVATE);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_protected())
		{
			m_ActivityValue->setVisibility(uml::VisibilityKind::PROTECTED);
		}
		if (literal == UML::UMLPackage::eInstance()->get_UML_VisibilityKind_package())
		{
			m_ActivityValue->setVisibility(uml::VisibilityKind::PACKAGE);
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_isLeaf())
	{
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = values->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> valueObject = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(inputValue);
		if (valueObject != nullptr)
		{
			m_ActivityValue->setIsLeaf(valueObject->isValue());
		}
		
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_StructuredClassifier_ownedConnector())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getOwnedConnector()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::ConnectorObject> value = std::dynamic_pointer_cast<UML::ConnectorObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getOwnedConnector()->push_back(value->getConnectorValue());
			}
			
			iter++;
		}
	}
	if (feature == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding())
	{
		Bag<fUML::Semantics::Values::Value>::iterator iter = values->begin();
		Bag<fUML::Semantics::Values::Value>::iterator end = values->end();
		m_ActivityValue->getTemplateBinding()->clear();
		while (iter != end)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> inputValue = *iter;
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(inputValue);
			std::shared_ptr<UML::TemplateBindingObject> value = std::dynamic_pointer_cast<UML::TemplateBindingObject>(reference->getReferent());
			if (value != nullptr)
			{
				m_ActivityValue->getTemplateBinding()->push_back(value->getTemplateBindingValue());
			}
			
			iter++;
		}
	}
}

void ActivityObject::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values, int position)
{
	this->setFeatureValue(feature, values, position);
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> ActivityObject::retrieveFeatureValues()
{
	std::shared_ptr<uml::Classifier> type = this->getTypes()->at(0);
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAllAttributes();
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	
	unsigned int allAttributesSize = allAttributes->size();

	for(unsigned int i = 0; i < allAttributesSize; i++)
	{
		std::shared_ptr<uml::Property> property = allAttributes->at(i);
		if (property == UML::UMLPackage::eInstance()->get_UML_Activity_edge() && m_ActivityValue->getEdge() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Activity_group() && m_ActivityValue->getGroup() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Activity_node() && m_ActivityValue->getNode() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Activity_ownedGroup() && m_ActivityValue->getOwnedGroup() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Activity_ownedNode() && m_ActivityValue->getOwnedNode() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Activity_partition() && m_ActivityValue->getPartition() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Activity_structuredNode() && m_ActivityValue->getStructuredNode() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Activity_variable() && m_ActivityValue->getVariable() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Behavior_context() && m_ActivityValue->getContext() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Behavior_ownedParameter() && m_ActivityValue->getOwnedParameter() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Behavior_ownedParameterSet() && m_ActivityValue->getOwnedParameterSet() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Behavior_postcondition() && m_ActivityValue->getPostcondition() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Behavior_precondition() && m_ActivityValue->getPrecondition() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Behavior_redefinedBehavior() && m_ActivityValue->getRedefinedBehavior() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Behavior_specification() && m_ActivityValue->getSpecification() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_classifierBehavior() && m_ActivityValue->getClassifierBehavior() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_interfaceRealization() && m_ActivityValue->getInterfaceRealization() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_BehavioredClassifier_ownedBehavior() && m_ActivityValue->getOwnedBehavior() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Class_extension() && m_ActivityValue->getExtension() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Class_nestedClassifier() && m_ActivityValue->getNestedClassifier() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Class_ownedAttribute() && m_ActivityValue->getOwnedAttribute() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Class_ownedOperation() && m_ActivityValue->getOwnedOperation() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Class_ownedReception() && m_ActivityValue->getOwnedReception() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Class_superClass() && m_ActivityValue->getSuperClass() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_attribute() && m_ActivityValue->getAttribute() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_collaborationUse() && m_ActivityValue->getCollaborationUse() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_feature() && m_ActivityValue->getFeature() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_generalization() && m_ActivityValue->getGeneralization() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_inheritedMember() && m_ActivityValue->getInheritedMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedTemplateSignature() && m_ActivityValue->getOwnedTemplateSignature() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_ownedUseCase() && m_ActivityValue->getOwnedUseCase() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_powertypeExtent() && m_ActivityValue->getPowertypeExtent() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_redefinedClassifier() && m_ActivityValue->getRedefinedClassifier() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_representation() && m_ActivityValue->getRepresentation() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_substitution() && m_ActivityValue->getSubstitution() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_templateParameter() && m_ActivityValue->getTemplateParameter() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Classifier_useCase() && m_ActivityValue->getUseCase() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedComment() && m_ActivityValue->getOwnedComment() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_ownedElement() && m_ActivityValue->getOwnedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Element_owner() && m_ActivityValue->getOwner().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_EncapsulatedClassifier_ownedPort() && m_ActivityValue->getOwnedPort() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_clientDependency() && m_ActivityValue->getClientDependency() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_nameExpression() && m_ActivityValue->getNameExpression() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_NamedElement_namespace() && m_ActivityValue->getNamespace().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_elementImport() && m_ActivityValue->getElementImport() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_importedMember() && m_ActivityValue->getImportedMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_member() && m_ActivityValue->getMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedMember() && m_ActivityValue->getOwnedMember() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_ownedRule() && m_ActivityValue->getOwnedRule() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Namespace_packageImport() && m_ActivityValue->getPackageImport() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_ParameterableElement_owningTemplateParameter() && m_ActivityValue->getOwningTemplateParameter().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinedElement() && m_ActivityValue->getRedefinedElement() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_RedefinableElement_redefinitionContext() && m_ActivityValue->getRedefinitionContext() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_StructuredClassifier_ownedConnector() && m_ActivityValue->getOwnedConnector() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_StructuredClassifier_part() && m_ActivityValue->getPart() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_StructuredClassifier_role() && m_ActivityValue->getRole() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_TemplateableElement_templateBinding() && m_ActivityValue->getTemplateBinding() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
		if (property == UML::UMLPackage::eInstance()->get_UML_Type_package() && m_ActivityValue->getPackage().lock() != nullptr)
		{
			featureValues->add(this->retrieveFeatureValue(property));
		}
	}
	
	return featureValues;
}

