#include "SubsetUnionBenchmarkFactoryImpl.hpp"
#include "SubsetUnionBenchmarkPackage.hpp"

#include "EClass.hpp"

using namespace subsetUnionBenchmark;

//*********************************
// Constructor / Destructor
//*********************************

SubsetUnionBenchmarkFactoryImpl::SubsetUnionBenchmarkFactoryImpl()
{
	m_idMap.insert(std::pair<std::string,unsigned int>("Container", SubsetUnionBenchmarkPackage::CONTAINER));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element", SubsetUnionBenchmarkPackage::ELEMENT));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level1", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL1));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level10", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL10));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level2", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL2));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level3", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL3));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level4", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL4));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level5", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL5));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level6", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL6));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level7", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL7));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level8", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL8));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level9", SubsetUnionBenchmarkPackage::ELEMENT_LEVEL9));
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
		case SubsetUnionBenchmarkPackage::CONTAINER:
		{
				return std::shared_ptr<Container>(this->createContainer());
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT:
		{
				return std::shared_ptr<Element>(this->createElement());
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL1:
		{
				return std::shared_ptr<Element_Level1>(this->createElement_Level1());
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL10:
		{
				return std::shared_ptr<Element_Level10>(this->createElement_Level10());
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL2:
		{
				return std::shared_ptr<Element_Level2>(this->createElement_Level2());
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL3:
		{
				return std::shared_ptr<Element_Level3>(this->createElement_Level3());
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL4:
		{
				return std::shared_ptr<Element_Level4>(this->createElement_Level4());
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL5:
		{
				return std::shared_ptr<Element_Level5>(this->createElement_Level5());
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL6:
		{
				return std::shared_ptr<Element_Level6>(this->createElement_Level6());
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL7:
		{
				return std::shared_ptr<Element_Level7>(this->createElement_Level7());
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL8:
		{
				return std::shared_ptr<Element_Level8>(this->createElement_Level8());
			
		}
		case SubsetUnionBenchmarkPackage::ELEMENT_LEVEL9:
		{
				return std::shared_ptr<Element_Level9>(this->createElement_Level9());
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << classID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> SubsetUnionBenchmarkFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container /* = nullptr*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	std::string _className = _class->eClass()->getName();
	return create(_className, _container);
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
	std::shared_ptr<Container> element(new ContainerImpl());
	return element;
}
std::shared_ptr<Element> SubsetUnionBenchmarkFactoryImpl::createElement() const
{
	std::shared_ptr<Element> element(new ElementImpl());
	return element;
}
std::shared_ptr<Element_Level1> SubsetUnionBenchmarkFactoryImpl::createElement_Level1() const
{
	std::shared_ptr<Element_Level1> element(new Element_Level1Impl());
	return element;
}
std::shared_ptr<Element_Level10> SubsetUnionBenchmarkFactoryImpl::createElement_Level10() const
{
	std::shared_ptr<Element_Level10> element(new Element_Level10Impl());
	return element;
}
std::shared_ptr<Element_Level2> SubsetUnionBenchmarkFactoryImpl::createElement_Level2() const
{
	std::shared_ptr<Element_Level2> element(new Element_Level2Impl());
	return element;
}
std::shared_ptr<Element_Level3> SubsetUnionBenchmarkFactoryImpl::createElement_Level3() const
{
	std::shared_ptr<Element_Level3> element(new Element_Level3Impl());
	return element;
}
std::shared_ptr<Element_Level4> SubsetUnionBenchmarkFactoryImpl::createElement_Level4() const
{
	std::shared_ptr<Element_Level4> element(new Element_Level4Impl());
	return element;
}
std::shared_ptr<Element_Level5> SubsetUnionBenchmarkFactoryImpl::createElement_Level5() const
{
	std::shared_ptr<Element_Level5> element(new Element_Level5Impl());
	return element;
}
std::shared_ptr<Element_Level6> SubsetUnionBenchmarkFactoryImpl::createElement_Level6() const
{
	std::shared_ptr<Element_Level6> element(new Element_Level6Impl());
	return element;
}
std::shared_ptr<Element_Level7> SubsetUnionBenchmarkFactoryImpl::createElement_Level7() const
{
	std::shared_ptr<Element_Level7> element(new Element_Level7Impl());
	return element;
}
std::shared_ptr<Element_Level8> SubsetUnionBenchmarkFactoryImpl::createElement_Level8() const
{
	std::shared_ptr<Element_Level8> element(new Element_Level8Impl());
	return element;
}
std::shared_ptr<Element_Level9> SubsetUnionBenchmarkFactoryImpl::createElement_Level9() const
{
	std::shared_ptr<Element_Level9> element(new Element_Level9Impl());
	return element;
}

std::shared_ptr<SubsetUnionBenchmarkPackage> SubsetUnionBenchmarkFactoryImpl::getSubsetUnionBenchmarkPackage() const
{
	return SubsetUnionBenchmarkPackage::eInstance();
}
