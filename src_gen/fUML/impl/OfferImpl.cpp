#include "OfferImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
OfferImpl::OfferImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_offeredTokens == nullptr)
	{
		m_offeredTokens = new std::vector<fUML::Token * >();
	}
}

OfferImpl::~OfferImpl()
{
	if(m_offeredTokens!=nullptr)
	{
		delete(m_offeredTokens);
	 	m_offeredTokens = nullptr;
	}
	
}

OfferImpl::OfferImpl(const OfferImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::vector<fUML::Token * > *  _offeredTokens = obj.getOfferedTokens();
	this->getOfferedTokens()->insert(this->getOfferedTokens()->end(), _offeredTokens->begin(), _offeredTokens->end());


	//clone containt lists
}

ecore::EObject *  OfferImpl::copy() const
{
	return new OfferImpl(*this);
}

ecore::EClass* OfferImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getOffer();
}

//*********************************
// Attribute Setter Gettter
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
}

bool OfferImpl::hasTokens() 
{
	//generated from body annotation
	    this->removeWithdrawnTokens();
    return (this->getOfferedTokens()->size() > 0);
}

void OfferImpl::removeOfferedValues(int count) 
{
	//generated from body annotation
	    int n = count;
    int i = 1;
    while (n > 0) {
        if (this->getOfferedTokens()->at(i - 1)->getValue() != nullptr) {
            this->getOfferedTokens()->erase(this->getOfferedTokens()->begin() + i - 1);
        } else {
            i = i + 1;
        }
        n = n - 1;
    }
}

void OfferImpl::removeWithdrawnTokens() 
{
	//generated from body annotation
	    unsigned int i = 1;
    while (i <= this->getOfferedTokens()->size()) {
        if (this->getOfferedTokens()->at(i - 1)->isWithdrawn()) {
            this->getOfferedTokens()->erase(this->getOfferedTokens()->begin() + i - 1);
            i = i - 1;
        }
        i = i + 1;
    }
}

std::vector<fUML::Token * > *  OfferImpl::retrieveOfferedTokens() 
{
	//generated from body annotation
	    this->removeWithdrawnTokens();

    std::vector<Token*>* tokens = new std::vector<Token*>();
    std::vector<Token*>* offeredTokens = this->getOfferedTokens();
    for (unsigned int i = 0; i < this->getOfferedTokens()->size(); i++) {
        Token * offeredToken = offeredTokens->at(i);
        tokens->push_back(offeredToken);
    }

    return tokens;
}

//*********************************
// References
//*********************************
std::vector<fUML::Token * > *  OfferImpl::getOfferedTokens() const
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
