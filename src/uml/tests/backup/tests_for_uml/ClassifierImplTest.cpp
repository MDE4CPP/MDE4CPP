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

//Included from operation "getAllAttributesTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Generalization.hpp"
#include "uml/Model.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
//Included from operation "getGeneralsTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Generalization.hpp"
#include "uml/Model.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
//Included from operation "parentsTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Generalization.hpp"
#include "uml/Model.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"

//*********************************
// Tests
//*********************************

void ClassifierImplTest__getAllAttributesTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour getAllAttributesTestFB

		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Class> c2 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Property> pt1 = factory->createProperty_in_Class( c2, 0 );
		std::shared_ptr<uml::Class> c3 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Property> pt2 = factory->createProperty_in_Class( c3, 0 );
		std::shared_ptr<uml::Generalization> g = factory->createGeneralization( 0 );
		g->setGeneral( c2 );
		c3->getGeneralization()->add( g );

		ASSERT_EQUALM( "bag size not 0", 0, c->getAllAttributes()->size() );

		std::shared_ptr<Bag<uml::Property>> aqual = c2->getAllAttributes();

		std::shared_ptr<Bag<uml::Property>> expected( new Bag<uml::Property>() );
		expected->add( pt1 );
		ASSERT_EQUALM( "bag size not 1", expected->size(), aqual->size() );
		for( unsigned int i = 0; i < aqual->size(); i++ ) {
			ASSERT_EQUALM( "bag element not equal", expected->at( i ), aqual->at( i ) );
		}

		std::shared_ptr<Bag<uml::Property>> aqual2 = c3->getAllAttributes();

		std::shared_ptr<Bag<uml::Property>> expected2( new Bag<uml::Property>() );
		expected2->add( pt2 );
		expected2->add( pt1 );
		ASSERT_EQUALM( "bag size not 1", expected2->size(), aqual2->size() );
		for( unsigned int i = 0; i < aqual2->size(); i++ ) {
			ASSERT_EQUALM( "bag element not equal", expected2->at( i ), aqual2->at( i ) );
		}
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ClassifierImplTest__getGeneralsTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour getGeneralsTestFB

		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Class> c2 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Class> c3 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Generalization> g = factory->createGeneralization( 0 );
		g->setGeneral( c2 );
		c3->getGeneralization()->add( g );

		ASSERT_EQUALM( "bag size not 0", 0, c->getGenerals()->size() );
		ASSERT_EQUALM( "bag size not 0", 0, c2->getGenerals()->size() );

		std::shared_ptr<Bag<uml::Classifier>> aqual = c3->getGenerals();

		std::shared_ptr<Bag<uml::Classifier>> expected( new Bag<uml::Classifier>() );
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

void ClassifierImplTest__parentsTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour parentsTestFB

		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Class> c2 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Class> c3 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Generalization> g = factory->createGeneralization( 0 );
		g->setGeneral( c2 );
		c3->getGeneralization()->add( g );

		ASSERT_EQUALM( "bag size not 0", 0, c->parents()->size() );
		ASSERT_EQUALM( "bag size not 0", 0, c2->parents()->size() );

		std::shared_ptr<Bag<uml::Classifier>> aqual = c3->parents();

		std::shared_ptr<Bag<uml::Classifier>> expected( new Bag<uml::Classifier>() );
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

cute::suite make_suite_ClassifierImplTest() {

	cute::suite s { };

	s += CUTE( ClassifierImplTest__getAllAttributesTest );
	s += CUTE( ClassifierImplTest__getGeneralsTest );
	s += CUTE( ClassifierImplTest__parentsTest );
	return s;
}

