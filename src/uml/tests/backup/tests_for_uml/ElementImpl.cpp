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

#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"
#include "uml/Stereotype.hpp"

#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"
#include "uml/Stereotype.hpp"

#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"
#include "abstractDataTypes/Bag.hpp"

//*********************************
// Tests
//*********************************

void ElementImpl__applyStereotypeTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		p->setName( "Model" );
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );
		c->setName( "Class" );
		std::shared_ptr<uml::Stereotype> s = factory->createStereotype();
		s->setName( "Stereotype" );

		ASSERT_EQUALM( "return value is not nullptr", nullptr, c->applyStereotype( s ) );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ElementImpl__getAppliedStereotypeTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		p->setName( "Model" );
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );
		c->setName( "Class" );
		std::shared_ptr<uml::Stereotype> s = factory->createStereotype();
		s->setName( "Stereotype" );

		c->applyStereotype( s );

		ASSERT_EQUALM( "got AppliedStereotype is wrong", s, c->getAppliedStereotype( "Model::Class::Stereotype" ) );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ElementImpl__getAppliedStereotypesTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Stereotype> s = factory->createStereotype();
		std::shared_ptr<uml::Stereotype> s2 = factory->createStereotype();

		c->applyStereotype( s );
		c->applyStereotype( s2 );

		std::shared_ptr<Bag<uml::Stereotype>> expected( new Bag<uml::Stereotype>() );
		expected->add( s );
		expected->add( s2 );
		std::shared_ptr<Bag<uml::Stereotype>> aqual = c->getAppliedStereotypes();
		ASSERT_EQUALM( "c bag size not equal", expected->size(), aqual->size() );
		for( unsigned int i = 0; i < aqual->size(); i++ ) {
			ASSERT_EQUALM( "c bag element not equal", expected->at( i ), aqual->at( i ) );
		}
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

