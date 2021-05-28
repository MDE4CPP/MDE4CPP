#include "fUML/Semantics/Activities/impl/ActivityEdgeInstanceImpl.hpp"

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
#include <algorithm> 
#include "fUML/FUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/UmlFactory.hpp"


#include "uml/ActivityEdge.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/Offer.hpp"
#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ActivityEdgeInstanceImpl::ActivityEdgeInstanceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ActivityEdgeInstanceImpl::~ActivityEdgeInstanceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityEdgeInstance "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActivityEdgeInstanceImpl::ActivityEdgeInstanceImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ActivityEdgeInstanceImpl()
{
	m_group = par_group;
}

ActivityEdgeInstanceImpl::ActivityEdgeInstanceImpl(const ActivityEdgeInstanceImpl & obj): ActivityEdgeInstanceImpl()
{
	*this = obj;
}

ActivityEdgeInstanceImpl& ActivityEdgeInstanceImpl::operator=(const ActivityEdgeInstanceImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	ActivityEdgeInstance::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityEdgeInstance "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_edge  = obj.getEdge();
	m_group  = obj.getGroup();
	std::shared_ptr<Bag<fUML::Semantics::Activities::Offer>> _offers = obj.getOffers();
	m_offers.reset(new Bag<fUML::Semantics::Activities::Offer>(*(obj.getOffers().get())));
	m_source  = obj.getSource();
	m_target  = obj.getTarget();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ActivityEdgeInstanceImpl::copy() const
{
	std::shared_ptr<ActivityEdgeInstanceImpl> element(new ActivityEdgeInstanceImpl());
	*element =(*this);
	element->setThisActivityEdgeInstancePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActivityEdgeInstanceImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityEdgeInstance_Class();
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
	std::shared_ptr<Bag<fUML::Semantics::Activities::Offer> > offerList = this->getOffers();
    for(std::shared_ptr<fUML::Semantics::Activities::Offer> offer : *offerList)
    {
        count+=offer->countOfferedVales();
    }
    return count;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > ActivityEdgeInstanceImpl::getOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens(new Bag<fUML::Semantics::Activities::Token>());

	Bag<fUML::Semantics::Activities::Offer>* offerList = this->getOffers().get();
    const int size = offerList->size();
    Bag<fUML::Semantics::Activities::Token>* vec;
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
	return std::any_of(this->getOffers()->begin(),this->getOffers()->end(),[](std::shared_ptr<fUML::Semantics::Activities::Offer> offer){return offer->hasTokens();});

	//end of body
}

void ActivityEdgeInstanceImpl::sendOffer(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> tokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Semantics::Activities::Offer> offer(fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createOffer());
	//NEWDEBUG
	DEBUG_MESSAGE(std::cout<<"-- printing from ActivityEdgeInstance::"<<__FUNCTION__<<" '"<<(this->getEdge() == nullptr ? "..." : ("edge = " + this->getEdge()->getName()))<<"' : created new offer with "<<tokens->size()<<" tokens"<<std::endl;)
    offer->getOfferedTokens()->insert(offer->getOfferedTokens()->end(), tokens->begin(), tokens->end());
    this->getOffers()->push_back(offer);
    auto target = this->getTarget().lock();

	//NEWDEBUG
	DEBUG_MESSAGE(std::cout<<"-- printing from ActivityEdgeInstance::"<<__FUNCTION__<<" '"<<(this->getEdge() == nullptr ? "..." : ("edge = " + this->getEdge()->getName()))<<"' : #offers before receive = "<<this->getOffers()->size()<<std::endl;)

    if(nullptr == target )
    {
        std::cout << "[sendOffer] The edge does not have a target" << std::endl;
    }
    else
    {
    	target->receiveOffer();
    }

	//NEWDEBUG
	DEBUG_MESSAGE(std::cout<<"-- printing from ActivityEdgeInstance::"<<__FUNCTION__<<" '"<<(this->getEdge() == nullptr ? "..." : ("edge = " + this->getEdge()->getName()))<<"' : current #offers after receive = "<<this->getOffers()->size()<<std::endl;)
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > ActivityEdgeInstanceImpl::takeOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens(new Bag<fUML::Semantics::Activities::Token>());

	std::shared_ptr<Bag<fUML::Semantics::Activities::Offer> > offerList = this->getOffers();
	//NEWDEBUG
	DEBUG_MESSAGE(std::cout<<"-- printing from ActivityEdgeInstance::"<<__FUNCTION__<<" '"<<(this->getEdge() == nullptr ? "..." : ("edge = " + this->getEdge()->getName()))<<"' : #offers = "<<this->getOffers()->size()<<std::endl;)
	    for(std::shared_ptr<fUML::Semantics::Activities::Offer> offer : *offerList)
    {
    	auto vec = offer->retrieveOfferedTokens();
	//NEWDEBUG
	DEBUG_MESSAGE(std::cout<<"-- printing from ActivityEdgeInstance::"<<__FUNCTION__<<" '"<<(this->getEdge() == nullptr ? "..." : ("edge = " + this->getEdge()->getName()))<<"' : retrieved "<<vec->size()<<" tokens from offer"<<std::endl;)
        tokens->insert(tokens->end(), vec->begin(), vec->end());
    }
    this->getOffers()->clear();

    return tokens;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > ActivityEdgeInstanceImpl::takeOfferedTokens(int maxCount)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens(new Bag<fUML::Semantics::Activities::Token>());
    int remainingCount = maxCount;

    while (this->getOffers()->size() > 0 && remainingCount > 0) {
    	std::shared_ptr<fUML::Semantics::Activities::Offer> offer = this->getOffers()->at(0);
    	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > offeredTokens = offer->retrieveOfferedTokens();
        int count = offer->countOfferedVales();
        if (count <= remainingCount) {
            for (unsigned int i = 0; i < offeredTokens->size(); i++) {
                tokens->push_back(offeredTokens->at(i));
            }
            remainingCount = remainingCount - count;
            this->getOffers()->erase(this->getOffers()->begin());
        } else {
            for (int i = 0; i < remainingCount; i++) {
            	std::shared_ptr<fUML::Semantics::Activities::Token> token = offeredTokens->at(i);
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
/*
Getter & Setter for reference edge
*/
std::shared_ptr<uml::ActivityEdge> ActivityEdgeInstanceImpl::getEdge() const
{

    return m_edge;
}
void ActivityEdgeInstanceImpl::setEdge(std::shared_ptr<uml::ActivityEdge> _edge)
{
    m_edge = _edge;
}


/*
Getter & Setter for reference group
*/
std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> ActivityEdgeInstanceImpl::getGroup() const
{
//assert(m_group);
    return m_group;
}
void ActivityEdgeInstanceImpl::setGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _group)
{
    m_group = _group;
}


/*
Getter & Setter for reference offers
*/
std::shared_ptr<Bag<fUML::Semantics::Activities::Offer>> ActivityEdgeInstanceImpl::getOffers() const
{
	if(m_offers == nullptr)
	{
		m_offers.reset(new Bag<fUML::Semantics::Activities::Offer>());
		
		
	}

    return m_offers;
}



/*
Getter & Setter for reference source
*/
std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> ActivityEdgeInstanceImpl::getSource() const
{
//assert(m_source);
    return m_source;
}
void ActivityEdgeInstanceImpl::setSource(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _source)
{
    m_source = _source;
}


/*
Getter & Setter for reference target
*/
std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> ActivityEdgeInstanceImpl::getTarget() const
{
//assert(m_target);
    return m_target;
}
void ActivityEdgeInstanceImpl::setTarget(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _target)
{
    m_target = _target;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<ActivityEdgeInstance> ActivityEdgeInstanceImpl::getThisActivityEdgeInstancePtr() const
{
	return m_thisActivityEdgeInstancePtr.lock();
}
void ActivityEdgeInstanceImpl::setThisActivityEdgeInstancePtr(std::weak_ptr<ActivityEdgeInstance> thisActivityEdgeInstancePtr)
{
	m_thisActivityEdgeInstancePtr = thisActivityEdgeInstancePtr;
}
std::shared_ptr<ecore::EObject> ActivityEdgeInstanceImpl::eContainer() const
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
Any ActivityEdgeInstanceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_EDGE:
			return eAny(getEdge()); //60
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_GROUP:
			return eAny(getGroup().lock()); //64
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_OFFERS:
		{
			return eAny(getOffers()); //63			
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_SOURCE:
			return eAny(getSource().lock()); //61
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_TARGET:
			return eAny(getTarget().lock()); //62
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ActivityEdgeInstanceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_EDGE:
			return getEdge() != nullptr; //60
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_GROUP:
			return getGroup().lock() != nullptr; //64
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_OFFERS:
			return getOffers() != nullptr; //63
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_SOURCE:
			return getSource().lock() != nullptr; //61
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_TARGET:
			return getTarget().lock() != nullptr; //62
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ActivityEdgeInstanceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_EDGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ActivityEdge> _edge = std::dynamic_pointer_cast<uml::ActivityEdge>(_temp);
			setEdge(_edge); //60
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _group = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(_temp);
			setGroup(_group); //64
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_OFFERS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::Offer>> offersList(new Bag<fUML::Semantics::Activities::Offer>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				offersList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::Offer>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::Offer>::iterator iterOffers = m_offers->begin();
			Bag<fUML::Semantics::Activities::Offer>::iterator endOffers = m_offers->end();
			while (iterOffers != endOffers)
			{
				if (offersList->find(*iterOffers) == -1)
				{
					m_offers->erase(*iterOffers);
				}
				iterOffers++;
			}
 
			iterOffers = offersList->begin();
			endOffers = offersList->end();
			while (iterOffers != endOffers)
			{
				if (m_offers->find(*iterOffers) == -1)
				{
					m_offers->add(*iterOffers);
				}
				iterOffers++;			
			}
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_SOURCE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _source = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(_temp);
			setSource(_source); //61
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_TARGET:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _target = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(_temp);
			setTarget(_target); //62
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ActivityEdgeInstanceImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 606
		case ActivitiesPackage::ACTIVITYEDGEINSTANCE_OPERATION_COUNTOFFEREDVALUE:
		{
			result = eAny(this->countOfferedValue());
			break;
		}
		
		// 609
		case ActivitiesPackage::ACTIVITYEDGEINSTANCE_OPERATION_GETOFFEREDTOKENS:
		{
			result = eAny(this->getOfferedTokens());
			break;
		}
		
		// 610
		case ActivitiesPackage::ACTIVITYEDGEINSTANCE_OPERATION_HASOFFER:
		{
			result = eAny(this->hasOffer());
			break;
		}
		
		// 605
		case ActivitiesPackage::ACTIVITYEDGEINSTANCE_OPERATION_SENDOFFER_TOKEN:
		{
			//Retrieve input parameter 'tokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_tokens;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_tokens_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_tokens = (*incoming_param_tokens_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> >();
			this->sendOffer(incoming_param_tokens);
			break;
		}
		
		// 607
		case ActivitiesPackage::ACTIVITYEDGEINSTANCE_OPERATION_TAKEOFFEREDTOKENS:
		{
			result = eAny(this->takeOfferedTokens());
			break;
		}
		
		// 608
		case ActivitiesPackage::ACTIVITYEDGEINSTANCE_OPERATION_TAKEOFFEREDTOKENS_EINT:
		{
			//Retrieve input parameter 'maxCount'
			//parameter 0
			int incoming_param_maxCount;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_maxCount_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_maxCount = (*incoming_param_maxCount_arguments_citer)->get()->get<int >();
			result = eAny(this->takeOfferedTokens(incoming_param_maxCount));
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void ActivityEdgeInstanceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ActivityEdgeInstanceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("edge");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("edge")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("offers");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("offers")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityEdgeInstanceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void ActivityEdgeInstanceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_EDGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ActivityEdge> _edge = std::dynamic_pointer_cast<uml::ActivityEdge>( references.front() );
				setEdge(_edge);
			}
			
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_GROUP:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _group = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>( references.front() );
				setGroup(_group);
			}
			
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_OFFERS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::Offer>> _offers = getOffers();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::Offer>  _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::Offer>(ref);
				if (_r != nullptr)
				{
					_offers->push_back(_r);
				}
			}
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_SOURCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _source = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>( references.front() );
				setSource(_source);
			}
			
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_TARGET:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _target = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>( references.front() );
				setTarget(_target);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ActivityEdgeInstanceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ActivityEdgeInstanceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getEdge(), "edge", getEdge()->eClass() != uml::umlPackage::eInstance()->getActivityEdge_Class()); 
		saveHandler->addReferences<fUML::Semantics::Activities::Offer>("offers", this->getOffers());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

