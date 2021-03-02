/*
 * LoadHandler.cpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#include "persistence/base/LoadHandler.hpp"
#include "PersistenceDefine.hpp"

#include <iostream>
#include <sstream> // used for getLevel()
#include <cassert>

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Union.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "uml/Class.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Package.hpp"
#include "persistence/base/HandlerHelper.hpp"

#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "pluginFramework/PluginFramework.hpp"
#include "pluginFramework/EcoreModelPlugin.hpp"
#include "pluginFramework/UMLModelPlugin.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"

using namespace persistence::base;

LoadHandler::LoadHandler()
{
	m_rootObject = nullptr;
	m_level = -1;
	m_isXSIMode = true;
}

LoadHandler::~LoadHandler()
{

}

std::shared_ptr<ecore::EObject> LoadHandler::getObjectByRef(std::string ref)
{
	std::shared_ptr<ecore::EObject> tmp;

	if (!ref.empty())
	{
		if (m_refToObject_map.find(ref) != m_refToObject_map.end())
		{
			// found
			tmp = m_refToObject_map.at(ref);
			//return std::dynamic_pointer_cast<ecore::EObject>( tmp );
		}
		else
		{
			size_t double_dot = ref.find("#//", 0);
			std::string _ref_prefix = "";
			std::string _ref_name = "";
			if (double_dot != std::string::npos)
			{
				std::string _ref_prefix = ref.substr(0, double_dot); // TODO '_ref_prefix' is not used in this case
				std::string _ref_name = ref.substr(double_dot);
			}
			if (m_refToObject_map.find(_ref_name) != m_refToObject_map.end())
			{
				// found
				tmp = m_refToObject_map.at(_ref_name);
				//return std::dynamic_pointer_cast<ecore::EObject>( tmp );
			}
			else
			{
				MSG_WARNING("Given Reference-Name '" << ref << "' or '" << _ref_name << "' are not in stored map.");
				return nullptr;
			}
		}
	}
	return tmp;
}


void LoadHandler::addToMap(std::shared_ptr<ecore::EObject> object)
{
	addToMap(object, true, "");
}

void LoadHandler::addToMap(std::shared_ptr<ecore::EObject> object, bool useCurrentObjects, const std::string& uri)
{

	std::string ref = "";
	if (useCurrentObjects)
	{
		ref = getCurrentXMIID();
		if (ref.empty())
		{
			ref = HandlerHelper::extractReference(object, m_rootObject, m_rootPrefix, m_currentObjects, uri);
		}
	}
	else
	{
		ref = HandlerHelper::extractReference(object, m_rootObject, m_rootPrefix, uri);
	}
	if (!ref.empty())
	{
		if (m_refToObject_map.find(ref) == m_refToObject_map.end())
		{
			// ref not found in map, so insert
			m_refToObject_map.insert(std::pair<std::string, std::shared_ptr<ecore::EObject>>(ref, object));

			MSG_DEBUG("Add to map: '" << ref << "'  eClass: '" << object->eClass()->getName() << "'");
		}
	}
}
/**/

std::string LoadHandler::getPrefix()
{
	return m_rootPrefix;
}

std::string LoadHandler::getRootName()
{
	return m_rootName;
}

std::string LoadHandler::getLevel()
{
	std::stringstream ss;
	for (int ii = 0; ii < m_level; ii++)
	{
		ss << " ";
	}
	return ss.str();
}

void LoadHandler::handleRoot(std::shared_ptr<ecore::EObject> object)
{
	if (object == nullptr)
	{
		return;
	}
	m_level++;
	m_currentObjects.push_back(object);
	m_rootObject = object;
	getNextNodeName();
	if (!m_isXSIMode)
	{
		m_refToObject_map.insert(std::pair<std::string, std::shared_ptr<ecore::EObject>>(getCurrentXMIID(), m_rootObject));
	}


	object->load(m_thisPtr);
}

