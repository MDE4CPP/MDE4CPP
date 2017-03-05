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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	m_storedTokens.reset(new std::vector<std::shared_ptr<fUML::Token>>());
}

DataStoreActivationImpl::~DataStoreActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DataStoreActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

DataStoreActivationImpl::DataStoreActivationImpl(const DataStoreActivationImpl & obj)
{
	//create copy of all Attributes
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_currentExecution  = obj.getCurrentExecution();

	m_group  = obj.getGroup();

	std::shared_ptr<std::vector<std::shared_ptr<fUML::ActivityEdgeInstance>>> _incomingEdges = obj.getIncomingEdges();
	this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

	std::shared_ptr<std::vector<std::shared_ptr<fUML::ActivityEdgeInstance>>> _outgoingEdges = obj.getOutgoingEdges();
	this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());

	std::shared_ptr<std::vector<std::shared_ptr<fUML::PinActivation>>> _pinActivation = obj.getPinActivation();
	this->getPinActivation()->insert(this->getPinActivation()->end(), _pinActivation->begin(), _pinActivation->end());

	std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> _storedTokens = obj.getStoredTokens();
	this->getStoredTokens()->insert(this->getStoredTokens()->end(), _storedTokens->begin(), _storedTokens->end());


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->push_back(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
}

ecore::EObject *  DataStoreActivationImpl::copy() const
{
	return new DataStoreActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> DataStoreActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDataStoreActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void DataStoreActivationImpl::fire(std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>>  incomingTokens) 
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
	if (!this->getOutgoingEdges()->empty())
	{
		std::shared_ptr<std::vector<std::shared_ptr<Token>>> offeredTokens(new std::vector<std::shared_ptr<Token>>());

    	std::shared_ptr<std::vector<std::shared_ptr<ActivityEdgeInstance>>> incomingEdgeList = this->getIncomingEdges();
        for(std::shared_ptr<ActivityEdgeInstance> incomingEdge : *incomingEdgeList)
        {
        	std::shared_ptr<std::vector<std::shared_ptr<Token>>> tokenList = incomingEdge->takeOfferedTokens();
            for(std::shared_ptr<Token> token: *tokenList)
            {
                //token->withdraw();
                offeredTokens->push_back(token);
            }
        }

        this->addTokens(offeredTokens);
        this->getOutgoingEdges()->front()->sendOffer(offeredTokens);
    }

	std::shared_ptr<fUML::ActivityExecution> act = std::dynamic_pointer_cast<fUML::ActivityExecution>(this->getExecutionContext());
	struct null_deleter{void operator()(void const *) const { } };
    act->getActivationGroup()->addNodeActivation(std::shared_ptr<DataStoreActivation>(this, null_deleter()));
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Execution> DataStoreActivationImpl::getCurrentExecution() const
{
//assert(m_currentExecution);
    return m_currentExecution;
}
void DataStoreActivationImpl::setCurrentExecution(std::shared_ptr<fUML::Execution> _currentExecution)
{
    m_currentExecution = _currentExecution;
}

std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> DataStoreActivationImpl::getStoredTokens() const
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
