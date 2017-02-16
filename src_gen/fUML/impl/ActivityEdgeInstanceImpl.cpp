#include "ActivityEdgeInstanceImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
 #include "FUMLFactory.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ActivityEdgeInstanceImpl::ActivityEdgeInstanceImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
	if( m_offers == nullptr)
	{
		m_offers = new std::vector<fUML::Offer * >();
	}
	
	
}

ActivityEdgeInstanceImpl::~ActivityEdgeInstanceImpl()
{
	if(m_offers!=nullptr)
	{
		delete(m_offers);
	 	m_offers = nullptr;
	}
	
}

ActivityEdgeInstanceImpl::ActivityEdgeInstanceImpl(const ActivityEdgeInstanceImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_edge  = obj.getEdge();

	m_group  = obj.getGroup();

	std::vector<fUML::Offer * > *  _offers = obj.getOffers();
	this->getOffers()->insert(this->getOffers()->end(), _offers->begin(), _offers->end());

	m_source  = obj.getSource();

	m_target  = obj.getTarget();


	//clone containt lists
}

ecore::EObject *  ActivityEdgeInstanceImpl::copy() const
{
	return new ActivityEdgeInstanceImpl(*this);
}

ecore::EClass* ActivityEdgeInstanceImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityEdgeInstance();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
int ActivityEdgeInstanceImpl::countOfferedValue() 
{
	//generated from body annotation
	    int count = 0;
    for(Offer* offer : *this->getOffers())
    {
        count+=offer->countOfferedVales();
    }
    return count;
}

std::vector<fUML::Token * > *  ActivityEdgeInstanceImpl::getOfferedTokens() 
{
	//generated from body annotation
	    std::vector<Token * > * tokens = new  std::vector<Token * >();

    for(Offer * offer : *this->getOffers())
    {
auto vec = offer->retrieveOfferedTokens();
        tokens->insert(tokens->end(), vec->begin(), vec->end());
    }

    return tokens;

}

bool ActivityEdgeInstanceImpl::hasOffer() 
{
	//generated from body annotation
	return std::any_of(this->getOffers()->begin(),this->getOffers()->end(),[](Offer * offer){return offer->hasTokens();});
}

void ActivityEdgeInstanceImpl::sendOffer(std::vector<fUML::Token * > *  tokens) 
{
	//generated from body annotation
	    Offer * offer = fUML::FUMLFactory::eInstance()->createOffer();

    offer->getOfferedTokens()->insert(offer->getOfferedTokens()->end(), tokens->begin(), tokens->end());

     this->getOffers()->push_back(offer);
    this->getTarget()->recieveOffer();
}

std::vector<fUML::Token * > *  ActivityEdgeInstanceImpl::takeOfferedTokens() 
{
	//generated from body annotation
	    std::vector<Token * > * tokens = new  std::vector<Token * >();

    for(Offer * offer : *this->getOffers())
    {
 auto vec = offer->retrieveOfferedTokens();
        tokens->insert(tokens->end(), vec->begin(), vec->end());
    }
    
    for ( auto p : *this->getOffers()){
        delete p;
    }
    this->getOffers()->clear();

    return tokens;
}

std::vector<fUML::Token * > *  ActivityEdgeInstanceImpl::takeOfferedTokens(int maxCount) 
{
	//generated from body annotation
	    std::vector<Token * > * tokens = new  std::vector<Token * >();
    int remainingCount = maxCount;

    while (this->getOffers()->size() > 0 && remainingCount > 0) {
        Offer * offer = this->getOffers()->at(0);
        std::vector<Token * > * offeredTokens = offer->retrieveOfferedTokens();
        int count = offer->countOfferedVales();
        if (count <= remainingCount) {
            for (unsigned int i = 0; i < offeredTokens->size(); i++) {
                tokens->push_back(offeredTokens->at(i));
            }
            remainingCount = remainingCount - count;
            this->getOffers()->erase(this->getOffers()->begin());
        } else {
            for (int i = 0; i < remainingCount; i++) {
                Token * token = offeredTokens->at(i);
                if (token->getValue() != nullptr) {
                    tokens->push_back(token);
                }
            }
            offer->removeOfferedValues(remainingCount);
            remainingCount = 0;
        }
    }

    return tokens;
}

//*********************************
// References
//*********************************
uml::ActivityEdge *  ActivityEdgeInstanceImpl::getEdge() const
{
	
	return m_edge;
}
void ActivityEdgeInstanceImpl::setEdge(uml::ActivityEdge *  _edge)
{
	m_edge = _edge;
}

fUML::ActivityNodeActivationGroup *  ActivityEdgeInstanceImpl::getGroup() const
{
	//assert(m_group);
	return m_group;
}
void ActivityEdgeInstanceImpl::setGroup(fUML::ActivityNodeActivationGroup *  _group)
{
	m_group = _group;
}

std::vector<fUML::Offer * > *  ActivityEdgeInstanceImpl::getOffers() const
{
	
	return m_offers;
}


fUML::ActivityNodeActivation *  ActivityEdgeInstanceImpl::getSource() const
{
	//assert(m_source);
	return m_source;
}
void ActivityEdgeInstanceImpl::setSource(fUML::ActivityNodeActivation *  _source)
{
	m_source = _source;
}

fUML::ActivityNodeActivation *  ActivityEdgeInstanceImpl::getTarget() const
{
	//assert(m_target);
	return m_target;
}
void ActivityEdgeInstanceImpl::setTarget(fUML::ActivityNodeActivation *  _target)
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
