#include "ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl.hpp"
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

ecore::EObject *  ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::copy() const
{
	return new ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl(*this);
}

std::shared_ptr<ecore::EClass> ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1();
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
boost::any ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}
