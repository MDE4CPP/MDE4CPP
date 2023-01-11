#include "UML4CPPProfile/impl/UML4CPPProfileFactoryImpl.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/Class.hpp"
#include <cassert>

#include "UML4CPPProfile/impl/DoNotGenerateImpl.hpp"
#include "UML4CPPProfile/impl/ExternalLibraryImpl.hpp"
#include "UML4CPPProfile/impl/GetterNameImpl.hpp"
#include "UML4CPPProfile/impl/MainBehaviorImpl.hpp"
#include "UML4CPPProfile/impl/NonExecutableImpl.hpp"
#include "UML4CPPProfile/impl/SetterNameImpl.hpp"
#include "UML4CPPProfile/impl/SingletonImpl.hpp"
#include "UML4CPPProfile/impl/UML4CPPPackageImpl.hpp"


using namespace UML4CPPProfile;
//*********************************
// Constructor / Destructor
//*********************************
UML4CPPProfileFactoryImpl::UML4CPPProfileFactoryImpl()
{
	m_idMap.insert(std::make_pair("UML4CPPProfile::DoNotGenerate", UML4CPPProfilePackage::DONOTGENERATE_STEREOTYPE));
	m_idMap.insert(std::make_pair("UML4CPPProfile::ExternalLibrary", UML4CPPProfilePackage::EXTERNALLIBRARY_STEREOTYPE));
	m_idMap.insert(std::make_pair("UML4CPPProfile::GetterName", UML4CPPProfilePackage::GETTERNAME_STEREOTYPE));
	m_idMap.insert(std::make_pair("UML4CPPProfile::MainBehavior", UML4CPPProfilePackage::MAINBEHAVIOR_STEREOTYPE));
	m_idMap.insert(std::make_pair("UML4CPPProfile::NonExecutable", UML4CPPProfilePackage::NONEXECUTABLE_STEREOTYPE));
	m_idMap.insert(std::make_pair("UML4CPPProfile::SetterName", UML4CPPProfilePackage::SETTERNAME_STEREOTYPE));
	m_idMap.insert(std::make_pair("UML4CPPProfile::Singleton", UML4CPPProfilePackage::SINGLETON_STEREOTYPE));
	m_idMap.insert(std::make_pair("UML4CPPProfile::UML4CPPPackage", UML4CPPProfilePackage::UML4CPPPACKAGE_STEREOTYPE));
}

UML4CPPProfileFactoryImpl::~UML4CPPProfileFactoryImpl()
{
}

UML4CPPProfileFactory* UML4CPPProfileFactoryImpl::create()
{
	return new UML4CPPProfileFactoryImpl();
}

