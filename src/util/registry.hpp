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

std::shared_ptr<ecore::EPackage> getEPackage(std::string nsURI);
std::shared_ptr<ecore::EFactory> getEFactory(std::string nsURI);
void put(std::string nsURI, std::shared_ptr<ecore::EPackage> package);

private:
static Registry * m_instance;
std::map<const std::string, std::shared_ptr<ecore::EPackage> > m_packageMap;
};
}
#endif
