#include "Element_Level10Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkDepthPackageImpl.hpp"

//Forward declaration includes
#include "Element_Level9.hpp"


using namespace subsetUnionBenchmarkDepth;

//*********************************
// Constructor / Destructor
//*********************************
Element_Level10Impl::Element_Level10Impl()
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

Element_Level10Impl::~Element_Level10Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Element_Level10 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Element_Level10Impl::Element_Level10Impl(const Element_Level10Impl & obj):Element_Level10Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Element_Level10 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  Element_Level10Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Element_Level10Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Element_Level10Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkDepthPackageImpl::eInstance()->getElement_Level10();
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
boost::any Element_Level10Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkDepthPackage::ELEMENT_NAME:
			return getName(); //210
	}
	return boost::any();
}
