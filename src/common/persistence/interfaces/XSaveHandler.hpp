/*
 * SaveHandler.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_INTERFACES_XSAVEHANDLER_HPP
#define PERSISTENCE_INTERFACES_XSAVEHANDLER_HPP

#include <list>
#include <map>
#include <unordered_map>

#include <memory>
#include <string>

#include "abstractDataTypes/SubsetUnion.hpp"

namespace ecore
{
	class EObject;
	class EStructuralFeature;
}

namespace persistence
{
	namespace interfaces
	{
		class XSaveHandler
		{
			public:
				//destructor
				virtual ~XSaveHandler()
				{
				}

				virtual std::string extractType(std::shared_ptr<ecore::EObject> obj) const = 0;

				virtual bool createAndAddElement(const std::string& name) = 0;

				template<typename T>
				void addAttribute(const std::string& name, T value)
				{
					addAttribute(name, std::to_string(value));
				}
				virtual void addAttribute(const std::string &name, bool value) = 0;
				virtual void addAttribute(const std::string &name, const std::string& value) = 0;
				virtual void addAttributeAsNode(const std::string& name, const std::string& value) = 0;

				virtual void addReference(const std::string &name, std::shared_ptr<ecore::EObject> object) = 0;
				virtual void addReferences(const std::string &name, std::shared_ptr<ecore::EObject> object) = 0;
				virtual void addReference(const std::shared_ptr<ecore::EObject> object, const std::string &tagName, const bool typeRequired) = 0;

				template<typename T> void addReferences(const std::string &name, std::shared_ptr<Bag<T> > objects)
				{
					for (std::shared_ptr<T> _object : *objects)
					{
						addReferences(name, _object);
					}
				}

				template<typename T> void addReferences(const std::string &name, std::shared_ptr<std::list<T> > objects)
				{
					for (auto _object : *objects)
					{
						addReferences(name, _object);
					}
				}

				template<typename T> void addReferences(const std::string &name, std::shared_ptr<std::vector<T> > objects)
				{
					for (auto _object : *objects)
					{
						addReferences(name, _object);
					}
				}

				template<typename K, typename V> void addReferences(const std::string &name, std::shared_ptr<std::map<K,V> > objects)
				{
					for (auto _object : *objects)
					{
						addReferences(name, _object.second);
					}
				}
				
				template<typename K, typename V> void addReferences(const std::string &name, std::shared_ptr<std::unordered_map<K,V> > objects)
				{
					for (auto _object : *objects)
					{
						addReferences(name, _object.second);
					}
				}
					
				virtual void release() = 0;
		};

	} /* namespace interfaces */
} /* namespace persistence */
#endif
