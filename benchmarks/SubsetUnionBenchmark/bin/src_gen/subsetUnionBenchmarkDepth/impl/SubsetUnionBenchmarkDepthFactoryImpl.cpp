#include "SubsetUnionBenchmarkDepthFactoryImpl.hpp"
#include "SubsetUnionBenchmarkDepthPackage.hpp"

#include "EClass.hpp"

using namespace subsetUnionBenchmarkDepth;

//*********************************
// Constructor / Destructor
//*********************************

SubsetUnionBenchmarkDepthFactoryImpl::SubsetUnionBenchmarkDepthFactoryImpl()
{
	m_idMap.insert(std::pair<std::string,unsigned int>("Container", SubsetUnionBenchmarkDepthPackage::CONTAINER));
	m_idMap.insert(std::pair<std::string,unsigned int>("Container_Level1", SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL1));
	m_idMap.insert(std::pair<std::string,unsigned int>("Container_Level10", SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL10));
	m_idMap.insert(std::pair<std::string,unsigned int>("Container_Level2", SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL2));
	m_idMap.insert(std::pair<std::string,unsigned int>("Container_Level3", SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL3));
	m_idMap.insert(std::pair<std::string,unsigned int>("Container_Level4", SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL4));
	m_idMap.insert(std::pair<std::string,unsigned int>("Container_Level5", SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL5));
	m_idMap.insert(std::pair<std::string,unsigned int>("Container_Level6", SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL6));
	m_idMap.insert(std::pair<std::string,unsigned int>("Container_Level7", SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL7));
	m_idMap.insert(std::pair<std::string,unsigned int>("Container_Level8", SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL8));
	m_idMap.insert(std::pair<std::string,unsigned int>("Container_Level9", SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL9));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element", SubsetUnionBenchmarkDepthPackage::ELEMENT));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level1", SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL1));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level10", SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL10));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level2", SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL2));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level3", SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL3));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level4", SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL4));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level5", SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL5));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level6", SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL6));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level7", SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL7));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level8", SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL8));
	m_idMap.insert(std::pair<std::string,unsigned int>("Element_Level9", SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL9));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExampleModel", SubsetUnionBenchmarkDepthPackage::EXAMPLEMODEL));
}

SubsetUnionBenchmarkDepthFactoryImpl::~SubsetUnionBenchmarkDepthFactoryImpl()
{
}

