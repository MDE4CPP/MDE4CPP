/*
 * XMLPersistence.cpp
 *
 *  Created on: 25.01.2018
 *      Author: Alexander
 */

#include "persistence/xml/XMLPersistence.hpp"
#include "persistence/base/Persistence.hpp"
#include "persistence/base/PersistenceDefine.hpp"

#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"
#include "persistence/base/Load.hpp"
#include "persistence/base/Save.hpp"
#include "persistence/xml/XMLSave.hpp"
#include "persistence/xml/XMLLoad.hpp"

using namespace persistence::xml;

#include <iostream>

XMLPersistence::XMLPersistence()
{
}

XMLPersistence::~XMLPersistence()
{
}

std::shared_ptr<ecore::EObject> XMLPersistence::load(const std::string& filename)
{
	if (isValidFile(filename) == false)
	{
		MSG_ERROR(MSG_FLF << "Given filename: '" << filename << "' is not valid!");
		return nullptr;
	}

	MSG_DEBUG("Load from XML-File");

	std::shared_ptr<persistence::xml::XMLLoad> xmlLoad(new persistence::xml::XMLLoad());

	std::shared_ptr<ecore::EObject> object = xmlLoad->load(filename);
	m_refToObject_map = xmlLoad->getTypesMap();
	return object;
}

bool XMLPersistence::save(const std::string& filename, std::shared_ptr<ecore::EObject> model, std::shared_ptr<ecore::EPackage> metaMetaPackage, bool xsiMode)
{
	if (isValidFile(filename) == false)
	{
		MSG_ERROR(MSG_FLF << "Given filename: '" << filename << "' is not valid!");
		return false;
	}

	MSG_DEBUG("Save as XML-File");

	std::shared_ptr<persistence::xml::XMLSave> xmlSave(new persistence::xml::XMLSave());
	xmlSave->setTypesMap(m_refToObject_map);
	return xmlSave->save(filename, model, metaMetaPackage, xsiMode);
}


bool XMLPersistence::isValidFile(const std::string& filename)
{
	// TODO needs implementation
	MSG_WARNING(MSG_FLF << " is not implemented!");

	return true;
}
