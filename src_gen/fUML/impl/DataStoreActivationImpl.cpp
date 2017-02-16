#include "DataStoreActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
DataStoreActivationImpl::DataStoreActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_storedTokens == nullptr)
	{
		m_storedTokens = new std::vector<fUML::Token * >();
	}
}

DataStoreActivationImpl::~DataStoreActivationImpl()
{
	if(m_storedTokens!=nullptr)
	{
		delete(m_storedTokens);
	 	m_storedTokens = nullptr;
	}
	
}

DataStoreActivationImpl::DataStoreActivationImpl(const DataStoreActivationImpl & obj)
{
	//create copy of all Attributes
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_currentExecution  = obj.getCurrentExecution();

	m_group  = obj.getGroup();

	std::vector<fUML::ActivityEdgeInstance * > *  _incomingEdges = obj.getIncomingEdges();
	this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

	std::vector<fUML::ActivityEdgeInstance * > *  _outgoingEdges = obj.getOutgoingEdges();
	this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());

	std::vector<fUML::PinActivation * > *  _pinActivation = obj.getPinActivation();
	this->getPinActivation()->insert(this->getPinActivation()->end(), _pinActivation->begin(), _pinActivation->end());

	std::vector<fUML::Token * > *  _storedTokens = obj.getStoredTokens();
	this->getStoredTokens()->insert(this->getStoredTokens()->end(), _storedTokens->begin(), _storedTokens->end());


	//clone containt lists
	for(fUML::Token * 	_heldTokens : *obj.getHeldTokens())
	{
		this->getHeldTokens()->push_back(dynamic_cast<fUML::Token * >(_heldTokens->copy()));
	}
}

ecore::EObject *  DataStoreActivationImpl::copy() const
{
	return new DataStoreActivationImpl(*this);
}

ecore::EClass* DataStoreActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDataStoreActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void DataStoreActivationImpl::fire(std::vector<fUML::Token * > *  incomingTokens) 
{
	//generated from body annotation
	    m_storedTokens = incomingTokens;
    do {

        DEBUG_MESSAGE(std::cout<< "[fire] Action " << this->getNode()->getName() << "..."<<std::endl;)
        DEBUG_MESSAGE(std::cout<<"[event] Fire activity=" << this->getActivityExecution()->getBehavior()->getName()
                   << " action=" << this->getNode()->getName()<<std::endl;)

        this->doAction();
        this->sendOffers();
        incomingTokens = this->completeAction();

    } while (incomingTokens->size() > 0);
}

void DataStoreActivationImpl::sendOffers() 
{
	//generated from body annotation
	    if (!this->getOutgoingEdges()->empty()) {

        std::vector<Token *>* offeredTokens = new std::vector<Token *>();

        for(ActivityEdgeInstance * incomingEdge : *this->getIncomingEdges() )
        {
            for(Token * token: *incomingEdge->takeOfferedTokens())
            {
                //token->withdraw();
                offeredTokens->push_back(token);
            }
        }

        this->addTokens(offeredTokens);
        this->getOutgoingEdges()->front()->sendOffer(offeredTokens);
    }

    fUML::ActivityExecution* act = dynamic_cast<fUML::ActivityExecution*> (this->getExecutionContext());
    act->getActivationGroup()->addNodeActivation(this);
}

//*********************************
// References
//*********************************
fUML::Execution *  DataStoreActivationImpl::getCurrentExecution() const
{
	//assert(m_currentExecution);
	return m_currentExecution;
}
void DataStoreActivationImpl::setCurrentExecution(fUML::Execution *  _currentExecution)
{
	m_currentExecution = _currentExecution;
}

std::vector<fUML::Token * > *  DataStoreActivationImpl::getStoredTokens() const
{
	
	return m_storedTokens;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DataStoreActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::DATASTOREACTIVATION_CURRENTEXECUTION:
			return getCurrentExecution(); //1138
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //1137
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //1133
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //1132
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //1131
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //1134
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //1130
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //1136
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //1135
		case FUMLPackage::DATASTOREACTIVATION_STOREDTOKENS:
			return getStoredTokens(); //1139
	}
	return boost::any();
}
