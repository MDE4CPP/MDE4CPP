#include "uml/impl/ProtocolConformanceImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/UmlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/DirectedRelationship.hpp"
#include "uml/Element.hpp"
#include "uml/ProtocolStateMachine.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	ProtocolConformance::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ProtocolConformance "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_specificMachine  = obj.getSpecificMachine();
	//Clone references with containment (deep copy)
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

std::shared_ptr<ecore::EClass> ProtocolConformanceImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getProtocolConformance_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference generalMachine
*/
std::shared_ptr<uml::ProtocolStateMachine> ProtocolConformanceImpl::getGeneralMachine() const
{
//assert(m_generalMachine);
    return m_generalMachine;
}
void ProtocolConformanceImpl::setGeneralMachine(std::shared_ptr<uml::ProtocolStateMachine> _generalMachine)
{
    m_generalMachine = _generalMachine;
}


/*
Getter & Setter for reference specificMachine
*/
std::weak_ptr<uml::ProtocolStateMachine> ProtocolConformanceImpl::getSpecificMachine() const
{
//assert(m_specificMachine);
    return m_specificMachine;
}
void ProtocolConformanceImpl::setSpecificMachine(std::weak_ptr<uml::ProtocolStateMachine> _specificMachine)
{
    m_specificMachine = _specificMachine;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ProtocolConformanceImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ProtocolConformanceImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::Element>> ProtocolConformanceImpl::getRelatedElement() const
{
	if(m_relatedElement == nullptr)
	{
		/*Union*/
		m_relatedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_relatedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_relatedElement;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> ProtocolConformanceImpl::getSource() const
{
	if(m_source == nullptr)
	{
		/*SubsetUnion*/
		m_source.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_source->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_source;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> ProtocolConformanceImpl::getTarget() const
{
	if(m_target == nullptr)
	{
		/*SubsetUnion*/
		m_target.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_target->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_target;
}




std::shared_ptr<ProtocolConformance> ProtocolConformanceImpl::getThisProtocolConformancePtr() const
{
	return m_thisProtocolConformancePtr.lock();
}
void ProtocolConformanceImpl::setThisProtocolConformancePtr(std::weak_ptr<ProtocolConformance> thisProtocolConformancePtr)
{
	m_thisProtocolConformancePtr = thisProtocolConformancePtr;
	setThisDirectedRelationshipPtr(thisProtocolConformancePtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any ProtocolConformanceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLCONFORMANCE_ATTRIBUTE_GENERALMACHINE:
			return eAny(getGeneralMachine()); //1866
		case uml::umlPackage::PROTOCOLCONFORMANCE_ATTRIBUTE_SPECIFICMACHINE:
			return eAny(getSpecificMachine().lock()); //1867
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
bool ProtocolConformanceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLCONFORMANCE_ATTRIBUTE_GENERALMACHINE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ProtocolStateMachine> _generalMachine = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(_temp);
			setGeneralMachine(_generalMachine); //1866
			return true;
		}
		case uml::umlPackage::PROTOCOLCONFORMANCE_ATTRIBUTE_SPECIFICMACHINE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ProtocolStateMachine> _specificMachine = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(_temp);
			setSpecificMachine(_specificMachine); //1867
			return true;
		}
	}

	return DirectedRelationshipImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ProtocolConformanceImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DirectedRelationshipImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
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

