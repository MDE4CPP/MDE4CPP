#include "tests_for_uml/ElementImpl.hpp"

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

void ElementImpl__applyStereotypeTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		ASSERTM( "Test not implemented", false );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ElementImpl__getAppliedStereotypeTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		ASSERTM( "Test not implemented", false );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ElementImpl__getAppliedStereotypesTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		ASSERTM( "Test not implemented", false );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ElementImpl__getValueTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		ASSERTM( "Test not implemented", false );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ElementImpl__isStereotypeAppliedTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		ASSERTM( "Test not implemented", false );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ElementImpl__setValueTest() {

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

cute::suite make_suite_ElementImpl() {

	cute::suite s { };

	s += CUTE( ElementImpl__applyStereotypeTest );
	s += CUTE( ElementImpl__getAppliedStereotypeTest );
	s += CUTE( ElementImpl__getAppliedStereotypesTest );
	s += CUTE( ElementImpl__getValueTest );
	s += CUTE( ElementImpl__isStereotypeAppliedTest );
	s += CUTE( ElementImpl__setValueTest );
	return s;
}

