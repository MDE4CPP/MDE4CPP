/*
 * SaveHandler.cpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#include "persistence/base/SaveHandler.hpp"
#include "PersistenceDefine.hpp"

#include <iostream>
#include <string>
#include <sstream> // used for addReferences()

#include "ecore/EObject.hpp"
#include "persistence/base/HandlerHelper.hpp"
#include "persistence/crossguid/guid.hpp"

using namespace persistence::base;

SaveHandler::SaveHandler()
{
	m_rootObject = nullptr;
	m_isXSIMode = true;
	m_savedObjects.reset(new Bag<ecore::EObject>());
}

SaveHandler::~SaveHandler()
{
}

/**/
std::string SaveHandler::getPrefix()
{
	return m_rootPrefix;
}

void SaveHandler::setRootObject(std::shared_ptr<ecore::EObject> object)
{
	if (m_rootObject == nullptr)
	{
		m_rootObject = object;
	}
}

void SaveHandler::addAttribute(const std::string &name, bool value)
{
	addAttribute(name, (value ? (std::string) "true" : (std::string) "false"));
}

std::string SaveHandler::extractType(std::shared_ptr<ecore::EObject> obj) const
{
	return persistence::base::HandlerHelper::extractType(obj, m_rootPrefix);
}

void SaveHandler::setThisPtr(std::shared_ptr<SaveHandler> thisPtr)
{
	m_thisPtr = thisPtr;
}

void SaveHandler::setIsXSIMode(bool value)
{
	m_isXSIMode = value;
}

void SaveHandler::setTypesMap(std::map<std::string, std::shared_ptr<ecore::EObject>> typesMap)
{
	std::map<std::string, std::shared_ptr<ecore::EObject>>::iterator iter = typesMap.begin();
	std::map<std::string, std::shared_ptr<ecore::EObject>>::iterator end = typesMap.end();
	while (iter != end)
	{
		m_refObjectName_map.insert(std::pair<std::shared_ptr<ecore::EObject>, std::string>(iter->second, iter->first));
		iter++;
	}
}


