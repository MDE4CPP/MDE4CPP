/*
 * TestModel.hpp
 *
 *  Created on: 23.06.2017
 *      Author: Alexander
 */

#ifndef TESTMODEL_HPP
#define TESTMODEL_HPP

#include <memory>

namespace ecore
{
	class EPackage;
	class EObject;
}

namespace testmodel
{
	class TestModel
	{
		public:
			TestModel();
			virtual ~TestModel();

			static std::shared_ptr<ecore::EPackage> getMetaMetaPackage();
			static std::shared_ptr<ecore::EObject> createEcoreTestMetaModel();
	};

} /* namespace persistence */

#endif
