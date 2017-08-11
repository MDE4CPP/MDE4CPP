#include "EventDispatchLoopImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
EventDispatchLoopImpl::EventDispatchLoopImpl()
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

EventDispatchLoopImpl::~EventDispatchLoopImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EventDispatchLoop "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

EventDispatchLoopImpl::EventDispatchLoopImpl(const EventDispatchLoopImpl & obj):EventDispatchLoopImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EventDispatchLoop "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

    
	//Clone references with containment (deep copy)



}

ecore::EObject *  EventDispatchLoopImpl::copy() const
{
	return new EventDispatchLoopImpl(*this);
}

std::shared_ptr<ecore::EClass> EventDispatchLoopImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getEventDispatchLoop();
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

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EventDispatchLoopImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}
