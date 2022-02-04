
#include "fUML/Semantics/Activities/impl/OfferImpl.hpp"
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


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
OfferImpl::OfferImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OfferImpl::~OfferImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Offer "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


OfferImpl::OfferImpl(const OfferImpl & obj): OfferImpl()
{
	*this = obj;
}

OfferImpl& OfferImpl::operator=(const OfferImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Offer 
	 * which is generated by the compiler (as Offer is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Offer::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Offer "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_offeredTokens  = obj.getOfferedTokens();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OfferImpl::copy() const
{
	std::shared_ptr<OfferImpl> element(new OfferImpl());
	*element =(*this);
	element->setThisOfferPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
int OfferImpl::countOfferedVales()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    this->removeWithdrawnTokens();

    int count = 0;
    for (unsigned int i = 0; i < this->getOfferedTokens()->size(); i++) {
        if (this->getOfferedTokens()->at(i)->getValue() != nullptr) {
            count = count + 1;
        }
    }

    return count;
	//end of body
}

bool OfferImpl::hasTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    this->removeWithdrawnTokens();
    return (this->getOfferedTokens()->size() > 0);
	//end of body
}

void OfferImpl::removeOfferedValues(int count)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    int n = count;
    unsigned int i = 0;
    while (n > 0) {
        if (this->getOfferedTokens()->at(i)->getValue() != nullptr) {
            this->getOfferedTokens()->erase(this->getOfferedTokens()->begin() + i);
        } else {
            i = i + 1;
        }
        n = n - 1;
    }
	//end of body
}

void OfferImpl::removeWithdrawnTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	 std::shared_ptr< Bag<fUML::Semantics::Activities::Token> > offeredTokens= this->getOfferedTokens();
    Bag<fUML::Semantics::Activities::Token> *offeredTokensPtr=offeredTokens.get();

    const unsigned int numberTokens=offeredTokensPtr->size();

    if(numberTokens==1)
    {
        if((*offeredTokensPtr)[0]->isWithdrawn())
        {
            offeredTokensPtr->clear();
        }
    }
    else
    {
        Bag<fUML::Semantics::Activities::Token> *new_OfferedTokensPtr = new Bag<fUML::Semantics::Activities::Token>();
        m_offeredTokens.reset(new_OfferedTokensPtr);
        //	m_offeredTokens.reserve(numberTokens);
        for(unsigned int i = 0; i < numberTokens; i++)
        {
            if(!((*offeredTokensPtr)[i]->isWithdrawn()))
            {
                new_OfferedTokensPtr->push_back((*offeredTokensPtr)[i]);
            }
        }
    }
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > OfferImpl::retrieveOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->removeWithdrawnTokens();

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens(new Bag<fUML::Semantics::Activities::Token>());
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > offeredTokens = this->getOfferedTokens();
    for (unsigned int i = 0; i < this->getOfferedTokens()->size(); i++)
    {
    	std::shared_ptr<fUML::Semantics::Activities::Token> offeredToken = offeredTokens->at(i);
        tokens->push_back(offeredToken);
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
/* Getter & Setter for reference offeredTokens */
std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> OfferImpl::getOfferedTokens() const
{
	if(m_offeredTokens == nullptr)
	{
		m_offeredTokens.reset(new Bag<fUML::Semantics::Activities::Token>());
		
		
	}
    return m_offeredTokens;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> OfferImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void OfferImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OfferImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("offeredTokens");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("offeredTokens")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void OfferImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void OfferImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::OFFER_ATTRIBUTE_OFFEREDTOKENS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> _offeredTokens = getOfferedTokens();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::Token>  _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(ref);
				if (_r != nullptr)
				{
					_offeredTokens->push_back(_r);
				}
			}
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void OfferImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void OfferImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
	// Add references
		saveHandler->addReferences<fUML::Semantics::Activities::Token>("offeredTokens", this->getOfferedTokens());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> OfferImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getOffer_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any OfferImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::OFFER_ATTRIBUTE_OFFEREDTOKENS:
			return eAnyBag(getOfferedTokens(),fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS); //840
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool OfferImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::OFFER_ATTRIBUTE_OFFEREDTOKENS:
			return getOfferedTokens() != nullptr; //840
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool OfferImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::OFFER_ATTRIBUTE_OFFEREDTOKENS:
		{
			// CAST Any to Bag<fUML::Semantics::Activities::Token>
			if((newValue->isContainer()) && (fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> offeredTokensList= newValue->get<std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>>();
					std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> _offeredTokens=getOfferedTokens();
					for(const std::shared_ptr<fUML::Semantics::Activities::Token> indexOfferedTokens: *_offeredTokens)
					{
						if (offeredTokensList->find(indexOfferedTokens) == -1)
						{
							_offeredTokens->erase(indexOfferedTokens);
						}
					}

					for(const std::shared_ptr<fUML::Semantics::Activities::Token> indexOfferedTokens: *offeredTokensList)
					{
						if (_offeredTokens->find(indexOfferedTokens) == -1)
						{
							_offeredTokens->add(indexOfferedTokens);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
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
Any OfferImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Activities::Offer::countOfferedVales() : int: 904773483
		case ActivitiesPackage::OFFER_OPERATION_COUNTOFFEREDVALES:
		{
			result = eAny(this->countOfferedVales(),0,false);
			break;
		}
		// fUML::Semantics::Activities::Offer::hasTokens() : bool: 3339319593
		case ActivitiesPackage::OFFER_OPERATION_HASTOKENS:
		{
			result = eAny(this->hasTokens(),0,false);
			break;
		}
		// fUML::Semantics::Activities::Offer::removeOfferedValues(int): 1313324759
		case ActivitiesPackage::OFFER_OPERATION_REMOVEOFFEREDVALUES_EINT:
		{
			//Retrieve input parameter 'count'
			//parameter 0
			int incoming_param_count;
			std::list<Any>::const_iterator incoming_param_count_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_count = (*incoming_param_count_arguments_citer)->get<int >();
			this->removeOfferedValues(incoming_param_count);
			break;
		}
		// fUML::Semantics::Activities::Offer::removeWithdrawnTokens(): 3955994697
		case ActivitiesPackage::OFFER_OPERATION_REMOVEWITHDRAWNTOKENS:
		{
			this->removeWithdrawnTokens();
			break;
		}
		// fUML::Semantics::Activities::Offer::retrieveOfferedTokens() : fUML::Semantics::Activities::Token[*]: 1383812745
		case ActivitiesPackage::OFFER_OPERATION_RETRIEVEOFFEREDTOKENS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > resultList = this->retrieveOfferedTokens();
			return eAnyBag(resultList,fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS);
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

std::shared_ptr<fUML::Semantics::Activities::Offer> OfferImpl::getThisOfferPtr() const
{
	return m_thisOfferPtr.lock();
}
void OfferImpl::setThisOfferPtr(std::weak_ptr<fUML::Semantics::Activities::Offer> thisOfferPtr)
{
	m_thisOfferPtr = thisOfferPtr;
}


