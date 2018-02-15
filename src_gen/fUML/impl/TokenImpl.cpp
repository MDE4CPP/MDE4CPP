#include "fUML/impl/TokenImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fuml/ControlToken.hpp"
#include "fuml/ExecutionFactory.hpp"
#include "fuml/Locus.hpp"

//Forward declaration includes
#include "fUML/ActivityNodeActivation.hpp"

#include "fUML/Token.hpp"

#include "fUML/Value.hpp"


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
	return FUMLPackageImpl::eInstance()->getToken_EClass();
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


std::shared_ptr<ecore::EObject> TokenImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TokenImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::TOKEN_EREFERENCE_HOLDER:
			return getHolder(); //530
		case FUMLPackage::TOKEN_EATTRIBUTE_WITHDRAWN:
			return isWithdrawn(); //531
	}
	return boost::any();
}

void TokenImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::TOKEN_EREFERENCE_HOLDER:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivation> _holder = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivation>>(newValue);
			setHolder(_holder); //530
			break;
		}
		case FUMLPackage::TOKEN_EATTRIBUTE_WITHDRAWN:
		{
			// BOOST CAST
			bool _withdrawn = boost::any_cast<bool>(newValue);
			setWithdrawn(_withdrawn); //531
			break;
		}
	}
}
