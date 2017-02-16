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
	// Reference Members
	//*********************************
	if( m_clauseActivations == nullptr)
	{
		m_clauseActivations = new std::vector<fUML::ClauseActivation * >();
	}
	if( m_selectedClauses == nullptr)
	{
		m_selectedClauses = new std::vector<uml::Clause * >();
	}
}

ConditionalNodeActivationImpl::~ConditionalNodeActivationImpl()
{
	if(m_clauseActivations!=nullptr)
	{
		for(auto c :*m_clauseActivations)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_selectedClauses!=nullptr)
	{
		delete(m_selectedClauses);
	 	m_selectedClauses = nullptr;
	}
	
}

ConditionalNodeActivationImpl::ConditionalNodeActivationImpl(const ConditionalNodeActivationImpl & obj)
{
	//create copy of all Attributes
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_group  = obj.getGroup();

	std::vector<fUML::ActivityEdgeInstance * > *  _incomingEdges = obj.getIncomingEdges();
	this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

	std::vector<fUML::ActivityEdgeInstance * > *  _outgoingEdges = obj.getOutgoingEdges();
	this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());

	std::vector<fUML::PinActivation * > *  _pinActivation = obj.getPinActivation();
	this->getPinActivation()->insert(this->getPinActivation()->end(), _pinActivation->begin(), _pinActivation->end());

	std::vector<uml::Clause * > *  _selectedClauses = obj.getSelectedClauses();
	this->getSelectedClauses()->insert(this->getSelectedClauses()->end(), _selectedClauses->begin(), _selectedClauses->end());


	//clone containt lists
	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup = dynamic_cast<fUML::ActivityNodeActivationGroup * >(obj.getActivationGroup()->copy());
	}
	for(fUML::ClauseActivation * 	_clauseActivations : *obj.getClauseActivations())
	{
		this->getClauseActivations()->push_back(dynamic_cast<fUML::ClauseActivation * >(_clauseActivations->copy()));
	}
	for(fUML::Token * 	_heldTokens : *obj.getHeldTokens())
	{
		this->getHeldTokens()->push_back(dynamic_cast<fUML::Token * >(_heldTokens->copy()));
	}
}

ecore::EObject *  ConditionalNodeActivationImpl::copy() const
{
	return new ConditionalNodeActivationImpl(*this);
}

ecore::EClass* ConditionalNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getConditionalNodeActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::ClauseActivation *  ConditionalNodeActivationImpl::getClauseActivation(uml::Clause *  clause) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ConditionalNodeActivationImpl::runTest(uml::Clause *  clause) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ConditionalNodeActivationImpl::selectBody(uml::Clause *  clause) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<fUML::ClauseActivation * > *  ConditionalNodeActivationImpl::getClauseActivations() const
{
	
	return m_clauseActivations;
}


std::vector<uml::Clause * > *  ConditionalNodeActivationImpl::getSelectedClauses() const
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
