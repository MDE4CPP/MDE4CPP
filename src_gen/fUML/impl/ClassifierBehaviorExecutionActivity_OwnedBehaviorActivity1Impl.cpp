#include "fUML/impl/ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl.hpp"

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
ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl()
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

ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::~ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl(const ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl & obj):ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1_EClass();
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


std::shared_ptr<ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1> ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::getThisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}

void ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
