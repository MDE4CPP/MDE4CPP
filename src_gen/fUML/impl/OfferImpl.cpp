#include "OfferImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"

//Forward declaration includes
#include "Token.hpp"


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
	//generated from body annotation
	    this->removeWithdrawnTokens();
    return (this->getOfferedTokens()->size() > 0);
	//end of body
}

void OfferImpl::removeOfferedValues(int count) 
{
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
	//generated from body annotation
	    unsigned int i = 0;
    while (i < this->getOfferedTokens()->size()) {
        if (this->getOfferedTokens()->at(i)->isWithdrawn()) {
            this->getOfferedTokens()->erase(this->getOfferedTokens()->begin() + i );
            i = i - 1;
        }
        i = i + 1;
    }
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > OfferImpl::retrieveOfferedTokens() 
{
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any OfferImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::OFFER_OFFEREDTOKENS:
			return getOfferedTokens(); //520
	}
	return boost::any();
}
