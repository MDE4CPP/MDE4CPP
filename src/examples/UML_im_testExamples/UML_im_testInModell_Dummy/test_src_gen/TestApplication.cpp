#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Calculators/Calculators_TestSuite.hpp"
#include "SimpleOperations/SimpleOperations_TestSuite.hpp"

bool runSuite( int argc, char const *argv[] ) {

	bool success = true;	
	cute::xml_file_opener xmlfile( argc, argv );
	cute::xml_listener<cute::ide_listener<>> lis( xmlfile.out );
	cute::runner<cute::xml_listener<cute::ide_listener<cute::null_listener> > > runner = cute::makeRunner( lis, argc, argv );
	cute::suite suite_Calculators_TestSuite = make_suite_Calculators_TestSuite();
	cute::suite suite_SimpleOperations_TestSuite = make_suite_SimpleOperations_TestSuite();

	success &= runner( suite_Calculators_TestSuite, "Calculators_TestSuite" );
	success &= runCalculators_TestSuiteSubTests( runner );
	success &= runner( suite_SimpleOperations_TestSuite, "SimpleOperations_TestSuite" );
	success &= runSimpleOperations_TestSuiteSubTests( runner );
	return success;
}

int main( int argc, char const *argv[] ) {

    return runSuite( argc, argv ) ? EXIT_SUCCESS : EXIT_FAILURE;
}
