/*
 * LoadHandler.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_INTERFACE_XLOADHANDLER_HPP
#define PERSISTENCE_INTERFACE_XLOADHANDLER_HPP

#include <map>
#include <memory>
#include <string>

namespace ecore
{
	class EObject;
	class EStructuralFeature;
}

namespace persistence
{
	namespace interface
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

	} /* namespace interface */
} /* namespace persistence */

#endif /* XLoadHandler_HPP_ */
