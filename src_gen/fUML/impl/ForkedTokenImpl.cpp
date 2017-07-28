#include "ForkedTokenImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
 

//Forward declaration includes
#include "ActivityNodeActivation.hpp";

#include "Token.hpp";

#include "Value.hpp";


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ForkedTokenImpl::ForkedTokenImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	//Init references
	
}

ForkedTokenImpl::~ForkedTokenImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ForkedToken "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ForkedTokenImpl::ForkedTokenImpl(const ForkedTokenImpl & obj):ForkedTokenImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ForkedToken "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_baseTokenIsWithdrawn = obj.isBaseTokenIsWithdrawn();
	m_remainingOffersCount = obj.getRemainingOffersCount();

	//copy references with no containment (soft copy)
	
	m_baseToken  = obj.getBaseToken();

	m_holder  = obj.getHolder();


    
	//Clone references with containment (deep copy)



}

ecore::EObject *  ForkedTokenImpl::copy() const
{
	return new ForkedTokenImpl(*this);
}

std::shared_ptr<ecore::EClass> ForkedTokenImpl::eStaticClass() const
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
bool
 ForkedTokenImpl::equals(std::shared_ptr<fUML::Token>  otherToken) 
{
	//generated from body annotation
	return (this == otherToken.get());
}

std::shared_ptr<fUML::Value> 
 ForkedTokenImpl::getValue()  const 
{
	//generated from body annotation
	return this->getBaseToken()->getValue();
}

bool
 ForkedTokenImpl::isControl() 
{
	//generated from body annotation
	return this->getBaseToken()->isControl();
}

void
 ForkedTokenImpl::withdraw() 
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
std::shared_ptr<fUML::Token > ForkedTokenImpl::getBaseToken() const
{

    return m_baseToken;
}
void ForkedTokenImpl::setBaseToken(std::shared_ptr<fUML::Token> _baseToken)
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
