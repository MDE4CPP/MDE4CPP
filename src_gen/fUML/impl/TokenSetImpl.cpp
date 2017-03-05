#include "TokenSetImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

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
	m_tokens.reset(new std::vector<std::shared_ptr<fUML::Token>>());
}

TokenSetImpl::~TokenSetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TokenSet "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

TokenSetImpl::TokenSetImpl(const TokenSetImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> _tokens = obj.getTokens();
	this->getTokens()->insert(this->getTokens()->end(), _tokens->begin(), _tokens->end());


	//clone containt lists
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
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> TokenSetImpl::getTokens() const
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
