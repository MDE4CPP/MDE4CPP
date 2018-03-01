/*
 * TestModel.hpp
 *
 *  Created on: 23.06.2017
 *      Author: Alexander
 */

#ifndef _TESTMODEL_HPP_
#define _TESTMODEL_HPP_

#include "EcoreFactory.hpp"
#include "EcorePackage.hpp"
#include "impl/EcoreFactoryImpl.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"

namespace testmodel {

class TestModel {
public:
	TestModel ();
	virtual ~TestModel ();

	static std::shared_ptr<ecore::EPackage> getMetaMetaPackage();
	static std::shared_ptr<ecore::EObject> createEcoreTestMetaModel ();
};

} /* namespace persistence */

#endif /* TESTMODEL_HPP_ */
