/*
 * Load.cpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#include "persistence/base/Load.hpp"

#ifdef NDEBUG
#define MSG_DEBUG(a) /**/
#else
#define MSG_DEBUG(a) std::cout << "| DEBUG    | " << a << std::endl
#endif
#define MSG_WARNING(a) std::cout << "| WARNING  | "<< a << std::endl
#define MSG_ERROR(a) std::cout << "| ERROR    | " << a << std::endl
#define MSG_FLF __FILE__ << ":" << __LINE__ << " " << __FUNCTION__ << "() "

#include <iostream>

#include "abstractDataTypes/Bag.hpp"
#include "boost/any.hpp"

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

		std::shared_ptr<PluginFramework> pluginFramework = PluginFramework::eInstance();
		std::shared_ptr<MDE4CPPPlugin> plugin = pluginFramework->findPluginByName(prefix);

		if (!plugin)
		{
			MSG_ERROR(MSG_FLF << " Given Plugin name '" << prefix << "' is not supported or not found by PluginFramework");
			return nullptr;
		}

		// Create root object of model
		std::shared_ptr<ecore::EObject> rootElement = plugin->create(rootName);
		m_handler->handleRoot(rootElement);

		std::shared_ptr<ecore::EPackage> package = plugin->getEPackage();
		m_handler->loadTypes(package);

		// Resolve unresolved references that are stored during loading
		m_handler->resolveReferences();
		return rootElement;
	}
}

std::map<std::string, std::shared_ptr<ecore::EObject>> Load::getTypesMap()
{
	return m_handler->getTypesMap();
}
