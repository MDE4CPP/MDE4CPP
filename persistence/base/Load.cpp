/*
 * Load.cpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#include "persistence/base/Load.hpp"

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

#include "pluginFramework/EcoreModelPlugin.hpp"
#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "pluginFramework/PluginFramework.hpp"
#include "pluginFramework/UMLModelPlugin.hpp"

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
	std::shared_ptr<ecore::EObject> rootElement = nullptr;

	if (read(filename) == false)
	{
		MSG_ERROR(MSG_FLF <<" Occurred during reading file.");
		rootElement = nullptr;
	}
	else
	{
		MSG_DEBUG("Reading file successfully.");

		// Use PluginFramework to create factory and package by given prefix (eg. ecore, uml,...)
		std::string prefix = m_handler->getPrefix();
		std::string rootName = m_handler->getRootName();

		std::shared_ptr<PluginFramework> pluginFramework = PluginFramework::eInstance();
		std::shared_ptr<MDE4CPPPlugin> plugin = pluginFramework->findPluginByName(prefix);
		std::shared_ptr<EcoreModelPlugin> ecorePlugin = std::dynamic_pointer_cast<EcoreModelPlugin>(plugin);

		if (ecorePlugin && (prefix.compare("ecore") == 0))
		{
			//std::shared_ptr<ecore::EFactory> factory = ecorePlugin->getFactory(); // TODO get Factory of ecorePlugin
			std::shared_ptr<ecore::EcoreFactory> factory = std::dynamic_pointer_cast<ecore::EcoreFactory>(ecorePlugin->getFactory());
			rootElement = factory->create(rootName);
		}
		else if (ecorePlugin && (prefix.compare("uml") == 0))
		{
			//std::shared_ptr<ecore::EFactory> factory = ecorePlugin->getFactory(); // TODO get Factory of ecorePlugin
			std::shared_ptr<uml::UmlFactory> factory = std::dynamic_pointer_cast<uml::UmlFactory>(ecorePlugin->getFactory());
			rootElement = factory->create(rootName);
		}
		else
		{
			MSG_ERROR(MSG_FLF << " Given Plugin name '" << prefix << "' is not supported or not found by PluginFramework");
			return rootElement;
		}

		// Create root object of model
		m_handler->handleRoot(rootElement);

		std::shared_ptr<ecore::EPackage> package = ecorePlugin->getPackage();
		readDataTypes(package);

		// Resolve unresolved references that are stored during loading
		m_handler->resolveReferences();

	}

	return rootElement;
}

void Load::readDataTypes(const std::string prefix)
{
	std::shared_ptr<PluginFramework> pluginFramework = PluginFramework::eInstance();
	std::shared_ptr<MDE4CPPPlugin> plugin = pluginFramework->findPluginByName(prefix);

	if (plugin)
	{
		std::shared_ptr<EcoreModelPlugin> ecorePlugin = std::dynamic_pointer_cast<EcoreModelPlugin>(plugin);
		std::shared_ptr<ecore::EPackage> package = ecorePlugin->getPackage();
		readDataTypes(package);
	}
}

void Load::readDataTypes(std::shared_ptr<ecore::EPackage> package)
{


	// Add EClassifiers of package to map if not already in // TODO this sequence should not necessary, because Handlers should use PluginFramework to find correct objects and types
	std::shared_ptr<Bag<ecore::EClassifier>> eClassifiers = package->getEClassifiers();
	for (std::shared_ptr<ecore::EClassifier> eClassifier : *eClassifiers)
	{
		// Filter only EDataType objects and add to handler's internal map
		std::shared_ptr<ecore::EClass> _metaClass = eClassifier->eClass();
		m_handler->addToMap(eClassifier, false); // TODO add default parameter force=true to addToMap()
	}
}
