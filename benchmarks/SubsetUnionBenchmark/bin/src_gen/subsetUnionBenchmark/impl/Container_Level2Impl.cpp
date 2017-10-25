#include "Container_Level2Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes
#include "Container.hpp"

#include "Element.hpp"

#include "Element_Level2.hpp"


using namespace subsetUnionBenchmark;

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
		/*Subset*/
		m_subset2.reset(new Subset<subsetUnionBenchmark::Element_Level2, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset2 - Subset<subsetUnionBenchmark::Element_Level2, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_subset2->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset2 - Subset<subsetUnionBenchmark::Element_Level2, subsetUnionBenchmark::Element >(m_union)" << std::endl;
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

	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level2>> _subset2List = obj.getSubset2();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level2> _subset2 : *_subset2List)
	{
		this->getSubset2()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level2>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level2>(_subset2->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset2" << std::endl;
	#endif

		/*Subset*/
		m_subset2->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset2 - Subset<subsetUnionBenchmark::Element_Level2, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  Container_Level2Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level2Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level2Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getContainer_Level2();
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
std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level2, subsetUnionBenchmark::Element > > Container_Level2Impl::getSubset2() const
{

    return m_subset2;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<subsetUnionBenchmark::Element> > Container_Level2Impl::getUnion() const
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
		case SubsetUnionBenchmarkPackage::CONTAINER_NAME:
			return getName(); //51
		case SubsetUnionBenchmarkPackage::CONTAINER_LEVEL2_SUBSET2:
			return getSubset2(); //52
		case SubsetUnionBenchmarkPackage::CONTAINER_UNION:
			return getUnion(); //50
	}
	return boost::any();
}
