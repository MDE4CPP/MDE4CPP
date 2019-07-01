#include "tests_for_uml/ClassImplTest.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>

#include "cute.h"
#include "helper/TestSuiteCountHelper.hpp"
#include "helper/TestSuiteMainHelper.hpp"
#include "helper/TestSuiteMemoryHelper.hpp"
#include "helper/TestSuiteTimeHelper.hpp"


//*********************************
// Tests
//*********************************

void ClassImplTest__getSuperClassesTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		ASSERTM( "Test not implemented", false );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

//*********************************
// Make Class Test Suite
//*********************************

cute::suite make_suite_ClassImplTest() {

	cute::suite s { };

	s += CUTE( ClassImplTest__getSuperClassesTest );
	return s;
}

