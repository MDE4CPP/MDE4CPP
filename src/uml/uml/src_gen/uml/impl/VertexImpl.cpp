
#include "uml/impl/VertexImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Region.hpp"
#include "uml/State.hpp"
#include "uml/StateMachine.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Transition.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
VertexImpl::VertexImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

VertexImpl::~VertexImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Vertex "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
VertexImpl::VertexImpl(std::weak_ptr<uml::Region> par_container)
:VertexImpl()
{
	m_container = par_container;
	m_namespace = par_container;
}

//Additional constructor for the containments back reference
VertexImpl::VertexImpl(std::weak_ptr<uml::Namespace> par_namespace)
:VertexImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
VertexImpl::VertexImpl(std::weak_ptr<uml::Element> par_owner)
:VertexImpl()
{
	m_owner = par_owner;
}

VertexImpl::VertexImpl(const VertexImpl & obj): VertexImpl()
{
	*this = obj;
}

VertexImpl& VertexImpl::operator=(const VertexImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Vertex 
	 * which is generated by the compiler (as Vertex is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Vertex::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Vertex "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_container  = obj.getContainer();
	m_incoming  = obj.getIncoming();
	m_outgoing  = obj.getOutgoing();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::StateMachine> VertexImpl::containingStateMachine()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Transition>> VertexImpl::getIncomings()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Transition>> VertexImpl::getOutgoings()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool VertexImpl::isContainedInRegion(const std::shared_ptr<uml::Region>& r)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool VertexImpl::isContainedInState(const std::shared_ptr<uml::State>& s)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference container */
std::weak_ptr<uml::Region> VertexImpl::getContainer() const
{
    return m_container;
}
void VertexImpl::setContainer(std::weak_ptr<uml::Region> _container)
{
    m_container = _container;
	
}

/* Getter & Setter for reference incoming */
const std::shared_ptr<Bag<uml::Transition>>& VertexImpl::getIncoming() const
{
	if(m_incoming == nullptr)
	{
		m_incoming.reset(new Bag<uml::Transition>());
		
		
	}
    return m_incoming;
}

/* Getter & Setter for reference outgoing */
const std::shared_ptr<Bag<uml::Transition>>& VertexImpl::getOutgoing() const
{
	if(m_outgoing == nullptr)
	{
		m_outgoing.reset(new Bag<uml::Transition>());
		
		
	}
    return m_outgoing;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> VertexImpl::eContainer() const
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
void VertexImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void VertexImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void VertexImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void VertexImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::VERTEX_ATTRIBUTE_CONTAINER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Region> _container = std::dynamic_pointer_cast<uml::Region>( references.front() );
				setContainer(_container);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void VertexImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void VertexImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& VertexImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getVertex_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> VertexImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::VERTEX_ATTRIBUTE_CONTAINER:
		{
			std::shared_ptr<ecore::EObject> returnValue=getContainer().lock();
			return eEcoreAny(returnValue,uml::umlPackage::REGION_CLASS); //2549
		}
		case uml::umlPackage::VERTEX_ATTRIBUTE_INCOMING:
			return eEcoreContainerAny(getIncoming(),uml::umlPackage::TRANSITION_CLASS); //25410
		case uml::umlPackage::VERTEX_ATTRIBUTE_OUTGOING:
			return eEcoreContainerAny(getOutgoing(),uml::umlPackage::TRANSITION_CLASS); //25411
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}

bool VertexImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::VERTEX_ATTRIBUTE_CONTAINER:
			return getContainer().lock() != nullptr; //2549
		case uml::umlPackage::VERTEX_ATTRIBUTE_INCOMING:
			return getIncoming() != nullptr; //25410
		case uml::umlPackage::VERTEX_ATTRIBUTE_OUTGOING:
			return getOutgoing() != nullptr; //25411
	}
	return NamedElementImpl::internalEIsSet(featureID);
}

bool VertexImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::VERTEX_ATTRIBUTE_CONTAINER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Region> _container = std::dynamic_pointer_cast<uml::Region>(eObject);
					if(_container)
					{
						setContainer(_container); //2549
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'container'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'container'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> VertexImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Vertex::containingStateMachine() : uml::StateMachine: 2007948051
		case umlPackage::VERTEX_OPERATION_CONTAININGSTATEMACHINE:
		{
			result = eEcoreAny(this->containingStateMachine(), uml::umlPackage::STATEMACHINE_CLASS);
			break;
		}
		// uml::Vertex::getIncomings() : uml::Transition[*]: 124960789
		case umlPackage::VERTEX_OPERATION_GETINCOMINGS:
		{
			std::shared_ptr<Bag<uml::Transition>> resultList = this->getIncomings();
			return eEcoreContainerAny(resultList,uml::umlPackage::TRANSITION_CLASS);
			break;
		}
		// uml::Vertex::getOutgoings() : uml::Transition[*]: 3840074001
		case umlPackage::VERTEX_OPERATION_GETOUTGOINGS:
		{
			std::shared_ptr<Bag<uml::Transition>> resultList = this->getOutgoings();
			return eEcoreContainerAny(resultList,uml::umlPackage::TRANSITION_CLASS);
			break;
		}
		// uml::Vertex::isContainedInRegion(uml::Region) : bool: 1632706225
		case umlPackage::VERTEX_OPERATION_ISCONTAINEDINREGION_REGION:
		{
			//Retrieve input parameter 'r'
			//parameter 0
			std::shared_ptr<uml::Region> incoming_param_r;
			Bag<Any>::const_iterator incoming_param_r_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_r_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_r = std::dynamic_pointer_cast<uml::Region>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'r'. Failed to invoke operation 'isContainedInRegion'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'r'. Failed to invoke operation 'isContainedInRegion'!")
					return nullptr;
				}
			}
		
			result = eAny(this->isContainedInRegion(incoming_param_r), 0, false);
			break;
		}
		// uml::Vertex::isContainedInState(uml::State) : bool: 3997919607
		case umlPackage::VERTEX_OPERATION_ISCONTAINEDINSTATE_STATE:
		{
			//Retrieve input parameter 's'
			//parameter 0
			std::shared_ptr<uml::State> incoming_param_s;
			Bag<Any>::const_iterator incoming_param_s_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_s_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_s = std::dynamic_pointer_cast<uml::State>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 's'. Failed to invoke operation 'isContainedInState'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 's'. Failed to invoke operation 'isContainedInState'!")
					return nullptr;
				}
			}
		
			result = eAny(this->isContainedInState(incoming_param_s), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Vertex> VertexImpl::getThisVertexPtr() const
{
	return m_thisVertexPtr.lock();
}
void VertexImpl::setThisVertexPtr(std::weak_ptr<uml::Vertex> thisVertexPtr)
{
	m_thisVertexPtr = thisVertexPtr;
	setThisNamedElementPtr(thisVertexPtr);
}


