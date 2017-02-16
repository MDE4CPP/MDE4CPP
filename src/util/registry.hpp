#ifndef REGISTRY_HPP
#define REGISTRY_HPP

#include <map>
#include <string>

#include "EPackage.hpp"
#include "EFactory.hpp"


namespace util
{




class Registry
{
public:
    Registry();

    static Registry * eInstance();

    ecore::EPackage* getEPackage(std::string nsURI);
     ecore::EFactory* getEFactory(std::string nsURI);

    void put(std::string nsURI, ecore::EPackage* package);

private:

    static Registry * m_instance;
    std::map<const std::string, ecore::EPackage*> m_packageMap;

};

}

#endif // REGISTRY_HPP
