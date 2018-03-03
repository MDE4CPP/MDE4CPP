/*
 * Persistence.hpp
 *
 *  Created on: 16.05.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_BASE_PERSISTENCE_HPP_
#define PERSISTENCE_BASE_PERSISTENCE_HPP_

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
		class Persistence
		{
			public:
				Persistence();
				virtual ~Persistence();

				virtual std::shared_ptr<ecore::EObject> load(const std::string &filename) = 0;
				virtual bool save(const std::string &filename, std::shared_ptr<ecore::EObject> model, std::shared_ptr<ecore::EPackage> metaMetaPackage) = 0;

			protected:
				bool isValidFile(const std::string &filename);
		};
	} /* namespace base */
} /* namespace persistence */

#endif /* PERSISTENCE_HPP_ */
