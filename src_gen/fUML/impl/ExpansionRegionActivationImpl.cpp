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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		m_activationGroups.reset(new Bag<fUML::ExpansionActivationGroup>());
	
	
		m_inputExpansionTokens.reset(new Bag<fUML::TokenSet>());
	
	
		m_inputTokens.reset(new Bag<fUML::TokenSet>());
	
	
}

ExpansionRegionActivationImpl::~ExpansionRegionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionRegionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ExpansionRegionActivationImpl::ExpansionRegionActivationImpl(const ExpansionRegionActivationImpl & obj)
{
	//create copy of all Attributes
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with now containment
	
		std::shared_ptr< Bag<fUML::ExpansionActivationGroup> >
	 _activationGroups = obj.getActivationGroups();
	m_activationGroups.reset(new 	 Bag<fUML::ExpansionActivationGroup> 
	(*(obj.getActivationGroups().get())));// this->getActivationGroups()->insert(this->getActivationGroups()->end(), _activationGroups->begin(), _activationGroups->end());

	m_group  = obj.getGroup();

		std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
	 _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new 	 Bag<fUML::ActivityEdgeInstance> 
	(*(obj.getIncomingEdges().get())));// this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

		std::shared_ptr< Bag<fUML::TokenSet> >
	 _inputExpansionTokens = obj.getInputExpansionTokens();
	m_inputExpansionTokens.reset(new 	 Bag<fUML::TokenSet> 
	(*(obj.getInputExpansionTokens().get())));// this->getInputExpansionTokens()->insert(this->getInputExpansionTokens()->end(), _inputExpansionTokens->begin(), _inputExpansionTokens->end());

		std::shared_ptr< Bag<fUML::TokenSet> >
	 _inputTokens = obj.getInputTokens();
	m_inputTokens.reset(new 	 Bag<fUML::TokenSet> 
	(*(obj.getInputTokens().get())));// this->getInputTokens()->insert(this->getInputTokens()->end(), _inputTokens->begin(), _inputTokens->end());

	m_node  = obj.getNode();

		std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
	 _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new 	 Bag<fUML::ActivityEdgeInstance> 
	(*(obj.getOutgoingEdges().get())));// this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());

		std::shared_ptr< Bag<fUML::PinActivation> >
	 _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new 	 Bag<fUML::PinActivation> 
	(*(obj.getPinActivation().get())));// this->getPinActivation()->insert(this->getPinActivation()->end(), _pinActivation->begin(), _pinActivation->end());


	//clone containt lists
	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
}

ecore::EObject *  ExpansionRegionActivationImpl::copy() const
{
	return new ExpansionRegionActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> ExpansionRegionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExpansionRegionActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void
 ExpansionRegionActivationImpl::doStructuredActivity() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::ExpansionNodeActivation> 
 ExpansionRegionActivationImpl::getExpansionNodeActivation(std::shared_ptr<uml::ExpansionNode>  node) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int
 ExpansionRegionActivationImpl::numberOfValues() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void
 ExpansionRegionActivationImpl::runGroup(std::shared_ptr<fUML::ExpansionActivationGroup>  activationGroup) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<fUML::ExpansionActivationGroup> >
 ExpansionRegionActivationImpl::getActivationGroups() const
{

    return m_activationGroups;
}


	std::shared_ptr< Bag<fUML::TokenSet> >
 ExpansionRegionActivationImpl::getInputExpansionTokens() const
{
//assert(m_inputExpansionTokens);
    return m_inputExpansionTokens;
}


	std::shared_ptr< Bag<fUML::TokenSet> >
 ExpansionRegionActivationImpl::getInputTokens() const
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
