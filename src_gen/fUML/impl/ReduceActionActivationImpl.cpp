#include "ReduceActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"

//Forward declaration includes
#include "ActionActivation.hpp"

#include "ActivityEdgeInstance.hpp"

#include "ActivityNode.hpp"

#include "ActivityNodeActivationGroup.hpp"

#include "Execution.hpp"

#include "PinActivation.hpp"

#include "Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ReduceActionActivationImpl::ReduceActionActivationImpl()
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

ReduceActionActivationImpl::~ReduceActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReduceActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




ReduceActionActivationImpl::ReduceActionActivationImpl(const ReduceActionActivationImpl & obj):ReduceActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReduceActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_currentExecution  = obj.getCurrentExecution();

	m_group  = obj.getGroup();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr< Bag<fUML::PinActivation> > _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Bag<fUML::PinActivation>(*(obj.getPinActivation().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ReduceActionActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ReduceActionActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ReduceActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getReduceActionActivation();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Execution > ReduceActionActivationImpl::getCurrentExecution() const
{

    return m_currentExecution;
}
void ReduceActionActivationImpl::setCurrentExecution(std::shared_ptr<fUML::Execution> _currentExecution)
{
    m_currentExecution = _currentExecution;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ReduceActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::REDUCEACTIONACTIVATION_CURRENTEXECUTION:
			return getCurrentExecution(); //1058
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //1057
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //1053
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //1052
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //1051
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //1054
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //1050
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //1056
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //1055
	}
	return boost::any();
}
