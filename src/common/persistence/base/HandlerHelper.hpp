/*
 * HandlerHelper.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_BASE_HANDLERHELPER_HPP
#define PERSISTENCE_BASE_HANDLERHELPER_HPP

#include <string>
#include <vector>
#include <memory>

namespace ecore
{
	class EObject;
}

namespace persistence
{
	namespace base
	{
		class HandlerHelper
		{
			public:
				HandlerHelper();
				virtual ~HandlerHelper();

				static std::string extractType(const std::shared_ptr<ecore::EObject> obj, std::string prefix);
				static std::string extractReference(const std::shared_ptr<ecore::EObject> toObject, const std::shared_ptr<ecore::EObject> rootObject, std::string prefix, const std::string& uri);
				static std::string extractReference(const std::shared_ptr<ecore::EObject> toObject, const std::shared_ptr<ecore::EObject> rootObject, std::string prefix, std::vector<std::shared_ptr<ecore::EObject>> currentObjects, const std::string& uri);
		};

	} /* namespace base */
} /* namespace persistence */

#endif /* HandlerHelper_HPP_ */
