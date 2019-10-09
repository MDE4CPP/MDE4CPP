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

//Included from operation "getSuperClassesTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Generalization.hpp"
#include "uml/Model.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"

//*********************************
// Tests
//*********************************

void ClassImplTest__getSuperClassesTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour getSuperClassesTestFB

		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Class> c2 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Class> c3 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Generalization> g = factory->createGeneralization( 0 );
		g->setGeneral( c2 );
		c3->getGeneralization()->add( g );

		ASSERT_EQUALM( "bag size not 0", 0, c->getSuperClasses()->size() );
		ASSERT_EQUALM( "bag size not 0", 0, c2->getSuperClasses()->size() );

		std::shared_ptr<Bag<uml::Class>> aqual = c3->getSuperClasses();

		std::shared_ptr<Bag<uml::Class>> expected( new Bag<uml::Class>() );
		expected->add( c2 );
		ASSERT_EQUALM( "bag size not 1", expected->size(), aqual->size() );
		for( unsigned int i = 0; i < aqual->size(); i++ ) {
			ASSERT_EQUALM( "bag element not equal", expected->at( i ), aqual->at( i ) );
		}
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

