#include "fUML/impl/EventAccepterImpl.hpp"

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
#include "fUML/SignalInstance.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
EventAccepterImpl::EventAccepterImpl()
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

EventAccepterImpl::~EventAccepterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EventAccepter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




EventAccepterImpl::EventAccepterImpl(const EventAccepterImpl & obj):EventAccepterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EventAccepter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  EventAccepterImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EventAccepterImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> EventAccepterImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getEventAccepter_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void EventAccepterImpl::accept(std::shared_ptr<fUML::SignalInstance>  signalInstance) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool EventAccepterImpl::match(std::shared_ptr<fUML::SignalInstance>  signalInstance) 
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


std::shared_ptr<EventAccepter> EventAccepterImpl::getThisEventAccepterPtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<EventAccepter>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> EventAccepterImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EventAccepterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}

void EventAccepterImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
