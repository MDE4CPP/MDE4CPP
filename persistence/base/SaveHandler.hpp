/*
 * SaveHandler.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_BASE_SAVEHANDLER_HPP
#define PERSISTENCE_BASE_SAVEHANDLER_HPP

#include "persistence/interface/XSaveHandler.hpp"

#include <string>
#include "abstractDataTypes/Bag.hpp"

namespace ecore
{
	class EObject;
}

namespace persistence
{
	namespace base
	{
		class SaveHandler: public persistence::interface::XSaveHandler
		{
			public:
				SaveHandler();
				virtual ~SaveHandler();

				std::string getPrefix();
				void setRootObject(std::shared_ptr<ecore::EObject> object);

				std::string extractType(std::shared_ptr<ecore::EObject> obj) const;

				virtual bool createRootNode(const std::string& name, const std::string& ns_uri) = 0;
				virtual bool createRootNode(const std::string& prefix, const std::string& name, const std::string& ns_uri) = 0;

				virtual bool createAndAddElement(const std::string& name) = 0;

				void addAttribute(const std::string &name, bool value);
				virtual void addAttribute(const std::string &name, const std::string& value) = 0;

				void addReference(const std::string &name, std::shared_ptr<ecore::EObject> object);
				virtual void addReferences(const std::string &name, std::shared_ptr<ecore::EObject> object) = 0;
				virtual void addReference(const std::shared_ptr<ecore::EObject> object, const std::string &tagName, const bool typeRequired);
				virtual void release() = 0;
				virtual void setThisPtr(std::shared_ptr<SaveHandler> thisPtr);
				virtual void setIsXSIMode(bool value);
				virtual void setTypesMap(std::map<std::string, std::shared_ptr<ecore::EObject>> typesMap);

			protected:
				std::shared_ptr<ecore::EObject> m_rootObject;
				std::string m_rootPrefix;

			private:
				std::shared_ptr<SaveHandler> m_thisPtr;
				bool m_isXSIMode;
				std::shared_ptr<Bag<ecore::EObject>> m_savedObjects;
				std::map<std::shared_ptr<ecore::EObject>, std::string> m_refToObject_map;
		};
	} /* namespace base */
} /* namespace persistence */

#endif /* SaveHandler_HPP_ */
