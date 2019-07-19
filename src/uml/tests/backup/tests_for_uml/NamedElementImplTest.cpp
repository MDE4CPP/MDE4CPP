#include "tests_for_uml/NamedElementImplTest.hpp"

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

//Included from operation "allNamespacesTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"
//Included from operation "getQualifiedNameTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"
#include "abstractDataTypes/Bag.hpp"
//Included from operation "separatorTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"

//*********************************
// Tests
//*********************************

void NamedElementImplTest__allNamespacesTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour allNamespacesTestFB

		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Class> c2 = factory->createClass_in_Namespace( p );
		std::shared_ptr<uml::Class> c3 = factory->createClass();

		std::shared_ptr<Bag<uml::Namespace>> aqual = c->allNamespaces();
		std::shared_ptr<Bag<uml::Namespace>> aqual2 = c2->allNamespaces();
		std::shared_ptr<Bag<uml::Namespace>> aqual3 = c3->allNamespaces();

		std::shared_ptr<Bag<uml::Namespace>> expected( new Bag<uml::Namespace>() );
		expected->add( p );
		ASSERT_EQUALM( "bag size not equal", expected->size(), aqual->size() );
		for( unsigned int i = 0; i < aqual->size(); i++ ) {
			ASSERT_EQUALM( "bag element not equal", expected->at( i ), aqual->at( i ) );
		}
		ASSERT_EQUALM( "bag size not equal", expected->size(), aqual2->size() );
		for( unsigned int i = 0; i < aqual2->size(); i++ ) {
			ASSERT_EQUALM( "bag element not equal", expected->at( i ), aqual2->at( i ) );
		}
		ASSERT_EQUALM( "bag size not 0", 0, aqual3->size() );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void NamedElementImplTest__getQualifiedNameTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour getQualifiedNameTestFB

		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		p->setName( "Model" );
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );
		c->setName( "Class1" );
		std::shared_ptr<uml::Package> p2 = factory->createPackage_in_Namespace( p, 0 );
		p2->setName( "Package1" );
		std::shared_ptr<uml::Class> c2 = factory->createClass_in_Package( p2 );
		c2->setName( "Class2" );
		std::shared_ptr<uml::Class> c3 = factory->createClass_in_Package( p2 );

		ASSERT_EQUALM( "qualified name not correct", "Model::Class1", c->getQualifiedName() );
		ASSERT_EQUALM( "qualified name not correct", "Model::Package1::Class2", c2->getQualifiedName() );
		ASSERT_EQUALM( "qualified name not correct", "", c3->getQualifiedName() );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void NamedElementImplTest__separatorTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour separatorTestFB

		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );

		ASSERT_EQUALM( "seperator ist not ::", "::", c->separator() );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

//*********************************
// Make Class Test Suite
//*********************************

cute::suite make_suite_NamedElementImplTest() {

	cute::suite s { };

	s += CUTE( NamedElementImplTest__allNamespacesTest );
	s += CUTE( NamedElementImplTest__getQualifiedNameTest );
	s += CUTE( NamedElementImplTest__separatorTest );
	return s;
}

