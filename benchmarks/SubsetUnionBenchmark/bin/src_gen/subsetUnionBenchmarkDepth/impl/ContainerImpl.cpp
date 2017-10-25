#include "ContainerImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkDepthPackageImpl.hpp"

//Forward declaration includes
#include "Element.hpp"


using namespace subsetUnionBenchmarkDepth;

//*********************************
// Constructor / Destructor
//*********************************
ContainerImpl::ContainerImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Union*/
		m_union.reset(new Union<subsetUnionBenchmarkDepth::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_union - Union<subsetUnionBenchmarkDepth::Element>()" << std::endl;
		#endif
	
	

	//Init references
	
	
}

ContainerImpl::~ContainerImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Container "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




ContainerImpl::ContainerImpl(const ContainerImpl & obj):ContainerImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Container "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ContainerImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ContainerImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ContainerImpl::eStaticClass() const
{
	return SubsetUnionBenchmarkDepthPackageImpl::eInstance()->getContainer();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ContainerImpl::setName(std::string _name)
{
	m_name = _name;
} 

std::string ContainerImpl::getName() const 
{
	return m_name;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<subsetUnionBenchmarkDepth::Element> > ContainerImpl::getUnion() const
{
	return m_union;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ContainerImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_NAME:
			return getName(); //11
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_UNION:
			return getUnion(); //10
	}
	return boost::any();
}
