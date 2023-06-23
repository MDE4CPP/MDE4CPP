
#include "uml/impl/ProtocolConformanceImpl.hpp"
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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
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
#include "uml/Comment.hpp"
#include "uml/DirectedRelationship.hpp"
#include "uml/Element.hpp"
#include "uml/ProtocolStateMachine.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ProtocolConformanceImpl::ProtocolConformanceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ProtocolConformanceImpl::~ProtocolConformanceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ProtocolConformance "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ProtocolConformanceImpl::ProtocolConformanceImpl(std::weak_ptr<uml::Element> par_owner)
:ProtocolConformanceImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ProtocolConformanceImpl::ProtocolConformanceImpl(std::weak_ptr<uml::ProtocolStateMachine> par_specificMachine)
:ProtocolConformanceImpl()
{
	m_specificMachine = par_specificMachine;
	m_owner = par_specificMachine;
}

ProtocolConformanceImpl::ProtocolConformanceImpl(const ProtocolConformanceImpl & obj): ProtocolConformanceImpl()
{
	*this = obj;
}

ProtocolConformanceImpl& ProtocolConformanceImpl::operator=(const ProtocolConformanceImpl & obj)
{
	//call overloaded =Operator for each base class
	DirectedRelationshipImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ProtocolConformance 
	 * which is generated by the compiler (as ProtocolConformance is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ProtocolConformance::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ProtocolConformance "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_specificMachine  = obj.getSpecificMachine();
	//Clone references with containment (deep copy)
	//clone reference 'generalMachine'
	if(obj.getGeneralMachine()!=nullptr)
	{
		m_generalMachine = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(obj.getGeneralMachine()->copy());
	}
	return *this;
}

std::shared_ptr<ecore::EObject> ProtocolConformanceImpl::copy() const
{
	std::shared_ptr<ProtocolConformanceImpl> element(new ProtocolConformanceImpl());
	*element =(*this);
	element->setThisProtocolConformancePtr(element);
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
/* Getter & Setter for reference generalMachine */
const std::shared_ptr<uml::ProtocolStateMachine>& ProtocolConformanceImpl::getGeneralMachine() const
{
    return m_generalMachine;
}
void ProtocolConformanceImpl::setGeneralMachine(const std::shared_ptr<uml::ProtocolStateMachine>& _generalMachine)
{
    m_generalMachine = _generalMachine;
	
}

/* Getter & Setter for reference specificMachine */
std::weak_ptr<uml::ProtocolStateMachine> ProtocolConformanceImpl::getSpecificMachine() const
{
    return m_specificMachine;
}
void ProtocolConformanceImpl::setSpecificMachine(std::weak_ptr<uml::ProtocolStateMachine> _specificMachine)
{
    m_specificMachine = _specificMachine;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ProtocolConformanceImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_specificMachine.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ProtocolConformanceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ProtocolConformanceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("generalMachine");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("generalMachine")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DirectedRelationshipImpl::loadAttributes(loadHandler, attr_list);
}

void ProtocolConformanceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
}

void ProtocolConformanceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLCONFORMANCE_ATTRIBUTE_GENERALMACHINE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ProtocolStateMachine> _generalMachine = std::dynamic_pointer_cast<uml::ProtocolStateMachine>( references.front() );
				setGeneralMachine(_generalMachine);
			}
			
			return;
		}

		case uml::umlPackage::PROTOCOLCONFORMANCE_ATTRIBUTE_SPECIFICMACHINE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ProtocolStateMachine> _specificMachine = std::dynamic_pointer_cast<uml::ProtocolStateMachine>( references.front() );
				setSpecificMachine(_specificMachine);
			}
			
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
}

void ProtocolConformanceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ProtocolConformanceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getGeneralMachine(), "generalMachine", getGeneralMachine()->eClass() != uml::umlPackage::eInstance()->getProtocolStateMachine_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ProtocolConformanceImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getProtocolConformance_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ProtocolConformanceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLCONFORMANCE_ATTRIBUTE_GENERALMACHINE:
			return eAny(getGeneralMachine(),uml::umlPackage::PROTOCOLSTATEMACHINE_CLASS,false); //1866
		case uml::umlPackage::PROTOCOLCONFORMANCE_ATTRIBUTE_SPECIFICMACHINE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getSpecificMachine().lock();
			return eEcoreAny(returnValue,uml::umlPackage::PROTOCOLSTATEMACHINE_CLASS); //1867
		}
	}
	return DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
}

bool ProtocolConformanceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLCONFORMANCE_ATTRIBUTE_GENERALMACHINE:
			return getGeneralMachine() != nullptr; //1866
		case uml::umlPackage::PROTOCOLCONFORMANCE_ATTRIBUTE_SPECIFICMACHINE:
			return getSpecificMachine().lock() != nullptr; //1867
	}
	return DirectedRelationshipImpl::internalEIsSet(featureID);
}

bool ProtocolConformanceImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLCONFORMANCE_ATTRIBUTE_GENERALMACHINE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ProtocolStateMachine> _generalMachine = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(eObject);
					if(_generalMachine)
					{
						setGeneralMachine(_generalMachine); //1866
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'generalMachine'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'generalMachine'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::PROTOCOLCONFORMANCE_ATTRIBUTE_SPECIFICMACHINE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ProtocolStateMachine> _specificMachine = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(eObject);
					if(_specificMachine)
					{
						setSpecificMachine(_specificMachine); //1867
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'specificMachine'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'specificMachine'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return DirectedRelationshipImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ProtocolConformanceImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DirectedRelationshipImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ProtocolConformance> ProtocolConformanceImpl::getThisProtocolConformancePtr() const
{
	return m_thisProtocolConformancePtr.lock();
}
void ProtocolConformanceImpl::setThisProtocolConformancePtr(std::weak_ptr<uml::ProtocolConformance> thisProtocolConformancePtr)
{
	m_thisProtocolConformancePtr = thisProtocolConformancePtr;
	setThisDirectedRelationshipPtr(thisProtocolConformancePtr);
}


