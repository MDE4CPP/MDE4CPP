/*
 * LoadHandler.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_INTERFACES_XLOADHANDLER_HPP
#define PERSISTENCE_INTERFACES_XLOADHANDLER_HPP

#include <map>
#include <list>
#include <vector>
#include <memory>
#include <string>
#include "abstractDataTypes/Bag.hpp"

namespace ecore
{
	class EObject;
	class EStructuralFeature;
}

namespace persistence
{
	namespace interfaces
	{

		class XLoadHandler
		{
			public:
				//destructor
				virtual ~XLoadHandler()
				{
				}
				virtual std::string getLevel() = 0;
				virtual void addToMap(std::shared_ptr<ecore::EObject> object) = 0;
				virtual void handleChild(std::shared_ptr<ecore::EObject> object) = 0;

				template<typename T> void handleChildContainer(std::shared_ptr<Bag<T>> objects)
				{
					for (auto _object : *objects)
					{
						handleChild(_object);
					}
				}
				template<typename T> void handleChildContainer(std::shared_ptr<std::list<T> > objects)
				{
					for (auto _object : *objects)
					{
						handleChild(_object);
					}
				}
				template<typename T> void handleChildContainer(std::shared_ptr<std::vector<T> > objects)
				{
					for (auto _object : *objects)
					{
						handleChild(_object);
					}
				}
				template<typename K, typename V> void handleChildContainer(std::shared_ptr<std::map<K,V> > objects)
				{
					for (auto _object : *objects)
					{
						handleChild(_object.second);
					}
				}

				virtual std::shared_ptr<ecore::EObject> getCurrentObject() = 0;

				virtual void release() = 0;

				virtual unsigned int getNumOfChildNodes() = 0;
				virtual std::string getNextNodeName() = 0;
				virtual std::map<std::string, std::string> getAttributeList() = 0;
				virtual std::string getCurrentXSITypeName() = 0;
				virtual std::shared_ptr<ecore::EObject> checkNodeType(std::shared_ptr<ecore::EObject> object) = 0;

				virtual void addUnresolvedReference(const std::string &name, std::shared_ptr<ecore::EObject> object, std::shared_ptr<ecore::EStructuralFeature> esf) = 0;
				virtual std::shared_ptr<std::string> getChildText() = 0;
		};

	} /* namespace interfaces */
} /* namespace persistence */

#endif /* XLoadHandler_HPP_ */
