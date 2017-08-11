#include "SemanticStrategyImpl.hpp"
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
SemanticStrategyImpl::SemanticStrategyImpl()
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

SemanticStrategyImpl::~SemanticStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SemanticStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

SemanticStrategyImpl::SemanticStrategyImpl(const SemanticStrategyImpl & obj):SemanticStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SemanticStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

    
	//Clone references with containment (deep copy)



}

ecore::EObject *  SemanticStrategyImpl::copy() const
{
	return new SemanticStrategyImpl(*this);
}

std::shared_ptr<ecore::EClass> SemanticStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getSemanticStrategy();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::string SemanticStrategyImpl::retrieveName() 
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
boost::any SemanticStrategyImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}
