#include "uml/impl/ObjectImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Property.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ObjectImpl::ObjectImpl()
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

ObjectImpl::~ObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Object "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ObjectImpl::ObjectImpl(const ObjectImpl & obj):ObjectImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Object "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ObjectImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ObjectImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ObjectImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getObject_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
boost::any ObjectImpl::get(std::shared_ptr<uml::Property>  property) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ObjectImpl::set(std::shared_ptr<uml::Property>  property,boost::any value) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ObjectImpl::unset(std::shared_ptr<uml::Property>  property) 
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


std::shared_ptr<ecore::EObject> ObjectImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ObjectImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}

void ObjectImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
