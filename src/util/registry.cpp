#include "registry.hpp"

using namespace util;

Registry::Registry()
{
}

//static initialisation
Registry* Registry::m_instance=nullptr;

Registry* Registry::eInstance()
{
    if(m_instance==nullptr)
    {
        //create a new Factoryimplementation
        m_instance = new Registry();
    }
    return m_instance;
}

 ecore::EPackage* Registry::getEPackage(std::string nsURI)
{
    return m_packageMap[nsURI];
}

 ecore::EFactory* Registry::getEFactory(std::string nsURI)
{
    if(m_packageMap[nsURI])
    {
        return m_packageMap[nsURI]->getEFactoryInstance();
    }
    return nullptr;
}

void Registry::put(std::string nsURI,  ecore::EPackage * package)
{
    m_packageMap.insert(std::pair<std::string, ecore::EPackage *>(nsURI,package));
}
