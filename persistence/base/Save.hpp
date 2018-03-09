/*
 * Save.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_BASE_SAVE_HPP
#define PERSISTENCE_BASE_SAVE_HPP

#include <memory>
#include <string>

namespace ecore
{
	class EObject;
	class EPackage;
}

namespace persistence
{
	namespace base
	{
		class SaveHandler;
	}
}

namespace persistence
{
	namespace base
	{
		class Save
		{
			public:
				Save();
				virtual ~Save();

				bool save(const std::string &filename, std::shared_ptr<ecore::EObject> model, std::shared_ptr<ecore::EPackage> metaMetaPackage, bool xsiMode = true);

			protected:
				std::shared_ptr<persistence::base::SaveHandler> m_handler;

				virtual bool write(const std::string &filename) = 0;
		};
	} /* namespace base */
} /* namespace persistence */

#endif /* SAVE_HPP_ */
