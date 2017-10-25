#include "Element_Level9Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkDepthPackageImpl.hpp"

//Forward declaration includes
#include "Element_Level8.hpp"


using namespace subsetUnionBenchmarkDepth;

//*********************************
// Constructor / Destructor
//*********************************
Element_Level9Impl::Element_Level9Impl()
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

Element_Level9Impl::~Element_Level9Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Element_Level9 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Element_Level9Impl::Element_Level9Impl(const Element_Level9Impl & obj):Element_Level9Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Element_Level9 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  Element_Level9Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Element_Level9Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Element_Level9Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkDepthPackageImpl::eInstance()->getElement_Level9();
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
boost::any Element_Level9Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkDepthPackage::ELEMENT_NAME:
			return getName(); //190
	}
	return boost::any();
}
