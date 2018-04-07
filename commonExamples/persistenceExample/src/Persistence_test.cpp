/*
 * Persistence_test.cpp
 *
 *  Created on: 05.05.2017
 *      Author: Alexander P.
 */

#include <dirent.h>
#include <memory>
#include <iostream>
#include <omp.h>
#include <string>
#include <vector>

#ifdef _WIN32
	#include <windows.h>

	#define getcwd _getcwd
#else
	#include <sys/stat.h>
#endif
#define MAX_CHAR 260

#ifdef NDEBUG
#define MSG_DEBUG(a) /**/
#else
#define MSG_DEBUG(a) std::cout << "| DEBUG    | " << a << std::endl
#endif
#define MSG_WARNING(a) std::cout << "| WARNING  | "<< a << std::endl
#define MSG_ERROR(a) std::cout << "| ERROR    | " << a << std::endl
#define MSG_FLF __FILE__ << ":" << __LINE__ << " " << __FUNCTION__ << "() "

#include "ecore/EPackage.hpp"
#include "ecore/EObject.hpp"
#include "persistence/xml/XMLPersistence.hpp"
#include "uml/UmlPackage.hpp"
#include "TestModel.hpp"

void performReadAndWrite(std::string loadPath, std::string savePath, std::shared_ptr<ecore::EPackage> package, bool xsiMode = true)
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

		if (myPersistence.save(savePath, myEcoreTestLoadMetaModel, package, xsiMode))
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

void performUniModelTest(std::string dataFolderName)
{
	// Set filename with path
	std::string filename = dataFolderName + "/UniModel.ecore";
	std::string filename2 = dataFolderName + "/UniModel_out.ecore";
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

	performReadAndWrite(filename, filename2, testmodel::TestModel::getMetaMetaPackage());
}

int main()
{
	// Set OpenMP number of threads
	omp_set_num_threads(1);
	char folderBuffer[MAX_CHAR];
	std::vector<std::string> libraries;
	if (!getcwd(folderBuffer, sizeof(folderBuffer)))
	{
		std::cerr << "Could not locate workspace folder" << std::endl;
		return 1;
	}
	std::string dataFolderName = "data";
	std::string folderName(folderBuffer);
	std::string folderPath = folderName + "/" + dataFolderName;

#ifdef _WIN32
	if (!(CreateDirectory(folderPath.c_str(), NULL) ||
		    ERROR_ALREADY_EXISTS == GetLastError()))
	{
		std::cout << "Could not create folder '" << folderPath << "'!" << std::endl;
		return 2;
	}
#else
	 mkdir(dataFolderName.c_str(), 0777);
#endif


	performUniModelTest(dataFolderName);
//	performReadAndWrite(dataFolderName + "//ecore.ecore", dataFolderName + "//ecore_out.ecore", testmodel::TestModel::getMetaMetaPackage());
//	performReadAndWrite(dataFolderName + "//types.ecore", dataFolderName + "//types_out.ecore", testmodel::TestModel::getMetaMetaPackage());
//	performReadAndWrite(dataFolderName + "//uml.ecore", dataFolderName + "//uml_out.ecore", testmodel::TestModel::getMetaMetaPackage());
//	performReadAndWrite(dataFolderName + "//fuml.ecore", dataFolderName + "//fuml_out.ecore", testmodel::TestModel::getMetaMetaPackage());

	return 0;
}
