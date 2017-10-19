#include "ContainerImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes
#include "Element.hpp"

#include "Element_Level1.hpp"

#include "Element_Level10.hpp"

#include "Element_Level2.hpp"

#include "Element_Level3.hpp"

#include "Element_Level4.hpp"

#include "Element_Level5.hpp"

#include "Element_Level6.hpp"

#include "Element_Level7.hpp"

#include "Element_Level8.hpp"

#include "Element_Level9.hpp"


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
		m_union.reset(new Union<subsetUnionBenchmark::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_union - Union<subsetUnionBenchmark::Element>()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_subset1->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset1 - Subset<subsetUnionBenchmark::Element_Level1, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset10->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset10 - Subset<subsetUnionBenchmark::Element_Level10, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset2->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset2 - Subset<subsetUnionBenchmark::Element_Level2, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset3->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset3 - Subset<subsetUnionBenchmark::Element_Level3, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset4->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset4 - Subset<subsetUnionBenchmark::Element_Level4, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset5->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset5 - Subset<subsetUnionBenchmark::Element_Level5, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset6->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset6 - Subset<subsetUnionBenchmark::Element_Level6, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset7->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset7 - Subset<subsetUnionBenchmark::Element_Level7, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset8->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset8 - Subset<subsetUnionBenchmark::Element_Level8, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset9->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset9 - Subset<subsetUnionBenchmark::Element_Level9, subsetUnionBenchmark::Element >(m_union)" << std::endl;
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
		m_subset1->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset1 - Subset<subsetUnionBenchmark::Element_Level1, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset10->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset10 - Subset<subsetUnionBenchmark::Element_Level10, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset2->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset2 - Subset<subsetUnionBenchmark::Element_Level2, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset3->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset3 - Subset<subsetUnionBenchmark::Element_Level3, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset4->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset4 - Subset<subsetUnionBenchmark::Element_Level4, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset5->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset5 - Subset<subsetUnionBenchmark::Element_Level5, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset6->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset6 - Subset<subsetUnionBenchmark::Element_Level6, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset7->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset7 - Subset<subsetUnionBenchmark::Element_Level7, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset8->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset8 - Subset<subsetUnionBenchmark::Element_Level8, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_subset9->initSubset(m_union);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subset9 - Subset<subsetUnionBenchmark::Element_Level9, subsetUnionBenchmark::Element >(m_union)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  ContainerImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ContainerImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ContainerImpl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getContainer();
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
std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level1, subsetUnionBenchmark::Element > > ContainerImpl::getSubset1() const
{

    return m_subset1;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level10, subsetUnionBenchmark::Element > > ContainerImpl::getSubset10() const
{

    return m_subset10;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level2, subsetUnionBenchmark::Element > > ContainerImpl::getSubset2() const
{

    return m_subset2;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level3, subsetUnionBenchmark::Element > > ContainerImpl::getSubset3() const
{

    return m_subset3;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level4, subsetUnionBenchmark::Element > > ContainerImpl::getSubset4() const
{

    return m_subset4;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level5, subsetUnionBenchmark::Element > > ContainerImpl::getSubset5() const
{

    return m_subset5;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level6, subsetUnionBenchmark::Element > > ContainerImpl::getSubset6() const
{

    return m_subset6;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level7, subsetUnionBenchmark::Element > > ContainerImpl::getSubset7() const
{

    return m_subset7;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level8, subsetUnionBenchmark::Element > > ContainerImpl::getSubset8() const
{

    return m_subset8;
}


std::shared_ptr<Subset<subsetUnionBenchmark::Element_Level9, subsetUnionBenchmark::Element > > ContainerImpl::getSubset9() const
{

    return m_subset9;
}





//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<subsetUnionBenchmark::Element> > ContainerImpl::getUnion() const
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
		case SubsetUnionBenchmarkPackage::CONTAINER_NAME:
			return getName(); //01
		case SubsetUnionBenchmarkPackage::CONTAINER_SUBSET1:
			return getSubset1(); //02
		case SubsetUnionBenchmarkPackage::CONTAINER_SUBSET10:
			return getSubset10(); //011
		case SubsetUnionBenchmarkPackage::CONTAINER_SUBSET2:
			return getSubset2(); //03
		case SubsetUnionBenchmarkPackage::CONTAINER_SUBSET3:
			return getSubset3(); //04
		case SubsetUnionBenchmarkPackage::CONTAINER_SUBSET4:
			return getSubset4(); //05
		case SubsetUnionBenchmarkPackage::CONTAINER_SUBSET5:
			return getSubset5(); //06
		case SubsetUnionBenchmarkPackage::CONTAINER_SUBSET6:
			return getSubset6(); //07
		case SubsetUnionBenchmarkPackage::CONTAINER_SUBSET7:
			return getSubset7(); //08
		case SubsetUnionBenchmarkPackage::CONTAINER_SUBSET8:
			return getSubset8(); //09
		case SubsetUnionBenchmarkPackage::CONTAINER_SUBSET9:
			return getSubset9(); //010
		case SubsetUnionBenchmarkPackage::CONTAINER_UNION:
			return getUnion(); //00
	}
	return boost::any();
}
