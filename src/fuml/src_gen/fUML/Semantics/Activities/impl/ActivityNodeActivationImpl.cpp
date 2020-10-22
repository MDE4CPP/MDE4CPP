#include "fUML/Semantics/Activities/impl/ActivityNodeActivationImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "ecore/EClass.hpp"
#include "fUML/Semantics/Activities/ForkedToken.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/Class.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "fUML/Semantics/Activities/ActivityExecution.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"

#include "fUML/Semantics/StructuredClassifiers/Object.hpp"

#include "fUML/Semantics/Loci/SemanticVisitor.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivitiesPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ActivityNodeActivationImpl::ActivityNodeActivationImpl()
{	
}

ActivityNodeActivationImpl::~ActivityNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActivityNodeActivationImpl::ActivityNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
:ActivityNodeActivationImpl()
{
	m_group = par_group;
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

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Semantics::Activities::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Semantics::Activities::Token>(std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif

	
}

std::shared_ptr<ecore::EObject>  ActivityNodeActivationImpl::copy() const
{
	std::shared_ptr<ActivityNodeActivationImpl> element(new ActivityNodeActivationImpl(*this));
	element->setThisActivityNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActivityNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute running
*/
bool ActivityNodeActivationImpl::isRunning() const 
{
	return m_running;
}

void ActivityNodeActivationImpl::setRunning(bool _running)
{
	m_running = _running;
} 



//*********************************
// Operations
//*********************************
void ActivityNodeActivationImpl::addIncomingEdge(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance>  edge)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		if (edge->getTarget().lock().get() != this)
	{
		edge->setTarget(getThisActivityNodeActivationPtr());
	}
    this->getIncomingEdges()->push_back(edge);
	//end of body
}

void ActivityNodeActivationImpl::addOutgoingEdge(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance>  edge)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		if (edge->getSource().lock().get() != this)
	{
		edge->setSource(getThisActivityNodeActivationPtr());
	}
	this->getOutgoingEdges()->push_back(edge);
	//end of body
}

void ActivityNodeActivationImpl::addToken(std::shared_ptr<fUML::Semantics::Activities::Token>  token)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
				ACT_DEBUG(std::cout << "SET_TOKEN;NODE:" << (owner != nullptr ? owner->getName() : "[NO_OWNER]") << "::"
									<< this->getNode()->getName() << ";TOKEN:" << token->getValue()
									<< ";CURRENT_TOKENS:" << (this->getHeldTokens()->size() + 1) << ";DIRECTION:add"
									<< std::endl;)
		}
	)

if (!token->isWithdrawn())
{
	token->withdraw();
	//token = token->_copy();
	if(token->getMetaElementID() == fUML::Semantics::Activities::ActivitiesPackage::FORKEDTOKEN_CLASS)
	{
		token = token->_copy();
	}
		
}

token->setHolder(getThisActivityNodeActivationPtr());
token->setWithdrawn(false);

DEBUG_MESSAGE(std::cout<<"[addToken] Adding token with value = "<<token->getValue()<<std::endl;)

this->getHeldTokens()->push_back(token);
	//end of body
}

void ActivityNodeActivationImpl::addTokens(std::shared_ptr<Bag<fUML::Semantics::Activities::Token> >  tokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	for(std::shared_ptr<fUML::Semantics::Activities::Token> token: *tokens)
    {
        this->addToken(token);
    }
	//end of body
}

void ActivityNodeActivationImpl::clearTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    while (this->getHeldTokens()->size() > 0) {
        this->getHeldTokens()->at(0)->withdraw();
    }
	//end of body
}

void ActivityNodeActivationImpl::createEdgeInstances()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return;
	//end of body
}

void ActivityNodeActivationImpl::createNodeActivations()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return;
	//end of body
}

void ActivityNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token> >  incomingTokens)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> ActivityNodeActivationImpl::getActivityExecution()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	
	auto group=this->getGroup().lock();
	if(group)
	{
		return group->retrieveActivityExecution();
	}
	else
	{
		std::cout << __PRETTY_FUNCTION__  << std::endl;
		throw "empty group!";
	}

	return std::shared_ptr<fUML::Semantics::Activities::ActivityExecution>();
	//end of body
}

