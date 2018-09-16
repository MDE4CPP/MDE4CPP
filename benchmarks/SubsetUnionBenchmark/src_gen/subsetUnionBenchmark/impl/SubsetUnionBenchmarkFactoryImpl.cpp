#include "subsetUnionBenchmark/impl/SubsetUnionBenchmarkFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "subsetUnionBenchmark/SubsetUnionBenchmarkPackage.hpp"

#include "ecore/EClass.hpp"


#include "subsetUnionBenchmark/impl/ContainerImpl.hpp"
#include "subsetUnionBenchmark/impl/ElementImpl.hpp"
#include "subsetUnionBenchmark/impl/Element_Level1Impl.hpp"
#include "subsetUnionBenchmark/impl/Element_Level10Impl.hpp"
#include "subsetUnionBenchmark/impl/Element_Level2Impl.hpp"
#include "subsetUnionBenchmark/impl/Element_Level3Impl.hpp"
#include "subsetUnionBenchmark/impl/Element_Level4Impl.hpp"
#include "subsetUnionBenchmark/impl/Element_Level5Impl.hpp"
#include "subsetUnionBenchmark/impl/Element_Level6Impl.hpp"
#include "subsetUnionBenchmark/impl/Element_Level7Impl.hpp"
#include "subsetUnionBenchmark/impl/Element_Level8Impl.hpp"
#include "subsetUnionBenchmark/impl/Element_Level9Impl.hpp"

using namespace subsetUnionBenchmark;

//*********************************
// Constructor / Destructor
//*********************************

SubsetUnionBenchmarkFactoryImpl::SubsetUnionBenchmarkFactoryImpl()
{
	m_idMap.insert(std::make_pair("Container", SubsetUnionBenchmarkPackage::CONTAINER_ECLASS));
	m_idMap.insert(std::make_pair("Element", SubsetUnionBenchmarkPackage::ELEMENT_ECLASS));
	m_idMap.insert(std::make_pair("Element_Level1", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL1_ECLASS));
	m_idMap.insert(std::make_pair("Element_Level10", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL10_ECLASS));
	m_idMap.insert(std::make_pair("Element_Level2", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL2_ECLASS));
	m_idMap.insert(std::make_pair("Element_Level3", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL3_ECLASS));
	m_idMap.insert(std::make_pair("Element_Level4", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL4_ECLASS));
	m_idMap.insert(std::make_pair("Element_Level5", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL5_ECLASS));
	m_idMap.insert(std::make_pair("Element_Level6", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL6_ECLASS));
	m_idMap.insert(std::make_pair("Element_Level7", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL7_ECLASS));
	m_idMap.insert(std::make_pair("Element_Level8", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL8_ECLASS));
	m_idMap.insert(std::make_pair("Element_Level9", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL9_ECLASS));
}

SubsetUnionBenchmarkFactoryImpl::~SubsetUnionBenchmarkFactoryImpl()
{
}

