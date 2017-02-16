#include "JoinNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
JoinNodeActivationImpl::JoinNodeActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

JoinNodeActivationImpl::~JoinNodeActivationImpl()
{
	
}

JoinNodeActivationImpl::JoinNodeActivationImpl(const JoinNodeActivationImpl & obj)
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

ecore::EObject *  JoinNodeActivationImpl::copy() const
{
	return new JoinNodeActivationImpl(*this);
}

ecore::EClass* JoinNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getJoinNodeActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool JoinNodeActivationImpl::isReady() 
{
	//generated from body annotation
	    bool ready = true;
    unsigned int i = 1;
    while (ready && i <= this->getIncomingEdges()->size()) {
        ready = this->getIncomingEdges()->at(i - 1)->hasOffer();
        i = i + 1;
    }

    return ready;
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
boost::any JoinNodeActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //633
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //632
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //631
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //634
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //630
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //635
	}
	return boost::any();
}
