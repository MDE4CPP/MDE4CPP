#include "ExpansionRegionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExpansionRegionActivationImpl::ExpansionRegionActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_activationGroups == nullptr)
	{
		m_activationGroups = new std::vector<fUML::ExpansionActivationGroup * >();
	}
	if( m_inputExpansionTokens == nullptr)
	{
		m_inputExpansionTokens = new std::vector<fUML::TokenSet * >();
	}
	if( m_inputTokens == nullptr)
	{
		m_inputTokens = new std::vector<fUML::TokenSet * >();
	}
}

ExpansionRegionActivationImpl::~ExpansionRegionActivationImpl()
{
	if(m_inputTokens!=nullptr)
	{
		delete(m_inputTokens);
	 	m_inputTokens = nullptr;
	}
	if(m_inputExpansionTokens!=nullptr)
	{
		delete(m_inputExpansionTokens);
	 	m_inputExpansionTokens = nullptr;
	}
	if(m_activationGroups!=nullptr)
	{
		delete(m_activationGroups);
	 	m_activationGroups = nullptr;
	}
	
}

ExpansionRegionActivationImpl::ExpansionRegionActivationImpl(const ExpansionRegionActivationImpl & obj)
{
	//create copy of all Attributes
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with now containment
	
	std::vector<fUML::ExpansionActivationGroup * > *  _activationGroups = obj.getActivationGroups();
	this->getActivationGroups()->insert(this->getActivationGroups()->end(), _activationGroups->begin(), _activationGroups->end());

	m_group  = obj.getGroup();

	std::vector<fUML::ActivityEdgeInstance * > *  _incomingEdges = obj.getIncomingEdges();
	this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	std::vector<fUML::TokenSet * > *  _inputExpansionTokens = obj.getInputExpansionTokens();
	this->getInputExpansionTokens()->insert(this->getInputExpansionTokens()->end(), _inputExpansionTokens->begin(), _inputExpansionTokens->end());

	std::vector<fUML::TokenSet * > *  _inputTokens = obj.getInputTokens();
	this->getInputTokens()->insert(this->getInputTokens()->end(), _inputTokens->begin(), _inputTokens->end());

	m_node  = obj.getNode();

	std::vector<fUML::ActivityEdgeInstance * > *  _outgoingEdges = obj.getOutgoingEdges();
	this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());

	std::vector<fUML::PinActivation * > *  _pinActivation = obj.getPinActivation();
	this->getPinActivation()->insert(this->getPinActivation()->end(), _pinActivation->begin(), _pinActivation->end());


	//clone containt lists
	for(fUML::Token * 	_heldTokens : *obj.getHeldTokens())
	{
		this->getHeldTokens()->push_back(dynamic_cast<fUML::Token * >(_heldTokens->copy()));
	}
}

ecore::EObject *  ExpansionRegionActivationImpl::copy() const
{
	return new ExpansionRegionActivationImpl(*this);
}

ecore::EClass* ExpansionRegionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExpansionRegionActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void ExpansionRegionActivationImpl::doStructuredActivity() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

fUML::ExpansionNodeActivation *  ExpansionRegionActivationImpl::getExpansionNodeActivation(uml::ExpansionNode *  node) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int ExpansionRegionActivationImpl::numberOfValues() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ExpansionRegionActivationImpl::runGroup(fUML::ExpansionActivationGroup *  activationGroup) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<fUML::ExpansionActivationGroup * > *  ExpansionRegionActivationImpl::getActivationGroups() const
{
	
	return m_activationGroups;
}


std::vector<fUML::TokenSet * > *  ExpansionRegionActivationImpl::getInputExpansionTokens() const
{
	//assert(m_inputExpansionTokens);
	return m_inputExpansionTokens;
}


std::vector<fUML::TokenSet * > *  ExpansionRegionActivationImpl::getInputTokens() const
{
	
	return m_inputTokens;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExpansionRegionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXPANSIONREGIONACTIVATION_ACTIVATIONGROUPS:
			return getActivationGroups(); //7610
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //767
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //763
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //762
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //761
		case FUMLPackage::EXPANSIONREGIONACTIVATION_INPUTEXPANSIONTOKENS:
			return getInputExpansionTokens(); //769
		case FUMLPackage::EXPANSIONREGIONACTIVATION_INPUTTOKENS:
			return getInputTokens(); //768
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //764
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //760
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //766
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //765
	}
	return boost::any();
}
