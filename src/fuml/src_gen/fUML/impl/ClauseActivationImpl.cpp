#include "fUML/impl/ClauseActivationImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "fUML/BooleanValue.hpp"

#include "uml/Clause.hpp"

#include "fUML/ClauseActivation.hpp"

#include "fUML/ConditionalNodeActivation.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ClauseActivationImpl::ClauseActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	//Init references
	

	
}

ClauseActivationImpl::~ClauseActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ClauseActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ClauseActivationImpl::ClauseActivationImpl(const ClauseActivationImpl & obj):ClauseActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ClauseActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_clause  = obj.getClause();

	m_conditionalNodeActivation  = obj.getConditionalNodeActivation();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ClauseActivationImpl::copy() const
{
	std::shared_ptr<ClauseActivationImpl> element(new ClauseActivationImpl(*this));
	element->setThisClauseActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ClauseActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getClauseActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::BooleanValue> ClauseActivationImpl::getDecision()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<fUML::ClauseActivation> > ClauseActivationImpl::getPredecessors()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<fUML::ClauseActivation> > ClauseActivationImpl::getSuccessors()
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
std::shared_ptr<uml::Clause > ClauseActivationImpl::getClause() const
{
//assert(m_clause);
    return m_clause;
}
void ClauseActivationImpl::setClause(std::shared_ptr<uml::Clause> _clause)
{
    m_clause = _clause;
}

std::shared_ptr<fUML::ConditionalNodeActivation > ClauseActivationImpl::getConditionalNodeActivation() const
{
//assert(m_conditionalNodeActivation);
    return m_conditionalNodeActivation;
}
void ClauseActivationImpl::setConditionalNodeActivation(std::shared_ptr<fUML::ConditionalNodeActivation> _conditionalNodeActivation)
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
		case FUMLPackage::CLAUSEACTIVATION_EREFERENCE_CLAUSE:
			return eAny(getClause()); //700
		case FUMLPackage::CLAUSEACTIVATION_EREFERENCE_CONDITIONALNODEACTIVATION:
			return eAny(getConditionalNodeActivation()); //701
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ClauseActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::CLAUSEACTIVATION_EREFERENCE_CLAUSE:
			return getClause() != nullptr; //700
		case FUMLPackage::CLAUSEACTIVATION_EREFERENCE_CONDITIONALNODEACTIVATION:
			return getConditionalNodeActivation() != nullptr; //701
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ClauseActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::CLAUSEACTIVATION_EREFERENCE_CLAUSE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Clause> _clause = newValue->get<std::shared_ptr<uml::Clause>>();
			setClause(_clause); //700
			return true;
		}
		case FUMLPackage::CLAUSEACTIVATION_EREFERENCE_CONDITIONALNODEACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ConditionalNodeActivation> _conditionalNodeActivation = newValue->get<std::shared_ptr<fUML::ConditionalNodeActivation>>();
			setConditionalNodeActivation(_conditionalNodeActivation); //701
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
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
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void ClauseActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void ClauseActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::CLAUSEACTIVATION_EREFERENCE_CLAUSE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Clause> _clause = std::dynamic_pointer_cast<uml::Clause>( references.front() );
				setClause(_clause);
			}
			
			return;
		}

		case FUMLPackage::CLAUSEACTIVATION_EREFERENCE_CONDITIONALNODEACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::ConditionalNodeActivation> _conditionalNodeActivation = std::dynamic_pointer_cast<fUML::ConditionalNodeActivation>( references.front() );
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
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		saveHandler->addReference("clause", this->getClause());
		saveHandler->addReference("conditionalNodeActivation", this->getConditionalNodeActivation());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

