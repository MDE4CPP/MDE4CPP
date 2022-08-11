
#include "uml/impl/ClauseImpl.hpp"
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
#include "abstractDataTypes/Subset.hpp"


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
#include "uml/Clause.hpp"
#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/ExecutableNode.hpp"
#include "uml/OutputPin.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ClauseImpl::ClauseImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ClauseImpl::~ClauseImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Clause "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ClauseImpl::ClauseImpl(std::weak_ptr<uml::Element> par_owner)
:ClauseImpl()
{
	m_owner = par_owner;
}

ClauseImpl::ClauseImpl(const ClauseImpl & obj): ClauseImpl()
{
	*this = obj;
}

ClauseImpl& ClauseImpl::operator=(const ClauseImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Clause 
	 * which is generated by the compiler (as Clause is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Clause::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Clause "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_body  = obj.getBody();
	m_bodyOutput  = obj.getBodyOutput();
	m_decider  = obj.getDecider();
	m_predecessorClause  = obj.getPredecessorClause();
	m_successorClause  = obj.getSuccessorClause();
	m_test  = obj.getTest();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ClauseImpl::copy() const
{
	std::shared_ptr<ClauseImpl> element(new ClauseImpl());
	*element =(*this);
	element->setThisClausePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool ClauseImpl::body_output_pins(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ClauseImpl::decider_output(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ClauseImpl::test_and_body(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference body */
std::shared_ptr<Bag<uml::ExecutableNode>> ClauseImpl::getBody() const
{
	if(m_body == nullptr)
	{
		m_body.reset(new Bag<uml::ExecutableNode>());
		
		
	}
    return m_body;
}

/* Getter & Setter for reference bodyOutput */
std::shared_ptr<Bag<uml::OutputPin>> ClauseImpl::getBodyOutput() const
{
	if(m_bodyOutput == nullptr)
	{
		m_bodyOutput.reset(new Bag<uml::OutputPin>());
		
		
	}
    return m_bodyOutput;
}

/* Getter & Setter for reference decider */
std::shared_ptr<uml::OutputPin> ClauseImpl::getDecider() const
{
    return m_decider;
}
void ClauseImpl::setDecider(std::shared_ptr<uml::OutputPin> _decider)
{
    m_decider = _decider;
	
}

/* Getter & Setter for reference predecessorClause */
std::shared_ptr<Bag<uml::Clause>> ClauseImpl::getPredecessorClause() const
{
	if(m_predecessorClause == nullptr)
	{
		m_predecessorClause.reset(new Bag<uml::Clause>());
		
		
	}
    return m_predecessorClause;
}

/* Getter & Setter for reference successorClause */
std::shared_ptr<Bag<uml::Clause>> ClauseImpl::getSuccessorClause() const
{
	if(m_successorClause == nullptr)
	{
		m_successorClause.reset(new Bag<uml::Clause>());
		
		
	}
    return m_successorClause;
}

/* Getter & Setter for reference test */
std::shared_ptr<Bag<uml::ExecutableNode>> ClauseImpl::getTest() const
{
	if(m_test == nullptr)
	{
		m_test.reset(new Bag<uml::ExecutableNode>());
		
		
	}
    return m_test;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ClauseImpl::getOwnedElement() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ClauseImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ClauseImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ClauseImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("body");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("body")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("bodyOutput");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bodyOutput")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("decider");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("decider")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("predecessorClause");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("predecessorClause")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("successorClause");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("successorClause")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("test");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("test")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void ClauseImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ElementImpl::loadNode(nodeName, loadHandler);
}

void ClauseImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODY:
		{
			std::shared_ptr<Bag<uml::ExecutableNode>> _body = getBody();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ExecutableNode>  _r = std::dynamic_pointer_cast<uml::ExecutableNode>(ref);
				if (_r != nullptr)
				{
					_body->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODYOUTPUT:
		{
			std::shared_ptr<Bag<uml::OutputPin>> _bodyOutput = getBodyOutput();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::OutputPin>  _r = std::dynamic_pointer_cast<uml::OutputPin>(ref);
				if (_r != nullptr)
				{
					_bodyOutput->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_DECIDER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OutputPin> _decider = std::dynamic_pointer_cast<uml::OutputPin>( references.front() );
				setDecider(_decider);
			}
			
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE:
		{
			std::shared_ptr<Bag<uml::Clause>> _predecessorClause = getPredecessorClause();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Clause>  _r = std::dynamic_pointer_cast<uml::Clause>(ref);
				if (_r != nullptr)
				{
					_predecessorClause->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE:
		{
			std::shared_ptr<Bag<uml::Clause>> _successorClause = getSuccessorClause();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Clause>  _r = std::dynamic_pointer_cast<uml::Clause>(ref);
				if (_r != nullptr)
				{
					_successorClause->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_TEST:
		{
			std::shared_ptr<Bag<uml::ExecutableNode>> _test = getTest();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ExecutableNode>  _r = std::dynamic_pointer_cast<uml::ExecutableNode>(ref);
				if (_r != nullptr)
				{
					_test->push_back(_r);
				}
			}
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void ClauseImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ClauseImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::ExecutableNode>("body", this->getBody());
		saveHandler->addReferences<uml::OutputPin>("bodyOutput", this->getBodyOutput());
		saveHandler->addReference(this->getDecider(), "decider", getDecider()->eClass() != uml::umlPackage::eInstance()->getOutputPin_Class()); 
		saveHandler->addReferences<uml::Clause>("predecessorClause", this->getPredecessorClause());
		saveHandler->addReferences<uml::Clause>("successorClause", this->getSuccessorClause());
		saveHandler->addReferences<uml::ExecutableNode>("test", this->getTest());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ClauseImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getClause_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ClauseImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODY:
			return eEcoreContainerAny(getBody(),uml::umlPackage::EXECUTABLENODE_CLASS); //383
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODYOUTPUT:
			return eEcoreContainerAny(getBodyOutput(),uml::umlPackage::OUTPUTPIN_CLASS); //384
		case uml::umlPackage::CLAUSE_ATTRIBUTE_DECIDER:
			return eAny(getDecider(),uml::umlPackage::OUTPUTPIN_CLASS,false); //385
		case uml::umlPackage::CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE:
			return eEcoreContainerAny(getPredecessorClause(),uml::umlPackage::CLAUSE_CLASS); //386
		case uml::umlPackage::CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE:
			return eEcoreContainerAny(getSuccessorClause(),uml::umlPackage::CLAUSE_CLASS); //387
		case uml::umlPackage::CLAUSE_ATTRIBUTE_TEST:
			return eEcoreContainerAny(getTest(),uml::umlPackage::EXECUTABLENODE_CLASS); //388
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}

bool ClauseImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODY:
			return getBody() != nullptr; //383
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODYOUTPUT:
			return getBodyOutput() != nullptr; //384
		case uml::umlPackage::CLAUSE_ATTRIBUTE_DECIDER:
			return getDecider() != nullptr; //385
		case uml::umlPackage::CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE:
			return getPredecessorClause() != nullptr; //386
		case uml::umlPackage::CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE:
			return getSuccessorClause() != nullptr; //387
		case uml::umlPackage::CLAUSE_ATTRIBUTE_TEST:
			return getTest() != nullptr; //388
	}
	return ElementImpl::internalEIsSet(featureID);
}

bool ClauseImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODY:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::ExecutableNode>> _body = getBody();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ExecutableNode> valueToAdd = std::dynamic_pointer_cast<uml::ExecutableNode>(anEObject);
	
							if (valueToAdd)
							{
								if(_body->find(valueToAdd) == -1)
								{
									_body->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreContainerAny' for feature 'body'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreContainerAny' for feature 'body'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODYOUTPUT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::OutputPin>> _bodyOutput = getBodyOutput();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::OutputPin> valueToAdd = std::dynamic_pointer_cast<uml::OutputPin>(anEObject);
	
							if (valueToAdd)
							{
								if(_bodyOutput->find(valueToAdd) == -1)
								{
									_bodyOutput->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreContainerAny' for feature 'bodyOutput'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreContainerAny' for feature 'bodyOutput'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_DECIDER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::OutputPin> _decider = std::dynamic_pointer_cast<uml::OutputPin>(eObject);
					if(_decider)
					{
						setDecider(_decider); //385
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'decider'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'decider'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Clause>> _predecessorClause = getPredecessorClause();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Clause> valueToAdd = std::dynamic_pointer_cast<uml::Clause>(anEObject);
	
							if (valueToAdd)
							{
								if(_predecessorClause->find(valueToAdd) == -1)
								{
									_predecessorClause->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreContainerAny' for feature 'predecessorClause'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreContainerAny' for feature 'predecessorClause'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Clause>> _successorClause = getSuccessorClause();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Clause> valueToAdd = std::dynamic_pointer_cast<uml::Clause>(anEObject);
	
							if (valueToAdd)
							{
								if(_successorClause->find(valueToAdd) == -1)
								{
									_successorClause->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreContainerAny' for feature 'successorClause'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreContainerAny' for feature 'successorClause'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_TEST:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::ExecutableNode>> _test = getTest();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ExecutableNode> valueToAdd = std::dynamic_pointer_cast<uml::ExecutableNode>(anEObject);
	
							if (valueToAdd)
							{
								if(_test->find(valueToAdd) == -1)
								{
									_test->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreContainerAny' for feature 'test'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreContainerAny' for feature 'test'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ClauseImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Clause::body_output_pins(Any, std::map) : bool: 3629525042
		case umlPackage::CLAUSE_OPERATION_BODY_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'body_output_pins'!"<< std::endl;)
				return nullptr;
			}
			
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'body_output_pins'!"<< std::endl;)
				return nullptr;
			}
			
		
			result = eAny(this->body_output_pins(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Clause::decider_output(Any, std::map) : bool: 1450067495
		case umlPackage::CLAUSE_OPERATION_DECIDER_OUTPUT_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'decider_output'!"<< std::endl;)
				return nullptr;
			}
			
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'decider_output'!"<< std::endl;)
				return nullptr;
			}
			
		
			result = eAny(this->decider_output(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Clause::test_and_body(Any, std::map) : bool: 4255472206
		case umlPackage::CLAUSE_OPERATION_TEST_AND_BODY_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'test_and_body'!"<< std::endl;)
				return nullptr;
			}
			
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'test_and_body'!"<< std::endl;)
				return nullptr;
			}
			
		
			result = eAny(this->test_and_body(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = ElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Clause> ClauseImpl::getThisClausePtr() const
{
	return m_thisClausePtr.lock();
}
void ClauseImpl::setThisClausePtr(std::weak_ptr<uml::Clause> thisClausePtr)
{
	m_thisClausePtr = thisClausePtr;
	setThisElementPtr(thisClausePtr);
}


