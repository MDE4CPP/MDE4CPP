#include "ActivityNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
#include "ActivityNode.hpp"

#include "Class.hpp"
#include "ActivityNodeActivation.hpp"

#include "EClass.hpp"

//Forward declaration includes
#include "ActivityEdgeInstance.hpp"

#include "ActivityExecution.hpp"

#include "ActivityNode.hpp"

#include "ActivityNodeActivation.hpp"

#include "ActivityNodeActivationGroup.hpp"

#include "Locus.hpp"

#include "Object.hpp"

#include "SemanticVisitor.hpp"

#include "Token.hpp"


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
	//References
	

		m_heldTokens.reset(new Bag<fUML::Token>());
	
	

		m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>());
	
	

	

		m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>());
	
	

	//Init references
	

	
	

	
	

	

	
	
}

ActivityNodeActivationImpl::~ActivityNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




ActivityNodeActivationImpl::ActivityNodeActivationImpl(const ActivityNodeActivationImpl & obj):ActivityNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));


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

std::shared_ptr<ecore::EObject>  ActivityNodeActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ActivityNodeActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ActivityNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityNodeActivation();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ActivityNodeActivationImpl::setRunning(bool _running)
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
void ActivityNodeActivationImpl::addIncomingEdge(std::shared_ptr<fUML::ActivityEdgeInstance>  edge) 
{
	//generated from body annotation
	struct null_deleter{void operator()(void const *) const { } };
	edge->setTarget(std::shared_ptr<ActivityNodeActivation>(this, null_deleter()));
    this->getIncomingEdges()->push_back(edge);
	//end of body
}

void ActivityNodeActivationImpl::addOutgoingEdge(std::shared_ptr<fUML::ActivityEdgeInstance>  edge) 
{
	//generated from body annotation
	 if (edge->getSource().get() != this)
    {
		struct null_deleter{void operator()(void const *) const { } };
    	edge->setSource(std::shared_ptr<ActivityNodeActivation>(this, null_deleter()));
    }
    this->getOutgoingEdges()->push_back(edge);
	//end of body
}

void ActivityNodeActivationImpl::addToken(std::shared_ptr<fUML::Token>  token) 
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
            
            std::shared_ptr<uml::NamedElement> owner = std::dynamic_pointer_cast<uml::NamedElement>(this->getNode()->getOwner().lock());
			if(nullptr != owner) {
				ACT_DEBUG(std::cout << "SET_TOKEN;NODE:" << (owner != nullptr ? owner->getName() : "[NO_OWNER]") << "::"
									<< this->getNode()->getName() << ";TOKEN:" << token->getValue()
									<< ";CURRENT_TOKENS:" << (this->getHeldTokens()->size() + 1) << ";DIRECTION:add"
									<< std::endl;)
			}
		}
	)

	if (token->getHolder().lock() != nullptr)
	{
		token->withdraw();
		token = std::dynamic_pointer_cast<Token>(token->copy());
	}
	//struct null_deleter{void operator()(void const *) const { } };
	token->setHolder(shared_from_this());

	DEBUG_MESSAGE(std::cout<<"[addToken] Adding token with value = " <<token->getValue()<<std::endl;)
   
    this->getHeldTokens()->push_back(token);
	//end of body
}

void ActivityNodeActivationImpl::addTokens(std::shared_ptr<Bag<fUML::Token> >  tokens) 
{
	//generated from body annotation
	for(std::shared_ptr<Token> token: *tokens)
    {
        this->addToken(token);
    }
	//end of body
}

void ActivityNodeActivationImpl::clearTokens() 
{
	//generated from body annotation
	    while (this->getHeldTokens()->size() > 0) {
        this->getHeldTokens()->at(0)->withdraw();
    }
	//end of body
}

void ActivityNodeActivationImpl::createEdgeInstances() 
{
	//generated from body annotation
	return;
	//end of body
}

void ActivityNodeActivationImpl::createNodeActivations() 
{
	//generated from body annotation
	return;
	//end of body
}

void ActivityNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::ActivityExecution> ActivityNodeActivationImpl::getActivityExecution() 
{
	//generated from body annotation
	return this->getGroup()->retrieveActivityExecution();
	//end of body
}

std::shared_ptr<fUML::Object> ActivityNodeActivationImpl::getExecutionContext() 
{
	//generated from body annotation
	return this->getActivityExecution()->getContext();
	//end of body
}

std::shared_ptr<fUML::Locus> ActivityNodeActivationImpl::getExecutionLocus() 
{
	//generated from body annotation
	return this->getActivityExecution()->getLocus();
	//end of body
}

std::shared_ptr<fUML::ActivityNodeActivation> ActivityNodeActivationImpl::getNodeActivation(std::shared_ptr<uml::ActivityNode>  node) 
{
	//generated from body annotation
	std::shared_ptr<ActivityNodeActivation> activation = nullptr;
    if (node == this->getNode()) 
    {
        struct null_deleter{void operator()(void const *) const { } };
        activation = std::shared_ptr<ActivityNodeActivation>(this, null_deleter());
    }

    return activation;
	//end of body
}

