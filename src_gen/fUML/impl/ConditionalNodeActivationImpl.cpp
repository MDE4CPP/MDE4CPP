#include "ConditionalNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "ActivityEdgeInstance.hpp";

#include "ActivityNode.hpp";

#include "ActivityNodeActivationGroup.hpp";

#include "Clause.hpp";

#include "ClauseActivation.hpp";

#include "PinActivation.hpp";

#include "StructuredActivityNodeActivation.hpp";

#include "Token.hpp";


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
	//References
		m_clauseActivations.reset(new Bag<fUML::ClauseActivation>());
	
	

		m_selectedClauses.reset(new Bag<uml::Clause>());
	
	

	//Init references
	
	

	
	
}

ConditionalNodeActivationImpl::~ConditionalNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConditionalNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ConditionalNodeActivationImpl::ConditionalNodeActivationImpl(const ConditionalNodeActivationImpl & obj):ConditionalNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConditionalNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

		std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
	 _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new 	 Bag<fUML::ActivityEdgeInstance> 
	(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

		std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
	 _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new 	 Bag<fUML::ActivityEdgeInstance> 
	(*(obj.getOutgoingEdges().get())));

		std::shared_ptr< Bag<fUML::PinActivation> >
	 _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new 	 Bag<fUML::PinActivation> 
	(*(obj.getPinActivation().get())));

		std::shared_ptr< Bag<uml::Clause> >
	 _selectedClauses = obj.getSelectedClauses();
	m_selectedClauses.reset(new 	 Bag<uml::Clause> 
	(*(obj.getSelectedClauses().get())));


    
	//Clone references with containment (deep copy)

	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup.reset(dynamic_cast<fUML::ActivityNodeActivationGroup*>(obj.getActivationGroup()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_activationGroup" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ClauseActivation>> _clauseActivationsList = obj.getClauseActivations();
	for(std::shared_ptr<fUML::ClauseActivation> _clauseActivations : *_clauseActivationsList)
	{
		this->getClauseActivations()->add(std::shared_ptr<fUML::ClauseActivation>(dynamic_cast<fUML::ClauseActivation*>(_clauseActivations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_clauseActivations" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif

	
	

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
std::shared_ptr<fUML::ClauseActivation> 
 ConditionalNodeActivationImpl::getClauseActivation(std::shared_ptr<uml::Clause>  clause) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void
 ConditionalNodeActivationImpl::runTest(std::shared_ptr<uml::Clause>  clause) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void
 ConditionalNodeActivationImpl::selectBody(std::shared_ptr<uml::Clause>  clause) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<fUML::ClauseActivation> >
 ConditionalNodeActivationImpl::getClauseActivations() const
{

    return m_clauseActivations;
}


	std::shared_ptr< Bag<uml::Clause> >
 ConditionalNodeActivationImpl::getSelectedClauses() const
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
