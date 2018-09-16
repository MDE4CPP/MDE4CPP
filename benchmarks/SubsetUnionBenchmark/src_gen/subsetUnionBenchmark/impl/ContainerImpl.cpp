#include "subsetUnionBenchmark/impl/ContainerImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "subsetUnionBenchmark/impl/SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "subsetUnionBenchmark/SubsetUnionBenchmarkFactory.hpp"
#include "subsetUnionBenchmark/SubsetUnionBenchmarkPackage.hpp"
#include <exception> // used in Persistence

#include "subsetUnionBenchmark/Element.hpp"

#include "subsetUnionBenchmark/Element_Level1.hpp"

#include "subsetUnionBenchmark/Element_Level10.hpp"

#include "subsetUnionBenchmark/Element_Level2.hpp"

#include "subsetUnionBenchmark/Element_Level3.hpp"

#include "subsetUnionBenchmark/Element_Level4.hpp"

#include "subsetUnionBenchmark/Element_Level5.hpp"

#include "subsetUnionBenchmark/Element_Level6.hpp"

#include "subsetUnionBenchmark/Element_Level7.hpp"

#include "subsetUnionBenchmark/Element_Level8.hpp"

#include "subsetUnionBenchmark/Element_Level9.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "subsetUnionBenchmark/SubsetUnionBenchmarkPackage.hpp"
#include "subsetUnionBenchmark/SubsetUnionBenchmarkFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace subsetUnionBenchmark;

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
		/*Subset*/
		m_subset1.reset(new Subset<subsetUnionBenchmark::Element_Level1, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset1 - Subset<subsetUnionBenchmark::Element_Level1, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset10.reset(new Subset<subsetUnionBenchmark::Element_Level10, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset10 - Subset<subsetUnionBenchmark::Element_Level10, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset2.reset(new Subset<subsetUnionBenchmark::Element_Level2, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset2 - Subset<subsetUnionBenchmark::Element_Level2, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset3.reset(new Subset<subsetUnionBenchmark::Element_Level3, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset3 - Subset<subsetUnionBenchmark::Element_Level3, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset4.reset(new Subset<subsetUnionBenchmark::Element_Level4, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset4 - Subset<subsetUnionBenchmark::Element_Level4, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset5.reset(new Subset<subsetUnionBenchmark::Element_Level5, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset5 - Subset<subsetUnionBenchmark::Element_Level5, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset6.reset(new Subset<subsetUnionBenchmark::Element_Level6, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset6 - Subset<subsetUnionBenchmark::Element_Level6, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset7.reset(new Subset<subsetUnionBenchmark::Element_Level7, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset7 - Subset<subsetUnionBenchmark::Element_Level7, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset8.reset(new Subset<subsetUnionBenchmark::Element_Level8, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset8 - Subset<subsetUnionBenchmark::Element_Level8, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset9.reset(new Subset<subsetUnionBenchmark::Element_Level9, subsetUnionBenchmark::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subset9 - Subset<subsetUnionBenchmark::Element_Level9, subsetUnionBenchmark::Element >()" << std::endl;
		#endif
	
	

		/*Union*/
		m_unionBag.reset(new Union<subsetUnionBenchmark::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_unionBag - Union<subsetUnionBenchmark::Element>()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_subset1->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset1 - Subset<subsetUnionBenchmark::Element_Level1, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset10->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset10 - Subset<subsetUnionBenchmark::Element_Level10, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset2->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset2 - Subset<subsetUnionBenchmark::Element_Level2, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset3->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset3 - Subset<subsetUnionBenchmark::Element_Level3, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset4->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset4 - Subset<subsetUnionBenchmark::Element_Level4, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset5->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset5 - Subset<subsetUnionBenchmark::Element_Level5, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset6->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset6 - Subset<subsetUnionBenchmark::Element_Level6, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset7->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset7 - Subset<subsetUnionBenchmark::Element_Level7, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset8->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset8 - Subset<subsetUnionBenchmark::Element_Level8, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset9->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset9 - Subset<subsetUnionBenchmark::Element_Level9, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

	
	
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

	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level1>> _subset1List = obj.getSubset1();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level1> _subset1 : *_subset1List)
	{
		this->getSubset1()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level1>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level1>(_subset1->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset1" << std::endl;
	#endif
	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level10>> _subset10List = obj.getSubset10();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level10> _subset10 : *_subset10List)
	{
		this->getSubset10()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level10>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level10>(_subset10->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset10" << std::endl;
	#endif
	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level2>> _subset2List = obj.getSubset2();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level2> _subset2 : *_subset2List)
	{
		this->getSubset2()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level2>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level2>(_subset2->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset2" << std::endl;
	#endif
	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level3>> _subset3List = obj.getSubset3();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level3> _subset3 : *_subset3List)
	{
		this->getSubset3()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level3>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level3>(_subset3->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset3" << std::endl;
	#endif
	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level4>> _subset4List = obj.getSubset4();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level4> _subset4 : *_subset4List)
	{
		this->getSubset4()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level4>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level4>(_subset4->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset4" << std::endl;
	#endif
	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level5>> _subset5List = obj.getSubset5();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level5> _subset5 : *_subset5List)
	{
		this->getSubset5()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level5>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level5>(_subset5->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset5" << std::endl;
	#endif
	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level6>> _subset6List = obj.getSubset6();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level6> _subset6 : *_subset6List)
	{
		this->getSubset6()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level6>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level6>(_subset6->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset6" << std::endl;
	#endif
	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level7>> _subset7List = obj.getSubset7();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level7> _subset7 : *_subset7List)
	{
		this->getSubset7()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level7>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level7>(_subset7->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset7" << std::endl;
	#endif
	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level8>> _subset8List = obj.getSubset8();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level8> _subset8 : *_subset8List)
	{
		this->getSubset8()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level8>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level8>(_subset8->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset8" << std::endl;
	#endif
	std::shared_ptr<Bag<subsetUnionBenchmark::Element_Level9>> _subset9List = obj.getSubset9();
	for(std::shared_ptr<subsetUnionBenchmark::Element_Level9> _subset9 : *_subset9List)
	{
		this->getSubset9()->add(std::shared_ptr<subsetUnionBenchmark::Element_Level9>(std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level9>(_subset9->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subset9" << std::endl;
	#endif

		/*Subset*/
		m_subset1->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset1 - Subset<subsetUnionBenchmark::Element_Level1, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset10->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset10 - Subset<subsetUnionBenchmark::Element_Level10, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset2->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset2 - Subset<subsetUnionBenchmark::Element_Level2, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset3->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset3 - Subset<subsetUnionBenchmark::Element_Level3, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset4->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset4 - Subset<subsetUnionBenchmark::Element_Level4, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset5->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset5 - Subset<subsetUnionBenchmark::Element_Level5, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset6->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset6 - Subset<subsetUnionBenchmark::Element_Level6, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset7->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset7 - Subset<subsetUnionBenchmark::Element_Level7, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset8->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset8 - Subset<subsetUnionBenchmark::Element_Level8, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset9->initSubset(m_unionBag);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset9 - Subset<subsetUnionBenchmark::Element_Level9, subsetUnionBenchmark::Element >(m_unionBag)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  ContainerImpl::copy() const
{
	std::shared_ptr<ContainerImpl> element(new ContainerImpl(*this));
	element->setThisContainerPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ContainerImpl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getContainer_EClass();
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
std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level1, subsetUnionBenchmark::Element>> ContainerImpl::getSubset1() const
{

    return m_subset1;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level10, subsetUnionBenchmark::Element>> ContainerImpl::getSubset10() const
{

    return m_subset10;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level2, subsetUnionBenchmark::Element>> ContainerImpl::getSubset2() const
{

    return m_subset2;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level3, subsetUnionBenchmark::Element>> ContainerImpl::getSubset3() const
{

    return m_subset3;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level4, subsetUnionBenchmark::Element>> ContainerImpl::getSubset4() const
{

    return m_subset4;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level5, subsetUnionBenchmark::Element>> ContainerImpl::getSubset5() const
{

    return m_subset5;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level6, subsetUnionBenchmark::Element>> ContainerImpl::getSubset6() const
{

    return m_subset6;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level7, subsetUnionBenchmark::Element>> ContainerImpl::getSubset7() const
{

    return m_subset7;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level8, subsetUnionBenchmark::Element>> ContainerImpl::getSubset8() const
{

    return m_subset8;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level9, subsetUnionBenchmark::Element>> ContainerImpl::getSubset9() const
{

    return m_subset9;
}





//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<subsetUnionBenchmark::Element>> ContainerImpl::getUnionBag() const
{
	return m_unionBag;
}


std::shared_ptr<Container> ContainerImpl::getThisContainerPtr() const
{
	return m_thisContainerPtr.lock();
}
void ContainerImpl::setThisContainerPtr(std::weak_ptr<Container> thisContainerPtr)
{
	m_thisContainerPtr = thisContainerPtr;
}
std::shared_ptr<ecore::EObject> ContainerImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ContainerImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkPackage::CONTAINER_EATTRIBUTE_NAME:
			return eAny(getName()); //121
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET1:
			return eAny(getSubset1()); //122
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET10:
			return eAny(getSubset10()); //1211
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET2:
			return eAny(getSubset2()); //123
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET3:
			return eAny(getSubset3()); //124
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET4:
			return eAny(getSubset4()); //125
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET5:
			return eAny(getSubset5()); //126
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET6:
			return eAny(getSubset6()); //127
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET7:
			return eAny(getSubset7()); //128
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET8:
			return eAny(getSubset8()); //129
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET9:
			return eAny(getSubset9()); //1210
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_UNIONBAG:
			return eAny(getUnionBag()); //120
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ContainerImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkPackage::CONTAINER_EATTRIBUTE_NAME:
			return getName() != ""; //121
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET1:
			return getSubset1() != nullptr; //122
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET10:
			return getSubset10() != nullptr; //1211
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET2:
			return getSubset2() != nullptr; //123
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET3:
			return getSubset3() != nullptr; //124
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET4:
			return getSubset4() != nullptr; //125
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET5:
			return getSubset5() != nullptr; //126
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET6:
			return getSubset6() != nullptr; //127
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET7:
			return getSubset7() != nullptr; //128
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET8:
			return getSubset8() != nullptr; //129
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_SUBSET9:
			return getSubset9() != nullptr; //1210
		case SubsetUnionBenchmarkPackage::CONTAINER_EREFERENCE_UNIONBAG:
			return getUnionBag() != nullptr; //120
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ContainerImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case SubsetUnionBenchmarkPackage::CONTAINER_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = newValue->get<std::string>();
			setName(_name); //121
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ContainerImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get SubsetUnionBenchmarkFactory
	std::shared_ptr<subsetUnionBenchmark::SubsetUnionBenchmarkFactory> modelFactory = subsetUnionBenchmark::SubsetUnionBenchmarkFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void ContainerImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("name");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setName(value);
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ContainerImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<subsetUnionBenchmark::SubsetUnionBenchmarkFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("subset1") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Element_Level1";
			}
			std::shared_ptr<subsetUnionBenchmark::Element_Level1> subset1 = std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level1>(modelFactory->create(typeName));
			if (subset1 != nullptr)
			{
				std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level1, subsetUnionBenchmark::Element>> list_subset1 = this->getSubset1();
				list_subset1->push_back(subset1);
				loadHandler->handleChild(subset1);
			}
			return;
		}

		if ( nodeName.compare("subset10") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Element_Level10";
			}
			std::shared_ptr<subsetUnionBenchmark::Element_Level10> subset10 = std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level10>(modelFactory->create(typeName));
			if (subset10 != nullptr)
			{
				std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level10, subsetUnionBenchmark::Element>> list_subset10 = this->getSubset10();
				list_subset10->push_back(subset10);
				loadHandler->handleChild(subset10);
			}
			return;
		}

		if ( nodeName.compare("subset2") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Element_Level2";
			}
			std::shared_ptr<subsetUnionBenchmark::Element_Level2> subset2 = std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level2>(modelFactory->create(typeName));
			if (subset2 != nullptr)
			{
				std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level2, subsetUnionBenchmark::Element>> list_subset2 = this->getSubset2();
				list_subset2->push_back(subset2);
				loadHandler->handleChild(subset2);
			}
			return;
		}

		if ( nodeName.compare("subset3") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Element_Level3";
			}
			std::shared_ptr<subsetUnionBenchmark::Element_Level3> subset3 = std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level3>(modelFactory->create(typeName));
			if (subset3 != nullptr)
			{
				std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level3, subsetUnionBenchmark::Element>> list_subset3 = this->getSubset3();
				list_subset3->push_back(subset3);
				loadHandler->handleChild(subset3);
			}
			return;
		}

		if ( nodeName.compare("subset4") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Element_Level4";
			}
			std::shared_ptr<subsetUnionBenchmark::Element_Level4> subset4 = std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level4>(modelFactory->create(typeName));
			if (subset4 != nullptr)
			{
				std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level4, subsetUnionBenchmark::Element>> list_subset4 = this->getSubset4();
				list_subset4->push_back(subset4);
				loadHandler->handleChild(subset4);
			}
			return;
		}

		if ( nodeName.compare("subset5") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Element_Level5";
			}
			std::shared_ptr<subsetUnionBenchmark::Element_Level5> subset5 = std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level5>(modelFactory->create(typeName));
			if (subset5 != nullptr)
			{
				std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level5, subsetUnionBenchmark::Element>> list_subset5 = this->getSubset5();
				list_subset5->push_back(subset5);
				loadHandler->handleChild(subset5);
			}
			return;
		}

		if ( nodeName.compare("subset6") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Element_Level6";
			}
			std::shared_ptr<subsetUnionBenchmark::Element_Level6> subset6 = std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level6>(modelFactory->create(typeName));
			if (subset6 != nullptr)
			{
				std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level6, subsetUnionBenchmark::Element>> list_subset6 = this->getSubset6();
				list_subset6->push_back(subset6);
				loadHandler->handleChild(subset6);
			}
			return;
		}

		if ( nodeName.compare("subset7") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Element_Level7";
			}
			std::shared_ptr<subsetUnionBenchmark::Element_Level7> subset7 = std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level7>(modelFactory->create(typeName));
			if (subset7 != nullptr)
			{
				std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level7, subsetUnionBenchmark::Element>> list_subset7 = this->getSubset7();
				list_subset7->push_back(subset7);
				loadHandler->handleChild(subset7);
			}
			return;
		}

		if ( nodeName.compare("subset8") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Element_Level8";
			}
			std::shared_ptr<subsetUnionBenchmark::Element_Level8> subset8 = std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level8>(modelFactory->create(typeName));
			if (subset8 != nullptr)
			{
				std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level8, subsetUnionBenchmark::Element>> list_subset8 = this->getSubset8();
				list_subset8->push_back(subset8);
				loadHandler->handleChild(subset8);
			}
			return;
		}

		if ( nodeName.compare("subset9") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Element_Level9";
			}
			std::shared_ptr<subsetUnionBenchmark::Element_Level9> subset9 = std::dynamic_pointer_cast<subsetUnionBenchmark::Element_Level9>(modelFactory->create(typeName));
			if (subset9 != nullptr)
			{
				std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level9, subsetUnionBenchmark::Element>> list_subset9 = this->getSubset9();
				list_subset9->push_back(subset9);
				loadHandler->handleChild(subset9);
			}
			return;
		}

		if ( nodeName.compare("unionBag") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Element";
			}
			std::shared_ptr<subsetUnionBenchmark::Element> unionBag = std::dynamic_pointer_cast<subsetUnionBenchmark::Element>(modelFactory->create(typeName));
			if (unionBag != nullptr)
			{
				std::shared_ptr<Union<subsetUnionBenchmark::Element>> list_unionBag = this->getUnionBag();
				list_unionBag->push_back(unionBag);
				loadHandler->handleChild(unionBag);
			}
			return;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void ContainerImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ContainerImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ContainerImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<subsetUnionBenchmark::SubsetUnionBenchmarkPackage> package = subsetUnionBenchmark::SubsetUnionBenchmarkPackage::eInstance();

		// Save 'subset1'
		for (std::shared_ptr<subsetUnionBenchmark::Element_Level1> subset1 : *this->getSubset1()) 
		{
			saveHandler->addReference(subset1, "subset1", subset1->eClass() != package->getElement_Level1_EClass());
		}

		// Save 'subset10'
		for (std::shared_ptr<subsetUnionBenchmark::Element_Level10> subset10 : *this->getSubset10()) 
		{
			saveHandler->addReference(subset10, "subset10", subset10->eClass() != package->getElement_Level10_EClass());
		}

		// Save 'subset2'
		for (std::shared_ptr<subsetUnionBenchmark::Element_Level2> subset2 : *this->getSubset2()) 
		{
			saveHandler->addReference(subset2, "subset2", subset2->eClass() != package->getElement_Level2_EClass());
		}

		// Save 'subset3'
		for (std::shared_ptr<subsetUnionBenchmark::Element_Level3> subset3 : *this->getSubset3()) 
		{
			saveHandler->addReference(subset3, "subset3", subset3->eClass() != package->getElement_Level3_EClass());
		}

		// Save 'subset4'
		for (std::shared_ptr<subsetUnionBenchmark::Element_Level4> subset4 : *this->getSubset4()) 
		{
			saveHandler->addReference(subset4, "subset4", subset4->eClass() != package->getElement_Level4_EClass());
		}

		// Save 'subset5'
		for (std::shared_ptr<subsetUnionBenchmark::Element_Level5> subset5 : *this->getSubset5()) 
		{
			saveHandler->addReference(subset5, "subset5", subset5->eClass() != package->getElement_Level5_EClass());
		}

		// Save 'subset6'
		for (std::shared_ptr<subsetUnionBenchmark::Element_Level6> subset6 : *this->getSubset6()) 
		{
			saveHandler->addReference(subset6, "subset6", subset6->eClass() != package->getElement_Level6_EClass());
		}

		// Save 'subset7'
		for (std::shared_ptr<subsetUnionBenchmark::Element_Level7> subset7 : *this->getSubset7()) 
		{
			saveHandler->addReference(subset7, "subset7", subset7->eClass() != package->getElement_Level7_EClass());
		}

		// Save 'subset8'
		for (std::shared_ptr<subsetUnionBenchmark::Element_Level8> subset8 : *this->getSubset8()) 
		{
			saveHandler->addReference(subset8, "subset8", subset8->eClass() != package->getElement_Level8_EClass());
		}

		// Save 'subset9'
		for (std::shared_ptr<subsetUnionBenchmark::Element_Level9> subset9 : *this->getSubset9()) 
		{
			saveHandler->addReference(subset9, "subset9", subset9->eClass() != package->getElement_Level9_EClass());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getContainer_EAttribute_name()) )
		{
			saveHandler->addAttribute("name", this->getName());
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'unionBag'
		std::shared_ptr<Union<subsetUnionBenchmark::Element>> list_unionBag = this->getUnionBag();
		for (std::shared_ptr<subsetUnionBenchmark::Element> unionBag : *list_unionBag) 
		{
			saveHandler->addReference(unionBag, "unionBag", unionBag->eClass() != package->getElement_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

