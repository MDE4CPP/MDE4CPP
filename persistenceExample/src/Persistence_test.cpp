/*
 * Persistence_test.cpp
 *
 *  Created on: 05.05.2017
 *      Author: Alexander P.
 */

#include <memory>
#include <iostream>
#include <omp.h>
#include <string>

#include "ecore/EPackage.hpp"
#include "ecore/EObject.hpp"
#include "persistence/xml/XMLPersistence.hpp"
#include "TestModel.hpp"

void performReadAndWrite(std::string loadPath, std::string savePath)
{
	try
	{
		// Perform load()
		MSG_DEBUG("Start load() of 'myEcoreTestSaveMetaModel'");
		persistence::xml::XMLPersistence myPersistence;
		std::shared_ptr<ecore::EObject> myEcoreTestLoadMetaModel = myPersistence.load(loadPath);
		if (myEcoreTestLoadMetaModel != nullptr)
		{
			MSG_DEBUG("Successful load() of model from '" << loadPath << "'");
		}
		else
		{
			MSG_ERROR(MSG_FLF << "During load() of model from '" << loadPath << "'");
		}

		// Perform save()
		MSG_DEBUG("Start save() of 'myEcoreTestLoadMetaModel'");

		if (myPersistence.save(savePath, myEcoreTestLoadMetaModel, testmodel::TestModel::getMetaMetaPackage()))
		{
			MSG_DEBUG("Successful save() of model to '" << savePath << "'");
		}
		else
		{
			MSG_ERROR(MSG_FLF << "During save() of model to '" << savePath << "'");
		}
	}
	catch (std::exception &e)
	{
		MSG_ERROR(MSG_FLF << e.what());
	}
}

void performUniModelTest()
{
	// Set filename with path
	std::string filename = "_tmp/UniModel.ecore";
	std::string filename2 = "_tmp/UniModel_out.ecore";
	try
	{
		// Get MetaPackage
		MSG_DEBUG("Get 'myEcoreMetaMetaPackage'");
		std::shared_ptr<ecore::EPackage> myEcoreMetaMetaPackage = testmodel::TestModel::getMetaMetaPackage();
		if (myEcoreMetaMetaPackage == 0)
		{
			MSG_ERROR(MSG_FLF << "'myEcoreMetaMetaPackage' is empty");
			return;
		}

		// Create Save-Model
		MSG_DEBUG("Create 'myEcoreTestSaveMetaModel'");
		std::shared_ptr<ecore::EObject> myEcoreTestSaveMetaModel = testmodel::TestModel::createEcoreTestMetaModel();
		if (myEcoreTestSaveMetaModel == 0)
		{
			MSG_ERROR(MSG_FLF << "'myEcoreTestSaveMetaModel' is empty");
			return;
		}

		// Perform save()
		MSG_DEBUG("Start save() of 'myEcoreTestSaveMetaModel'");
		// Crete persistence object
		persistence::xml::XMLPersistence myPersistence;
		if (myPersistence.save(filename, myEcoreTestSaveMetaModel, myEcoreMetaMetaPackage))
		{

			MSG_DEBUG("Successful save() 'myEcoreTestSaveMetaModel' to '" << filename.c_str() << "'");
		}
		else
		{
			MSG_ERROR(MSG_FLF << "During save() of 'myEcoreTestSaveMetaModel'");
		}
	}
	catch (std::exception &e)
	{
		MSG_ERROR(MSG_FLF << e.what());
	}

	performReadAndWrite(filename, filename2);
}

int main()
{
	// Set OpenMP number of threads
	omp_set_num_threads(1);

	performUniModelTest();
	performReadAndWrite("_tmp/ecore.ecore", "_tmp/ecore_out.ecore");
	performReadAndWrite("_tmp/types.ecore", "_tmp/types_out.ecore");

	return 0;
}
