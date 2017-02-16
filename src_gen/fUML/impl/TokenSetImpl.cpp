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
	// Reference Members
	//*********************************
	if( m_tokens == nullptr)
	{
		m_tokens = new std::vector<fUML::Token * >();
	}
}

TokenSetImpl::~TokenSetImpl()
{
	if(m_tokens!=nullptr)
	{
		delete(m_tokens);
	 	m_tokens = nullptr;
	}
	
}

TokenSetImpl::TokenSetImpl(const TokenSetImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::vector<fUML::Token * > *  _tokens = obj.getTokens();
	this->getTokens()->insert(this->getTokens()->end(), _tokens->begin(), _tokens->end());


	//clone containt lists
}

ecore::EObject *  TokenSetImpl::copy() const
{
	return new TokenSetImpl(*this);
}

ecore::EClass* TokenSetImpl::eStaticClass() const
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
std::vector<fUML::Token * > *  TokenSetImpl::getTokens() const
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
