/*
 * Load.cpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#include "persistence/base/Load.hpp"

#include "boost/any.hpp"

#include "ecore/EClass.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EcoreFactory.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"

#include "persistence/base/LoadHandler.hpp"

#include "pluginFramework/EcoreModelPlugin.hpp"
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
	std::shared_ptr<ecore::EObject> retvalue = nullptr;
	std::string prefix;

	MSG_DEBUG("Reading file '" << filename << "'");

	if (read(filename) == false)
	{
		MSG_ERROR(MSG_FLF <<" Occurred during reading file.");
		retvalue = nullptr;
	}
	else
	{
		MSG_DEBUG("Reading file successfully.");

		// Use PluginFramework to create factory and package by given prefix (eg. ecore, uml,...)
		prefix = m_handler->getPrefix();

		std::shared_ptr<PluginFramework> pluginFramework = PluginFramework::eInstance();
		std::shared_ptr<MDE4CPPPlugin> plugin = pluginFramework->findPluginByName(prefix);

		if (plugin && (prefix.compare("ecore") == 0))
		{
			std::shared_ptr<EcoreModelPlugin> ecorePlugin = std::dynamic_pointer_cast<EcoreModelPlugin>(plugin);
			std::shared_ptr<ecore::EPackage> package = ecorePlugin->getPackage();
			//std::shared_ptr<ecore::EFactory> factory = ecorePlugin->getFactory(); // TODO get Factory of ecorePlugin
			std::shared_ptr<ecore::EcoreFactory> factory = std::dynamic_pointer_cast<ecore::EcoreFactory>(ecorePlugin->getFactory())->eInstance();

			// Create root object of model
			//std::shared_ptr<ecore::EPackage> pck_root = std::dynamic_pointer_cast<ecore::EPackage>(factory->create(std::dynamic_pointer_cast<ecore::EClass>(package->getEClassifier("EPackage"))) ); // TODO Not supported yet
			std::shared_ptr<ecore::EPackage> pck_root = factory->createEPackage();

			m_handler->setCurrentObject(pck_root);
			m_handler->getNextNodeName();

			// Start loading process by calling load() on root object
			pck_root->load(m_handler);

			// Add EClassifiers of package to map if not already in // TODO this sequence should not necessary, because Handlers should use PluginFramework to find correct objects and types
			std::shared_ptr<Bag<ecore::EClassifier>> eClassifiers = package->getEClassifiers();
			for (std::shared_ptr<ecore::EClassifier> eClassifier : *eClassifiers)
			{
				// Filter only EDataType objects and add to handler's internal map
				std::shared_ptr<ecore::EClass> _metaClass = eClassifier->eClass();
				if (_metaClass->getName().compare("EDataType") == 0)
				{
					m_handler->addToMap(eClassifier); // TODO add default parameter force=true to addToMap()
				}
			}

			// Resolve unresolved references that are stored during loading
			m_handler->resolveReferences();

			// cast root object to EObject
			retvalue = std::dynamic_pointer_cast<ecore::EObject>(pck_root);
		}
		else
		{
			MSG_ERROR(MSG_FLF << " Given Plugin name '" << prefix << "' is not supported or not found by PluginFramework");
		}
	}

	return retvalue;
}
