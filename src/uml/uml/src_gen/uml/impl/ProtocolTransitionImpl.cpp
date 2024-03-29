
#include "uml/impl/ProtocolTransitionImpl.hpp"
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
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/Region.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Transition.hpp"
#include "uml/Trigger.hpp"
#include "uml/Vertex.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ProtocolTransitionImpl::ProtocolTransitionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ProtocolTransitionImpl::~ProtocolTransitionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ProtocolTransition "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ProtocolTransitionImpl::ProtocolTransitionImpl(std::weak_ptr<uml::Region> par_container)
:ProtocolTransitionImpl()
{
	m_container = par_container;
	m_namespace = par_container;
}

//Additional constructor for the containments back reference
ProtocolTransitionImpl::ProtocolTransitionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ProtocolTransitionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ProtocolTransitionImpl::ProtocolTransitionImpl(std::weak_ptr<uml::Element> par_owner)
:ProtocolTransitionImpl()
{
	m_owner = par_owner;
}

ProtocolTransitionImpl::ProtocolTransitionImpl(const ProtocolTransitionImpl & obj): ProtocolTransitionImpl()
{
	*this = obj;
}

ProtocolTransitionImpl& ProtocolTransitionImpl::operator=(const ProtocolTransitionImpl & obj)
{
	//call overloaded =Operator for each base class
	TransitionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ProtocolTransition 
	 * which is generated by the compiler (as ProtocolTransition is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ProtocolTransition::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ProtocolTransition "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_referred  = obj.getReferred();
	//Clone references with containment (deep copy)
	//clone reference 'postCondition'
	if(obj.getPostCondition()!=nullptr)
	{
		m_postCondition = std::dynamic_pointer_cast<uml::Constraint>(obj.getPostCondition()->copy());
	}

	//clone reference 'preCondition'
	if(obj.getPreCondition()!=nullptr)
	{
		m_preCondition = std::dynamic_pointer_cast<uml::Constraint>(obj.getPreCondition()->copy());
	}
	return *this;
}

std::shared_ptr<ecore::EObject> ProtocolTransitionImpl::copy() const
{
	std::shared_ptr<ProtocolTransitionImpl> element(new ProtocolTransitionImpl());
	*element =(*this);
	element->setThisProtocolTransitionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool ProtocolTransitionImpl::associated_actions(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ProtocolTransitionImpl::belongs_to_psm(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Operation> > ProtocolTransitionImpl::getReferreds()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ProtocolTransitionImpl::refers_to_operation(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference postCondition */
std::shared_ptr<uml::Constraint> ProtocolTransitionImpl::getPostCondition() const
{
    return m_postCondition;
}
void ProtocolTransitionImpl::setPostCondition(std::shared_ptr<uml::Constraint> _postCondition)
{
    m_postCondition = _postCondition;
	
}

/* Getter & Setter for reference preCondition */
std::shared_ptr<uml::Constraint> ProtocolTransitionImpl::getPreCondition() const
{
    return m_preCondition;
}
void ProtocolTransitionImpl::setPreCondition(std::shared_ptr<uml::Constraint> _preCondition)
{
    m_preCondition = _preCondition;
	
}

/* Getter & Setter for reference referred */
std::shared_ptr<Bag<uml::Operation>> ProtocolTransitionImpl::getReferred() const
{
	if(m_referred == nullptr)
	{
		m_referred.reset(new Bag<uml::Operation>());
		
		
	}
    return m_referred;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement>> ProtocolTransitionImpl::getMember() const
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

std::weak_ptr<uml::Namespace> ProtocolTransitionImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ProtocolTransitionImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> ProtocolTransitionImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> ProtocolTransitionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ProtocolTransitionImpl::getRedefinedElement() const
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
std::shared_ptr<ecore::EObject> ProtocolTransitionImpl::eContainer() const
{
	if(auto wp = m_container.lock())
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
void ProtocolTransitionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ProtocolTransitionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("postCondition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("postCondition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("preCondition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("preCondition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	TransitionImpl::loadAttributes(loadHandler, attr_list);
}

void ProtocolTransitionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	TransitionImpl::loadNode(nodeName, loadHandler);
}

void ProtocolTransitionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_POSTCONDITION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Constraint> _postCondition = std::dynamic_pointer_cast<uml::Constraint>( references.front() );
				setPostCondition(_postCondition);
			}
			
			return;
		}

		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_PRECONDITION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Constraint> _preCondition = std::dynamic_pointer_cast<uml::Constraint>( references.front() );
				setPreCondition(_preCondition);
			}
			
			return;
		}
	}
	TransitionImpl::resolveReferences(featureID, references);
}

void ProtocolTransitionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	TransitionImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ProtocolTransitionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getPostCondition(), "postCondition", getPostCondition()->eClass() != uml::umlPackage::eInstance()->getConstraint_Class()); 
		saveHandler->addReference(this->getPreCondition(), "preCondition", getPreCondition()->eClass() != uml::umlPackage::eInstance()->getConstraint_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ProtocolTransitionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getProtocolTransition_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ProtocolTransitionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_POSTCONDITION:
			return eAny(getPostCondition(),uml::umlPackage::CONSTRAINT_CLASS,false); //18826
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_PRECONDITION:
			return eAny(getPreCondition(),uml::umlPackage::CONSTRAINT_CLASS,false); //18827
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_REFERRED:
			return eAnyBag(getReferred(),uml::umlPackage::OPERATION_CLASS); //18828
	}
	return TransitionImpl::eGet(featureID, resolve, coreType);
}

