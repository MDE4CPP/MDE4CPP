#include "EventAccepterImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
EventAccepterImpl::EventAccepterImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

EventAccepterImpl::~EventAccepterImpl()
{
	
}

EventAccepterImpl::EventAccepterImpl(const EventAccepterImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
}

ecore::EObject *  EventAccepterImpl::copy() const
{
	return new EventAccepterImpl(*this);
}

ecore::EClass* EventAccepterImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getEventAccepter();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void EventAccepterImpl::accept(fUML::SignalInstance *  signalInstance) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool EventAccepterImpl::match(fUML::SignalInstance *  signalInstance) 
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EventAccepterImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}
