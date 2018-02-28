#include "fUML/impl/ActivityEdgeInstanceImpl.hpp"

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
 #include "fuml/FUMLFactory.hpp"

//Forward declaration includes
#include "uml/ActivityEdge.hpp"

#include "fUML/ActivityNodeActivation.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/Offer.hpp"

#include "fUML/Token.hpp"


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


//Additional constructor for the containments back reference
			ActivityEdgeInstanceImpl::ActivityEdgeInstanceImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:ActivityEdgeInstanceImpl()
			{
			    m_group = par_group;
			}





//Additional constructor for the containments back reference
			ActivityEdgeInstanceImpl::ActivityEdgeInstanceImpl(std::weak_ptr<fUML::ActivityNodeActivation > par_ActivityNodeActivation, const int reference_id)
			:ActivityEdgeInstanceImpl()
			{
				switch(reference_id)
				{	
				case FUMLPackage::ACTIVITYEDGEINSTANCE_EREFERENCE_SOURCE:
					 m_source = par_ActivityNodeActivation;
					 return;
				case FUMLPackage::ACTIVITYEDGEINSTANCE_EREFERENCE_TARGET:
					 m_target = par_ActivityNodeActivation;
					 return;
				default:
				std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
				}
			   
			}





//Additional constructor for the containments back reference






ActivityEdgeInstanceImpl::ActivityEdgeInstanceImpl(const ActivityEdgeInstanceImpl & obj):ActivityEdgeInstanceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityEdgeInstance "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_edge  = obj.getEdge();

	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::Offer>> _offers = obj.getOffers();
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
	return FUMLPackageImpl::eInstance()->getActivityEdgeInstance_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
int ActivityEdgeInstanceImpl::countOfferedValue() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<Token> > tokens(new Bag<Token>());

	Bag<Offer>* offerList = this->getOffers().get();
    const int size = offerList->size();
    Bag<fUML::Token>* vec;
    for(int i=0; i < size; i++){
    {
        vec = (*offerList)[i]->retrieveOfferedTokens().get();
        if(vec->size()>0)
        {
            if (tokens->empty())
            {
                *tokens = *vec;
            } else {
                tokens->insert(tokens->end(), vec->begin(), vec->end());
            }
        }
        }
    }

    return tokens;
	//end of body
}

bool ActivityEdgeInstanceImpl::hasOffer() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return std::any_of(this->getOffers()->begin(),this->getOffers()->end(),[](std::shared_ptr<Offer> offer){return offer->hasTokens();});

	//end of body
}

void ActivityEdgeInstanceImpl::sendOffer(std::shared_ptr<Bag<fUML::Token> >  tokens) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		 std::shared_ptr<Offer> offer(fUML::FUMLFactory::eInstance()->createOffer());
    offer->getOfferedTokens()->insert(offer->getOfferedTokens()->end(), tokens->begin(), tokens->end());
    this->getOffers()->push_back(offer);
    auto target = this->getTarget().lock();
    if(nullptr == target )
    {
        std::cout << "[sendOffer] The edge does not have a target" << std::endl;
    }
    else
    {
    	target->recieveOffer();
    }
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ActivityEdgeInstanceImpl::takeOfferedTokens() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
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

std::weak_ptr<fUML::ActivityNodeActivationGroup > ActivityEdgeInstanceImpl::getGroup() const
{
//assert(m_group);
    return m_group;
}
void ActivityEdgeInstanceImpl::setGroup(std::shared_ptr<fUML::ActivityNodeActivationGroup> _group)
{
    m_group = _group;
}

std::shared_ptr<Bag<fUML::Offer>> ActivityEdgeInstanceImpl::getOffers() const
{

    return m_offers;
}


std::weak_ptr<fUML::ActivityNodeActivation > ActivityEdgeInstanceImpl::getSource() const
{
//assert(m_source);
    return m_source;
}
void ActivityEdgeInstanceImpl::setSource(std::shared_ptr<fUML::ActivityNodeActivation> _source)
{
    m_source = _source;
}

std::weak_ptr<fUML::ActivityNodeActivation > ActivityEdgeInstanceImpl::getTarget() const
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


std::shared_ptr<ActivityEdgeInstance> ActivityEdgeInstanceImpl::getThisActivityEdgeInstancePtr()
{
	if(auto wp = m_group.lock())
	{
		std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> ownersActivityEdgeInstanceList = wp->getEdgeInstances();
		for (std::shared_ptr<fUML::ActivityEdgeInstance> anActivityEdgeInstance : *ownersActivityEdgeInstanceList)
		{
			if (anActivityEdgeInstance.get() == this)
			{
				return anActivityEdgeInstance ;
			}
		}
	}

	if(auto wp = m_source.lock())
	{
		return nullptr;
	}
	if(auto wp = m_target.lock())
	{
		return nullptr;
	}

	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<ActivityEdgeInstance>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> ActivityEdgeInstanceImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}

	if(auto wp = m_source.lock())
	{
		return wp;
	}
	if(auto wp = m_target.lock())
	{
		return wp;
	}

	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActivityEdgeInstanceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYEDGEINSTANCE_EREFERENCE_EDGE:
			return getEdge(); //510
		case FUMLPackage::ACTIVITYEDGEINSTANCE_EREFERENCE_GROUP:
			return getGroup(); //514
		case FUMLPackage::ACTIVITYEDGEINSTANCE_EREFERENCE_OFFERS:
			return getOffers(); //513
		case FUMLPackage::ACTIVITYEDGEINSTANCE_EREFERENCE_SOURCE:
			return getSource(); //511
		case FUMLPackage::ACTIVITYEDGEINSTANCE_EREFERENCE_TARGET:
			return getTarget(); //512
	}
	return boost::any();
}

void ActivityEdgeInstanceImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYEDGEINSTANCE_EREFERENCE_EDGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityEdge> _edge = boost::any_cast<std::shared_ptr<uml::ActivityEdge>>(newValue);
			setEdge(_edge); //510
			break;
		}
		case FUMLPackage::ACTIVITYEDGEINSTANCE_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //514
			break;
		}
		case FUMLPackage::ACTIVITYEDGEINSTANCE_EREFERENCE_SOURCE:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivation> _source = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivation>>(newValue);
			setSource(_source); //511
			break;
		}
		case FUMLPackage::ACTIVITYEDGEINSTANCE_EREFERENCE_TARGET:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivation> _target = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivation>>(newValue);
			setTarget(_target); //512
			break;
		}
	}
}
