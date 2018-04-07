#include "Container_Level1Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkDepthPackageImpl.hpp"

//Forward declaration includes
#include "Container.hpp"

#include "Element.hpp"

#include "Element_Level1.hpp"


using namespace subsetUnionBenchmarkDepth;

//*********************************
// Constructor / Destructor
//*********************************
Container_Level1Impl::Container_Level1Impl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*SubsetUnion*/
		m_subset1.reset(new SubsetUnion<subsetUnionBenchmarkDepth::Element_Level1, subsetUnionBenchmarkDepth::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_subset1 - SubsetUnion<subsetUnionBenchmarkDepth::Element_Level1, subsetUnionBenchmarkDepth::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*SubsetUnion*/
		m_subset1->initSubsetUnion(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_subset1 - SubsetUnion<subsetUnionBenchmarkDepth::Element_Level1, subsetUnionBenchmarkDepth::Element >(m_union)" << std::endl;
		#endif
	
	
}

Container_Level1Impl::~Container_Level1Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Container_Level1 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Container_Level1Impl::Container_Level1Impl(const Container_Level1Impl & obj):Container_Level1Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Container_Level1 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  Container_Level1Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level1Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level1Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkDepthPackageImpl::eInstance()->getContainer_Level1();
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
std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level1, subsetUnionBenchmarkDepth::Element > > Container_Level1Impl::getSubset1() const
{
	return m_subset1;
}
std::shared_ptr<Union<subsetUnionBenchmarkDepth::Element> > Container_Level1Impl::getUnion() const
{
	return m_union;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any Container_Level1Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_NAME:
			return getName(); //41
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL1_SUBSET1:
			return getSubset1(); //42
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_UNION:
			return getUnion(); //40
	}
	return boost::any();
}
