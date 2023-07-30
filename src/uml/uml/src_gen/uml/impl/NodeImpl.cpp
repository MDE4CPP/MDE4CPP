
#include "uml/impl/NodeImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Behavior.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/CommunicationPath.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/Connector.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Deployment.hpp"
#include "uml/DeploymentTarget.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Extension.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Node.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Port.hpp"
#include "uml/Property.hpp"
#include "uml/Reception.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/UseCase.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
NodeImpl::NodeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

NodeImpl::~NodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Node "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
NodeImpl::NodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:NodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
NodeImpl::NodeImpl(std::weak_ptr<uml::Element> par_owner)
:NodeImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
NodeImpl::NodeImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:NodeImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
NodeImpl::NodeImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:NodeImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


NodeImpl::NodeImpl(const NodeImpl & obj): NodeImpl()
{
	*this = obj;
}

NodeImpl& NodeImpl::operator=(const NodeImpl & obj)
{
	//call overloaded =Operator for each base class
	ClassImpl::operator=(obj);
	DeploymentTargetImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Node 
	 * which is generated by the compiler (as Node is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Node::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Node "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'nestedNode'
	std::shared_ptr<Subset<uml::Node, uml::NamedElement>> nestedNodeList = obj.getNestedNode();
	if(nestedNodeList)
	{
		/*Subset*/
		m_nestedNode.reset(new Subset<uml::Node, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_nestedNode - Subset<uml::Node, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getNestedNode()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedNode - Subset<uml::Node, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Node> nestedNodeindexElem: *nestedNodeList) 
		{
			std::shared_ptr<uml::Node> temp = std::dynamic_pointer_cast<uml::Node>((nestedNodeindexElem)->copy());
			m_nestedNode->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr nestedNode."<< std::endl;)
	}
	/*Subset*/
	getNestedNode()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_nestedNode - Subset<uml::Node, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> NodeImpl::copy() const
{
	std::shared_ptr<NodeImpl> element(new NodeImpl());
	*element =(*this);
	element->setThisNodePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::CommunicationPath> NodeImpl::createCommunicationPath(bool end1IsNavigable, uml::AggregationKind end1Aggregation, std::string end1Name, int end1Lower, int end1Upper, const std::shared_ptr<uml::Node>& end1Node, bool end2IsNavigable, uml::AggregationKind end2Aggregation, std::string end2Name, int end2Lower, int end2Upper)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::CommunicationPath> > NodeImpl::getCommunicationPaths()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool NodeImpl::internal_structure(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference nestedNode */
const std::shared_ptr<Subset<uml::Node, uml::NamedElement>>& NodeImpl::getNestedNode() const
{
	if(m_nestedNode == nullptr)
	{
		/*Subset*/
		m_nestedNode.reset(new Subset<uml::Node, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_nestedNode - Subset<uml::Node, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getNestedNode()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedNode - Subset<uml::Node, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_nestedNode;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> NodeImpl::getAttribute() const
{
	if(m_attribute == nullptr)
	{
		/*SubsetUnion*/
		m_attribute.reset(new SubsetUnion<uml::Property, uml::Feature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getAttribute()->initSubsetUnion(getFeature());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >(getFeature())" << std::endl;
		#endif
		
	}
	return m_attribute;
}

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> NodeImpl::getFeature() const
{
	if(m_feature == nullptr)
	{
		/*SubsetUnion*/
		m_feature.reset(new SubsetUnion<uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getFeature()->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_feature;
}

std::shared_ptr<Union<uml::NamedElement>> NodeImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace> NodeImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> NodeImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> NodeImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedMember()->initSubsetUnion(getOwnedElement(), getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >(getOwnedElement(), getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> NodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> NodeImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}

std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> NodeImpl::getRole() const
{
	if(m_role == nullptr)
	{
		/*SubsetUnion*/
		m_role.reset(new SubsetUnion<uml::ConnectableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getRole()->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_role;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> NodeImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}
	if(auto wp = m_package.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void NodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void NodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ClassImpl::loadAttributes(loadHandler, attr_list);
	DeploymentTargetImpl::loadAttributes(loadHandler, attr_list);
}

void NodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("nestedNode") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Node";
			}
			loadHandler->handleChildContainer<uml::Node>(this->getNestedNode());  

			return; 
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}
	//load BasePackage Nodes
	ClassImpl::loadNode(nodeName, loadHandler);
	DeploymentTargetImpl::loadNode(nodeName, loadHandler);
}

void NodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ClassImpl::resolveReferences(featureID, references);
	DeploymentTargetImpl::resolveReferences(featureID, references);
}

void NodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ClassImpl::saveContent(saveHandler);
	DeploymentTargetImpl::saveContent(saveHandler);
	
	BehavioredClassifierImpl::saveContent(saveHandler);
	EncapsulatedClassifierImpl::saveContent(saveHandler);
	
	StructuredClassifierImpl::saveContent(saveHandler);
	
	ClassifierImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	TypeImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void NodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'nestedNode'
		for (const std::shared_ptr<uml::Node>& nestedNode : *this->getNestedNode()) 
		{
			saveHandler->addReference(nestedNode, "nestedNode", nestedNode->eClass() != package->getNode_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& NodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getNode_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any NodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::NODE_ATTRIBUTE_NESTEDNODE:
			return eAnyBag(getNestedNode(),uml::umlPackage::NODE_CLASS); //15755
	}
	Any result;
	result = ClassImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = DeploymentTargetImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool NodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::NODE_ATTRIBUTE_NESTEDNODE:
			return getNestedNode() != nullptr; //15755
	}
	bool result = false;
	result = ClassImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = DeploymentTargetImpl::internalEIsSet(featureID);
	return result;
}

bool NodeImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::NODE_ATTRIBUTE_NESTEDNODE:
		{
			// CAST Any to Bag<uml::Node>
			if((newValue->isContainer()) && (uml::umlPackage::NODE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Node>> nestedNodeList= newValue->get<std::shared_ptr<Bag<uml::Node>>>();
					std::shared_ptr<Bag<uml::Node>> _nestedNode=getNestedNode();
					for(const std::shared_ptr<uml::Node> indexNestedNode: *_nestedNode)
					{
						if (!(nestedNodeList->includes(indexNestedNode)))
						{
							_nestedNode->erase(indexNestedNode);
						}
					}

					for(const std::shared_ptr<uml::Node> indexNestedNode: *nestedNodeList)
					{
						if (!(_nestedNode->includes(indexNestedNode)))
						{
							_nestedNode->add(indexNestedNode);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
	}

	bool result = false;
	result = ClassImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = DeploymentTargetImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
Any NodeImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::Node::createCommunicationPath(bool, uml::AggregationKind, std::string, int, int, uml::Node, bool, uml::AggregationKind, std::string, int, int) : uml::CommunicationPath: 2087191607
		case umlPackage::NODE_OPERATION_CREATECOMMUNICATIONPATH_BOOLEAN_UNLIMITEDNATURAL:
		{
			//Retrieve input parameter 'end1IsNavigable'
			//parameter 0
			bool incoming_param_end1IsNavigable;
			std::list<Any>::const_iterator incoming_param_end1IsNavigable_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_end1IsNavigable = (*incoming_param_end1IsNavigable_arguments_citer)->get<bool >();
			//Retrieve input parameter 'end1Aggregation'
			//parameter 1
			uml::AggregationKind incoming_param_end1Aggregation;
			std::list<Any>::const_iterator incoming_param_end1Aggregation_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_end1Aggregation = (*incoming_param_end1Aggregation_arguments_citer)->get<uml::AggregationKind >();
			//Retrieve input parameter 'end1Name'
			//parameter 2
			std::string incoming_param_end1Name;
			std::list<Any>::const_iterator incoming_param_end1Name_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_end1Name = (*incoming_param_end1Name_arguments_citer)->get<std::string >();
			//Retrieve input parameter 'end1Lower'
			//parameter 3
			int incoming_param_end1Lower;
			std::list<Any>::const_iterator incoming_param_end1Lower_arguments_citer = std::next(arguments->begin(), 3);
			incoming_param_end1Lower = (*incoming_param_end1Lower_arguments_citer)->get<int >();
			//Retrieve input parameter 'end1Upper'
			//parameter 4
			int incoming_param_end1Upper;
			std::list<Any>::const_iterator incoming_param_end1Upper_arguments_citer = std::next(arguments->begin(), 4);
			incoming_param_end1Upper = (*incoming_param_end1Upper_arguments_citer)->get<int >();
			//Retrieve input parameter 'end1Node'
			//parameter 5
			std::shared_ptr<uml::Node> incoming_param_end1Node;
			std::list<Any>::const_iterator incoming_param_end1Node_arguments_citer = std::next(arguments->begin(), 5);
			incoming_param_end1Node = (*incoming_param_end1Node_arguments_citer)->get<std::shared_ptr<uml::Node> >();
			//Retrieve input parameter 'end2IsNavigable'
			//parameter 6
			bool incoming_param_end2IsNavigable;
			std::list<Any>::const_iterator incoming_param_end2IsNavigable_arguments_citer = std::next(arguments->begin(), 6);
			incoming_param_end2IsNavigable = (*incoming_param_end2IsNavigable_arguments_citer)->get<bool >();
			//Retrieve input parameter 'end2Aggregation'
			//parameter 7
			uml::AggregationKind incoming_param_end2Aggregation;
			std::list<Any>::const_iterator incoming_param_end2Aggregation_arguments_citer = std::next(arguments->begin(), 7);
			incoming_param_end2Aggregation = (*incoming_param_end2Aggregation_arguments_citer)->get<uml::AggregationKind >();
			//Retrieve input parameter 'end2Name'
			//parameter 8
			std::string incoming_param_end2Name;
			std::list<Any>::const_iterator incoming_param_end2Name_arguments_citer = std::next(arguments->begin(), 8);
			incoming_param_end2Name = (*incoming_param_end2Name_arguments_citer)->get<std::string >();
			//Retrieve input parameter 'end2Lower'
			//parameter 9
			int incoming_param_end2Lower;
			std::list<Any>::const_iterator incoming_param_end2Lower_arguments_citer = std::next(arguments->begin(), 9);
			incoming_param_end2Lower = (*incoming_param_end2Lower_arguments_citer)->get<int >();
			//Retrieve input parameter 'end2Upper'
			//parameter 10
			int incoming_param_end2Upper;
			std::list<Any>::const_iterator incoming_param_end2Upper_arguments_citer = std::next(arguments->begin(), 10);
			incoming_param_end2Upper = (*incoming_param_end2Upper_arguments_citer)->get<int >();
			result = eAnyObject(this->createCommunicationPath(incoming_param_end1IsNavigable,incoming_param_end1Aggregation,incoming_param_end1Name,incoming_param_end1Lower,incoming_param_end1Upper,incoming_param_end1Node,incoming_param_end2IsNavigable,incoming_param_end2Aggregation,incoming_param_end2Name,incoming_param_end2Lower,incoming_param_end2Upper), uml::umlPackage::COMMUNICATIONPATH_CLASS);
			break;
		}
		// uml::Node::getCommunicationPaths() : uml::CommunicationPath[*]: 810632424
		case umlPackage::NODE_OPERATION_GETCOMMUNICATIONPATHS:
		{
			std::shared_ptr<Bag<uml::CommunicationPath> > resultList = this->getCommunicationPaths();
			return eAnyBag(resultList,uml::umlPackage::COMMUNICATIONPATH_CLASS);
			break;
		}
		// uml::Node::internal_structure(Any, std::map) : bool: 1965611485
		case umlPackage::NODE_OPERATION_INTERNAL_STRUCTURE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->internal_structure(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = DeploymentTargetImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = ClassImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Node> NodeImpl::getThisNodePtr() const
{
	return m_thisNodePtr.lock();
}
void NodeImpl::setThisNodePtr(std::weak_ptr<uml::Node> thisNodePtr)
{
	m_thisNodePtr = thisNodePtr;
	setThisClassPtr(thisNodePtr);
	setThisDeploymentTargetPtr(thisNodePtr);
}


