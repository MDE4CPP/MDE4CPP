#include "fUML/impl/GetNextEventStrategyImpl.hpp"

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
#include "fUML/ObjectActivation.hpp"

#include "fUML/SemanticStrategy.hpp"

#include "fUML/SignalInstance.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
GetNextEventStrategyImpl::GetNextEventStrategyImpl()
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

GetNextEventStrategyImpl::~GetNextEventStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete GetNextEventStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




GetNextEventStrategyImpl::GetNextEventStrategyImpl(const GetNextEventStrategyImpl & obj):GetNextEventStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy GetNextEventStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  GetNextEventStrategyImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new GetNextEventStrategyImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> GetNextEventStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getGetNextEventStrategy_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::SignalInstance> GetNextEventStrategyImpl::retrieveNextEvent(std::shared_ptr<fUML::ObjectActivation>  objectActivation) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<GetNextEventStrategy> GetNextEventStrategyImpl::getThisGetNextEventStrategyPtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<GetNextEventStrategy>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> GetNextEventStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any GetNextEventStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}

void GetNextEventStrategyImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
