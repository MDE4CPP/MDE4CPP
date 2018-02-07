#include "uml/impl/ActivityContentImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Activity.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityContentImpl::ActivityContentImpl()
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

ActivityContentImpl::~ActivityContentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityContent "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




ActivityContentImpl::ActivityContentImpl(const ActivityContentImpl & obj):ActivityContentImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityContent "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ActivityContentImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ActivityContentImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ActivityContentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getActivityContent();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Activity> ActivityContentImpl::containingActivity() 
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


std::shared_ptr<ecore::EObject> ActivityContentImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActivityContentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}

void ActivityContentImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
