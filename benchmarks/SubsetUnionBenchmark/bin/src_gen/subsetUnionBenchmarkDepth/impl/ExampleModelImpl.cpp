#include "ExampleModelImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkDepthPackageImpl.hpp"

//Forward declaration includes
#include "Container.hpp"


using namespace subsetUnionBenchmarkDepth;

//*********************************
// Constructor / Destructor
//*********************************
ExampleModelImpl::ExampleModelImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_container.reset(new Bag<subsetUnionBenchmarkDepth::Container>());
	
	

	//Init references
	
	
}

ExampleModelImpl::~ExampleModelImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExampleModel "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




ExampleModelImpl::ExampleModelImpl(const ExampleModelImpl & obj):ExampleModelImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExampleModel "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<subsetUnionBenchmarkDepth::Container>> _containerList = obj.getContainer();
	for(std::shared_ptr<subsetUnionBenchmarkDepth::Container> _container : *_containerList)
	{
		this->getContainer()->add(std::shared_ptr<subsetUnionBenchmarkDepth::Container>(std::dynamic_pointer_cast<subsetUnionBenchmarkDepth::Container>(_container->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_container" << std::endl;
	#endif

	
	
}

std::shared_ptr<ecore::EObject>  ExampleModelImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExampleModelImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExampleModelImpl::eStaticClass() const
{
	return SubsetUnionBenchmarkDepthPackageImpl::eInstance()->getExampleModel();
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
std::shared_ptr< Bag<subsetUnionBenchmarkDepth::Container> > ExampleModelImpl::getContainer() const
{

    return m_container;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExampleModelImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkDepthPackage::EXAMPLEMODEL_CONTAINER:
			return getContainer(); //00
	}
	return boost::any();
}
