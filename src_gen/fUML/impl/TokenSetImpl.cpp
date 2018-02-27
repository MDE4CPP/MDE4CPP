#include "fUML/impl/TokenSetImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "fUML/Token.hpp"


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
	
	std::shared_ptr<Bag<fUML::Token>> _tokens = obj.getTokens();
	m_tokens.reset(new Bag<fUML::Token>(*(obj.getTokens().get())));


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  TokenSetImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new TokenSetImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> TokenSetImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getTokenSet_EClass();
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
std::shared_ptr<Bag<fUML::Token>> TokenSetImpl::getTokens() const
{

    return m_tokens;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<TokenSet> TokenSetImpl::getThisTokenSetPtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<TokenSet>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> TokenSetImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TokenSetImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::TOKENSET_EREFERENCE_TOKENS:
			return getTokens(); //740
	}
	return boost::any();
}

void TokenSetImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
