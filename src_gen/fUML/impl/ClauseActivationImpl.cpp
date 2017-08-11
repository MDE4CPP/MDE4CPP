#include "ClauseActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "BooleanValue.hpp"

#include "Clause.hpp"

#include "ClauseActivation.hpp"

#include "ConditionalNodeActivation.hpp"


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

ecore::EObject *  ClauseActivationImpl::copy() const
{
	return new ClauseActivationImpl(*this);
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ClauseActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
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
