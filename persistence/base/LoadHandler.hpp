/*
 * LoadHandler.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_BASE_LOADHANDLER_HPP
#define PERSISTENCE_BASE_LOADHANDLER_HPP

#include "persistence/interface/XLoadHandler.hpp"

#include <list>
#include <map>
#include <memory>
#include <string>

namespace ecore
{
	class EObject;
	class EPackage;
	class EStructuralFeature;
}

namespace uml
{
	class Package;
}

namespace persistence
{
	namespace base
	{
		struct UnresolvedReference
		{
				inline UnresolvedReference(std::string refName, std::shared_ptr<ecore::EObject> eObject, std::shared_ptr<ecore::EStructuralFeature> eStructuralFeature) :
					refName(refName), eObject(eObject), eStructuralFeature(eStructuralFeature)
				{
				}

				std::string refName;
				std::shared_ptr<ecore::EObject> eObject;
				std::shared_ptr<ecore::EStructuralFeature> eStructuralFeature;
		};

		/**
		 * Class LoadHandler
		 */
		class LoadHandler: public persistence::interface::XLoadHandler
		{
			public:
				LoadHandler();
				virtual ~LoadHandler();

				std::shared_ptr<ecore::EObject> getObjectByRef(std::string ref);

				std::string getLevel();
				std::string getPrefix();
				virtual std::string getRootName();

				std::string extractType(std::shared_ptr<ecore::EObject> obj) const;

				void addToMap(std::shared_ptr<ecore::EObject> object);
				void addToMap(std::shared_ptr<ecore::EObject> object, bool useCurrentObjects);

				void handleRoot(std::shared_ptr<ecore::EObject> object);
				void handleChild(std::shared_ptr<ecore::EObject> object);
				std::shared_ptr<ecore::EObject> getCurrentObject();

				virtual void release();

				virtual unsigned int getNumOfChildNodes() = 0;
				virtual std::string getNextNodeName() = 0;
				virtual std::map<std::string, std::string> getAttributeList() = 0;
				virtual std::string getCurrentXSITypeName() = 0;

				void addUnresolvedReference(const std::string &name, std::shared_ptr<ecore::EObject> object, std::shared_ptr<ecore::EStructuralFeature> esf);

				void resolveReferences();

				virtual void setThisPtr(std::shared_ptr<LoadHandler> thisPtr);
				virtual void solve(const std::string& name, std::list<std::shared_ptr<ecore::EObject>> references, std::shared_ptr<ecore::EObject> object, std::shared_ptr<ecore::EStructuralFeature> esf);
				virtual void loadTypes(const std::string& name);
				virtual void loadTypes(std::shared_ptr<ecore::EPackage> package);
				virtual void loadTypes(std::shared_ptr<uml::Package> package, std::string uri);
				virtual std::string getCurrentXMIID() = 0;
				virtual std::map<std::string, std::shared_ptr<ecore::EObject>> getTypesMap();

			protected:
				int m_level;

				std::shared_ptr<ecore::EObject> m_rootObject;
				std::list<std::shared_ptr<ecore::EObject> > m_currentObjects;

				std::string m_rootPrefix;
				std::string m_rootName;

				std::map<std::string, std::shared_ptr<ecore::EObject>> m_refToObject_map;
				std::list<persistence::base::UnresolvedReference> m_unresolvedReferences;

				std::shared_ptr<LoadHandler> m_thisPtr;
				bool m_isXSIMode;
		};
	} /* namespace base */
} /* namespace persistence */

#endif /* LoadHandler_HPP_ */
