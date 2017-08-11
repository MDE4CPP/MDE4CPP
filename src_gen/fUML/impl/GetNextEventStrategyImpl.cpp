#include "GetNextEventStrategyImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "ObjectActivation.hpp"

#include "SemanticStrategy.hpp"

#include "SignalInstance.hpp"


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

ecore::EObject *  GetNextEventStrategyImpl::copy() const
{
	return new GetNextEventStrategyImpl(*this);
}

std::shared_ptr<ecore::EClass> GetNextEventStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getGetNextEventStrategy();
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
