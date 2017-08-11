#include "TokenSetImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
TokenSetImpl::TokenSetImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_tokens.reset(new Bag<fUML::Token>());
	
	

	//Init references
	
	
}

TokenSetImpl::~TokenSetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TokenSet "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

TokenSetImpl::TokenSetImpl(const TokenSetImpl & obj):TokenSetImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TokenSet "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<fUML::Token> > _tokens = obj.getTokens();
	m_tokens.reset(new Bag<fUML::Token>(*(obj.getTokens().get())));


    
	//Clone references with containment (deep copy)



}

ecore::EObject *  TokenSetImpl::copy() const
{
	return new TokenSetImpl(*this);
}

std::shared_ptr<ecore::EClass> TokenSetImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getTokenSet();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr< Bag<fUML::Token> > TokenSetImpl::getTokens() const
{

    return m_tokens;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TokenSetImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::TOKENSET_TOKENS:
			return getTokens(); //740
	}
	return boost::any();
}
