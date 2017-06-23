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
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	
		m_heldTokens.reset(new Bag<fUML::Token>());
	
	
		m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>());
	
	
	
		m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>());
	
	
}

ActivityNodeActivationImpl::~ActivityNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ActivityNodeActivationImpl::ActivityNodeActivationImpl(const ActivityNodeActivationImpl & obj)
{
	//create copy of all Attributes
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_group  = obj.getGroup();

		std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
	 _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new 	 Bag<fUML::ActivityEdgeInstance> 
	(*(obj.getIncomingEdges().get())));// this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

		std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
	 _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new 	 Bag<fUML::ActivityEdgeInstance> 
	(*(obj.getOutgoingEdges().get())));// this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());


	//clone containt lists
	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
}

ecore::EObject *  ActivityNodeActivationImpl::copy() const
{
	return new ActivityNodeActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> ActivityNodeActivationImpl::eStaticClass() const
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
void
 ActivityNodeActivationImpl::addIncomingEdge(std::shared_ptr<fUML::ActivityEdgeInstance>  edge) 
{
	//generated from body annotation
	struct null_deleter{void operator()(void const *) const { } };
	edge->setTarget(std::shared_ptr<ActivityNodeActivation>(this, null_deleter()));
    this->getIncomingEdges()->push_back(edge);
}

void
 ActivityNodeActivationImpl::addOutgoingEdge(std::shared_ptr<fUML::ActivityEdgeInstance>  edge) 
{
	//generated from body annotation
	 if (edge->getSource().get() != this)
    {
		struct null_deleter{void operator()(void const *) const { } };
    	edge->setSource(std::shared_ptr<ActivityNodeActivation>(this, null_deleter()));
    }
    this->getOutgoingEdges()->push_back(edge);
}

void
 ActivityNodeActivationImpl::addToken(std::shared_ptr<fUML::Token>  token) 
{
	//generated from body annotation
	DEBUG_MESSAGE(
		if (this->getNode()== nullptr)
		{
			std::cout<<"[addToken] ..."<<std::endl;
		}
		else
		{
			std::cout<<"[addToken] node = " << this->getNode()->getName()<<std::endl;
		}
	)

	if (token->getHolder() != nullptr)
	{
		token->withdraw();
		token = std::shared_ptr<fUML::Token>(dynamic_cast<Token*>(token->copy()));
		DEBUG_MESSAGE(std::cout << "ActivityNodeActivationImpl::addToken - no copy created - maybe error";)
	}
	struct null_deleter{void operator()(void const *) const { } };
	token->setHolder(std::shared_ptr<ActivityNodeActivation>(this, null_deleter()));

	DEBUG_MESSAGE(std::cout<<"[addToken] Adding token with value = " <<token->getValue()<<std::endl;)
   
    this->getHeldTokens()->push_back(token);
}

void
 ActivityNodeActivationImpl::addTokens(std::shared_ptr<Bag<fUML::Token> >  tokens) 
{
	//generated from body annotation
	for(std::shared_ptr<Token> token: *tokens)
    {
        this->addToken(token);
    }
}

void
 ActivityNodeActivationImpl::clearTokens() 
{
	//generated from body annotation
	    while (this->getHeldTokens()->size() > 0) {
        this->getHeldTokens()->at(0)->withdraw();
    }
}

void
 ActivityNodeActivationImpl::createEdgeInstances() 
{
	//generated from body annotation
	return;
}

void
 ActivityNodeActivationImpl::createNodeActivations() 
{
	//generated from body annotation
	return;
}

void
 ActivityNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::ActivityExecution> 
 ActivityNodeActivationImpl::getActivityExecution() 
{
	//generated from body annotation
	return this->getGroup()->retrieveActivityExecution();
}

std::shared_ptr<fUML::Object> 
 ActivityNodeActivationImpl::getExecutionContext() 
{
	//generated from body annotation
	return this->getActivityExecution()->getContext();
}

std::shared_ptr<fUML::Locus> 
 ActivityNodeActivationImpl::getExecutionLocus() 
{
	//generated from body annotation
	return this->getActivityExecution()->getLocus();
}

std::shared_ptr<fUML::ActivityNodeActivation> 
 ActivityNodeActivationImpl::getNodeActivation(std::shared_ptr<uml::ActivityNode>  node) 
{
	//generated from body annotation
	std::shared_ptr<ActivityNodeActivation> activation = nullptr;
    if (node == this->getNode()) 
    {
        struct null_deleter{void operator()(void const *) const { } };
        activation = std::shared_ptr<ActivityNodeActivation>(this, null_deleter());
    }

    return activation;
}

bool
 ActivityNodeActivationImpl::getRunning() 
{
	//generated from body annotation
	return this->isRunning();
}

std::shared_ptr<Bag<fUML::Token> >
 ActivityNodeActivationImpl::getTokens() 
{
	//generated from body annotation
	std::shared_ptr<Bag<Token> > tokens(new Bag<Token>());
	std::shared_ptr<Bag<Token> > heldTokens = this->getHeldTokens();
    for (unsigned int i = 0; i < heldTokens->size(); i++) 
    {
    	std::shared_ptr<Token> heldToken = heldTokens->at(i);
        tokens->push_back(heldToken);
    }

    return tokens;
}

bool
 ActivityNodeActivationImpl::isReady() 
{
	//generated from body annotation
	return this->getRunning();
}

bool
 ActivityNodeActivationImpl::isSourceFor(std::shared_ptr<fUML::ActivityEdgeInstance>  edgeInstances) 
{
	//generated from body annotation
	return (edgeInstances->getSource().get() ==this);
}

void
 ActivityNodeActivationImpl::recieveOffer() 
{
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[receiveOffer] "
 << (this->getNode() == nullptr ? "..." : ("node = " + this->getNode()->getName()))<<std::endl;)

    _beginIsolation();

    bool ready = this->isReady();

    std::shared_ptr<Bag<Token> > tokens(new Bag<Token>());
    if (ready) 
    {
        DEBUG_MESSAGE(std::cout<<"[receiveOffer] Firing."<<std::endl;)
        tokens = this->takeOfferedTokens();
    }

    _endIsolation();

    if (ready) 
    {
        DEBUG_MESSAGE(std::cout<< "Firing "<<tokens->size()<<" token(s)"<<std::endl;)
        this->fire(tokens);
    }
    else
    {
        DEBUG_MESSAGE(std::cout<< "Node"<<(this->getNode() == nullptr ? "..." : "node = " + this->getNode()->getName())<<" is not ready to execute."<<std::endl;)
    }
}

