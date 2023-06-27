
#include "fUML/Semantics/Activities/impl/ActivityEdgeInstanceImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include <algorithm> 
#include "fUML/fUMLFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/ActivityEdge.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/Offer.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

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
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ActivityEdgeInstance 
	 * which is generated by the compiler (as ActivityEdgeInstance is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ActivityEdgeInstance::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityEdgeInstance "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_edge  = obj.getEdge();
	m_group  = obj.getGroup();
	m_offers  = obj.getOffers();
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
        count+=offer->countOfferedValues();
    }
    return count;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> ActivityEdgeInstanceImpl::getOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> tokens(new Bag<fUML::Semantics::Activities::Token>());
	std::shared_ptr<Bag<fUML::Semantics::Activities::Offer>> offers = this->getOffers();

    for(const std::shared_ptr<fUML::Semantics::Activities::Offer>& offer : *offers)
    {
		std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> tokensOfOffer = offer->retrieveOfferedTokens();

        tokens->insert(tokens->end(), tokensOfOffer->begin(), tokensOfOffer->end());
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

void ActivityEdgeInstanceImpl::sendOffer(const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& tokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Semantics::Activities::Offer> offer(fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createOffer());
    	offer->getOfferedTokens()->insert(offer->getOfferedTokens()->end(), tokens->begin(), tokens->end());
    	this->getOffers()->push_back(offer);

	DEBUG_INFO((((this ->getEdge() == nullptr) || (this->getEdge()->getName() == "")) ? "Anonymous edge" : (this->getEdge()->eClass()->getName() + " '" + this->getEdge()->getName() + "'")) << " created a new offer containing "<<tokens->size()<<" token(s).")

    	auto target = this->getTarget().lock();

    if(nullptr == target )
    {
        //NEWDEBUG
	DEBUG_ERROR("Target is nullptr! Failed to send offer!")
    }
    else
    {
    	target->receiveOffer();
    }
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> ActivityEdgeInstanceImpl::takeOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens(new Bag<fUML::Semantics::Activities::Token>());

	std::shared_ptr<Bag<fUML::Semantics::Activities::Offer> > offerList = this->getOffers();
	//NEWDEBUG
	DEBUG_INFO((((this->getEdge() == nullptr) || (this->getEdge()->getName() == "")) ? "Anonymous edge" : (this->getEdge()->eClass()->getName() + " '" + this->getEdge()->getName() + "'")) << " has " << this->getOffers()->size() << " offer(s).")

	for(const std::shared_ptr<fUML::Semantics::Activities::Offer>& offer : *offerList)
    	{
    		auto vec = offer->retrieveOfferedTokens();
		//NEWDEBUG
		DEBUG_INFO("Retrieved "<<vec->size()<<" token(s) from offer.")
       		tokens->insert(tokens->end(), vec->begin(), vec->end());
  	}

	DEBUG_INFO("Retrieved a total number of " << tokens->size() << " token(s).")

    	this->getOffers()->clear();

    	return tokens;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> ActivityEdgeInstanceImpl::takeOfferedTokens(int maxCount)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens(new Bag<fUML::Semantics::Activities::Token>());
    int remainingCount = maxCount;

    while (this->getOffers()->size() > 0 && remainingCount > 0) {
    	std::shared_ptr<fUML::Semantics::Activities::Offer> offer = this->getOffers()->at(0);
    	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > offeredTokens = offer->retrieveOfferedTokens();
        int count = offer->countOfferedValues();
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
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference edge */
const std::shared_ptr<uml::ActivityEdge>& ActivityEdgeInstanceImpl::getEdge() const
{
    return m_edge;
}
void ActivityEdgeInstanceImpl::setEdge(const std::shared_ptr<uml::ActivityEdge>& _edge)
{
    m_edge = _edge;
	
}

/* Getter & Setter for reference group */
std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> ActivityEdgeInstanceImpl::getGroup() const
{
    return m_group;
}
void ActivityEdgeInstanceImpl::setGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _group)
{
    m_group = _group;
	
}

/* Getter & Setter for reference offers */
const std::shared_ptr<Bag<fUML::Semantics::Activities::Offer>>& ActivityEdgeInstanceImpl::getOffers() const
{
	if(m_offers == nullptr)
	{
		m_offers.reset(new Bag<fUML::Semantics::Activities::Offer>());
		
		
	}
    return m_offers;
}

/* Getter & Setter for reference source */
std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> ActivityEdgeInstanceImpl::getSource() const
{
    return m_source;
}
void ActivityEdgeInstanceImpl::setSource(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _source)
{
    m_source = _source;
	
}

/* Getter & Setter for reference target */
std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> ActivityEdgeInstanceImpl::getTarget() const
{
    return m_target;
}
void ActivityEdgeInstanceImpl::setTarget(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _target)
{
    m_target = _target;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ActivityEdgeInstanceImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
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

std::shared_ptr<ecore::EClass> ActivityEdgeInstanceImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityEdgeInstance_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ActivityEdgeInstanceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_EDGE:
			return eAny(getEdge(),uml::umlPackage::ACTIVITYEDGE_CLASS,false); //60
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_GROUP:
		{
			std::shared_ptr<ecore::EObject> returnValue=getGroup().lock();
			return eEcoreAny(returnValue,fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_CLASS); //64
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_OFFERS:
			return eEcoreContainerAny(getOffers(),fUML::Semantics::Activities::ActivitiesPackage::OFFER_CLASS); //63
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_SOURCE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getSource().lock();
			return eEcoreAny(returnValue,fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_CLASS); //61
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_TARGET:
		{
			std::shared_ptr<ecore::EObject> returnValue=getTarget().lock();
			return eEcoreAny(returnValue,fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_CLASS); //62
		}
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

bool ActivityEdgeInstanceImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_EDGE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ActivityEdge> _edge = std::dynamic_pointer_cast<uml::ActivityEdge>(eObject);
					if(_edge)
					{
						setEdge(_edge); //60
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'edge'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'edge'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_GROUP:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _group = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(eObject);
					if(_group)
					{
						setGroup(_group); //64
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'group'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'group'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_OFFERS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<fUML::Semantics::Activities::Offer>> _offers = getOffers();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<fUML::Semantics::Activities::Offer> valueToAdd = std::dynamic_pointer_cast<fUML::Semantics::Activities::Offer>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_offers->includes(valueToAdd)))
								{
									_offers->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'offers'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'offers'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_SOURCE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _source = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(eObject);
					if(_source)
					{
						setSource(_source); //61
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'source'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'source'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_TARGET:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _target = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(eObject);
					if(_target)
					{
						setTarget(_target); //62
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'target'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'target'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ActivityEdgeInstanceImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Activities::ActivityEdgeInstance::countOfferedValue() : int: 3512353870
		case ActivitiesPackage::ACTIVITYEDGEINSTANCE_OPERATION_COUNTOFFEREDVALUE:
		{
			result = eAny(this->countOfferedValue(), 0, false);
			break;
		}
		// fUML::Semantics::Activities::ActivityEdgeInstance::getOfferedTokens() : fUML::Semantics::Activities::Token[*]: 247253392
		case ActivitiesPackage::ACTIVITYEDGEINSTANCE_OPERATION_GETOFFEREDTOKENS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> resultList = this->getOfferedTokens();
			return eEcoreContainerAny(resultList,fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS);
			break;
		}
		// fUML::Semantics::Activities::ActivityEdgeInstance::hasOffer() : bool: 2669398996
		case ActivitiesPackage::ACTIVITYEDGEINSTANCE_OPERATION_HASOFFER:
		{
			result = eAny(this->hasOffer(), 0, false);
			break;
		}
		// fUML::Semantics::Activities::ActivityEdgeInstance::sendOffer(fUML::Semantics::Activities::Token[*]): 2265631071
		case ActivitiesPackage::ACTIVITYEDGEINSTANCE_OPERATION_SENDOFFER_TOKEN:
		{
			//Retrieve input parameter 'tokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_tokens;
			Bag<Any>::const_iterator incoming_param_tokens_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_tokens_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_tokens.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<fUML::Semantics::Activities::Token> _temp = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(anEObject);
								incoming_param_tokens->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'tokens'. Failed to invoke operation 'sendOffer'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'tokens'. Failed to invoke operation 'sendOffer'!")
					return nullptr;
				}
			}
		
			this->sendOffer(incoming_param_tokens);
			break;
		}
		// fUML::Semantics::Activities::ActivityEdgeInstance::takeOfferedTokens() : fUML::Semantics::Activities::Token[*]: 3785400521
		case ActivitiesPackage::ACTIVITYEDGEINSTANCE_OPERATION_TAKEOFFEREDTOKENS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> resultList = this->takeOfferedTokens();
			return eEcoreContainerAny(resultList,fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS);
			break;
		}
		// fUML::Semantics::Activities::ActivityEdgeInstance::takeOfferedTokens(int) : fUML::Semantics::Activities::Token[*]: 1787668928
		case ActivitiesPackage::ACTIVITYEDGEINSTANCE_OPERATION_TAKEOFFEREDTOKENS_EINT:
		{
			//Retrieve input parameter 'maxCount'
			//parameter 0
			int incoming_param_maxCount;
			Bag<Any>::const_iterator incoming_param_maxCount_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_maxCount = (*incoming_param_maxCount_arguments_citer)->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'maxCount'. Failed to invoke operation 'takeOfferedTokens'!")
				return nullptr;
			}
		
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> resultList = this->takeOfferedTokens(incoming_param_maxCount);
			return eEcoreContainerAny(resultList,fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> ActivityEdgeInstanceImpl::getThisActivityEdgeInstancePtr() const
{
	return m_thisActivityEdgeInstancePtr.lock();
}
void ActivityEdgeInstanceImpl::setThisActivityEdgeInstancePtr(std::weak_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> thisActivityEdgeInstancePtr)
{
	m_thisActivityEdgeInstancePtr = thisActivityEdgeInstancePtr;
}


