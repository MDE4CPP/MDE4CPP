#include "cute.h"
#include "SimpleOperations/SimpleOperations_TestSuite.hpp"
//#include "SimpleOperations/impl/SimpleOperationsPackageImpl.hpp"

//testCodeGen.includes


#include "SimpleOperations/Addition/Addition_TestSuite.hpp"

void complexSimpleOperationsTest_SimpleOperationsTest() {


    //TestQuelltext
}	

cute::suite make_suite_SimpleOperations_TestSuite() {

	cute::suite s { };

	s += CUTE( complexSimpleOperationsTest_SimpleOperationsTest );
	return s;
}

bool runSimpleOperations_TestSuiteSubTests( cute::runner<cute::xml_listener<cute::ide_listener<cute::null_listener> > > runner ) {

	bool success = true;
	cute::suite suite_Addition_TestSuite = make_suite_Addition_TestSuite();

	success &= runner( suite_Addition_TestSuite, "SimpleOperations_TestSuite::Addition_TestSuite" );
	success &= runAddition_TestSuiteSubTests( runner );
	return success;
}