int
 ActivityNodeActivationImpl::removeToken(std::shared_ptr<fUML::Token>  token) 
{
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Token> > heldTokenList = this->getHeldTokens();
	std::vector<std::shared_ptr<fUML::Token>>::iterator iter = heldTokenList->begin();
	std::vector<std::shared_ptr<fUML::Token>>::iterator end = heldTokenList->end();

	int i = 0;
	while (iter != end)
	{
		i++;
		if (*iter == token)
		{
			DEBUG_MESSAGE(
				if (this->getNode() == nullptr)
				{
					std::cout<<"[removeToken] ..."<<std::endl;
				} else
				{
					std::cout<<"[removeToken] node = " + this->getNode()->getName()<<std::endl;
				}
			)
			this->getHeldTokens()->erase(iter);
			return i;
		}

		iter++;
	}

	return 0;
}

void
 ActivityNodeActivationImpl::resume() 
{
	//generated from body annotation
	struct null_deleter{void operator()(void const *) const { } };
	this->getGroup()->resume(std::shared_ptr<ActivityNodeActivation>(this, null_deleter()));
}

void
 ActivityNodeActivationImpl::run() 
{
	//generated from body annotation
	    if (this->getNode() != nullptr) {
        DEBUG_MESSAGE(std::cout<<"[run] node = " << this->getNode()->getName()<<std::endl;)
    } else {
        DEBUG_MESSAGE(std::cout<<"[run] Anonymous activation of type "<<std::endl;)
    }

    this->setRunning(true);
}

void
 ActivityNodeActivationImpl::sendOffers(std::shared_ptr<Bag<fUML::Token> >  tokens) 
{
	//generated from body annotation
	if (tokens->size() > 0) 
	{
        // *** Send all outgoing offers concurrently. ***
		std::shared_ptr<Bag<ActivityEdgeInstance> > outgoingEdgeList = this->getOutgoingEdges();
        for(std::shared_ptr<ActivityEdgeInstance> outgoingEdge : *outgoingEdgeList)
        {
            DEBUG_MESSAGE(std::cout<<"[sendOffers] Sending offer to " << outgoingEdge->getTarget()->getNode()->getName() << "."<<std::endl;)
            outgoingEdge->sendOffer(tokens);
        }
    }
}

void
 ActivityNodeActivationImpl::suspend() 
{
	//generated from body annotation
	struct null_deleter{void operator()(void const *) const { } };
	this->getGroup()->suspend(std::shared_ptr<ActivityNodeActivation>(this, null_deleter()));
}

std::shared_ptr<Bag<fUML::Token> >
 ActivityNodeActivationImpl::takeOfferedTokens() 
{
	//generated from body annotation
	std::shared_ptr<Bag<Token> > allTokens(new Bag<Token>());
	std::shared_ptr<Bag<ActivityEdgeInstance> > incomingEdgeList = this->getIncomingEdges();
	for(std::shared_ptr<ActivityEdgeInstance> incomingEdge : *incomingEdgeList)
	{
		auto vec = incomingEdge->takeOfferedTokens();
		allTokens->insert(allTokens->end(), vec->begin(), vec->end());
	}
	return allTokens;
}

std::shared_ptr<Bag<fUML::Token> >
 ActivityNodeActivationImpl::takeTokens() 
{
	//generated from body annotation
	std::shared_ptr<Bag<Token> > tokens = this->getTokens();
    this->clearTokens();

    return tokens;
}

void
 ActivityNodeActivationImpl::terminate() 
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
std::shared_ptr<fUML::ActivityNodeActivationGroup > ActivityNodeActivationImpl::getGroup() const
{
//assert(m_group);
    return m_group;
}
void ActivityNodeActivationImpl::setGroup(std::shared_ptr<fUML::ActivityNodeActivationGroup> _group)
{
    m_group = _group;
}

	std::shared_ptr< Bag<fUML::Token> >
 ActivityNodeActivationImpl::getHeldTokens() const
{

    return m_heldTokens;
}


	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
 ActivityNodeActivationImpl::getIncomingEdges() const
{

    return m_incomingEdges;
}


std::shared_ptr<uml::ActivityNode > ActivityNodeActivationImpl::getNode() const
{

    return m_node;
}
void ActivityNodeActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
    m_node = _node;
}

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
 ActivityNodeActivationImpl::getOutgoingEdges() const
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
