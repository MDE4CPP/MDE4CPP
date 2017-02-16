#include "ClauseActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ClauseActivationImpl::ClauseActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

ClauseActivationImpl::~ClauseActivationImpl()
{
	
}

ClauseActivationImpl::ClauseActivationImpl(const ClauseActivationImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_clause  = obj.getClause();

	m_conditionalNodeActivation  = obj.getConditionalNodeActivation();


	//clone containt lists
}

ecore::EObject *  ClauseActivationImpl::copy() const
{
	return new ClauseActivationImpl(*this);
}

ecore::EClass* ClauseActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getClauseActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::BooleanValue *  ClauseActivationImpl::getDecision() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<fUML::ClauseActivation * > *  ClauseActivationImpl::getPredecessors() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<fUML::ClauseActivation * > *  ClauseActivationImpl::getSuccessors() 
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
uml::Clause *  ClauseActivationImpl::getClause() const
{
	//assert(m_clause);
	return m_clause;
}
void ClauseActivationImpl::setClause(uml::Clause *  _clause)
{
	m_clause = _clause;
}

fUML::ConditionalNodeActivation *  ClauseActivationImpl::getConditionalNodeActivation() const
{
	//assert(m_conditionalNodeActivation);
	return m_conditionalNodeActivation;
}
void ClauseActivationImpl::setConditionalNodeActivation(fUML::ConditionalNodeActivation *  _conditionalNodeActivation)
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
