
#include "uml/impl/JoinNodeImpl.hpp"
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
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/ControlNode.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
JoinNodeImpl::JoinNodeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

JoinNodeImpl::~JoinNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete JoinNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
JoinNodeImpl::JoinNodeImpl(std::weak_ptr<uml::Activity> par_activity)
:JoinNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
JoinNodeImpl::JoinNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:JoinNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
JoinNodeImpl::JoinNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:JoinNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
JoinNodeImpl::JoinNodeImpl(std::weak_ptr<uml::Element> par_owner)
:JoinNodeImpl()
{
	m_owner = par_owner;
}

JoinNodeImpl::JoinNodeImpl(const JoinNodeImpl & obj): JoinNodeImpl()
{
	*this = obj;
}

JoinNodeImpl& JoinNodeImpl::operator=(const JoinNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	ControlNodeImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of JoinNode 
	 * which is generated by the compiler (as JoinNode is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//JoinNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy JoinNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isCombineDuplicate = obj.getIsCombineDuplicate();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'joinSpec'
	if(obj.getJoinSpec()!=nullptr)
	{
		m_joinSpec = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getJoinSpec()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> JoinNodeImpl::copy() const
{
	std::shared_ptr<JoinNodeImpl> element(new JoinNodeImpl());
	*element =(*this);
	element->setThisJoinNodePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool JoinNodeImpl::incoming_object_flow(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool JoinNodeImpl::one_outgoing_edge(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isCombineDuplicate */
bool JoinNodeImpl::getIsCombineDuplicate() const 
{
	return m_isCombineDuplicate;
}
void JoinNodeImpl::setIsCombineDuplicate(bool _isCombineDuplicate)
{
	m_isCombineDuplicate = _isCombineDuplicate;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference joinSpec */
std::shared_ptr<uml::ValueSpecification> JoinNodeImpl::getJoinSpec() const
{
    return m_joinSpec;
}
void JoinNodeImpl::setJoinSpec(std::shared_ptr<uml::ValueSpecification> _joinSpec)
{
    m_joinSpec = _joinSpec;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> JoinNodeImpl::getInGroup() const
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

std::shared_ptr<Union<uml::Element>> JoinNodeImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> JoinNodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> JoinNodeImpl::getRedefinedElement() const
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
std::shared_ptr<ecore::EObject> JoinNodeImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
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
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void JoinNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void JoinNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isCombineDuplicate");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsCombineDuplicate(value);
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

	ControlNodeImpl::loadAttributes(loadHandler, attr_list);
}

void JoinNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("joinSpec") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getJoinSpec()); 

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
	ControlNodeImpl::loadNode(nodeName, loadHandler);
}

void JoinNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ControlNodeImpl::resolveReferences(featureID, references);
}

void JoinNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ControlNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void JoinNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'joinSpec'
		std::shared_ptr<uml::ValueSpecification> joinSpec = this->getJoinSpec();
		if (joinSpec != nullptr)
		{
			saveHandler->addReference(joinSpec, "joinSpec", joinSpec->eClass() != package->getValueSpecification_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getJoinNode_Attribute_isCombineDuplicate()) )
		{
			saveHandler->addAttribute("isCombineDuplicate", this->getIsCombineDuplicate());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> JoinNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getJoinNode_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> JoinNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::JOINNODE_ATTRIBUTE_ISCOMBINEDUPLICATE:
			return eAny(getIsCombineDuplicate(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //13120
		case uml::umlPackage::JOINNODE_ATTRIBUTE_JOINSPEC:
			return eAny(getJoinSpec(),uml::umlPackage::VALUESPECIFICATION_CLASS,false); //13121
	}
	return ControlNodeImpl::eGet(featureID, resolve, coreType);
}

bool JoinNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::JOINNODE_ATTRIBUTE_ISCOMBINEDUPLICATE:
			return getIsCombineDuplicate() != true; //13120
		case uml::umlPackage::JOINNODE_ATTRIBUTE_JOINSPEC:
			return getJoinSpec() != nullptr; //13121
	}
	return ControlNodeImpl::internalEIsSet(featureID);
}

bool JoinNodeImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::JOINNODE_ATTRIBUTE_ISCOMBINEDUPLICATE:
		{
			// CAST Any to bool
			bool _isCombineDuplicate = newValue->get<bool>();
			setIsCombineDuplicate(_isCombineDuplicate); //13120
			return true;
		}
		case uml::umlPackage::JOINNODE_ATTRIBUTE_JOINSPEC:
		{
			// CAST Any to uml::ValueSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _joinSpec = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setJoinSpec(_joinSpec); //13121
			return true;
		}
	}

	return ControlNodeImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> JoinNodeImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::JoinNode::incoming_object_flow(Any, std::map) : bool: 3951350133
		case umlPackage::JOINNODE_OPERATION_INCOMING_OBJECT_FLOW_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any> >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->incoming_object_flow(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::JoinNode::one_outgoing_edge(Any, std::map) : bool: 2181464453
		case umlPackage::JOINNODE_OPERATION_ONE_OUTGOING_EDGE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any> >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->one_outgoing_edge(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = ControlNodeImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::JoinNode> JoinNodeImpl::getThisJoinNodePtr() const
{
	return m_thisJoinNodePtr.lock();
}
void JoinNodeImpl::setThisJoinNodePtr(std::weak_ptr<uml::JoinNode> thisJoinNodePtr)
{
	m_thisJoinNodePtr = thisJoinNodePtr;
	setThisControlNodePtr(thisJoinNodePtr);
}


