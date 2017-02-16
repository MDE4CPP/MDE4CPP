#include "ActivityContentImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityContentImpl::ActivityContentImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

ActivityContentImpl::~ActivityContentImpl()
{
	
}

ActivityContentImpl::ActivityContentImpl(const ActivityContentImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
}

ecore::EObject *  ActivityContentImpl::copy() const
{
	return new ActivityContentImpl(*this);
}

ecore::EClass* ActivityContentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getActivityContent();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
uml::Activity *  ActivityContentImpl::containingActivity() 
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
boost::any ActivityContentImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}
