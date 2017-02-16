#include "ActivityNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "ActivityNode.hpp"

#include "Class.hpp"
#include "ActivityNodeActivation.hpp"

#include "EClass.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ActivityNodeActivationImpl::ActivityNodeActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_heldTokens == nullptr)
	{
		m_heldTokens = new std::vector<fUML::Token * >();
	}
	if( m_incomingEdges == nullptr)
	{
		m_incomingEdges = new std::vector<fUML::ActivityEdgeInstance * >();
	}
	
	if( m_outgoingEdges == nullptr)
	{
		m_outgoingEdges = new std::vector<fUML::ActivityEdgeInstance * >();
	}
}

ActivityNodeActivationImpl::~ActivityNodeActivationImpl()
{
	if(m_outgoingEdges!=nullptr)
	{
		delete(m_outgoingEdges);
	 	m_outgoingEdges = nullptr;
	}
	if(m_incomingEdges!=nullptr)
	{
		delete(m_incomingEdges);
	 	m_incomingEdges = nullptr;
	}
	if(m_heldTokens!=nullptr)
	{
		for(auto c :*m_heldTokens)
		{
			delete(c);
			c = 0;
		}
	}
	
}

ActivityNodeActivationImpl::ActivityNodeActivationImpl(const ActivityNodeActivationImpl & obj)
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

ecore::EObject *  ActivityNodeActivationImpl::copy() const
{
	return new ActivityNodeActivationImpl(*this);
}

ecore::EClass* ActivityNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityNodeActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ActivityNodeActivationImpl::setRunning (bool _running)
{
	m_running = _running;
} 

bool ActivityNodeActivationImpl::isRunning() const 
{
	return m_running;
}

//*********************************
// Operations
//*********************************
void ActivityNodeActivationImpl::addIncomingEdge(fUML::ActivityEdgeInstance *  edge) 
{
	//generated from body annotation
	    edge->setTarget(this);
    this->getIncomingEdges()->push_back(edge);
}

void ActivityNodeActivationImpl::addOutgoingEdge(fUML::ActivityEdgeInstance *  edge) 
{
	//generated from body annotation
	    edge->setSource(this);
    this->getOutgoingEdges()->push_back(edge);
}

void ActivityNodeActivationImpl::addToken(fUML::Token *  token) 
{
	//generated from body annotation
	    if (this->getNode()== nullptr) {
        DEBUG_MESSAGE(std::cout<<"[addToken] ..."<<std::endl;)
    } else {
        DEBUG_MESSAGE(std::cout<<"[addToken] node = " << this->getNode()->getName()<<std::endl;)
    }

    Token * transferredToken = token->transfer(this);
    DEBUG_MESSAGE(std::cout<<"[addToken] Adding token with value = " <<transferredToken->getValue()<<std::endl;)
    this->getHeldTokens()->push_back(transferredToken);
}

void ActivityNodeActivationImpl::addTokens(std::vector<fUML::Token * > *  tokens) 
{
	//generated from body annotation
	 for(Token * token: *tokens)
    {
        this->addToken(token);
    }
}

void ActivityNodeActivationImpl::clearTokens() 
{
	//generated from body annotation
	    while (this->getHeldTokens()->size() > 0) {
        this->getHeldTokens()->at(0)->withdraw();
    }
}

void ActivityNodeActivationImpl::createEdgeInstances() 
{
	//generated from body annotation
	return;
}

void ActivityNodeActivationImpl::createNodeActivations() 
{
	//generated from body annotation
	return;
}

void ActivityNodeActivationImpl::fire(std::vector<fUML::Token * > *  incomingTokens) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

fUML::ActivityExecution *  ActivityNodeActivationImpl::getActivityExecution() 
{
	//generated from body annotation
	return this->getGroup()->retrieveActivityExecution();
}

fUML::Object *  ActivityNodeActivationImpl::getExecutionContext() 
{
	//generated from body annotation
	return this->getActivityExecution()->getContext();
}

fUML::Locus *  ActivityNodeActivationImpl::getExecutionLocus() 
{
	//generated from body annotation
	return this->getActivityExecution()->getLocus();
}

fUML::ActivityNodeActivation *  ActivityNodeActivationImpl::getNodeActivation(uml::ActivityNode *  node) 
{
	//generated from body annotation
	    ActivityNodeActivation * activation = nullptr;
    if (node == this->getNode()) {
        activation = this;
    }

    return activation;
}

bool ActivityNodeActivationImpl::getRunning() 
{
	//generated from body annotation
	return this->isRunning();
}

std::vector<fUML::Token * > *  ActivityNodeActivationImpl::getTokens() 
{
	//generated from body annotation
	    std::vector< Token* > * tokens = new std::vector< Token* >();
    std::vector< Token* > * heldTokens = this->getHeldTokens();
    for (unsigned int i = 0; i < heldTokens->size(); i++) {
        Token * heldToken = heldTokens->at(i);
        tokens->push_back(heldToken);
    }

    return tokens;
}

bool ActivityNodeActivationImpl::isReady() 
{
	//generated from body annotation
	return this->getRunning();
}

bool ActivityNodeActivationImpl::isSourceFor(fUML::ActivityEdgeInstance *  edgeInstances) 
{
	//generated from body annotation
	    return (edgeInstances->getSource() ==this);
}

