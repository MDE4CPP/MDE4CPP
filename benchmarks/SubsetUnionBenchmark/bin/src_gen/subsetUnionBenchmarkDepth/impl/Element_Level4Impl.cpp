#include "Element_Level4Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkDepthPackageImpl.hpp"

//Forward declaration includes
#include "Element_Level3.hpp"


using namespace subsetUnionBenchmarkDepth;

//*********************************
// Constructor / Destructor
//*********************************
Element_Level4Impl::Element_Level4Impl()
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

Element_Level4Impl::~Element_Level4Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Element_Level4 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Element_Level4Impl::Element_Level4Impl(const Element_Level4Impl & obj):Element_Level4Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Element_Level4 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  Element_Level4Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Element_Level4Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Element_Level4Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkDepthPackageImpl::eInstance()->getElement_Level4();
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
boost::any Element_Level4Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkDepthPackage::ELEMENT_NAME:
			return getName(); //90
	}
	return boost::any();
}
