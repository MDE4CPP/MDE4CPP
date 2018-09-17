/*
 * XMLPersistence.cpp
 *
 *  Created on: 25.01.2018
 *      Author: Alexander
 */

#include "persistence/xml/XMLPersistence.hpp"

#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"
#include "persistence/base/Load.hpp"
#include "persistence/base/Save.hpp"
#include "persistence/xml/XMLSave.hpp"
#include "persistence/xml/XMLLoad.hpp"

using namespace persistence::xml;

#ifdef NDEBUG
#define MSG_DEBUG(a) /**/
#else
#define MSG_DEBUG(a) std::cout << "| DEBUG    | " << a << std::endl
#endif
#define MSG_WARNING(a) std::cout << "| WARNING  | "<< a << std::endl
#define MSG_ERROR(a) std::cout << "| ERROR    | " << a << std::endl
#define MSG_FLF __FILE__ << ":" << __LINE__ << " " << __FUNCTION__ << "() "

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
