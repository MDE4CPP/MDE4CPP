#include "Container_Level8Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkDepthPackageImpl.hpp"

//Forward declaration includes
#include "Container_Level7.hpp"

#include "Element.hpp"

#include "Element_Level1.hpp"

#include "Element_Level2.hpp"

#include "Element_Level3.hpp"

#include "Element_Level4.hpp"

#include "Element_Level5.hpp"

#include "Element_Level6.hpp"

#include "Element_Level7.hpp"

#include "Element_Level8.hpp"


using namespace subsetUnionBenchmarkDepth;

//*********************************
// Constructor / Destructor
//*********************************
Container_Level8Impl::Container_Level8Impl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*SubsetUnion*/
		m_subset8.reset(new SubsetUnion<subsetUnionBenchmarkDepth::Element_Level8, subsetUnionBenchmarkDepth::Element_Level7 >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_subset8 - SubsetUnion<subsetUnionBenchmarkDepth::Element_Level8, subsetUnionBenchmarkDepth::Element_Level7 >()" << std::endl;
		#endif
	
	

	//Init references
		/*SubsetUnion*/
		m_subset8->initSubsetUnion(m_subset7);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_subset8 - SubsetUnion<subsetUnionBenchmarkDepth::Element_Level8, subsetUnionBenchmarkDepth::Element_Level7 >(m_subset7)" << std::endl;
		#endif
	
	
}

Container_Level8Impl::~Container_Level8Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Container_Level8 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Container_Level8Impl::Container_Level8Impl(const Container_Level8Impl & obj):Container_Level8Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Container_Level8 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  Container_Level8Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level8Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level8Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkDepthPackageImpl::eInstance()->getContainer_Level8();
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
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level1, subsetUnionBenchmarkDepth::Element > > Container_Level8Impl::getSubset1() const
{
	return m_subset1;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level2, subsetUnionBenchmarkDepth::Element_Level1 > > Container_Level8Impl::getSubset2() const
{
	return m_subset2;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level3, subsetUnionBenchmarkDepth::Element_Level2 > > Container_Level8Impl::getSubset3() const
{
	return m_subset3;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level4, subsetUnionBenchmarkDepth::Element_Level3 > > Container_Level8Impl::getSubset4() const
{
	return m_subset4;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level5, subsetUnionBenchmarkDepth::Element_Level4 > > Container_Level8Impl::getSubset5() const
{
	return m_subset5;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level6, subsetUnionBenchmarkDepth::Element_Level5 > > Container_Level8Impl::getSubset6() const
{
	return m_subset6;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level7, subsetUnionBenchmarkDepth::Element_Level6 > > Container_Level8Impl::getSubset7() const
{
	return m_subset7;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level8, subsetUnionBenchmarkDepth::Element_Level7 > > Container_Level8Impl::getSubset8() const
{
	return m_subset8;
}
std::shared_ptr<Union<subsetUnionBenchmarkDepth::Element> > Container_Level8Impl::getUnion() const
{
	return m_union;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any Container_Level8Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_NAME:
			return getName(); //171
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL1_SUBSET1:
			return getSubset1(); //172
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL2_SUBSET2:
			return getSubset2(); //173
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL3_SUBSET3:
			return getSubset3(); //174
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL4_SUBSET4:
			return getSubset4(); //175
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL5_SUBSET5:
			return getSubset5(); //176
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL6_SUBSET6:
			return getSubset6(); //177
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL7_SUBSET7:
			return getSubset7(); //178
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL8_SUBSET8:
			return getSubset8(); //179
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_UNION:
			return getUnion(); //170
	}
	return boost::any();
}
