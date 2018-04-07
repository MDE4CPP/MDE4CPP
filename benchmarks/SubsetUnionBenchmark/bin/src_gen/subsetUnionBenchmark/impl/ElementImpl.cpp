#include "ElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes


using namespace subsetUnionBenchmark;

//*********************************
// Constructor / Destructor
//*********************************
ElementImpl::ElementImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References

	//Init references
}

ElementImpl::~ElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Element "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




ElementImpl::ElementImpl(const ElementImpl & obj):ElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Element "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ElementImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ElementImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ElementImpl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getElement();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ElementImpl::setName(std::string _name)
{
	m_name = _name;
} 

std::string ElementImpl::getName() const 
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkPackage::ELEMENT_NAME:
			return getName(); //00
	}
	return boost::any();
}
