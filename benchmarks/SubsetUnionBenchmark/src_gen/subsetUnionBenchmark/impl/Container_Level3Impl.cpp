#include "Container_Level3Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes
#include "Container.hpp"

#include "Element.hpp"

#include "Element_Level3.hpp"


using namespace subsetUnionBenchmark;

//*********************************
// Constructor / Destructor
//*********************************
Container_Level3Impl::Container_Level3Impl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_subset3.reset(new Subset<subsetUnionBenchmark::Element_Level3, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset3 - Subset<subsetUnionBenchmark::Element_Level3, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_subset3->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset3 - Subset<subsetUnionBenchmark::Element_Level3, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

Container_Level3Impl::~Container_Level3Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Container_Level3 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Container_Level3Impl::Container_Level3Impl(const Container_Level3Impl & obj):Container_Level3Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Container_Level3 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level3>> _subset3List = obj.getSubset3();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level3> _subset3 : *_subset3List)
	{
		this->getSubset3()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level3>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level3>(_subset3->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset3" << std::endl;
	#endif

		/*Subset*/
		m_subset3->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset3 - Subset<subsetUnionBenchmark::Element_Level3, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  Container_Level3Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level3Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level3Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getContainer_Level3();
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
std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level3, subsetUnionBenchmark::Element > > Container_Level3Impl::getSubset3() const
{

    return m_subset3;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<subsetUnionBenchmark::Element> > Container_Level3Impl::getUnion() const
{
	return m_union;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any Container_Level3Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkPackage::CONTAINER_NAME:
			return getName(); //71
		case SubsetUnionBenchmarkPackage::CONTAINER_LEVEL3_SUBSET3:
			return getSubset3(); //72
		case SubsetUnionBenchmarkPackage::CONTAINER_UNION:
			return getUnion(); //70
	}
	return boost::any();
}
