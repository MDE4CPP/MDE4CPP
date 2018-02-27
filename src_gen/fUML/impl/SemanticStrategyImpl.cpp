#include "fUML/impl/SemanticStrategyImpl.hpp"

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

std::shared_ptr<ecore::EObject>  SemanticStrategyImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new SemanticStrategyImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> SemanticStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getSemanticStrategy_EClass();
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


std::shared_ptr<SemanticStrategy> SemanticStrategyImpl::getThisSemanticStrategyPtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<SemanticStrategy>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> SemanticStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any SemanticStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}

void SemanticStrategyImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
