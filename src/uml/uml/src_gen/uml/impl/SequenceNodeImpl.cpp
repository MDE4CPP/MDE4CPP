
#include "uml/impl/SequenceNodeImpl.hpp"
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
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/ExecutableNode.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Variable.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
SequenceNodeImpl::SequenceNodeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SequenceNodeImpl::~SequenceNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SequenceNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
SequenceNodeImpl::SequenceNodeImpl(std::weak_ptr<uml::Activity> par_Activity, const int reference_id)
:SequenceNodeImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
		m_activity = par_Activity;
		m_owner = par_Activity;
		 return;
	case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
		m_inActivity = par_Activity;
		m_owner = par_Activity;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
SequenceNodeImpl::SequenceNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:SequenceNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
SequenceNodeImpl::SequenceNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:SequenceNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
SequenceNodeImpl::SequenceNodeImpl(std::weak_ptr<uml::Element> par_owner)
:SequenceNodeImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
SequenceNodeImpl::SequenceNodeImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup)
:SequenceNodeImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}

SequenceNodeImpl::SequenceNodeImpl(const SequenceNodeImpl & obj): SequenceNodeImpl()
{
	*this = obj;
}

SequenceNodeImpl& SequenceNodeImpl::operator=(const SequenceNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	StructuredActivityNodeImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of SequenceNode 
	 * which is generated by the compiler (as SequenceNode is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//SequenceNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SequenceNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	
	return *this;
}

std::shared_ptr<ecore::EObject> SequenceNodeImpl::copy() const
{
	std::shared_ptr<SequenceNodeImpl> element(new SequenceNodeImpl());
	*element =(*this);
	element->setThisSequenceNodePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference executableNode */
const std::shared_ptr<Bag<uml::ExecutableNode>>& SequenceNodeImpl::getExecutableNode() const
{
	//Cast conversion from redefined container reference StructuredActivityNode::node 
	std::shared_ptr<Bag<uml::ExecutableNode>> executableNode(new Bag<uml::ExecutableNode>());

	Bag<uml::ActivityNode>::iterator iter = uml::StructuredActivityNodeImpl::getNode()->begin();
	Bag<uml::ActivityNode>::iterator end = uml::StructuredActivityNodeImpl::getNode()->end();
	
	while(iter != end)
	{
		std::shared_ptr<uml::ExecutableNode> _executableNode = std::dynamic_pointer_cast<uml::ExecutableNode>(*iter);
		if(_executableNode)
		{
			executableNode->add(_executableNode);
		}

		iter++;
	}	
	return executableNode;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityEdge>> SequenceNodeImpl::getContainedEdge() const
{
	if(m_containedEdge == nullptr)
	{
		/*Union*/
		m_containedEdge.reset(new Union<uml::ActivityEdge>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_containedEdge - Union<uml::ActivityEdge>()" << std::endl;
		#endif
		
		
	}
	return m_containedEdge;
}

std::shared_ptr<Union<uml::ActivityNode>> SequenceNodeImpl::getContainedNode() const
{
	if(m_containedNode == nullptr)
	{
		/*Union*/
		m_containedNode.reset(new Union<uml::ActivityNode>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_containedNode - Union<uml::ActivityNode>()" << std::endl;
		#endif
		
		
	}
	return m_containedNode;
}

std::shared_ptr<Union<uml::ActivityGroup>> SequenceNodeImpl::getInGroup() const
{
	if(m_inGroup == nullptr)
	{
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
		
		
	}
	return m_inGroup;
}

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> SequenceNodeImpl::getInput() const
{
	if(m_input == nullptr)
	{
		/*SubsetUnion*/
		m_input.reset(new SubsetUnion<uml::InputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getInput()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_input;
}

std::shared_ptr<Union<uml::NamedElement>> SequenceNodeImpl::getMember() const
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

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> SequenceNodeImpl::getOutput() const
{
	if(m_output == nullptr)
	{
		/*SubsetUnion*/
		m_output.reset(new SubsetUnion<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOutput()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_output;
}

std::shared_ptr<Union<uml::Element>> SequenceNodeImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> SequenceNodeImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> SequenceNodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> SequenceNodeImpl::getRedefinedElement() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> SequenceNodeImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}
	if(auto wp = m_inActivity.lock())
	{
		return wp;
	}


	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_superGroup.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void SequenceNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void SequenceNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	StructuredActivityNodeImpl::loadAttributes(loadHandler, attr_list);
}

void SequenceNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("executableNode") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::ExecutableNode>(this->getExecutableNode());  

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
	StructuredActivityNodeImpl::loadNode(nodeName, loadHandler);
}

void SequenceNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	StructuredActivityNodeImpl::resolveReferences(featureID, references);
}

void SequenceNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuredActivityNodeImpl::saveContent(saveHandler);
	
	ActionImpl::saveContent(saveHandler);
	ActivityGroupImpl::saveContent(saveHandler);
	NamespaceImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void SequenceNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'executableNode'

		saveHandler->addReferences<uml::ExecutableNode>("executableNode", this->getExecutableNode());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& SequenceNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getSequenceNode_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any SequenceNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::SEQUENCENODE_ATTRIBUTE_EXECUTABLENODE:
			return eAnyBag(getExecutableNode(),uml::umlPackage::EXECUTABLENODE_CLASS); //21444
	}
	return StructuredActivityNodeImpl::eGet(featureID, resolve, coreType);
}

bool SequenceNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::SEQUENCENODE_ATTRIBUTE_EXECUTABLENODE:
			return getExecutableNode() != nullptr; //21444
	}
	return StructuredActivityNodeImpl::internalEIsSet(featureID);
}

bool SequenceNodeImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::SEQUENCENODE_ATTRIBUTE_EXECUTABLENODE:
		{
			// CAST Any to Bag<uml::ExecutableNode>
			if((newValue->isContainer()) && (uml::umlPackage::EXECUTABLENODE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ExecutableNode>> executableNodeList= newValue->get<std::shared_ptr<Bag<uml::ExecutableNode>>>();
					std::shared_ptr<Bag<uml::ExecutableNode>> _executableNode=getExecutableNode();
					for(const std::shared_ptr<uml::ExecutableNode> indexExecutableNode: *_executableNode)
					{
						if (executableNodeList->find(indexExecutableNode) == -1)
						{
							_executableNode->erase(indexExecutableNode);
						}
					}

					for(const std::shared_ptr<uml::ExecutableNode> indexExecutableNode: *executableNodeList)
					{
						if (_executableNode->find(indexExecutableNode) == -1)
						{
							_executableNode->add(indexExecutableNode);
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

	return StructuredActivityNodeImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any SequenceNodeImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = StructuredActivityNodeImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::SequenceNode> SequenceNodeImpl::getThisSequenceNodePtr() const
{
	return m_thisSequenceNodePtr.lock();
}
void SequenceNodeImpl::setThisSequenceNodePtr(std::weak_ptr<uml::SequenceNode> thisSequenceNodePtr)
{
	m_thisSequenceNodePtr = thisSequenceNodePtr;
	setThisStructuredActivityNodePtr(thisSequenceNodePtr);
}


