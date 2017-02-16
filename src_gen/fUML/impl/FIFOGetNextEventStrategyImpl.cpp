#include "FIFOGetNextEventStrategyImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
FIFOGetNextEventStrategyImpl::FIFOGetNextEventStrategyImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

FIFOGetNextEventStrategyImpl::~FIFOGetNextEventStrategyImpl()
{
	
}

FIFOGetNextEventStrategyImpl::FIFOGetNextEventStrategyImpl(const FIFOGetNextEventStrategyImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
}

ecore::EObject *  FIFOGetNextEventStrategyImpl::copy() const
{
	return new FIFOGetNextEventStrategyImpl(*this);
}

ecore::EClass* FIFOGetNextEventStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getFIFOGetNextEventStrategy();
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
boost::any FIFOGetNextEventStrategyImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}
