#include "ConditionalNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ConditionalNodeActivationImpl::ConditionalNodeActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	m_clauseActivations.reset(new std::vector<std::shared_ptr<fUML::ClauseActivation>>());
	m_selectedClauses.reset(new std::vector<std::shared_ptr<uml::Clause>>());
}

ConditionalNodeActivationImpl::~ConditionalNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConditionalNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ConditionalNodeActivationImpl::ConditionalNodeActivationImpl(const ConditionalNodeActivationImpl & obj)
{
	//create copy of all Attributes
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_group  = obj.getGroup();

	std::shared_ptr<std::vector<std::shared_ptr<fUML::ActivityEdgeInstance>>> _incomingEdges = obj.getIncomingEdges();
	this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

	std::shared_ptr<std::vector<std::shared_ptr<fUML::ActivityEdgeInstance>>> _outgoingEdges = obj.getOutgoingEdges();
	this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());

	std::shared_ptr<std::vector<std::shared_ptr<fUML::PinActivation>>> _pinActivation = obj.getPinActivation();
	this->getPinActivation()->insert(this->getPinActivation()->end(), _pinActivation->begin(), _pinActivation->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::Clause>>> _selectedClauses = obj.getSelectedClauses();
	this->getSelectedClauses()->insert(this->getSelectedClauses()->end(), _selectedClauses->begin(), _selectedClauses->end());


	//clone containt lists
	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup.reset(dynamic_cast<fUML::ActivityNodeActivationGroup*>(obj.getActivationGroup()->copy()));
	}
	std::shared_ptr<std::vector<std::shared_ptr<fUML::ClauseActivation>>> _clauseActivationsList = obj.getClauseActivations();
	for(std::shared_ptr<fUML::ClauseActivation> _clauseActivations : *_clauseActivationsList)
	{
		this->getClauseActivations()->push_back(std::shared_ptr<fUML::ClauseActivation>(dynamic_cast<fUML::ClauseActivation*>(_clauseActivations->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->push_back(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
}

ecore::EObject *  ConditionalNodeActivationImpl::copy() const
{
	return new ConditionalNodeActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> ConditionalNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getConditionalNodeActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::ClauseActivation>  ConditionalNodeActivationImpl::getClauseActivation(std::shared_ptr<uml::Clause>  clause) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ConditionalNodeActivationImpl::runTest(std::shared_ptr<uml::Clause>  clause) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ConditionalNodeActivationImpl::selectBody(std::shared_ptr<uml::Clause>  clause) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<fUML::ClauseActivation>>> ConditionalNodeActivationImpl::getClauseActivations() const
{

    return m_clauseActivations;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::Clause>>> ConditionalNodeActivationImpl::getSelectedClauses() const
{

    return m_selectedClauses;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ConditionalNodeActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::STRUCTUREDACTIVITYNODEACTIVATION_ACTIVATIONGROUP:
			return getActivationGroup(); //738
		case FUMLPackage::CONDITIONALNODEACTIVATION_CLAUSEACTIVATIONS:
			return getClauseActivations(); //739
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //737
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //733
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //732
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //731
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //734
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //730
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //736
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //735
		case FUMLPackage::CONDITIONALNODEACTIVATION_SELECTEDCLAUSES:
			return getSelectedClauses(); //7310
	}
	return boost::any();
}
