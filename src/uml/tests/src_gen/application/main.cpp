
#include <iostream>

#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "helper/TestSuiteMainHelper.hpp"



bool runSuite( int argc, char const *argv[] ) {

	bool success = true;	
	cute::xml_file_opener xmlfile( argc, argv );
	cute::xml_listener<cute::ide_listener<>> lis( xmlfile.out );
	cute::runner<cute::xml_listener<cute::ide_listener<cute::null_listener> > > runner = cute::makeRunner( lis, argc, argv );


	TestSuiteMainHelper::PrintTestsCountStatistic();

	return success;
}

int main( int argc, char const *argv[] ) {

    return runSuite( argc, argv ) ? EXIT_SUCCESS : EXIT_FAILURE;
}