SubsetUnionBenchmarkFactory* SubsetUnionBenchmarkFactoryImpl::create()
{
	return new SubsetUnionBenchmarkFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> SubsetUnionBenchmarkFactoryImpl::create(const unsigned int classID,  std::shared_ptr<ecore::EObject> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	switch(classID)
	{
		case SubsetUnionBenchmarkPackage::CONTAINER_ECLASS:
		{
				return this->createContainer();
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_ECLASS:
		{
				return this->createElement();
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL1_ECLASS:
		{
				return this->createElement_Level1();
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL10_ECLASS:
		{
				return this->createElement_Level10();
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL2_ECLASS:
		{
				return this->createElement_Level2();
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL3_ECLASS:
		{
				return this->createElement_Level3();
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL4_ECLASS:
		{
				return this->createElement_Level4();
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL5_ECLASS:
		{
				return this->createElement_Level5();
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL6_ECLASS:
		{
				return this->createElement_Level6();
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL7_ECLASS:
		{
				return this->createElement_Level7();
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL8_ECLASS:
		{
				return this->createElement_Level8();
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL9_ECLASS:
		{
				return this->createElement_Level9();
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << classID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> SubsetUnionBenchmarkFactoryImpl::create(std::shared_ptr<ecore::EClass> _class) const
{
	return create(_class, nullptr);
}

std::shared_ptr<ecore::EObject> SubsetUnionBenchmarkFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	int _classID = _class->eClass()->getClassifierID();
	return create(_classID, _container);
}

std::shared_ptr<ecore::EObject> SubsetUnionBenchmarkFactoryImpl::create(std::string _className) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        unsigned int id = iter->second;
		return create(id);
    }

    return nullptr;
}

std::shared_ptr<ecore::EObject> SubsetUnionBenchmarkFactoryImpl::create(std::string _className, std::shared_ptr<EObject> _container, const unsigned int referenceID) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        unsigned int id = iter->second;
		return create(id, _container, referenceID);
    }

    return nullptr;
}


std::shared_ptr<Container> SubsetUnionBenchmarkFactoryImpl::createContainer() const
{
	std::shared_ptr<ContainerImpl> element(new ContainerImpl());
	element->setThisContainerPtr(element);
	return element;
}
std::shared_ptr<Element> SubsetUnionBenchmarkFactoryImpl::createElement() const
{
	std::shared_ptr<ElementImpl> element(new ElementImpl());
	element->setThisElementPtr(element);
	return element;
}
std::shared_ptr<Element_Level1> SubsetUnionBenchmarkFactoryImpl::createElement_Level1() const
{
	std::shared_ptr<Element_Level1Impl> element(new Element_Level1Impl());
	element->setThisElement_Level1Ptr(element);
	return element;
}
std::shared_ptr<Element_Level10> SubsetUnionBenchmarkFactoryImpl::createElement_Level10() const
{
	std::shared_ptr<Element_Level10Impl> element(new Element_Level10Impl());
	element->setThisElement_Level10Ptr(element);
	return element;
}
std::shared_ptr<Element_Level2> SubsetUnionBenchmarkFactoryImpl::createElement_Level2() const
{
	std::shared_ptr<Element_Level2Impl> element(new Element_Level2Impl());
	element->setThisElement_Level2Ptr(element);
	return element;
}
std::shared_ptr<Element_Level3> SubsetUnionBenchmarkFactoryImpl::createElement_Level3() const
{
	std::shared_ptr<Element_Level3Impl> element(new Element_Level3Impl());
	element->setThisElement_Level3Ptr(element);
	return element;
}
std::shared_ptr<Element_Level4> SubsetUnionBenchmarkFactoryImpl::createElement_Level4() const
{
	std::shared_ptr<Element_Level4Impl> element(new Element_Level4Impl());
	element->setThisElement_Level4Ptr(element);
	return element;
}
std::shared_ptr<Element_Level5> SubsetUnionBenchmarkFactoryImpl::createElement_Level5() const
{
	std::shared_ptr<Element_Level5Impl> element(new Element_Level5Impl());
	element->setThisElement_Level5Ptr(element);
	return element;
}
std::shared_ptr<Element_Level6> SubsetUnionBenchmarkFactoryImpl::createElement_Level6() const
{
	std::shared_ptr<Element_Level6Impl> element(new Element_Level6Impl());
	element->setThisElement_Level6Ptr(element);
	return element;
}
std::shared_ptr<Element_Level7> SubsetUnionBenchmarkFactoryImpl::createElement_Level7() const
{
	std::shared_ptr<Element_Level7Impl> element(new Element_Level7Impl());
	element->setThisElement_Level7Ptr(element);
	return element;
}
std::shared_ptr<Element_Level8> SubsetUnionBenchmarkFactoryImpl::createElement_Level8() const
{
	std::shared_ptr<Element_Level8Impl> element(new Element_Level8Impl());
	element->setThisElement_Level8Ptr(element);
	return element;
}
std::shared_ptr<Element_Level9> SubsetUnionBenchmarkFactoryImpl::createElement_Level9() const
{
	std::shared_ptr<Element_Level9Impl> element(new Element_Level9Impl());
	element->setThisElement_Level9Ptr(element);
	return element;
}

std::shared_ptr<SubsetUnionBenchmarkPackage> SubsetUnionBenchmarkFactoryImpl::getSubsetUnionBenchmarkPackage() const
{
	return SubsetUnionBenchmarkPackage::eInstance();
}
