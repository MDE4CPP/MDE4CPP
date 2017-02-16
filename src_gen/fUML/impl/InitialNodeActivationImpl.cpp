#include "InitialNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
InitialNodeActivationImpl::InitialNodeActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

InitialNodeActivationImpl::~InitialNodeActivationImpl()
{
	
}

InitialNodeActivationImpl::InitialNodeActivationImpl(const InitialNodeActivationImpl & obj)
{
	//create copy of all Attributes
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_group  = obj.getGroup();

	std::vector<fUML::ActivityEdgeInstance * > *  _incomingEdges = obj.getIncomingEdges();
	this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

	std::vector<fUML::ActivityEdgeInstance * > *  _outgoingEdges = obj.getOutgoingEdges();
	this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());


	//clone containt lists
	for(fUML::Token * 	_heldTokens : *obj.getHeldTokens())
	{
		this->getHeldTokens()->push_back(dynamic_cast<fUML::Token * >(_heldTokens->copy()));
	}
}

ecore::EObject *  InitialNodeActivationImpl::copy() const
{
	return new InitialNodeActivationImpl(*this);
}

ecore::EClass* InitialNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getInitialNodeActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void InitialNodeActivationImpl::fire(std::vector<fUML::Token * > *  incomingTokens) 
{
	//generated from body annotation
	    std::vector<Token*>* tokens = new std::vector<Token*>();
    ControlToken* controlToken = fUML::FUMLFactory::eInstance()->createControlToken();
    tokens->push_back(controlToken);
    this->addTokens(tokens);

    this->sendOffers(tokens);
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InitialNodeActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //653
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //652
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //651
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //654
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //650
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //655
	}
	return boost::any();
}
