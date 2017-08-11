#include "ClassifierBehaviorExecutionActivityImpl.hpp"
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
ClassifierBehaviorExecutionActivityImpl::ClassifierBehaviorExecutionActivityImpl()
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

ClassifierBehaviorExecutionActivityImpl::~ClassifierBehaviorExecutionActivityImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ClassifierBehaviorExecutionActivity "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ClassifierBehaviorExecutionActivityImpl::ClassifierBehaviorExecutionActivityImpl(const ClassifierBehaviorExecutionActivityImpl & obj):ClassifierBehaviorExecutionActivityImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ClassifierBehaviorExecutionActivity "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

    
	//Clone references with containment (deep copy)



}

ecore::EObject *  ClassifierBehaviorExecutionActivityImpl::copy() const
{
	return new ClassifierBehaviorExecutionActivityImpl(*this);
}

std::shared_ptr<ecore::EClass> ClassifierBehaviorExecutionActivityImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getClassifierBehaviorExecutionActivity();
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
boost::any ClassifierBehaviorExecutionActivityImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}
