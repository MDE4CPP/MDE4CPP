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
	// Reference Members
	//*********************************
	if( m_bodyOutputLists == nullptr)
	{
		m_bodyOutputLists = new std::vector<fUML::Values * >();
	}
}

LoopNodeActivationImpl::~LoopNodeActivationImpl()
{
	if(m_bodyOutputLists!=nullptr)
	{
		for(auto c :*m_bodyOutputLists)
		{
			delete(c);
			c = 0;
		}
	}
	
}

LoopNodeActivationImpl::LoopNodeActivationImpl(const LoopNodeActivationImpl & obj)
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


	//clone containt lists
	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup = dynamic_cast<fUML::ActivityNodeActivationGroup * >(obj.getActivationGroup()->copy());
	}
	for(fUML::Values * 	_bodyOutputLists : *obj.getBodyOutputLists())
	{
		this->getBodyOutputLists()->push_back(dynamic_cast<fUML::Values * >(_bodyOutputLists->copy()));
	}
	for(fUML::Token * 	_heldTokens : *obj.getHeldTokens())
	{
		this->getHeldTokens()->push_back(dynamic_cast<fUML::Token * >(_heldTokens->copy()));
	}
}

ecore::EObject *  LoopNodeActivationImpl::copy() const
{
	return new LoopNodeActivationImpl(*this);
}

ecore::EClass* LoopNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLoopNodeActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
uml::ActivityNode *  LoopNodeActivationImpl::makeLoopVariableList() 
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
std::vector<fUML::Values * > *  LoopNodeActivationImpl::getBodyOutputLists() const
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