SubsetUnionBenchmarkDepthFactory* SubsetUnionBenchmarkDepthFactoryImpl::create()
{
	return new SubsetUnionBenchmarkDepthFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> SubsetUnionBenchmarkDepthFactoryImpl::create(const unsigned int classID,  std::shared_ptr<ecore::EObject> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	switch(classID)
	{
		case SubsetUnionBenchmarkDepthPackage::CONTAINER:
		{
				return std::shared_ptr<Container>(this->createContainer());
			
		}
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL1:
		{
				return std::shared_ptr<Container_Level1>(this->createContainer_Level1());
			
		}
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL10:
		{
				return std::shared_ptr<Container_Level10>(this->createContainer_Level10());
			
		}
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL2:
		{
				return std::shared_ptr<Container_Level2>(this->createContainer_Level2());
			
		}
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL3:
		{
				return std::shared_ptr<Container_Level3>(this->createContainer_Level3());
			
		}
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL4:
		{
				return std::shared_ptr<Container_Level4>(this->createContainer_Level4());
			
		}
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL5:
		{
				return std::shared_ptr<Container_Level5>(this->createContainer_Level5());
			
		}
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL6:
		{
				return std::shared_ptr<Container_Level6>(this->createContainer_Level6());
			
		}
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL7:
		{
				return std::shared_ptr<Container_Level7>(this->createContainer_Level7());
			
		}
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL8:
		{
				return std::shared_ptr<Container_Level8>(this->createContainer_Level8());
			
		}
		case SubsetUnionBenchmarkDepthPackage::CONTAINER_LEVEL9:
		{
				return std::shared_ptr<Container_Level9>(this->createContainer_Level9());
			
		}
		case SubsetUnionBenchmarkDepthPackage::ELEMENT:
		{
				return std::shared_ptr<Element>(this->createElement());
			
		}
		case SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL1:
		{
				return std::shared_ptr<Element_Level1>(this->createElement_Level1());
			
		}
		case SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL10:
		{
				return std::shared_ptr<Element_Level10>(this->createElement_Level10());
			
		}
		case SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL2:
		{
				return std::shared_ptr<Element_Level2>(this->createElement_Level2());
			
		}
		case SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL3:
		{
				return std::shared_ptr<Element_Level3>(this->createElement_Level3());
			
		}
		case SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL4:
		{
				return std::shared_ptr<Element_Level4>(this->createElement_Level4());
			
		}
		case SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL5:
		{
				return std::shared_ptr<Element_Level5>(this->createElement_Level5());
			
		}
		case SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL6:
		{
				return std::shared_ptr<Element_Level6>(this->createElement_Level6());
			
		}
		case SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL7:
		{
				return std::shared_ptr<Element_Level7>(this->createElement_Level7());
			
		}
		case SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL8:
		{
				return std::shared_ptr<Element_Level8>(this->createElement_Level8());
			
		}
		case SubsetUnionBenchmarkDepthPackage::ELEMENT_LEVEL9:
		{
				return std::shared_ptr<Element_Level9>(this->createElement_Level9());
			
		}
		case SubsetUnionBenchmarkDepthPackage::EXAMPLEMODEL:
		{
				return std::shared_ptr<ExampleModel>(this->createExampleModel());
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << classID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> SubsetUnionBenchmarkDepthFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container /* = nullptr*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	std::string _className = _class->eClass()->getName();
	return create(_className, _container);
}

std::shared_ptr<ecore::EObject> SubsetUnionBenchmarkDepthFactoryImpl::create(std::string _className) const
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

std::shared_ptr<ecore::EObject> SubsetUnionBenchmarkDepthFactoryImpl::create(std::string _className, std::shared_ptr<EObject> _container, const unsigned int referenceID) const
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


std::shared_ptr<Container> SubsetUnionBenchmarkDepthFactoryImpl::createContainer() const
{
	std::shared_ptr<Container> element(new ContainerImpl());
	return element;
}
std::shared_ptr<Container_Level1> SubsetUnionBenchmarkDepthFactoryImpl::createContainer_Level1() const
{
	std::shared_ptr<Container_Level1> element(new Container_Level1Impl());
	return element;
}
std::shared_ptr<Container_Level10> SubsetUnionBenchmarkDepthFactoryImpl::createContainer_Level10() const
{
	std::shared_ptr<Container_Level10> element(new Container_Level10Impl());
	return element;
}
std::shared_ptr<Container_Level2> SubsetUnionBenchmarkDepthFactoryImpl::createContainer_Level2() const
{
	std::shared_ptr<Container_Level2> element(new Container_Level2Impl());
	return element;
}
std::shared_ptr<Container_Level3> SubsetUnionBenchmarkDepthFactoryImpl::createContainer_Level3() const
{
	std::shared_ptr<Container_Level3> element(new Container_Level3Impl());
	return element;
}
std::shared_ptr<Container_Level4> SubsetUnionBenchmarkDepthFactoryImpl::createContainer_Level4() const
{
	std::shared_ptr<Container_Level4> element(new Container_Level4Impl());
	return element;
}
std::shared_ptr<Container_Level5> SubsetUnionBenchmarkDepthFactoryImpl::createContainer_Level5() const
{
	std::shared_ptr<Container_Level5> element(new Container_Level5Impl());
	return element;
}
std::shared_ptr<Container_Level6> SubsetUnionBenchmarkDepthFactoryImpl::createContainer_Level6() const
{
	std::shared_ptr<Container_Level6> element(new Container_Level6Impl());
	return element;
}
std::shared_ptr<Container_Level7> SubsetUnionBenchmarkDepthFactoryImpl::createContainer_Level7() const
{
	std::shared_ptr<Container_Level7> element(new Container_Level7Impl());
	return element;
}
std::shared_ptr<Container_Level8> SubsetUnionBenchmarkDepthFactoryImpl::createContainer_Level8() const
{
	std::shared_ptr<Container_Level8> element(new Container_Level8Impl());
	return element;
}
std::shared_ptr<Container_Level9> SubsetUnionBenchmarkDepthFactoryImpl::createContainer_Level9() const
{
	std::shared_ptr<Container_Level9> element(new Container_Level9Impl());
	return element;
}
std::shared_ptr<Element> SubsetUnionBenchmarkDepthFactoryImpl::createElement() const
{
	std::shared_ptr<Element> element(new ElementImpl());
	return element;
}
std::shared_ptr<Element_Level1> SubsetUnionBenchmarkDepthFactoryImpl::createElement_Level1() const
{
	std::shared_ptr<Element_Level1> element(new Element_Level1Impl());
	return element;
}
std::shared_ptr<Element_Level10> SubsetUnionBenchmarkDepthFactoryImpl::createElement_Level10() const
{
	std::shared_ptr<Element_Level10> element(new Element_Level10Impl());
	return element;
}
std::shared_ptr<Element_Level2> SubsetUnionBenchmarkDepthFactoryImpl::createElement_Level2() const
{
	std::shared_ptr<Element_Level2> element(new Element_Level2Impl());
	return element;
}
std::shared_ptr<Element_Level3> SubsetUnionBenchmarkDepthFactoryImpl::createElement_Level3() const
{
	std::shared_ptr<Element_Level3> element(new Element_Level3Impl());
	return element;
}
std::shared_ptr<Element_Level4> SubsetUnionBenchmarkDepthFactoryImpl::createElement_Level4() const
{
	std::shared_ptr<Element_Level4> element(new Element_Level4Impl());
	return element;
}
std::shared_ptr<Element_Level5> SubsetUnionBenchmarkDepthFactoryImpl::createElement_Level5() const
{
	std::shared_ptr<Element_Level5> element(new Element_Level5Impl());
	return element;
}
std::shared_ptr<Element_Level6> SubsetUnionBenchmarkDepthFactoryImpl::createElement_Level6() const
{
	std::shared_ptr<Element_Level6> element(new Element_Level6Impl());
	return element;
}
std::shared_ptr<Element_Level7> SubsetUnionBenchmarkDepthFactoryImpl::createElement_Level7() const
{
	std::shared_ptr<Element_Level7> element(new Element_Level7Impl());
	return element;
}
std::shared_ptr<Element_Level8> SubsetUnionBenchmarkDepthFactoryImpl::createElement_Level8() const
{
	std::shared_ptr<Element_Level8> element(new Element_Level8Impl());
	return element;
}
std::shared_ptr<Element_Level9> SubsetUnionBenchmarkDepthFactoryImpl::createElement_Level9() const
{
	std::shared_ptr<Element_Level9> element(new Element_Level9Impl());
	return element;
}
std::shared_ptr<ExampleModel> SubsetUnionBenchmarkDepthFactoryImpl::createExampleModel() const
{
	std::shared_ptr<ExampleModel> element(new ExampleModelImpl());
	return element;
}

std::shared_ptr<SubsetUnionBenchmarkDepthPackage> SubsetUnionBenchmarkDepthFactoryImpl::getSubsetUnionBenchmarkDepthPackage() const
{
	return SubsetUnionBenchmarkDepthPackage::eInstance();
}
