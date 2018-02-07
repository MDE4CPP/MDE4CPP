#include "fUML/impl/ClauseActivationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "fUML/BooleanValue.hpp"

#include "uml/Clause.hpp"

#include "fUML/ClauseActivation.hpp"

#include "fUML/ConditionalNodeActivation.hpp"


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
	std::shared_ptr<ecore::EObject> element(new ClauseActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ClauseActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getClauseActivation();
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


std::shared_ptr<ecore::EObject> ClauseActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ClauseActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::CLAUSEACTIVATION_CLAUSE:
			return getClause(); //700
		case FUMLPackage::CLAUSEACTIVATION_CONDITIONALNODEACTIVATION:
			return getConditionalNodeActivation(); //701
	}
	return boost::any();
}

void ClauseActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::CLAUSEACTIVATION_CLAUSE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Clause> _clause = boost::any_cast<std::shared_ptr<uml::Clause>>(newValue);
			setClause(_clause); //700
			break;
		}
		case FUMLPackage::CLAUSEACTIVATION_CONDITIONALNODEACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ConditionalNodeActivation> _conditionalNodeActivation = boost::any_cast<std::shared_ptr<fUML::ConditionalNodeActivation>>(newValue);
			setConditionalNodeActivation(_conditionalNodeActivation); //701
			break;
		}
	}
}
