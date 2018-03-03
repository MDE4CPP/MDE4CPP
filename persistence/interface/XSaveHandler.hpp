/*
 * SaveHandler.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_INTERFACE_XSAVEHANDLER_HPP
#define PERSISTENCE_INTERFACE_XSAVEHANDLER_HPP

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

#include "abstractDataTypes/Bag.hpp"
#include "boost/exception/to_string.hpp"

namespace ecore
{
	class EObject;
	class EStructuralFeature;
}

namespace persistence
{
	namespace interface
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
					addAttribute(name, boost::to_string(value));
				}
				virtual void addAttribute(const std::string &name, bool value) = 0;
				virtual void addAttribute(const std::string &name, const std::string& value) = 0;

				virtual void addReference(const std::string &name, std::shared_ptr<ecore::EObject> object) = 0;
				virtual void addReferences(const std::string &name, std::shared_ptr<ecore::EObject> object) = 0;

				template<typename T>
				void addReferences(const std::string &name, std::shared_ptr<Bag<T> > objects)
				{
					for (std::shared_ptr<T> _object : *objects)
					{
						addReferences(name, _object);
					}
				}

				virtual void release() = 0;
		};

	} /* namespace interface */
} /* namespace persistence */
#endif
