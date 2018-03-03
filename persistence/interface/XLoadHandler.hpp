/*
 * LoadHandler.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_INTERFACE_XLOADHANDLER_HPP
#define PERSISTENCE_INTERFACE_XLOADHANDLER_HPP

#ifdef NDEBUG
#define MSG_DEBUG(a) /**/
#else
#define MSG_DEBUG(a) std::cout << "| DEBUG    | " << a << std::endl
#endif
#define MSG_WARNING(a) std::cout << "| WARNING  | "<< a << std::endl
#define MSG_ERROR(a) std::cout << "| ERROR    | " << a << std::endl
#define MSG_FLF __FILE__ << ":" << __LINE__ << " " << __FUNCTION__ << "() "

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
				virtual void setCurrentObject(std::shared_ptr<ecore::EObject> object) = 0;
				virtual std::shared_ptr<ecore::EObject> getCurrentObject() = 0;

				virtual void release() = 0;

				virtual unsigned int getNumOfChildNodes() = 0;
				virtual std::string getNextNodeName() = 0;
				virtual std::map<std::string, std::string> getAttributeList() = 0;

				virtual void addUnresolvedReference(const std::string &name, std::shared_ptr<ecore::EObject> object, std::shared_ptr<ecore::EStructuralFeature> esf) = 0;
		};

	} /* namespace interface */
} /* namespace persistence */

#endif /* XLoadHandler_HPP_ */
