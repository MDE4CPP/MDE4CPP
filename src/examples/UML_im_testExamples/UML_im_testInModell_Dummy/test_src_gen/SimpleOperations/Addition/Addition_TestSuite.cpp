#include "cute.h"
#include "SimpleOperations/Addition/Addition_TestSuite.hpp"
//#include "SimpleOperations/impl/AdditionImpl.hpp"

//testCodeGen.includes


#include "SimpleOperations/Addition/Calculate_TestSuite.hpp"

void complexAdditionTest_AdditionTest() {


    //TestQuelltext
}	

cute::suite make_suite_Addition_TestSuite() {

	cute::suite s { };

	s += CUTE( complexAdditionTest_AdditionTest );
	return s;
}

bool runAddition_TestSuiteSubTests( cute::runner<cute::xml_listener<cute::ide_listener<cute::null_listener> > > runner ) {

	bool success = true;
	cute::suite suite_Calculate = make_suite_Calculate_TestSuite();

	success &= runner( suite_Calculate, "SimpleOperations_TestSuite::Addition_TestSuite::Calculate_TestSuite" );
	return success;
}
