#include "AuthorImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "EcoreSimpleExampleModelPackageImpl.hpp"

//Forward declaration includes
#include "NamedElement.hpp"


using namespace ecoreSimpleExampleModel;

//*********************************
// Constructor / Destructor
//*********************************
AuthorImpl::AuthorImpl()
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

AuthorImpl::~AuthorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Author "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




AuthorImpl::AuthorImpl(const AuthorImpl & obj):AuthorImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Author "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_Name = obj.getName();

	//copy references with no containment (soft copy)
	

    
	//Clone references with containment (deep copy)



}

ecore::EObject *  AuthorImpl::copy() const
{
	return new AuthorImpl(*this);
}

std::shared_ptr<ecore::EClass> AuthorImpl::eStaticClass() const
{
	return EcoreSimpleExampleModelPackageImpl::eInstance()->getAuthor();
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
invalid

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any AuthorImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcoreSimpleExampleModelPackage::NAMEDELEMENT_NAME:
			return getName(); //10
	}
	return boost::any();
}
