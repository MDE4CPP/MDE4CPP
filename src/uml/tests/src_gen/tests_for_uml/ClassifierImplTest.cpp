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

//Included from operation "classAttributeCircleTest"
#include "uml/UmlFactory.hpp"
#include "uml/Model.hpp"
#include "uml/Class.hpp"
#include "uml/Property.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
//Included from operation "doubleGeneralizationgetAllAttributesTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Generalization.hpp"
#include "uml/Model.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
//Included from operation "doubleParentsTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Generalization.hpp"
#include "uml/Model.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
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
//Included from operation "parentsCircleTest"
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

void ClassifierImplTest__classAttributeCircleTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour classAttributeCircleTestFB

		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		std::shared_ptr<uml::Class> c1 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Class> c2 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Property> pt1 = factory->createProperty_in_Class( c1, 0 );
		pt1->setType( c2 );
		std::shared_ptr<uml::Property> pt2 = factory->createProperty_in_Class( c2, 0 );
		pt2->setType( c1 );

		ASSERT_EQUALM( "model has a circle", false, c1->getAttribute()->find( pt1 ) != -1 && c2->getAttribute()->find( pt2 ) != -1 );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ClassifierImplTest__doubleGeneralizationgetAllAttributesTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour doubleGeneralizationgetAllAttributesTestFB

		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		std::shared_ptr<uml::Class> c1 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Property> pt1 = factory->createProperty_in_Class( c1, 0 );
		std::shared_ptr<uml::Class> c21 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Property> pt21 = factory->createProperty_in_Class( c21, 0 );
		std::shared_ptr<uml::Generalization> g_c1c21 = factory->createGeneralization( 0 );
		g_c1c21->setGeneral( c1 );
		c21->getGeneralization()->add( g_c1c21 );
		std::shared_ptr<uml::Class> c22 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Property> pt22 = factory->createProperty_in_Class( c22, 0 );
		std::shared_ptr<uml::Generalization> g_c1c22 = factory->createGeneralization( 0 );
		g_c1c22->setGeneral( c1 );
		c22->getGeneralization()->add( g_c1c22 );
		std::shared_ptr<uml::Class> c3 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Property> pt3 = factory->createProperty_in_Class( c3, 0 );
		std::shared_ptr<uml::Generalization> g_c21c3 = factory->createGeneralization( 0 );
		g_c21c3->setGeneral( c21 );
		c3->getGeneralization()->add( g_c21c3 );
		std::shared_ptr<uml::Generalization> g_c22c3 = factory->createGeneralization( 0 );
		g_c22c3->setGeneral( c22 );
		c3->getGeneralization()->add( g_c22c3 );

		ASSERT_EQUALM( "c1 bag size not 1", 1, c1->getAllAttributes()->size() );
		ASSERT_EQUALM( "c1 pt1 bag element not equal", pt1, c1->getAllAttributes()->at( 0 ) );

		ASSERT_EQUALM( "c21 bag size not 2", 2, c21->getAllAttributes()->size() );
		ASSERT_EQUALM( "c21 pt21 bag element not equal", pt21, c21->getAllAttributes()->at( 0 ) );
		ASSERT_EQUALM( "c21 pt1 bag element not equal", pt1, c21->getAllAttributes()->at( 1 ) );

		ASSERT_EQUALM( "c22 bag size not 2", 2, c22->getAllAttributes()->size() );
		ASSERT_EQUALM( "c22 pt22 bag element not equal", pt22, c22->getAllAttributes()->at( 0 ) );
		ASSERT_EQUALM( "c22 pt1 bag element not equal", pt1, c22->getAllAttributes()->at( 1 ) );

		//Only generalizations of this class is return. Not the generalizations of the generalized classes
		ASSERT_EQUALM( "c3 bag size not 4", 4, c3->getAllAttributes()->size() );
		ASSERT_EQUALM( "c3 pt3 bag element not equal", pt3, c3->getAllAttributes()->at( 0 ) );
		ASSERT_EQUALM( "c3 pt21 bag element not equal", pt21, c3->getAllAttributes()->at( 1 ) );
		ASSERT_EQUALM( "c3 pt1 bag element not equal", pt1, c3->getAllAttributes()->at( 2 ) );
		ASSERT_EQUALM( "c3 pt22 bag element not equal", pt22, c3->getAllAttributes()->at( 3 ) );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ClassifierImplTest__doubleParentsTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour doubleParentsTestFB

		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		std::shared_ptr<uml::Class> c1 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Class> c21 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Generalization> g_c1c21 = factory->createGeneralization( 0 );
		g_c1c21->setGeneral( c1 );
		c21->getGeneralization()->add( g_c1c21 );
		std::shared_ptr<uml::Class> c22 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Generalization> g_c1c22 = factory->createGeneralization( 0 );
		g_c1c22->setGeneral( c1 );
		c22->getGeneralization()->add( g_c1c22 );
		std::shared_ptr<uml::Class> c3 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Generalization> g_c21c3 = factory->createGeneralization( 0 );
		g_c21c3->setGeneral( c21 );
		c3->getGeneralization()->add( g_c21c3 );
		std::shared_ptr<uml::Generalization> g_c22c3 = factory->createGeneralization( 0 );
		g_c22c3->setGeneral( c22 );
		c3->getGeneralization()->add( g_c22c3 );

		ASSERT_EQUALM( "c1 bag size not 0", 0, c1->parents()->size() );

		ASSERT_EQUALM( "c21 bag size not 1", 1, c21->parents()->size() );
		ASSERT_EQUALM( "c21 bag element not equal", c1, c21->parents()->at( 0 ) );

		ASSERT_EQUALM( "c22 bag size not 1", 1, c22->parents()->size() );
		ASSERT_EQUALM( "c22 bag element not equal", c1, c22->parents()->at( 0 ) );

		//Only generalizations of this class is return. Not the generalizations of the generalized classes
		ASSERT_EQUALM( "c3 bag size not 2", 2, c3->parents()->size() );
		ASSERT_EQUALM( "c3 0=>c21 bag element not equal", c21, c3->parents()->at( 0 ) );
		ASSERT_EQUALM( "c3 0=>c22 bag element not equal", c22, c3->parents()->at( 1 ) );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

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
		ASSERT_EQUALM( "bag size not 2", expected2->size(), aqual2->size() );
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

void ClassifierImplTest__parentsCircleTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour parentsCircleTestFB

		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Class> c2 = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Generalization> g = factory->createGeneralization( 0 );
		g->setGeneral( c2 );
		c->getGeneralization()->add( g );
		std::shared_ptr<uml::Generalization> g2 = factory->createGeneralization( 0 );
		g2->setGeneral( c );
		c2->getGeneralization()->add( g2 );

		ASSERT_EQUALM( "c bag size not 1", 1, c->parents()->size() );
		ASSERT_EQUALM( "c2 bag size not 1", 1, c2->parents()->size() );
		ASSERT_EQUALM( "model has a circle", false, c->parents()->at( 0 ) == c2 && c2->parents()->at( 0 ) == c );
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

	s += CUTE( ClassifierImplTest__classAttributeCircleTest );
	s += CUTE( ClassifierImplTest__doubleGeneralizationgetAllAttributesTest );
	s += CUTE( ClassifierImplTest__doubleParentsTest );
	s += CUTE( ClassifierImplTest__getAllAttributesTest );
	s += CUTE( ClassifierImplTest__getGeneralsTest );
	s += CUTE( ClassifierImplTest__parentsCircleTest );
	s += CUTE( ClassifierImplTest__parentsTest );
	return s;
}