std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> ActivityNodeActivationImpl::getExecutionContext()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getActivityExecution()->getContext();
	//end of body
}

std::shared_ptr<fUML::Semantics::Loci::Locus> ActivityNodeActivationImpl::getExecutionLocus()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getActivityExecution()->getLocus();
	//end of body
}

std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> ActivityNodeActivationImpl::getNodeActivation(std::shared_ptr<uml::ActivityNode>  node)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (node == this->getNode())
	{
		return getThisActivityNodeActivationPtr();
	}
	else
	{
		return nullptr;
	}
	//end of body
}

bool ActivityNodeActivationImpl::getRunning()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->isRunning();
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > ActivityNodeActivationImpl::getTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens(new Bag<fUML::Semantics::Activities::Token>());
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > heldTokens = this->getHeldTokens();
    for (unsigned int i = 0; i < heldTokens->size(); i++) 
    {
    	std::shared_ptr<fUML::Semantics::Activities::Token> heldToken = heldTokens->at(i);
        tokens->push_back(heldToken);
    }

    return tokens;
	//end of body
}

bool ActivityNodeActivationImpl::isReady()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getRunning();
	//end of body
}

bool ActivityNodeActivationImpl::isSourceFor(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance>  edgeInstances)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return (edgeInstances->getSource().lock().get() ==this);
	//end of body
}

void ActivityNodeActivationImpl::receiveOffer()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[receiveOffer] "
 << (this->getNode() == nullptr ? "..." : ("node = " + this->getNode()->getName()))<<std::endl;)

    _beginIsolation();

    bool ready = this->isReady();

    std::shared_ptr<Bag<Token> > tokens;
    if (ready) 
    {
        DEBUG_MESSAGE(std::cout<<"[receiveOffer] Firing."<<std::endl;)
        tokens = this->takeOfferedTokens();
    }
		else{
		//NEWDEBUG
		DEBUG_MESSAGE(std::cout<<"ActivityNodeActivation::[receiveOffer] NOT taking offered tokens because not ready"<<std::endl;)
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

int ActivityNodeActivationImpl::removeToken(std::shared_ptr<fUML::Semantics::Activities::Token>  token)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > heldTokenList = this->getHeldTokens();
	std::vector<std::shared_ptr<fUML::Semantics::Activities::Token>>::iterator iter = heldTokenList->begin();
	std::vector<std::shared_ptr<fUML::Semantics::Activities::Token>>::iterator end = heldTokenList->end();

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
			std::cout<<"SET_TOKEN;NODE:" << (owner != nullptr? owner->getName() : "[NO_OWNER]") << "::" << this->getNode()->getName() <<";TOKEN:"<<token->getValue() << ";CURRENT_TOKENS:"<< (heldTokenList->size()-1) <<";DIRECTION:remove"<<std::endl;
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		auto group=this->getGroup().lock();
	if(group)
	{
		group->resume(getThisActivityNodeActivationPtr());
	}
	else
	{
		DEBUG_MESSAGE(std::cout<<"empty group"<<std::endl;)
	}

	//end of body
}

void ActivityNodeActivationImpl::run()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if (this->getNode() != nullptr) {
        DEBUG_MESSAGE(std::cout<<"[run] node = " << this->getNode()->getName()<<std::endl;)
    } else {
        DEBUG_MESSAGE(std::cout<<"[run] Anonymous activation of type "<<std::endl;)
    }

    this->setRunning(true);
	//end of body
}

