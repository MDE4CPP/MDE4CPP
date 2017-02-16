#include "ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl()
{
	//*********************************
	// Reference Members
	//*********************************

}

ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::~ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl()
{
	
}

ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl(const ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
}

ecore::EObject *  ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::copy() const
{
	return new ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl(*this);
}

ecore::EClass* ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::eStaticClass() const
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
