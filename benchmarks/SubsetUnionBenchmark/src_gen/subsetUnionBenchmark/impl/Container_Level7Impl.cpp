#include "Container_Level7Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes
#include "Container.hpp"

#include "Element.hpp"

#include "Element_Level7.hpp"


using namespace subsetUnionBenchmark;

//*********************************
// Constructor / Destructor
//*********************************
Container_Level7Impl::Container_Level7Impl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_subset7.reset(new Subset<subsetUnionBenchmark::Element_Level7, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset7 - Subset<subsetUnionBenchmark::Element_Level7, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_subset7->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset7 - Subset<subsetUnionBenchmark::Element_Level7, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

Container_Level7Impl::~Container_Level7Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Container_Level7 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Container_Level7Impl::Container_Level7Impl(const Container_Level7Impl & obj):Container_Level7Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Container_Level7 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level7>> _subset7List = obj.getSubset7();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level7> _subset7 : *_subset7List)
	{
		this->getSubset7()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level7>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level7>(_subset7->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset7" << std::endl;
	#endif

		/*Subset*/
		m_subset7->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset7 - Subset<subsetUnionBenchmark::Element_Level7, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  Container_Level7Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level7Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level7Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getContainer_Level7();
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
std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level7, subsetUnionBenchmark::Element > > Container_Level7Impl::getSubset7() const
{

    return m_subset7;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<subsetUnionBenchmark::Element> > Container_Level7Impl::getUnion() const
{
	return m_union;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any Container_Level7Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkPackage::CONTAINER_NAME:
			return getName(); //151
		case SubsetUnionBenchmarkPackage::CONTAINER_LEVEL7_SUBSET7:
			return getSubset7(); //152
		case SubsetUnionBenchmarkPackage::CONTAINER_UNION:
			return getUnion(); //150
	}
	return boost::any();
}
