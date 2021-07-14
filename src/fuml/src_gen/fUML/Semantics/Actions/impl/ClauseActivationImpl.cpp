#include "fUML/Semantics/Actions/impl/ClauseActivationImpl.hpp"

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
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"


#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/Clause.hpp"
#include "fUML/Semantics/Actions/ClauseActivation.hpp"
#include "fUML/Semantics/Actions/ConditionalNodeActivation.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
ClauseActivationImpl::ClauseActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ClauseActivationImpl::~ClauseActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ClauseActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ClauseActivationImpl::ClauseActivationImpl(const ClauseActivationImpl & obj): ClauseActivationImpl()
{
	*this = obj;
}

ClauseActivationImpl& ClauseActivationImpl::operator=(const ClauseActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	ClauseActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ClauseActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_clause  = obj.getClause();
	m_conditionalNodeActivation  = obj.getConditionalNodeActivation();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ClauseActivationImpl::copy() const
{
	std::shared_ptr<ClauseActivationImpl> element(new ClauseActivationImpl());
	*element =(*this);
	element->setThisClauseActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ClauseActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getClauseActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> ClauseActivationImpl::getDecision()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<fUML::Semantics::Actions::ClauseActivation> > ClauseActivationImpl::getPredecessors()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<fUML::Semantics::Actions::ClauseActivation> > ClauseActivationImpl::getSuccessors()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClauseActivationImpl::isReady()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ClauseActivationImpl::recieveControl()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ClauseActivationImpl::runTest()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ClauseActivationImpl::selectBody()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference clause
*/
std::shared_ptr<uml::Clause> ClauseActivationImpl::getClause() const
{
//assert(m_clause);
    return m_clause;
}
void ClauseActivationImpl::setClause(std::shared_ptr<uml::Clause> _clause)
{
    m_clause = _clause;
	
}


/*
Getter & Setter for reference conditionalNodeActivation
*/
std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> ClauseActivationImpl::getConditionalNodeActivation() const
{
//assert(m_conditionalNodeActivation);
    return m_conditionalNodeActivation;
}
void ClauseActivationImpl::setConditionalNodeActivation(std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> _conditionalNodeActivation)
{
    m_conditionalNodeActivation = _conditionalNodeActivation;
	
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<ClauseActivation> ClauseActivationImpl::getThisClauseActivationPtr() const
{
	return m_thisClauseActivationPtr.lock();
}
void ClauseActivationImpl::setThisClauseActivationPtr(std::weak_ptr<ClauseActivation> thisClauseActivationPtr)
{
	m_thisClauseActivationPtr = thisClauseActivationPtr;
}
std::shared_ptr<ecore::EObject> ClauseActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ClauseActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CLAUSEACTIVATION_ATTRIBUTE_CLAUSE:
			return eAny(getClause()); //260
		case fUML::Semantics::Actions::ActionsPackage::CLAUSEACTIVATION_ATTRIBUTE_CONDITIONALNODEACTIVATION:
			return eAny(getConditionalNodeActivation()); //261
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ClauseActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CLAUSEACTIVATION_ATTRIBUTE_CLAUSE:
			return getClause() != nullptr; //260
		case fUML::Semantics::Actions::ActionsPackage::CLAUSEACTIVATION_ATTRIBUTE_CONDITIONALNODEACTIVATION:
			return getConditionalNodeActivation() != nullptr; //261
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ClauseActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CLAUSEACTIVATION_ATTRIBUTE_CLAUSE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Clause> _clause = std::dynamic_pointer_cast<uml::Clause>(_temp);
			setClause(_clause); //260
			return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::CLAUSEACTIVATION_ATTRIBUTE_CONDITIONALNODEACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> _conditionalNodeActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::ConditionalNodeActivation>(_temp);
			setConditionalNodeActivation(_conditionalNodeActivation); //261
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ClauseActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 2606
		case ActionsPackage::CLAUSEACTIVATION_OPERATION_GETDECISION:
		{
			result = eAny(this->getDecision());
			break;
		}
		
		// 2607
		case ActionsPackage::CLAUSEACTIVATION_OPERATION_GETPREDECESSORS:
		{
			result = eAny(this->getPredecessors());
			break;
		}
		
		// 2608
		case ActionsPackage::CLAUSEACTIVATION_OPERATION_GETSUCCESSORS:
		{
			result = eAny(this->getSuccessors());
			break;
		}
		
		// 2603
		case ActionsPackage::CLAUSEACTIVATION_OPERATION_ISREADY:
		{
			result = eAny(this->isReady());
			break;
		}
		
		// 2602
		case ActionsPackage::CLAUSEACTIVATION_OPERATION_RECIEVECONTROL:
		{
			this->recieveControl();
			break;
		}
		
		// 2604
		case ActionsPackage::CLAUSEACTIVATION_OPERATION_RUNTEST:
		{
			this->runTest();
			break;
		}
		
		// 2605
		case ActionsPackage::CLAUSEACTIVATION_OPERATION_SELECTBODY:
		{
			this->selectBody();
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
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
void ClauseActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ClauseActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("clause");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("clause")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("conditionalNodeActivation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("conditionalNodeActivation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ClauseActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void ClauseActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CLAUSEACTIVATION_ATTRIBUTE_CLAUSE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Clause> _clause = std::dynamic_pointer_cast<uml::Clause>( references.front() );
				setClause(_clause);
			}
			
			return;
		}

		case fUML::Semantics::Actions::ActionsPackage::CLAUSEACTIVATION_ATTRIBUTE_CONDITIONALNODEACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> _conditionalNodeActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::ConditionalNodeActivation>( references.front() );
				setConditionalNodeActivation(_conditionalNodeActivation);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ClauseActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ClauseActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getClause(), "clause", getClause()->eClass() != uml::umlPackage::eInstance()->getClause_Class()); 
		saveHandler->addReference(this->getConditionalNodeActivation(), "conditionalNodeActivation", getConditionalNodeActivation()->eClass() != fUML::Semantics::Actions::ActionsPackage::eInstance()->getConditionalNodeActivation_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

