
#include "fUML/Semantics/Activities/impl/OfferImpl.hpp"
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
int OfferImpl::countOfferedValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->removeWithdrawnTokens();

    int count = 0;
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> offeredTokens= this->getOfferedTokens();

    for (const std::shared_ptr<fUML::Semantics::Activities::Token>& offeredToken: *offeredTokens) {
        if (offeredToken->getValue() != nullptr) {
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
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> offeredTokens= this->getOfferedTokens();
	Bag<fUML::Semantics::Activities::Token>::iterator it = offeredTokens->begin();
	
    while (count > 0) 
	{
        if ((*it)->getValue() != nullptr) 
		{
			Bag<fUML::Semantics::Activities::Token>::iterator delIt = it;
			it++;
            offeredTokens->erase(delIt);
        } 
		else 
		{
            it++;
        }
        count = count - 1;
    }
	//end of body
}

void OfferImpl::removeWithdrawnTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> offeredTokens= this->getOfferedTokens();
	Bag<fUML::Semantics::Activities::Token>::iterator it = offeredTokens->begin();
	Bag<fUML::Semantics::Activities::Token>::iterator endIt = offeredTokens->end();
	
	
	while(it != endIt)
	{
		if((*it)->isWithdrawn())
		{
			Bag<fUML::Semantics::Activities::Token>::iterator delIt = it;
			it++;
			offeredTokens->erase(delIt);
		}
		else
		{
			it++;
		}
	}
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> OfferImpl::retrieveOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->removeWithdrawnTokens();

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens(this->getOfferedTokens());

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
std::shared_ptr<Any> OfferImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::OFFER_ATTRIBUTE_OFFEREDTOKENS:
			return eEcoreContainerAny(getOfferedTokens(),fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS); //830
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool OfferImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::OFFER_ATTRIBUTE_OFFEREDTOKENS:
			return getOfferedTokens() != nullptr; //830
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool OfferImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::OFFER_ATTRIBUTE_OFFEREDTOKENS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> _offeredTokens = getOfferedTokens();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<fUML::Semantics::Activities::Token> valueToAdd = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(anEObject);
	
							if (valueToAdd)
							{
								if(_offeredTokens->find(valueToAdd) == -1)
								{
									_offeredTokens->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'offeredTokens'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'offeredTokens'. Failed to set feature!")
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
std::shared_ptr<Any> OfferImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Activities::Offer::countOfferedValues() : int: 1884613252
		case ActivitiesPackage::OFFER_OPERATION_COUNTOFFEREDVALUES:
		{
			result = eAny(this->countOfferedValues(), 0, false);
			break;
		}
		// fUML::Semantics::Activities::Offer::hasTokens() : bool: 3339319593
		case ActivitiesPackage::OFFER_OPERATION_HASTOKENS:
		{
			result = eAny(this->hasTokens(), 0, false);
			break;
		}
		// fUML::Semantics::Activities::Offer::removeOfferedValues(int): 1313324759
		case ActivitiesPackage::OFFER_OPERATION_REMOVEOFFEREDVALUES_EINT:
		{
			//Retrieve input parameter 'count'
			//parameter 0
			int incoming_param_count;
			Bag<Any>::const_iterator incoming_param_count_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_count = (*incoming_param_count_arguments_citer)->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'count'. Failed to invoke operation 'removeOfferedValues'!")
				return nullptr;
			}
		
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
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> resultList = this->retrieveOfferedTokens();
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

std::shared_ptr<fUML::Semantics::Activities::Offer> OfferImpl::getThisOfferPtr() const
{
	return m_thisOfferPtr.lock();
}
void OfferImpl::setThisOfferPtr(std::weak_ptr<fUML::Semantics::Activities::Offer> thisOfferPtr)
{
	m_thisOfferPtr = thisOfferPtr;
}


