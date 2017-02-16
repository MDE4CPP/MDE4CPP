#include "ActivityParameterNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "ActivityNode.hpp"
#include "ActivityParameterNode.hpp"
#include "FUMLFactory.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ActivityParameterNodeActivationImpl::ActivityParameterNodeActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

ActivityParameterNodeActivationImpl::~ActivityParameterNodeActivationImpl()
{
	
}

ActivityParameterNodeActivationImpl::ActivityParameterNodeActivationImpl(const ActivityParameterNodeActivationImpl & obj)
{
	//create copy of all Attributes
	m_offeredTokenCount = obj.getOfferedTokenCount();
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

ecore::EObject *  ActivityParameterNodeActivationImpl::copy() const
{
	return new ActivityParameterNodeActivationImpl(*this);
}

ecore::EClass* ActivityParameterNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityParameterNodeActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void ActivityParameterNodeActivationImpl::clearTokens() 
{
	//generated from body annotation
	    if (this->getNode()->getIncoming()->size() == 0) {
        ObjectNodeActivationImpl::clearTokens();
    }
}

void ActivityParameterNodeActivationImpl::fire(std::vector<fUML::Token * > *  incomingTokens) 
{
	//generated from body annotation
	if (this->getNode()->getIncoming()->size() == 0) {
		DEBUG_MESSAGE(std::cout<< "[fire] Input activity parameter node "
				<< this->getNode()->getName() << "..."<<std::endl;)
		uml::Parameter * parameter =
				(dynamic_cast<uml::ActivityParameterNode*>(this->getNode()))->getParameter();
		ParameterValue * parameterValue =
				this->getActivityExecution()->getParameterValue(parameter);

		if (parameterValue != nullptr) {
			DEBUG_MESSAGE(std::cout<< "[fire] Parameter has "
					<< parameterValue->getValues()->size() << " value(s)."<<std::endl;)
			for (Value * value : *parameterValue->getValues()) {
				ObjectToken * token =
						fUML::FUMLFactory::eInstance()->createObjectToken();
				token->setValue(value);
				this->addToken(token);
			}
			this->sendUnofferedTokens();
		}
	}

	else {
		DEBUG_MESSAGE(std::cout<< "[fire] Output activity parameter node "
				<< this->getNode()->getName() + "..."<<std::endl;)
		this->addTokens(incomingTokens);
		fUML::ForkedToken* forkToken =
				dynamic_cast<fUML::ForkedToken*>(incomingTokens->at(0));
		if (forkToken != nullptr) {
			forkToken->getBaseToken()->setHolder(this);
		}

	}
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
boost::any ActivityParameterNodeActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //603
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //602
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //601
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //604
		case FUMLPackage::OBJECTNODEACTIVATION_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount(); //606
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //600
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //605
	}
	return boost::any();
}
