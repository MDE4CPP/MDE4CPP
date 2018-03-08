/*
 * Load.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_BASE_LOAD_HPP
#define PERSISTENCE_BASE_LOAD_HPP

#include <memory>

namespace ecore
{
	class EPackage;
	class EObject;
}

namespace persistence
{
	namespace base
	{
		class LoadHandler;
	}
}

namespace persistence
{
	namespace base
	{
		class Load
		{
			public:
				Load();
				virtual ~Load();

				std::shared_ptr<ecore::EObject> load(const std::string &filename);

			protected:
				std::shared_ptr<persistence::base::LoadHandler> m_handler;

				virtual bool read(const std::string &filename) = 0;
		};

	} /* namespace base */
} /* namespace persistence */

#endif /* LOAD_HPP_ */
