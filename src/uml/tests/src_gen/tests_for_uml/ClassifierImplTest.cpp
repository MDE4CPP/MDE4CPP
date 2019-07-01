#include "tests_for_uml/ClassifierImplTest.hpp"

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

void ClassifierImplTest__getAllAttributesTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		ASSERTM( "Test not implemented", false );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ClassifierImplTest__getGeneralsTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		ASSERTM( "Test not implemented", false );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ClassifierImplTest__parentsTest() {

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

cute::suite make_suite_ClassifierImplTest() {

	cute::suite s { };

	s += CUTE( ClassifierImplTest__getAllAttributesTest );
	s += CUTE( ClassifierImplTest__getGeneralsTest );
	s += CUTE( ClassifierImplTest__parentsTest );
	return s;
}

