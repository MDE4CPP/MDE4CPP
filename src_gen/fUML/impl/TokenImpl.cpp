#include "TokenImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

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
	
}

TokenImpl::~TokenImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Token "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

TokenImpl::TokenImpl(const TokenImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_holder  = obj.getHolder();


	//clone containt lists
}

ecore::EObject *  TokenImpl::copy() const
{
	return new TokenImpl(*this);
}

std::shared_ptr<ecore::EClass> TokenImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getToken();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool TokenImpl::equals(std::shared_ptr<fUML::Token>  other) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::Value>  TokenImpl::getValue()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TokenImpl::isControl() 
{
	//generated from body annotation
	return dynamic_cast<fUML::ControlToken*>(this) != nullptr;
}

bool TokenImpl::isWithdrawn() 
{
	//generated from body annotation
	    return (this->getHolder()==nullptr);
}

std::shared_ptr<fUML::Token>  TokenImpl::transfer(std::shared_ptr<fUML::ActivityNodeActivation>  holder) 
{
	//generated from body annotation
	struct null_deleter{void operator()(void const *) const { } };
	std::shared_ptr<fUML::Token> token = std::shared_ptr<Token>(this, null_deleter());
    if (this->getHolder() != nullptr) 
    {
        this->withdraw();
        token = std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(this->copy()));
    }

    token->setHolder(holder);
    return token;
}

void TokenImpl::withdraw() 
{
	//generated from body annotation
	if (!this->isWithdrawn()) 
	{
		struct null_deleter{void operator()(void const *) const { } };
		std::shared_ptr<fUML::ActivityNodeActivation> holder = this->getHolder();
        this->setHolder(nullptr);
		if (holder)
		{
			holder->removeToken(std::shared_ptr<Token>(this, null_deleter()));
		}
    }
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::ActivityNodeActivation> TokenImpl::getHolder() const
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
	}
	return boost::any();
}
