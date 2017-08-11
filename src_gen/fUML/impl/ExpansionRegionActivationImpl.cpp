#include "ExpansionRegionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "ActionActivation.hpp"

#include "ActivityEdgeInstance.hpp"

#include "ActivityNode.hpp"

#include "ActivityNodeActivationGroup.hpp"

#include "ExpansionActivationGroup.hpp"

#include "ExpansionNode.hpp"

#include "ExpansionNodeActivation.hpp"

#include "PinActivation.hpp"

#include "Token.hpp"

#include "TokenSet.hpp"


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
	//References
		m_activationGroups.reset(new Bag<fUML::ExpansionActivationGroup>());
	
	

		m_inputExpansionTokens.reset(new Bag<fUML::TokenSet>());
	
	

		m_inputTokens.reset(new Bag<fUML::TokenSet>());
	
	

	//Init references
	
	

	
	

	
	
}

ExpansionRegionActivationImpl::~ExpansionRegionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionRegionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ExpansionRegionActivationImpl::ExpansionRegionActivationImpl(const ExpansionRegionActivationImpl & obj):ExpansionRegionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpansionRegionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<fUML::ExpansionActivationGroup> > _activationGroups = obj.getActivationGroups();
	m_activationGroups.reset(new Bag<fUML::ExpansionActivationGroup>(*(obj.getActivationGroups().get())));

	m_group  = obj.getGroup();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	std::shared_ptr< Bag<fUML::TokenSet> > _inputExpansionTokens = obj.getInputExpansionTokens();
	m_inputExpansionTokens.reset(new Bag<fUML::TokenSet>(*(obj.getInputExpansionTokens().get())));

	std::shared_ptr< Bag<fUML::TokenSet> > _inputTokens = obj.getInputTokens();
	m_inputTokens.reset(new Bag<fUML::TokenSet>(*(obj.getInputTokens().get())));

	m_node  = obj.getNode();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr< Bag<fUML::PinActivation> > _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Bag<fUML::PinActivation>(*(obj.getPinActivation().get())));


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif


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
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ExpansionRegionActivationImpl::doStructuredActivity() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::ExpansionNodeActivation> ExpansionRegionActivationImpl::getExpansionNodeActivation(std::shared_ptr<uml::ExpansionNode>  node) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int ExpansionRegionActivationImpl::numberOfValues() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ExpansionRegionActivationImpl::runGroup(std::shared_ptr<fUML::ExpansionActivationGroup>  activationGroup) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<fUML::ExpansionActivationGroup> > ExpansionRegionActivationImpl::getActivationGroups() const
{

    return m_activationGroups;
}


std::shared_ptr< Bag<fUML::TokenSet> > ExpansionRegionActivationImpl::getInputExpansionTokens() const
{
//assert(m_inputExpansionTokens);
    return m_inputExpansionTokens;
}


std::shared_ptr< Bag<fUML::TokenSet> > ExpansionRegionActivationImpl::getInputTokens() const
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
