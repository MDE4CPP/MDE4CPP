#include "Container_Level1Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes
#include "Container.hpp"

#include "Element.hpp"

#include "Element_Level1.hpp"


using namespace subsetUnionBenchmark;

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
		/*Subset*/
		m_subset1.reset(new Subset<subsetUnionBenchmark::Element_Level1, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset1 - Subset<subsetUnionBenchmark::Element_Level1, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_subset1->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset1 - Subset<subsetUnionBenchmark::Element_Level1, subsetUnionBenchmark::Element >(m_union)" << std::endl;
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

	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level1>> _subset1List = obj.getSubset1();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level1> _subset1 : *_subset1List)
	{
		this->getSubset1()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level1>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level1>(_subset1->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset1" << std::endl;
	#endif

		/*Subset*/
		m_subset1->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset1 - Subset<subsetUnionBenchmark::Element_Level1, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  Container_Level1Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level1Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level1Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getContainer_Level1();
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
std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level1, subsetUnionBenchmark::Element > > Container_Level1Impl::getSubset1() const
{

    return m_subset1;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<subsetUnionBenchmark::Element> > Container_Level1Impl::getUnion() const
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
		case SubsetUnionBenchmarkPackage::CONTAINER_NAME:
			return getName(); //31
		case SubsetUnionBenchmarkPackage::CONTAINER_LEVEL1_SUBSET1:
			return getSubset1(); //32
		case SubsetUnionBenchmarkPackage::CONTAINER_UNION:
			return getUnion(); //30
	}
	return boost::any();
}
