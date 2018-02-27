#include "fUML/impl/ForkedTokenImpl.hpp"

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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
 

//Forward declaration includes
#include "fUML/ActivityNodeActivation.hpp"

#include "fUML/Token.hpp"

#include "fUML/Value.hpp"


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
	m_withdrawn = obj.isWithdrawn();

	//copy references with no containment (soft copy)
	
	m_baseToken  = obj.getBaseToken();

	m_holder  = obj.getHolder();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ForkedTokenImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ForkedTokenImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ForkedTokenImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getForkedToken_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ForkedTokenImpl::setBaseTokenIsWithdrawn(bool _baseTokenIsWithdrawn)
{
	m_baseTokenIsWithdrawn = _baseTokenIsWithdrawn;
} 

bool ForkedTokenImpl::isBaseTokenIsWithdrawn() const 
{
	return m_baseTokenIsWithdrawn;
}

void ForkedTokenImpl::setRemainingOffersCount(int _remainingOffersCount)
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
bool ForkedTokenImpl::equals(std::shared_ptr<fUML::Token>  otherToken) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return (this == otherToken.get());
	//end of body
}

std::shared_ptr<fUML::Value> ForkedTokenImpl::getValue()  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getBaseToken()->getValue();
	//end of body
}

bool ForkedTokenImpl::isControl() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getBaseToken()->isControl();
	//end of body
}

void ForkedTokenImpl::withdraw() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//end of body
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


std::shared_ptr<ForkedToken> ForkedTokenImpl::getThisForkedTokenPtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<ForkedToken>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> ForkedTokenImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ForkedTokenImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::FORKEDTOKEN_EREFERENCE_BASETOKEN:
			return getBaseToken(); //552
		case FUMLPackage::FORKEDTOKEN_EATTRIBUTE_BASETOKENISWITHDRAWN:
			return isBaseTokenIsWithdrawn(); //554
		case FUMLPackage::TOKEN_EREFERENCE_HOLDER:
			return getHolder(); //550
		case FUMLPackage::FORKEDTOKEN_EATTRIBUTE_REMAININGOFFERSCOUNT:
			return getRemainingOffersCount(); //553
		case FUMLPackage::TOKEN_EATTRIBUTE_WITHDRAWN:
			return isWithdrawn(); //551
	}
	return boost::any();
}

void ForkedTokenImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::FORKEDTOKEN_EREFERENCE_BASETOKEN:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Token> _baseToken = boost::any_cast<std::shared_ptr<fUML::Token>>(newValue);
			setBaseToken(_baseToken); //552
			break;
		}
		case FUMLPackage::FORKEDTOKEN_EATTRIBUTE_BASETOKENISWITHDRAWN:
		{
			// BOOST CAST
			bool _baseTokenIsWithdrawn = boost::any_cast<bool>(newValue);
			setBaseTokenIsWithdrawn(_baseTokenIsWithdrawn); //554
			break;
		}
		case FUMLPackage::TOKEN_EREFERENCE_HOLDER:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivation> _holder = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivation>>(newValue);
			setHolder(_holder); //550
			break;
		}
		case FUMLPackage::FORKEDTOKEN_EATTRIBUTE_REMAININGOFFERSCOUNT:
		{
			// BOOST CAST
			int _remainingOffersCount = boost::any_cast<int>(newValue);
			setRemainingOffersCount(_remainingOffersCount); //553
			break;
		}
		case FUMLPackage::TOKEN_EATTRIBUTE_WITHDRAWN:
		{
			// BOOST CAST
			bool _withdrawn = boost::any_cast<bool>(newValue);
			setWithdrawn(_withdrawn); //551
			break;
		}
	}
}
