#include "Container_Level2Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkDepthPackageImpl.hpp"

//Forward declaration includes
#include "Container_Level1.hpp"

#include "Element.hpp"

#include "Element_Level1.hpp"

#include "Element_Level2.hpp"


using namespace subsetUnionBenchmarkDepth;

//*********************************
// Constructor / Destructor
//*********************************
Container_Level2Impl::Container_Level2Impl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*SubsetUnion*/
		m_subset2.reset(new SubsetUnion<subsetUnionBenchmarkDepth::Element_Level2, subsetUnionBenchmarkDepth::Element_Level1 >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_subset2 - SubsetUnion<subsetUnionBenchmarkDepth::Element_Level2, subsetUnionBenchmarkDepth::Element_Level1 >()" << std::endl;
		#endif
	
	

	//Init references
		/*SubsetUnion*/
		m_subset2->initSubsetUnion(m_subset1);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_subset2 - SubsetUnion<subsetUnionBenchmarkDepth::Element_Level2, subsetUnionBenchmarkDepth::Element_Level1 >(m_subset1)" << std::endl;
		#endif
	
	
}

Container_Level2Impl::~Container_Level2Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Container_Level2 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Container_Level2Impl::Container_Level2Impl(const Container_Level2Impl & obj):Container_Level2Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Container_Level2 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  Container_Level2Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level2Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level2Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkDepthPackageImpl::eInstance()->getContainer_Level2();
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
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level1, subsetUnionBenchmarkDepth::Element > > Container_Level2Impl::getSubset1() const
{
	return m_subset1;
}
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level2, subsetUnionBenchmarkDepth::Element_Level1 > > Container_Level2Impl::getSubset2() const
{
	return m_subset2;
}
std::shared_ptr<Union<subsetUnionBenchmarkDepth::Element> > Container_Level2Impl::getUnion() const
{
	return m_union;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any Container_Level2Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_NAME:
			return getName(); //61
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL1_SUBSET1:
			return getSubset1(); //62
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL2_SUBSET2:
			return getSubset2(); //63
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_UNION:
			return getUnion(); //60
	}
	return boost::any();
}
