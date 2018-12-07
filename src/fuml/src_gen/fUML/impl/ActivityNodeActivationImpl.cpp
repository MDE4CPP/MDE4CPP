#include "fUML/impl/ActivityNodeActivationImpl.hpp"

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
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "ecore/EClass.hpp"
#include "fUML/ActivityNodeActivation.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/Class.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/ActivityEdgeInstance.hpp"

#include "fUML/ActivityExecution.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivation.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/Locus.hpp"

#include "fUML/Object.hpp"

#include "fUML/SemanticVisitor.hpp"

#include "fUML/Token.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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


//Additional constructor for the containments back reference
			ActivityNodeActivationImpl::ActivityNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
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

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
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
	std::shared_ptr<ActivityNodeActivationImpl> element(new ActivityNodeActivationImpl(*this));
	element->setThisActivityNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActivityNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityNodeActivation_EClass();
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		if (edge->getTarget().lock().get() != this)
	{
		edge->setTarget(getThisActivityNodeActivationPtr());
	}
    this->getIncomingEdges()->push_back(edge);
	//end of body
}

void ActivityNodeActivationImpl::addOutgoingEdge(std::shared_ptr<fUML::ActivityEdgeInstance>  edge)
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

void ActivityNodeActivationImpl::addToken(std::shared_ptr<fUML::Token>  token)
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
		token = std::dynamic_pointer_cast<Token>(token->copy());
	}
	token->setHolder(getThisActivityNodeActivationPtr());
	token->setWithdrawn(false);

	DEBUG_MESSAGE(std::cout<<"[addToken] Adding token with value = " <<token->getValue()<<std::endl;)

	this->getHeldTokens()->push_back(token);
	//end of body
}

void ActivityNodeActivationImpl::addTokens(std::shared_ptr<Bag<fUML::Token> >  tokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	for(std::shared_ptr<Token> token: *tokens)
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

void ActivityNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::ActivityExecution> ActivityNodeActivationImpl::getActivityExecution()
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

	return std::shared_ptr<fUML::ActivityExecution>();
	//end of body
}

std::shared_ptr<fUML::Object> ActivityNodeActivationImpl::getExecutionContext()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getActivityExecution()->getContext();
	//end of body
}

std::shared_ptr<fUML::Locus> ActivityNodeActivationImpl::getExecutionLocus()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getActivityExecution()->getLocus();
	//end of body
}

std::shared_ptr<fUML::ActivityNodeActivation> ActivityNodeActivationImpl::getNodeActivation(std::shared_ptr<uml::ActivityNode>  node)
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

std::shared_ptr<Bag<fUML::Token> > ActivityNodeActivationImpl::getTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getRunning();
	//end of body
}

bool ActivityNodeActivationImpl::isSourceFor(std::shared_ptr<fUML::ActivityEdgeInstance>  edgeInstances)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return (edgeInstances->getSource().lock().get() ==this);
	//end of body
}

void ActivityNodeActivationImpl::recieveOffer()
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
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

void ActivityNodeActivationImpl::sendOffers(std::shared_ptr<Bag<fUML::Token> >  tokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			if (tokens->size() > 0) 
	{
        // *** Send all outgoing offers concurrently. ***
		std::shared_ptr<Bag<ActivityEdgeInstance> > outgoingEdgeList = this->getOutgoingEdges();
        for(std::shared_ptr<ActivityEdgeInstance> outgoingEdge : *outgoingEdgeList)
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
					}
				}
			)
            outgoingEdge->sendOffer(tokens);
        }
    }
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

std::shared_ptr<Bag<fUML::Token> > ActivityNodeActivationImpl::takeOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<Token> > tokens = this->getTokens();
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
std::weak_ptr<fUML::ActivityNodeActivationGroup > ActivityNodeActivationImpl::getGroup() const
{
//assert(m_group);
    return m_group;
}
void ActivityNodeActivationImpl::setGroup(std::shared_ptr<fUML::ActivityNodeActivationGroup> _group)
{
    m_group = _group;
}

std::shared_ptr<Bag<fUML::Token>> ActivityNodeActivationImpl::getHeldTokens() const
{

    return m_heldTokens;
}


std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> ActivityNodeActivationImpl::getIncomingEdges() const
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

std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> ActivityNodeActivationImpl::getOutgoingEdges() const
{

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
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return eAny(getGroup()); //73
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return eAny(getHeldTokens()); //72
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return eAny(getIncomingEdges()); //71
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return eAny(getNode()); //74
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return eAny(getOutgoingEdges()); //70
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return eAny(isRunning()); //75
	}
	return SemanticVisitorImpl::eGet(featureID, resolve, coreType);
}
bool ActivityNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return getGroup().lock() != nullptr; //73
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return getHeldTokens() != nullptr; //72
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return getIncomingEdges() != nullptr; //71
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return getNode() != nullptr; //74
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return getOutgoingEdges() != nullptr; //70
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return isRunning() != false; //75
	}
	return SemanticVisitorImpl::internalEIsSet(featureID);
}
bool ActivityNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = newValue->get<std::shared_ptr<fUML::ActivityNodeActivationGroup>>();
			setGroup(_group); //73
			return true;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = newValue->get<std::shared_ptr<uml::ActivityNode>>();
			setNode(_node); //74
			return true;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = newValue->get<bool>();
			setRunning(_running); //75
			return true;
		}
	}

	return SemanticVisitorImpl::eSet(featureID, newValue);
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
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

	SemanticVisitorImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{

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
			std::shared_ptr<fUML::Token> heldTokens = std::dynamic_pointer_cast<fUML::Token>(modelFactory->create(typeName));
			if (heldTokens != nullptr)
			{
				std::shared_ptr<Bag<fUML::Token>> list_heldTokens = this->getHeldTokens();
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

	SemanticVisitorImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ActivityNodeActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>( references.front() );
				setGroup(_group);
			}
			
			return;
		}

		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
		{
			std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdges = getIncomingEdges();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::ActivityEdgeInstance> _r = std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(ref);
				if (_r != nullptr)
				{
					_incomingEdges->push_back(_r);
				}				
			}
			return;
		}

		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ActivityNode> _node = std::dynamic_pointer_cast<uml::ActivityNode>( references.front() );
				setNode(_node);
			}
			
			return;
		}

		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
		{
			std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdges = getOutgoingEdges();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::ActivityEdgeInstance> _r = std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(ref);
				if (_r != nullptr)
				{
					_outgoingEdges->push_back(_r);
				}				
			}
			return;
		}
	}
	SemanticVisitorImpl::resolveReferences(featureID, references);
}

void ActivityNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ActivityNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getActivityNodeActivation_EAttribute_running()) )
		{
			saveHandler->addAttribute("running", this->isRunning());
		}

		// Add references
		std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> incomingEdges_list = this->getIncomingEdges();
		for (std::shared_ptr<fUML::ActivityEdgeInstance > object : *incomingEdges_list)
		{ 
			saveHandler->addReferences("incomingEdges", object);
		}
		saveHandler->addReference("node", this->getNode());
		std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> outgoingEdges_list = this->getOutgoingEdges();
		for (std::shared_ptr<fUML::ActivityEdgeInstance > object : *outgoingEdges_list)
		{ 
			saveHandler->addReferences("outgoingEdges", object);
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'heldTokens'
		std::shared_ptr<Bag<fUML::Token>> list_heldTokens = this->getHeldTokens();
		for (std::shared_ptr<fUML::Token> heldTokens : *list_heldTokens) 
		{
			saveHandler->addReference(heldTokens, "heldTokens", heldTokens->eClass() != package->getToken_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

