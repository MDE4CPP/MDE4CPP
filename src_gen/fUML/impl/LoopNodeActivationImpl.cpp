#include "LoopNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "ActivityEdgeInstance.hpp"

#include "ActivityNode.hpp"

#include "ActivityNodeActivationGroup.hpp"

#include "PinActivation.hpp"

#include "StructuredActivityNodeActivation.hpp"

#include "Token.hpp"

#include "Values.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LoopNodeActivationImpl::LoopNodeActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_bodyOutputLists.reset(new Bag<fUML::Values>());
	
	

	//Init references
	
	
}

LoopNodeActivationImpl::~LoopNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LoopNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LoopNodeActivationImpl::LoopNodeActivationImpl(const LoopNodeActivationImpl & obj):LoopNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LoopNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr< Bag<fUML::PinActivation> > _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Bag<fUML::PinActivation>(*(obj.getPinActivation().get())));


    
	//Clone references with containment (deep copy)

	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup.reset(dynamic_cast<fUML::ActivityNodeActivationGroup*>(obj.getActivationGroup()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_activationGroup" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Values>> _bodyOutputListsList = obj.getBodyOutputLists();
	for(std::shared_ptr<fUML::Values> _bodyOutputLists : *_bodyOutputListsList)
	{
		this->getBodyOutputLists()->add(std::shared_ptr<fUML::Values>(dynamic_cast<fUML::Values*>(_bodyOutputLists->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_bodyOutputLists" << std::endl;
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

ecore::EObject *  LoopNodeActivationImpl::copy() const
{
	return new LoopNodeActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> LoopNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLoopNodeActivation();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::ActivityNode> LoopNodeActivationImpl::makeLoopVariableList() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void LoopNodeActivationImpl::runBody() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void LoopNodeActivationImpl::runLoopVariables() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeActivationImpl::runTest() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<fUML::Values> > LoopNodeActivationImpl::getBodyOutputLists() const
{

    return m_bodyOutputLists;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LoopNodeActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::STRUCTUREDACTIVITYNODEACTIVATION_ACTIVATIONGROUP:
			return getActivationGroup(); //728
		case FUMLPackage::LOOPNODEACTIVATION_BODYOUTPUTLISTS:
			return getBodyOutputLists(); //729
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //727
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //723
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //722
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //721
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //724
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //720
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //726
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //725
	}
	return boost::any();
}
