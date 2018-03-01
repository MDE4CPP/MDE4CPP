#include "Container_Level5Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes
#include "Container.hpp"

#include "Element.hpp"

#include "Element_Level5.hpp"


using namespace subsetUnionBenchmark;

//*********************************
// Constructor / Destructor
//*********************************
Container_Level5Impl::Container_Level5Impl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_subset5.reset(new Subset<subsetUnionBenchmark::Element_Level5, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset5 - Subset<subsetUnionBenchmark::Element_Level5, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_subset5->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset5 - Subset<subsetUnionBenchmark::Element_Level5, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

Container_Level5Impl::~Container_Level5Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Container_Level5 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Container_Level5Impl::Container_Level5Impl(const Container_Level5Impl & obj):Container_Level5Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Container_Level5 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level5>> _subset5List = obj.getSubset5();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level5> _subset5 : *_subset5List)
	{
		this->getSubset5()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level5>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level5>(_subset5->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset5" << std::endl;
	#endif

		/*Subset*/
		m_subset5->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset5 - Subset<subsetUnionBenchmark::Element_Level5, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  Container_Level5Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level5Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level5Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getContainer_Level5();
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
std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level5, subsetUnionBenchmark::Element > > Container_Level5Impl::getSubset5() const
{

    return m_subset5;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<subsetUnionBenchmark::Element> > Container_Level5Impl::getUnion() const
{
	return m_union;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any Container_Level5Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkPackage::CONTAINER_NAME:
			return getName(); //101
		case SubsetUnionBenchmarkPackage::CONTAINER_LEVEL5_SUBSET5:
			return getSubset5(); //102
		case SubsetUnionBenchmarkPackage::CONTAINER_UNION:
			return getUnion(); //100
	}
	return boost::any();
}
