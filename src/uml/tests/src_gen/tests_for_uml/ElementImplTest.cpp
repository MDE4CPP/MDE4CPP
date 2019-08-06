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
#include "Stereotype_uml/Stereotype_umlFactory.hpp"
#include "Stereotype_uml/ExampleClass.hpp"
#include "Stereotype_uml/ExampleStereotype.hpp"
//Included from operation "getAppliedStereotypeTest"
#include "Stereotype_uml/Stereotype_umlFactory.hpp"
#include "Stereotype_uml/ExampleClass.hpp"
#include "Stereotype_uml/ExampleStereotype.hpp"
//Included from operation "getAppliedStereotypesTest"
#include "Stereotype_uml/Stereotype_umlFactory.hpp"
#include "Stereotype_uml/ExampleClass.hpp"
#include "Stereotype_uml/ExampleStereotype.hpp"
#include "abstractDataTypes/Bag.hpp"
//Included from operation "getValueTest"
#include "Stereotype_uml/Stereotype_umlFactory.hpp"
#include "Stereotype_uml/ExampleClass.hpp"
#include "Stereotype_uml/ExampleStereotype.hpp"
#include "uml/UmlFactory.hpp"
#include "abstractDataTypes/Any.hpp"
//Included from operation "isStereotypeAppliedTest"
#include "Stereotype_uml/Stereotype_umlFactory.hpp"
#include "Stereotype_uml/ExampleClass.hpp"
#include "Stereotype_uml/ExampleStereotype.hpp"
//Included from operation "setValueTest"
#include "Stereotype_uml/Stereotype_umlFactory.hpp"
#include "Stereotype_uml/ExampleClass.hpp"
#include "Stereotype_uml/ExampleStereotype.hpp"
#include "uml/UmlFactory.hpp"
#include "abstractDataTypes/Any.hpp"

//*********************************
// Tests
//*********************************

void ElementImplTest__applyStereotypeTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour applyStereotypeTestFB

		std::shared_ptr<Stereotype_uml::Stereotype_umlFactory> factory = Stereotype_uml::Stereotype_umlFactory::eInstance();
		std::shared_ptr<Stereotype_uml::ExampleClass> ec = factory->createExampleClass();
		std::shared_ptr<Stereotype_uml::ExampleStereotype> es = factory->createExampleStereotype();
		
		//TODO: applyStereotype always return "nullptr"
		ASSERT_EQUALM( "return value is not nullptr", nullptr, ec->applyStereotype( es ) );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ElementImplTest__getAppliedStereotypeTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour getAppliedStereotypeTestFB

		std::shared_ptr<Stereotype_uml::Stereotype_umlFactory> factory = Stereotype_uml::Stereotype_umlFactory::eInstance();
		std::shared_ptr<Stereotype_uml::ExampleClass> ec = factory->createExampleClass();
		std::shared_ptr<Stereotype_uml::ExampleStereotype> es = factory->createExampleStereotype();

		ec->applyStereotype( es );

		ASSERT_EQUALM( "got AppliedStereotype is wrong", es, ec->getAppliedStereotype( es->getMetaClass()->getQualifiedName() ) );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ElementImplTest__getAppliedStereotypesTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour getAppliedStereotypesTestFB

		std::shared_ptr<Stereotype_uml::Stereotype_umlFactory> factory = Stereotype_uml::Stereotype_umlFactory::eInstance();
		std::shared_ptr<Stereotype_uml::ExampleClass> ec = factory->createExampleClass();
		std::shared_ptr<Stereotype_uml::ExampleStereotype> es = factory->createExampleStereotype();
		std::shared_ptr<Stereotype_uml::ExampleStereotype> es2 = factory->createExampleStereotype();

		ec->applyStereotype( es );
		ec->applyStereotype( es2 );

		std::shared_ptr<Bag<uml::Stereotype>> expected( new Bag<uml::Stereotype>() );
		expected->add( es );
		expected->add( es2 );
		std::shared_ptr<Bag<uml::Stereotype>> aqual = ec->getAppliedStereotypes();
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
		std::shared_ptr<uml::UmlFactory> umlfactory = uml::UmlFactory::eInstance();
		std::shared_ptr<Stereotype_uml::Stereotype_umlFactory> factory = Stereotype_uml::Stereotype_umlFactory::eInstance();
		std::shared_ptr<Stereotype_uml::ExampleClass> ec = factory->createExampleClass();
		std::shared_ptr<Stereotype_uml::ExampleStereotype> es = factory->createExampleStereotype();


		ASSERT_EQUALM( "value not equal", Any(), ec->getValue( es, "property" ) );
		ec->applyStereotype( es );
		ASSERT_EQUALM( "value not equal", Any(), ec->getValue( es, "property" ) );
		Any value = eAny( umlfactory->createLiteralInteger() );
		ec->setValue( es,"property", value );
		ASSERT_EQUALM( "value not equal", value, ec->getValue( es, "property" ) );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void ElementImplTest__isStereotypeAppliedTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour isStereotypeAppliedTestFB

		std::shared_ptr<Stereotype_uml::Stereotype_umlFactory> factory = Stereotype_uml::Stereotype_umlFactory::eInstance();
		std::shared_ptr<Stereotype_uml::ExampleClass> ec = factory->createExampleClass();
		std::shared_ptr<Stereotype_uml::ExampleStereotype> es = factory->createExampleStereotype();

		ASSERT_EQUALM( "Stereotype is applied", false, ec->isStereotypeApplied( es ) );
		ec->applyStereotype( es );
		ASSERT_EQUALM( "Stereotype is not applied", true, ec->isStereotypeApplied( es ) );
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
		std::shared_ptr<uml::UmlFactory> umlfactory = uml::UmlFactory::eInstance();
		std::shared_ptr<Stereotype_uml::Stereotype_umlFactory> factory = Stereotype_uml::Stereotype_umlFactory::eInstance();
		std::shared_ptr<Stereotype_uml::ExampleClass> ec = factory->createExampleClass();
		std::shared_ptr<Stereotype_uml::ExampleStereotype> es = factory->createExampleStereotype();

		ec->applyStereotype( es );
		Any value = eAny( umlfactory->createLiteralInteger() );
		ec->setValue( es,"property", value );
		ASSERT_EQUALM( "value not equal", value, ec->getValue( es, "property" ) );
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

