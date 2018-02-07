#include "fUML/impl/OfferImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "fUML/Token.hpp"


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
	
	std::shared_ptr< Bag<fUML::Token> > _offeredTokens = obj.getOfferedTokens();
	m_offeredTokens.reset(new Bag<fUML::Token>(*(obj.getOfferedTokens().get())));


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  OfferImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new OfferImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> OfferImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getOffer();
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
std::shared_ptr< Bag<fUML::Token> > OfferImpl::getOfferedTokens() const
{

    return m_offeredTokens;
}


//*********************************
// Union Getter
//*********************************


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
		case FUMLPackage::OFFER_OFFEREDTOKENS:
			return getOfferedTokens(); //520
	}
	return boost::any();
}

void OfferImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
