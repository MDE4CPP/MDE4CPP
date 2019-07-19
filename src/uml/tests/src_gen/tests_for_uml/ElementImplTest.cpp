#include "tests_for_uml/ElementImplTest.hpp"

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

//Included from operation "applyStereotypeTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"
#include "uml/Stereotype.hpp"
//Included from operation "getAppliedStereotypeTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"
#include "uml/Stereotype.hpp"
//Included from operation "getAppliedStereotypesTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"
#include "abstractDataTypes/Bag.hpp"
//Included from operation "getValueTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"
#include "uml/Stereotype.hpp"
#include "abstractDataTypes/Any.hpp"
//Included from operation "isStereotypeAppliedTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"
#include "uml/Stereotype.hpp"
//Included from operation "setValueTest"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"
#include "uml/Stereotype.hpp"
#include "abstractDataTypes/Any.hpp"

//*********************************
// Tests
//*********************************

void ElementImplTest__applyStereotypeTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour applyStereotypeTestFB

		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		p->setName( "Model" );
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );
		c->setName( "Class" );
		std::shared_ptr<uml::Stereotype> s = factory->createStereotype();
		s->setName( "Stereotype" );
		
		//TODO: applyStereotype always return "nullptr"
		ASSERT_EQUALM( "return value is not nullptr", nullptr, c->applyStereotype( s ) );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ElementImplTest__getAppliedStereotypeTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour getAppliedStereotypeTestFB

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

void ElementImplTest__getAppliedStereotypesTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour getAppliedStereotypesTestFB

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

void ElementImplTest__getValueTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour getValueTestFB

		//TODO: setValue is not implemented in ElementImpl
		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );
		std::shared_ptr<uml::Stereotype> s = factory->createStereotype();
		s->setName( "Stereotype" );

		ASSERT_EQUALM( "value not equal", Any(), c->getValue( s, "property" ) );
		Any value = eAny( factory->createLiteralInteger() );
		c->setValue( s,"property", value );
		ASSERT_EQUALM( "value not equal", value, c->getValue( s, "property" ) );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ElementImplTest__isStereotypeAppliedTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour isStereotypeAppliedTestFB

		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		p->setName( "Model" );
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );
		c->setName( "Class" );
		std::shared_ptr<uml::Stereotype> s = factory->createStereotype();
		s->setName( "Stereotype" );

		ASSERT_EQUALM( "Stereotype is applied", false, c->isStereotypeApplied( s ) );
		c->applyStereotype( s );
		ASSERT_EQUALM( "Stereotype is not applied", true, c->isStereotypeApplied( s ) );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ElementImplTest__setValueTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour setValueTestFB

		//TODO: setValue is not implemented in ElementImpl
		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		std::shared_ptr<uml::Model> p = factory->createModel();
		p->setName( "Model" );
		std::shared_ptr<uml::Class> c = factory->createClass_in_Package( p );
		c->setName( "Class" );
		std::shared_ptr<uml::Stereotype> s = factory->createStereotype();
		s->setName( "Stereotype" );

		Any value = eAny( factory->createLiteralInteger() );
		c->setValue( s,"property", value );
		ASSERT_EQUALM( "value not equal", value, c->getValue( s, "property" ) );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

//*********************************
// Make Class Test Suite
//*********************************

cute::suite make_suite_ElementImplTest() {

	cute::suite s { };

	s += CUTE( ElementImplTest__applyStereotypeTest );
	s += CUTE( ElementImplTest__getAppliedStereotypeTest );
	s += CUTE( ElementImplTest__getAppliedStereotypesTest );
	s += CUTE( ElementImplTest__getValueTest );
	s += CUTE( ElementImplTest__isStereotypeAppliedTest );
	s += CUTE( ElementImplTest__setValueTest );
	return s;
}

