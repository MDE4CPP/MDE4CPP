#include "Container_Level4Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes
#include "Container.hpp"

#include "Element.hpp"

#include "Element_Level4.hpp"


using namespace subsetUnionBenchmark;

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
		/*Subset*/
		m_subset4.reset(new Subset<subsetUnionBenchmark::Element_Level4, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset4 - Subset<subsetUnionBenchmark::Element_Level4, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_subset4->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset4 - Subset<subsetUnionBenchmark::Element_Level4, subsetUnionBenchmark::Element >(m_union)" << std::endl;
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

	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level4>> _subset4List = obj.getSubset4();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level4> _subset4 : *_subset4List)
	{
		this->getSubset4()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level4>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level4>(_subset4->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset4" << std::endl;
	#endif

		/*Subset*/
		m_subset4->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset4 - Subset<subsetUnionBenchmark::Element_Level4, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  Container_Level4Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level4Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level4Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getContainer_Level4();
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
std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level4, subsetUnionBenchmark::Element > > Container_Level4Impl::getSubset4() const
{

    return m_subset4;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<subsetUnionBenchmark::Element> > Container_Level4Impl::getUnion() const
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
		case SubsetUnionBenchmarkPackage::CONTAINER_NAME:
			return getName(); //91
		case SubsetUnionBenchmarkPackage::CONTAINER_LEVEL4_SUBSET4:
			return getSubset4(); //92
		case SubsetUnionBenchmarkPackage::CONTAINER_UNION:
			return getUnion(); //90
	}
	return boost::any();
}
