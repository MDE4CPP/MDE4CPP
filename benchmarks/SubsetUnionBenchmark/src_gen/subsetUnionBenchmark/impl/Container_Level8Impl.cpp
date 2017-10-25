#include "Container_Level8Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes
#include "Container.hpp"

#include "Element.hpp"

#include "Element_Level8.hpp"


using namespace subsetUnionBenchmark;

//*********************************
// Constructor / Destructor
//*********************************
Container_Level8Impl::Container_Level8Impl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_subset8.reset(new Subset<subsetUnionBenchmark::Element_Level8, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset8 - Subset<subsetUnionBenchmark::Element_Level8, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_subset8->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset8 - Subset<subsetUnionBenchmark::Element_Level8, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

Container_Level8Impl::~Container_Level8Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Container_Level8 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




Container_Level8Impl::Container_Level8Impl(const Container_Level8Impl & obj):Container_Level8Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Container_Level8 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level8>> _subset8List = obj.getSubset8();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level8> _subset8 : *_subset8List)
	{
		this->getSubset8()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level8>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level8>(_subset8->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset8" << std::endl;
	#endif

		/*Subset*/
		m_subset8->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset8 - Subset<subsetUnionBenchmark::Element_Level8, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  Container_Level8Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new Container_Level8Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> Container_Level8Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getContainer_Level8();
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
std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level8, subsetUnionBenchmark::Element > > Container_Level8Impl::getSubset8() const
{

    return m_subset8;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<subsetUnionBenchmark::Element> > Container_Level8Impl::getUnion() const
{
	return m_union;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any Container_Level8Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkPackage::CONTAINER_NAME:
			return getName(); //161
		case SubsetUnionBenchmarkPackage::CONTAINER_LEVEL8_SUBSET8:
			return getSubset8(); //162
		case SubsetUnionBenchmarkPackage::CONTAINER_UNION:
			return getUnion(); //160
	}
	return boost::any();
}
