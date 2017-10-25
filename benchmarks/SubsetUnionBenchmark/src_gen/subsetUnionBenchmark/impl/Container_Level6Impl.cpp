#include "Container_Level6Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes
#include "Container.hpp"

#include "Element.hpp"

#include "Element_Level6.hpp"


using namespace subsetUnionBenchmark;

//*********************************
// Constructor / Destructor
//*********************************
Container_Level6Impl::Container_Level6Impl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_subset6.reset(new Subset<subsetUnionBenchmark::Element_Level6, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset6 - Subset<subsetUnionBenchmark::Element_Level6, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_subset6->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset6 - Subset<subsetUnionBenchmark::Element_Level6, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

Container_Level6Impl::~Container_Level6Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Container_Level6 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Container_Level6Impl::Container_Level6Impl(const Container_Level6Impl & obj):Container_Level6Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Container_Level6 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level6>> _subset6List = obj.getSubset6();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level6> _subset6 : *_subset6List)
	{
		this->getSubset6()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level6>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level6>(_subset6->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset6" << std::endl;
	#endif

		/*Subset*/
		m_subset6->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset6 - Subset<subsetUnionBenchmark::Element_Level6, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  Container_Level6Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level6Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level6Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getContainer_Level6();
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
std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level6, subsetUnionBenchmark::Element > > Container_Level6Impl::getSubset6() const
{

    return m_subset6;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<subsetUnionBenchmark::Element> > Container_Level6Impl::getUnion() const
{
	return m_union;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any Container_Level6Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkPackage::CONTAINER_NAME:
			return getName(); //131
		case SubsetUnionBenchmarkPackage::CONTAINER_LEVEL6_SUBSET6:
			return getSubset6(); //132
		case SubsetUnionBenchmarkPackage::CONTAINER_UNION:
			return getUnion(); //130
	}
	return boost::any();
}
