#include "Element_Level5Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes
#include "Element.hpp"


using namespace subsetUnionBenchmark;

//*********************************
// Constructor / Destructor
//*********************************
Element_Level5Impl::Element_Level5Impl()
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

Element_Level5Impl::~Element_Level5Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Element_Level5 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Element_Level5Impl::Element_Level5Impl(const Element_Level5Impl & obj):Element_Level5Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Element_Level5 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  Element_Level5Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Element_Level5Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Element_Level5Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getElement_Level5();
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
boost::any Element_Level5Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkPackage::ELEMENT_NAME:
			return getName(); //60
	}
	return boost::any();
}
