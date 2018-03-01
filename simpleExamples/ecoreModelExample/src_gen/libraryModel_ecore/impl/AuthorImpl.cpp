#include "libraryModel_ecore/impl/AuthorImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "libraryModel_ecore/impl/LibraryModel_ecorePackageImpl.hpp"

//Forward declaration includes
#include "libraryModel_ecore/NamedElement.hpp"


using namespace libraryModel_ecore;

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

std::shared_ptr<ecore::EObject>  AuthorImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new AuthorImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> AuthorImpl::eStaticClass() const
{
	return LibraryModel_ecorePackageImpl::eInstance()->getAuthor_EClass();
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


std::shared_ptr<ecore::EObject> AuthorImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any AuthorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //10
	}
	return boost::any();
}

void AuthorImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _Name = boost::any_cast<std::string>(newValue);
			setName(_Name); //10
			break;
		}
	}
}