void LoadHandler::handleChild(std::shared_ptr<ecore::EObject> object)
{
	if (object == nullptr)
	{
		return;
	}

	m_level++;
	m_currentObjects.push_back(object);

	if (!m_isXSIMode)
	{
		addToMap(object);	// add 'object' to loadHandler's internal Map, that is used for resolving references.
	}
	object->load(m_thisPtr); // call recursively 'object.load().
	if (m_isXSIMode)
	{
		addToMap(object);	// add 'object' to loadHandler's internal Map, that is used for resolving references.
	}
	release(); // report loadHandler to set 'this' as new current Object.
}

std::shared_ptr<ecore::EObject> LoadHandler::getCurrentObject()
{
	std::shared_ptr<ecore::EObject> tmp_obj = m_currentObjects.back();
	assert(tmp_obj);

	return tmp_obj;
}

/*
 * This API is adapted to API in Project emf4cpp.
 *
 * LINK to source: https://github.com/catedrasaes-umu/emf4cpp/tree/master/emf4cpp/ecorecpp/serializer/serializer-xerces.cpp
 * ::ecorecpp::mapping::type_traits::string_t serializer::get_type(EObject_ptr obj) const
 *
 */
std::string LoadHandler::extractType(std::shared_ptr<ecore::EObject> obj) const
{
	return persistence::base::HandlerHelper::extractType(obj, m_rootPrefix);
}

void LoadHandler::release()
{
	std::shared_ptr<ecore::EObject> tmp_obj = m_currentObjects.back();

	if (tmp_obj == nullptr)
	{
		MSG_ERROR("You can't call " << __PRETTY_FUNCTION__ << " while current Object is nullptr.");
	}
	else
	{
		// set current (container) object as new current object (decrease depth)
		m_currentObjects.pop_back();
		m_level--;
	}
}

void LoadHandler::addUnresolvedReference(const std::string &name, std::shared_ptr<ecore::EObject> object, std::shared_ptr<ecore::EStructuralFeature> esf)
{
	if (object != nullptr)
	{
		if (esf != nullptr)
		{
			m_unresolvedReferences.push_back(persistence::base::UnresolvedReference(name, object, esf));
		}
		else
		{
			MSG_ERROR(MSG_FLF << " esf is a nullptr");
		}
	}
	else
	{
		MSG_ERROR(MSG_FLF << " object is a nullptr");
	}
}

void LoadHandler::resolveReferences()
{
	while (!m_unresolvedReferences.empty())
	{
		persistence::base::UnresolvedReference uref = m_unresolvedReferences.back();
		m_unresolvedReferences.pop_back();

		std::string name = uref.refName;
		std::shared_ptr<ecore::EObject> object = uref.eObject;
		std::shared_ptr<ecore::EStructuralFeature> esf = uref.eStructuralFeature;

		std::vector<std::shared_ptr<ecore::EObject>> references;

		try
		{
			if (esf->getUpperBound() == 1)
			{
				// EStructuralFeature is a single object
				solve(name, references, object, esf);
			}
			else
			{
				// EStructuralFeature is a list of objects
				std::vector<std::string> _strs;

				int nameSize=name.size();
				if(nameSize>0)
				{
					size_t pos = name.find(" ");
					size_t initPos = 0;

					while( pos != std::string::npos )
					{
						_strs.push_back( name.substr( initPos, pos - initPos ) );

						initPos = pos + 1;

						pos = name.find( " ", initPos );
					}

					// Add last reference
					_strs.push_back( name.substr( initPos, nameSize - initPos ) );

					for(std::string _tmpStr:_strs)
					{
						if (std::string::npos != _tmpStr.find("#//") || !m_isXSIMode)
						{
							solve(_tmpStr, references, object, esf);
						}
					}
					// Call resolveReferences() of corresponding 'object'
					object->resolveReferences(esf->getFeatureID(), references);
				}
			}
		}
		catch (std::exception& e)
		{
			MSG_ERROR(MSG_FLF << " Exception: " << e.what());
		}
	}
}

void LoadHandler::setThisPtr(std::shared_ptr<LoadHandler> thisPtr)
{
	m_thisPtr = thisPtr;
}

