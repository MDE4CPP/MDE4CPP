#include "ObjectNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "Token.hpp"
#include "FUMLFactory.hpp"

//Forward declaration includes
#include "ActivityEdgeInstance.hpp"

#include "ActivityNode.hpp"

#include "ActivityNodeActivation.hpp"

#include "ActivityNodeActivationGroup.hpp"

#include "Token.hpp"


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

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif


}

ecore::EObject *  ObjectNodeActivationImpl::copy() const
{
	return new ObjectNodeActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> ObjectNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObjectNodeActivation();
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
	//generated from body annotation
	    ActivityNodeActivationImpl::clearTokens();
    this->setOfferedTokenCount(0);
	//end of body
}

int ObjectNodeActivationImpl::countOfferedValues() 
{
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
	//generated from body annotation
	    if (this->getHeldTokens()->size() == 0) {
        this->setOfferedTokenCount(0);
    }

    return (this->getHeldTokens()->size() - this->getOfferedTokenCount());
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ObjectNodeActivationImpl::getUnofferedTokens() 
{
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Token> > tokens(new Bag<fUML::Token>());

	int i = 1;
    while (i <= this->countUnofferedTokens()) 
    {
    	tokens->push_back(this->getHeldTokens()->at(this->getOfferedTokenCount() + i - 1));
        i = i + 1;
    }

    return tokens;
	//end of body
}

int ObjectNodeActivationImpl::removeToken(std::shared_ptr<fUML::Token>  token) 
{
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
	//generated from body annotation
	    ActivityNodeActivationImpl::run();
    this->setOfferedTokenCount(0);
	//end of body
}

void ObjectNodeActivationImpl::sendOffers(std::shared_ptr<Bag<fUML::Token> >  tokens) 
{
	//generated from body annotation
	if (tokens->size() == 0) 
	{
		std::shared_ptr<ObjectToken> token(fUML::FUMLFactory::eInstance()->createObjectToken());
		struct null_deleter{void operator()(void const *) const { } };		    
        token->setHolder(std::shared_ptr<ObjectNodeActivation>(this, null_deleter()));
        tokens->push_back(token);
    }

    ActivityNodeActivationImpl::sendOffers(tokens);
	//end of body
}

void ObjectNodeActivationImpl::sendUnofferedTokens() 
{
	//generated from body annotation
	std::shared_ptr<Bag<Token> > tokens = this->getUnofferedTokens();
    this->setOfferedTokenCount(this->getOfferedTokenCount() + tokens->size());
    this->sendOffers(tokens);
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ObjectNodeActivationImpl::takeUnofferedTokens() 
{
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ObjectNodeActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //593
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //592
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //591
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //594
		case FUMLPackage::OBJECTNODEACTIVATION_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount(); //596
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //590
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //595
	}
	return boost::any();
}
