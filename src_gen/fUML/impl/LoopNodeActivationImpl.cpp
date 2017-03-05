#include "LoopNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

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
	m_bodyOutputLists.reset(new std::vector<std::shared_ptr<fUML::Values>>());
}

LoopNodeActivationImpl::~LoopNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LoopNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LoopNodeActivationImpl::LoopNodeActivationImpl(const LoopNodeActivationImpl & obj)
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


	//clone containt lists
	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup.reset(dynamic_cast<fUML::ActivityNodeActivationGroup*>(obj.getActivationGroup()->copy()));
	}
	std::shared_ptr<std::vector<std::shared_ptr<fUML::Values>>> _bodyOutputListsList = obj.getBodyOutputLists();
	for(std::shared_ptr<fUML::Values> _bodyOutputLists : *_bodyOutputListsList)
	{
		this->getBodyOutputLists()->push_back(std::shared_ptr<fUML::Values>(dynamic_cast<fUML::Values*>(_bodyOutputLists->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->push_back(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
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
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::ActivityNode>  LoopNodeActivationImpl::makeLoopVariableList() 
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
std::shared_ptr<std::vector<std::shared_ptr<fUML::Values>>> LoopNodeActivationImpl::getBodyOutputLists() const
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
