#include "Container_Level10Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes
#include "Container.hpp"

#include "Element.hpp"

#include "Element_Level10.hpp"


using namespace subsetUnionBenchmark;

//*********************************
// Constructor / Destructor
//*********************************
Container_Level10Impl::Container_Level10Impl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_subset10.reset(new Subset<subsetUnionBenchmark::Element_Level10, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset10 - Subset<subsetUnionBenchmark::Element_Level10, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_subset10->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset10 - Subset<subsetUnionBenchmark::Element_Level10, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

Container_Level10Impl::~Container_Level10Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Container_Level10 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Container_Level10Impl::Container_Level10Impl(const Container_Level10Impl & obj):Container_Level10Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Container_Level10 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level10>> _subset10List = obj.getSubset10();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level10> _subset10 : *_subset10List)
	{
		this->getSubset10()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level10>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level10>(_subset10->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset10" << std::endl;
	#endif

		/*Subset*/
		m_subset10->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset10 - Subset<subsetUnionBenchmark::Element_Level10, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  Container_Level10Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level10Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level10Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getContainer_Level10();
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
std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level10, subsetUnionBenchmark::Element > > Container_Level10Impl::getSubset10() const
{

    return m_subset10;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<subsetUnionBenchmark::Element> > Container_Level10Impl::getUnion() const
{
	return m_union;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any Container_Level10Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkPackage::CONTAINER_NAME:
			return getName(); //211
		case SubsetUnionBenchmarkPackage::CONTAINER_LEVEL10_SUBSET10:
			return getSubset10(); //212
		case SubsetUnionBenchmarkPackage::CONTAINER_UNION:
			return getUnion(); //210
	}
	return boost::any();
}
