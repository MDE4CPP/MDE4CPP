
#include <iostream>

#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "helper/TestSuiteMainHelper.hpp"


#include "tests_for_uml/ClassImplTest.hpp"
#include "tests_for_uml/ClassifierImplTest.hpp"
#include "tests_for_uml/ElementImplTest.hpp"
#include "tests_for_uml/NamedElementImplTest.hpp"

bool runSuite( int argc, char const *argv[] ) {

	bool success = true;	
	cute::xml_file_opener xmlfile( argc, argv );
	cute::xml_listener<cute::ide_listener<>> lis( xmlfile.out );
	cute::runner<cute::xml_listener<cute::ide_listener<cute::null_listener> > > runner = cute::makeRunner( lis, argc, argv );
	cute::suite suite_ClassImplTest = make_suite_ClassImplTest();
	cute::suite suite_ClassifierImplTest = make_suite_ClassifierImplTest();
	cute::suite suite_ElementImplTest = make_suite_ElementImplTest();
	cute::suite suite_NamedElementImplTest = make_suite_NamedElementImplTest();

	success &= runner( suite_ClassImplTest, "ClassImplTest" );
	success &= runner( suite_ClassifierImplTest, "ClassifierImplTest" );
	success &= runner( suite_ElementImplTest, "ElementImplTest" );
	success &= runner( suite_NamedElementImplTest, "NamedElementImplTest" );

	TestSuiteMainHelper::PrintTestsCountStatistic();

	return success;
}

int main( int argc, char const *argv[] ) {

    return runSuite( argc, argv ) ? EXIT_SUCCESS : EXIT_FAILURE;
}
