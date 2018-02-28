#include "fUML/impl/ObjectNodeActivationImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/ObjectToken.hpp"
#include "fUML/Token.hpp"

//Forward declaration includes
#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivation.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ObjectNodeActivationImpl::ObjectNodeActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References

	//Init references
}

ObjectNodeActivationImpl::~ObjectNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ObjectNodeActivationImpl::ObjectNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:ObjectNodeActivationImpl()
			{
			    m_group = par_group;
			}






ObjectNodeActivationImpl::ObjectNodeActivationImpl(const ObjectNodeActivationImpl & obj):ObjectNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ObjectNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_offeredTokenCount = obj.getOfferedTokenCount();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	m_node  = obj.getNode();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdgesList = obj.getIncomingEdges();
	for(std::shared_ptr<fUML::ActivityEdgeInstance> _incomingEdges : *_incomingEdgesList)
	{
		this->getIncomingEdges()->add(std::shared_ptr<fUML::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(_incomingEdges->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_incomingEdges" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdgesList = obj.getOutgoingEdges();
	for(std::shared_ptr<fUML::ActivityEdgeInstance> _outgoingEdges : *_outgoingEdgesList)
	{
		this->getOutgoingEdges()->add(std::shared_ptr<fUML::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(_outgoingEdges->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outgoingEdges" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ObjectNodeActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ObjectNodeActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ObjectNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObjectNodeActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ObjectNodeActivationImpl::setOfferedTokenCount(int _offeredTokenCount)
{
	m_offeredTokenCount = _offeredTokenCount;
} 

int ObjectNodeActivationImpl::getOfferedTokenCount() const 
{
	return m_offeredTokenCount;
}

//*********************************
// Operations
//*********************************
void ObjectNodeActivationImpl::addToken(std::shared_ptr<fUML::Token>  token) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if (token->getValue() == nullptr) {
        token->withdraw();
    } else {
        ActivityNodeActivationImpl::addToken(token);
    }
	//end of body
}

void ObjectNodeActivationImpl::clearTokens() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    ActivityNodeActivationImpl::clearTokens();
    this->setOfferedTokenCount(0);
	//end of body
}

int ObjectNodeActivationImpl::countOfferedValues() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		int totalValueCount = 0;
    unsigned int i = 0;
    while (i < this->getIncomingEdges()->size()) {
        totalValueCount = totalValueCount
                + this->getIncomingEdges()->at(i)->countOfferedValue();
        i = i + 1;
    }

    return totalValueCount;
	//end of body
}

int ObjectNodeActivationImpl::countUnofferedTokens() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if (this->getHeldTokens()->size() == 0) {
        this->setOfferedTokenCount(0);
    }

    return (this->getHeldTokens()->size() - this->getOfferedTokenCount());
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ObjectNodeActivationImpl::getUnofferedTokens() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Token> > tokens(new Bag<fUML::Token>());

  int i = 0; 
  const int numberUnofferedTokens=this->countUnofferedTokens(); 
  int offeredTokenCount=this->getOfferedTokenCount(); 
 
  Bag<fUML::Token>* heldTokenPtr = this->getHeldTokens().get(); 
  if(nullptr!=heldTokenPtr) 
  { 
    while (i < numberUnofferedTokens) 
    { 
      tokens->push_back((*heldTokenPtr)[offeredTokenCount + i]);
      i++; 
    } 
  } 
  return tokens; 
	//end of body
}

int ObjectNodeActivationImpl::removeToken(std::shared_ptr<fUML::Token>  token) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    int i = ActivityNodeActivationImpl::removeToken(token);
    if (i > 0 && i <= this->getOfferedTokenCount()) {
        this->setOfferedTokenCount(this->getOfferedTokenCount() - 1);
    }

    return i;
	//end of body
}

void ObjectNodeActivationImpl::run() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    ActivityNodeActivationImpl::run();
    this->setOfferedTokenCount(0);
	//end of body
}

void ObjectNodeActivationImpl::sendOffers(std::shared_ptr<Bag<fUML::Token> >  tokens) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (tokens->size() == 0) 
	{
		std::shared_ptr<ObjectToken> token = fUML::FUMLFactory::eInstance()->createObjectToken();
		token->setHolder(getThisObjectNodeActivationPtr());
		token->setWithdrawn(false);
		tokens->push_back(token);
	}

	ActivityNodeActivationImpl::sendOffers(tokens);
	//end of body
}

void ObjectNodeActivationImpl::sendUnofferedTokens() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<Token> > tokens = this->getUnofferedTokens();
    this->setOfferedTokenCount(this->getOfferedTokenCount() + tokens->size());
    this->sendOffers(tokens);
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ObjectNodeActivationImpl::takeUnofferedTokens() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Token> > tokens = this->getUnofferedTokens();
    for (unsigned int i = 0; i < tokens->size(); i++) 
    {
    	std::shared_ptr<Token> token = tokens->at(i);
        token->withdraw();
    }
    return tokens;
	//end of body
}

void ObjectNodeActivationImpl::terminate() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    this->clearTokens();
    ActivityNodeActivationImpl::terminate();
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ObjectNodeActivation> ObjectNodeActivationImpl::getThisObjectNodeActivationPtr()
{
	if(auto wp = m_group.lock())
	{
		std::shared_ptr<Bag<fUML::ActivityNodeActivation>> ownersObjectNodeActivationList = wp->getNodeActivations();
		for (std::shared_ptr<fUML::ActivityNodeActivation> anObjectNodeActivation : *ownersObjectNodeActivationList)
		{
			if (anObjectNodeActivation.get() == this)
			{
				return std::dynamic_pointer_cast<ObjectNodeActivation>(anObjectNodeActivation );
			}
		}
	}
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<ObjectNodeActivation>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> ObjectNodeActivationImpl::eContainer() const
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
boost::any ObjectNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return getGroup(); //593
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return getHeldTokens(); //592
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return getIncomingEdges(); //591
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return getNode(); //594
		case FUMLPackage::OBJECTNODEACTIVATION_EATTRIBUTE_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount(); //596
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return getOutgoingEdges(); //590
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return isRunning(); //595
	}
	return boost::any();
}

void ObjectNodeActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //593
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //594
			break;
		}
		case FUMLPackage::OBJECTNODEACTIVATION_EATTRIBUTE_OFFEREDTOKENCOUNT:
		{
			// BOOST CAST
			int _offeredTokenCount = boost::any_cast<int>(newValue);
			setOfferedTokenCount(_offeredTokenCount); //596
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //595
			break;
		}
	}
}
