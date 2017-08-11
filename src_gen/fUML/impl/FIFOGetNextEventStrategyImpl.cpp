#include "FIFOGetNextEventStrategyImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "GetNextEventStrategy.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
FIFOGetNextEventStrategyImpl::FIFOGetNextEventStrategyImpl()
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

FIFOGetNextEventStrategyImpl::~FIFOGetNextEventStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FIFOGetNextEventStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

FIFOGetNextEventStrategyImpl::FIFOGetNextEventStrategyImpl(const FIFOGetNextEventStrategyImpl & obj):FIFOGetNextEventStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FIFOGetNextEventStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

    
	//Clone references with containment (deep copy)



}

ecore::EObject *  FIFOGetNextEventStrategyImpl::copy() const
{
	return new FIFOGetNextEventStrategyImpl(*this);
}

std::shared_ptr<ecore::EClass> FIFOGetNextEventStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getFIFOGetNextEventStrategy();
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
boost::any FIFOGetNextEventStrategyImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}