bool ActivityNodeActivationImpl::getRunning() 
{
	//generated from body annotation
	return this->isRunning();
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ActivityNodeActivationImpl::getTokens() 
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
	//end of body
}

bool ActivityNodeActivationImpl::isReady() 
{
	//generated from body annotation
	return this->getRunning();
	//end of body
}

bool ActivityNodeActivationImpl::isSourceFor(std::shared_ptr<fUML::ActivityEdgeInstance>  edgeInstances) 
{
	//generated from body annotation
	return (edgeInstances->getSource().get() ==this);
	//end of body
}

void ActivityNodeActivationImpl::recieveOffer() 
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
	//end of body
}

int ActivityNodeActivationImpl::removeToken(std::shared_ptr<fUML::Token>  token) 
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

			ACT_DEBUG(
				if (this->getNode() == nullptr)
				{
					std::cout<<"SET_TOKEN;NODE:[ANONYMOUS_ACTIVATION]"<<";TOKEN:"<<token->getValue() << ";CURRENT_TOKENS:"<< (heldTokenList->size()-1) <<";DIRECTION:remove"<<std::endl;
				} else
				{
                    std::shared_ptr<uml::NamedElement> owner = std::dynamic_pointer_cast<uml::NamedElement>(this->getNode()->getOwner().lock());
			if(nullptr != owner){
					std::cout<<"SET_TOKEN;NODE:" << (owner != nullptr? owner->getName() : "[NO_OWNER]") << "::" << this->getNode()->getName() <<";TOKEN:"<<token->getValue() << ";CURRENT_TOKENS:"<< (heldTokenList->size()-1) <<";DIRECTION:remove"<<std::endl;
					}
				}
			)
			this->getHeldTokens()->erase(iter);
			return i;
		}

		iter++;
	}

	return 0;
	//end of body
}

void ActivityNodeActivationImpl::resume() 
{
	//generated from body annotation
	struct null_deleter{void operator()(void const *) const { } };
	this->getGroup()->resume(std::shared_ptr<ActivityNodeActivation>(this, null_deleter()));
	//end of body
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
	//end of body
}

void ActivityNodeActivationImpl::sendOffers(std::shared_ptr<Bag<fUML::Token> >  tokens) 
{
	//generated from body annotation
		if (tokens->size() > 0) 
	{
        // *** Send all outgoing offers concurrently. ***
		std::shared_ptr<Bag<ActivityEdgeInstance> > outgoingEdgeList = this->getOutgoingEdges();
        for(std::shared_ptr<ActivityEdgeInstance> outgoingEdge : *outgoingEdgeList)
        {
			DEBUG_MESSAGE(
			if(nullptr == outgoingEdge->getTarget()){
				std::cerr << "[sendOffers] Target is NULL for edge: " << outgoingEdge->getEdge()->getName() << std::endl;
			}
			else if(nullptr == outgoingEdge->getTarget()->getNode())
			{
				std::cerr << "[sendOffers] Node is NULL for target on edge: " <<  outgoingEdge->getEdge()->getName() << std::endl;
			}else{
				std::cout << "[sendOffers] Sending offer to " << outgoingEdge->getTarget()->getNode()->getName() << "."
						  << std::endl;
			}
			)
            outgoingEdge->sendOffer(tokens);
        }
    }
	//end of body
}

void ActivityNodeActivationImpl::suspend() 
{
	//generated from body annotation
	struct null_deleter{void operator()(void const *) const { } };
	this->getGroup()->suspend(std::shared_ptr<ActivityNodeActivation>(this, null_deleter()));
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ActivityNodeActivationImpl::takeOfferedTokens() 
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
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ActivityNodeActivationImpl::takeTokens() 
{
	//generated from body annotation
	std::shared_ptr<Bag<Token> > tokens = this->getTokens();
    this->clearTokens();

    return tokens;
	//end of body
}

void ActivityNodeActivationImpl::terminate() 
{
	//generated from body annotation
	/*    if (this->isRunning()) {
        if (this->getNode() != nullptr) {
            DEBUG_MESSAGE(std::cout<<"[terminate] node = " << this->getNode()->getName()<<std::endl;)
        } else {
            DEBUG_MESSAGE(std::cout<<"[terminate] Anonymous activation of type " << this->eClass()->getName()<<std::endl;)
        }
    }
*/
this->setRunning(false);
	//end of body
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

std::shared_ptr< Bag<fUML::Token> > ActivityNodeActivationImpl::getHeldTokens() const
{

    return m_heldTokens;
}


std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > ActivityNodeActivationImpl::getIncomingEdges() const
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

std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > ActivityNodeActivationImpl::getOutgoingEdges() const
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
