#include "util/registry.hpp"

#include "ecore/EPackage.hpp"
#include "ecore/EFactory.hpp"

using namespace util;

Registry::Registry()
{
}

//static initialisation
Registry* Registry::m_instance = nullptr;

Registry* Registry::eInstance()
{
	if (m_instance == nullptr)
	{
		//create a new Factoryimplementation
		m_instance = new Registry();
	}
	return m_instance;
}

std::shared_ptr<ecore::EPackage> Registry::getEPackage(std::string nsURI)
{
	return m_packageMap[nsURI];
}

std::shared_ptr<ecore::EFactory> Registry::getEFactory(std::string nsURI)
{
	if (m_packageMap[nsURI])
	{
		return m_packageMap[nsURI]->getEFactoryInstance();
	}
	return nullptr;
}

void Registry::put(std::string nsURI, std::shared_ptr<ecore::EPackage> package)
{
	m_packageMap.insert(std::pair<std::string, std::shared_ptr<ecore::EPackage>>(nsURI, package));
}
