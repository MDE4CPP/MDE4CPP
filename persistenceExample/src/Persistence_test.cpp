/*
 * Persistence_test.cpp
 *
 *  Created on: 05.05.2017
 *      Author: Alexander P.
 */

#ifdef NDEBUG
#define MSG_DEBUG(a) /**/
#else
#include <iostream>
#define MSG_DEBUG(a) std::cout<<"| DEBUG    | "<<a<<std::endl
#endif
#define MSG_WARNING(a) std::cout<<"| WARNING  | "<<a<<std::endl
#define MSG_ERROR(a) std::cout<<"| ERROR    | "<<a<<std::endl
#define MSG_FLF __FILE__<<":"<<__LINE__<<" "<<__FUNCTION__<<"() "

#include <omp.h>
#include <stdlib.h>
#include <string>
#include <memory>

#include "persistence/xml/XMLPersistence.hpp"
#include "TestModel.hpp"

#include "ecore/EPackage.hpp"
#include "ecore/EObject.hpp"

int main ()
{
	try
	{
		// Set OpenMP number of threads
		omp_set_num_threads( 1 );

		// Set filename with path
		std::string filename = "_tmp/UniModel.ecore";
		std::string filename2 = "_tmp/UniModel_out.ecore";
		std::string filename3 = "_tmp/xmi.ecore";
		std::string filename4 = "_tmp/xmi_out.ecore";

		// Get MetaPackage
		MSG_DEBUG( "Get 'myEcoreMetaMetaPackage'" );
		std::shared_ptr<ecore::EPackage> myEcoreMetaMetaPackage = testmodel::TestModel::getMetaMetaPackage();
		if ( myEcoreMetaMetaPackage == 0 )
		{
			MSG_ERROR( MSG_FLF << "'myEcoreMetaMetaPackage' is empty" );
			return 0;
		}

		// Create Save-Model
		MSG_DEBUG( "Create 'myEcoreTestSaveMetaModel'" );
		std::shared_ptr<ecore::EObject> myEcoreTestSaveMetaModel = testmodel::TestModel::createEcoreTestMetaModel();
		if ( myEcoreTestSaveMetaModel == 0 )
		{
			MSG_ERROR( MSG_FLF << "'myEcoreTestSaveMetaModel' is empty" );
			return 0;
		}
		// Create Load-Model
		MSG_DEBUG( "Create 'myEcoreTestLoadMetaModel'" );
		std::shared_ptr<ecore::EObject> myEcoreTestLoadMetaModel;

		// Crete persistence object
		persistence::xml::XMLPersistence myPersistence;

		// Perform save()
		MSG_DEBUG( "Start save() of 'myEcoreTestSaveMetaModel'");

		if ( myPersistence.save( filename, myEcoreTestSaveMetaModel, myEcoreMetaMetaPackage ) )
		{

			MSG_DEBUG( "Successful save() 'myEcoreTestSaveMetaModel' to '" << filename.c_str() << "'");
		}
		else
		{
			MSG_ERROR( MSG_FLF << "During save() of 'myEcoreTestSaveMetaModel'");
		}

		// Perform load()
		MSG_DEBUG( "Start load() of 'myEcoreTestSaveMetaModel'");
		myEcoreTestLoadMetaModel = myPersistence.load( filename );
		if ( myEcoreTestLoadMetaModel != nullptr )
		{
			MSG_DEBUG( "Successful load() of 'myEcoreTestLoadMetaModel' from '" << filename << "'");
		}
		else
		{
			MSG_ERROR( MSG_FLF << "During load() of 'myEcoreTestLoadMetaModel'");
		}

		// Perform save() again
		MSG_DEBUG( "Start save() of 'myEcoreTestLoadMetaModel'");

		if ( myPersistence.save( filename2, myEcoreTestLoadMetaModel, myEcoreMetaMetaPackage ) )
		{
			MSG_DEBUG( "Successful save() 'myEcoreTestSaveMetaModel' to '" << filename2 << "'");
		}
		else
		{
			MSG_ERROR( MSG_FLF << "During save() of 'myEcoreTestLoadMetaModel'");
		}

		// Perform load() on unknown model
		MSG_DEBUG( "Start load() of 'myEcoreTestSaveMetaModel'" );
		myEcoreTestLoadMetaModel = myPersistence.load( filename3 );
		if ( myEcoreTestLoadMetaModel != nullptr )
		{
			MSG_DEBUG( "Successful load() of 'myEcoreTestLoadMetaModel' from '" << filename3 << "'" );
		}
		else
		{
			MSG_ERROR( MSG_FLF << "During load() of 'myEcoreTestLoadMetaModel'" );
		}

		// Perform save() again
		MSG_DEBUG( "Start save() of 'myEcoreTestLoadMetaModel'" );

		if ( myPersistence.save( filename4, myEcoreTestLoadMetaModel, myEcoreMetaMetaPackage ) )
		{
			MSG_DEBUG( "Successful save() 'myEcoreTestSaveMetaModel' to '" << filename4 << "'" );
		}
		else
		{
			MSG_ERROR( MSG_FLF << "During save() of 'myEcoreTestLoadMetaModel'" );
		}
	}
	catch ( std::exception &e )
	{
		MSG_ERROR( MSG_FLF << e.what() );
	}
	return 0;
}