void ActivityNodeActivationImpl::sendOffers(std::shared_ptr<Bag<fUML::Semantics::Activities::Token> >  tokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	//NEWDEBUG
	DEBUG_MESSAGE(std::cout<<"[sendOffers] "<< (this->getNode() == nullptr ? "..." : ("node = " + this->getNode()->getName()))<<std::endl;)		
if (tokens->size() > 0) 
	{
        // *** Send all outgoing offers concurrently. ***
		std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance> > outgoingEdgeList = this->getOutgoingEdges();
        for(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> outgoingEdge : *outgoingEdgeList)
        {
			DEBUG_MESSAGE(
				auto target=outgoingEdge->getTarget().lock();
				if(!target){
					std::cerr << "[sendOffers] Target is NULL for edge: " << outgoingEdge->getEdge()->getName() << std::endl;
				}
				else
				{
					if(! (target->getNode()))
					{
						std::cerr << "[sendOffers] Node is NULL for target on edge: " <<  outgoingEdge->getEdge()->getName() << std::endl;
					}
					else
					{
						std::cout << "[sendOffers] Sending offer to " << target->getNode()->getName() << "."
							  << std::endl;
						//NEWDEBUG
						DEBUG_MESSAGE(std::cout << "[sendOffers] Sending offer to " << target->getNode()->getName() << " with "<<tokens->size()<<" tokens."<< std::endl;)
					}
				}
			)
            outgoingEdge->sendOffer(tokens);
        }
    }

//NEWDEBUG alles hier drunter
	if (this->getNode() == nullptr) 
	{
        DEBUG_MESSAGE(std::cout<<"-- printing from ActivityNodeActivation::"<<__FUNCTION__<<" : node = anonymous fork\n";)
    } 
	else 
	{
		DEBUG_MESSAGE(std::cout<<"-- printing from ActivityNodeActivation::"<<__FUNCTION__<<" : node = "<<this->getNode()->getName()<<std::endl;)
    }
		DEBUG_MESSAGE(std::cout<<"-- printing from ActivityNodeActivation::"<<__FUNCTION__<<" : ENDE!!!!!!!!!\n";)
	//end of body
}

void ActivityNodeActivationImpl::suspend()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		auto group=this->getGroup().lock();
	if(group)
	{
		group->suspend(getThisActivityNodeActivationPtr());
	}
	else
	{
		DEBUG_MESSAGE(std::cout<<"empty group"<<std::endl;)
	}
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > ActivityNodeActivationImpl::takeOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > allTokens(new Bag<fUML::Semantics::Activities::Token>());
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance> > incomingEdgeList = this->getIncomingEdges();

	//NEWDEBUG
	DEBUG_MESSAGE(std::cout<<"-- printing from ActivityNodeActivation::"<<__FUNCTION__<<" '"<<(this->getNode() == nullptr ? "..." : ("node = " + this->getNode()->getName()))<<"' : #incomingEdges = "<<incomingEdgeList->size()<<std::endl;)

	for(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> incomingEdge : *incomingEdgeList)
	{
		auto vec = incomingEdge->takeOfferedTokens();
		allTokens->insert(allTokens->end(), vec->begin(), vec->end());
	}

	//NEWDEBUG
	DEBUG_MESSAGE(std::cout<<"-- printing from ActivityNodeActivation::"<<__FUNCTION__<<" for node '"<<(this->getNode() == nullptr ? "..." : ("node = " + this->getNode()->getName()))<<"' : #allTokens = "<<allTokens->size()<<std::endl;)

	return allTokens;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > ActivityNodeActivationImpl::takeTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens = this->getTokens();
    this->clearTokens();

    return tokens;
	//end of body
}

void ActivityNodeActivationImpl::terminate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
/*
Getter & Setter for reference group
*/
std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > ActivityNodeActivationImpl::getGroup() const
{
//assert(m_group);
    return m_group;
}

void ActivityNodeActivationImpl::setGroup(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _group)
{
    m_group = _group;
}



/*
Getter & Setter for reference heldTokens
*/
std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> ActivityNodeActivationImpl::getHeldTokens() const
{
	if(m_heldTokens == nullptr)
	{
		m_heldTokens.reset(new Bag<fUML::Semantics::Activities::Token>());
		
		
	}

    return m_heldTokens;
}





/*
Getter & Setter for reference incomingEdges
*/
std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> ActivityNodeActivationImpl::getIncomingEdges() const
{
	if(m_incomingEdges == nullptr)
	{
		m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>());
		
		
	}

    return m_incomingEdges;
}