void ActivityNodeActivationImpl::recieveOffer() 
{
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[receiveOffer] "
 << (this->getNode() == nullptr ? "..." : ("node = " + this->getNode()->getName()))<<std::endl;)

    _beginIsolation();

    bool ready = this->isReady();

    std::vector< Token *>*tokens = new std::vector< Token *>();
    if (ready) {
        DEBUG_MESSAGE(std::cout<<"[receiveOffer] Firing."<<std::endl;)
        tokens = this->takeOfferedTokens();
    }

    _endIsolation();

    if (ready) {
        DEBUG_MESSAGE(std::cout<< "Firing "<<tokens->size()<<" token(s)"<<std::endl;)
        this->fire(tokens);
    }
    else
    {
        DEBUG_MESSAGE(std::cout<< "Node"<<(this->getNode() == nullptr ? "..." : "node = " + this->getNode()->getName())<<" is not ready to execute."<<std::endl;)
    }
}

int ActivityNodeActivationImpl::removeToken(fUML::Token *  token) 
{
	//generated from body annotation
	    bool notFound = true;

    unsigned int i = 0;
    while (notFound && i < this->getHeldTokens()->size())
    {
        if (this->getHeldTokens()->at(i) == token)
        {
            if (this->getNode() == nullptr) {
            DEBUG_MESSAGE(std::cout<<"[removeToken] ..."<<std::endl;)
            } else {
            DEBUG_MESSAGE(std::cout<<"[removeToken] node = " + this->getNode()->getName()<<std::endl;)
            }
            this->getHeldTokens()->erase(this->getHeldTokens()->begin()+i);
            notFound = false;
        }
        i++;
    }

    if (notFound) {
    i = 0;
    }

    return i;
}

void ActivityNodeActivationImpl::resume() 
{
	//generated from body annotation
	this->getGroup()->resume(this);
}

void ActivityNodeActivationImpl::run() 
{
	//generated from body annotation
	    if (this->getNode() != nullptr) {
        DEBUG_MESSAGE(std::cout<<"[run] node = " << this->getNode()->getName()<<std::endl;)
    } else {
        DEBUG_MESSAGE(std::cout<<"[run] Anonymous activation of type "<<std::endl;)
    }

    this->setRunning(true);
}

void ActivityNodeActivationImpl::sendOffers(std::vector<fUML::Token * > *  tokens) 
{
	//generated from body annotation
	    if (tokens->size() > 0) {

        // *** Send all outgoing offers concurrently. ***
        for(ActivityEdgeInstance* outgoingEdge : * this->getOutgoingEdges())
        {
            DEBUG_MESSAGE(std::cout<<"[sendOffers] Sending offer to " << outgoingEdge->getTarget()->getNode()->getName() << "."<<std::endl;)
            outgoingEdge->sendOffer(tokens);
        }
    }
}

void ActivityNodeActivationImpl::suspend() 
{
	//generated from body annotation
	this->getGroup()->suspend(this);
}

std::vector<fUML::Token * > *  ActivityNodeActivationImpl::takeOfferedTokens() 
{
	//generated from body annotation
	std::vector< Token *>* allTokens = new std::vector< Token *>();

for(ActivityEdgeInstance * incomingEdge : *this->getIncomingEdges())
{
auto vec = incomingEdge->takeOfferedTokens();
       allTokens->insert(allTokens->end(), vec->begin(), vec->end());
}
return allTokens;
}

std::vector<fUML::Token * > *  ActivityNodeActivationImpl::takeTokens() 
{
	//generated from body annotation
	    std::vector< Token*>* tokens = this->getTokens();
    this->clearTokens();

    return tokens;
}

void ActivityNodeActivationImpl::terminate() 
{
	//generated from body annotation
	    if (this->isRunning()) {
        if (this->getNode() != nullptr) {
            DEBUG_MESSAGE(std::cout<<"[terminate] node = " << this->getNode()->getName()<<std::endl;)
        } else {
            DEBUG_MESSAGE(std::cout<<"[terminate] Anonymous activation of type " << this->eClass()->getName()<<std::endl;)
        }
    }

    this->setRunning(false);
}

//*********************************
// References
//*********************************
fUML::ActivityNodeActivationGroup *  ActivityNodeActivationImpl::getGroup() const
{
	//assert(m_group);
	return m_group;
}
void ActivityNodeActivationImpl::setGroup(fUML::ActivityNodeActivationGroup *  _group)
{
	m_group = _group;
}

std::vector<fUML::Token * > *  ActivityNodeActivationImpl::getHeldTokens() const
{
	
	return m_heldTokens;
}


std::vector<fUML::ActivityEdgeInstance * > *  ActivityNodeActivationImpl::getIncomingEdges() const
{
	
	return m_incomingEdges;
}


uml::ActivityNode *  ActivityNodeActivationImpl::getNode() const
{
	
	return m_node;
}
void ActivityNodeActivationImpl::setNode(uml::ActivityNode *  _node)
{
	m_node = _node;
}

std::vector<fUML::ActivityEdgeInstance * > *  ActivityNodeActivationImpl::getOutgoingEdges() const
{
	
	return m_outgoingEdges;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActivityNodeActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //583
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //582
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //581
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //584
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //580
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //585
	}
	return boost::any();
}
