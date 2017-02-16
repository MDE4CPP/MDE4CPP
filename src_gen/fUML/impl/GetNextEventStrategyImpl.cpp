#include "GetNextEventStrategyImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
GetNextEventStrategyImpl::GetNextEventStrategyImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

GetNextEventStrategyImpl::~GetNextEventStrategyImpl()
{
	
}

GetNextEventStrategyImpl::GetNextEventStrategyImpl(const GetNextEventStrategyImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
}

ecore::EObject *  GetNextEventStrategyImpl::copy() const
{
	return new GetNextEventStrategyImpl(*this);
}

ecore::EClass* GetNextEventStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getGetNextEventStrategy();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::SignalInstance *  GetNextEventStrategyImpl::retrieveNextEvent(fUML::ObjectActivation *  objectActivation) 
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
boost::any GetNextEventStrategyImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}
