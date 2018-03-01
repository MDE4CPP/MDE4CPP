#include "Container_Level9Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes
#include "Container.hpp"

#include "Element.hpp"

#include "Element_Level9.hpp"


using namespace subsetUnionBenchmark;

//*********************************
// Constructor / Destructor
//*********************************
Container_Level9Impl::Container_Level9Impl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_subset9.reset(new Subset<subsetUnionBenchmark::Element_Level9, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset9 - Subset<subsetUnionBenchmark::Element_Level9, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_subset9->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset9 - Subset<subsetUnionBenchmark::Element_Level9, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

Container_Level9Impl::~Container_Level9Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Container_Level9 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Container_Level9Impl::Container_Level9Impl(const Container_Level9Impl & obj):Container_Level9Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Container_Level9 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level9>> _subset9List = obj.getSubset9();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level9> _subset9 : *_subset9List)
	{
		this->getSubset9()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level9>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level9>(_subset9->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset9" << std::endl;
	#endif

		/*Subset*/
		m_subset9->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset9 - Subset<subsetUnionBenchmark::Element_Level9, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  Container_Level9Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level9Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level9Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getContainer_Level9();
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
std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level9, subsetUnionBenchmark::Element > > Container_Level9Impl::getSubset9() const
{

    return m_subset9;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<subsetUnionBenchmark::Element> > Container_Level9Impl::getUnion() const
{
	return m_union;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any Container_Level9Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkPackage::CONTAINER_NAME:
			return getName(); //191
		case SubsetUnionBenchmarkPackage::CONTAINER_LEVEL9_SUBSET9:
			return getSubset9(); //192
		case SubsetUnionBenchmarkPackage::CONTAINER_UNION:
			return getUnion(); //190
	}
	return boost::any();
}
