#include "cute.h"
#include "SimpleOperations/Addition/Calculate_TestSuite.hpp"
//#include "SimpleOperations/impl/AdditionImpl.hpp"

//testCodeGen.includes

//TestIncludes

void positivNumbersAdditionTest_CalculateTest() {


    //TestQuelltext
}	

void negativNumbersAdditionTest_CalculateTest() {


    //TestQuelltext
}	

cute::suite make_suite_Calculate_TestSuite() {

	cute::suite s { };

	s += CUTE( positivNumbersAdditionTest_CalculateTest );
	s += CUTE( negativNumbersAdditionTest_CalculateTest );
	return s;
}