void LoadHandler::solve(const std::string& name, std::vector<std::shared_ptr<ecore::EObject>> references, std::shared_ptr<ecore::EObject> object, std::shared_ptr<ecore::EStructuralFeature> esf)
{
	bool found = false;
	bool libraryLoaded = false;

	while (!found)
	{
		std::shared_ptr<ecore::EObject> resolved_object = this->getObjectByRef(name);
		if (resolved_object)
		{
			references.push_back(resolved_object);
			// Call resolveReferences() of corresponding 'object'
			object->resolveReferences(esf->getFeatureID(), references);
			found = true;
		}
		else
		{
			std::string adr= std::to_string ((long long)(&(*object)));
			std::string adrName="#//";
			adrName=adrName+ object->eClass()->getName() + "_" +adr;

			std::shared_ptr<ecore::EObject> resolved_object = this->getObjectByRef(adrName);
			if (resolved_object)
			{
				references.push_back(resolved_object);
				// Call resolveReferences() of corresponding 'object'
				object->resolveReferences(esf->getFeatureID(), references);
				found = true;
			}
			else
			{

				if (libraryLoaded)
				{
					return;
				}
				loadTypes(name);
				libraryLoaded = true;
			}
		}
	}
}

void LoadHandler::loadTypes(const std::string& name)
{
	unsigned int indexStartUri = name.find(" ");
	unsigned int indexEndUri = name.find("#");
	if (indexStartUri != std::string::npos)
	{
		std::string nsURI = name.substr(indexStartUri+1, indexEndUri-indexStartUri-1);
		unsigned int index = nsURI.find("file:/");
		if (index == 0)
		{
			loadTypesFromFile(nsURI);
		}
		else
		{
			std::shared_ptr<MDE4CPPPlugin> plugin = PluginFramework::eInstance()->findPluginByUri(nsURI);
			if (plugin)
			{
				std::shared_ptr<EcoreModelPlugin> ecorePlugin = std::dynamic_pointer_cast<EcoreModelPlugin>(plugin);
				if (ecorePlugin)
				{
					loadTypes(ecorePlugin->getEPackage(), nsURI);
					return;
				}
				std::shared_ptr<UMLModelPlugin> umlPlugin = std::dynamic_pointer_cast<UMLModelPlugin>(plugin);
				if (umlPlugin)
				{
					loadTypes(umlPlugin->getPackage(), nsURI);
				}

			}
		}
	}
}

void LoadHandler::loadTypes(std::shared_ptr<ecore::EPackage> package, const std::string& uri)
{
	std::shared_ptr<Subset<ecore::EClassifier, ecore::EObject>> eClassifiers = package->getEClassifiers();
	for (std::shared_ptr<ecore::EClassifier> eClassifier : *eClassifiers)
	{
		// Filter only EDataType objects and add to handler's internal map
		std::shared_ptr<ecore::EClass> _metaClass = eClassifier->eClass();
		addToMap(eClassifier, false, uri); // TODO add default parameter force=true to addToMap()
	}
}

void LoadHandler::loadTypes(std::shared_ptr<uml::Package> package, const std::string& uri)
{
	std::shared_ptr<Bag<uml::NamedElement>> memberList = package->getMember();
	for (std::shared_ptr<uml::NamedElement> member : *memberList)
	{
		// Filter only EDataType objects and add to handler's internal map
		std::string metaClassName = "";
		std::shared_ptr<ecore::EClass> ecoreMetaClass = member->eClass();
		if (ecoreMetaClass)
		{
			auto x = ecoreMetaClass->getEPackage().lock();
			if (x)
			{
				metaClassName = x->getName() + ":" + ecoreMetaClass->getName();
			}
			else
			{
				metaClassName = ecoreMetaClass->getName();
			}
		}
		else
		{
			std::shared_ptr<uml::Class> metaClass = member->getMetaClass();
			if (metaClass == nullptr)
			{
				metaClassName = metaClass->getName();
			}
		}

		std::string ref = metaClassName + " " + uri + "#" + member->getName();
		m_refToObject_map.insert(std::pair<std::string, std::shared_ptr<ecore::EObject>>(ref, member));

		MSG_DEBUG("Add to map: '" << ref << "'");
	}
}
std::map<std::string, std::shared_ptr<ecore::EObject>> LoadHandler::getTypesMap()
{
	return m_refToObject_map;
}
