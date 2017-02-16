#include "EventDispatchLoopImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
EventDispatchLoopImpl::EventDispatchLoopImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

EventDispatchLoopImpl::~EventDispatchLoopImpl()
{
	
}

EventDispatchLoopImpl::EventDispatchLoopImpl(const EventDispatchLoopImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
}

ecore::EObject *  EventDispatchLoopImpl::copy() const
{
	return new EventDispatchLoopImpl(*this);
}

ecore::EClass* EventDispatchLoopImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getEventDispatchLoop();
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
