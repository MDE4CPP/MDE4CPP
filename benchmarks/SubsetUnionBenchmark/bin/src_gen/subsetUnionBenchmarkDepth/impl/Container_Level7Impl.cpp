#include "Container_Level7Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkDepthPackageImpl.hpp"

//Forward declaration includes
#include "Container_Level6.hpp"

#include "Element.hpp"

#include "Element_Level1.hpp"

#include "Element_Level2.hpp"

#include "Element_Level3.hpp"

#include "Element_Level4.hpp"

#include "Element_Level5.hpp"

#include "Element_Level6.hpp"

#include "Element_Level7.hpp"


using namespace subsetUnionBenchmarkDepth;

//*********************************
// Constructor / Destructor
//*********************************
Container_Level7Impl::Container_Level7Impl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*SubsetUnion*/
		m_subset7.reset(new SubsetUnion<subsetUnionBenchmarkDepth::Element_Level7, subsetUnionBenchmarkDepth::Element_Level6 >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_subset7 - SubsetUnion<subsetUnionBenchmarkDepth::Element_Level7, subsetUnionBenchmarkDepth::Element_Level6 >()" << std::endl;
		#endif
	
	

	//Init references
		/*SubsetUnion*/
		m_subset7->initSubsetUnion(m_subset6);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_subset7 - SubsetUnion<subsetUnionBenchmarkDepth::Element_Level7, subsetUnionBenchmarkDepth::Element_Level6 >(m_subset6)" << std::endl;
		#endif
	
	
}

Container_Level7Impl::~Container_Level7Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Container_Level7 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Container_Level7Impl::Container_Level7Impl(const Container_Level7Impl & obj):Container_Level7Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Container_Level7 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  Container_Level7Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level7Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level7Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkDepthPackageImpl::eInstance()->getContainer_Level7();
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
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level1, subsetUnionBenchmarkDepth::Element > > Container_Level7Impl::getSubset1() const
{
	return m_subset1;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level2, subsetUnionBenchmarkDepth::Element_Level1 > > Container_Level7Impl::getSubset2() const
{
	return m_subset2;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level3, subsetUnionBenchmarkDepth::Element_Level2 > > Container_Level7Impl::getSubset3() const
{
	return m_subset3;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level4, subsetUnionBenchmarkDepth::Element_Level3 > > Container_Level7Impl::getSubset4() const
{
	return m_subset4;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level5, subsetUnionBenchmarkDepth::Element_Level4 > > Container_Level7Impl::getSubset5() const
{
	return m_subset5;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level6, subsetUnionBenchmarkDepth::Element_Level5 > > Container_Level7Impl::getSubset6() const
{
	return m_subset6;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level7, subsetUnionBenchmarkDepth::Element_Level6 > > Container_Level7Impl::getSubset7() const
{
	return m_subset7;
}
std::shared_ptr<Union<subsetUnionBenchmarkDepth::Element> > Container_Level7Impl::getUnion() const
{
	return m_union;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any Container_Level7Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_NAME:
			return getName(); //161
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL1_SUBSET1:
			return getSubset1(); //162
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL2_SUBSET2:
			return getSubset2(); //163
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL3_SUBSET3:
			return getSubset3(); //164
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL4_SUBSET4:
			return getSubset4(); //165
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL5_SUBSET5:
			return getSubset5(); //166
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL6_SUBSET6:
			return getSubset6(); //167
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL7_SUBSET7:
			return getSubset7(); //168
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_UNION:
			return getUnion(); //160
	}
	return boost::any();
}
