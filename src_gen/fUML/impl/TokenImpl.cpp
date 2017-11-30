#include "TokenImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"

//Forward declaration includes
#include "ActivityNodeActivation.hpp"

#include "Token.hpp"

#include "Value.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
TokenImpl::TokenImpl()
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

TokenImpl::~TokenImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Token "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




TokenImpl::TokenImpl(const TokenImpl & obj):TokenImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Token "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_withdrawn = obj.isWithdrawn();

	//copy references with no containment (soft copy)
	
	m_holder  = obj.getHolder();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  TokenImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new TokenImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> TokenImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getToken();
}

//*********************************
// Attribute Setter Getter
//*********************************
void TokenImpl::setWithdrawn(bool _withdrawn)
{
	m_withdrawn = _withdrawn;
} 

bool TokenImpl::isWithdrawn() const 
{
	return m_withdrawn;
}

//*********************************
// Operations
//*********************************
bool TokenImpl::equals(std::shared_ptr<fUML::Token>  other) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::Value> TokenImpl::getValue()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TokenImpl::isControl() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return dynamic_cast<fUML::ControlToken*>(this) != nullptr;
	//end of body
}

std::shared_ptr<fUML::Token> TokenImpl::transfer(std::shared_ptr<fUML::ActivityNodeActivation>  holder) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::shared_ptr<fUML::Token> token = shared_from_this();
    if (!this->isWithdrawn())
    {
        this->withdraw();
        token = std::dynamic_pointer_cast<fUML::Token>(this->copy());
    }

    token->setHolder(holder);
	token->setWithdrawn(false);
    return token;
	//end of body
}

void TokenImpl::withdraw() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		if (!this->isWithdrawn()) 
	{
		std::shared_ptr<fUML::ActivityNodeActivation> holder = this->getHolder().lock();
        this->setHolder(nullptr);
		this->setWithdrawn(true);
		if (holder)
		{
			holder->removeToken(shared_from_this());
		}
    }
	//end of body
}

//*********************************
// References
//*********************************
std::weak_ptr<fUML::ActivityNodeActivation > TokenImpl::getHolder() const
{

    return m_holder;
}
void TokenImpl::setHolder(std::shared_ptr<fUML::ActivityNodeActivation> _holder)
{
    m_holder = _holder;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TokenImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::TOKEN_HOLDER:
			return getHolder(); //530
		case FUMLPackage::TOKEN_WITHDRAWN:
			return isWithdrawn(); //531
	}
	return boost::any();
}
