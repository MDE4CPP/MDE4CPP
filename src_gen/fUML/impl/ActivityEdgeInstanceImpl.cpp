#include "ActivityEdgeInstanceImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
 #include "FUMLFactory.hpp"

//Forward declaration includes
#include "ActivityEdge.hpp"

#include "ActivityNodeActivation.hpp"

#include "ActivityNodeActivationGroup.hpp"

#include "Offer.hpp"

#include "Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ActivityEdgeInstanceImpl::ActivityEdgeInstanceImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

		m_offers.reset(new Bag<fUML::Offer>());
	
	

	

	

	//Init references
	

	

	
	

	

	
}

ActivityEdgeInstanceImpl::~ActivityEdgeInstanceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityEdgeInstance "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




ActivityEdgeInstanceImpl::ActivityEdgeInstanceImpl(const ActivityEdgeInstanceImpl & obj):ActivityEdgeInstanceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityEdgeInstance "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_edge  = obj.getEdge();

	m_group  = obj.getGroup();

	std::shared_ptr< Bag<fUML::Offer> > _offers = obj.getOffers();
	m_offers.reset(new Bag<fUML::Offer>(*(obj.getOffers().get())));

	m_source  = obj.getSource();

	m_target  = obj.getTarget();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ActivityEdgeInstanceImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ActivityEdgeInstanceImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ActivityEdgeInstanceImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityEdgeInstance();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
int ActivityEdgeInstanceImpl::countOfferedValue() 
{
	//generated from body annotation
	int count = 0;
	std::shared_ptr<Bag<Offer> > offerList = this->getOffers();
    for(std::shared_ptr<Offer> offer : *offerList)
    {
        count+=offer->countOfferedVales();
    }
    return count;
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ActivityEdgeInstanceImpl::getOfferedTokens() 
{
	//generated from body annotation
	std::shared_ptr<Bag<Token> > tokens(new Bag<Token>());

	std::shared_ptr<Bag<Offer> > offerList = this->getOffers();
    for(std::shared_ptr<Offer> offer : *offerList)
    {
    	auto vec = offer->retrieveOfferedTokens();
        tokens->insert(tokens->end(), vec->begin(), vec->end());
    }

    return tokens;
	//end of body
}

bool ActivityEdgeInstanceImpl::hasOffer() 
{
	//generated from body annotation
	return std::any_of(this->getOffers()->begin(),this->getOffers()->end(),[](std::shared_ptr<Offer> offer){return offer->hasTokens();});

	//end of body
}

void ActivityEdgeInstanceImpl::sendOffer(std::shared_ptr<Bag<fUML::Token> >  tokens) 
{
	//generated from body annotation
	 std::shared_ptr<Offer> offer(fUML::FUMLFactory::eInstance()->createOffer());
    offer->getOfferedTokens()->insert(offer->getOfferedTokens()->end(), tokens->begin(), tokens->end());
    this->getOffers()->push_back(offer);
    if(nullptr == this->getTarget())
    {
        std::cout << "[sendOffer] The edge does not have a target" << std::endl;
    }
    else
    {
        this->getTarget()->recieveOffer();
    }
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ActivityEdgeInstanceImpl::takeOfferedTokens() 
{
	//generated from body annotation
	std::shared_ptr<Bag<Token> > tokens(new Bag<Token>());

	std::shared_ptr<Bag<Offer> > offerList = this->getOffers();
	    for(std::shared_ptr<Offer> offer : *offerList)
    {
    	auto vec = offer->retrieveOfferedTokens();
        tokens->insert(tokens->end(), vec->begin(), vec->end());
    }
    this->getOffers()->clear();

    return tokens;
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ActivityEdgeInstanceImpl::takeOfferedTokens(int maxCount) 
{
	//generated from body annotation
	std::shared_ptr<Bag<Token> > tokens(new Bag<Token>());
    int remainingCount = maxCount;

    while (this->getOffers()->size() > 0 && remainingCount > 0) {
    	std::shared_ptr<Offer> offer = this->getOffers()->at(0);
    	std::shared_ptr<Bag<fUML::Token> > offeredTokens = offer->retrieveOfferedTokens();
        int count = offer->countOfferedVales();
        if (count <= remainingCount) {
            for (unsigned int i = 0; i < offeredTokens->size(); i++) {
                tokens->push_back(offeredTokens->at(i));
            }
            remainingCount = remainingCount - count;
            this->getOffers()->erase(this->getOffers()->begin());
        } else {
            for (int i = 0; i < remainingCount; i++) {
            	std::shared_ptr<Token> token = offeredTokens->at(i);
                if (token->getValue() != nullptr) {
                    tokens->push_back(token);
                }
            }
            offer->removeOfferedValues(remainingCount);
            remainingCount = 0;
        }
    }

    return tokens;
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ActivityEdge > ActivityEdgeInstanceImpl::getEdge() const
{

    return m_edge;
}
void ActivityEdgeInstanceImpl::setEdge(std::shared_ptr<uml::ActivityEdge> _edge)
{
    m_edge = _edge;
}

std::shared_ptr<fUML::ActivityNodeActivationGroup > ActivityEdgeInstanceImpl::getGroup() const
{
//assert(m_group);
    return m_group;
}
void ActivityEdgeInstanceImpl::setGroup(std::shared_ptr<fUML::ActivityNodeActivationGroup> _group)
{
    m_group = _group;
}

std::shared_ptr< Bag<fUML::Offer> > ActivityEdgeInstanceImpl::getOffers() const
{

    return m_offers;
}


std::shared_ptr<fUML::ActivityNodeActivation > ActivityEdgeInstanceImpl::getSource() const
{
//assert(m_source);
    return m_source;
}
void ActivityEdgeInstanceImpl::setSource(std::shared_ptr<fUML::ActivityNodeActivation> _source)
{
    m_source = _source;
}

std::shared_ptr<fUML::ActivityNodeActivation > ActivityEdgeInstanceImpl::getTarget() const
{
//assert(m_target);
    return m_target;
}
void ActivityEdgeInstanceImpl::setTarget(std::shared_ptr<fUML::ActivityNodeActivation> _target)
{
    m_target = _target;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActivityEdgeInstanceImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYEDGEINSTANCE_EDGE:
			return getEdge(); //510
		case FUMLPackage::ACTIVITYEDGEINSTANCE_GROUP:
			return getGroup(); //514
		case FUMLPackage::ACTIVITYEDGEINSTANCE_OFFERS:
			return getOffers(); //513
		case FUMLPackage::ACTIVITYEDGEINSTANCE_SOURCE:
			return getSource(); //511
		case FUMLPackage::ACTIVITYEDGEINSTANCE_TARGET:
			return getTarget(); //512
	}
	return boost::any();
}
