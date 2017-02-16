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
	// Reference Members
	//*********************************
	
}

TokenImpl::~TokenImpl()
{
	
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

ecore::EClass* TokenImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getToken();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool TokenImpl::equals(fUML::Token *  other) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

fUML::Value *  TokenImpl::getValue()  const 
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

fUML::Token *  TokenImpl::transfer(fUML::ActivityNodeActivation *  holder) 
{
	//generated from body annotation
	 fUML::Token * token = this;
    if (this->getHolder() != nullptr) {
        this->withdraw();
        token = dynamic_cast<fUML::Token *>(this->copy());
    }

    token->setHolder(holder);
    return token;

}

void TokenImpl::withdraw() 
{
	//generated from body annotation
	    if (!this->isWithdrawn()) {
        this->getHolder()->removeToken(this);
        this->setHolder(nullptr);
    }
}

//*********************************
// References
//*********************************
fUML::ActivityNodeActivation *  TokenImpl::getHolder() const
{
	
	return m_holder;
}
void TokenImpl::setHolder(fUML::ActivityNodeActivation *  _holder)
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
