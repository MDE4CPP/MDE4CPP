/*
 * Load.cpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#include "persistence/base/Load.hpp"
#include "PersistenceDefine.hpp"

#include <iostream>

#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"

#include "ecore/EClass.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EcoreFactory.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"

#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "persistence/base/LoadHandler.hpp"

#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "pluginFramework/PluginFramework.hpp"

using namespace persistence::base;

Load::Load()
{
}

Load::~Load()
{
}

std::shared_ptr<ecore::EObject> Load::load(const std::string &filename)
{
	MSG_DEBUG("Reading file '" << filename << "'");
	if (read(filename) == false)
	{
		MSG_ERROR(MSG_FLF <<" Occurred during reading file.");
		return nullptr;
	}
	else
	{
		MSG_DEBUG("Reading file successfully.");

		// Use PluginFramework to create factory and package by given prefix (eg. ecore, uml,...)
		std::string prefix = m_handler->getPrefix();
		std::string rootName = m_handler->getRootName();

		std::shared_ptr<MDE4CPPPlugin> plugin = PluginFramework::eInstance()->findPluginByName(prefix);
		if (!plugin)
		{
			MSG_ERROR(MSG_FLF << " Given Plugin name '" << prefix << "' is not supported or not found by PluginFramework");
			return nullptr;
		}

		// Create root object of model
		std::shared_ptr<ecore::EObject> rootElement = plugin->create(rootName);
		m_handler->handleRoot(rootElement);

		// Resolve unresolved references that are stored during loading
		m_handler->resolveReferences();
		return rootElement;
	}
}

std::map<std::string, std::shared_ptr<ecore::EObject>> Load::getTypesMap()
{
	return m_handler->getTypesMap();
}
