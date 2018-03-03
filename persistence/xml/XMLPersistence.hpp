/*
 * persistence::xml.hpp
 *
 *  Created on: 25.01.2018
 *      Author: Alexander
 */

#ifndef PERSISTENCE_XML_XMLPersistence_HPP
#define PERSISTENCE_XML_XMLPersistence_HPP

#include "persistence/base/Persistence.hpp"

#include <string>

namespace ecore
{
	class EObject;
	class EPackage;
}

namespace persistence
{
	namespace xml
	{

		class XMLPersistence: persistence::base::Persistence
		{
			public:
				XMLPersistence();
				virtual ~XMLPersistence();

				std::shared_ptr<ecore::EObject> load(const std::string &filename);
				bool save(const std::string &filename, std::shared_ptr<ecore::EObject> model, std::shared_ptr<ecore::EPackage> metaMetaPackage);

			private:

		};
	} /* namespace xml */
} /* namespace persistence */

#endif
