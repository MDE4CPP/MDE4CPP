#include "fUML/impl/ControlTokenImpl.hpp"

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
#include "fuml/FUMLFactory.hpp"

//Forward declaration includes
#include "fUML/ActivityNodeActivation.hpp"

#include "fUML/Token.hpp"

#include "fUML/Value.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ControlTokenImpl::ControlTokenImpl()
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

ControlTokenImpl::~ControlTokenImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ControlToken "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ControlTokenImpl::ControlTokenImpl(const ControlTokenImpl & obj):ControlTokenImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ControlToken "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_withdrawn = obj.isWithdrawn();

	//copy references with no containment (soft copy)
	
	m_holder  = obj.getHolder();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ControlTokenImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ControlTokenImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ControlTokenImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getControlToken_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ControlTokenImpl::equals(std::shared_ptr<fUML::Token>  other) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return (std::dynamic_pointer_cast<ControlToken>(other) != nullptr);
	//end of body
}

std::shared_ptr<fUML::Value> ControlTokenImpl::getValue()  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return nullptr;
	//end of body
}

bool ControlTokenImpl::isControl() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		return true;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ControlToken> ControlTokenImpl::getThisControlTokenPtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<ControlToken>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> ControlTokenImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ControlTokenImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::TOKEN_EREFERENCE_HOLDER:
			return getHolder(); //560
		case FUMLPackage::TOKEN_EATTRIBUTE_WITHDRAWN:
			return isWithdrawn(); //561
	}
	return boost::any();
}

void ControlTokenImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::TOKEN_EREFERENCE_HOLDER:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivation> _holder = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivation>>(newValue);
			setHolder(_holder); //560
			break;
		}
		case FUMLPackage::TOKEN_EATTRIBUTE_WITHDRAWN:
		{
			// BOOST CAST
			bool _withdrawn = boost::any_cast<bool>(newValue);
			setWithdrawn(_withdrawn); //561
			break;
		}
	}
}
