#include "fUML/impl/OfferImpl.hpp"

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

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

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
OfferImpl::OfferImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_offeredTokens.reset(new Bag<fUML::Token>());
	
	

	//Init references
	
	
}

OfferImpl::~OfferImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Offer "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




OfferImpl::OfferImpl(const OfferImpl & obj):OfferImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Offer "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<fUML::Token>> _offeredTokens = obj.getOfferedTokens();
	m_offeredTokens.reset(new Bag<fUML::Token>(*(obj.getOfferedTokens().get())));


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  OfferImpl::copy() const
{
	std::shared_ptr<OfferImpl> element(new OfferImpl(*this));
	element->setThisOfferPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OfferImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getOffer_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

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
	 std::shared_ptr< Bag<fUML::Token> > offeredTokens= this->getOfferedTokens();
    Bag<fUML::Token> *offeredTokensPtr=offeredTokens.get();

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
        Bag<fUML::Token> *new_OfferedTokensPtr = new Bag<fUML::Token>();
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

std::shared_ptr<Bag<fUML::Token> > OfferImpl::retrieveOfferedTokens() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->removeWithdrawnTokens();

	std::shared_ptr<Bag<Token> > tokens(new Bag<Token>());
	std::shared_ptr<Bag<Token> > offeredTokens = this->getOfferedTokens();
    for (unsigned int i = 0; i < this->getOfferedTokens()->size(); i++)
    {
    	std::shared_ptr<Token> offeredToken = offeredTokens->at(i);
        tokens->push_back(offeredToken);
    }

    return tokens;
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<fUML::Token>> OfferImpl::getOfferedTokens() const
{

    return m_offeredTokens;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<Offer> OfferImpl::getThisOfferPtr()
{
	return m_thisOfferPtr.lock();
}
void OfferImpl::setThisOfferPtr(std::weak_ptr<Offer> thisOfferPtr)
{
	m_thisOfferPtr = thisOfferPtr;
}
std::shared_ptr<ecore::EObject> OfferImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any OfferImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::OFFER_EREFERENCE_OFFEREDTOKENS:
			return getOfferedTokens(); //520
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool OfferImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::OFFER_EREFERENCE_OFFEREDTOKENS:
			return getOfferedTokens() != nullptr; //520
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool OfferImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
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
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void OfferImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void OfferImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::OFFER_EREFERENCE_OFFEREDTOKENS:
		{
			std::shared_ptr<Bag<fUML::Token>> _offeredTokens = getOfferedTokens();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Token> _r = std::dynamic_pointer_cast<fUML::Token>(ref);
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
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<fUML::Token>> offeredTokens_list = this->getOfferedTokens();
		for (std::shared_ptr<fUML::Token > object : *offeredTokens_list)
		{ 
			saveHandler->addReferences("offeredTokens", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

