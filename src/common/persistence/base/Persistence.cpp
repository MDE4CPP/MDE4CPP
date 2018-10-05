/*
 * Persistence.cpp
 *
 *  Created on: 16.05.2017
 *      Author: Alexander
 */

#include "persistence/base/Persistence.hpp"

#include <iostream>
#include "ecore/EObject.hpp"

using namespace persistence::base;

Persistence::Persistence()
{
}

Persistence::~Persistence()
{
}

std::map<std::string, std::shared_ptr<ecore::EObject>> Persistence::getObjectReferenceMap()
{
	return m_refToObject_map;
}
