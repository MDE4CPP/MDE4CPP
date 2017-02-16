#include "ForkedTokenImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
 

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ForkedTokenImpl::ForkedTokenImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

ForkedTokenImpl::~ForkedTokenImpl()
{
	
}

ForkedTokenImpl::ForkedTokenImpl(const ForkedTokenImpl & obj)
{
	//create copy of all Attributes
	m_baseTokenIsWithdrawn = obj.isBaseTokenIsWithdrawn();
	m_remainingOffersCount = obj.getRemainingOffersCount();

	//copy references with now containment
	
	m_baseToken  = obj.getBaseToken();

	m_holder  = obj.getHolder();


	//clone containt lists
}

ecore::EObject *  ForkedTokenImpl::copy() const
{
	return new ForkedTokenImpl(*this);
}

ecore::EClass* ForkedTokenImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getForkedToken();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ForkedTokenImpl::setBaseTokenIsWithdrawn (bool _baseTokenIsWithdrawn)
{
	m_baseTokenIsWithdrawn = _baseTokenIsWithdrawn;
} 

bool ForkedTokenImpl::isBaseTokenIsWithdrawn() const 
{
	return m_baseTokenIsWithdrawn;
}

void ForkedTokenImpl::setRemainingOffersCount (int _remainingOffersCount)
{
	m_remainingOffersCount = _remainingOffersCount;
} 

int ForkedTokenImpl::getRemainingOffersCount() const 
{
	return m_remainingOffersCount;
}

//*********************************
// Operations
//*********************************
bool ForkedTokenImpl::equals(fUML::Token *  otherToken) 
{
	//generated from body annotation
	return this == otherToken;
}

fUML::Value *  ForkedTokenImpl::getValue()  const 
{
	//generated from body annotation
	return this->getBaseToken()->getValue();
}

bool ForkedTokenImpl::isControl() 
{
	//generated from body annotation
	return this->getBaseToken()->isControl();
}

void ForkedTokenImpl::withdraw() 
{
	//generated from body annotation
	    if (!this->isBaseTokenIsWithdrawn() & !this->getBaseToken()->isWithdrawn()) {
        this->getBaseToken()->withdraw();
        this->setBaseTokenIsWithdrawn(true);
    }

    if (this->getRemainingOffersCount() > 0) {
        this->setRemainingOffersCount(this->getRemainingOffersCount() - 1);
    }

    if (this->getRemainingOffersCount() == 0) {
        TokenImpl::withdraw();
    }
}

//*********************************
// References
//*********************************
fUML::Token *  ForkedTokenImpl::getBaseToken() const
{
	
	return m_baseToken;
}
void ForkedTokenImpl::setBaseToken(fUML::Token *  _baseToken)
{
	m_baseToken = _baseToken;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ForkedTokenImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::FORKEDTOKEN_BASETOKEN:
			return getBaseToken(); //551
		case FUMLPackage::FORKEDTOKEN_BASETOKENISWITHDRAWN:
			return isBaseTokenIsWithdrawn(); //553
		case FUMLPackage::TOKEN_HOLDER:
			return getHolder(); //550
		case FUMLPackage::FORKEDTOKEN_REMAININGOFFERSCOUNT:
			return getRemainingOffersCount(); //552
	}
	return boost::any();
}
