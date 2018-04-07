#include "Container_Level4Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkDepthPackageImpl.hpp"

//Forward declaration includes
#include "Container_Level3.hpp"

#include "Element.hpp"

#include "Element_Level1.hpp"

#include "Element_Level2.hpp"

#include "Element_Level3.hpp"

#include "Element_Level4.hpp"


using namespace subsetUnionBenchmarkDepth;

//*********************************
// Constructor / Destructor
//*********************************
Container_Level4Impl::Container_Level4Impl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*SubsetUnion*/
		m_subset4.reset(new SubsetUnion<subsetUnionBenchmarkDepth::Element_Level4, subsetUnionBenchmarkDepth::Element_Level3 >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_subset4 - SubsetUnion<subsetUnionBenchmarkDepth::Element_Level4, subsetUnionBenchmarkDepth::Element_Level3 >()" << std::endl;
		#endif
	
	

	//Init references
		/*SubsetUnion*/
		m_subset4->initSubsetUnion(m_subset3);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_subset4 - SubsetUnion<subsetUnionBenchmarkDepth::Element_Level4, subsetUnionBenchmarkDepth::Element_Level3 >(m_subset3)" << std::endl;
		#endif
	
	
}

Container_Level4Impl::~Container_Level4Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Container_Level4 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Container_Level4Impl::Container_Level4Impl(const Container_Level4Impl & obj):Container_Level4Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Container_Level4 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  Container_Level4Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level4Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level4Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkDepthPackageImpl::eInstance()->getContainer_Level4();
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
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level1, subsetUnionBenchmarkDepth::Element > > Container_Level4Impl::getSubset1() const
{
	return m_subset1;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level2, subsetUnionBenchmarkDepth::Element_Level1 > > Container_Level4Impl::getSubset2() const
{
	return m_subset2;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level3, subsetUnionBenchmarkDepth::Element_Level2 > > Container_Level4Impl::getSubset3() const
{
	return m_subset3;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level4, subsetUnionBenchmarkDepth::Element_Level3 > > Container_Level4Impl::getSubset4() const
{
	return m_subset4;
}
std::shared_ptr<Union<subsetUnionBenchmarkDepth::Element> > Container_Level4Impl::getUnion() const
{
	return m_union;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any Container_Level4Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_NAME:
			return getName(); //101
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL1_SUBSET1:
			return getSubset1(); //102
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL2_SUBSET2:
			return getSubset2(); //103
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL3_SUBSET3:
			return getSubset3(); //104
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL4_SUBSET4:
			return getSubset4(); //105
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_UNION:
			return getUnion(); //100
	}
	return boost::any();
}