/*
Getter & Setter for reference node
*/
std::shared_ptr<uml::ActivityNode > ActivityNodeActivationImpl::getNode() const
{

    return m_node;
}

void ActivityNodeActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
    m_node = _node;
}



/*
Getter & Setter for reference outgoingEdges
*/
std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> ActivityNodeActivationImpl::getOutgoingEdges() const
{
	if(m_outgoingEdges == nullptr)
	{
		m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>());
		
		
	}

    return m_outgoingEdges;
}





//*********************************
// Union Getter
//*********************************



std::shared_ptr<ActivityNodeActivation> ActivityNodeActivationImpl::getThisActivityNodeActivationPtr() const
{
	return m_thisActivityNodeActivationPtr.lock();
}
void ActivityNodeActivationImpl::setThisActivityNodeActivationPtr(std::weak_ptr<ActivityNodeActivation> thisActivityNodeActivationPtr)
{
	m_thisActivityNodeActivationPtr = thisActivityNodeActivationPtr;
	setThisSemanticVisitorPtr(thisActivityNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> ActivityNodeActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ActivityNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_GROUP:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getGroup().lock())); //93
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_HELDTOKENS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Activities::Token>::iterator iter = m_heldTokens->begin();
			Bag<fUML::Semantics::Activities::Token>::iterator end = m_heldTokens->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //92
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_INCOMINGEDGES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator iter = m_incomingEdges->begin();
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator end = m_incomingEdges->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //91
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_NODE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getNode())); //94
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_OUTGOINGEDGES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator iter = m_outgoingEdges->begin();
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator end = m_outgoingEdges->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //90
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_RUNNING:
			return eAny(isRunning()); //95
	}
	return fUML::Semantics::Loci::SemanticVisitorImpl::eGet(featureID, resolve, coreType);
}
bool ActivityNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_GROUP:
			return getGroup().lock() != nullptr; //93
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_HELDTOKENS:
			return getHeldTokens() != nullptr; //92
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_INCOMINGEDGES:
			return getIncomingEdges() != nullptr; //91
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_NODE:
			return getNode() != nullptr; //94
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_OUTGOINGEDGES:
			return getOutgoingEdges() != nullptr; //90
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_RUNNING:
			return isRunning() != false; //95
	}
	return fUML::Semantics::Loci::SemanticVisitorImpl::internalEIsSet(featureID);
}
bool ActivityNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _group = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(_temp);
			setGroup(_group); //93
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_HELDTOKENS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> heldTokensList(new Bag<fUML::Semantics::Activities::Token>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				heldTokensList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::Token>::iterator iterHeldTokens = m_heldTokens->begin();
			Bag<fUML::Semantics::Activities::Token>::iterator endHeldTokens = m_heldTokens->end();
			while (iterHeldTokens != endHeldTokens)
			{
				if (heldTokensList->find(*iterHeldTokens) == -1)
				{
					m_heldTokens->erase(*iterHeldTokens);
				}
				iterHeldTokens++;
			}

			iterHeldTokens = heldTokensList->begin();
			endHeldTokens = heldTokensList->end();
			while (iterHeldTokens != endHeldTokens)
			{
				if (m_heldTokens->find(*iterHeldTokens) == -1)
				{
					m_heldTokens->add(*iterHeldTokens);
				}
				iterHeldTokens++;			
			}
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_INCOMINGEDGES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> incomingEdgesList(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				incomingEdgesList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityEdgeInstance>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator iterIncomingEdges = m_incomingEdges->begin();
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator endIncomingEdges = m_incomingEdges->end();
			while (iterIncomingEdges != endIncomingEdges)
			{
				if (incomingEdgesList->find(*iterIncomingEdges) == -1)
				{
					m_incomingEdges->erase(*iterIncomingEdges);
				}
				iterIncomingEdges++;
			}

			iterIncomingEdges = incomingEdgesList->begin();
			endIncomingEdges = incomingEdgesList->end();
			while (iterIncomingEdges != endIncomingEdges)
			{
				if (m_incomingEdges->find(*iterIncomingEdges) == -1)
				{
					m_incomingEdges->add(*iterIncomingEdges);
				}
				iterIncomingEdges++;			
			}
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ActivityNode> _node = std::dynamic_pointer_cast<uml::ActivityNode>(_temp);
			setNode(_node); //94
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_OUTGOINGEDGES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> outgoingEdgesList(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				outgoingEdgesList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityEdgeInstance>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator iterOutgoingEdges = m_outgoingEdges->begin();
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator endOutgoingEdges = m_outgoingEdges->end();
			while (iterOutgoingEdges != endOutgoingEdges)
			{
				if (outgoingEdgesList->find(*iterOutgoingEdges) == -1)
				{
					m_outgoingEdges->erase(*iterOutgoingEdges);
				}
				iterOutgoingEdges++;
			}

			iterOutgoingEdges = outgoingEdgesList->begin();
			endOutgoingEdges = outgoingEdgesList->end();
			while (iterOutgoingEdges != endOutgoingEdges)
			{
				if (m_outgoingEdges->find(*iterOutgoingEdges) == -1)
				{
					m_outgoingEdges->add(*iterOutgoingEdges);
				}
				iterOutgoingEdges++;			
			}
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = newValue->get<bool>();
			setRunning(_running); //95
			return true;
		}
	}

	return fUML::Semantics::Loci::SemanticVisitorImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ActivityNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ActivityNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("running");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setRunning(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("incomingEdges");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("incomingEdges")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("node");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("node")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("outgoingEdges");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("outgoingEdges")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	fUML::Semantics::Loci::SemanticVisitorImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Activities::ActivitiesFactory> modelFactory=fUML::Semantics::Activities::ActivitiesFactory::eInstance();

	try
	{
		if ( nodeName.compare("heldTokens") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<fUML::Semantics::Activities::Token> heldTokens = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(modelFactory->create(typeName));
			if (heldTokens != nullptr)
			{
				std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> list_heldTokens = this->getHeldTokens();
				list_heldTokens->push_back(heldTokens);
				loadHandler->handleChild(heldTokens);
			}
			return;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}
	//load BasePackage Nodes
	fUML::Semantics::Loci::SemanticVisitorImpl::loadNode(nodeName, loadHandler);
}

void ActivityNodeActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_GROUP:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _group = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>( references.front() );
				setGroup(_group);
			}
			
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_INCOMINGEDGES:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _incomingEdges = getIncomingEdges();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityEdgeInstance>(ref);
				if (_r != nullptr)
				{
					_incomingEdges->push_back(_r);
				}				
			}
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_NODE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ActivityNode> _node = std::dynamic_pointer_cast<uml::ActivityNode>( references.front() );
				setNode(_node);
			}
			
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_OUTGOINGEDGES:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _outgoingEdges = getOutgoingEdges();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityEdgeInstance>(ref);
				if (_r != nullptr)
				{
					_outgoingEdges->push_back(_r);
				}				
			}
			return;
		}
	}
	fUML::Semantics::Loci::SemanticVisitorImpl::resolveReferences(featureID, references);
}

void ActivityNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ActivityNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getActivityNodeActivation_Attribute_running()) )
		{
			saveHandler->addAttribute("running", this->isRunning());
		}

		// Add references
		std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> incomingEdges_list = this->getIncomingEdges();
		for (std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance > object : *incomingEdges_list)
		{ 
			saveHandler->addReferences("incomingEdges", object);
		}
		saveHandler->addReference("node", this->getNode());
		std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> outgoingEdges_list = this->getOutgoingEdges();
		for (std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance > object : *outgoingEdges_list)
		{ 
			saveHandler->addReferences("outgoingEdges", object);
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'heldTokens'
		std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> list_heldTokens = this->getHeldTokens();
		for (std::shared_ptr<fUML::Semantics::Activities::Token> heldTokens : *list_heldTokens) 
		{
			saveHandler->addReference(heldTokens, "heldTokens", heldTokens->eClass() !=fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