bool ProtocolTransitionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_POSTCONDITION:
			return getPostCondition() != nullptr; //18826
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_PRECONDITION:
			return getPreCondition() != nullptr; //18827
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_REFERRED:
			return getReferred() != nullptr; //18828
	}
	return TransitionImpl::internalEIsSet(featureID);
}

bool ProtocolTransitionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_POSTCONDITION:
		{
			// CAST Any to uml::Constraint
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Constraint> _postCondition = std::dynamic_pointer_cast<uml::Constraint>(_temp);
			setPostCondition(_postCondition); //18826
			return true;
		}
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_PRECONDITION:
		{
			// CAST Any to uml::Constraint
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Constraint> _preCondition = std::dynamic_pointer_cast<uml::Constraint>(_temp);
			setPreCondition(_preCondition); //18827
			return true;
		}
	}

	return TransitionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ProtocolTransitionImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::ProtocolTransition::associated_actions(Any, std::map) : bool: 2063258255
		case umlPackage::PROTOCOLTRANSITION_OPERATION_ASSOCIATED_ACTIONS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->associated_actions(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ProtocolTransition::belongs_to_psm(Any, std::map) : bool: 277614638
		case umlPackage::PROTOCOLTRANSITION_OPERATION_BELONGS_TO_PSM_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->belongs_to_psm(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ProtocolTransition::getReferreds() : uml::Operation[*]: 37225025
		case umlPackage::PROTOCOLTRANSITION_OPERATION_GETREFERREDS:
		{
			std::shared_ptr<Bag<uml::Operation> > resultList = this->getReferreds();
			return eAnyBag(resultList,uml::umlPackage::OPERATION_CLASS);
			break;
		}
		// uml::ProtocolTransition::refers_to_operation(Any, std::map) : bool: 205735088
		case umlPackage::PROTOCOLTRANSITION_OPERATION_REFERS_TO_OPERATION_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->refers_to_operation(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = TransitionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ProtocolTransition> ProtocolTransitionImpl::getThisProtocolTransitionPtr() const
{
	return m_thisProtocolTransitionPtr.lock();
}
void ProtocolTransitionImpl::setThisProtocolTransitionPtr(std::weak_ptr<uml::ProtocolTransition> thisProtocolTransitionPtr)
{
	m_thisProtocolTransitionPtr = thisProtocolTransitionPtr;
	setThisTransitionPtr(thisProtocolTransitionPtr);
}


