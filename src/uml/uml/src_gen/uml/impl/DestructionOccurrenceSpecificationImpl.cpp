
#include "uml/impl/DestructionOccurrenceSpecificationImpl.hpp"
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
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/GeneralOrdering.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Lifeline.hpp"
#include "uml/Message.hpp"
#include "uml/MessageOccurrenceSpecification.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DestructionOccurrenceSpecificationImpl::~DestructionOccurrenceSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DestructionOccurrenceSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:DestructionOccurrenceSpecificationImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:DestructionOccurrenceSpecificationImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:DestructionOccurrenceSpecificationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::Element> par_owner)
:DestructionOccurrenceSpecificationImpl()
{
	m_owner = par_owner;
}

DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(const DestructionOccurrenceSpecificationImpl & obj): DestructionOccurrenceSpecificationImpl()
{
	*this = obj;
}

DestructionOccurrenceSpecificationImpl& DestructionOccurrenceSpecificationImpl::operator=(const DestructionOccurrenceSpecificationImpl & obj)
{
	//call overloaded =Operator for each base class
	MessageOccurrenceSpecificationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of DestructionOccurrenceSpecification 
	 * which is generated by the compiler (as DestructionOccurrenceSpecification is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//DestructionOccurrenceSpecification::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DestructionOccurrenceSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DestructionOccurrenceSpecificationImpl::copy() const
{
	std::shared_ptr<DestructionOccurrenceSpecificationImpl> element(new DestructionOccurrenceSpecificationImpl());
	*element =(*this);
	element->setThisDestructionOccurrenceSpecificationPtr(element);
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

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> DestructionOccurrenceSpecificationImpl::eContainer() const
{
	if(auto wp = m_enclosingInteraction.lock())
	{
		return wp;
	}

	if(auto wp = m_enclosingOperand.lock())
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
void DestructionOccurrenceSpecificationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DestructionOccurrenceSpecificationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	MessageOccurrenceSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void DestructionOccurrenceSpecificationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	MessageOccurrenceSpecificationImpl::loadNode(nodeName, loadHandler);
}

void DestructionOccurrenceSpecificationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	MessageOccurrenceSpecificationImpl::resolveReferences(featureID, references);
}

void DestructionOccurrenceSpecificationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	MessageOccurrenceSpecificationImpl::saveContent(saveHandler);
	
	MessageEndImpl::saveContent(saveHandler);
	OccurrenceSpecificationImpl::saveContent(saveHandler);
	
	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DestructionOccurrenceSpecificationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> DestructionOccurrenceSpecificationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDestructionOccurrenceSpecification_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> DestructionOccurrenceSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return MessageOccurrenceSpecificationImpl::eGet(featureID, resolve, coreType);
}

bool DestructionOccurrenceSpecificationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return MessageOccurrenceSpecificationImpl::internalEIsSet(featureID);
}

bool DestructionOccurrenceSpecificationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return MessageOccurrenceSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> DestructionOccurrenceSpecificationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = MessageOccurrenceSpecificationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::DestructionOccurrenceSpecification> DestructionOccurrenceSpecificationImpl::getThisDestructionOccurrenceSpecificationPtr() const
{
	return m_thisDestructionOccurrenceSpecificationPtr.lock();
}
void DestructionOccurrenceSpecificationImpl::setThisDestructionOccurrenceSpecificationPtr(std::weak_ptr<uml::DestructionOccurrenceSpecification> thisDestructionOccurrenceSpecificationPtr)
{
	m_thisDestructionOccurrenceSpecificationPtr = thisDestructionOccurrenceSpecificationPtr;
	setThisMessageOccurrenceSpecificationPtr(thisDestructionOccurrenceSpecificationPtr);
}