//*********************************
// creators
//*********************************
std::shared_ptr<uml::Element> UML4CPPProfileFactoryImpl::create(const unsigned int _metaClassId,  std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	switch(_metaClassId)
	{
		case UML4CPPProfilePackage::DONOTGENERATE_STEREOTYPE:
		{
				return this->createDoNotGenerate(_metaClassId);
			
		}
		case UML4CPPProfilePackage::EXTERNALLIBRARY_STEREOTYPE:
		{
				return this->createExternalLibrary(_metaClassId);
			
		}
		case UML4CPPProfilePackage::GETTERNAME_STEREOTYPE:
		{
				return this->createGetterName(_metaClassId);
			
		}
		case UML4CPPProfilePackage::MAINBEHAVIOR_STEREOTYPE:
		{
				return this->createMainBehavior(_metaClassId);
			
		}
		case UML4CPPProfilePackage::NONEXECUTABLE_STEREOTYPE:
		{
				return this->createNonExecutable(_metaClassId);
			
		}
		case UML4CPPProfilePackage::SETTERNAME_STEREOTYPE:
		{
				return this->createSetterName(_metaClassId);
			
		}
		case UML4CPPProfilePackage::SINGLETON_STEREOTYPE:
		{
				return this->createSingleton(_metaClassId);
			
		}
		case UML4CPPProfilePackage::UML4CPPPACKAGE_STEREOTYPE:
		{
				return this->createUML4CPPPackage(_metaClassId);
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << _metaClassId <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<uml::Element> UML4CPPProfileFactoryImpl::create(std::shared_ptr<uml::Class> _class, std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	if(_class->getIsAbstract())
    {
    	return nullptr;
    }
	std::string typeName = _class->getQualifiedName();
	return create(typeName,container,referenceID);
}

std::shared_ptr<uml::Element> UML4CPPProfileFactoryImpl::create(std::string _className, std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the getMetaElementId()
        unsigned int id = iter->second;
		return create(id,container,referenceID);
    }
    return nullptr;
}

//--------------------------
//create-Functions for class 'DoNotGenerate'
//--------------------------
std::shared_ptr<UML4CPPProfile::DoNotGenerate> UML4CPPProfileFactoryImpl::createDoNotGenerate(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<UML4CPPProfile::DoNotGenerateImpl> element(new UML4CPPProfile::DoNotGenerateImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDoNotGeneratePtr(element);
	element->instantiate();
	return element;
}


//--------------------------
//create-Functions for class 'ExternalLibrary'
//--------------------------
std::shared_ptr<UML4CPPProfile::ExternalLibrary> UML4CPPProfileFactoryImpl::createExternalLibrary(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<UML4CPPProfile::ExternalLibraryImpl> element(new UML4CPPProfile::ExternalLibraryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExternalLibraryPtr(element);
	element->instantiate();
	return element;
}


//--------------------------
//create-Functions for class 'GetterName'
//--------------------------
std::shared_ptr<UML4CPPProfile::GetterName> UML4CPPProfileFactoryImpl::createGetterName(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<UML4CPPProfile::GetterNameImpl> element(new UML4CPPProfile::GetterNameImpl());
	element->setMetaElementID(metaElementID);
	element->setThisGetterNamePtr(element);
	element->instantiate();
	return element;
}


//--------------------------
//create-Functions for class 'MainBehavior'
//--------------------------
std::shared_ptr<UML4CPPProfile::MainBehavior> UML4CPPProfileFactoryImpl::createMainBehavior(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<UML4CPPProfile::MainBehaviorImpl> element(new UML4CPPProfile::MainBehaviorImpl());
	element->setMetaElementID(metaElementID);
	element->setThisMainBehaviorPtr(element);
	element->instantiate();
	return element;
}


//--------------------------
//create-Functions for class 'NonExecutable'
//--------------------------
std::shared_ptr<UML4CPPProfile::NonExecutable> UML4CPPProfileFactoryImpl::createNonExecutable(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<UML4CPPProfile::NonExecutableImpl> element(new UML4CPPProfile::NonExecutableImpl());
	element->setMetaElementID(metaElementID);
	element->setThisNonExecutablePtr(element);
	element->instantiate();
	return element;
}


//--------------------------
//create-Functions for class 'SetterName'
//--------------------------
std::shared_ptr<UML4CPPProfile::SetterName> UML4CPPProfileFactoryImpl::createSetterName(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<UML4CPPProfile::SetterNameImpl> element(new UML4CPPProfile::SetterNameImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSetterNamePtr(element);
	element->instantiate();
	return element;
}


//--------------------------
//create-Functions for class 'Singleton'
//--------------------------
std::shared_ptr<UML4CPPProfile::Singleton> UML4CPPProfileFactoryImpl::createSingleton(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<UML4CPPProfile::SingletonImpl> element(new UML4CPPProfile::SingletonImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSingletonPtr(element);
	element->instantiate();
	return element;
}


//--------------------------
//create-Functions for class 'UML4CPPPackage'
//--------------------------
std::shared_ptr<UML4CPPProfile::UML4CPPPackage> UML4CPPProfileFactoryImpl::createUML4CPPPackage(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<UML4CPPProfile::UML4CPPPackageImpl> element(new UML4CPPProfile::UML4CPPPackageImpl());
	element->setMetaElementID(metaElementID);
	element->setThisUML4CPPPackagePtr(element);
	element->instantiate();
	return element;
}





std::shared_ptr<UML4CPPProfilePackage> UML4CPPProfileFactoryImpl::getUML4CPPProfilePackage()
{
	return UML4CPPProfilePackage::eInstance();
}
